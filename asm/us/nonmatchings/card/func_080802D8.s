.syntax unified
	.align 2, 0
	.global func_080802D8
	.thumb
	.thumb_func
	.type func_080802D8, %function
func_080802D8: @ 080802D8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	ldr r0, _08080324 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r4, [r0, #0x00]
	cmp r4, #0x01
	bne _08080334
	ldr r6, _08080328 @ =0x02034AAC
	ldr r2, [r6, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA5
	ldrb r1, [r0, #0x00]
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x09
	bls _08080304
	movs r5, #0x09
_08080304:
	cmp r1, #0x08
	bhi _08080316
	ldr r0, _0808032C @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0x9C
	ldr r1, _08080330 @ =0x09EE78BC
	adds r2, #0x48
	bl TaskCreate
_08080316:
	ldr r0, [r6, #0x00]
	adds r0, #0xA5
	strb r5, [r0, #0x00]
	ldr r0, [r6, #0x00]
	adds r0, #0xA7
	strb r4, [r0, #0x00]
	b _08080370
_08080324: .4byte 0x02039B9C
_08080328: .4byte 0x02034AAC
_0808032C: .4byte 0x02039DD4
_08080330: .4byte 0x09EE78BC
_08080334:
	cmp r4, #0x15
	bne _08080368
	ldr r3, _08080358 @ =0x02034AAC
	ldr r0, [r3, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xA5
	ldrb r1, [r2, #0x00]
	cmp r1, #0x00
	beq _0808035C
	subs r1, #0x01
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	strb r1, [r2, #0x00]
	ldr r0, [r3, #0x00]
	adds r0, #0xA7
	movs r1, #0x01
	strb r1, [r0, #0x00]
	b _08080370
_08080358: .4byte 0x02034AAC
_0808035C:
	movs r5, #0x00
	adds r1, r0, #0x0
	adds r1, #0xA7
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08080370
_08080368:
	ldr r0, _08080464 @ =0x02034AAC
	ldr r0, [r0, #0x00]
	adds r0, #0xA5
	ldrb r5, [r0, #0x00]
_08080370:
	ldr r1, _08080468 @ =0x02039DD4
	ldr r2, [r1, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xC2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	mov r8, r1
	cmp r0, r5
	ble _08080388
	cmp r5, #0x00
	beq _08080388
	b _08080580
_08080388:
	movs r3, #0x00
	ldr r0, _0808046C @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r7, r0, #0x0
	cmp r1, #0x02
	bne _080803B0
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080803B0
	adds r0, r2, #0x0
	adds r0, #0xE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080803B0
	movs r3, #0x01
_080803B0:
	ldr r0, [r7, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _080803D4
	mov r0, r8
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x24]
	cmp r0, #0x16
	bne _080803D4
	adds r0, r1, #0x0
	adds r0, #0xE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080803D4
	movs r3, #0x01
_080803D4:
	ldr r0, [r7, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x1D
	bne _080803FA
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080803FA
	adds r0, r1, #0x0
	adds r0, #0xE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080803FA
	movs r3, #0x01
_080803FA:
	cmp r3, #0x00
	beq _08080400
	b _08080580
_08080400:
	movs r3, #0x00
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bge _0808042C
	mov r6, r8
	movs r4, #0x80
	lsls r4, r4, #0x0E
_08080414:
	ldr r2, [r6, #0x00]
	lsls r0, r3, #0x02
	adds r0, r2, r0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	orrs r0, r4
	str r0, [r1, #0x78]
	adds r3, #0x01
	adds r2, #0xD0
	ldrb r2, [r2, #0x00]
	cmp r3, r2
	blt _08080414
_0808042C:
	ldr r4, [r7, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08080470 @ =0x00800000
	ldr r3, _08080474 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xC2
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, r5
	beq _08080524
	cmp r5, #0x00
	bne _08080482
	ldrh r2, [r1, #0x00]
	cmp r0, #0x09
	ble _08080478
	movs r0, #0xE5
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x09
	strb r0, [r1, #0x00]
	b _080804A0
	.byte 0x00, 0x00
_08080464: .4byte 0x02034AAC
_08080468: .4byte 0x02039DD4
_0808046C: .4byte 0x02039B84
_08080470: .4byte 0x00800000
_08080474: .4byte 0x00000000
_08080478:
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strb r2, [r0, #0x00]
	b _080804A0
_08080482:
	ldrb r0, [r1, #0x00]
	subs r0, r0, r5
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	ldr r0, [r7, #0x00]
	adds r5, r0, r2
	movs r0, #0x00
	ldsb r0, [r5, r0]
	movs r1, #0x09
	negs r1, r1
	cmp r0, r1
	bge _080804A0
	strb r1, [r5, #0x00]
_080804A0:
	ldr r0, _0808050C @ =0x00000213
	bl m4aSongNumStart
	ldr r2, _08080510 @ =0x02039B84
	mov r8, r2
	ldr r6, [r2, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _08080514 @ =0x00000400
	ldr r3, _08080518 @ =0x00000000
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
	ldr r4, _0808051C @ =0x02034AAC
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x06
	orrs r0, r1
	str r0, [r2, #0x78]
	mov r0, r9
	bl func_08080228
	ldr r2, _08080520 @ =0x02039DD4
	ldr r0, [r2, #0x00]
	ldr r1, [r4, #0x00]
	str r1, [r0, #0x00]
	adds r0, #0xD0
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r1, [r2, #0x00]
	ldr r0, [r4, #0x00]
	adds r0, #0xA5
	ldrb r0, [r0, #0x00]
	adds r1, #0xC2
	movs r2, #0x00
	strh r0, [r1, #0x00]
	mov r3, r8
	ldr r0, [r3, #0x00]
	adds r0, #0xA4
	strb r2, [r0, #0x00]
	bl func_0807BA54
	b _08080580
	.byte 0x00, 0x00
_0808050C: .4byte 0x00000213
_08080510: .4byte 0x02039B84
_08080514: .4byte 0x00000400
_08080518: .4byte 0x00000000
_0808051C: .4byte 0x02034AAC
_08080520: .4byte 0x02039DD4
_08080524:
	mov r0, r9
	bl func_08080228
	ldr r0, [r7, #0x00]
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r0, r1
	movs r6, #0x00
	strb r6, [r0, #0x00]
	ldr r5, [r7, #0x00]
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
	ldr r4, _0808058C @ =0xFFFFFBFF
	adds r0, r2, #0x0
	ands r0, r4
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	movs r0, #0xCC
	bl m4aSongNumStart
	ldr r0, [r7, #0x00]
	adds r0, #0xA4
	strb r6, [r0, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r2, _08080590 @ =0x02034AAC
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	adds r1, #0xD0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	mov r3, r8
	ldr r1, [r3, #0x00]
	ldr r0, [r2, #0x00]
	adds r0, #0xA5
	ldrb r0, [r0, #0x00]
	adds r1, #0xC2
	strh r0, [r1, #0x00]
_08080580:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0808058C: .4byte 0xFFFFFBFF
_08080590: .4byte 0x02034AAC
.syntax divided
