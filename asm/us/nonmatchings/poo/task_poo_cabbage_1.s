.syntax unified
	.align 2, 0
	.global task_poo_cabbage_1
	.thumb
	.thumb_func
	.type task_poo_cabbage_1, %function
task_poo_cabbage_1: @ 080D11B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x020
	adds r5, r0, #0x0
	ldr r1, _080D11E4 @ =0x096FD850
	mov r0, sp
	movs r2, #0x1E
	bl _0811F030
	adds r1, r5, #0x0
	adds r1, #0xCE
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	adds r7, r5, #0x0
	adds r7, #0xA4
	ldrh r0, [r7, #0x00]
	cmp r0, #0x02
	beq _080D11F6
	cmp r0, #0x02
	bgt _080D11E8
	cmp r0, #0x01
	bne _080D11E2
	b _080D1474
_080D11E2:
	b _080D1492
_080D11E4: .4byte 0x096FD850
_080D11E8:
	cmp r0, #0x03
	bne _080D11EE
	b _080D1358
_080D11EE:
	cmp r0, #0x04
	bne _080D11F4
	b _080D13CA
_080D11F4:
	b _080D1492
_080D11F6:
	ldr r0, _080D1290 @ =0x0203C3D8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D129C
	movs r0, #0x44
	adds r0, r0, r5
	mov r8, r0
	bl func_080C76B0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D129C
	adds r4, r5, #0x0
	adds r4, #0xBC
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	adds r6, r5, #0x0
	adds r6, #0xA8
	cmp r0, #0x00
	beq _080D122A
	ldr r1, [r4, #0x00]
	adds r0, r6, #0x0
	bl func_08000DE8
_080D122A:
	ldr r1, _080D1294 @ =0x09EF4BC8
	adds r2, r5, #0x0
	adds r2, #0x24
	adds r0, r6, #0x0
	bl func_08000E14
	str r0, [r4, #0x00]
	movs r0, #0x03
	strh r0, [r7, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x0C
	movs r1, #0x03
	movs r2, #0x00
	bl func_080059A4
	movs r0, #0xDE
	bl func_0811FE70
	adds r1, r5, #0x0
	adds r1, #0xCA
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	adds r1, #0x02
	movs r0, #0x14
	strh r0, [r1, #0x00]
	subs r1, #0x2C
	ldr r0, _080D1298 @ =0xFFFFE000
	str r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x34
	bl func_080D1078
	bl func_080D1710
	adds r1, r5, #0x0
	adds r1, #0xD4
	strh r0, [r1, #0x00]
	bl func_080D16FC
	adds r4, r5, #0x0
	adds r4, #0xD0
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080D1284
	b _080D1492
_080D1284:
	mov r0, r8
	bl func_08012304
	movs r0, #0x00
	strb r0, [r4, #0x00]
	b _080D1492
_080D1290: .4byte 0x0203C3D8
_080D1294: .4byte 0x09EF4BC8
_080D1298: .4byte 0xFFFFE000
_080D129C:
	ldr r4, _080D134C @ =0x08121400
	adds r2, r5, #0x0
	adds r2, #0xC8
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r3, r5, #0x0
	adds r3, #0xC0
	ldr r0, [r3, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x24]
	adds r0, r0, r1
	str r0, [r5, #0x24]
	ldrb r0, [r2, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	ldr r1, [r3, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x28]
	adds r0, r0, r1
	str r0, [r5, #0x28]
	subs r2, #0x04
	ldr r1, [r2, #0x00]
	adds r1, #0x33
	str r1, [r2, #0x00]
	ldr r0, [r5, #0x2C]
	adds r0, r0, r1
	str r0, [r5, #0x2C]
	cmp r0, #0x00
	ble _080D12F8
	movs r0, #0x00
	str r0, [r5, #0x2C]
	ldr r1, [r2, #0x00]
	movs r0, #0xB3
	muls r0, r1
	asrs r0, r0, #0x08
	negs r0, r0
	str r0, [r2, #0x00]
_080D12F8:
	adds r0, r5, #0x0
	adds r0, #0xD1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D1304
	b _080D1492
_080D1304:
	ldr r2, [r5, #0x24]
	asrs r2, r2, #0x08
	ldr r0, _080D1350 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r5, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080D1354 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	movs r3, #0x80
	lsls r3, r3, #0x0D
	adds r2, r2, r3
	movs r0, #0x88
	lsls r0, r0, #0x11
	cmp r2, r0
	bls _080D1334
	b _080D148E
_080D1334:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x24
	negs r0, r0
	cmp r1, r0
	bge _080D1342
	b _080D148E
_080D1342:
	cmp r1, #0xC4
	bgt _080D1348
	b _080D1492
_080D1348:
	b _080D148E
	.byte 0x00, 0x00
_080D134C: .4byte 0x08121400
_080D1350: .4byte 0x0203C40C
_080D1354: .4byte 0x0203C3F8
_080D1358:
	adds r4, r5, #0x0
	adds r4, #0xCC
	ldrh r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D1390
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r6, r5, #0x0
	adds r6, #0xA0
	ldr r1, [r5, #0x3C]
	ldr r2, [r6, #0x00]
	adds r1, r1, r2
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	bne _080D1390
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	bge _080D1390
	movs r0, #0x0A
	strh r0, [r4, #0x00]
	str r1, [r6, #0x00]
_080D1390:
	adds r0, r5, #0x0
	adds r0, #0x24
	ldr r1, [r5, #0x34]
	adds r4, r5, #0x0
	adds r4, #0xCA
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	adds r0, r5, #0x0
	adds r0, #0x28
	ldr r1, [r5, #0x38]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D1492
	adds r0, r5, #0x0
	adds r0, #0xA4
	movs r1, #0x04
	strh r1, [r0, #0x00]
	subs r0, #0x98
	movs r2, #0x00
	bl func_080059A4
	b _080D1492
_080D13CA:
	movs r0, #0x04
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D13F2
	adds r0, r5, #0x0
	adds r0, #0xD4
	ldrh r0, [r0, #0x00]
	cmp r0, #0x0D
	bne _080D13F2
	movs r0, #0x8E
	bl func_080C7B84
	movs r0, #0x04
	bl func_080D2D3C
	movs r0, #0x53
	bl func_0800FDD0
_080D13F2:
	adds r6, r5, #0x0
	adds r6, #0x0C
	adds r0, r6, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D1492
	adds r1, r5, #0x0
	adds r1, #0xA4
	movs r4, #0x00
	movs r7, #0x00
	movs r0, #0x01
	strh r0, [r1, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
	bl func_080D171C
	adds r0, r5, #0x0
	adds r0, #0xD2
	strb r4, [r0, #0x00]
	adds r0, #0x02
	ldrh r0, [r0, #0x00]
	cmp r0, #0x05
	bne _080D1448
	ldr r0, _080D143C @ =0x000AB300
	str r0, [r5, #0x24]
	ldr r0, _080D1440 @ =0x00057100
	str r0, [r5, #0x28]
	str r7, [r5, #0x2C]
	ldr r0, _080D1444 @ =0x09756D86
	str r0, [r5, #0x08]
	b _080D1492
	.byte 0x00, 0x00
_080D143C: .4byte 0x000AB300
_080D1440: .4byte 0x00057100
_080D1444: .4byte 0x09756D86
_080D1448:
	cmp r0, #0x08
	bne _080D1468
	ldr r0, _080D145C @ =0x000AB300
	str r0, [r5, #0x24]
	ldr r0, _080D1460 @ =0x00057100
	str r0, [r5, #0x28]
	str r7, [r5, #0x2C]
	ldr r0, _080D1464 @ =0x09756D90
	str r0, [r5, #0x08]
	b _080D1492
_080D145C: .4byte 0x000AB300
_080D1460: .4byte 0x00057100
_080D1464: .4byte 0x09756D90
_080D1468:
	ldr r0, _080D1470 @ =0x09756C78
	str r0, [r5, #0x08]
	b _080D1492
	.byte 0x00, 0x00
_080D1470: .4byte 0x09756C78
_080D1474:
	adds r0, r5, #0x0
	adds r0, #0xD4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	mov r1, sp
	adds r4, r1, r0
	bl func_080D172C
	ldrh r1, [r4, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bcs _080D1492
_080D148E:
	movs r0, #0x00
	b _080D1494
_080D1492:
	movs r0, #0x01
_080D1494:
	add sp, #0x020
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
