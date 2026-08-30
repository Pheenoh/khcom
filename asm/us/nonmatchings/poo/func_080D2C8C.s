.syntax unified
	.align 2, 0
	.global func_080D2C8C
	.thumb
	.thumb_func
	.type func_080D2C8C, %function
func_080D2C8C: @ 080D2C8C
	push {r4, r5, r6, lr}
	ldr r3, _080D2CA4 @ =0x0203C470
	adds r2, r3, #0x0
	ldm r0!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	str r1, [r3, #0x20]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D2CA4: .4byte 0x0203C470
.syntax divided
