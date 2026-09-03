@ Per-unit .data after the task descriptors.
@ ROM 0x1EDB7E8..0x1EFAC00 (128,024 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09EDB7E8
data_09EDB7E8:
	.incbin "roms/B8CE.gba", 0x1edb7e8, 0x1f418
