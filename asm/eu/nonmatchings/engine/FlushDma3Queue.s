.syntax unified
	.text
	.align 2, 0
	.global FlushDma3Queue
	.thumb
	.thumb_func
	.type FlushDma3Queue, %function
FlushDma3Queue:
	.incbin "roms/B8CP.gba", 0x47d0, 0x2a8
.syntax divided
