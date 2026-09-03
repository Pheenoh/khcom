.syntax unified
	.text
	.align 2, 0
	.global SELMAP_EVKEY_0
	.thumb
	.thumb_func
	.type SELMAP_EVKEY_0, %function
SELMAP_EVKEY_0:
	.incbin "roms/B8CP.gba", 0x97da8, 0x1d4
.syntax divided
