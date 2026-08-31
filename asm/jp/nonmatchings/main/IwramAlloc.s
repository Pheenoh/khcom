.syntax unified
	.align 2, 0
	.global IwramAlloc
	.thumb
	.thumb_func
	.type IwramAlloc, %function
IwramAlloc:
	.incbin "roms/B8CJ.gba", 0x928, 0x10
.syntax divided
