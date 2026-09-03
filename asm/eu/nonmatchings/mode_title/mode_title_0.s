.syntax unified
	.text
	.align 2, 0
	.global mode_title_0
	.thumb
	.thumb_func
	.type mode_title_0, %function
mode_title_0:
	.incbin "roms/B8CP.gba", 0xd2400, 0x1b8
.syntax divided
