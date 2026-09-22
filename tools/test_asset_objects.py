import copy
import hashlib
import os
import tempfile
import unittest
from pathlib import Path

from asset_objects import materialize_assets
from regional_data import asset_symbols, check_layout, normalize_sidecar


class AssetObjectsTest(unittest.TestCase):
    def setUp(self):
        self.data = bytes(range(96))
        self.asset = {'name': 'tiles', 'address': 0x08000020, 'size': 32,
                      'sha256': hashlib.sha256(self.data[32:64]).hexdigest(),
                      'kind': 'Tiles4bpp', 'unit': 'graphics.s'}
        self.document = {'version': 1, 'regions': {'eu': {'binary_assets': [self.asset]}}}

    def plan(self):
        return normalize_sidecar(self.document, {'eu': self.data})['regions']['eu']

    def test_object_is_not_an_absolute_binding(self):
        self.assertEqual(asset_symbols(self.plan()), [])
        with self.assertRaises(ValueError):
            asset_symbols(self.plan(), [('tiles', 0x08000020)])

    def test_requires_owner_and_whole_tiles(self):
        del self.asset['unit']
        with self.assertRaises(ValueError):
            self.plan()
        self.asset['unit'] = 'graphics.s'
        self.asset['size'] = 31
        with self.assertRaises(ValueError):
            self.plan()

    def test_content_bounds_and_overlap(self):
        self.asset['sha256'] = '0' * 64
        with self.assertRaises(ValueError):
            self.plan()
        self.asset['sha256'] = hashlib.sha256(self.data[32:64]).hexdigest()
        self.asset['address'] = 0x08000060
        with self.assertRaises(ValueError):
            self.plan()
        self.asset['address'] = 0x08000020
        other = copy.deepcopy(self.asset)
        other['name'] = 'overlap'
        self.document['regions']['eu']['binary_assets'].append(other)
        with self.assertRaises(ValueError):
            self.plan()

    def test_real_object_identity_and_size(self):
        plan = self.plan()
        symbol = {'name': 'tiles', 'value': 32, 'size': 32, 'flags': 'g     O', 'section': '.rodata'}
        objects = {'graphics.s': {'symbols': [symbol]}}
        linked = {'symbols': [{**symbol, 'value': 0x08000020, 'section': '.text'}]}
        self.assertEqual(check_layout(plan, objects, linked), [])
        linked['symbols'][0]['section'] = '*ABS*'
        self.assertTrue(check_layout(plan, objects, linked))
        linked['symbols'][0]['section'] = '.text'
        linked['symbols'][0]['size'] = 31
        self.assertTrue(check_layout(plan, objects, linked))
        self.assertTrue(check_layout(plan, {}, linked))

    def test_emission_preserves_source_stream(self):
        previous = Path.cwd()
        with tempfile.TemporaryDirectory() as temporary:
            os.chdir(temporary)
            try:
                source = Path('asm/eu/graphics.s')
                source.parent.mkdir(parents=True)
                source.write_text('.section .rodata\n.global host\nhost:\n'
                                  '.incbin "assets/eu/08000000-08000060.bin"\n')
                units = [(source, 'build/eu/asm/graphics.o', None)]
                result = materialize_assets(self.plan(), units, 'eu', 'build/eu')
                text = result[0][0].read_text()
                self.assertIn('.type tiles, %object\ntiles:', text)
                self.assertIn('.size tiles, . - tiles', text)
                self.assertIn('"assets/eu/08000000-08000060.bin", 0, 32', text)
                self.assertIn('"assets/eu/08000000-08000060.bin", 32, 32', text)
                self.assertIn('"assets/eu/08000000-08000060.bin", 64, 32', text)
                with self.assertRaises(ValueError):
                    materialize_assets(self.plan(), [], 'eu', 'build/eu')
                self.asset['address'] = 0x08000060
                with self.assertRaises(ValueError):
                    materialize_assets({'assets': [self.asset]}, units, 'eu', 'build/eu')
            finally:
                os.chdir(previous)


if __name__ == '__main__':
    unittest.main()
