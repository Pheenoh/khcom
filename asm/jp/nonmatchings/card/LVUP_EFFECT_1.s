.syntax unified
	.align 2, 0
	.global LVUP_EFFECT_1
	.thumb
	.thumb_func
	.type LVUP_EFFECT_1, %function
LVUP_EFFECT_1:
	.incbin "roms/B8CJ.gba", 0xa18f0, 0x204
.syntax divided
