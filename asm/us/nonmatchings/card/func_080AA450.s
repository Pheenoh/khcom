.syntax unified
	.align 2, 0
	.global func_080AA450
	.thumb
	.thumb_func
	.type func_080AA450, %function
func_080AA450: @ 080AA450
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldr r0, _080AA474 @ =0x0000FFFF
	mov r8, r0
	ldr r1, _080AA478 @ =0x0000063C
	adds r0, r5, r1
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080AA4B4
	ldr r3, _080AA47C @ =0x000006D2
	adds r0, r5, r3
	b _080AA492
	.byte 0x00, 0x00
_080AA474: .4byte 0x0000FFFF
_080AA478: .4byte 0x0000063C
_080AA47C: .4byte 0x000006D2
_080AA480:
	adds r0, r2, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080AA4B4
	ldr r1, _080AA5C4 @ =0x000006D2
	adds r0, r5, r1
_080AA492:
	movs r3, #0x24
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _080AA480
	movs r1, #0xDA
	lsls r1, r1, #0x03
	adds r0, r5, r1
	movs r3, #0x22
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _080AA480
	ldrh r2, [r2, #0x20]
	mov r8, r2
_080AA4B4:
	adds r0, r5, #0x0
	bl func_080AA634
	ldr r0, _080AA5C8 @ =0x0000FFFF
	cmp r8, r0
	bne _080AA4C2
	b _080AA60C
_080AA4C2:
	ldr r0, _080AA5CC @ =0x00000FFF
	mov r1, r8
	ands r0, r1
	movs r1, #0x34
	muls r1, r0
	ldr r0, _080AA5D0 @ =0x08F70AB0
	adds r7, r1, r0
	ldr r4, _080AA5D4 @ =0x08F709B0
	adds r6, r7, #0x0
	adds r6, #0x2A
	ldrb r1, [r6, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r4, #0x0
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x10]
	ldr r0, [r7, #0x04]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x14]
	ldr r0, [r7, #0x08]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x24]
	ldr r0, _080AA5D8 @ =0x09611AB8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x20]
	ldr r3, _080AA5DC @ =0x000004D4
	adds r2, r5, r3
	ldrb r1, [r6, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r0, #0x9B
	lsls r0, r0, #0x03
	adds r1, r5, r0
	ldr r0, [r7, #0x00]
	str r0, [r1, #0x00]
	movs r6, #0x00
	movs r1, #0xDC
	lsls r1, r1, #0x03
	adds r0, r5, r1
	ldrh r3, [r0, #0x00]
	mov r0, r8
	lsls r0, r0, #0x10
	mov r9, r0
	cmp r6, r3
	bcs _080AA56A
	ldr r1, _080AA5E0 @ =0x000004CC
	adds r2, r5, r1
	ldr r0, [r2, #0x00]
	ldrh r0, [r0, #0x14]
	ldrh r1, [r7, #0x1C]
	cmp r0, r1
	beq _080AA56A
	adds r4, r3, #0x0
	adds r3, r2, #0x0
	adds r2, r1, #0x0
_080AA554:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r4
	bcs _080AA56A
	ldr r0, [r3, #0x00]
	lsls r1, r6, #0x05
	adds r1, r1, r0
	ldrh r0, [r1, #0x14]
	cmp r0, r2
	bne _080AA554
_080AA56A:
	ldr r3, _080AA5E4 @ =0x000006CC
	adds r0, r5, r3
	strh r6, [r0, #0x00]
	ldr r1, _080AA5E8 @ =0x05000160
	adds r0, r7, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x05
	ldr r2, _080AA5EC @ =0x09614318
	adds r0, r0, r2
	movs r2, #0x20
	bl func_08005BE8
	movs r4, #0x00
	lsls r6, r6, #0x05
_080AA588:
	ldr r1, _080AA5E0 @ =0x000004CC
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	adds r0, r6, r0
	lsls r1, r4, #0x01
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	bl func_0808DD20
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x09
	bls _080AA588
	adds r0, r5, #0x0
	mov r1, r8
	bl func_080AA3A0
	mov r3, r9
	lsrs r1, r3, #0x10
	adds r0, r5, #0x0
	bl func_080AAEB0
	ldrh r0, [r7, #0x1C]
	cmp r0, #0x2E
	bls _080AA5F4
	ldr r1, _080AA5F0 @ =0x09518AB8
	b _080AA5F6
	.byte 0x00, 0x00
_080AA5C4: .4byte 0x000006D2
_080AA5C8: .4byte 0x0000FFFF
_080AA5CC: .4byte 0x00000FFF
_080AA5D0: .4byte 0x08F70AB0
_080AA5D4: .4byte 0x08F709B0
_080AA5D8: .4byte 0x09611AB8
_080AA5DC: .4byte 0x000004D4
_080AA5E0: .4byte 0x000004CC
_080AA5E4: .4byte 0x000006CC
_080AA5E8: .4byte 0x05000160
_080AA5EC: .4byte 0x09614318
_080AA5F0: .4byte 0x09518AB8
_080AA5F4:
	ldr r1, _080AA608 @ =0x095182B8
_080AA5F6:
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl func_0800510C
	movs r0, #0x00
	bl func_080AA6D4
	b _080AA626
_080AA608: .4byte 0x095182B8
_080AA60C:
	movs r4, #0x00
_080AA60E:
	movs r0, #0x00
	adds r1, r4, #0x0
	bl func_0808DD20
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x09
	bls _080AA60E
	movs r0, #0x00
	bl func_080AA6D4
_080AA626:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
