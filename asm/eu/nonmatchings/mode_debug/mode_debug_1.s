.syntax unified
	.text
	.align 2, 0
	.global mode_debug_1
	.thumb
	.thumb_func
	.type mode_debug_1, %function
mode_debug_1:
	.incbin "roms/B8CP.gba", 0xb4c8, 0x608
.syntax divided
