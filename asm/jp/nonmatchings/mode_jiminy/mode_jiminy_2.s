.syntax unified
	.align 2, 0
	.global mode_jiminy_2
	.thumb
	.thumb_func
	.type mode_jiminy_2, %function
mode_jiminy_2:
	.incbin "roms/B8CJ.gba", 0x5c8c8, 0xa4
.syntax divided
