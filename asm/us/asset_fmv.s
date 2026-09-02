@ High entropy, likely FMV video data.
@ ROM 0x1B00000..0x1D00000 (2,097,152 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09B00000
data_09B00000:
	.incbin "roms/B8CE.gba", 0x1b00000, 0x200000
