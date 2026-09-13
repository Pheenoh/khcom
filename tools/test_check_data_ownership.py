import tempfile
import subprocess
import unittest
from pathlib import Path

from check_data_ownership import ROOT, active_objects, check, read_symbols


def symbol(name='gState', value=0, size=4, kind='B'):
    return dict(name=name, value=value, size=size, kind=kind)


class OwnershipTests(unittest.TestCase):
    def setUp(self):
        self.objects = {'src/state.o': [symbol()]}
        self.linked = [symbol(value=0x02000000)]
        self.ledger = set()
        self.placements = {('src/state.o', 'bss'): 0x02000000}
        self.contracts = {}
        self.sections = {'.bss.state': {'value': 0x02000000, 'size': 4}}

    def errors(self):
        return check(self.objects, self.linked, self.ledger, self.placements, self.contracts, self.sections)[0]

    def contract(self):
        self.contracts = {'src/state.o': {
            'base': '0x02000000', 'size': '0x4',
            'symbols': {'gState': {'offset': '0x0', 'size': '0x4'}}}}

    def test_owned_storage(self):
        self.assertEqual(self.errors(), [])

    def test_duplicate_owner(self):
        self.objects['src/other.o'] = [symbol()]
        self.assertTrue(any('multiple owners' in error for error in self.errors()))

    def test_absolute_override(self):
        self.ledger.add('gState')
        self.assertTrue(any('overridden' in error for error in self.errors()))

    def test_absolute_ram_symbol(self):
        self.linked.append(symbol('gUnowned', 0x03000000, 0, 'A'))
        self.assertTrue(any('absolute RAM symbol' in error for error in self.errors()))

    def test_absolute_rom_symbol(self):
        self.linked.append(symbol('gRom', 0x08000000, 0, 'A'))
        self.assertEqual(self.errors(), [])

    def test_discarded_storage(self):
        self.linked = []
        self.assertTrue(any('discarded' in error for error in self.errors()))

    def test_wrong_placement(self):
        self.linked[0]['value'] += 4
        self.assertTrue(any('placed incorrectly' in error for error in self.errors()))

    def test_wrong_linked_size(self):
        self.linked[0]['size'] = 8
        self.assertTrue(any('linked size differs' in error for error in self.errors()))

    def test_missing_placement(self):
        self.placements = {}
        self.assertTrue(any('no RAM section placement' in error for error in self.errors()))

    def test_common_storage(self):
        self.objects['src/state.o'][0].update(kind='C', value=4)
        self.placements = {('src/state.o', 'common'): 0x02000000}
        self.assertEqual(self.errors(), [])

    def test_overlapping_different_names(self):
        self.objects['src/other.o'] = [symbol('gOther')]
        self.placements['src/other.o', 'bss'] = 0x02000000
        self.linked.append(symbol('gOther', value=0x02000000))
        self.assertTrue(any('overlapping RAM definitions' in error for error in self.errors()))

    def test_adjacent_definitions(self):
        self.objects['src/other.o'] = [symbol('gOther')]
        self.placements['src/other.o', 'bss'] = 0x02000004
        self.linked.append(symbol('gOther', value=0x02000004))
        self.assertEqual(self.errors(), [])

    def test_nested_overlap(self):
        self.objects['src/state.o'][0]['size'] = 16
        self.linked[0]['size'] = 16
        self.objects['src/other.o'] = [symbol('gOther')]
        self.placements['src/other.o', 'bss'] = 0x02000004
        self.linked.append(symbol('gOther', value=0x02000004))
        self.assertTrue(any('overlapping RAM definitions' in error for error in self.errors()))

    def test_storage_extends_outside_ram(self):
        self.placements['src/state.o', 'bss'] = 0x0203FFFE
        self.linked[0]['value'] = 0x0203FFFE
        self.assertTrue(any('extends outside RAM' in error for error in self.errors()))

    def test_contract(self):
        self.contract()
        self.assertEqual(self.errors(), [])

    def multi_section_contract(self):
        self.contract()
        first = self.contracts['src/state.o']
        self.contracts['src/state.o'] = {'sections': [first, {
            'section': '.common.state', 'base': '0x02000020', 'size': '0x4',
            'symbols': {'gCommon': {'offset': '0x0', 'size': '0x4'}}}]}
        self.objects['src/state.o'].append(symbol('gCommon', kind='C', value=4))
        self.linked.append(symbol('gCommon', value=0x02000020))
        self.placements['src/state.o', 'common'] = 0x02000020
        self.sections['.common.state'] = {'value': 0x02000020, 'size': 4}

    def test_multi_section_contract(self):
        self.multi_section_contract()
        self.assertEqual(self.errors(), [])

    def test_multi_section_missing_common(self):
        self.multi_section_contract()
        del self.sections['.common.state']
        self.assertTrue(any('.common.state extent differs' in error for error in self.errors()))

    def test_multi_section_common_drift(self):
        self.multi_section_contract()
        self.linked[1]['value'] += 4
        self.assertTrue(any('expected RAM address' in error for error in self.errors()))

    def test_multi_section_duplicate_member(self):
        self.multi_section_contract()
        group = self.contracts['src/state.o']['sections'][1]
        group['symbols']['gState'] = {'offset': 0, 'size': 4}
        self.assertTrue(any('duplicate objects' in error for error in self.errors()))

    def test_multi_section_overlap(self):
        self.multi_section_contract()
        self.contracts['src/state.o']['sections'][1]['base'] = '0x02000002'
        self.assertTrue(any('overlapping contract sections' in error for error in self.errors()))

    def test_multi_section_member_overrun(self):
        self.multi_section_contract()
        group = self.contracts['src/state.o']['sections'][1]
        group['symbols']['gCommon']['offset'] = 4
        self.assertTrue(any('outside its layout contract' in error for error in self.errors()))

    def test_contract_rejects_moved_base(self):
        self.contract()
        self.placements['src/state.o', 'bss'] += 4
        self.linked[0]['value'] += 4
        self.assertTrue(any('expected RAM address' in error for error in self.errors()))

    def test_contract_rejects_extra_definition(self):
        self.contract()
        self.objects['src/state.o'].append(symbol('gExtra', value=4))
        self.assertTrue(any('definition set differs' in error for error in self.errors()))

    def test_contract_rejects_section_growth(self):
        self.contract()
        self.sections['.bss.state']['size'] = 8
        self.assertTrue(any('extent differs' in error for error in self.errors()))

    def test_contract_rejects_missing_section(self):
        self.contract()
        self.sections = {}
        self.assertTrue(any('extent differs' in error for error in self.errors()))

    def test_contract_rejects_wrong_size(self):
        self.contract()
        self.objects['src/state.o'][0]['size'] = 2
        self.assertTrue(any('definition size does not match' in error for error in self.errors()))

    def test_contract_rejects_overlap(self):
        self.contract()
        self.contracts['src/state.o']['symbols']['gOther'] = {'offset': 0, 'size': 4}
        self.assertTrue(any('overlapping' in error for error in self.errors()))

    def test_contract_rejects_overrun(self):
        self.contract()
        self.contracts['src/state.o']['size'] = 2
        self.assertTrue(any('outside its layout contract' in error for error in self.errors()))

    def test_contract_rejects_missing_owner(self):
        self.contract()
        self.objects = {}
        self.assertTrue(any('owner is not linked' in error for error in self.errors()))

    def test_active_objects_ignore_stale_files(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            config = root / 'config' / 'us'
            config.mkdir(parents=True)
            (config / 'units.txt').write_text('state.c -fno-common\nstate.c(.rodata)\nstart.s\n')
            stale = root / 'build' / 'us' / 'src'
            stale.mkdir(parents=True)
            (stale / 'old_state.o').touch()
            self.assertEqual(active_objects(root, 'us'), ['src/state.o'])


class CompilerStorageTests(unittest.TestCase):
    def compile_storage(self, directory, source, flags):
        root = Path(directory)
        src = root / 'storage.c'
        assembly = root / 'storage.s'
        obj = root / 'storage.o'
        src.write_text(source)
        subprocess.run([str(ROOT / 'tools/agbcc/bin/agbcc'), '-O2', *flags,
                        '-o', str(assembly), str(src)], check=True, capture_output=True)
        subprocess.run(['arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', str(obj), str(assembly)],
                       check=True, capture_output=True)
        return obj

    def test_common_attribute_overrides_no_common(self):
        with tempfile.TemporaryDirectory() as directory:
            obj = self.compile_storage(directory,
                'int ordinary;\nint forced __attribute__((common));\n', ['-fno-common'])
            symbols = {s['name']: s for s in read_symbols(obj, 'arm-none-eabi-')}
            self.assertEqual(symbols['ordinary']['kind'], 'B')
            self.assertEqual(symbols['forced']['kind'], 'C')

    def test_common_storage_alignment(self):
        with tempfile.TemporaryDirectory() as directory:
            obj = self.compile_storage(directory,
                'struct SpriteState { unsigned words[9]; } sprite;\n'
                'struct MapResources { unsigned words[12]; } resources;\n'
                'unsigned char inventory[270];\nvoid* pointer;\n', [])
            output = subprocess.check_output(['arm-none-eabi-readelf', '-sW', str(obj)], text=True)
            common = {}
            for line in output.splitlines():
                fields = line.split()
                if len(fields) == 8 and fields[6] == 'COM':
                    common[fields[7]] = (int(fields[1], 16), int(fields[2]))
            self.assertEqual(common, {'sprite': (16, 36), 'resources': (16, 48),
                                      'inventory': (16, 272), 'pointer': (4, 4)})

    def test_common_halfword_uses_word_allocation(self):
        with tempfile.TemporaryDirectory() as directory:
            obj = self.compile_storage(directory,
                'volatile unsigned short flag __attribute__((common));\n'
                'typedef char FlagType[(sizeof(flag) == 2) ? 1 : -1];\n', ['-fno-common'])
            symbols = {s['name']: s for s in read_symbols(obj, 'arm-none-eabi-')}
            self.assertEqual(symbols['flag']['kind'], 'C')
            self.assertEqual(symbols['flag']['size'], 4)


if __name__ == '__main__':
    unittest.main()
