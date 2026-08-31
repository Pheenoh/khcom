.syntax unified
	.align 2, 0
	.global mode_eventselect_1
	.thumb
	.thumb_func
	.type mode_eventselect_1, %function
mode_eventselect_1:
	.incbin "roms/B8CJ.gba", 0x74f74, 0x238
.syntax divided
