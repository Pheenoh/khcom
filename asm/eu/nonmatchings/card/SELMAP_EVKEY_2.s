.syntax unified
	.text
	.align 2, 0
	.global SELMAP_EVKEY_2
	.thumb
	.thumb_func
	.type SELMAP_EVKEY_2, %function
SELMAP_EVKEY_2:
	.incbin "roms/B8CP.gba", 0x98110, 0x1c4
.syntax divided
