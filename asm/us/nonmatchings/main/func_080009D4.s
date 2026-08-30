.syntax unified
	.align 2, 0
	.global func_080009D4
	.thumb
	.thumb_func
	.type func_080009D4, %function
func_080009D4: @ 080009D4
	push {lr}
	ldr r1, _080009E0 @ =0x030074B8
	bl func_08000938
	pop {r0}
	bx r0
_080009E0: .4byte 0x030074B8
.syntax divided
