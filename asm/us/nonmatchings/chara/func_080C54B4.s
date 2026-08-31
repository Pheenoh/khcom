.syntax unified
	.align 2, 0
	.global func_080C54B4
	.thumb
	.thumb_func
	.type func_080C54B4, %function
func_080C54B4: @ 080C54B4
	push {r4, r5, lr}
	ldr r5, _080C5554 @ =0x02039820
	ldr r0, _080C5558 @ =0x0203982C
	ldr r1, _080C555C @ =0x02039B68
	ldr r2, _080C5560 @ =0x020397E0
	bl func_08006ED4
	str r0, [r5, #0x00]
	ldr r1, _080C5564 @ =0x02039828
	movs r3, #0x03
	ands r3, r0
	str r3, [r1, #0x00]
	ldr r2, _080C5568 @ =0x020397FC
	movs r1, #0x1C
	ands r1, r0
	lsrs r1, r1, #0x02
	strb r1, [r2, #0x00]
	ldr r2, _080C556C @ =0x02039824
	movs r1, #0xE0
	lsls r1, r1, #0x04
	ands r1, r0
	lsrs r1, r1, #0x09
	strb r1, [r2, #0x00]
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080C558C
	cmp r3, #0x01
	bhi _080C558C
	bl func_080C5AA4
	ldr r0, [r5, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080C5506
	ldr r4, _080C5570 @ =0x02039B60
	bl func_080C5B50
	strb r0, [r4, #0x00]
_080C5506:
	ldr r0, [r5, #0x00]
	movs r1, #0xFE
	lsls r1, r1, #0x0F
	ands r0, r1
	ldr r4, _080C5570 @ =0x02039B60
	cmp r0, #0x00
	beq _080C5530
	ldr r0, _080C5574 @ =0x0203C3A8
	movs r2, #0x00
	ldsb r2, [r0, r2]
	cmp r2, #0x01
	bne _080C5530
	ldr r1, _080C5578 @ =0x020397D4
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xB4
	ble _080C5530
	strb r2, [r4, #0x00]
_080C5530:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x01
	bne _080C55C4
	ldr r2, _080C557C @ =0x03006C78
	ldrh r1, [r2, #0x00]
	ldr r0, _080C5580 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _080C5584 @ =0x020397F0
	ldr r0, _080C5554 @ =0x02039820
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, _080C5588 @ =0x09EF15B8
	movs r1, #0x00
	bl func_080010CC
	ldrb r0, [r4, #0x00]
	b _080C55C8
_080C5554: .4byte 0x02039820
_080C5558: .4byte 0x0203982C
_080C555C: .4byte 0x02039B68
_080C5560: .4byte 0x020397E0
_080C5564: .4byte 0x02039828
_080C5568: .4byte 0x020397FC
_080C556C: .4byte 0x02039824
_080C5570: .4byte 0x02039B60
_080C5574: .4byte 0x0203C3A8
_080C5578: .4byte 0x020397D4
_080C557C: .4byte 0x03006C78
_080C5580: .4byte 0x0000FFFE
_080C5584: .4byte 0x020397F0
_080C5588: .4byte 0x09EF15B8
_080C558C:
	bl GetKeysPressed
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080C559E
	ldr r1, _080C55D0 @ =0x0203BEA4
	movs r0, #0x0A
	strh r0, [r1, #0x00]
_080C559E:
	ldr r1, _080C55D0 @ =0x0203BEA4
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _080C55C4
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080C55C4
	bl func_080078A4
	ldr r0, _080C55D4 @ =0x0203BEAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C55C4
	bl _call_via_r0
_080C55C4:
	ldr r0, _080C55D8 @ =0x02039B60
	ldrb r0, [r0, #0x00]
_080C55C8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080C55D0: .4byte 0x0203BEA4
_080C55D4: .4byte 0x0203BEAC
_080C55D8: .4byte 0x02039B60
.syntax divided
