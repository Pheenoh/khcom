.syntax unified
	.align 2, 0
	.global func_080792F4
	.thumb
	.thumb_func
	.type func_080792F4, %function
func_080792F4: @ 080792F4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	ldr r0, _08079344 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r5, [r0, #0x00]
	cmp r5, #0x01
	bne _08079354
	ldr r6, _08079348 @ =0x02034A98
	ldr r2, [r6, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA5
	ldrb r1, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x09
	ble _08079322
	movs r4, #0x09
_08079322:
	cmp r1, #0x08
	bhi _08079334
	ldr r0, _0807934C @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0x9C
	ldr r1, _08079350 @ =0x09EE78BC
	adds r2, #0x48
	bl TaskCreate
_08079334:
	ldr r0, [r6, #0x00]
	adds r0, #0xA5
	strb r4, [r0, #0x00]
	ldr r0, [r6, #0x00]
	adds r0, #0xA7
	strb r5, [r0, #0x00]
	b _08079390
	.byte 0x00, 0x00
_08079344: .4byte 0x02039B84
_08079348: .4byte 0x02034A98
_0807934C: .4byte 0x02039DD4
_08079350: .4byte 0x09EE78BC
_08079354:
	cmp r5, #0x15
	bne _08079388
	ldr r3, _08079378 @ =0x02034A98
	ldr r0, [r3, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xA5
	ldrb r1, [r2, #0x00]
	cmp r1, #0x00
	beq _0807937C
	subs r1, #0x01
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	strb r1, [r2, #0x00]
	ldr r0, [r3, #0x00]
	adds r0, #0xA7
	movs r1, #0x01
	strb r1, [r0, #0x00]
	b _08079390
_08079378: .4byte 0x02034A98
_0807937C:
	movs r4, #0x00
	adds r1, r0, #0x0
	adds r1, #0xA7
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08079390
_08079388:
	ldr r0, _080794A0 @ =0x02034A98
	ldr r0, [r0, #0x00]
	adds r0, #0xA5
	ldrb r4, [r0, #0x00]
_08079390:
	ldr r0, _080794A4 @ =0x02039DD4
	ldr r6, [r0, #0x00]
	adds r2, r6, #0x0
	adds r2, #0xC2
	lsls r1, r4, #0x18
	asrs r3, r1, #0x18
	movs r4, #0x00
	ldsh r2, [r2, r4]
	mov r12, r1
	adds r7, r0, #0x0
	cmp r2, r3
	ble _080793AE
	cmp r3, #0x00
	beq _080793AE
	b _080795EC
_080793AE:
	movs r4, #0x00
	ldr r3, _080794A8 @ =0x02039B84
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x90
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r8, r3
	cmp r0, #0x00
	beq _08079434
	ldr r0, _080794AC @ =0x02039B9C
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r2, r0, #0x0
	cmp r1, #0x02
	bne _080793EE
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080793EE
	adds r0, r6, #0x0
	adds r0, #0xE2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080793EE
	movs r4, #0x01
_080793EE:
	ldr r0, [r2, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _08079410
	ldr r1, [r7, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x24]
	cmp r0, #0x16
	bne _08079410
	adds r0, r1, #0x0
	adds r0, #0xE2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08079410
	movs r4, #0x01
_08079410:
	ldr r0, [r2, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x1D
	bne _08079434
	ldr r1, [r7, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _08079434
	adds r0, r1, #0x0
	adds r0, #0xE2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08079434
	movs r4, #0x01
_08079434:
	cmp r4, #0x00
	beq _0807943A
	b _080795EC
_0807943A:
	movs r3, #0x00
	ldr r0, [r7, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcs _08079468
	adds r5, r7, #0x0
	movs r4, #0x80
	lsls r4, r4, #0x0E
_0807944C:
	ldr r2, [r5, #0x00]
	lsls r0, r3, #0x02
	adds r0, r2, r0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	orrs r0, r4
	str r0, [r1, #0x78]
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r2, #0xD0
	ldrb r2, [r2, #0x00]
	cmp r3, r2
	bcc _0807944C
_08079468:
	mov r5, r8
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080794B0 @ =0x00800000
	ldr r3, _080794B4 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r7, #0x00]
	adds r0, #0xC2
	mov r2, r12
	asrs r1, r2, #0x18
	ldrh r3, [r0, #0x00]
	movs r5, #0x00
	ldsh r2, [r0, r5]
	cmp r2, r1
	bne _0807948E
	b _08079590
_0807948E:
	cmp r1, #0x00
	bne _080794C2
	cmp r2, #0x09
	ble _080794B8
	movs r0, #0xE5
	lsls r0, r0, #0x01
	adds r1, r4, r0
	b _080794D2
	.byte 0x00, 0x00
_080794A0: .4byte 0x02034A98
_080794A4: .4byte 0x02039DD4
_080794A8: .4byte 0x02039B84
_080794AC: .4byte 0x02039B9C
_080794B0: .4byte 0x00800000
_080794B4: .4byte 0x00000000
_080794B8:
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strb r3, [r0, #0x00]
	b _080794E2
_080794C2:
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, r1, r0
	cmp r0, #0x09
	ble _080794D8
	movs r5, #0xE5
	lsls r5, r5, #0x01
	adds r1, r4, r5
_080794D2:
	movs r0, #0x09
	strb r0, [r1, #0x00]
	b _080794E2
_080794D8:
	subs r0, r1, r3
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r2, r4, r1
	strb r0, [r2, #0x00]
_080794E2:
	ldr r0, _08079574 @ =0x00000213
	bl m4aSongNumStart
	ldr r7, _08079578 @ =0x02039B84
	ldr r6, [r7, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _0807957C @ =0x00000400
	ldr r3, _08079580 @ =0x00000000
	orrs r0, r2
	movs r4, #0x80
	movs r5, #0x00
	adds r2, r0, #0x0
	orrs r2, r4
	adds r3, r1, #0x0
	movs r4, #0x21
	negs r4, r4
	adds r0, r2, #0x0
	ands r0, r4
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	ldr r4, _08079584 @ =0x02034A98
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x06
	orrs r0, r1
	str r0, [r2, #0x78]
	mov r0, r9
	bl func_080791C0
	ldr r6, _08079588 @ =0x02039DD4
	ldr r0, [r6, #0x00]
	ldr r1, [r4, #0x00]
	str r1, [r0, #0x00]
	adds r0, #0xD0
	movs r5, #0x01
	strb r5, [r0, #0x00]
	ldr r1, [r6, #0x00]
	ldr r0, [r4, #0x00]
	adds r0, #0xA5
	ldrb r0, [r0, #0x00]
	adds r1, #0xC2
	strh r0, [r1, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, #0xA4
	strb r5, [r0, #0x00]
	ldr r0, _0807958C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080795EC
	bl func_0807BA54
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080795EC
	ldr r0, [r7, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _080795EC
	ldr r0, [r6, #0x00]
	adds r0, #0xEE
	strb r5, [r0, #0x00]
	b _080795EC
_08079574: .4byte 0x00000213
_08079578: .4byte 0x02039B84
_0807957C: .4byte 0x00000400
_08079580: .4byte 0x00000000
_08079584: .4byte 0x02034A98
_08079588: .4byte 0x02039DD4
_0807958C: .4byte 0x02039BB0
_08079590:
	mov r0, r9
	bl func_080791C0
	mov r2, r8
	ldr r0, [r2, #0x00]
	movs r4, #0xE5
	lsls r4, r4, #0x01
	adds r1, r0, r4
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r5, [r2, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	movs r2, #0x81
	negs r2, r2
	ands r0, r2
	movs r4, #0x21
	negs r4, r4
	adds r2, r0, #0x0
	ands r2, r4
	adds r3, r1, #0x0
	ldr r4, _080795F8 @ =0xFFFFFBFF
	adds r0, r2, #0x0
	ands r0, r4
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	movs r0, #0xCC
	bl m4aSongNumStart
	mov r5, r8
	ldr r0, [r5, #0x00]
	adds r0, #0xA4
	movs r3, #0x01
	strb r3, [r0, #0x00]
	ldr r0, [r7, #0x00]
	ldr r2, _080795FC @ =0x02034A98
	ldr r1, [r2, #0x00]
	str r1, [r0, #0x00]
	adds r0, #0xD0
	strb r3, [r0, #0x00]
	ldr r1, [r7, #0x00]
	ldr r0, [r2, #0x00]
	adds r0, #0xA5
	ldrb r0, [r0, #0x00]
	adds r1, #0xC2
	strh r0, [r1, #0x00]
_080795EC:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080795F8: .4byte 0xFFFFFBFF
_080795FC: .4byte 0x02034A98
.syntax divided
