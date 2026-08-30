.syntax unified
	.align 2, 0
	.global func_080FF8CC
	.thumb
	.thumb_func
	.type func_080FF8CC, %function
func_080FF8CC: @ 080FF8CC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r7, _080FFB7C @ =0x020354C0
	movs r1, #0x00
	ldsh r0, [r7, r1]
	cmp r0, #0x02
	beq _080FF950
	ldr r0, _080FFB80 @ =0x020354D0
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, _080FFB84 @ =0x0999CF38
	ldr r3, _080FFB88 @ =0x02035120
	mov r8, r3
	ldr r3, [r3, #0x00]
	ldr r6, _080FFB8C @ =0x0203511C
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r1, _080FFB90 @ =0x00000BB8
	str r1, [sp, #0x00C]
	movs r1, #0x00
	bl func_080023E0
	ldr r0, _080FFB94 @ =0x020354C8
	mov r10, r0
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080FFB98 @ =0x0999CF54
	mov r0, r8
	ldr r3, [r0, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _080FFB9C @ =0x00000BB9
	mov r9, r0
	str r0, [sp, #0x00C]
	movs r0, #0x70
	bl func_080023E0
	mov r2, r10
	ldr r1, [r2, #0x04]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080FFBA0 @ =0x0999CF88
	mov r0, r8
	ldr r3, [r0, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	mov r4, r9
	str r4, [sp, #0x00C]
	movs r0, #0x70
	bl func_080023E0
_080FF950:
	movs r0, #0x80
	lsls r0, r0, #0x03
	mov r10, r0
	ldr r0, _080FFBA4 @ =0x02035118
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x01
	bne _080FF968
	movs r0, #0x04
	mov r2, r10
	orrs r2, r0
	mov r10, r2
_080FF968:
	movs r3, #0x00
	ldsh r0, [r7, r3]
	cmp r0, #0x02
	bne _080FFA32
	ldr r0, _080FFBA8 @ =0x02035130
	bl func_08005A64
	adds r2, r0, #0x0
	ldr r6, _080FFBAC @ =0x09EF8FAC
	ldr r5, _080FFBB0 @ =0x020350F8
	movs r4, #0x00
	ldsh r0, [r5, r4]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r1, r1, r6
	movs r3, #0x08
	ldsh r0, [r1, r3]
	lsls r0, r0, #0x13
	movs r4, #0xB0
	lsls r4, r4, #0x0D
	adds r0, r0, r4
	asrs r0, r0, #0x10
	movs r3, #0x0A
	ldsh r1, [r1, r3]
	lsls r1, r1, #0x13
	movs r4, #0xC0
	lsls r4, r4, #0x0C
	adds r1, r1, r4
	asrs r1, r1, #0x10
	ldr r3, _080FFBB4 @ =0x02035128
	ldr r3, [r3, #0x00]
	ldr r4, _080FFBB8 @ =0x02035124
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	mov r9, r4
	str r4, [sp, #0x004]
	mov r4, r10
	str r4, [sp, #0x008]
	ldr r4, _080FFBBC @ =0x000007DD
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r0, _080FFBC0 @ =0x020354D8
	mov r8, r0
	movs r2, #0x00
	ldsh r1, [r5, r2]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r6
	movs r3, #0x08
	ldsh r1, [r0, r3]
	lsls r1, r1, #0x0B
	movs r4, #0x80
	lsls r4, r4, #0x06
	adds r1, r1, r4
	mov r0, r8
	bl func_0805F1C0
	ldr r4, _080FFBC4 @ =0x020354DC
	movs r0, #0x00
	ldsh r1, [r5, r0]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r6
	movs r2, #0x0A
	ldsh r1, [r0, r2]
	lsls r1, r1, #0x0B
	ldr r3, _080FFBC8 @ =0xFFFFFA00
	adds r1, r1, r3
	adds r0, r4, #0x0
	bl func_0805F1C0
	ldr r0, _080FFBCC @ =0x02035150
	bl func_08005A64
	adds r2, r0, #0x0
	mov r1, r8
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, _080FFBD0 @ =0x0203514C
	ldr r3, [r3, #0x00]
	ldr r4, _080FFBD4 @ =0x02035148
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r9
	str r4, [sp, #0x004]
	mov r4, r10
	str r4, [sp, #0x008]
	movs r4, #0xFA
	lsls r4, r4, #0x03
	str r4, [sp, #0x00C]
	bl func_080023E0
_080FFA32:
	movs r5, #0x00
	movs r7, #0x00
_080FFA36:
	ldr r0, _080FFBD8 @ =0x020351C8
	lsls r3, r5, #0x02
	adds r0, r3, r0
	ldr r6, [r0, #0x00]
	cmp r6, #0x00
	beq _080FFA8C
	ldr r0, _080FFBDC @ =0x02035168
	adds r0, r3, r0
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	beq _080FFA8C
	ldr r1, _080FFBAC @ =0x09EF8FAC
	adds r1, r7, r1
	movs r2, #0x08
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x0D
	adds r0, r0, r2
	asrs r0, r0, #0x10
	movs r2, #0x0A
	ldsh r1, [r1, r2]
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x0D
	adds r1, r1, r2
	asrs r1, r1, #0x10
	ldr r2, _080FFBE0 @ =0x02035198
	adds r2, r3, r2
	ldr r3, [r2, #0x00]
	str r4, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	mov r4, r10
	str r4, [sp, #0x008]
	ldr r4, _080FFBE4 @ =0x000007D1
	adds r2, r5, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r6, #0x0
	bl func_080023E0
_080FFA8C:
	adds r7, #0x14
	adds r5, #0x01
	cmp r5, #0x0B
	ble _080FFA36
	ldr r0, _080FFBD8 @ =0x020351C8
	ldr r1, _080FFBB0 @ =0x020350F8
	movs r2, #0x00
	ldsh r1, [r1, r2]
	lsls r1, r1, #0x02
	adds r0, r1, r0
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	beq _080FFAC4
	ldr r0, _080FFBE0 @ =0x02035198
	adds r0, r1, r0
	ldr r3, [r0, #0x00]
	ldr r0, _080FFBDC @ =0x02035168
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	str r0, [sp, #0x00C]
	movs r0, #0x70
	movs r1, #0x20
	bl func_080023E0
_080FFAC4:
	ldr r1, _080FFBE8 @ =0x020352B8
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080FFAE2
	ldr r2, _080FFBEC @ =0x020351F8
	ldr r0, _080FFBD4 @ =0x02035148
	ldr r3, [r0, #0x00]
	movs r0, #0x01
	str r0, [sp, #0x000]
	ldrb r0, [r1, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x80
	movs r1, #0x1C
	bl func_080664D8
_080FFAE2:
	ldr r0, _080FFBA4 @ =0x02035118
	movs r3, #0x00
	ldsh r7, [r0, r3]
	cmp r7, #0x01
	bne _080FFB6C
	ldr r1, _080FFBF0 @ =0x020354A0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080FFB0A
	ldr r2, _080FFBF4 @ =0x020352C0
	ldr r0, _080FFBB8 @ =0x02035124
	ldr r3, [r0, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldrb r0, [r1, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x61
	movs r1, #0x38
	bl func_080664D8
_080FFB0A:
	ldr r4, _080FFBF8 @ =0x08121400
	mov r10, r4
	ldr r0, _080FFBFC @ =0x0203511A
	mov r9, r0
	ldrb r0, [r0, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	add r0, r10
	movs r2, #0x00
	ldsh r1, [r0, r2]
	negs r1, r1
	asrs r1, r1, #0x05
	adds r1, #0x54
	ldr r3, _080FFC00 @ =0x020354B8
	mov r8, r3
	ldr r2, [r3, #0x00]
	ldr r6, _080FFC04 @ =0x020354B0
	ldr r3, [r6, #0x00]
	ldr r5, _080FFC08 @ =0x020354A8
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r7, [sp, #0x00C]
	movs r0, #0x2F
	bl func_080023E0
	mov r1, r9
	ldrb r0, [r1, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	add r0, r10
	movs r2, #0x00
	ldsh r1, [r0, r2]
	negs r1, r1
	asrs r1, r1, #0x05
	adds r1, #0x54
	mov r3, r8
	ldr r2, [r3, #0x04]
	ldr r3, [r6, #0x04]
	ldr r0, [r5, #0x04]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x2F
	bl func_080023E0
_080FFB6C:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080FFB7C: .4byte 0x020354C0
_080FFB80: .4byte 0x020354D0
_080FFB84: .4byte 0x0999CF38
_080FFB88: .4byte 0x02035120
_080FFB8C: .4byte 0x0203511C
_080FFB90: .4byte 0x00000BB8
_080FFB94: .4byte 0x020354C8
_080FFB98: .4byte 0x0999CF54
_080FFB9C: .4byte 0x00000BB9
_080FFBA0: .4byte 0x0999CF88
_080FFBA4: .4byte 0x02035118
_080FFBA8: .4byte 0x02035130
_080FFBAC: .4byte 0x09EF8FAC
_080FFBB0: .4byte 0x020350F8
_080FFBB4: .4byte 0x02035128
_080FFBB8: .4byte 0x02035124
_080FFBBC: .4byte 0x000007DD
_080FFBC0: .4byte 0x020354D8
_080FFBC4: .4byte 0x020354DC
_080FFBC8: .4byte 0xFFFFFA00
_080FFBCC: .4byte 0x02035150
_080FFBD0: .4byte 0x0203514C
_080FFBD4: .4byte 0x02035148
_080FFBD8: .4byte 0x020351C8
_080FFBDC: .4byte 0x02035168
_080FFBE0: .4byte 0x02035198
_080FFBE4: .4byte 0x000007D1
_080FFBE8: .4byte 0x020352B8
_080FFBEC: .4byte 0x020351F8
_080FFBF0: .4byte 0x020354A0
_080FFBF4: .4byte 0x020352C0
_080FFBF8: .4byte 0x08121400
_080FFBFC: .4byte 0x0203511A
_080FFC00: .4byte 0x020354B8
_080FFC04: .4byte 0x020354B0
_080FFC08: .4byte 0x020354A8
.syntax divided
