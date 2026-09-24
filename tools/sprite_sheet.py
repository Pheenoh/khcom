import struct
import zlib

SHAPES = {
    (0, 0): (8, 8), (0, 1): (16, 16), (0, 2): (32, 32), (0, 3): (64, 64),
    (1, 0): (16, 8), (1, 1): (32, 8), (1, 2): (32, 16), (1, 3): (64, 32),
    (2, 0): (8, 16), (2, 1): (8, 32), (2, 2): (16, 32), (2, 3): (32, 64),
}
SHAPE_CODES = {size: code for code, size in SHAPES.items()}
FLAGS = ("hflip", "vflip", "fresh")
ATTRIBUTES = ("hflip", "vflip", "pal", "prio", "layer", "fresh", "same", "tile")
PLACEMENT = ("w", "h", "x", "y", "hflip", "vflip", "pal", "prio")
PNG_SIGNATURE = b"\x89PNG\r\n\x1a\n"


class SheetError(Exception):
    pass


def piece_from_oam(attrs):
    a0, a1, a2 = attrs
    if a0 & 0x3F00 or a1 & 0x0E00:
        raise SheetError(f"OAM entry {list(attrs)} uses affine, blend, mosaic or 256-colour bits")
    code = (a0 >> 14, a1 >> 14)
    if code not in SHAPES:
        raise SheetError(f"OAM entry {list(attrs)} has no valid shape")
    w, h = SHAPES[code]
    x, y = a1 & 0x1FF, a0 & 0xFF
    return {"w": w, "h": h, "x": x - 512 if x & 0x100 else x, "y": y - 256 if y & 0x80 else y,
            "hflip": (a1 >> 12) & 1, "vflip": (a1 >> 13) & 1, "pal": a2 >> 12, "prio": (a2 >> 10) & 3,
            "layer": 0, "tile": a2 & 0x3FF}


def oam_from_piece(piece, tile):
    shape, size = SHAPE_CODES[(piece["w"], piece["h"])]
    a0 = (shape << 14) | (piece["y"] & 0xFF)
    a1 = (size << 14) | (piece["vflip"] << 13) | (piece["hflip"] << 12) | (piece["x"] & 0x1FF)
    a2 = (piece["pal"] << 12) | (piece["prio"] << 10) | tile
    return [a0, a1, a2]


def piece_to_yaml(piece):
    item = [f"{piece['w']}x{piece['h']}", piece["x"], piece["y"]]
    attrs = {}
    for name in ATTRIBUTES:
        value = piece.get(name)
        if value or (name == "tile" and value is not None):
            attrs[name] = list(value) if name == "same" else True if name in FLAGS else value
    if attrs:
        item.append(attrs)
    return item


def piece_from_yaml(item):
    if not isinstance(item, list) or len(item) not in (3, 4):
        raise SheetError(f"piece {item} is not [shape, x, y] with an optional attribute map")
    try:
        w, h = (int(v) for v in str(item[0]).split("x"))
    except ValueError:
        raise SheetError(f"piece {item} does not start with a WxH shape")
    if (w, h) not in SHAPE_CODES:
        raise SheetError(f"piece {item} has no OBJ shape {w}x{h}")
    attrs = item[3] if len(item) == 4 else {}
    if not isinstance(attrs, dict) or set(attrs) - set(ATTRIBUTES):
        raise SheetError(f"piece {item} has attributes other than {', '.join(ATTRIBUTES)}")
    piece = {"w": w, "h": h, "x": int(item[1]), "y": int(item[2]),
             "hflip": int(bool(attrs.get("hflip"))), "vflip": int(bool(attrs.get("vflip"))),
             "pal": int(attrs.get("pal", 0)), "prio": int(attrs.get("prio", 0)), "layer": int(attrs.get("layer", 0))}
    if not (-256 <= piece["x"] < 256 and -128 <= piece["y"] < 128 and 0 <= piece["pal"] < 16
            and 0 <= piece["prio"] < 4 and piece["layer"] >= 0):
        raise SheetError(f"piece {item} is outside the OAM ranges")
    if attrs.get("fresh"):
        piece["fresh"] = True
    if "same" in attrs:
        piece["same"] = tuple(int(v) for v in attrs["same"])
        if len(piece["same"]) != 2 or piece["layer"]:
            raise SheetError(f"piece {item} must name its tile owner as [frame, piece] and has no layer")
    if "tile" in attrs:
        piece["tile"] = int(attrs["tile"])
        if not 0 <= piece["tile"] < 1024 or piece["layer"] or "same" in piece or piece.get("fresh"):
            raise SheetError(f"piece {item} names a tile outside 0-1023 or mixes it with packing attributes")
    return piece


