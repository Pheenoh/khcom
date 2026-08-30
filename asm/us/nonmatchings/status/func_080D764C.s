.syntax unified
	.align 2, 0
	.global func_080D764C
	.thumb
	.thumb_func
	.type func_080D764C, %function
func_080D764C: @ 080D764C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	bl func_0800139C
	movs r1, #0x40
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r6, #0x00
	beq _080D76B4
	ldrh r0, [r5, #0x1A]
	movs r2, #0x1A
	ldsh r1, [r5, r2]
	cmp r1, #0x00
	ble _080D7670
	subs r0, #0x01
	strh r0, [r5, #0x1A]
	b _080D77D6
_080D7670:
	ldrh r2, [r5, #0x1C]
	movs r3, #0x1C
	ldsh r0, [r5, r3]
	cmp r0, #0x00
	ble _080D7684
	subs r0, r2, #0x1
	strh r0, [r5, #0x1C]
	bl func_080D83F4
	b _080D77D6
_080D7684:
	cmp r1, #0x00
	beq _080D768A
	b _080D783E
_080D768A:
	ldr r0, _080D76AC @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D7698
	b _080D783E
_080D7698:
	ldr r0, [r5, #0x14]
	mvns r0, r0
	movs r4, #0x00
	strh r0, [r5, #0x1A]
	movs r0, #0x79
	bl func_0811FE70
	ldr r0, _080D76B0 @ =0x02034F00
	strb r4, [r0, #0x00]
	b _080D783E
_080D76AC: .4byte 0x02039BB0
_080D76B0: .4byte 0x02034F00
_080D76B4:
	bl func_0800139C
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080D7716
	movs r0, #0x1A
	ldsh r4, [r5, r0]
	bl func_080D82D4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #0x01
	cmp r4, r0
	bge _080D76F8
	ldrh r1, [r5, #0x1A]
	movs r2, #0x1A
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	blt _080D76E2
	adds r0, r1, #0x1
	strh r0, [r5, #0x1A]
	b _080D77D6
_080D76E2:
	bl func_080D82D4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080D76F0
	strh r6, [r5, #0x1A]
	b _080D77D6
_080D76F0:
	movs r0, #0x69
	bl func_0811FE70
	b _080D783E
_080D76F8:
	movs r3, #0x1C
	ldsh r4, [r5, r3]
	bl func_080D8308
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, r0
	blt _080D770A
	b _080D783E
_080D770A:
	ldrh r0, [r5, #0x1C]
	adds r0, #0x01
	strh r0, [r5, #0x1C]
	bl func_080D8374
	b _080D77D6
_080D7716:
	bl func_0800139C
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080D7754
	ldr r0, _080D7750 @ =0x02039BB0
	ldr r4, [r0, #0x08]
	movs r0, #0x08
	ands r4, r0
	cmp r4, #0x00
	bne _080D7754
	ldr r0, [r5, #0x14]
	cmp r0, #0x00
	bne _080D7736
	b _080D783E
_080D7736:
	subs r0, #0x01
	str r0, [r5, #0x14]
	movs r1, #0x1A
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	blt _080D7788
	bl func_080D82D4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080D7788
	b _080D77A0
	.byte 0x00, 0x00
_080D7750: .4byte 0x02039BB0
_080D7754:
	bl func_0800139C
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080D77B2
	ldr r0, _080D7798 @ =0x02039BB0
	ldr r4, [r0, #0x08]
	movs r0, #0x08
	ands r4, r0
	cmp r4, #0x00
	bne _080D77B2
	ldr r0, [r5, #0x14]
	cmp r0, #0x02
	bhi _080D783E
	adds r0, #0x01
	str r0, [r5, #0x14]
	movs r2, #0x1A
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	blt _080D7788
	bl func_080D82D4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D77A0
_080D7788:
	ldr r0, [r5, #0x14]
	mvns r0, r0
	movs r1, #0x00
	strh r0, [r5, #0x1A]
	ldr r0, _080D779C @ =0x02034F00
	strb r1, [r0, #0x00]
	b _080D77A2
	.byte 0x00, 0x00
_080D7798: .4byte 0x02039BB0
_080D779C: .4byte 0x02034F00
_080D77A0:
	strh r4, [r5, #0x1A]
_080D77A2:
	movs r0, #0x00
	strh r0, [r5, #0x1C]
	bl func_080D8474
	movs r0, #0x65
	bl func_0811FE70
	b _080D783E
_080D77B2:
	bl func_08001390
	movs r1, #0x04
	ands r1, r0
	cmp r1, #0x00
	beq _080D77DE
	movs r3, #0x1A
	ldsh r0, [r5, r3]
	cmp r0, #0x00
	blt _080D783E
	ldr r0, [r5, #0x14]
	mvns r0, r0
	movs r1, #0x00
	strh r0, [r5, #0x1A]
	strh r1, [r5, #0x1C]
	movs r0, #0x00
	bl func_080D8474
_080D77D6:
	movs r0, #0x79
	bl func_0811FE70
	b _080D783E
_080D77DE:
	bl func_08001390
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _080D7814
	bl func_080D8340
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D7814
	ldr r1, _080D7810 @ =0x02034F00
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080D781C
	movs r2, #0x1A
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	blt _080D7814
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0x66
	bl func_0811FE70
	b _080D783E
_080D7810: .4byte 0x02034F00
_080D7814:
	ldr r0, _080D7844 @ =0x02034F00
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D783E
_080D781C:
	bl func_08001390
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	bne _080D7832
	bl func_080D8340
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D783E
_080D7832:
	ldr r1, _080D7844 @ =0x02034F00
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x68
	bl func_0811FE70
_080D783E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D7844: .4byte 0x02034F00
.syntax divided
