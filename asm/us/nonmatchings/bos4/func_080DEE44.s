.syntax unified
	.align 2, 0
	.global func_080DEE44
	.thumb
	.thumb_func
	.type func_080DEE44, %function
func_080DEE44: @ 080DEE44
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	adds r1, r6, #0x0
	bl func_080DEE28
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xFF
	bne _080DEE60
	movs r0, #0x00
	b _080DEF14
_080DEE60:
	adds r0, r5, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _080DEE6E
	movs r0, #0x03
	b _080DEF14
_080DEE6E:
	adds r0, r5, #0x0
	bl func_080DEE18
	movs r4, #0x01
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080DEE82
	movs r4, #0x03
_080DEE82:
	movs r2, #0x08
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DEE92
	orrs r4, r2
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
_080DEE92:
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _080DEEA0
	orrs r4, r2
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
_080DEEA0:
	adds r0, r5, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080DEEB6
	cmp r0, #0x04
	beq _080DEEB6
	cmp r0, #0x02
	bne _080DEEE4
_080DEEB6:
	movs r0, #0x10
	orrs r4, r0
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x00
	bl func_080DEDD8
	adds r1, r0, #0x0
	b _080DEECA
_080DEEC8:
	adds r1, #0x08
_080DEECA:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x05
	beq _080DEEE4
	ldrb r0, [r1, #0x02]
	cmp r0, r5
	bne _080DEEC8
	ldrb r0, [r1, #0x03]
	cmp r0, r6
	beq _080DEEE4
	movs r0, #0x08
	orrs r4, r0
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
_080DEEE4:
	ldr r2, _080DEF1C @ =0x0203C590
	ldrh r1, [r2, #0x02]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DEF12
	ldrb r0, [r2, #0x05]
	bl func_080E54B8
	ldrb r0, [r0, #0x00]
	bl func_080DEDD8
	adds r1, r0, #0x0
	ldrb r0, [r1, #0x02]
	cmp r0, r5
	bne _080DEF12
	ldrb r0, [r1, #0x03]
	cmp r0, r6
	bne _080DEF12
	movs r0, #0x02
	orrs r4, r0
	lsls r0, r4, #0x10
	lsrs r4, r0, #0x10
_080DEF12:
	adds r0, r4, #0x0
_080DEF14:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080DEF1C: .4byte 0x0203C590
.syntax divided
