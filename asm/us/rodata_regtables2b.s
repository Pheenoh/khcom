@ Per-unit .data between the point-list table and the task descriptors.
@ ROM 0x1EDA2A0..0x1EDADC8 (2,856 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_09EDA2A0
data_09EDA2A0:
	.incbin "roms/B8CE.gba", 0x1eda2a0, 0xb28
