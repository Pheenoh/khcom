.syntax unified
	.align 2, 0
	.global task_smn_mushu_1
	.thumb
	.thumb_func
	.type task_smn_mushu_1, %function
task_smn_mushu_1: @ 08043878
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x020
	adds r7, r0, #0x0
	adds r6, r7, #0x0
	adds r6, #0x38
	ldr r1, _08043898 @ =0x00000153
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080438A0
	ldr r0, _0804389C @ =0x02039B84
	b _080438A2
_08043898: .4byte 0x00000153
_0804389C: .4byte 0x02039B84
_080438A0:
	ldr r0, _08043908 @ =0x02039B9C
_080438A2:
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x17
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080438B8
	b _080439D4
_080438B8:
	ldr r2, [r6, #0x04]
	mov r10, r2
	ldr r3, [r6, #0x08]
	str r3, [sp, #0x018]
	ldr r4, [r6, #0x0C]
	str r4, [sp, #0x01C]
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [r6, #0x04]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x08]
	str r0, [r6, #0x08]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x0C]
	ldr r2, _0804390C @ =0xFFFFDE00
	adds r0, r0, r2
	str r0, [r6, #0x0C]
	ldr r0, [r1, #0x00]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043910
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r4, #0x04
	movs r5, #0x00
	adds r2, r0, #0x0
	orrs r2, r4
	adds r3, r1, #0x0
	str r2, [r6, #0x34]
	str r3, [r6, #0x38]
	b _0804391E
	.byte 0x00, 0x00
_08043908: .4byte 0x02039B9C
_0804390C: .4byte 0xFFFFDE00
_08043910:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
_0804391E:
	ldr r0, [r7, #0x34]
	cmp r0, #0x01
	beq _08043990
	cmp r0, #0x01
	bcc _08043932
	cmp r0, #0x02
	beq _08043A20
	cmp r0, #0x03
	beq _080439EA
	b _08043BA4
_08043932:
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r5, r7, r3
	movs r4, #0x00
	ldsh r0, [r5, r4]
	cmp r0, #0x00
	bne _0804395A
	movs r0, #0xA5
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r6, #0x04]
	ldr r1, [r6, #0x08]
	ldr r2, [r6, #0x0C]
	bl func_080140E0
	ldr r0, _0804398C @ =0x00000235
	bl m4aSongNumStart
_0804395A:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r7, r1
	subs r1, #0x4C
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r4, r7, r2
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	movs r3, #0x00
	ldsh r0, [r4, r3]
	cmp r0, #0x00
	bgt _080439DC
	movs r0, #0x03
	str r0, [r7, #0x34]
	movs r0, #0x00
	strh r0, [r5, #0x00]
	movs r4, #0xAA
	lsls r4, r4, #0x01
	adds r1, r7, r4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08043BA4
	.byte 0x00, 0x00
_0804398C: .4byte 0x00000235
_08043990:
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r5, r7, r0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	bne _080439B8
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r6, #0x04]
	ldr r1, [r6, #0x08]
	ldr r2, [r6, #0x0C]
	bl func_080140E0
	ldr r0, _080439D8 @ =0x00000239
	bl m4aSongNumStart
_080439B8:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r7, r3
	movs r1, #0xA5
	lsls r1, r1, #0x01
	adds r4, r7, r1
	ldrh r2, [r4, #0x00]
	movs r1, #0x19
	bl func_080058FC
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	bgt _080439DC
_080439D4:
	movs r0, #0x00
	b _08043BC2
_080439D8: .4byte 0x00000239
_080439DC:
	ldrh r0, [r5, #0x00]
	adds r0, #0x01
	strh r0, [r5, #0x00]
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	b _08043BA4
_080439EA:
	ldr r0, _08043A1C @ =0x0813EA7C
	adds r4, r7, #0x0
	adds r4, #0x08
	ldr r1, [r7, #0x00]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x02
	movs r3, #0x00
	bl func_08019068
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08043A0C
	b _08043BA4
_08043A0C:
	movs r0, #0x02
	str r0, [r7, #0x34]
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r1, r7, r3
	movs r0, #0x00
	strh r0, [r1, #0x00]
	b _08043BA4
_08043A1C: .4byte 0x0813EA7C
_08043A20:
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r0, r7, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r4, r7, #0x0
	adds r4, #0x08
	cmp r0, #0x00
	bne _08043A7A
	ldr r0, _08043A60 @ =0x0813EA7C
	ldr r1, [r7, #0x00]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x03
	movs r3, #0x01
	bl func_08019068
	movs r2, #0xA9
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08043A64
	cmp r0, #0x01
	bgt _08043A6E
	cmp r0, #0x00
	bne _08043A6E
	movs r3, #0xA5
	lsls r3, r3, #0x01
	adds r1, r7, r3
	movs r0, #0x78
	b _08043A78
_08043A60: .4byte 0x0813EA7C
_08043A64:
	movs r0, #0xA5
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0xF0
	b _08043A78
_08043A6E:
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0xF0
	lsls r0, r0, #0x01
_08043A78:
	strh r0, [r1, #0x00]
_08043A7A:
	adds r0, r4, #0x0
	bl func_08005B38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bne _08043B50
	ldrh r0, [r7, #0x12]
	cmp r0, #0x00
	bne _08043B50
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043AAC
	ldr r0, [r6, #0x04]
	ldr r3, _08043AA8 @ =0xFFFF3800
	adds r4, r0, r3
	b _08043AB4
	.byte 0x00, 0x00
_08043AA8: .4byte 0xFFFF3800
_08043AAC:
	ldr r0, [r6, #0x04]
	movs r1, #0xC8
	lsls r1, r1, #0x08
	adds r4, r0, r1
_08043AB4:
	ldr r2, [r6, #0x08]
	mov r8, r2
	movs r3, #0x00
	mov r9, r3
	movs r1, #0xA9
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08043AD4
	cmp r0, #0x01
	bgt _08043AD8
	cmp r0, #0x00
	bne _08043AD8
	movs r5, #0x9D
	b _08043ADA
_08043AD4:
	movs r5, #0x9E
	b _08043ADA
_08043AD8:
	movs r5, #0x9F
_08043ADA:
	bl func_08019A30
	ldr r0, _08043B1C @ =0x0000024D
	bl m4aSongNumStart
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043B28
	ldr r1, [r6, #0x04]
	ldr r2, _08043B20 @ =0xFFFFC800
	adds r1, r1, r2
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x0C]
	ldr r0, _08043B24 @ =0xFFFFF800
	adds r3, r3, r0
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r0, r9
	str r0, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	str r5, [sp, #0x010]
	movs r0, #0x00
	bl func_08012E44
	b _08043B50
	.byte 0x00, 0x00
_08043B1C: .4byte 0x0000024D
_08043B20: .4byte 0xFFFFC800
_08043B24: .4byte 0xFFFFF800
_08043B28:
	ldr r1, [r6, #0x04]
	movs r2, #0xE0
	lsls r2, r2, #0x06
	adds r1, r1, r2
	ldr r3, [r6, #0x08]
	mov r12, r3
	ldr r3, [r6, #0x0C]
	ldr r2, _08043B9C @ =0xFFFFF800
	adds r3, r3, r2
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r2, r9
	str r2, [sp, #0x008]
	str r0, [sp, #0x00C]
	str r5, [sp, #0x010]
	movs r0, #0x00
	mov r2, r12
	bl func_08012E44
_08043B50:
	mov r1, sp
	adds r1, #0x16
	add r0, sp, #0x014
	bl func_08006B80
	add r0, sp, #0x014
	ldrh r0, [r0, #0x00]
	cmp r0, #0x03
	bhi _08043B78
	ldr r0, [r6, #0x04]
	mov r3, r10
	subs r0, r0, r3
	ldr r1, [r6, #0x08]
	ldr r4, [sp, #0x018]
	subs r1, r1, r4
	ldr r2, [r6, #0x0C]
	ldr r3, [sp, #0x01C]
	subs r2, r2, r3
	bl func_0801475C
_08043B78:
	movs r4, #0xA4
	lsls r4, r4, #0x01
	adds r2, r7, r4
	movs r1, #0xA5
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrh r3, [r2, #0x00]
	movs r4, #0x00
	ldsh r1, [r2, r4]
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r1, r0
	ble _08043BA0
	movs r0, #0x01
	str r0, [r7, #0x34]
	movs r0, #0x00
	b _08043BA2
	.byte 0x00, 0x00
_08043B9C: .4byte 0xFFFFF800
_08043BA0:
	adds r0, r3, #0x1
_08043BA2:
	strh r0, [r2, #0x00]
_08043BA4:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08043BB8
	adds r0, r7, #0x0
	adds r0, #0x08
	bl AnimUpdate
_08043BB8:
	adds r0, r7, #0x0
	adds r0, #0x20
	bl TaskPoolUpdate
	movs r0, #0x01
_08043BC2:
	add sp, #0x020
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
