@ Registration tables: modes, BGM, and the 218-entry task table.
@ ROM 0x1ECEB40..0x1EFAC00 (180,416 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09ECEB40
data_09ECEB40:
	.incbin "roms/B8CE.gba", 0x1eceb40, 0x2c0c0
