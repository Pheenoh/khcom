.syntax unified
	.align 2, 0
	.global func_0800388C
	.thumb
	.thumb_func
	.type func_0800388C, %function
func_0800388C: @ 0800388C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r3, #0x10
	lsrs r5, r3, #0x10
	lsrs r3, r3, #0x15
	adds r0, r1, r3
	cmp r0, #0x10
	bgt _080038BC
	movs r0, #0x00
	str r0, [r4, #0x20]
	strh r3, [r4, #0x08]
	str r2, [r4, #0x00]
	strh r0, [r4, #0x04]
	strh r1, [r4, #0x06]
	ldrh r1, [r4, #0x06]
	lsls r1, r1, #0x05
	ldr r0, _080038C4 @ =0x05000200
	adds r1, r1, r0
	adds r0, r2, #0x0
	adds r2, r5, #0x0
	bl RequestDma3Copy
_080038BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080038C4: .4byte 0x05000200
.syntax divided
