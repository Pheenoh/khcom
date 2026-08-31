.syntax unified
	.align 2, 0
	.global HeapFree
	.thumb
	.thumb_func
	.type HeapFree, %function
HeapFree:
	.incbin "roms/B8CJ.gba", 0x938, 0x8c
.syntax divided
