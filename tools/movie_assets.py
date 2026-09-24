import hashlib
import math
import struct
import sys
from pathlib import Path

import yaml

import baserom

YAML_LOADER = getattr(yaml, "CSafeLoader", yaml.SafeLoader)


def load_yaml(text):
    return yaml.load(text, Loader=YAML_LOADER)


def movie_extent(data):
    def need(at, size):
        if at < 0 or size < 0 or at + size > len(data):
            raise ValueError('movie block lies outside its file')

    def word(at):
        need(at, 4)
        return struct.unpack_from('<I', data, at)[0]

    need(0, 36)
    width, height, rate, frames, blocks, channels, sample_rate, codec = struct.unpack_from('<IIf5I', data)
    if not width or width > 288 or width % 8 or not height or height % 8:
        raise ValueError('invalid movie dimensions')
    if not math.isfinite(rate) or rate <= 0 or not frames or channels not in (0, 1, 2):
        raise ValueError('invalid movie timing or channel count')
    if channels and (not blocks or not sample_rate or codec not in (1, 2)):
        raise ValueError('invalid movie audio header')
    type_size = word(32)
    need(36, type_size)
    if type_size < frames or type_size % 4 or any(value > 2 for value in data[36:36 + frames]):
        raise ValueError('invalid movie frame-type table')
    pos = 36 + type_size

    def payload(at, count):
        size = word(at)
        length = word(at + 4)
        if size % 4 or size < 2 + count * 2:
            raise ValueError('invalid movie block-size table')
        need(at + 8, size)
        maximum = struct.unpack_from('<H', data, at + 8)[0]
        lengths = struct.unpack_from('<' + 'H' * count, data, at + 10)
        if sum(lengths) != length or max(lengths) > maximum:
            raise ValueError('movie block sizes do not cover their payload')
        begin = at + 8 + size
        need(begin, length)
        return begin + length

    pos = payload(pos, frames)
    if channels:
        type_size = word(pos)
        need(pos + 4, type_size)
        if type_size < blocks or type_size % 4:
            raise ValueError('invalid movie audio-type table')
        pos = payload(pos + 4 + type_size, blocks)
    return pos


def load_movie_assets(path, version, rom):
    value = load_yaml(Path(path).read_text())
    if set(value) != {'version', 'regions'} or value['version'] != 1:
        raise ValueError('invalid movie asset manifest')
    if set(value['regions']) != {'us', 'jp', 'eu'}:
        raise ValueError('movie asset manifest requires all regions')
    result = []
    names = set()
    for asset in value['regions'][version]:
        if set(asset) != {'name', 'symbol', 'address', 'size', 'sha256', 'after'}:
            raise ValueError('invalid movie asset record')
        name, after = asset['name'], asset['after']
        if not name.startswith('asset_') or not after.startswith('asset_') or name in names:
            raise ValueError('invalid or duplicate movie asset name')
        names.add(name)
        address, size = int(asset['address'], 16), asset['size']
        offset = address - 0x08000000
        if offset < 0 or type(size) is not int or size <= 0 or offset + size > len(rom):
            raise ValueError('movie asset lies outside ROM')
        data = rom[offset:offset + size]
        if hashlib.sha256(data).hexdigest() != asset['sha256']:
            raise ValueError('movie asset hash differs: ' + name)
        if movie_extent(data) != size:
            raise ValueError('movie asset extent differs: ' + name)
        result.append((address, address + size, name, after))
    result.sort()
    for first, second in zip(result, result[1:]):
        if first[1] > second[0]:
            raise ValueError('movie asset extents overlap')
    return result


def apply_movie_regions(found, placements, assets):
    result = list(found)
    for lo, hi, name, after in assets:
        for at, size, owner in placements:
            if size and at < hi and at + size > lo:
                raise ValueError('movie asset overlaps compiler-owned data: ' + owner)
        result = [(at, base, how) for at, base, how in result if not lo <= at < hi]
        result.extend([(lo, name, 'explicit'), (hi, after, 'explicit')])
    return result


if __name__ == '__main__':
    root = Path(__file__).resolve().parents[1]
    for version in ('us', 'jp', 'eu'):
        assets = load_movie_assets(root / 'config/movie_assets.yaml', version, baserom.read(version, purpose='tools/movie_assets.py'))
        print(version + ': movie assets OK (' + str(sum(hi - lo for lo, hi, _, _ in assets)) + ' bytes)')
