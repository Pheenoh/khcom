.syntax unified
	.align 2, 0
	.global mode_ms_charge_1
	.thumb
	.thumb_func
	.type mode_ms_charge_1, %function
mode_ms_charge_1: @ 08106E30
	push {r4, r5, lr}
	bl func_0801CC80
	ldr r1, _08106E54 @ =0x02035CB8
	ldrb r0, [r1, #0x00]
	adds r0, #0x02
	strb r0, [r1, #0x00]
	ldr r4, _08106E58 @ =0x02035C14
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x01
	beq _08106E72
	cmp r0, #0x01
	bgt _08106E5C
	cmp r0, #0x00
	beq _08106E62
	b _08106EEC
	.byte 0x00, 0x00
_08106E54: .4byte 0x02035CB8
_08106E58: .4byte 0x02035C14
_08106E5C:
	cmp r0, #0x02
	beq _08106EC2
	b _08106EEC
_08106E62:
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08106EEC
	movs r0, #0x01
	strh r0, [r4, #0x00]
	b _08106EEC
_08106E72:
	ldr r0, _08106E88 @ =0x02035C16
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x04
	bhi _08106EEC
	lsls r0, r0, #0x02
	ldr r1, _08106E8C @ =0x08106E90
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_08106E88: .4byte 0x02035C16
_08106E8C: .4byte 0x08106E90
	.byte 0xA4, 0x6E, 0x10, 0x08, 0xAA, 0x6E, 0x10, 0x08, 0xB0, 0x6E, 0x10, 0x08, 0xB6, 0x6E, 0x10, 0x08
	.byte 0xBC, 0x6E, 0x10, 0x08, 0xFE, 0xF7, 0x52, 0xFD, 0x20, 0xE0, 0xFE, 0xF7, 0x95, 0xFE, 0x1D, 0xE0
	.byte 0xFE, 0xF7, 0x96, 0xFF, 0x1A, 0xE0, 0xFF, 0xF7, 0xB1, 0xF8, 0x17, 0xE0, 0xFF, 0xF7, 0x8E, 0xF9
	.byte 0x14, 0xE0
_08106EC2:
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08106EEC
	ldr r0, _08106EE0 @ =0x02035E20
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08106EE8
	ldr r0, _08106EE4 @ =0x09EF95E8
	movs r1, #0x02
	bl func_080010CC
	b _08106EEC
	.byte 0x00, 0x00
_08106EE0: .4byte 0x02035E20
_08106EE4: .4byte 0x09EF95E8
_08106EE8:
	bl func_080E04EC
_08106EEC:
	ldr r0, _08106F40 @ =0x02035CBC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _08106F4C
	ldr r4, _08106F44 @ =0x02035CA0
	adds r0, r4, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	beq _08106F22
	ldr r5, _08106F48 @ =0x02035CBA
	movs r2, #0x00
	ldsh r0, [r5, r2]
	cmp r0, #0x00
	bge _08106F18
	adds r0, r4, #0x0
	bl func_08005B30
	strh r0, [r5, #0x00]
_08106F18:
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_080059A4
_08106F22:
	ldr r1, _08106F40 @ =0x02035CBC
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _08106F7C
	ldr r5, _08106F44 @ =0x02035CA0
	adds r0, r5, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08106F48 @ =0x02035CBA
	b _08106F62
_08106F40: .4byte 0x02035CBC
_08106F44: .4byte 0x02035CA0
_08106F48: .4byte 0x02035CBA
_08106F4C:
	ldr r4, _08106F88 @ =0x02035CBA
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	blt _08106F7C
	ldr r5, _08106F8C @ =0x02035CA0
	adds r0, r5, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_08106F62:
	movs r2, #0x00
	ldsh r1, [r4, r2]
	cmp r0, r1
	beq _08106F74
	ldrh r1, [r4, #0x00]
	adds r0, r5, #0x0
	movs r2, #0x01
	bl func_080059A4
_08106F74:
	movs r1, #0x01
	negs r1, r1
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
_08106F7C:
	bl func_08106234
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08106F88: .4byte 0x02035CBA
_08106F8C: .4byte 0x02035CA0
.syntax divided
