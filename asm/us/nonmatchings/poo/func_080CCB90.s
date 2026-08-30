.syntax unified
	.align 2, 0
	.global func_080CCB90
	.thumb
	.thumb_func
	.type func_080CCB90, %function
func_080CCB90: @ 080CCB90
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	adds r6, r2, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r1, r4, #0x0
	bl func_080CCB84
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_080CCB8C
	str r6, [r5, #0x08]
	movs r0, #0x00
	strh r0, [r5, #0x04]
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldr r6, _080CCBD0 @ =0x02034DF8
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	adds r2, r5, #0x0
	bl func_08000D20
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	bl func_08000D28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CCBD0: .4byte 0x02034DF8
.syntax divided
