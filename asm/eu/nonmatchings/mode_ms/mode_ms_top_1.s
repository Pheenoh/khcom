.syntax unified
	.text
	.align 2, 0
	.global mode_ms_top_1
	.thumb
	.thumb_func
	.type mode_ms_top_1, %function
mode_ms_top_1:
	.incbin "roms/B8CP.gba", 0x100448, 0x51c
.syntax divided
