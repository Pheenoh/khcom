@ task_* name strings and adjacent data.
@ ROM 0x013B9DC..0x0140000 (17,956 bytes). Split out of this incbin
@ as regions get identified.

	.section .rodata
	.global data_0813B9DC
data_0813B9DC:
	.incbin "roms/B8CE.gba", 0x13b9dc, 0x4624
