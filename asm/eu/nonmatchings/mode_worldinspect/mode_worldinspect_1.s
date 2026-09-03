.syntax unified
	.text
	.align 2, 0
	.global mode_worldinspect_1
	.thumb
	.thumb_func
	.type mode_worldinspect_1, %function
mode_worldinspect_1:
	.incbin "roms/B8CP.gba", 0xfe19c, 0x184
.syntax divided
