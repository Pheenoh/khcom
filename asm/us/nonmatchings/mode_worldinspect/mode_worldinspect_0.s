.syntax unified
	.align 2, 0
	.global mode_worldinspect_0
	.thumb
	.thumb_func
	.type mode_worldinspect_0, %function
mode_worldinspect_0: @ 080FFC0C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	ldr r4, _080FFE10 @ =0x020354D4
	movs r0, #0xA0
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r4, #0x00]
	bl func_08001F98
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1C
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	movs r0, #0x01
	movs r1, #0x02
	bl func_080055C8
	movs r0, #0x02
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x03
	movs r1, #0x00
	bl func_080055C8
	ldr r3, _080FFE14 @ =0x02039BB0
	movs r2, #0x0E
	ldsb r2, [r3, r2]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x010]
	ldr r4, _080FFE18 @ =0x020350F8
	movs r0, #0x0E
	ldsb r0, [r3, r0]
	movs r1, #0x0B
	cmp r0, #0x0B
	bgt _080FFC9E
	adds r1, r2, #0x0
_080FFC9E:
	strh r1, [r4, #0x00]
	ldr r1, _080FFE1C @ =0x020350FA
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r6, #0x00
	mov r12, r4
	mov r9, r1
	ldr r0, _080FFE20 @ =0x09EF8FAC
	mov r10, r0
	ldr r7, _080FFE24 @ =0x02035100
	adds r5, r3, #0x0
	mov r4, r9
	movs r3, #0xC3
	lsls r3, r3, #0x01
_080FFCBA:
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r7
	lsls r0, r2, #0x02
	adds r0, r0, r5
	adds r0, r0, r3
	ldrb r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080FFCD4
	adds r0, r2, #0x1
	strh r0, [r4, #0x00]
_080FFCD4:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0B
	ble _080FFCBA
	movs r6, #0x00
	mov r1, r9
	ldrh r5, [r1, #0x00]
	ldr r2, _080FFE28 @ =0x02039D30
	mov r9, r2
	ldr r3, _080FFE2C @ =0x09EF909C
	mov r8, r3
	ldr r7, _080FFE24 @ =0x02035100
_080FFCF0:
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	movs r0, #0x34
	muls r0, r4
	mov r6, r8
	adds r3, r0, r6
	mov r0, r9
	ldrh r1, [r0, #0x00]
	ldrh r0, [r3, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _080FFD24
	adds r0, r5, #0x0
	lsls r2, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r2, r2, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x0F
	adds r0, r0, r7
	ldrh r1, [r3, #0x02]
	strh r1, [r0, #0x00]
	lsrs r5, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x0B
	bgt _080FFD30
_080FFD24:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0D
	ble _080FFCF0
_080FFD30:
	movs r2, #0x00
	ldr r3, _080FFE30 @ =0x02035118
	strh r2, [r3, #0x00]
	ldr r5, _080FFE34 @ =0x0203511A
	strb r2, [r5, #0x00]
	mov r6, r12
	movs r0, #0x00
	ldsh r1, [r6, r0]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	add r0, r10
	movs r1, #0x08
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x0B
	movs r3, #0x80
	lsls r3, r3, #0x06
	adds r0, r0, r3
	ldr r5, _080FFE38 @ =0x020354D8
	str r0, [r5, #0x00]
	movs r0, #0x00
	ldsh r1, [r6, r0]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	add r0, r10
	movs r1, #0x0A
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x0B
	ldr r3, _080FFE3C @ =0xFFFFFA00
	adds r0, r0, r3
	ldr r5, _080FFE40 @ =0x020354DC
	str r0, [r5, #0x00]
	ldr r6, _080FFE44 @ =0x020354C0
	strh r2, [r6, #0x00]
	movs r0, #0x10
	ldr r1, _080FFE48 @ =0x020354C2
	strh r0, [r1, #0x00]
	ldr r0, _080FFE4C @ =0xFFFFF800
	ldr r2, _080FFE50 @ =0x020354C8
	str r0, [r2, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x08
	str r0, [r2, #0x04]
	ldr r0, _080FFE54 @ =0xFFFF8000
	ldr r3, _080FFE58 @ =0x020354D0
	str r0, [r3, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x00
	ldr r1, _080FFE5C @ =0x09A3CE7C
	bl func_080050DC
	movs r6, #0x00
	ldr r7, _080FFE2C @ =0x09EF909C
	movs r5, #0x34
	mov r8, r5
	movs r0, #0x14
	adds r0, r0, r7
	mov r10, r0
	ldr r1, _080FFE60 @ =0x02035168
	mov r9, r1
_080FFDAC:
	ldr r0, _080FFE24 @ =0x02035100
	lsls r1, r6, #0x10
	asrs r4, r1, #0x10
	lsls r1, r4, #0x01
	adds r5, r1, r0
	movs r3, #0x00
	ldsh r2, [r5, r3]
	cmp r2, #0x00
	beq _080FFE6C
	adds r0, r2, #0x0
	mov r1, r8
	muls r1, r0
	adds r0, r7, #0x4
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	adds r1, r1, r7
	ldrh r1, [r1, #0x08]
	bl func_08002A14
	lsls r4, r4, #0x02
	mov r2, r9
	adds r1, r4, r2
	str r0, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r5, r3]
	mov r1, r8
	muls r1, r0
	adds r0, r7, #0x0
	adds r0, #0x0C
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	adds r1, r1, r7
	ldrh r1, [r1, #0x10]
	bl func_080026A4
	ldr r1, _080FFE64 @ =0x02035198
	adds r1, r4, r1
	str r0, [r1, #0x00]
	ldr r0, _080FFE68 @ =0x020351C8
	adds r4, r4, r0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	mov r2, r8
	muls r2, r0
	adds r0, r2, #0x0
	add r0, r10
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	b _080FFE80
	.byte 0x00, 0x00
_080FFE10: .4byte 0x020354D4
_080FFE14: .4byte 0x02039BB0
_080FFE18: .4byte 0x020350F8
_080FFE1C: .4byte 0x020350FA
_080FFE20: .4byte 0x09EF8FAC
_080FFE24: .4byte 0x02035100
_080FFE28: .4byte 0x02039D30
_080FFE2C: .4byte 0x09EF909C
_080FFE30: .4byte 0x02035118
_080FFE34: .4byte 0x0203511A
_080FFE38: .4byte 0x020354D8
_080FFE3C: .4byte 0xFFFFFA00
_080FFE40: .4byte 0x020354DC
_080FFE44: .4byte 0x020354C0
_080FFE48: .4byte 0x020354C2
_080FFE4C: .4byte 0xFFFFF800
_080FFE50: .4byte 0x020354C8
_080FFE54: .4byte 0xFFFF8000
_080FFE58: .4byte 0x020354D0
_080FFE5C: .4byte 0x09A3CE7C
_080FFE60: .4byte 0x02035168
_080FFE64: .4byte 0x02035198
_080FFE68: .4byte 0x020351C8
_080FFE6C:
	lsls r1, r4, #0x02
	mov r3, r9
	adds r0, r1, r3
	str r2, [r0, #0x00]
	ldr r0, _080FFFF4 @ =0x02035198
	adds r0, r1, r0
	str r2, [r0, #0x00]
	ldr r0, _080FFFF8 @ =0x020351C8
	adds r1, r1, r0
	str r2, [r1, #0x00]
_080FFE80:
	lsls r0, r6, #0x10
	movs r5, #0x80
	lsls r5, r5, #0x09
	adds r0, r0, r5
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0B
	ble _080FFDAC
	ldr r1, _080FFFFC @ =0x099FB53C
	ldr r2, _08100000 @ =0x00006BC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _08100004 @ =0x09A324DC
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl func_0800510C
	ldr r1, _08100008 @ =0x040000D4
	ldr r0, _0810000C @ =0x09A32EDC
	str r0, [r1, #0x00]
	ldr r0, _08100010 @ =0x020354D4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x04]
	ldr r0, _08100014 @ =0x80000280
	str r0, [r1, #0x08]
	ldr r0, [r1, #0x08]
	movs r6, #0x00
	ldr r7, _08100018 @ =0x02035100
	ldr r5, _0810001C @ =0x09EF8FAC
_080FFEBE:
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x01
	adds r0, r0, r7
	movs r6, #0x00
	ldsh r0, [r0, r6]
	cmp r0, #0x00
	beq _080FFEF8
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r0, _08100010 @ =0x020354D4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x02
	adds r0, r0, r5
	movs r2, #0x08
	ldsh r1, [r0, r2]
	str r1, [sp, #0x008]
	movs r3, #0x0A
	ldsh r0, [r0, r3]
	str r0, [sp, #0x00C]
	movs r0, #0x07
	movs r1, #0x04
	ldr r2, _08100020 @ =0x09A333DC
	movs r3, #0x00
	bl func_080FF19C
_080FFEF8:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0B
	ble _080FFEBE
	movs r6, #0x00
	ldr r1, _08100024 @ =0x020350FA
	movs r5, #0x00
	ldsh r0, [r1, r5]
	subs r0, #0x01
	mov r9, r1
	cmp r6, r0
	bge _080FFF8C
	ldr r7, _08100018 @ =0x02035100
	ldr r0, _08100028 @ =0x099930BC
	mov r8, r0
_080FFF1A:
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r7
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r5, r0, #0x0
	cmp r1, #0x00
	beq _080FFF76
	adds r0, r2, #0x1
	lsls r0, r0, #0x01
	adds r0, r0, r7
	movs r6, #0x00
	ldsh r0, [r0, r6]
	cmp r0, #0x00
	beq _080FFF76
	ldr r0, _0810001C @ =0x09EF8FAC
	lsls r4, r2, #0x02
	adds r4, r4, r2
	lsls r4, r4, #0x02
	adds r4, r4, r0
	movs r0, #0x0C
	ldsh r2, [r4, r0]
	lsls r2, r2, #0x03
	add r2, r8
	movs r1, #0x00
	ldsh r0, [r2, r1]
	movs r3, #0x02
	ldsh r1, [r2, r3]
	movs r6, #0x04
	ldsh r3, [r2, r6]
	movs r6, #0x06
	ldsh r2, [r2, r6]
	str r2, [sp, #0x000]
	ldr r2, _08100010 @ =0x020354D4
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x004]
	movs r6, #0x0E
	ldsh r2, [r4, r6]
	str r2, [sp, #0x008]
	movs r6, #0x10
	ldsh r2, [r4, r6]
	str r2, [sp, #0x00C]
	ldr r2, _08100020 @ =0x09A333DC
	bl func_080FF19C
_080FFF76:
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r1, r5, r0
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _08100024 @ =0x020350FA
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x01
	cmp r1, r0
	blt _080FFF1A
_080FFF8C:
	movs r6, #0x00
	mov r3, r9
	movs r5, #0x00
	ldsh r0, [r3, r5]
	cmp r6, r0
	blt _080FFF9A
	b _081000CE
_080FFF9A:
	ldr r7, _08100010 @ =0x020354D4
	ldr r4, _0810001C @ =0x09EF8FAC
_080FFF9E:
	ldr r0, _08100018 @ =0x02035100
	lsls r1, r6, #0x10
	asrs r2, r1, #0x10
	lsls r3, r2, #0x01
	adds r0, r3, r0
	movs r6, #0x00
	ldsh r0, [r0, r6]
	adds r5, r1, #0x0
	cmp r0, #0x00
	bne _080FFFB4
	b _081000B8
_080FFFB4:
	ldr r0, _0810002C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _08100044
	cmp r2, #0x08
	bgt _08100030
	adds r3, r3, r2
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x09
	str r0, [sp, #0x000]
	ldr r0, [r7, #0x00]
	str r0, [sp, #0x004]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r4
	ldrh r0, [r1, #0x08]
	adds r0, #0x03
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldrh r0, [r1, #0x0A]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x03
	b _08100072
	.byte 0x00, 0x00
_080FFFF4: .4byte 0x02035198
_080FFFF8: .4byte 0x020351C8
_080FFFFC: .4byte 0x099FB53C
_08100000: .4byte 0x00006BC0
_08100004: .4byte 0x09A324DC
_08100008: .4byte 0x040000D4
_0810000C: .4byte 0x09A32EDC
_08100010: .4byte 0x020354D4
_08100014: .4byte 0x80000280
_08100018: .4byte 0x02035100
_0810001C: .4byte 0x09EF8FAC
_08100020: .4byte 0x09A333DC
_08100024: .4byte 0x020350FA
_08100028: .4byte 0x099930BC
_0810002C: .4byte 0x02039BB0
_08100030:
	adds r3, r2, #0x0
	subs r3, #0x09
	lsls r3, r3, #0x12
	asrs r3, r3, #0x10
	movs r0, #0x0A
	str r0, [sp, #0x000]
	ldr r0, [r7, #0x00]
	str r0, [sp, #0x004]
	lsls r1, r2, #0x02
	b _08100056
_08100044:
	cmp r2, #0x02
	bgt _08100080
	lsls r1, r2, #0x02
	lsls r3, r2, #0x12
	asrs r3, r3, #0x10
	movs r0, #0x15
	str r0, [sp, #0x000]
	ldr r0, [r7, #0x00]
	str r0, [sp, #0x004]
_08100056:
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r4
	ldrh r0, [r1, #0x08]
	adds r0, #0x03
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldrh r0, [r1, #0x0A]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x04
_08100072:
	movs r1, #0x01
	ldr r2, _0810007C @ =0x09A333DC
	bl func_080FF19C
	b _081000B8
_0810007C: .4byte 0x09A333DC
_08100080:
	subs r0, r2, #0x3
	lsls r3, r0, #0x01
	adds r3, r3, r0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x16
	str r0, [sp, #0x000]
	ldr r0, [r7, #0x00]
	str r0, [sp, #0x004]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r1, r1, r4
	ldrh r0, [r1, #0x08]
	adds r0, #0x03
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	ldrh r0, [r1, #0x0A]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x03
	movs r1, #0x01
	ldr r2, _08100114 @ =0x09A333DC
	bl func_080FF19C
_081000B8:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r5, r1
	ldr r1, _08100118 @ =0x020350FA
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x00
	ldsh r1, [r1, r2]
	cmp r0, r1
	bge _081000CE
	b _080FFF9E
_081000CE:
	movs r6, #0x00
	mov r3, r9
	movs r5, #0x00
	ldsh r0, [r3, r5]
	cmp r6, r0
	bge _08100158
	ldr r1, [sp, #0x010]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	ldr r7, _0810011C @ =0x09EF8FAC
	ldr r4, _08100120 @ =0x020354D4
_081000E6:
	lsls r0, r6, #0x10
	asrs r1, r0, #0x10
	adds r5, r0, #0x0
	cmp r8, r1
	bne _08100124
	ldr r3, [r4, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r7
	movs r2, #0x08
	ldsh r1, [r0, r2]
	str r1, [sp, #0x000]
	movs r6, #0x0A
	ldsh r0, [r0, r6]
	str r0, [sp, #0x004]
	movs r0, #0x03
	movs r1, #0x07
	movs r2, #0x04
	bl func_080FF10C
	b _08100144
	.byte 0x00, 0x00
_08100114: .4byte 0x09A333DC
_08100118: .4byte 0x020350FA
_0810011C: .4byte 0x09EF8FAC
_08100120: .4byte 0x020354D4
_08100124:
	ldr r3, [r4, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r7
	movs r2, #0x08
	ldsh r1, [r0, r2]
	str r1, [sp, #0x000]
	movs r6, #0x0A
	ldsh r0, [r0, r6]
	str r0, [sp, #0x004]
	movs r0, #0x02
	movs r1, #0x07
	movs r2, #0x04
	bl func_080FF10C
_08100144:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r5, r1
	ldr r1, _0810024C @ =0x020350FA
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x00
	ldsh r1, [r1, r2]
	cmp r0, r1
	blt _081000E6
_08100158:
	ldr r0, _08100250 @ =0x020354D4
	ldr r1, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x03
	movs r0, #0x01
	adds r2, r4, #0x0
	bl func_0800510C
	ldr r1, _08100254 @ =0x09A33E9C
	movs r0, #0x02
	adds r2, r4, #0x0
	bl func_0800510C
	ldr r1, _08100258 @ =0x09A3399C
	movs r0, #0x03
	adds r2, r4, #0x0
	bl func_0800510C
	ldr r5, _0810025C @ =0x020350F8
	movs r3, #0x00
	ldsh r0, [r5, r3]
	bl func_080FF2B8
	ldr r0, _08100260 @ =0x09A3D09C
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08100264 @ =0x02035124
	str r0, [r1, #0x00]
	ldr r0, _08100268 @ =0x0999D41A
	movs r6, #0x80
	lsls r6, r6, #0x03
	adds r1, r6, #0x0
	bl func_080026A4
	ldr r1, _0810026C @ =0x02035128
	str r0, [r1, #0x00]
	ldr r4, _08100270 @ =0x02035130
	ldr r1, _08100274 @ =0x09EF97C4
	ldr r2, _08100278 @ =0x09EF97B0
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _0810027C @ =0x09A3D0BC
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08100280 @ =0x02035148
	str r0, [r1, #0x00]
	ldr r0, _08100284 @ =0x0999D8A8
	movs r1, #0xC0
	bl func_080026A4
	ldr r1, _08100288 @ =0x0203514C
	str r0, [r1, #0x00]
	ldr r4, _0810028C @ =0x02035150
	ldr r1, _08100290 @ =0x09EF97DC
	ldr r2, _08100294 @ =0x09EF97CC
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _08100298 @ =0x020351F8
	movs r1, #0x18
	bl func_08065ACC
	ldr r1, _0810029C @ =0x02035100
	movs r2, #0x00
	ldsh r0, [r5, r2]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	bl func_080FF228
	ldr r1, _081002A0 @ =0x020352B8
	strb r0, [r1, #0x00]
	ldr r0, _081002A4 @ =0x020352C0
	movs r1, #0x3C
	bl func_08065ACC
	ldr r0, _081002A8 @ =0x09A3D07C
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _081002AC @ =0x0203511C
	str r0, [r1, #0x00]
	ldr r0, _081002B0 @ =0x0999CFC6
	adds r1, r6, #0x0
	bl func_080026A4
	ldr r1, _081002B4 @ =0x02035120
	str r0, [r1, #0x00]
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x02
	bl func_0800501C
	movs r0, #0x03
	bl func_0800501C
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0810024C: .4byte 0x020350FA
_08100250: .4byte 0x020354D4
_08100254: .4byte 0x09A33E9C
_08100258: .4byte 0x09A3399C
_0810025C: .4byte 0x020350F8
_08100260: .4byte 0x09A3D09C
_08100264: .4byte 0x02035124
_08100268: .4byte 0x0999D41A
_0810026C: .4byte 0x02035128
_08100270: .4byte 0x02035130
_08100274: .4byte 0x09EF97C4
_08100278: .4byte 0x09EF97B0
_0810027C: .4byte 0x09A3D0BC
_08100280: .4byte 0x02035148
_08100284: .4byte 0x0999D8A8
_08100288: .4byte 0x0203514C
_0810028C: .4byte 0x02035150
_08100290: .4byte 0x09EF97DC
_08100294: .4byte 0x09EF97CC
_08100298: .4byte 0x020351F8
_0810029C: .4byte 0x02035100
_081002A0: .4byte 0x020352B8
_081002A4: .4byte 0x020352C0
_081002A8: .4byte 0x09A3D07C
_081002AC: .4byte 0x0203511C
_081002B0: .4byte 0x0999CFC6
_081002B4: .4byte 0x02035120
.syntax divided
