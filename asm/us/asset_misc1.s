@ Assets and data up to the m4a tables.
@ ROM 0x1D00000..0x1D6D4BC (447,676 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09D00000
data_09D00000:
	.incbin "roms/B8CE.gba", 0x1d00000, 0x6d4bc
