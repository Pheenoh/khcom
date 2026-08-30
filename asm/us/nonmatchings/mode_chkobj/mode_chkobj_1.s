.syntax unified
	.align 2, 0
	.global mode_chkobj_1
	.thumb
	.thumb_func
	.type mode_chkobj_1, %function
mode_chkobj_1: @ 0800B418
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	bl func_08001390
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _0800B438
	ldr r0, _0800B434 @ =0x09ECEB64
	movs r1, #0x00
	bl func_080010CC
	b _0800B990
	.byte 0x00, 0x00
_0800B434: .4byte 0x09ECEB64
_0800B438:
	bl func_08001390
	movs r1, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _0800B458
	ldr r0, _0800B548 @ =0x0203489C
	ldr r0, [r0, #0x00]
	movs r2, #0x00
	adds r1, r0, #0x0
	adds r1, #0x40
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0800B456
	movs r2, #0x01
_0800B456:
	strb r2, [r1, #0x00]
_0800B458:
	ldr r4, _0800B548 @ =0x0203489C
	ldr r0, [r4, #0x00]
	adds r0, #0x24
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800B482
	bl func_08001384
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800B482
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x24
	ldrh r1, [r1, #0x16]
	movs r2, #0x00
	bl func_080059A4
_0800B482:
	bl func_0800139C
	movs r1, #0x30
	ands r1, r0
	cmp r1, #0x00
	bne _0800B490
	b _0800B5E8
_0800B490:
	bl func_0800139C
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _0800B4A6
	ldr r0, _0800B548 @ =0x0203489C
	ldr r1, [r0, #0x00]
	ldrh r0, [r1, #0x16]
	subs r0, #0x01
	strh r0, [r1, #0x16]
_0800B4A6:
	bl func_0800139C
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _0800B4BC
	ldr r0, _0800B548 @ =0x0203489C
	ldr r1, [r0, #0x00]
	ldrh r0, [r1, #0x16]
	adds r0, #0x01
	strh r0, [r1, #0x16]
_0800B4BC:
	ldr r7, _0800B548 @ =0x0203489C
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0x46
	movs r1, #0x00
	movs r4, #0x00
	strh r4, [r2, #0x00]
	adds r0, #0x40
	strb r1, [r0, #0x00]
	ldr r3, [r7, #0x00]
	adds r0, r3, #0x0
	adds r0, #0x44
	strh r4, [r0, #0x00]
	ldr r5, _0800B54C @ =0x0812E744
	movs r0, #0x18
	ldsh r1, [r3, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	movs r2, #0x14
	ldsh r1, [r3, r2]
	lsls r1, r1, #0x05
	ldr r0, [r0, #0x00]
	adds r6, r0, r1
	movs r1, #0x16
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	bge _0800B550
	ldrh r0, [r3, #0x14]
	subs r0, #0x01
	strh r0, [r3, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0800B526
	ldrh r0, [r3, #0x18]
	subs r0, #0x01
	strh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0800B512
	movs r0, #0x09
	strh r0, [r3, #0x18]
_0800B512:
	ldr r2, [r7, #0x00]
	movs r3, #0x18
	ldsh r1, [r2, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	ldrh r0, [r0, #0x04]
	subs r0, #0x01
	strh r0, [r2, #0x14]
_0800B526:
	ldr r3, _0800B54C @ =0x0812E744
	ldr r0, _0800B548 @ =0x0203489C
	ldr r2, [r0, #0x00]
	movs r0, #0x18
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r3
	movs r3, #0x14
	ldsh r1, [r2, r3]
	lsls r1, r1, #0x05
	ldr r0, [r0, #0x00]
	adds r6, r0, r1
	ldrh r0, [r6, #0x0C]
	subs r0, #0x01
	b _0800B5A8
_0800B548: .4byte 0x0203489C
_0800B54C: .4byte 0x0812E744
_0800B550:
	movs r1, #0x16
	ldsh r0, [r3, r1]
	ldrh r6, [r6, #0x0C]
	cmp r0, r6
	blt _0800B5BC
	ldrh r0, [r3, #0x14]
	adds r0, #0x01
	strh r0, [r3, #0x14]
	movs r0, #0x14
	ldsh r2, [r3, r0]
	movs r0, #0x18
	ldsh r1, [r3, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	ldrh r0, [r0, #0x04]
	cmp r2, r0
	blt _0800B58A
	ldrh r0, [r3, #0x18]
	adds r0, #0x01
	strh r0, [r3, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bls _0800B586
	strh r4, [r3, #0x18]
_0800B586:
	ldr r0, [r7, #0x00]
	strh r4, [r0, #0x14]
_0800B58A:
	ldr r3, _0800B5B4 @ =0x0812E744
	ldr r0, _0800B5B8 @ =0x0203489C
	ldr r2, [r0, #0x00]
	movs r0, #0x18
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r3
	movs r3, #0x14
	ldsh r1, [r2, r3]
	lsls r1, r1, #0x05
	ldr r0, [r0, #0x00]
	adds r6, r0, r1
	movs r0, #0x00
_0800B5A8:
	strh r0, [r2, #0x16]
	adds r0, r6, #0x0
	bl func_0800B30C
	b _0800B5C8
	.byte 0x00, 0x00
_0800B5B4: .4byte 0x0812E744
_0800B5B8: .4byte 0x0203489C
_0800B5BC:
	adds r0, r3, #0x0
	adds r0, #0x24
	ldrh r1, [r3, #0x16]
	movs r2, #0x00
	bl func_080059A4
_0800B5C8:
	ldr r2, _0800B630 @ =0x0812E744
	ldr r0, _0800B634 @ =0x0203489C
	ldr r0, [r0, #0x00]
	movs r3, #0x18
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, #0x08
	adds r0, r0, r2
	ldr r3, [r0, #0x00]
	movs r0, #0xA6
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
_0800B5E8:
	bl func_08001384
	movs r1, #0x04
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0x00
	beq _0800B638
	bl func_08001384
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _0800B612
	ldr r0, _0800B634 @ =0x0203489C
	ldr r1, [r0, #0x00]
	adds r1, #0x42
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_0800B612:
	bl func_08001384
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800B6E0
	ldr r0, _0800B634 @ =0x0203489C
	ldr r1, [r0, #0x00]
	adds r1, #0x42
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _0800B6E0
	.byte 0x00, 0x00
_0800B630: .4byte 0x0812E744
_0800B634: .4byte 0x0203489C
_0800B638:
	bl func_0800139C
	movs r1, #0xC0
	lsls r1, r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _0800B6E0
	ldr r5, _0800B698 @ =0x0203489C
	ldr r0, [r5, #0x00]
	adds r2, r0, #0x0
	adds r2, #0x46
	movs r1, #0x00
	strh r4, [r2, #0x00]
	adds r0, #0x40
	strb r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	adds r0, #0x44
	strh r4, [r0, #0x00]
	bl func_0800139C
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _0800B672
	ldr r1, [r5, #0x00]
	ldrh r0, [r1, #0x18]
	subs r0, #0x01
	strh r0, [r1, #0x18]
_0800B672:
	bl func_0800139C
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800B688
	ldr r1, [r5, #0x00]
	ldrh r0, [r1, #0x18]
	adds r0, #0x01
	strh r0, [r1, #0x18]
_0800B688:
	ldr r1, [r5, #0x00]
	ldrh r0, [r1, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0800B69C
	movs r0, #0x09
	strh r0, [r1, #0x18]
	b _0800B6A4
_0800B698: .4byte 0x0203489C
_0800B69C:
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bls _0800B6A4
	strh r4, [r1, #0x18]
_0800B6A4:
	ldr r5, _0800B760 @ =0x0203489C
	ldr r0, [r5, #0x00]
	movs r1, #0x00
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x14]
	ldr r4, _0800B764 @ =0x0812E744
	movs r2, #0x18
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r6, [r0, #0x00]
	adds r0, r6, #0x0
	bl func_0800B30C
	ldr r0, [r5, #0x00]
	movs r3, #0x18
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r4, #0x08
	adds r0, r0, r4
	ldr r3, [r0, #0x00]
	movs r0, #0xA6
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
_0800B6E0:
	ldr r4, _0800B768 @ =0x08121400
	ldr r6, _0800B760 @ =0x0203489C
	ldr r0, [r6, #0x00]
	adds r2, r0, #0x0
	adds r2, #0x42
	movs r7, #0xFF
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	asrs r0, r0, #0x06
	cmp r0, #0x00
	bge _0800B702
	negs r0, r0
_0800B702:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrh r2, [r2, #0x00]
	lsrs r0, r2, #0x01
	ands r0, r7
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	asrs r0, r0, #0x06
	cmp r0, #0x00
	bge _0800B720
	negs r0, r0
_0800B720:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsrs r0, r2, #0x02
	ands r0, r7
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	asrs r0, r0, #0x06
	cmp r0, #0x00
	bge _0800B73C
	negs r0, r0
_0800B73C:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0x0
	adds r1, r3, #0x0
	bl func_08005778
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _0800B76C
	ldr r1, [r6, #0x00]
	adds r1, #0x46
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	b _0800B780
	.byte 0x00, 0x00
_0800B760: .4byte 0x0203489C
_0800B764: .4byte 0x0812E744
_0800B768: .4byte 0x08121400
_0800B76C:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _0800B782
	ldr r1, [r6, #0x00]
	adds r1, #0x46
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
_0800B780:
	strh r0, [r1, #0x00]
_0800B782:
	ldr r4, _0800B7D4 @ =0x0203489C
	ldr r0, [r4, #0x00]
	bl func_08000EA4
	ldr r0, [r4, #0x00]
	bl func_08000EE0
	ldr r0, [r4, #0x00]
	adds r0, #0x40
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800B7A6
	bl func_0800139C
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800B7AE
_0800B7A6:
	ldr r0, [r4, #0x00]
	adds r0, #0x24
	bl func_08005A64
_0800B7AE:
	ldr r4, _0800B7D4 @ =0x0203489C
	ldr r0, [r4, #0x00]
	adds r0, #0x24
	bl func_08005AFC
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x3C]
	adds r1, #0x40
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800B7DC
	ldr r3, _0800B7D8 @ =0x0812E884
	movs r0, #0x00
	movs r1, #0x01
	movs r2, #0x00
	bl func_0809D2B0
	b _0800B7E8
	.byte 0x00, 0x00
_0800B7D4: .4byte 0x0203489C
_0800B7D8: .4byte 0x0812E884
_0800B7DC:
	ldr r3, _0800B998 @ =0x0812E88C
	movs r0, #0x00
	movs r1, #0x01
	movs r2, #0x00
	bl func_0809D2B0
_0800B7E8:
	ldr r3, _0800B99C @ =0x0812E744
	ldr r7, _0800B9A0 @ =0x0203489C
	ldr r2, [r7, #0x00]
	movs r0, #0x18
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r3
	movs r3, #0x14
	ldsh r1, [r2, r3]
	lsls r1, r1, #0x05
	ldr r0, [r0, #0x00]
	adds r6, r0, r1
	ldr r4, _0800B9A4 @ =0x0812E894
	movs r0, #0x00
	movs r1, #0x0C
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x0D
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x0E
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x0F
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x11
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x12
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	movs r0, #0x00
	movs r1, #0x13
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D2B0
	ldr r3, _0800B9A8 @ =0x0812E8BC
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r7, #0x00]
	movs r1, #0x14
	ldsh r3, [r0, r1]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D458
	ldr r3, [r6, #0x14]
	movs r0, #0x00
	movs r1, #0x0C
	movs r2, #0x00
	bl func_0809D2B0
	ldr r3, _0800B9AC @ =0x0812E8C4
	movs r0, #0x00
	movs r1, #0x0D
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r7, #0x00]
	adds r0, #0x24
	bl func_08005B38
	adds r3, r0, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x06
	movs r1, #0x0D
	movs r2, #0x00
	bl func_0809D458
	ldr r3, [r6, #0x18]
	movs r0, #0x00
	movs r1, #0x0E
	movs r2, #0x00
	bl func_0809D2B0
	ldr r3, _0800B9B0 @ =0x0812E8C8
	movs r0, #0x00
	movs r1, #0x0F
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r7, #0x00]
	movs r2, #0x16
	ldsh r3, [r0, r2]
	movs r0, #0x06
	movs r1, #0x0F
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800B9B4 @ =0x0812E8D0
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r7, #0x00]
	ldrh r3, [r0, #0x32]
	movs r0, #0x06
	movs r1, #0x10
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800B9B8 @ =0x0812E8D4
	movs r0, #0x00
	movs r1, #0x11
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r7, #0x00]
	ldrh r3, [r0, #0x2E]
	movs r0, #0x06
	movs r1, #0x11
	movs r2, #0x00
	bl func_0809D458
	ldr r0, [r7, #0x00]
	ldr r0, [r0, #0x3C]
	bl func_08003598
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x15
	ldr r3, _0800B9BC @ =0x0812E8DC
	movs r0, #0x00
	movs r1, #0x12
	movs r2, #0x00
	bl func_0809D2B0
	adds r4, r5, #0x0
	movs r0, #0x06
	movs r1, #0x12
	movs r2, #0x00
	adds r3, r4, #0x0
	bl func_0809D458
	ldr r0, [r7, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x44
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, r4
	bge _0800B944
	strh r5, [r1, #0x00]
_0800B944:
	ldr r3, _0800B9C0 @ =0x0812E8E4
	movs r0, #0x00
	movs r1, #0x13
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r7, #0x00]
	adds r0, #0x44
	movs r1, #0x00
	ldsh r3, [r0, r1]
	movs r0, #0x06
	movs r1, #0x13
	movs r2, #0x00
	bl func_0809D458
	ldr r0, [r7, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x46
	ldrh r1, [r1, #0x00]
	adds r1, #0x60
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r0, #0x3C]
	ldr r3, [r0, #0x1C]
	ldr r0, [r0, #0x20]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	str r0, [sp, #0x00C]
	movs r0, #0x78
	bl func_080023E0
	movs r0, #0x01
	bl func_080605A4
	bl func_08060598
_0800B990:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800B998: .4byte 0x0812E88C
_0800B99C: .4byte 0x0812E744
_0800B9A0: .4byte 0x0203489C
_0800B9A4: .4byte 0x0812E894
_0800B9A8: .4byte 0x0812E8BC
_0800B9AC: .4byte 0x0812E8C4
_0800B9B0: .4byte 0x0812E8C8
_0800B9B4: .4byte 0x0812E8D0
_0800B9B8: .4byte 0x0812E8D4
_0800B9BC: .4byte 0x0812E8DC
_0800B9C0: .4byte 0x0812E8E4
.syntax divided
