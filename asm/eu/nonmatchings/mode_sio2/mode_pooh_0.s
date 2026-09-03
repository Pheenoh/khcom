.syntax unified
	.text
	.align 2, 0
	.global mode_pooh_0
	.thumb
	.thumb_func
	.type mode_pooh_0, %function
mode_pooh_0:
	.incbin "roms/B8CP.gba", 0xc3f88, 0x2b8
.syntax divided
