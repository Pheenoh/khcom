@ Thumb-to-ARM interworking veneers at the end of the code section.
@ ROM 0x01213C4..0x01213DC (24 bytes).

	.section .rodata
	.global data_081213C4
data_081213C4:
	.incbin "roms/B8CE.gba", 0x1213c4, 0x18
