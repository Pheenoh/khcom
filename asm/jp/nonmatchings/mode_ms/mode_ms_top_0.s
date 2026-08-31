.syntax unified
	.align 2, 0
	.global mode_ms_top_0
	.thumb
	.thumb_func
	.type mode_ms_top_0, %function
mode_ms_top_0:
	.incbin "roms/B8CJ.gba", 0x101c68, 0x3ac
.syntax divided
