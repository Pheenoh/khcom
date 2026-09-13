import tempfile
import unittest
from pathlib import Path

from check_data_ownership import active_objects, check


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


if __name__ == '__main__':
    unittest.main()
