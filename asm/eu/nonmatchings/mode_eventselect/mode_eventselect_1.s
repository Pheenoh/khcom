.syntax unified
	.text
	.align 2, 0
	.global mode_eventselect_1
	.thumb
	.thumb_func
	.type mode_eventselect_1, %function
mode_eventselect_1:
	.incbin "roms/B8CP.gba", 0x744c0, 0x254
.syntax divided
