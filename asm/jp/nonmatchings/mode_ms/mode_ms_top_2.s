.syntax unified
	.align 2, 0
	.global mode_ms_top_2
	.thumb
	.thumb_func
	.type mode_ms_top_2, %function
mode_ms_top_2:
	.incbin "roms/B8CJ.gba", 0x102520, 0xac
.syntax divided
