.syntax unified
	.text
	.align 2, 0
	.global HCEffectName_1
	.thumb
	.thumb_func
	.type HCEffectName_1, %function
HCEffectName_1:
	.incbin "roms/B8CP.gba", 0x9e278, 0x1a0
.syntax divided
