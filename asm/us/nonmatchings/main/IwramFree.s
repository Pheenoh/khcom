.syntax unified
	.align 2, 0
	.global IwramFree
	.thumb
	.thumb_func
	.type IwramFree, %function
IwramFree: @ 080009D4
	push {lr}
	ldr r1, _080009E0 @ =0x030074B8
	bl HeapFree
	pop {r0}
	bx r0
_080009E0: .4byte 0x030074B8
.syntax divided
