.syntax unified
	.align 2, 0
	.global SetIwramHeapName
	.thumb
	.thumb_func
	.type SetIwramHeapName, %function
SetIwramHeapName:
	.incbin "roms/B8CJ.gba", 0xae4, 0x24
.syntax divided
