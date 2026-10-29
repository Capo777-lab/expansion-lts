import os, sys, threading
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from launcher_core import Core, resource_path, APP_NAME

W, H = 940, 600
BG0, BG1 = 8, 46          # degrade de preto para cinza escuro
PANEL = "#121212"
FG = "#f2f2f2"
MUTED = "#9a9a9a"


class GButton(tk.Label):
    """Botao no estilo preto e branco, com realce ao passar o mouse."""
    def __init__(self, master, text, command, big=False):
        super().__init__(master, text=text, fg="#111111", bg="#f2f2f2", cursor="hand2",
                         font=("Segoe UI", 20 if big else 11, "bold"), padx=24 if big else 14, pady=12 if big else 7)
        self.command = command
        self.enabled = True
        self.bind("<Enter>", lambda e: self.enabled and self.configure(bg="#ffffff"))
        self.bind("<Leave>", lambda e: self.configure(bg="#f2f2f2" if self.enabled else "#777777"))
        self.bind("<Button-1>", lambda e: self.enabled and self.command())

    def set_enabled(self, value):
        self.enabled = value
        self.configure(bg="#f2f2f2" if value else "#777777", cursor="hand2" if value else "arrow")


class App:
    def __init__(self):
        self.core = Core()
        self.root = tk.Tk()
        self.root.title(APP_NAME + " - Launcher")
        self.root.resizable(False, False)
        x = (self.root.winfo_screenwidth() - W) // 2
        y = (self.root.winfo_screenheight() - H) // 2
        self.root.geometry("%dx%d+%d+%d" % (W, H, x, y))
        self.canvas = tk.Canvas(self.root, width=W, height=H, highlightthickness=0, bd=0)
        self.canvas.pack()
        for yy in range(H):
            g = int(BG0 + (BG1 - BG0) * yy / H)
            self.canvas.create_line(0, yy, W, yy, fill="#%02x%02x%02x" % (g, g, g))
        self.logo = None
        try:
            self.logo = tk.PhotoImage(file=resource_path("logo.png"))
            self.canvas.create_image(W - 300, 130, image=self.logo)
        except tk.TclError:
            self.canvas.create_text(W - 300, 130, text=APP_NAME.upper(), fill=FG, font=("Segoe UI", 28, "bold"))

        # painel de novidades (esquerda)
        self.canvas.create_text(40, 36, anchor="w", text="NOVIDADES", fill=FG, font=("Segoe UI", 16, "bold"))
        self.news = tk.Text(self.root, width=44, height=24, bg=PANEL, fg=FG, bd=0, wrap="word",
                            font=("Segoe UI", 10), padx=14, pady=12, insertbackground=FG)
        self.canvas.create_window(40, 62, anchor="nw", window=self.news)
        self.load_news()

        # botoes (direita)
        self.play = GButton(self.root, "JOGAR", self.on_play, big=True)
        self.canvas.create_window(W - 300, 290, window=self.play)
        self.btn_update = GButton(self.root, "ATUALIZAR", self.on_update)
        self.canvas.create_window(W - 300, 360, window=self.btn_update, width=220)
        self.btn_backup = GButton(self.root, "BACKUP DO SAVE", self.on_backup)
        self.canvas.create_window(W - 300, 405, window=self.btn_backup, width=220)
        self.btn_cfg = GButton(self.root, "CONFIGURACOES", self.on_settings)
        self.canvas.create_window(W - 300, 450, window=self.btn_cfg, width=220)

        # status
        style = ttk.Style(self.root)
        style.theme_use("clam")
        style.configure("Treta.Horizontal.TProgressbar", troughcolor="#1c1c1c", background="#f2f2f2", bordercolor="#1c1c1c",
                        lightcolor="#f2f2f2", darkcolor="#f2f2f2")
        self.progress = ttk.Progressbar(self.root, style="Treta.Horizontal.TProgressbar", length=W - 80, maximum=1.0)
        self.canvas.create_window(40, H - 52, anchor="nw", window=self.progress)
        self.status_id = self.canvas.create_text(40, H - 22, anchor="w", text="", fill=MUTED, font=("Segoe UI", 10))
        self.version_id = self.canvas.create_text(W - 40, H - 22, anchor="e", text="", fill=MUTED, font=("Segoe UI", 9))
        self.refresh_state()

    # ---------- utilitarios ----------
    def ui(self, fn, *a):
        self.root.after(0, lambda: fn(*a))

    def set_status(self, text):
        self.canvas.itemconfigure(self.status_id, text=text)

    def set_progress(self, value):
        self.progress["value"] = value

    def load_news(self):
        text = "Sem novidades por enquanto."
        for p in (os.path.join(self.core.base, "novidades.txt"), resource_path("novidades.txt")):
            if os.path.isfile(p):
                try:
                    with open(p, encoding="utf-8") as f:
                        text = f.read()
                    break
                except OSError:
                    pass
        self.news.configure(state="normal")
        self.news.delete("1.0", "end")
        self.news.insert("1.0", text)
        self.news.configure(state="disabled")

    def refresh_state(self):
        if not self.core.has_rom():
            self.set_status("Jogo nao instalado. Clique em ATUALIZAR e escolha o arquivo .gba ou .zip.")
        elif not self.core.find_emulator():
            self.set_status("Emulador mGBA nao encontrado. Defina o caminho em CONFIGURACOES.")
        else:
            self.set_status("Tudo pronto. Bom jogo!")
        v = self.core.cfg.get("installed_version") or "importado manualmente"
        self.canvas.itemconfigure(self.version_id, text="Versao instalada: " + v)
        self.play.set_enabled(True)

    def worker(self, fn):
        threading.Thread(target=fn, daemon=True).start()

    # ---------- acoes ----------
    def on_play(self):
        try:
            proc = self.core.launch()
        except RuntimeError as e:
            messagebox.showwarning(APP_NAME, str(e))
            self.refresh_state()
            return
        self.play.set_enabled(False)
        self.set_status("Jogo em execucao...")

        def wait():
            proc.wait()
            self.ui(self.refresh_state)
        self.worker(wait)

    def on_backup(self):
        try:
            dest = self.core.backup_save()
            messagebox.showinfo(APP_NAME, "Backup criado:\n" + dest)
        except (RuntimeError, OSError) as e:
            messagebox.showwarning(APP_NAME, str(e))

    def on_update(self):
        cfg = self.core.cfg
        if cfg.get("github_repo") and cfg.get("github_token"):
            self.set_status("Procurando atualizacoes...")
            self.worker(self.update_online)
        else:
            self.update_manual()

    def update_manual(self):
        path = filedialog.askopenfilename(title="Escolha o .gba ou o .zip baixado do GitHub",
                                          filetypes=[("Jogo ou zip", "*.gba *.zip"), ("Todos", "*.*")])
        if not path:
            return
        try:
            self.core.import_file(path)
            messagebox.showinfo(APP_NAME, "Jogo atualizado com sucesso!")
        except (RuntimeError, OSError, Exception) as e:
            messagebox.showwarning(APP_NAME, "Nao foi possivel importar:\n%s" % e)
        self.refresh_state()

    def update_online(self):
        try:
            art = self.core.latest_artifact()
            if not self.core.has_update(art) and self.core.has_rom():
                self.ui(self.set_status, "Voce ja esta na versao mais recente.")
                return
            self.ui(self.set_status, "Baixando atualizacao...")
            self.core.download_artifact(art, lambda p: self.ui(self.set_progress, p))
            self.ui(self.set_progress, 0)
            self.ui(self.refresh_state)
            self.ui(messagebox.showinfo, APP_NAME, "Atualizacao instalada!")
        except Exception as e:
            self.ui(self.set_status, "Falha na atualizacao.")
            self.ui(messagebox.showwarning, APP_NAME, str(e))

    def on_settings(self):
        win = tk.Toplevel(self.root)
        win.title("Configuracoes")
        win.configure(bg=PANEL)
        win.resizable(False, False)
        win.grab_set()
        cfg = self.core.cfg
        vars_ = {
            "emulator_path": tk.StringVar(value=cfg["emulator_path"]),
            "rom_path": tk.StringVar(value=cfg["rom_path"]),
            "github_repo": tk.StringVar(value=cfg["github_repo"]),
            "github_token": tk.StringVar(value=cfg["github_token"]),
            "artifact_name": tk.StringVar(value=cfg["artifact_name"]),
            "scale": tk.IntVar(value=int(cfg["scale"])),
            "fullscreen": tk.BooleanVar(value=bool(cfg["fullscreen"])),
        }
        rows = [("Emulador mGBA (mGBA.exe)", "emulator_path", True), ("Arquivo do jogo (.gba)", "rom_path", True),
                ("Repositorio GitHub (usuario/nome)", "github_repo", False), ("Token do GitHub", "github_token", False),
                ("Nome do artifact", "artifact_name", False)]
        for i, (label, key, browse) in enumerate(rows):
            tk.Label(win, text=label, bg=PANEL, fg=FG, font=("Segoe UI", 10)).grid(row=i, column=0, sticky="w", padx=14, pady=6)
            e = tk.Entry(win, textvariable=vars_[key], width=48, bg="#1c1c1c", fg=FG, insertbackground=FG, bd=0,
                         show="*" if key == "github_token" else "")
            e.grid(row=i, column=1, padx=6, pady=6)
            if browse:
                def pick(k=key):
                    p = filedialog.askopenfilename()
                    if p:
                        vars_[k].set(p)
                tk.Button(win, text="...", command=pick, bd=0, bg="#f2f2f2").grid(row=i, column=2, padx=10)
        tk.Label(win, text="Zoom da tela (1 a 8)", bg=PANEL, fg=FG, font=("Segoe UI", 10)).grid(row=5, column=0, sticky="w", padx=14, pady=6)
        tk.Spinbox(win, from_=1, to=8, textvariable=vars_["scale"], width=5).grid(row=5, column=1, sticky="w", padx=6)
        tk.Checkbutton(win, text="Tela cheia", variable=vars_["fullscreen"], bg=PANEL, fg=FG, selectcolor="#1c1c1c",
                       activebackground=PANEL, activeforeground=FG).grid(row=6, column=1, sticky="w", padx=6, pady=4)

        def ok():
            for k, v in vars_.items():
                cfg[k] = v.get()
            self.core.save()
            win.destroy()
            self.refresh_state()
        GButton(win, "SALVAR", ok).grid(row=7, column=1, sticky="e", padx=6, pady=14)

    def run(self):
        self.root.mainloop()


if __name__ == "__main__":
    App().run()
