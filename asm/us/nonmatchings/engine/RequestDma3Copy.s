.syntax unified
	.align 2, 0
	.global RequestDma3Copy
	.thumb
	.thumb_func
	.type RequestDma3Copy, %function
RequestDma3Copy: @ 080043B4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r4, r2, #0x10
	lsrs r7, r4, #0x10
	cmp r7, #0x00
	beq _080043D2
	ldr r0, _080043D8 @ =0x03007574
	ldr r3, [r0, #0x00]
	movs r0, #0x85
	lsls r0, r0, #0x05
	adds r2, r3, r0
	ldrh r0, [r2, #0x00]
	cmp r0, #0xFF
	bls _080043DC
_080043D2:
	movs r0, #0x00
	b _08004430
	.byte 0x00, 0x00
_080043D8: .4byte 0x03007574
_080043DC:
	ldr r0, _08004418 @ =0x03006C78
	ldrh r1, [r0, #0x00]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _0800441C
	ldrh r1, [r2, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r3, r0
	str r5, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r0, r3, #0x4
	adds r0, r0, r1
	str r6, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r3, r0
	strh r7, [r0, #0x08]
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	ldrh r1, [r2, #0x00]
	strh r0, [r2, #0x00]
	b _0800442E
_08004418: .4byte 0x03006C78
_0800441C:
	ldr r2, _08004438 @ =0x040000D4
	str r5, [r2, #0x00]
	str r6, [r2, #0x04]
	lsrs r0, r4, #0x11
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #0x08]
	ldr r0, [r2, #0x08]
_0800442E:
	movs r0, #0x01
_08004430:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08004438: .4byte 0x040000D4
.syntax divided
