@ Assets and data after the m4a tables.
@ ROM 0x1D6D5ED..0x1ECEB40 (1,447,251 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09D6D5ED
data_09D6D5ED:
	.incbin "roms/B8CE.gba", 0x1d6d5ed, 0x161553
