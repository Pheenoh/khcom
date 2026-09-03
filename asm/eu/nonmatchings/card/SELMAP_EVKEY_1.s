.syntax unified
	.text
	.align 2, 0
	.global SELMAP_EVKEY_1
	.thumb
	.thumb_func
	.type SELMAP_EVKEY_1, %function
SELMAP_EVKEY_1:
	.incbin "roms/B8CP.gba", 0x97f7c, 0x160
.syntax divided
