.syntax unified
	.align 2, 0
	.global task_frd_aladdin_1
	.thumb
	.thumb_func
	.type task_frd_aladdin_1, %function
task_frd_aladdin_1: @ 08049324
	push {r4, r5, r6, r7, lr}
	add sp, #-0x00C
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r7, #0x20
	ldr r0, _08049348 @ =0x02039BB0
	ldrb r0, [r0, #0x0C]
	cmp r0, #0x01
	beq _08049338
	b _080494D4
_08049338:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08049350
	ldr r0, _0804934C @ =0x02039B84
	b _08049352
_08049348: .4byte 0x02039BB0
_0804934C: .4byte 0x02039B84
_08049350:
	ldr r0, _08049384 @ =0x02039B9C
_08049352:
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x17
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049368
	b _080494D4
_08049368:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r5, r6, r2
	ldr r0, [r5, #0x00]
	cmp r0, #0x01
	beq _080493F4
	cmp r0, #0x01
	bcc _08049388
	cmp r0, #0x02
	beq _0804943C
	cmp r0, #0x03
	bne _08049382
	b _080494F4
_08049382:
	b _08049678
_08049384: .4byte 0x02039B9C
_08049388:
	movs r0, #0xA7
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _080493B0
	ldr r0, _080493F0 @ =0x0813ED4C
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r2, [r6, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
_080493B0:
	movs r1, #0xAC
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	ldr r1, [r7, #0x04]
	subs r0, r0, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r7, #0x04]
	adds r0, r7, #0x4
	adds r1, r7, #0x0
	adds r1, #0x08
	movs r2, #0x10
	negs r2, r2
	movs r3, #0x00
	bl func_0801A8A4
	adds r0, r6, #0x0
	bl func_080490FC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080493E0
	b _08049678
_080493E0:
	movs r0, #0x01
	str r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r4, #0x00]
	movs r0, #0xC0
	bl func_0811FE70
	b _08049678
_080493F0: .4byte 0x0813ED4C
_080493F4:
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r4, r6, r2
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _08049414
	ldr r0, _08049430 @ =0x0813ED4C
	subs r2, #0x1E
	adds r1, r6, r2
	ldr r2, [r6, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
_08049414:
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r6, r1
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08049434
	movs r0, #0x03
	str r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r4, #0x00]
	b _08049678
	.byte 0x00, 0x00
_08049430: .4byte 0x0813ED4C
_08049434:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	b _08049678
_0804943C:
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r0, r6, r2
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r0, #0x00
	bne _080494B2
	ldr r0, _08049480 @ =0x0813ED4C
	subs r2, #0x1E
	adds r1, r6, r2
	ldr r2, [r6, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08049488
	movs r4, #0xAC
	lsls r4, r4, #0x01
	adds r1, r6, r4
	ldr r0, _08049484 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x40
	b _0804949A
_08049480: .4byte 0x0813ED4C
_08049484: .4byte 0x02039B84
_08049488:
	movs r4, #0xAC
	lsls r4, r4, #0x01
	adds r1, r6, r4
	ldr r0, _080494D8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x40
_0804949A:
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r4, #0xAA
	lsls r4, r4, #0x01
	adds r1, r6, r4
	ldr r0, _080494DC @ =0xFFFFFB00
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x1E
	strh r0, [r1, #0x00]
_080494B2:
	adds r0, r7, #0x4
	movs r2, #0xAC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r1, [r1, #0x00]
	subs r2, #0x08
	adds r4, r6, r2
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	adds r0, r6, #0x0
	bl func_080490FC
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bgt _080494E0
_080494D4:
	movs r0, #0x00
	b _0804968A
_080494D8: .4byte 0x02039B84
_080494DC: .4byte 0xFFFFFB00
_080494E0:
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	b _08049678
_080494F4:
	movs r4, #0xA7
	lsls r4, r4, #0x01
	adds r0, r6, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bne _08049516
	ldr r0, _08049548 @ =0x0813ED4C
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r2, [r6, #0x18]
	str r2, [sp, #0x000]
	movs r2, #0x02
	movs r3, #0x01
	bl func_08019068
_08049516:
	bl func_0801D288
	ldr r4, [r6, #0x14]
	mov r12, r4
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049550
	ldr r4, [r7, #0x34]
	ldr r5, [r7, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	adds r0, r4, #0x0
	orrs r0, r2
	adds r1, r5, #0x0
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	mov r1, r12
	ldr r0, [r1, #0x04]
	ldr r4, _0804954C @ =0xFFFFD800
	b _08049566
_08049548: .4byte 0x0813ED4C
_0804954C: .4byte 0xFFFFD800
_08049550:
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	mov r1, r12
	ldr r0, [r1, #0x04]
	movs r4, #0xA0
	lsls r4, r4, #0x06
_08049566:
	adds r2, r0, r4
	ldr r0, [r6, #0x14]
	ldr r3, [r0, #0x08]
	ldr r1, [r7, #0x04]
	subs r0, r2, r1
	asrs r0, r0, #0x03
	ldr r2, _080495FC @ =0xFFFFFC00
	cmp r0, r2
	blt _08049580
	movs r2, #0x80
	lsls r2, r2, #0x03
	cmp r0, r2
	ble _08049582
_08049580:
	adds r0, r2, #0x0
_08049582:
	adds r0, r1, r0
	str r0, [r7, #0x04]
	ldr r1, [r7, #0x08]
	subs r0, r3, r1
	asrs r0, r0, #0x05
	ldr r2, _08049600 @ =0xFFFFFE00
	cmp r0, r2
	blt _0804959A
	movs r2, #0x80
	lsls r2, r2, #0x02
	cmp r0, r2
	ble _0804959C
_0804959A:
	adds r0, r2, #0x0
_0804959C:
	adds r0, r1, r0
	str r0, [r7, #0x08]
	movs r1, #0x9D
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0804962E
	movs r2, #0x98
	lsls r2, r2, #0x01
	adds r0, r6, r2
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	blt _0804962E
	cmp r0, #0x01
	ble _080495CA
	cmp r0, #0x06
	bgt _0804962E
	cmp r0, #0x05
	blt _0804962E
_080495CA:
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049608
	ldr r1, [r7, #0x04]
	ldr r4, _08049604 @ =0xFFFFE200
	adds r1, r1, r4
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	movs r0, #0x14
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x32
	str r0, [sp, #0x008]
	movs r0, #0x95
	bl func_08011F78
	cmp r0, #0x00
	bne _08049628
	b _0804962E
	.byte 0x00, 0x00
_080495FC: .4byte 0xFFFFFC00
_08049600: .4byte 0xFFFFFE00
_08049604: .4byte 0xFFFFE200
_08049608:
	ldr r1, [r7, #0x04]
	movs r0, #0xF0
	lsls r0, r0, #0x05
	adds r1, r1, r0
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	movs r0, #0x14
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x32
	str r0, [sp, #0x008]
	movs r0, #0x95
	bl func_08011F78
	cmp r0, #0x00
	beq _0804962E
_08049628:
	ldr r0, _08049670 @ =0x00000251
	bl func_0811FE70
_0804962E:
	adds r0, r6, #0x0
	bl func_080490FC
	adds r0, r7, #0x4
	adds r1, r7, #0x0
	adds r1, #0x08
	movs r2, #0x10
	negs r2, r2
	movs r3, #0x00
	bl func_0801A8A4
	movs r1, #0xA7
	lsls r1, r1, #0x01
	adds r2, r6, r1
	movs r4, #0xA9
	lsls r4, r4, #0x01
	adds r0, r6, r4
	ldrh r3, [r2, #0x00]
	movs r4, #0x00
	ldsh r1, [r2, r4]
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r1, r0
	ble _08049674
	movs r0, #0x00
	strh r0, [r2, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x02
	str r0, [r1, #0x00]
	b _08049678
	.byte 0x00, 0x00
_08049670: .4byte 0x00000251
_08049674:
	adds r0, r3, #0x1
	strh r0, [r2, #0x00]
_08049678:
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r6, r1
	bl func_08005A64
	adds r0, r6, #0x0
	bl func_08000EA4
	movs r0, #0x01
_0804968A:
	add sp, #0x00C
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
