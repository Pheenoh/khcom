.syntax unified
	.text
	.align 2, 0
	.global ModeRequestHeapReset
	.thumb
	.thumb_func
	.type ModeRequestHeapReset, %function
ModeRequestHeapReset:
	.incbin "roms/B8CP.gba", 0x113c, 0x3c
.syntax divided
