.syntax unified
	.text
	.align 2, 0
	.global VBlankIntrWait
	.thumb
	.thumb_func
	.type VBlankIntrWait, %function
VBlankIntrWait:
	.incbin "roms/B8CJ.gba", 0x118088, 0x8
.syntax divided
