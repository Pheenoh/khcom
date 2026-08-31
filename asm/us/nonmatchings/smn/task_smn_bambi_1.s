.syntax unified
	.align 2, 0
	.global task_smn_bambi_1
	.thumb
	.thumb_func
	.type task_smn_bambi_1, %function
task_smn_bambi_1: @ 080420E0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x02C
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x38
	ldr r1, _08042100 @ =0x00000163
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08042108
	ldr r0, _08042104 @ =0x02039B84
	b _0804210A
	.byte 0x00, 0x00
_08042100: .4byte 0x00000163
_08042104: .4byte 0x02039B84
_08042108:
	ldr r0, _08042134 @ =0x02039B9C
_0804210A:
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x17
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08042206
	ldr r6, [r5, #0x34]
	cmp r6, #0x01
	bne _08042126
	b _080423AE
_08042126:
	cmp r6, #0x01
	bcc _08042138
	cmp r6, #0x02
	beq _0804221E
	cmp r6, #0x03
	beq _080421C2
	b _08042512
_08042134: .4byte 0x02039B9C
_08042138:
	ldr r2, _080421A0 @ =0x00000163
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0804214C
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	bl func_0802F284
_0804214C:
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r6, r5, r0
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	bne _08042174
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	bl func_080140E0
	ldr r0, _080421A4 @ =0x00000235
	bl m4aSongNumStart
_08042174:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	subs r1, #0x54
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bgt _08042210
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080421A8
	movs r0, #0x02
	b _080421AA
_080421A0: .4byte 0x00000163
_080421A4: .4byte 0x00000235
_080421A8:
	movs r0, #0x01
_080421AA:
	str r0, [r5, #0x34]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r2, #0xB2
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08042512
_080421C2:
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r6, r5, r0
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	bne _080421EA
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	bl func_080140E0
	ldr r0, _0804220C @ =0x00000239
	bl m4aSongNumStart
_080421EA:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r4, r5, r2
	ldrh r2, [r4, #0x00]
	movs r1, #0x19
	bl func_080058FC
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bgt _08042210
_08042206:
	movs r0, #0x00
	b _08042530
	.byte 0x00, 0x00
_0804220C: .4byte 0x00000239
_08042210:
	ldrh r0, [r6, #0x00]
	adds r0, #0x01
	strh r0, [r6, #0x00]
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	b _08042512
_0804221E:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x00
	ldsh r7, [r0, r1]
	cmp r7, #0x00
	bne _0804225E
	adds r0, r5, #0x0
	adds r0, #0x08
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, _08042340 @ =0xFFFFFB80
	str r0, [r1, #0x00]
	ldr r0, _08042344 @ =0x00000236
	bl m4aSongNumStart
	adds r0, r5, #0x0
	bl func_08042018
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	movs r1, #0xA5
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strh r7, [r0, #0x00]
_0804225E:
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r7, r5, r2
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	ble _080422CC
	bl func_08019A30
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	ldr r0, _08042348 @ =0xFFFFFC00
	mov r8, r0
	add r3, r8
	movs r0, #0x08
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x76
	bl func_08011F78
	cmp r0, #0x00
	beq _080422CC
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	bl func_0801416C
	adds r0, r5, #0x0
	adds r0, #0x08
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	mov r1, r8
	str r1, [r7, #0x00]
	ldr r0, _08042344 @ =0x00000236
	bl m4aSongNumStart
	ldr r0, _0804234C @ =0x0000028D
	bl m4aSongNumStart
	adds r0, r5, #0x0
	bl func_08042018
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	movs r0, #0xA5
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080422CC:
	adds r0, r5, #0x0
	bl func_08041FCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0804230E
	adds r0, r5, #0x0
	adds r0, #0x08
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, _08042340 @ =0xFFFFFB80
	str r0, [r1, #0x00]
	ldr r0, _08042344 @ =0x00000236
	bl m4aSongNumStart
	adds r0, r5, #0x0
	bl func_08042018
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r5, r2
	str r0, [r1, #0x00]
	movs r0, #0xA5
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0804230E:
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	ble _08042328
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x07
	bgt _08042334
_08042328:
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08042350
_08042334:
	movs r0, #0x03
	str r0, [r5, #0x34]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	b _0804250E
_08042340: .4byte 0xFFFFFB80
_08042344: .4byte 0x00000236
_08042348: .4byte 0xFFFFFC00
_0804234C: .4byte 0x0000028D
_08042350:
	ldr r0, [r0, #0x04]
	ldr r6, [r4, #0x04]
	cmp r6, r0
	bge _08042364
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	b _0804236E
_08042364:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
_0804236E:
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	movs r2, #0xB4
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x04]
	subs r0, r0, r6
	asrs r0, r0, #0x04
	adds r0, r6, r0
	str r0, [r4, #0x04]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x08]
	ldr r1, [r4, #0x08]
	subs r0, r0, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r4, #0x08]
	adds r0, r4, #0x4
	adds r1, r4, #0x0
	adds r1, #0x08
	movs r2, #0x10
	negs r2, r2
	movs r3, #0x00
	bl func_0801A8A4
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	b _08042510
_080423AE:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r1, #0x08
	adds r1, r1, r5
	mov r9, r1
	cmp r0, #0x00
	bne _080423DC
	mov r0, r9
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	adds r0, r5, #0x0
	bl func_08041D64
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x1E
	strh r0, [r1, #0x00]
_080423DC:
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080423FE
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	movs r0, #0x08
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x75
	bl func_08011F78
	b _08042412
_080423FE:
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	movs r0, #0x08
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x74
	bl func_08011F78
_08042412:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r7, r4, #0x4
	movs r2, #0x08
	adds r2, r2, r4
	mov r8, r2
	cmp r0, #0x04
	ble _0804246E
	cmp r0, #0x05
	bne _0804243C
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, _080424C4 @ =0xFFFFFD00
	str r1, [r0, #0x00]
	ldr r0, _080424C8 @ =0x00000236
	bl m4aSongNumStart
_0804243C:
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r6, r5, r2
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	ble _0804246E
	adds r2, #0x26
	adds r0, r5, r2
	ldr r1, [r0, #0x00]
	ldrh r2, [r6, #0x00]
	adds r0, r7, #0x0
	bl func_0800592C
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	ldrh r2, [r6, #0x00]
	mov r0, r8
	bl func_0800592C
	ldrh r0, [r6, #0x00]
	subs r0, #0x01
	strh r0, [r6, #0x00]
_0804246E:
	adds r0, r5, #0x0
	bl func_08041FCC
	movs r2, #0x10
	negs r2, r2
	adds r0, r7, #0x0
	mov r1, r8
	movs r3, #0x00
	bl func_0801A8A4
	mov r0, r9
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080424F0
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x00C]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x010]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x014]
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080424CC
	add r1, sp, #0x00C
	movs r0, #0x01
	b _080424D0
	.byte 0x00, 0x00
_080424C4: .4byte 0xFFFFFD00
_080424C8: .4byte 0x00000236
_080424CC:
	add r1, sp, #0x00C
	movs r0, #0x02
_080424D0:
	strh r0, [r1, #0x12]
	add r1, sp, #0x00C
	movs r0, #0x00
	strh r0, [r1, #0x14]
	ldr r0, _080424E8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _080424EC @ =0x09EDAF18
	add r2, sp, #0x00C
	bl TaskCreate
	b _080424FC
_080424E8: .4byte 0x02039B84
_080424EC: .4byte 0x09EDAF18
_080424F0:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080424FC:
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	cmp r0, #0x04
	ble _08042512
	movs r0, #0x03
	str r0, [r5, #0x34]
_0804250E:
	movs r0, #0x00
_08042510:
	strh r0, [r1, #0x00]
_08042512:
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08042526
	adds r0, r5, #0x0
	adds r0, #0x08
	bl AnimUpdate
_08042526:
	adds r0, r5, #0x0
	adds r0, #0x20
	bl TaskPoolUpdate
	movs r0, #0x01
_08042530:
	add sp, #0x02C
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
