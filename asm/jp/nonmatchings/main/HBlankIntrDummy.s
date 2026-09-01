.syntax unified
	.align 2, 0
	.global HBlankIntrDummy
	.thumb
	.thumb_func
	.type HBlankIntrDummy, %function
HBlankIntrDummy:
	.incbin "roms/B8CJ.gba", 0x5a4, 0x4
.syntax divided
