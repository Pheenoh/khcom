@ Thumb-to-ARM interworking veneers at the end of the code section.
@ ROM 0x01213C4..0x01213DC (24 bytes).

	.section .rodata
	.global data_081213C4
data_081213C4:
	.thumb_func
	.global func_081213C4
func_081213C4:
	.incbin "roms/B8CE.gba", 0x1213c4, 0x8
	.thumb_func
	.global func_081213CC
func_081213CC:
	.incbin "roms/B8CE.gba", 0x1213cc, 0x8
	.thumb_func
	.global func_081213D4
func_081213D4:
	.incbin "roms/B8CE.gba", 0x1213d4, 0x8
