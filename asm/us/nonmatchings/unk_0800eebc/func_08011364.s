.syntax unified
	.align 2, 0
	.global func_08011364
	.thumb
	.thumb_func
	.type func_08011364, %function
func_08011364: @ 08011364
	push {r4, lr}
	ldr r3, _08011394 @ =0x02039B84
	ldr r3, [r3, #0x00]
	adds r3, #0x76
	movs r4, #0x08
	strh r4, [r3, #0x00]
	movs r4, #0x30
	ldsh r3, [r1, r4]
	ldr r1, [r2, #0x00]
	muls r1, r3
	asrs r1, r1, #0x08
	negs r1, r1
	strh r1, [r0, #0x20]
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x38]
	movs r3, #0x20
	movs r4, #0x00
	orrs r1, r3
	str r1, [r0, #0x34]
	str r2, [r0, #0x38]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08011394: .4byte 0x02039B84
.syntax divided
