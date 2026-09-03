.syntax unified
	.text
	.align 2, 0
	.global mode_pooh_1
	.thumb
	.thumb_func
	.type mode_pooh_1, %function
mode_pooh_1:
	.incbin "roms/B8CP.gba", 0xc4240, 0x104
.syntax divided
