.syntax unified
	.align 2, 0
	.global mode_ms_top_1
	.thumb
	.thumb_func
	.type mode_ms_top_1, %function
mode_ms_top_1:
	.incbin "roms/B8CJ.gba", 0x102014, 0x50c
.syntax divided
