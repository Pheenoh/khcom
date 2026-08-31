@ All data past the code section (rodata, strings, script text, assets,
@ descriptor tables, padding). See docs/rom_map.md. Split out of this incbin
@ as regions get identified.

	.section .text
	.global data_08121330
data_08121330:
	.incbin "roms/B8CE.gba", 0x121330, 0x1C4C18C
