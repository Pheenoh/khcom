@ Per-unit .data between the chksnd list and the task descriptors.
@ ROM 0x1ED9A1C..0x1EDADC8 (5,036 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09ED9A1C
data_09ED9A1C:
	.incbin "roms/B8CE.gba", 0x1ed9a1c, 0x13ac
