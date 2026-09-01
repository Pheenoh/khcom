.syntax unified
	.align 2, 0
	.global SetEwramHeapName
	.thumb
	.thumb_func
	.type SetEwramHeapName, %function
SetEwramHeapName:
	.incbin "roms/B8CJ.gba", 0xad8, 0xc
.syntax divided
