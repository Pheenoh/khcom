.syntax unified
	.align 2, 0
	.global mode_chkeff_1
	.thumb
	.thumb_func
	.type mode_chkeff_1, %function
mode_chkeff_1: @ 0800BC50
	push {r4, r5, r6, lr}
	add sp, #-0x004
	bl func_08001390
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _0800BC70
	ldr r0, _0800BC6C @ =0x09ECEB64
	movs r1, #0x00
	bl func_080010CC
	b _0800BF44
	.byte 0x00, 0x00
_0800BC6C: .4byte 0x09ECEB64
_0800BC70:
	bl func_08001390
	movs r1, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _0800BC8C
	ldr r0, _0800BD10 @ =0x020348B8
	ldr r1, [r0, #0x00]
	movs r2, #0x00
	ldrb r0, [r1, #0x16]
	cmp r0, #0x00
	bne _0800BC8A
	movs r2, #0x01
_0800BC8A:
	strb r2, [r1, #0x16]
_0800BC8C:
	ldr r4, _0800BD10 @ =0x020348B8
	ldr r0, [r4, #0x00]
	ldrh r5, [r0, #0x14]
	bl func_0800139C
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _0800BCA6
	ldr r1, [r4, #0x00]
	ldrh r0, [r1, #0x14]
	subs r0, #0x01
	strh r0, [r1, #0x14]
_0800BCA6:
	bl func_0800139C
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _0800BCBA
	ldr r1, [r4, #0x00]
	ldrh r0, [r1, #0x14]
	adds r0, #0x01
	strh r0, [r1, #0x14]
_0800BCBA:
	ldr r1, [r4, #0x00]
	movs r2, #0x14
	ldsh r0, [r1, r2]
	cmp r0, #0x00
	bge _0800BCC8
	movs r0, #0x52
	strh r0, [r1, #0x14]
_0800BCC8:
	ldr r1, [r4, #0x00]
	ldrh r0, [r1, #0x14]
	cmp r0, #0x52
	bls _0800BCD4
	movs r0, #0x00
	strh r0, [r1, #0x14]
_0800BCD4:
	ldr r1, _0800BD14 @ =0x09ED9A1C
	ldr r2, [r4, #0x00]
	movs r3, #0x14
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r6, [r0, #0x00]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x14
	ldsh r1, [r2, r3]
	cmp r0, r1
	beq _0800BCFC
	movs r0, #0x00
	strb r0, [r2, #0x16]
	adds r0, r6, #0x0
	movs r1, #0x78
	movs r2, #0x50
	bl func_08006778
_0800BCFC:
	bl func_0800139C
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _0800BD18
	ldr r1, [r4, #0x00]
	ldr r0, [r1, #0x20]
	adds r0, #0x08
	b _0800BD2A
_0800BD10: .4byte 0x020348B8
_0800BD14: .4byte 0x09ED9A1C
_0800BD18:
	bl func_0800139C
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _0800BD2C
	ldr r1, [r4, #0x00]
	ldr r0, [r1, #0x20]
	subs r0, #0x08
_0800BD2A:
	str r0, [r1, #0x20]
_0800BD2C:
	bl func_08001390
	movs r1, #0x04
	ands r1, r0
	cmp r1, #0x00
	beq _0800BD46
	ldr r0, _0800BDE0 @ =0x020348B8
	ldr r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r1, #0x20]
	movs r0, #0x00
	strb r0, [r1, #0x1C]
_0800BD46:
	bl func_0800139C
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _0800BD68
	ldr r0, _0800BDE0 @ =0x020348B8
	ldr r4, [r0, #0x00]
	ldrh r0, [r4, #0x24]
	adds r0, #0x01
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x24]
	movs r1, #0x11
	bl __umodsi3
	strh r0, [r4, #0x24]
_0800BD68:
	bl func_0800139C
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800BD8A
	ldr r0, _0800BDE0 @ =0x020348B8
	ldr r4, [r0, #0x00]
	ldrh r0, [r4, #0x26]
	adds r0, #0x01
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x26]
	movs r1, #0x11
	bl __umodsi3
	strh r0, [r4, #0x26]
_0800BD8A:
	ldr r2, _0800BDE0 @ =0x020348B8
	ldr r1, [r2, #0x00]
	ldr r0, [r1, #0x20]
	cmp r0, #0x09
	bgt _0800BD98
	movs r0, #0x0A
	str r0, [r1, #0x20]
_0800BD98:
	ldr r1, [r2, #0x00]
	ldr r0, [r1, #0x20]
	movs r2, #0xA0
	lsls r2, r2, #0x04
	cmp r0, r2
	ble _0800BDA6
	str r2, [r1, #0x20]
_0800BDA6:
	bl func_08006B74
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800BDC6
	bl func_08001384
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800BDC6
	adds r0, r6, #0x0
	movs r1, #0x78
	movs r2, #0x50
	bl func_08006778
_0800BDC6:
	ldr r0, _0800BDE0 @ =0x020348B8
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x16]
	cmp r0, #0x00
	beq _0800BDE8
	ldr r3, _0800BDE4 @ =0x081309E0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D2B0
	b _0800BDF4
	.byte 0x00, 0x00
_0800BDE0: .4byte 0x020348B8
_0800BDE4: .4byte 0x081309E0
_0800BDE8:
	ldr r3, _0800BF4C @ =0x081309E8
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_0809D2B0
_0800BDF4:
	ldr r5, _0800BF50 @ =0x020348B8
	ldr r4, _0800BF54 @ =0x081309F0
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
	mov r4, sp
	adds r4, #0x02
	mov r0, sp
	adds r1, r4, #0x0
	bl func_08006B80
	ldr r3, _0800BF58 @ =0x08130A18
	movs r0, #0x00
	movs r1, #0x0E
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r5, #0x00]
	ldrh r3, [r0, #0x24]
	movs r0, #0x06
	movs r1, #0x0E
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800BF5C @ =0x08130A20
	movs r0, #0x00
	movs r1, #0x0F
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r5, #0x00]
	ldrh r3, [r0, #0x26]
	movs r0, #0x06
	movs r1, #0x0F
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800BF60 @ =0x08130A28
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r5, #0x00]
	ldr r3, [r0, #0x20]
	movs r0, #0x06
	movs r1, #0x10
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800BF64 @ =0x08130A30
	movs r0, #0x00
	movs r1, #0x11
	movs r2, #0x00
	bl func_0809D2B0
	ldr r0, [r5, #0x00]
	movs r1, #0x14
	ldsh r3, [r0, r1]
	movs r0, #0x06
	movs r1, #0x11
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800BF68 @ =0x08130A34
	movs r0, #0x00
	movs r1, #0x12
	movs r2, #0x00
	bl func_0809D2B0
	mov r0, sp
	ldrh r3, [r0, #0x00]
	movs r0, #0x06
	movs r1, #0x12
	movs r2, #0x00
	bl func_0809D458
	ldr r3, _0800BF6C @ =0x08130A38
	movs r0, #0x00
	movs r1, #0x13
	movs r2, #0x00
	bl func_0809D2B0
	ldrh r3, [r4, #0x00]
	movs r0, #0x06
	movs r1, #0x13
	movs r2, #0x00
	bl func_0809D458
	ldr r0, [r5, #0x00]
	bl func_08000EA4
	ldr r0, [r5, #0x00]
	bl func_08000EE0
	ldr r1, [r5, #0x00]
	ldrb r0, [r1, #0x1C]
	ldr r2, [r1, #0x20]
	adds r1, r2, #0x0
	bl func_0800675C
	ldr r1, [r5, #0x00]
	ldrh r0, [r1, #0x24]
	ldrh r1, [r1, #0x26]
	bl func_08005810
	ldr r0, [r5, #0x00]
	ldrb r0, [r0, #0x16]
	cmp r0, #0x00
	beq _0800BF1E
	bl func_0800139C
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0800BF22
_0800BF1E:
	bl func_08006954
_0800BF22:
	ldr r4, _0800BF50 @ =0x020348B8
	ldr r0, [r4, #0x00]
	ldrh r1, [r0, #0x18]
	ldrh r2, [r0, #0x1A]
	movs r0, #0x01
	bl func_080054EC
	ldr r0, _0800BF70 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0800BF44
	ldr r1, [r4, #0x00]
	ldrh r0, [r1, #0x1A]
	subs r0, #0x01
	strh r0, [r1, #0x1A]
_0800BF44:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0800BF4C: .4byte 0x081309E8
_0800BF50: .4byte 0x020348B8
_0800BF54: .4byte 0x081309F0
_0800BF58: .4byte 0x08130A18
_0800BF5C: .4byte 0x08130A20
_0800BF60: .4byte 0x08130A28
_0800BF64: .4byte 0x08130A30
_0800BF68: .4byte 0x08130A34
_0800BF6C: .4byte 0x08130A38
_0800BF70: .4byte 0x03007480
.syntax divided
