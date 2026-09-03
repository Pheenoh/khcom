@ Debug name strings: mode_*, task and script names.
@ ROM 0x0130E5C..0x013B9DC (43,904 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_08130E5C
data_08130E5C:
	.incbin "roms/B8CE.gba", 0x130e5c, 0xab80
