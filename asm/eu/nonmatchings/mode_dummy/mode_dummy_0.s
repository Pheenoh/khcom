.syntax unified
	.text
	.align 2, 0
	.global mode_dummy_0
	.thumb
	.thumb_func
	.type mode_dummy_0, %function
mode_dummy_0:
	.incbin "roms/B8CP.gba", 0xc8b4, 0xcc
.syntax divided
