@ Unidentified tail between the tables and the padding.
@ ROM 0x1EFAC00..0x1EFBFDC (5,084 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09EFAC00
data_09EFAC00:
	.incbin "roms/B8CE.gba", 0x1efac00, 0x13dc
