.syntax unified
	.align 2, 0
	.global func_08010CC8
	.thumb
	.thumb_func
	.type func_08010CC8, %function
func_08010CC8: @ 08010CC8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	ldr r0, _08010D04 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x7C]
	mov r10, r0
	ldr r0, _08010D08 @ =0x02039B9C
	ldr r2, [r0, #0x00]
	ldr r3, [r2, #0x7C]
	mov r9, r3
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x35
	beq _08010CF8
	adds r0, r2, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x35
	bne _08010D0C
_08010CF8:
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r1, r0
	movs r0, #0x26
	b _08010D14
	.byte 0x00, 0x00
_08010D04: .4byte 0x02039B84
_08010D08: .4byte 0x02039B9C
_08010D0C:
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r1, r1, r2
	movs r0, #0x42
_08010D14:
	str r0, [r1, #0x00]
	ldr r0, _08010D44 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _08010D50
	cmp r0, #0x01
	bcc _08010D50
	ldr r0, [r1, #0x68]
	ldr r1, [r1, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x05
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08010D48
	bl func_08010A24
	bl func_080107D4
	b _08010D50
_08010D44: .4byte 0x02039B84
_08010D48:
	bl func_080107D4
	bl func_08010A24
_08010D50:
	ldr r4, _08010DD4 @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0x40
	bl func_08000EA4
	ldr r6, [r4, #0x00]
	ldr r4, [r6, #0x68]
	ldr r5, [r6, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x10
	adds r0, r4, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08010E36
	ldr r0, _08010DD8 @ =0x00400000
	ldr r1, _08010DDC @ =0x00000000
	adds r2, r4, #0x0
	orrs r2, r0
	adds r3, r5, #0x0
	movs r4, #0x03
	negs r4, r4
	adds r0, r2, #0x0
	ands r0, r4
	adds r1, r3, #0x0
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	ldr r0, _08010DE0 @ =0x02039B9C
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6C]
	ands r0, r4
	str r0, [r2, #0x68]
	str r1, [r2, #0x6C]
	adds r1, r6, #0x0
	adds r1, #0xA0
	movs r0, #0x01
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08010DEC
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	movs r2, #0x41
	negs r2, r2
	ands r0, r2
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	mov r3, r9
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ldr r2, _08010DE4 @ =0x00010000
	ldr r3, _08010DE8 @ =0x00000000
	orrs r0, r2
	mov r2, r9
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0x02
	movs r1, #0x0A
	movs r2, #0x04
	bl func_08006290
	b _08010E14
_08010DD4: .4byte 0x02039B84
_08010DD8: .4byte 0x00400000
_08010DDC: .4byte 0x00000000
_08010DE0: .4byte 0x02039B9C
_08010DE4: .4byte 0x00010000
_08010DE8: .4byte 0x00000000
_08010DEC:
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _08010E90 @ =0xDFFFFFFF
	ands r0, r2
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	mov r3, r10
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ldr r2, _08010E94 @ =0x00010000
	ldr r3, _08010E98 @ =0x00000000
	orrs r0, r2
	mov r2, r10
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0x03
	movs r1, #0x0A
	movs r2, #0x04
	bl func_08006290
_08010E14:
	movs r0, #0x10
	movs r1, #0x0F
	bl func_08006494
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldr r4, _08010E9C @ =0x02039B84
	ldr r0, [r4, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	movs r0, #0x01
	bl func_08019050
	ldr r0, [r4, #0x00]
	adds r0, #0xE4
	movs r1, #0x00
	strh r1, [r0, #0x00]
_08010E36:
	ldr r3, _08010E9C @ =0x02039B84
	ldr r0, [r3, #0x00]
	mov r12, r0
	ldr r6, [r0, #0x68]
	ldr r7, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x03
	adds r0, r6, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08010EE8
	movs r1, #0x01
	str r1, [sp, #0x000]
	ldr r0, _08010EA0 @ =0xFFFFFBFF
	adds r4, r6, #0x0
	ands r4, r0
	adds r5, r7, #0x0
	mov r2, r12
	str r4, [r2, #0x68]
	str r5, [r2, #0x6C]
	mov r0, r12
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08010EAC
	ldr r2, _08010EA4 @ =0x20000000
	ldr r3, _08010EA8 @ =0x00000000
	adds r0, r4, #0x0
	orrs r0, r2
	adds r1, r5, #0x0
	mov r3, r12
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	mov r2, r10
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x01
	movs r3, #0x00
	orrs r0, r2
	mov r3, r10
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	b _08010ECE
_08010E90: .4byte 0xDFFFFFFF
_08010E94: .4byte 0x00010000
_08010E98: .4byte 0x00000000
_08010E9C: .4byte 0x02039B84
_08010EA0: .4byte 0xFFFFFBFF
_08010EA4: .4byte 0x20000000
_08010EA8: .4byte 0x00000000
_08010EAC:
	movs r2, #0x40
	movs r3, #0x00
	adds r0, r4, #0x0
	orrs r0, r2
	adds r1, r5, #0x0
	mov r2, r12
	str r0, [r2, #0x68]
	str r1, [r2, #0x6C]
	mov r3, r9
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x01
	movs r3, #0x00
	orrs r0, r2
	mov r2, r9
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
_08010ECE:
	ldr r3, _08010EE4 @ =0x02039B84
	ldr r1, [r3, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xA0
	movs r0, #0x02
	str r0, [r2, #0x00]
	adds r1, #0xE4
	movs r0, #0x00
	strh r0, [r1, #0x00]
	b _08010EEC
	.byte 0x00, 0x00
_08010EE4: .4byte 0x02039B84
_08010EE8:
	movs r0, #0x00
	str r0, [sp, #0x000]
_08010EEC:
	ldr r1, _08010F3C @ =0x02039B84
	ldr r3, [r1, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _08010F16
	adds r1, r3, #0x0
	adds r1, #0xA0
	ldr r0, [r1, #0x00]
	cmp r0, #0x04
	beq _08010F16
	movs r0, #0x04
	str r0, [r1, #0x00]
	adds r1, #0x44
	movs r0, #0x00
	strh r0, [r1, #0x00]
_08010F16:
	ldr r2, _08010F3C @ =0x02039B84
	mov r8, r2
	ldr r2, [r2, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA0
	ldr r6, [r0, #0x00]
	cmp r6, #0x01
	bne _08010F28
	b _08011260
_08010F28:
	cmp r6, #0x01
	bcc _08010F40
	cmp r6, #0x02
	bne _08010F32
	b _0801116C
_08010F32:
	cmp r6, #0x04
	bne _08010F38
	b _08011076
_08010F38:
	b _08011260
	.byte 0x00, 0x00
_08010F3C: .4byte 0x02039B84
_08010F40:
	adds r3, r2, #0x0
	adds r3, #0xE4
	movs r0, #0x00
	ldsh r1, [r3, r0]
	cmp r1, #0x00
	bne _08010F56
	adds r0, r2, #0x0
	adds r0, #0xE8
	str r1, [r0, #0x00]
	movs r0, #0x01
	strh r0, [r3, #0x00]
_08010F56:
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08010F62
	b _08011260
_08010F62:
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, #0xE4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x01
	bne _08010F9C
	movs r4, #0x00
_08010F72:
	ldr r5, _08011010 @ =0x02039B84
	ldr r0, [r5, #0x00]
	adds r0, #0xFC
	movs r1, #0x01
	lsls r1, r4
	ldr r0, [r0, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08010F8E
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_08010F8E:
	adds r4, #0x01
	cmp r4, #0x1F
	ble _08010F72
	ldr r0, [r5, #0x00]
	adds r0, #0xE4
	movs r1, #0x02
	strh r1, [r0, #0x00]
_08010F9C:
	ldr r5, _08011010 @ =0x02039B84
	ldr r0, [r5, #0x00]
	adds r0, #0xE8
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	beq _08010FB2
	b _08011260
_08010FB2:
	ldr r0, [r5, #0x00]
	adds r3, r0, #0x0
	adds r3, #0xE4
	movs r1, #0x00
	ldsh r2, [r3, r1]
	cmp r2, #0x02
	bne _08011064
	adds r0, #0x2C
	ldr r1, _08011014 @ =0x09EDE488
	movs r2, #0x00
	bl func_08000E14
	ldr r0, [r5, #0x00]
	adds r0, #0x40
	ldr r1, _08011018 @ =0x09EDAEA0
	movs r2, #0x00
	bl func_08000E14
	ldr r0, [r5, #0x00]
	adds r0, #0x40
	ldr r1, _0801101C @ =0x09EDE4A0
	movs r2, #0x00
	bl func_08000E14
	ldr r3, [r5, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x05
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08011028
	adds r0, r3, #0x0
	adds r0, #0x40
	ldr r1, _08011020 @ =0x09EE4954
	movs r2, #0x00
	bl func_08000E14
	ldr r0, [r5, #0x00]
	adds r0, #0x40
	ldr r1, _08011024 @ =0x09EE49B4
	movs r2, #0x00
	bl func_08000E14
	b _08011042
_08011010: .4byte 0x02039B84
_08011014: .4byte 0x09EDE488
_08011018: .4byte 0x09EDAEA0
_0801101C: .4byte 0x09EDE4A0
_08011020: .4byte 0x09EE4954
_08011024: .4byte 0x09EE49B4
_08011028:
	adds r0, r3, #0x0
	adds r0, #0x40
	ldr r1, _08011058 @ =0x09EE49B4
	movs r2, #0x00
	bl func_08000E14
	ldr r2, _0801105C @ =0x02039B84
	ldr r0, [r2, #0x00]
	adds r0, #0x40
	ldr r1, _08011060 @ =0x09EE4954
	movs r2, #0x00
	bl func_08000E14
_08011042:
	bl func_08076360
	bl func_080838E8
	ldr r0, _0801105C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xE4
	movs r1, #0x03
	strh r1, [r0, #0x00]
	b _08011260
	.byte 0x00, 0x00
_08011058: .4byte 0x09EE49B4
_0801105C: .4byte 0x02039B84
_08011060: .4byte 0x09EE4954
_08011064:
	cmp r2, #0x03
	beq _0801106A
	b _08011260
_0801106A:
	adds r1, r0, #0x0
	adds r1, #0xA0
	movs r0, #0x01
	str r0, [r1, #0x00]
	strh r4, [r3, #0x00]
	b _08011260
_08011076:
	adds r0, r2, #0x0
	adds r0, #0xE4
	movs r3, #0x00
	ldsh r7, [r0, r3]
	cmp r7, #0x00
	bne _080110D4
	bl func_08076374
	bl func_080838EC
	mov r0, r8
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	movs r2, #0x20
	movs r3, #0x00
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r6, _08011108 @ =0x02039B9C
	ldr r5, [r6, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	ldr r2, _0801110C @ =0x40000000
	ldr r3, _08011110 @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldr r2, [r4, #0x10]
	ldr r3, [r4, #0x14]
	movs r0, #0x08
	bl func_08019050
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, #0xF4
	str r7, [r0, #0x00]
	ldr r0, [r6, #0x00]
	adds r0, #0xF4
	str r7, [r0, #0x00]
_080110D4:
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r0, #0xE4
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x8C
	bne _0801111C
	movs r0, #0x01
	movs r1, #0x64
	bl func_08006184
	bl func_080063A8
	mov r0, r8
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08011114 @ =0x00400000
	ldr r3, _08011118 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	adds r4, #0x72
	movs r0, #0x64
	strh r0, [r4, #0x00]
	b _08011158
_08011108: .4byte 0x02039B9C
_0801110C: .4byte 0x40000000
_08011110: .4byte 0x00000000
_08011114: .4byte 0x00400000
_08011118: .4byte 0x00000000
_0801111C:
	cmp r0, #0x8C
	ble _08011158
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08011158
	bl func_0811FFA4
	mov r1, r10
	movs r2, #0x2C
	ldsh r0, [r1, r2]
	cmp r0, #0x00
	bgt _08011148
	ldr r0, _08011144 @ =0x09EF14EC
	movs r1, #0x01
	bl func_080010CC
	b _08011260
	.byte 0x00, 0x00
_08011144: .4byte 0x09EF14EC
_08011148:
	ldr r0, _08011154 @ =0x09EF14EC
	movs r1, #0x00
	bl func_080010CC
	b _08011260
	.byte 0x00, 0x00
_08011154: .4byte 0x09EF14EC
_08011158:
	ldr r0, _08011168 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xE4
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _08011260
	.byte 0x00, 0x00
_08011168: .4byte 0x02039B84
_0801116C:
	ldr r3, [sp, #0x000]
	cmp r3, #0x00
	beq _08011174
	b _08011260
_08011174:
	mov r2, r10
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x10
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r4, r0, #0x1F
	mov r3, r9
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801119A
	movs r4, #0x01
_0801119A:
	cmp r4, #0x00
	bne _08011260
	bl func_080ABED0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, r8
	ldr r5, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xE4
	strh r4, [r0, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x16
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08011212
	adds r0, r5, #0x0
	adds r0, #0xB2
	movs r1, #0x00
	ldsb r1, [r0, r1]
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _080111E2
	movs r2, #0x03
	negs r2, r2
	adds r0, r3, #0x0
	ands r0, r2
	adds r1, r4, #0x0
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
_080111E2:
	ldr r1, _08011208 @ =0x02039B84
	ldr r0, [r1, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	ands r0, r6
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801120C
	mov r2, r10
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x01
	movs r3, #0x00
	orrs r0, r2
	mov r3, r10
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	b _08011260
_08011208: .4byte 0x02039B84
_0801120C:
	bl func_08010C70
	b _08011260
_08011212:
	ldr r4, _08011258 @ =0x02039B9C
	ldr r3, [r4, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xB2
	movs r1, #0x00
	ldsb r1, [r0, r1]
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _08011234
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x03
	negs r2, r2
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
_08011234:
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	ands r0, r6
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801125C
	mov r2, r9
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x01
	movs r3, #0x00
	orrs r0, r2
	mov r3, r9
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	b _08011260
_08011258: .4byte 0x02039B9C
_0801125C:
	bl func_08010C70
_08011260:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
