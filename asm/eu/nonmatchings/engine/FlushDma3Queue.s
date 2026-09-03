.syntax unified
	.text
	.align 2, 0
	.global FlushDma3Queue
	.thumb
	.thumb_func
	.type FlushDma3Queue, %function
FlushDma3Queue:
	.incbin "roms/B8CP.gba", 0x47d4, 0x2a4
.syntax divided
