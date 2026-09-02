.syntax unified
	.align 2, 0
	.global task_frd_ariel_1
	.thumb
	.thumb_func
	.type task_frd_ariel_1, %function
task_frd_ariel_1: @ 08046FF8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x00C
	adds r7, r0, #0x0
	adds r6, r7, #0x0
	adds r6, #0x20
	ldr r0, _0804701C @ =0x02039BB0
	ldrb r0, [r0, #0x0C]
	cmp r0, #0x02
	beq _0804700C
	b _080472BC
_0804700C:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08047024
	ldr r0, _08047020 @ =0x02039B84
	b _08047026
_0804701C: .4byte 0x02039BB0
_08047020: .4byte 0x02039B84
_08047024:
	ldr r0, _08047068 @ =0x02039B9C
_08047026:
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x17
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804703C
	b _080472BC
_0804703C:
	adds r0, r6, #0x4
	adds r1, r6, #0x0
	adds r1, #0x08
	adds r2, r6, #0x0
	adds r2, #0x0C
	adds r3, r6, #0x0
	adds r3, #0x10
	bl func_0801C6D4
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	beq _080470D2
	cmp r0, #0x01
	bcc _0804706C
	cmp r0, #0x02
	bne _08047064
	b _080471B8
_08047064:
	b _08047336
	.byte 0x00, 0x00
_08047068: .4byte 0x02039B9C
_0804706C:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08047090
	ldr r0, _0804708C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDC
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, #0x30
	b _0804709C
	.byte 0x00, 0x00
_0804708C: .4byte 0x02039B84
_08047090:
	ldr r0, _080470C8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x30
_0804709C:
	lsls r0, r0, #0x08
	ldr r1, [r6, #0x04]
	subs r0, r0, r1
	asrs r0, r0, #0x03
	adds r1, r1, r0
	str r1, [r6, #0x04]
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x14
	ble _080470CC
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x01
	str r0, [r1, #0x00]
	b _08047336
_080470C8: .4byte 0x02039B84
_080470CC:
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
	b _08047336
_080470D2:
	movs r1, #0xA7
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r1, [r0, r2]
	cmp r1, #0x00
	bne _08047106
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r0, r7, r3
	str r1, [r0, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x0C
	strh r0, [r1, #0x00]
	ldr r0, _08047164 @ =0x0813EC5C
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldr r2, [r7, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x02
	movs r3, #0x00
	bl func_08019068
_08047106:
	movs r3, #0x98
	lsls r3, r3, #0x01
	adds r0, r7, r3
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	blt _0804711C
	cmp r0, #0x02
	ble _08047176
_0804711C:
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r4, r7, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	ble _08047144
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r7, r2
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r1, r7, r3
	ldr r1, [r1, #0x00]
	ldrh r2, [r4, #0x00]
	bl ApproachValue
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
_08047144:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08047168
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r1, [r6, #0x04]
	ldr r0, [r0, #0x00]
	subs r1, r1, r0
	b _08047174
	.byte 0x00, 0x00
_08047164: .4byte 0x0813EC5C
_08047168:
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r1, [r6, #0x04]
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
_08047174:
	str r1, [r6, #0x04]
_08047176:
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r0, r7, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bgt _080471AA
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r0, r7, r2
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080471AA
	movs r3, #0xA7
	lsls r3, r3, #0x01
	adds r1, r7, r3
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x02
	str r0, [r1, #0x00]
	b _08047336
_080471AA:
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r1, r7, r2
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _08047336
_080471B8:
	ldr r0, _080471F8 @ =0x0813EC5C
	movs r3, #0x98
	lsls r3, r3, #0x01
	adds r1, r7, r3
	ldr r2, [r7, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080471FC
	ldr r1, [r6, #0x04]
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x77
	bl func_08011F78
	cmp r0, #0x00
	bne _08047214
	b _0804721C
	.byte 0x00, 0x00
_080471F8: .4byte 0x0813EC5C
_080471FC:
	ldr r1, [r6, #0x04]
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x77
	bl func_08011F78
	cmp r0, #0x00
	beq _0804721C
_08047214:
	movs r0, #0x94
	lsls r0, r0, #0x02
	bl m4aSongNumStart
_0804721C:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	mov r12, r2
	cmp r2, #0x00
	beq _0804728C
	movs r3, #0xAE
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldr r1, [r6, #0x04]
	ldr r0, [r0, #0x00]
	subs r1, r1, r0
	str r1, [r6, #0x04]
	ldr r0, _08047288 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x30
	lsls r0, r0, #0x08
	cmp r1, r0
	bge _080472EE
	subs r3, #0x04
	adds r1, r7, r3
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	beq _080472BC
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	movs r0, #0xA7
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r0, [r7, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r6, #0x08]
	bl func_08019A30
	b _080472EE
	.byte 0x00, 0x00
_08047288: .4byte 0x02039B84
_0804728C:
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r1, [r6, #0x04]
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r6, #0x04]
	ldr r0, _080472C0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x30
	lsls r0, r0, #0x08
	cmp r1, r0
	ble _080472EE
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r1, r7, r3
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	bne _080472C4
_080472BC:
	movs r0, #0x00
	b _08047348
_080472C0: .4byte 0x02039B84
_080472C4:
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
	ldr r4, [r6, #0x34]
	ldr r5, [r6, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	adds r0, r4, #0x0
	orrs r0, r2
	adds r1, r5, #0x0
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	movs r1, #0xA7
	lsls r1, r1, #0x01
	adds r0, r7, r1
	mov r2, r12
	strh r2, [r0, #0x00]
	ldr r0, [r7, #0x14]
	ldr r0, [r0, #0x08]
	str r0, [r6, #0x08]
	bl func_08019A30
_080472EE:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r3, r7, r0
	ldr r2, _08047350 @ =0x08121400
	movs r1, #0xA7
	lsls r1, r1, #0x01
	adds r4, r7, r1
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r1, r1, #0x03
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r6, #0x0C]
	ldr r0, [r7, #0x14]
	ldr r0, [r0, #0x08]
	ldr r1, [r6, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r6, #0x08]
	movs r3, #0x00
	ldsh r0, [r4, r3]
	cmp r0, #0x14
	bne _08047330
	movs r0, #0xBE
	bl m4aSongNumStart
_08047330:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
_08047336:
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r7, r1
	bl AnimUpdate
	adds r0, r7, #0x0
	bl TaskPoolUpdate
	movs r0, #0x01
_08047348:
	add sp, #0x00C
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08047350: .4byte 0x08121400
.syntax divided
