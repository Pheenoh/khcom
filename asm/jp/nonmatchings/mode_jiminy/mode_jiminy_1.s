.syntax unified
	.align 2, 0
	.global mode_jiminy_1
	.thumb
	.thumb_func
	.type mode_jiminy_1, %function
mode_jiminy_1:
	.incbin "roms/B8CJ.gba", 0x5b0d8, 0x8fc
.syntax divided
