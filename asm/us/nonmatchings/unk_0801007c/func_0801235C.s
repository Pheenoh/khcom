.syntax unified
	.align 2, 0
	.global func_0801235C
	.thumb
	.thumb_func
	.type func_0801235C, %function
func_0801235C: @ 0801235C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r10, r1
	bl ListPoolFirst
	b _0801258E
_0801236E:
	mov r0, r10
	bl ListPoolLast
	adds r4, r0, #0x0
	movs r0, #0x18
	adds r0, r0, r5
	mov r9, r0
	b _0801257E
_0801237E:
	ldr r1, [r5, #0x10]
	ldr r0, [r4, #0x10]
	adds r6, r1, r0
	ldr r2, [r5, #0x04]
	ldr r1, [r4, #0x04]
	subs r0, r2, r1
	cmp r0, #0x00
	bge _08012390
	subs r0, r1, r2
_08012390:
	ldr r3, [r5, #0x08]
	ldr r2, [r4, #0x08]
	subs r1, r3, r2
	cmp r1, #0x00
	bge _0801239C
	subs r1, r2, r3
_0801239C:
	cmp r0, r6
	blt _080123A2
	b _08012574
_080123A2:
	cmp r1, r6
	blt _080123A8
	b _08012574
_080123A8:
	adds r2, r0, #0x0
	muls r2, r0
	adds r0, r2, #0x0
	asrs r0, r0, #0x08
	adds r2, r1, #0x0
	muls r2, r1
	adds r1, r2, #0x0
	asrs r1, r1, #0x08
	adds r0, r0, r1
	bl func_08003C9C
	subs r6, r6, r0
	mov r8, r6
	cmp r6, #0x00
	bgt _080123C8
	b _08012574
_080123C8:
	ldr r0, [r5, #0x0C]
	ldr r1, [r4, #0x0C]
	subs r3, r0, r1
	ldr r2, [r5, #0x14]
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	cmp r3, r2
	bge _0801249C
	negs r1, r3
	ldr r0, [r4, #0x14]
	cmp r1, r0
	bge _0801249C
	adds r0, r4, #0x0
	adds r0, #0x2C
	movs r6, #0x01
	strb r6, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r6, [r0, #0x00]
	ldr r0, [r4, #0x00]
	str r0, [r5, #0x34]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x00]
	adds r1, r6, #0x0
	lsls r1, r0
	ldr r0, [r5, #0x58]
	orrs r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x00]
	adds r1, r6, #0x0
	lsls r1, r0
	ldr r0, [r4, #0x58]
	orrs r0, r1
	str r0, [r4, #0x58]
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	bl GetAngle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _08012498 @ =0x08121400
	lsls r1, r0, #0x01
	adds r1, r1, r3
	movs r2, #0x00
	ldsh r1, [r1, r2]
	mov r2, r8
	muls r2, r1
	asrs r2, r2, #0x08
	negs r1, r2
	str r1, [r5, #0x38]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	mov r1, r8
	muls r1, r0
	adds r0, r1, #0x0
	asrs r0, r0, #0x08
	negs r0, r0
	str r0, [r5, #0x3C]
	str r4, [r5, #0x50]
	str r2, [r4, #0x38]
	ldr r0, [r5, #0x3C]
	negs r0, r0
	str r0, [r4, #0x3C]
	str r5, [r4, #0x50]
	ldrh r1, [r4, #0x30]
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08012476
	ldr r0, [r4, #0x0C]
	ldr r1, [r4, #0x14]
	subs r0, r0, r1
	str r0, [r5, #0x40]
	mov r2, r8
	str r2, [r5, #0x4C]
	ldr r0, [r4, #0x08]
	asrs r0, r0, #0x01
	str r0, [r5, #0x48]
	ldr r0, [r4, #0x04]
	str r0, [r5, #0x44]
_08012476:
	ldrh r1, [r5, #0x30]
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08012574
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x14]
	subs r0, r0, r1
	str r0, [r4, #0x40]
	mov r0, r8
	str r0, [r4, #0x4C]
	ldr r0, [r5, #0x08]
	asrs r0, r0, #0x01
	str r0, [r4, #0x48]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x44]
	b _08012574
_08012498: .4byte 0x08121400
_0801249C:
	ldrh r1, [r4, #0x30]
	movs r2, #0x01
	mov r12, r2
	movs r3, #0x01
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08012508
	ldr r0, [r4, #0x14]
	subs r0, r7, r0
	cmp r0, r6
	blt _08012508
	ldrh r0, [r5, #0x2E]
	movs r2, #0x00
	mov r1, r12
	orrs r0, r1
	strh r0, [r5, #0x2E]
	ldr r0, [r4, #0x0C]
	ldr r1, [r4, #0x14]
	subs r0, r0, r1
	cmp r0, r6
	bne _080124E8
	ldrh r0, [r4, #0x2E]
	movs r1, #0x02
	orrs r0, r1
	strh r0, [r4, #0x2E]
	ldr r0, [r4, #0x00]
	adds r1, r3, #0x0
	lsls r1, r0
	ldr r0, [r5, #0x58]
	orrs r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x00]
	adds r1, r3, #0x0
	lsls r1, r0
	ldr r0, [r4, #0x58]
	orrs r0, r1
	str r0, [r4, #0x58]
_080124E8:
	ldr r0, [r4, #0x0C]
	ldr r1, [r4, #0x14]
	subs r0, r0, r1
	str r0, [r5, #0x40]
	mov r2, r8
	str r2, [r5, #0x4C]
	ldr r0, [r4, #0x08]
	asrs r0, r0, #0x01
	str r0, [r5, #0x48]
	ldr r0, [r4, #0x04]
	str r0, [r5, #0x44]
	str r4, [r5, #0x50]
	ldr r0, [r4, #0x00]
	str r0, [r5, #0x34]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x34]
_08012508:
	ldrh r1, [r5, #0x30]
	movs r7, #0x01
	movs r6, #0x01
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08012574
	ldr r1, [r5, #0x0C]
	ldr r0, [r5, #0x14]
	subs r1, r1, r0
	ldr r2, [r4, #0x0C]
	cmp r1, r2
	blt _08012574
	ldrh r0, [r4, #0x2E]
	movs r3, #0x00
	orrs r0, r7
	strh r0, [r4, #0x2E]
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x14]
	subs r0, r0, r1
	cmp r0, r2
	bne _08012554
	ldrh r0, [r5, #0x2E]
	movs r1, #0x02
	orrs r0, r1
	strh r0, [r5, #0x2E]
	ldr r0, [r4, #0x00]
	adds r1, r6, #0x0
	lsls r1, r0
	ldr r0, [r5, #0x58]
	orrs r0, r1
	str r0, [r5, #0x58]
	ldr r0, [r5, #0x00]
	adds r1, r6, #0x0
	lsls r1, r0
	ldr r0, [r4, #0x58]
	orrs r0, r1
	str r0, [r4, #0x58]
_08012554:
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x14]
	subs r0, r0, r1
	str r0, [r4, #0x40]
	mov r0, r8
	str r0, [r4, #0x4C]
	ldr r0, [r5, #0x08]
	asrs r0, r0, #0x01
	str r0, [r4, #0x48]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x44]
	str r5, [r4, #0x50]
	ldr r0, [r4, #0x00]
	str r0, [r5, #0x34]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x34]
_08012574:
	adds r0, r4, #0x0
	adds r0, #0x18
	bl ListPoolPrev
	adds r4, r0, #0x0
_0801257E:
	cmp r4, #0x00
	beq _08012588
	cmp r5, r4
	beq _08012588
	b _0801237E
_08012588:
	mov r0, r9
	bl ListPoolNext
_0801258E:
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _08012596
	b _0801236E
_08012596:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
