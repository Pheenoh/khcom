.syntax unified
	.align 2, 0
	.global BgAffineSet
	.thumb
	.thumb_func
	.type BgAffineSet, %function
BgAffineSet:
	.incbin "roms/B8CJ.gba", 0x11805c, 0x4
.syntax divided
