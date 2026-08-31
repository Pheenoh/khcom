.syntax unified
	.align 2, 0
	.global IwramAlloc
	.thumb
	.thumb_func
	.type IwramAlloc, %function
IwramAlloc: @ 08000928
	push {lr}
	ldr r1, _08000934 @ =0x030074B8
	bl HeapAlloc
	pop {r1}
	bx r1
_08000934: .4byte 0x030074B8
.syntax divided
