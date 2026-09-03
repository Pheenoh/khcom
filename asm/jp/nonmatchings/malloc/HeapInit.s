.syntax unified
	.text
	.align 2, 0
	.global HeapInit
	.thumb
	.thumb_func
	.type HeapInit, %function
HeapInit:
	.incbin "roms/B8CJ.gba", 0x800, 0x60
.syntax divided
