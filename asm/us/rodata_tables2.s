@ Binary lookup tables and zero-padded runs.
@ ROM 0x0125E24..0x0126624 (2,048 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08125E24
data_08125E24:
	.incbin "roms/B8CE.gba", 0x125e24, 0x800
