from PIL import Image, ImageDraw, ImageFont
W, H = 560, 170
img = Image.new('RGBA', (W, H), (0, 0, 0, 0))
f1 = ImageFont.load_default(size=70); f2 = ImageFont.load_default(size=44)
def grad_text(img, text, font, y, top, bottom):
    m = Image.new('L', (W, H), 0); d = ImageDraw.Draw(m)
    bb = d.textbbox((0, 0), text, font=font); tw, th = bb[2]-bb[0], bb[3]-bb[1]
    x = (W - tw)//2 - bb[0]; d.text((x, y - bb[1]), text, fill=255, font=font)
    # contorno
    o = Image.new('L', (W, H), 0); od = ImageDraw.Draw(o)
    for dx in range(-3, 4):
        for dy in range(-3, 4):
            if dx*dx + dy*dy <= 9: od.text((x+dx, y-bb[1]+dy), text, fill=255, font=font)
    img.paste((0, 0, 0, 255), (0, 0), o)
    g = Image.new('RGBA', (W, H)); gd = ImageDraw.Draw(g)
    for yy in range(y, y + th + 1):
        t = (yy - y) / max(1, th)
        c = tuple(int(top[i] + (bottom[i]-top[i]) * t) for i in range(3)) + (255,)
        gd.line([(0, yy), (W, yy)], fill=c)
    img.paste(g, (0, 0), m)
grad_text(img, 'POKEMON', f1, 6, (255, 255, 255), (170, 170, 170))
grad_text(img, 'TRETA GERAL', f2, 100, (255, 255, 255), (120, 120, 120))
img.save('logo.png'); print(img.size)
