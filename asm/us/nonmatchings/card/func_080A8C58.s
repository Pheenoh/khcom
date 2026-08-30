.syntax unified
	.align 2, 0
	.global func_080A8C58
	.thumb
	.thumb_func
	.type func_080A8C58, %function
func_080A8C58: @ 080A8C58
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r7, r0, #0x0
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _080A8C66
	b _080A8E30
_080A8C66:
	movs r1, #0xE0
	lsls r1, r1, #0x03
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _080A8D14
	cmp r0, #0x01
	bgt _080A8C7C
	cmp r0, #0x00
	beq _080A8C84
	b _080A8ED4
_080A8C7C:
	cmp r0, #0x02
	bne _080A8C82
	b _080A8DA0
_080A8C82:
	b _080A8ED4
_080A8C84:
	ldr r2, _080A8CF0 @ =0x000006D4
	adds r0, r7, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	ldr r4, _080A8CF4 @ =0x000006DA
	adds r1, r7, r4
	movs r5, #0x00
	ldsh r1, [r1, r5]
	adds r2, r7, #0x0
	adds r2, #0x28
	ldr r3, [r7, #0x0C]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r6, _080A8CF8 @ =0x00000702
	adds r4, r7, r6
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _080A8CFC @ =0x000006D6
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8D00 @ =0x000006DC
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x68
	ldr r3, _080A8D04 @ =0x000004BC
	adds r6, r7, r3
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r4, _080A8D08 @ =0x00000703
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	movs r1, #0xDB
	lsls r1, r1, #0x03
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8D0C @ =0x000006DE
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0xA8
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r5, _080A8D10 @ =0x00000704
	b _080A8E94
	.byte 0x00, 0x00
_080A8CF0: .4byte 0x000006D4
_080A8CF4: .4byte 0x000006DA
_080A8CF8: .4byte 0x00000702
_080A8CFC: .4byte 0x000006D6
_080A8D00: .4byte 0x000006DC
_080A8D04: .4byte 0x000004BC
_080A8D08: .4byte 0x00000703
_080A8D0C: .4byte 0x000006DE
_080A8D10: .4byte 0x00000704
_080A8D14:
	ldr r6, _080A8D7C @ =0x000006D4
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _080A8D80 @ =0x000006DA
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0x28
	ldr r4, _080A8D84 @ =0x000004BC
	adds r6, r7, r4
	ldr r3, [r6, #0x00]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r4, _080A8D88 @ =0x00000702
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _080A8D8C @ =0x000006D6
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8D90 @ =0x000006DC
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x68
	ldr r3, [r7, #0x0C]
	str r5, [sp, #0x000]
	ldr r4, _080A8D94 @ =0x00000703
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	movs r1, #0xDB
	lsls r1, r1, #0x03
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8D98 @ =0x000006DE
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0xA8
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r5, _080A8D9C @ =0x00000704
	b _080A8E94
_080A8D7C: .4byte 0x000006D4
_080A8D80: .4byte 0x000006DA
_080A8D84: .4byte 0x000004BC
_080A8D88: .4byte 0x00000702
_080A8D8C: .4byte 0x000006D6
_080A8D90: .4byte 0x000006DC
_080A8D94: .4byte 0x00000703
_080A8D98: .4byte 0x000006DE
_080A8D9C: .4byte 0x00000704
_080A8DA0:
	ldr r6, _080A8E0C @ =0x000006D4
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _080A8E10 @ =0x000006DA
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0x28
	ldr r4, _080A8E14 @ =0x000004BC
	adds r6, r7, r4
	ldr r3, [r6, #0x00]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r4, _080A8E18 @ =0x00000702
	ldrb r4, [r4, r7]
	str r4, [sp, #0x004]
	bl func_080664D8
	ldr r1, _080A8E1C @ =0x000006D6
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8E20 @ =0x000006DC
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x68
	ldr r3, [r6, #0x00]
	str r5, [sp, #0x000]
	ldr r6, _080A8E24 @ =0x00000703
	adds r4, r7, r6
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	movs r1, #0xDB
	lsls r1, r1, #0x03
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8E28 @ =0x000006DE
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0xA8
	ldr r3, [r7, #0x0C]
	str r5, [sp, #0x000]
	ldr r5, _080A8E2C @ =0x00000704
	b _080A8E94
	.byte 0x00, 0x00
_080A8E0C: .4byte 0x000006D4
_080A8E10: .4byte 0x000006DA
_080A8E14: .4byte 0x000004BC
_080A8E18: .4byte 0x00000702
_080A8E1C: .4byte 0x000006D6
_080A8E20: .4byte 0x000006DC
_080A8E24: .4byte 0x00000703
_080A8E28: .4byte 0x000006DE
_080A8E2C: .4byte 0x00000704
_080A8E30:
	movs r6, #0xE0
	lsls r6, r6, #0x03
	adds r0, r7, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	beq _080A8E78
	cmp r0, #0x01
	bgt _080A8E46
	cmp r0, #0x00
	beq _080A8E4C
	b _080A8ED4
_080A8E46:
	cmp r0, #0x02
	beq _080A8EAC
	b _080A8ED4
_080A8E4C:
	ldr r1, _080A8E6C @ =0x000006D4
	adds r0, r7, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _080A8E70 @ =0x000006DA
	adds r1, r7, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r2, r7, #0x0
	adds r2, #0x28
	ldr r3, [r7, #0x0C]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r5, _080A8E74 @ =0x00000702
	b _080A8E94
	.byte 0x00, 0x00
_080A8E6C: .4byte 0x000006D4
_080A8E70: .4byte 0x000006DA
_080A8E74: .4byte 0x00000702
_080A8E78:
	ldr r6, _080A8EA0 @ =0x000006D6
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _080A8EA4 @ =0x000006DC
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0x68
	ldr r3, [r7, #0x0C]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r5, _080A8EA8 @ =0x00000703
_080A8E94:
	adds r4, r7, r5
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	b _080A8ED4
_080A8EA0: .4byte 0x000006D6
_080A8EA4: .4byte 0x000006DC
_080A8EA8: .4byte 0x00000703
_080A8EAC:
	movs r6, #0xDB
	lsls r6, r6, #0x03
	adds r0, r7, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _080A8EDC @ =0x000006DE
	adds r1, r7, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r2, r7, #0x0
	adds r2, #0xA8
	ldr r3, [r7, #0x0C]
	movs r4, #0x14
	str r4, [sp, #0x000]
	ldr r5, _080A8EE0 @ =0x00000704
	adds r4, r7, r5
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
_080A8ED4:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080A8EDC: .4byte 0x000006DE
_080A8EE0: .4byte 0x00000704
.syntax divided
