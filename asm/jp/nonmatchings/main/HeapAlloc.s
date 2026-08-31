.syntax unified
	.align 2, 0
	.global HeapAlloc
	.thumb
	.thumb_func
	.type HeapAlloc, %function
HeapAlloc:
	.incbin "roms/B8CJ.gba", 0x8a8, 0x70
.syntax divided
