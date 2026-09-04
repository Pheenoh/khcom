.syntax unified
	.text
	.align 2, 0
	.global WorldToScreen
	.thumb
	.thumb_func
	.type WorldToScreen, %function
WorldToScreen:
	.incbin "roms/B8CJ.gba", 0x1909c, 0xf4
.syntax divided
