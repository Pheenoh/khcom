.syntax unified
	.text
	.align 2, 0
	.global BgAffineSet
	.thumb
	.thumb_func
	.type BgAffineSet, %function
BgAffineSet:
	.incbin "roms/B8CP.gba", 0x116af8, 0x4
.syntax divided
