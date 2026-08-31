.syntax unified
	.align 2, 0
	.global IwramFree
	.thumb
	.thumb_func
	.type IwramFree, %function
IwramFree:
	.incbin "roms/B8CJ.gba", 0x9d4, 0x10
.syntax divided
