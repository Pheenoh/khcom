.syntax unified
	.text
	.align 2, 0
	.global BgInit
	.thumb
	.thumb_func
	.type BgInit, %function
BgInit:
	.incbin "roms/B8CP.gba", 0x4ccc, 0x70
.syntax divided
