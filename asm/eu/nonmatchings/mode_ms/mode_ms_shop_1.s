.syntax unified
	.text
	.align 2, 0
	.global mode_ms_shop_1
	.thumb
	.thumb_func
	.type mode_ms_shop_1, %function
mode_ms_shop_1:
	.incbin "roms/B8CP.gba", 0x102c84, 0x268
.syntax divided
