.syntax unified
	.align 2, 0
	.global func_080D2CA8
	.thumb
	.thumb_func
	.type func_080D2CA8, %function
func_080D2CA8: @ 080D2CA8
	push {r4, r5, r6, lr}
	ldr r3, _080D2CC0 @ =0x0203C470
	adds r2, r3, #0x0
	ldm r2!, {r4, r5, r6}
	stm r0!, {r4, r5, r6}
	ldr r2, [r2, #0x00]
	str r2, [r0, #0x00]
	ldr r0, [r3, #0x20]
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D2CC0: .4byte 0x0203C470
.syntax divided
