.syntax unified
	.align 2, 0
	.global VCountIntrDummy
	.thumb
	.thumb_func
	.type VCountIntrDummy, %function
VCountIntrDummy:
	.incbin "roms/B8CJ.gba", 0x5a8, 0x4
.syntax divided
