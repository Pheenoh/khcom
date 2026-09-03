.syntax unified
	.text
	.align 2, 0
	.global LVUP_EFFECT_0
	.thumb
	.thumb_func
	.type LVUP_EFFECT_0, %function
LVUP_EFFECT_0:
	.incbin "roms/B8CJ.gba", 0xa178c, 0x164
.syntax divided
