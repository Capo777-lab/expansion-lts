"""Logica do Treta Launcher (sem interface), para poder testar sem janela."""
import json, os, sys, shutil, subprocess, time, zipfile, urllib.request, urllib.error, urllib.parse

APP_NAME = "Pokemon Treta Geral"
ROM_NAME = "pokemon_treta_geral.gba"
API = "https://api.github.com"

DEFAULTS = {
    "emulator_path": "",
    "rom_path": "",
    "fullscreen": False,
    "scale": 4,
    "github_repo": "",       # ex.: Capo777-lab/expansion-lts
    "github_token": "",      # token pessoal (somente leitura de Actions)
    "artifact_name": "jogo-gba",
    "installed_version": "",
}


def app_dir():
    if getattr(sys, "frozen", False):
        return os.path.dirname(os.path.abspath(sys.executable))
    return os.path.dirname(os.path.abspath(__file__))


def resource_path(name):
    base = getattr(sys, "_MEIPASS", os.path.dirname(os.path.abspath(__file__)))
    return os.path.join(base, name)


class _NoAuthRedirect(urllib.request.HTTPRedirectHandler):
    """O GitHub redireciona o download para outro servidor, que rejeita o token."""
    def redirect_request(self, req, fp, code, msg, headers, newurl):
        return urllib.request.Request(newurl, headers={"User-Agent": "TretaLauncher"})


