@ Per-unit .data between the chksnd list and the mode_vsbattle descriptor.
@ ROM 0x1ED9A1C..0x1ED9BA8 (396 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09ED9A1C
data_09ED9A1C:
	.incbin "roms/B8CE.gba", 0x1ed9a1c, 0x18c
