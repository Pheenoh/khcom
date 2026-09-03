.syntax unified
	.text
	.align 2, 0
	.global HCEffectName_2
	.thumb
	.thumb_func
	.type HCEffectName_2, %function
HCEffectName_2:
	.incbin "roms/B8CP.gba", 0x9e5a0, 0x100
.syntax divided
