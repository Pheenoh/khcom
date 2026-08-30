.syntax unified
	.align 2, 0
	.global func_080009C4
	.thumb
	.thumb_func
	.type func_080009C4, %function
func_080009C4: @ 080009C4
	push {lr}
	ldr r1, _080009D0 @ =0x030074A8
	bl func_08000938
	pop {r0}
	bx r0
_080009D0: .4byte 0x030074A8
.syntax divided
