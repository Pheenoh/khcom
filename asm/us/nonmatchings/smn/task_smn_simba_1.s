.syntax unified
	.align 2, 0
	.global task_smn_simba_1
	.thumb
	.thumb_func
	.type task_smn_simba_1, %function
task_smn_simba_1: @ 08043244
	push {r4, r5, r6, r7, lr}
	add sp, #-0x00C
	adds r7, r0, #0x0
	adds r5, r7, #0x0
	adds r5, #0x38
	ldr r1, _0804325C @ =0x00000155
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08043264
	ldr r0, _08043260 @ =0x02039B84
	b _08043266
_0804325C: .4byte 0x00000155
_08043260: .4byte 0x02039B84
_08043264:
	ldr r0, _08043294 @ =0x02039B9C
_08043266:
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x17
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08043334
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	bl func_0802F284
	ldr r0, [r7, #0x34]
	cmp r0, #0x01
	beq _0804334A
	cmp r0, #0x01
	bcc _08043298
	cmp r0, #0x02
	beq _080432F0
	b _0804355C
_08043294: .4byte 0x02039B9C
_08043298:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r6, r7, r2
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	bne _080432BE
	adds r2, #0x02
	adds r1, r7, r2
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	bl func_080140E0
	ldr r0, _080432EC @ =0x00000235
	bl m4aSongNumStart
_080432BE:
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r7, r1
	subs r1, #0x50
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r4, r7, r2
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bgt _0804333C
	movs r1, #0x01
	str r1, [r7, #0x34]
	movs r0, #0x00
	strh r0, [r6, #0x00]
	movs r2, #0xAB
	lsls r2, r2, #0x01
	adds r0, r7, r2
	strb r1, [r0, #0x00]
	b _0804355C
_080432EC: .4byte 0x00000235
_080432F0:
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r6, r7, r0
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	bne _08043318
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	bl func_080140E0
	ldr r0, _08043338 @ =0x00000239
	bl m4aSongNumStart
_08043318:
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r2, #0xA5
	lsls r2, r2, #0x01
	adds r4, r7, r2
	ldrh r2, [r4, #0x00]
	movs r1, #0x19
	bl func_080058FC
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bgt _0804333C
_08043334:
	movs r0, #0x00
	b _08043596
_08043338: .4byte 0x00000239
_0804333C:
	ldrh r0, [r6, #0x00]
	adds r0, #0x01
	strh r0, [r6, #0x00]
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	b _0804355C
_0804334A:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r7, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	beq _0804335E
	cmp r0, #0x32
	beq _080433AC
	b _0804351C
_0804335E:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043388
	ldr r1, _08043380 @ =0x00000133
	ldr r2, [r5, #0x04]
	ldr r4, _08043384 @ =0xFFFFEC00
	adds r2, r2, r4
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	adds r3, r3, r0
	adds r3, r3, r4
	b _0804339C
_08043380: .4byte 0x00000133
_08043384: .4byte 0xFFFFEC00
_08043388:
	ldr r1, _080433A4 @ =0x00000133
	ldr r2, [r5, #0x04]
	movs r0, #0xA0
	lsls r0, r0, #0x05
	adds r2, r2, r0
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	adds r3, r3, r0
	ldr r0, _080433A8 @ =0xFFFFEC00
	adds r3, r3, r0
_0804339C:
	movs r0, #0x1E
	bl func_08019050
	b _0804351C
_080433A4: .4byte 0x00000133
_080433A8: .4byte 0xFFFFEC00
_080433AC:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _080433CC
	cmp r0, #0x01
	bgt _080433D8
	cmp r0, #0x00
	bne _080433D8
	ldr r0, _080433C8 @ =0x0000024A
	bl m4aSongNumStart
	b _080433E0
_080433C8: .4byte 0x0000024A
_080433CC:
	ldr r0, _080433D4 @ =0x0000024B
	bl m4aSongNumStart
	b _080433E0
_080433D4: .4byte 0x0000024B
_080433D8:
	movs r0, #0x93
	lsls r0, r0, #0x02
	bl m4aSongNumStart
_080433E0:
	bl func_0802F1E8
	movs r0, #0x05
	movs r1, #0x08
	movs r2, #0x14
	bl func_08006290
	movs r2, #0x80
	lsls r2, r2, #0x09
	movs r3, #0xAF
	lsls r3, r3, #0x09
	movs r0, #0x1E
	movs r1, #0xCC
	bl func_08019050
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043428
	ldr r0, [r5, #0x04]
	ldr r3, _08043424 @ =0xFFFFEC00
	adds r0, r0, r3
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r1, r1, r2
	adds r1, r1, r3
	movs r2, #0x01
	bl func_08014FDC
	b _08043440
_08043424: .4byte 0xFFFFEC00
_08043428:
	ldr r0, [r5, #0x04]
	movs r2, #0xA0
	lsls r2, r2, #0x05
	adds r0, r0, r2
	ldr r1, [r5, #0x08]
	ldr r2, [r5, #0x0C]
	adds r1, r1, r2
	ldr r2, _0804346C @ =0xFFFFEC00
	adds r1, r1, r2
	movs r2, #0x00
	bl func_08014FDC
_08043440:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _08043492
	cmp r0, #0x01
	bgt _080434CE
	cmp r0, #0x00
	bne _080434CE
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043474
	ldr r1, [r5, #0x04]
	ldr r2, _08043470 @ =0xFFFF8000
	adds r1, r1, r2
	b _0804347C
_0804346C: .4byte 0xFFFFEC00
_08043470: .4byte 0xFFFF8000
_08043474:
	ldr r1, [r5, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x08
	adds r1, r1, r0
_0804347C:
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x80
	str r0, [sp, #0x000]
	adds r0, #0x80
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x99
	bl func_08011F78
	b _0804351C
_08043492:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080434B0
	ldr r1, [r5, #0x04]
	ldr r2, _080434AC @ =0xFFFF8000
	adds r1, r1, r2
	b _080434B8
	.byte 0x00, 0x00
_080434AC: .4byte 0xFFFF8000
_080434B0:
	ldr r1, [r5, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x08
	adds r1, r1, r0
_080434B8:
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x80
	str r0, [sp, #0x000]
	adds r0, #0x80
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x9A
	bl func_08011F78
	b _0804351C
_080434CE:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08043500
	ldr r1, [r5, #0x04]
	ldr r2, _080434FC @ =0xFFFF8000
	adds r1, r1, r2
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x80
	str r0, [sp, #0x000]
	adds r0, #0x80
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x9B
	bl func_08011F78
	b _0804351C
	.byte 0x00, 0x00
_080434FC: .4byte 0xFFFF8000
_08043500:
	ldr r1, [r5, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x08
	adds r1, r1, r0
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x80
	str r0, [sp, #0x000]
	adds r0, #0x80
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x9B
	bl func_08011F78
_0804351C:
	adds r0, r7, #0x0
	adds r0, #0x08
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08043550
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldr r0, _0804354C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	movs r0, #0x08
	bl func_08019050
	movs r0, #0x02
	str r0, [r7, #0x34]
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x00
	b _0804355A
	.byte 0x00, 0x00
_0804354C: .4byte 0x02039B84
_08043550:
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
_0804355A:
	strh r0, [r1, #0x00]
_0804355C:
	movs r1, #0xAB
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08043570
	adds r0, r7, #0x0
	adds r0, #0x08
	bl AnimUpdate
_08043570:
	adds r0, r5, #0x4
	adds r1, r5, #0x0
	adds r1, #0x08
	adds r2, r5, #0x0
	adds r2, #0x0C
	adds r3, r5, #0x0
	adds r3, #0x10
	bl func_0801C6D4
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x10]
	cmp r0, r1
	ble _0804358C
	str r1, [r5, #0x0C]
_0804358C:
	adds r0, r7, #0x0
	adds r0, #0x20
	bl TaskPoolUpdate
	movs r0, #0x01
_08043596:
	add sp, #0x00C
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
