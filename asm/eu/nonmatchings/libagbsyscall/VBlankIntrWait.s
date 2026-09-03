.syntax unified
	.text
	.align 2, 0
	.global VBlankIntrWait
	.thumb
	.thumb_func
	.type VBlankIntrWait, %function
VBlankIntrWait:
	.incbin "roms/B8CP.gba", 0x116b2c, 0x8
.syntax divided
