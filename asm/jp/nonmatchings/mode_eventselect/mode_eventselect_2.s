.syntax unified
	.align 2, 0
	.global mode_eventselect_2
	.thumb
	.thumb_func
	.type mode_eventselect_2, %function
mode_eventselect_2:
	.incbin "roms/B8CJ.gba", 0x751ac, 0xdbc
.syntax divided
