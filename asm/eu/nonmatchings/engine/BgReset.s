.syntax unified
	.text
	.align 2, 0
	.global BgReset
	.thumb
	.thumb_func
	.type BgReset, %function
BgReset:
	.incbin "roms/B8CP.gba", 0x4eec, 0x54
.syntax divided
