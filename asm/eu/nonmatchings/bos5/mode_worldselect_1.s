.syntax unified
	.text
	.align 2, 0
	.global mode_worldselect_1
	.thumb
	.thumb_func
	.type mode_worldselect_1, %function
mode_worldselect_1:
	.incbin "roms/B8CP.gba", 0xfc8c8, 0x3c0
.syntax divided
