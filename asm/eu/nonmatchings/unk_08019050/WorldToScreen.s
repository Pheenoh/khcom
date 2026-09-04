.syntax unified
	.text
	.align 2, 0
	.global WorldToScreen
	.thumb
	.thumb_func
	.type WorldToScreen, %function
WorldToScreen:
	.incbin "roms/B8CP.gba", 0x1cf54, 0xf4
.syntax divided
