.syntax unified
	.text
	.align 2, 0
	.global mode_ms_top_0
	.thumb
	.thumb_func
	.type mode_ms_top_0, %function
mode_ms_top_0:
	.incbin "roms/B8CP.gba", 0x100080, 0x3c8
.syntax divided
