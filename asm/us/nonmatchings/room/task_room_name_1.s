.syntax unified
	.align 2, 0
	.global task_room_name_1
	.thumb
	.thumb_func
	.type task_room_name_1, %function
task_room_name_1: @ 080F7C8C
	adds r1, r0, #0x0
	ldr r0, _080F7CA4 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x70]
	movs r0, #0x84
	lsls r0, r0, #0x0B
	ands r2, r0
	cmp r2, #0x00
	beq _080F7CA8
	movs r0, #0x00
	b _080F7D40
	.byte 0x00, 0x00
_080F7CA4: .4byte 0x02039BA0
_080F7CA8:
	adds r3, r1, #0x0
	adds r3, #0x28
	ldrb r0, [r3, #0x00]
	cmp r0, #0x01
	beq _080F7CD6
	cmp r0, #0x01
	bgt _080F7CBC
	cmp r0, #0x00
	beq _080F7CC6
	b _080F7D3E
_080F7CBC:
	cmp r0, #0x02
	beq _080F7CFE
	cmp r0, #0x03
	beq _080F7D16
	b _080F7D3E
_080F7CC6:
	ldrh r0, [r1, #0x2A]
	adds r0, #0x01
	strh r0, [r1, #0x2A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _080F7D3E
	b _080F7D0C
_080F7CD6:
	ldrh r0, [r1, #0x2A]
	adds r0, #0x01
	strh r0, [r1, #0x2A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bls _080F7D3E
	strh r2, [r1, #0x2A]
	ldr r0, [r1, #0x10]
	subs r0, #0x99
	str r0, [r1, #0x10]
	ldr r0, [r1, #0x1C]
	adds r0, #0x19
	str r0, [r1, #0x1C]
	cmp r0, #0xFF
	ble _080F7D3E
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r1, #0x1C]
	b _080F7D0E
_080F7CFE:
	ldrh r0, [r1, #0x2A]
	adds r0, #0x01
	strh r0, [r1, #0x2A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xB3
	bls _080F7D3E
_080F7D0C:
	strh r2, [r1, #0x2A]
_080F7D0E:
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
	b _080F7D3E
_080F7D16:
	ldrh r0, [r1, #0x2A]
	adds r0, #0x01
	strh r0, [r1, #0x2A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bls _080F7D3E
	strh r2, [r1, #0x2A]
	ldr r0, [r1, #0x10]
	adds r0, #0x99
	str r0, [r1, #0x10]
	ldr r0, [r1, #0x1C]
	subs r0, #0x19
	str r0, [r1, #0x1C]
	cmp r0, #0x19
	bgt _080F7D3E
	movs r0, #0x19
	str r0, [r1, #0x1C]
	movs r0, #0x00
	b _080F7D40
_080F7D3E:
	movs r0, #0x01
_080F7D40:
	bx lr
	.byte 0x00, 0x00
.syntax divided
