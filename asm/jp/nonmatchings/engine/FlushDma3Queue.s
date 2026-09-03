.syntax unified
	.text
	.align 2, 0
	.global FlushDma3Queue
	.thumb
	.thumb_func
	.type FlushDma3Queue, %function
FlushDma3Queue:
	.incbin "roms/B8CJ.gba", 0x46c8, 0x270
.syntax divided
