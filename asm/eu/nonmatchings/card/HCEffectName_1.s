.syntax unified
	.text
	.align 2, 0
	.global HCEffectName_1
	.thumb
	.thumb_func
	.type HCEffectName_1, %function
HCEffectName_1:
	.incbin "roms/B8CP.gba", 0x9e240, 0x1d8
.syntax divided
