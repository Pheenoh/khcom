.syntax unified
	.text
	.align 2, 0
	.global LVUP_EFFECT_2
	.thumb
	.thumb_func
	.type LVUP_EFFECT_2, %function
LVUP_EFFECT_2:
	.incbin "roms/B8CP.gba", 0xa2130, 0x80
.syntax divided
