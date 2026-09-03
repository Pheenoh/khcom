.syntax unified
	.text
	.align 2, 0
	.global mode_worldinspect_2
	.thumb
	.thumb_func
	.type mode_worldinspect_2, %function
mode_worldinspect_2:
	.incbin "roms/B8CP.gba", 0xfe320, 0xa4
.syntax divided
