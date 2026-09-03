.syntax unified
	.text
	.align 2, 0
	.global mode_jiminy_1
	.thumb
	.thumb_func
	.type mode_jiminy_1, %function
mode_jiminy_1:
	.incbin "roms/B8CP.gba", 0xe824, 0xc4c
.syntax divided
