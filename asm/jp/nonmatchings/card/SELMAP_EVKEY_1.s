.syntax unified
	.align 2, 0
	.global SELMAP_EVKEY_1
	.thumb
	.thumb_func
	.type SELMAP_EVKEY_1, %function
SELMAP_EVKEY_1:
	.incbin "roms/B8CJ.gba", 0x97e10, 0x160
.syntax divided
