@ Debug name strings: mode_*, task and script names.
@ ROM 0x0133E54..0x013B9DC (31,624 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08133E54
data_08133E54:
	.incbin "roms/B8CE.gba", 0x133e54, 0x7b88
