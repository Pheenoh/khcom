@ Debug name strings: mode_*, BGM_*/SE_* sound names.
@ ROM 0x0126624..0x013B9DC (86,968 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08126624
data_08126624:
	.incbin "roms/B8CE.gba", 0x126624, 0x153b8
