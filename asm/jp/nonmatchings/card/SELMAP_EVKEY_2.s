.syntax unified
	.align 2, 0
	.global SELMAP_EVKEY_2
	.thumb
	.thumb_func
	.type SELMAP_EVKEY_2, %function
SELMAP_EVKEY_2:
	.incbin "roms/B8CJ.gba", 0x97fa4, 0x1c4
.syntax divided
