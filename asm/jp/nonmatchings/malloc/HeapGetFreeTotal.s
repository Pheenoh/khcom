.syntax unified
	.align 2, 0
	.global HeapGetFreeTotal
	.thumb
	.thumb_func
	.type HeapGetFreeTotal, %function
HeapGetFreeTotal:
	.incbin "roms/B8CJ.gba", 0xa28, 0x18
.syntax divided