def tile_rows(block, tile, w, h):
    tw = w // 8
    rows = [bytearray(w) for _ in range(h)]
    for ty in range(h // 8):
        for tx in range(tw):
            base = (tile + ty * tw + tx) * 32
            if base + 32 > len(block):
                raise SheetError(f"tile {tile + ty * tw + tx} is outside the {len(block) // 32}-tile block")
            for yy in range(8):
                row = rows[ty * 8 + yy]
                for xx in range(4):
                    b = block[base + yy * 4 + xx]
                    row[tx * 8 + xx * 2] = b & 15
                    row[tx * 8 + xx * 2 + 1] = b >> 4
    return rows


def rows_tiles(rows, w, h):
    out = bytearray()
    for ty in range(h // 8):
        for tx in range(w // 8):
            for yy in range(8):
                row = rows[ty * 8 + yy]
                for xx in range(4):
                    out.append(row[tx * 8 + xx * 2] | (row[tx * 8 + xx * 2 + 1] << 4))
    return bytes(out)


def flipped(rows, hflip, vflip):
    if hflip:
        rows = [row[::-1] for row in rows]
    if vflip:
        rows = rows[::-1]
    return rows


def colours(rows, piece):
    bank = piece["pal"] << 4
    return [bytes(bank | v if v else 0 for v in row) for row in flipped(rows, piece["hflip"], piece["vflip"])]


class Sheet:
    def __init__(self, layout):
        self.cell = tuple(layout["cell"])
        self.anchor = tuple(layout["anchor"])
        self.columns = layout["columns"]
        count = len(layout["frames"])
        if self.columns < 1 or min(self.cell) < 1:
            raise SheetError("a sheet needs a cell size and at least one column")
        self.width = self.cell[0] * self.columns
        self.height = self.cell[1] * ((count + self.columns - 1) // self.columns)
        for index, frame in enumerate(layout["frames"]):
            for piece in frame:
                x = self.anchor[0] + piece["x"]
                y = self.anchor[1] + piece["y"]
                if x < 0 or y < 0 or x + piece["w"] > self.cell[0] or y + piece["h"] > self.cell[1]:
                    raise SheetError(f"frame {index} has a {piece['w']}x{piece['h']} piece outside its cell")

    def blank(self):
        return bytearray(self.width * self.height)

    def origin(self, index):
        return ((index % self.columns) * self.cell[0] + self.anchor[0],
                (index // self.columns) * self.cell[1] + self.anchor[1])

    def read(self, layer, index, piece):
        ox, oy = self.origin(index)
        rows = []
        for r in range(piece["h"]):
            base = (oy + piece["y"] + r) * self.width + ox + piece["x"]
            rows.append(bytes(layer[base:base + piece["w"]]))
        return rows

    def write(self, layer, index, piece, rows, opaque_only):
        ox, oy = self.origin(index)
        for r, row in enumerate(rows):
            base = (oy + piece["y"] + r) * self.width + ox + piece["x"]
            if opaque_only:
                for c, v in enumerate(row):
                    if v:
                        layer[base + c] = v
            else:
                layer[base:base + piece["w"]] = row

    def cell_rows(self, layer, index):
        ox = (index % self.columns) * self.cell[0]
        oy = (index // self.columns) * self.cell[1]
        return [bytes(layer[(oy + r) * self.width + ox:(oy + r) * self.width + ox + self.cell[0]])
                for r in range(self.cell[1])]


def owner_of(frames, index, position, piece):
    other, slot = piece["same"]
    if (other, slot) >= (index, position) or other < 0 or slot < 0 or slot >= len(frames[other]):
        raise SheetError(f"frame {index} piece {position} shares tiles with a piece that does not precede it")
    owner = frames[other][slot]
    if (owner["w"], owner["h"]) != (piece["w"], piece["h"]):
        raise SheetError(f"frame {index} piece {position} shares tiles with a piece of another shape")
    return other, slot


def pack(frames, stored):
    runs = {}
    tiles = []
    block = bytearray()
    for index, (frame, datas) in enumerate(zip(frames, stored)):
        numbers = []
        for position, (piece, data) in enumerate(zip(frame, datas)):
            key = (piece["w"], piece["h"], data)
            if "same" in piece:
                other, slot = piece["same"]
                tile = (tiles[other] if other < index else numbers)[slot]
            elif key in runs and not piece.get("fresh"):
                tile = runs[key]
            else:
                tile = len(block) // 32
                block += data
                runs[key] = tile
            if tile + len(data) // 32 > 1024:
                raise SheetError(f"frame {index} piece {position} needs tiles past 1023, the last OBJ tile number")
            numbers.append(tile)
        tiles.append(numbers)
    return tiles, bytes(block)


def assign_layer(claims, piece, rows):
    layer = 1
    while True:
        if layer > len(claims):
            claims.append({})
        claim = claims[layer - 1]
        if all(claim.get((piece["x"] + c, piece["y"] + r), v) == v for r, row in enumerate(rows) for c, v in enumerate(row)):
            break
        layer += 1
    for r, row in enumerate(rows):
        for c, v in enumerate(row):
            claim[(piece["x"] + c, piece["y"] + r)] = v
    return layer


def canonical(frames, stored, values):
    pieces = [p for frame in frames for p in frame]
    if not pieces:
        raise SheetError("the set has no pieces")
    x0 = min(p["x"] for p in pieces)
    y0 = min(p["y"] for p in pieces)
    described = [[{k: v for k, v in p.items() if k != "tile"} for p in frame] for frame in frames]
    layout = {"cell": [max(p["x"] + p["w"] for p in pieces) - x0, max(p["y"] + p["h"] for p in pieces) - y0],
              "anchor": [-x0, -y0], "columns": min(len(frames), 8), "frames": described}
    sheet = Sheet(layout)
    main = sheet.blank()
    for index, frame in enumerate(frames):
        for p, rows in zip(reversed(frame), reversed(values[index])):
            sheet.write(main, index, p, rows, True)
    runs = {}
    owners = {}
    position = 0
    for index, frame in enumerate(frames):
        claims = []
        for slot, p in enumerate(frame):
            piece = described[index][slot]
            key = (p["w"], p["h"], stored[index][slot])
            clean = sheet.read(main, index, p) == values[index][slot]
            if p["tile"] == position:
                if key in runs:
                    piece["fresh"] = True
                runs[key] = p["tile"]
                owners[p["tile"]] = (index, slot)
                position += len(key[2]) // 32
            elif p["tile"] not in owners:
                raise SheetError(f"frame {index} piece {slot} uses tiles no earlier piece allocated")
            elif not clean or runs.get(key) != p["tile"]:
                piece["same"] = owners[p["tile"]]
            if not clean and "same" not in piece:
                piece["layer"] = assign_layer(claims, piece, values[index][slot])
    return layout


def decode(oam_frames, block, layout=None):
    frames = [[piece_from_oam(a) for a in frame] for frame in oam_frames]
    stored = []
    values = []
    for frame in frames:
        raw = [tile_rows(block, p["tile"], p["w"], p["h"]) for p in frame]
        stored.append([rows_tiles(rows, p["w"], p["h"]) for p, rows in zip(frame, raw)])
        values.append([colours(rows, p) for p, rows in zip(frame, raw)])
    if layout is None:
        layout = canonical(frames, stored, values)
    elif len(layout["frames"]) != len(frames) or any(len(a) != len(b) for a, b in zip(layout["frames"], frames)):
        raise SheetError("the description has a different number of frames or pieces than the ROM")
    for index, (described, found) in enumerate(zip(layout["frames"], frames)):
        for position, (piece, rom) in enumerate(zip(described, found)):
            if any(piece[k] != rom[k] for k in PLACEMENT):
                raise SheetError(f"frame {index} piece {position} is not where, or not what, the ROM places")
    sheet = Sheet(layout)
    layers = [sheet.blank() for _ in range(layer_count(layout))]
    for index, frame in enumerate(layout["frames"]):
        for p, rows in zip(reversed(frame), reversed(values[index])):
            sheet.write(layers[0], index, p, rows, True)
        claims = {}
        for position, (p, rows) in enumerate(zip(frame, values[index])):
            if not p["layer"]:
                continue
            claim = claims.setdefault(p["layer"], {})
            for r, row in enumerate(rows):
                for c, v in enumerate(row):
                    if claim.setdefault((p["x"] + c, p["y"] + r), v) != v:
                        raise SheetError(f"frame {index} piece {position} disagrees with another piece of layer {p['layer']}")
            sheet.write(layers[p["layer"]], index, p, rows, False)
    return layout, layers


def layer_count(layout):
    return 1 + max((p["layer"] for frame in layout["frames"] for p in frame), default=0)


def encode(layout, layers):
    frames = layout["frames"]
    sheet = Sheet(layout)
    if any("tile" in p for frame in frames for p in frame):
        raise SheetError("a sheet that packs its own tiles does not name tile numbers")
    if len(layers) != layer_count(layout):
        raise SheetError(f"the set needs {layer_count(layout)} layers, the sheets hold {len(layers)}")
    if any(len(layer) != sheet.width * sheet.height for layer in layers):
        raise SheetError(f"a sheet layer is not {sheet.width}x{sheet.height}")
    stored = []
    composite = sheet.blank()
    for index, frame in enumerate(frames):
        datas = []
        drawn = []
        for position, p in enumerate(frame):
            if "same" in p:
                other, slot = owner_of(frames, index, position, p)
                data = (stored[other] if other < index else datas)[slot]
                rows = colours(tile_rows(data, 0, p["w"], p["h"]), p)
            else:
                rows = sheet.read(layers[p["layer"]], index, p)
                for row in rows:
                    for v in row:
                        if v and v >> 4 != p["pal"]:
                            raise SheetError(f"frame {index} piece {position} holds a colour of bank {v >> 4} but draws with bank {p['pal']}")
                indices = flipped([bytes(v & 15 for v in row) for row in rows], p["hflip"], p["vflip"])
                data = rows_tiles(indices, p["w"], p["h"])
            datas.append(data)
            drawn.append(rows)
        for p, rows in zip(reversed(frame), reversed(drawn)):
            sheet.write(composite, index, p, rows, True)
        if sheet.cell_rows(composite, index) != sheet.cell_rows(layers[0], index):
            raise SheetError(f"frame {index} of the sheet differs from what its pieces draw")
        stored.append(datas)
    tiles, block = pack(frames, stored)
    oam = [[oam_from_piece(p, tile) for p, tile in zip(frame, numbers)] for frame, numbers in zip(frames, tiles)]
    return oam, block


def decode_view(oam_frames, block, layout=None):
    frames = [[piece_from_oam(a) for a in frame] for frame in oam_frames]
    if layout is None:
        pieces = [p for frame in frames for p in frame]
        if not pieces:
            raise SheetError("the set has no pieces")
        x0 = min(p["x"] for p in pieces)
        y0 = min(p["y"] for p in pieces)
        layout = {"cell": [max(p["x"] + p["w"] for p in pieces) - x0, max(p["y"] + p["h"] for p in pieces) - y0],
                  "anchor": [-x0, -y0], "columns": min(len(frames), 8), "frames": [[dict(p) for p in frame] for frame in frames]}
    elif len(layout["frames"]) != len(frames) or any(len(a) != len(b) for a, b in zip(layout["frames"], frames)):
        raise SheetError("the description has a different number of frames or pieces than the ROM")
    for index, (described, found) in enumerate(zip(layout["frames"], frames)):
        for position, (piece, rom) in enumerate(zip(described, found)):
            if any(piece.get(k) != rom[k] for k in PLACEMENT + ("tile",)):
                raise SheetError(f"frame {index} piece {position} is not where, or not what, the ROM places")
    sheet = Sheet(layout)
    main = sheet.blank()
    for index, frame in enumerate(layout["frames"]):
        for p in reversed(frame):
            sheet.write(main, index, p, colours(tile_rows(block, p["tile"], p["w"], p["h"]), p), True)
    return layout, [main]


def encode_view(layout, layers, block):
    sheet = Sheet(layout)
    if len(layers) != 1 or len(layers[0]) != sheet.width * sheet.height:
        raise SheetError(f"a sheet that borrows its tiles is one {sheet.width}x{sheet.height} layer")
    composite = sheet.blank()
    for index, frame in enumerate(layout["frames"]):
        for position, p in enumerate(frame):
            if "tile" not in p or p["layer"] or "same" in p:
                raise SheetError(f"frame {index} piece {position} of a sheet that borrows its tiles needs a tile number and nothing else")
        for p in reversed(frame):
            sheet.write(composite, index, p, colours(tile_rows(block, p["tile"], p["w"], p["h"]), p), True)
        if sheet.cell_rows(composite, index) != sheet.cell_rows(layers[0], index):
            raise SheetError(f"frame {index} of the sheet differs from what its pieces draw from the borrowed tiles")
    return [[oam_from_piece(p, p["tile"]) for p in frame] for frame in layout["frames"]]


def parse_records(data, frame_count, anim_count):
    position = 0
    frames = []
    anims = []

    def halfwords(count):
        nonlocal position
        if position + 2 * count > len(data):
            raise SheetError("the records run past the end of the set")
        values = struct.unpack_from(f"<{count}H", data, position)
        position += 2 * count
        return list(values)

    for _ in range(frame_count):
        count = halfwords(1)[0]
        frames.append([halfwords(3) for _ in range(count)])
        if count and halfwords(1)[0]:
            raise SheetError("a sprite record does not end with a zero halfword")
    for _ in range(anim_count):
        first, second, count = halfwords(3)
        anims.append({"fields": {"unk_00": first, "unk_02": second}, "frames": [halfwords(2) for _ in range(count)]})
    return frames, anims, bytes(data[position:])


def frame_words(oam):
    words = [len(oam)] + [value for attrs in oam for value in attrs]
    return words + [0] if oam else words


def anim_words(anim):
    fields = anim["fields"]
    return [fields["unk_00"], fields["unk_02"], len(anim["frames"])] + [value for frame in anim["frames"] for value in frame]


def record_bytes(oam_frames, anims):
    words = [w for oam in oam_frames for w in frame_words(oam)] + [w for anim in anims for w in anim_words(anim)]
    return struct.pack(f"<{len(words)}H", *words)


def png_chunk(kind, data):
    return struct.pack(">I", len(data)) + kind + data + struct.pack(">I", zlib.crc32(kind + data) & 0xFFFFFFFF)


def write_png(width, height, pixels, palette):
    raw = bytearray()
    for y in range(height):
        raw.append(0)
        raw += pixels[y * width:(y + 1) * width]
    header = struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0)
    plte = b"".join(bytes(rgb) for rgb in palette)
    return (PNG_SIGNATURE + png_chunk(b"IHDR", header) + png_chunk(b"PLTE", plte) + png_chunk(b"tRNS", b"\x00")
            + png_chunk(b"IDAT", zlib.compress(bytes(raw), 9)) + png_chunk(b"IEND", b""))


def unfilter(kind, line, prior, bpp):
    out = bytearray(line)
    if kind == 1:
        for i in range(bpp, len(out)):
            out[i] = (out[i] + out[i - bpp]) & 0xFF
    elif kind == 2:
        for i in range(len(out)):
            out[i] = (out[i] + prior[i]) & 0xFF
    elif kind == 3:
        for i in range(len(out)):
            left = out[i - bpp] if i >= bpp else 0
            out[i] = (out[i] + ((left + prior[i]) >> 1)) & 0xFF
    elif kind == 4:
        for i in range(len(out)):
            a = out[i - bpp] if i >= bpp else 0
            b = prior[i]
            c = prior[i - bpp] if i >= bpp else 0
            p = a + b - c
            pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
            out[i] = (out[i] + (a if pa <= pb and pa <= pc else b if pb <= pc else c)) & 0xFF
    elif kind != 0:
        raise SheetError(f"unknown PNG filter {kind}")
    return out


def read_png(data):
    if data[:8] != PNG_SIGNATURE:
        raise SheetError("not a PNG file")
    position = 8
    header = None
    idat = bytearray()
    while position + 8 <= len(data):
        length, kind = struct.unpack(">I4s", data[position:position + 8])
        body = data[position + 8:position + 8 + length]
        position += 12 + length
        if kind == b"IHDR":
            header = struct.unpack(">IIBBBBB", body)
        elif kind == b"IDAT":
            idat += body
        elif kind == b"IEND":
            break
    if header is None:
        raise SheetError("the PNG file has no header")
    width, height, depth, colour, _compression, _filter, interlace = header
    if colour != 3 or interlace or depth not in (1, 2, 4, 8):
        raise SheetError("a sheet must be an indexed, non-interlaced PNG file")
    raw = zlib.decompress(bytes(idat))
    stride = (width * depth + 7) // 8
    if len(raw) < height * (stride + 1):
        raise SheetError("the PNG image data is truncated")
    pixels = bytearray(width * height)
    prior = bytearray(stride)
    per = 8 // depth
    mask = (1 << depth) - 1
    for y in range(height):
        start = y * (stride + 1)
        line = unfilter(raw[start], raw[start + 1:start + 1 + stride], prior, 1)
        prior = line
        if depth == 8:
            pixels[y * width:(y + 1) * width] = line[:width]
        else:
            for x in range(width):
                pixels[y * width + x] = (line[x // per] >> (8 - depth * (x % per + 1))) & mask
    return width, height, pixels


def sheet_palette(palette_bytes, count):
    entries = []
    for offset in range(0, len(palette_bytes) - 1, 2):
        value = palette_bytes[offset] | (palette_bytes[offset + 1] << 8)
        entries.append(tuple(((value >> shift) & 0x1F) * 255 // 31 for shift in (0, 5, 10)))
    while len(entries) < count:
        grey = (len(entries) % 16) * 17
        entries.append((grey, grey, grey))
    return entries[:count]


def write_sheets(layout, layers, palette_bytes):
    sheet = Sheet(layout)
    count = (max(max(layer, default=0) for layer in layers) // 16 + 1) * 16
    palette = sheet_palette(palette_bytes, count)
    main = write_png(sheet.width, sheet.height, layers[0], palette)
    if len(layers) == 1:
        return main, None
    stacked = b"".join(bytes(layer) for layer in layers[1:])
    return main, write_png(sheet.width, sheet.height * (len(layers) - 1), stacked, palette)


def read_sheets(layout, main, extra):
    sheet = Sheet(layout)
    count = layer_count(layout)
    width, height, pixels = read_png(main)
    if (width, height) != (sheet.width, sheet.height):
        raise SheetError(f"the sheet is {width}x{height}, the description needs {sheet.width}x{sheet.height}")
    layers = [pixels]
    if count > 1:
        if extra is None:
            raise SheetError(f"the set needs a layer sheet holding {count - 1} layers")
        width, height, pixels = read_png(extra)
        if (width, height) != (sheet.width, sheet.height * (count - 1)):
            raise SheetError(f"the layer sheet is {width}x{height}, the description needs {sheet.width}x{sheet.height * (count - 1)}")
        size = sheet.width * sheet.height
        layers += [pixels[i * size:(i + 1) * size] for i in range(count - 1)]
    return layers