class Core:
    def __init__(self, base=None):
        self.base = base or app_dir()
        self.config_path = os.path.join(self.base, "config.json")
        self.game_dir = os.path.join(self.base, "jogo")
        self.backup_dir = os.path.join(self.base, "backups")
        os.makedirs(self.game_dir, exist_ok=True)
        os.makedirs(self.backup_dir, exist_ok=True)
        self.cfg = dict(DEFAULTS)
        self.load()

    # ---------- configuracao ----------
    def load(self):
        if os.path.exists(self.config_path):
            try:
                with open(self.config_path, encoding="utf-8") as f:
                    self.cfg.update(json.load(f))
            except (OSError, ValueError):
                pass
        if not self.cfg.get("rom_path"):
            self.cfg["rom_path"] = os.path.join(self.game_dir, ROM_NAME)

    def save(self):
        with open(self.config_path, "w", encoding="utf-8") as f:
            json.dump(self.cfg, f, indent=2, ensure_ascii=False)

    # ---------- emulador ----------
    def find_emulator(self):
        cands = [self.cfg.get("emulator_path", "")]
        for d in (os.path.join(self.base, "mgba"), os.path.join(self.base, "mGBA")):
            cands.append(os.path.join(d, "mGBA.exe"))
        for env in ("ProgramFiles", "ProgramFiles(x86)", "LOCALAPPDATA"):
            root = os.environ.get(env)
            if root:
                cands.append(os.path.join(root, "mGBA", "mGBA.exe"))
        for c in cands:
            if c and os.path.isfile(c):
                return c
        for name in ("mGBA", "mgba-qt", "mgba"):
            p = shutil.which(name)
            if p:
                return p
        return None

    def has_rom(self):
        return os.path.isfile(self.cfg["rom_path"])

    def build_command(self, emulator):
        cmd = [emulator]
        if self.cfg.get("fullscreen"):
            cmd.append("-f")
        scale = int(self.cfg.get("scale") or 0)
        if scale > 0:
            cmd += ["-C", "videoScale=%d" % scale]
        cmd.append(self.cfg["rom_path"])
        return cmd

    def launch(self):
        emu = self.find_emulator()
        if not emu:
            raise RuntimeError("Emulador mGBA nao encontrado. Defina o caminho nas Configuracoes.")
        if not self.has_rom():
            raise RuntimeError("Jogo nao encontrado. Use ATUALIZAR para importar o arquivo .gba.")
        return subprocess.Popen(self.build_command(emu), cwd=os.path.dirname(self.cfg["rom_path"]))

    # ---------- saves ----------
    def save_file(self):
        return os.path.splitext(self.cfg["rom_path"])[0] + ".sav"

    def backup_save(self):
        sav = self.save_file()
        if not os.path.isfile(sav):
            raise RuntimeError("Nenhum save encontrado ainda. Jogue e salve dentro do jogo primeiro.")
        stamp = time.strftime("%Y%m%d_%H%M%S")
        dest = os.path.join(self.backup_dir, "save_%s.sav" % stamp)
        shutil.copy2(sav, dest)
        return dest

    # ---------- atualizacao ----------
    def import_file(self, path, version=""):
        """Aceita um .gba ou um .zip que contenha um .gba. Guarda o jogo anterior em backups."""
        if path.lower().endswith(".zip"):
            with zipfile.ZipFile(path) as zf:
                names = [n for n in zf.namelist() if n.lower().endswith(".gba")]
                if not names:
                    raise RuntimeError("O zip nao contem nenhum arquivo .gba.")
                data = zf.read(names[0])
        elif path.lower().endswith(".gba"):
            with open(path, "rb") as f:
                data = f.read()
        else:
            raise RuntimeError("Escolha um arquivo .gba ou .zip.")
        rom = self.cfg["rom_path"]
        os.makedirs(os.path.dirname(rom), exist_ok=True)
        if os.path.isfile(rom):
            shutil.copy2(rom, os.path.join(self.backup_dir, "jogo_%s.gba" % time.strftime("%Y%m%d_%H%M%S")))
        tmp = rom + ".novo"
        with open(tmp, "wb") as f:
            f.write(data)
        os.replace(tmp, rom)
        if version:
            self.cfg["installed_version"] = version
            self.save()
        return rom

    def _github_request(self, url, accept="application/vnd.github+json"):
        return urllib.request.Request(url, headers={
            "Authorization": "Bearer " + self.cfg["github_token"],
            "Accept": accept,
            "User-Agent": "TretaLauncher",
            "X-GitHub-Api-Version": "2022-11-28",
        })

    def latest_artifact(self):
        repo, tok = self.cfg["github_repo"].strip(), self.cfg["github_token"].strip()
        if not repo or not tok:
            raise RuntimeError("Preencha o repositorio e o token do GitHub nas Configuracoes.")
        url = "%s/repos/%s/actions/artifacts?name=%s&per_page=10" % (API, repo, urllib.parse.quote(self.cfg["artifact_name"]))
        try:
            with urllib.request.urlopen(self._github_request(url), timeout=30) as r:
                data = json.load(r)
        except urllib.error.HTTPError as e:
            raise RuntimeError("GitHub respondeu erro %d. Confira o repositorio e o token." % e.code)
        except urllib.error.URLError as e:
            raise RuntimeError("Sem conexao com o GitHub: %s" % e.reason)
        items = [a for a in data.get("artifacts", []) if not a.get("expired")]
        if not items:
            raise RuntimeError("Nenhuma versao disponivel (o artifact pode ter expirado). Rode o build de novo no GitHub.")
        items.sort(key=lambda a: a["created_at"], reverse=True)
        return items[0]

    def has_update(self, art):
        return art["created_at"] != self.cfg.get("installed_version")

    def download_artifact(self, art, progress=None):
        opener = urllib.request.build_opener(_NoAuthRedirect())
        req = self._github_request(art["archive_download_url"], accept="application/vnd.github+json")
        tmp = os.path.join(self.backup_dir, "download.zip")
        total = art.get("size_in_bytes") or 0
        done = 0
        with opener.open(req, timeout=60) as r, open(tmp, "wb") as f:
            while True:
                chunk = r.read(64 * 1024)
                if not chunk:
                    break
                f.write(chunk)
                done += len(chunk)
                if progress and total:
                    progress(min(1.0, done / total))
        try:
            return self.import_file(tmp, version=art["created_at"])
        finally:
            try:
                os.remove(tmp)
            except OSError:
                pass
