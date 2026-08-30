.syntax unified
	.align 2, 0
	.global func_080D2D24
	.thumb
	.thumb_func
	.type func_080D2D24, %function
func_080D2D24: @ 080D2D24
	push {r4, lr}
	ldr r1, _080D2D38 @ =0x0203C470
	adds r1, #0x10
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080D2D38: .4byte 0x0203C470
.syntax divided
