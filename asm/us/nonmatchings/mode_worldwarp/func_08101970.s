.syntax unified
	.align 2, 0
	.global func_08101970
	.thumb
	.thumb_func
	.type func_08101970, %function
func_08101970: @ 08101970
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	ldr r0, _08101A08 @ =0x020358A4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081019EE
	ldr r0, _08101A0C @ =0x020358A0
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, _08101A10 @ =0x099A2AD4
	ldr r1, _08101A14 @ =0x020357C8
	mov r8, r1
	ldr r3, [r1, #0x00]
	ldr r6, _08101A18 @ =0x020357CC
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	movs r1, #0xFA
	lsls r1, r1, #0x03
	str r1, [sp, #0x00C]
	movs r1, #0x00
	bl func_080023E0
	ldr r3, _08101A1C @ =0x02035898
	ldr r1, [r3, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _08101A20 @ =0x099A2AF0
	mov r7, r8
	ldr r3, [r7, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _08101A24 @ =0x000007D1
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl func_080023E0
	ldr r3, _08101A1C @ =0x02035898
	ldr r1, [r3, #0x04]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _08101A28 @ =0x099A2B24
	ldr r3, [r7, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	subs r4, #0x2F
	str r4, [sp, #0x00C]
	movs r0, #0x80
	bl func_080023E0
_081019EE:
	movs r5, #0x80
	lsls r5, r5, #0x04
	ldr r0, _08101A2C @ =0x0203587C
	movs r7, #0x00
	ldsh r0, [r0, r7]
	cmp r0, #0x01
	beq _08101A44
	cmp r0, #0x01
	bgt _08101A30
	cmp r0, #0x00
	beq _08101A36
	b _08101A44
	.byte 0x00, 0x00
_08101A08: .4byte 0x020358A4
_08101A0C: .4byte 0x020358A0
_08101A10: .4byte 0x099A2AD4
_08101A14: .4byte 0x020357C8
_08101A18: .4byte 0x020357CC
_08101A1C: .4byte 0x02035898
_08101A20: .4byte 0x099A2AF0
_08101A24: .4byte 0x000007D1
_08101A28: .4byte 0x099A2B24
_08101A2C: .4byte 0x0203587C
_08101A30:
	cmp r0, #0x02
	beq _08101A40
	b _08101A44
_08101A36:
	ldr r0, _08101BE4 @ =0x020357C0
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	bne _08101A44
_08101A40:
	movs r0, #0x01
	orrs r5, r0
_08101A44:
	ldr r0, _08101BE8 @ =0x02035860
	bl func_08005A64
	adds r2, r0, #0x0
	ldr r3, _08101BEC @ =0x09993118
	mov r8, r3
	ldr r0, _08101BF0 @ =0x0203588C
	ldr r1, _08101BF4 @ =0x02035884
	ldr r0, [r0, #0x00]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	asrs r0, r0, #0x08
	ldrh r4, [r3, #0x16]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r7, #0x18
	ldsh r1, [r3, r7]
	ldr r3, _08101BF8 @ =0x02035858
	ldr r3, [r3, #0x00]
	ldr r4, _08101BFC @ =0x0203585C
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, _08101C00 @ =0x00000834
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r0, _08101C04 @ =0x020357D8
	bl func_08005A64
	adds r2, r0, #0x0
	ldr r7, _08101C08 @ =0x02035888
	ldr r0, [r7, #0x00]
	asrs r0, r0, #0x08
	mov r1, r8
	ldrh r1, [r1, #0x0A]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r3, r8
	movs r4, #0x0C
	ldsh r1, [r3, r4]
	ldr r3, _08101C0C @ =0x020357D0
	ldr r3, [r3, #0x00]
	ldr r4, _08101C10 @ =0x020357D4
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r7, #0x00
	str r7, [sp, #0x004]
	movs r6, #0x80
	lsls r6, r6, #0x04
	str r6, [sp, #0x008]
	movs r4, #0xFA
	lsls r4, r4, #0x03
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r0, _08101C14 @ =0x020357F8
	bl func_08005A64
	adds r2, r0, #0x0
	ldr r7, _08101C08 @ =0x02035888
	ldr r0, [r7, #0x00]
	asrs r0, r0, #0x08
	mov r1, r8
	ldrh r5, [r1, #0x10]
	adds r0, r5, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0x12
	ldsh r3, [r1, r4]
	str r3, [sp, #0x010]
	ldr r1, _08101C18 @ =0x020357F0
	ldr r3, [r1, #0x00]
	ldr r1, _08101C1C @ =0x020357F4
	ldr r1, [r1, #0x00]
	str r1, [sp, #0x000]
	movs r7, #0x00
	str r7, [sp, #0x004]
	ldr r1, _08101BE4 @ =0x020357C0
	mov r9, r1
	movs r4, #0x00
	ldsh r1, [r1, r4]
	movs r7, #0x5C
	mov r10, r7
	mov r4, r10
	muls r4, r1
	adds r1, r4, #0x0
	add r1, r8
	ldrh r4, [r1, #0x14]
	adds r1, r6, #0x0
	orrs r1, r4
	str r1, [sp, #0x008]
	movs r7, #0xFA
	lsls r7, r7, #0x03
	str r7, [sp, #0x00C]
	ldr r1, [sp, #0x010]
	bl func_080023E0
	ldr r1, _08101C08 @ =0x02035888
	ldr r0, [r1, #0x00]
	asrs r0, r0, #0x08
	adds r5, r5, r0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldr r2, _08101C20 @ =0x08B22BA8
	ldr r0, _08101C24 @ =0x02035810
	ldr r3, [r0, #0x00]
	ldr r0, _08101C28 @ =0x02035814
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r7, r9
	movs r1, #0x00
	ldsh r0, [r7, r1]
	mov r4, r10
	muls r4, r0
	adds r0, r4, #0x0
	add r0, r8
	ldrh r0, [r0, #0x14]
	orrs r6, r0
	str r6, [sp, #0x008]
	ldr r0, _08101C2C @ =0x000007D1
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	ldr r1, [sp, #0x010]
	bl func_080023E0
	movs r6, #0x00
	movs r7, #0x00
_08101B50:
	ldr r0, _08101C30 @ =0x02035828
	adds r0, r7, r0
	bl func_08005A64
	adds r2, r0, #0x0
	ldr r0, _08101BEC @ =0x09993118
	lsls r3, r6, #0x05
	adds r3, r3, r0
	ldr r0, _08101BF4 @ =0x02035884
	mov r8, r0
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	ldrh r0, [r3, #0x1C]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0x1E
	ldsh r1, [r3, r4]
	ldr r3, _08101C34 @ =0x02035818
	lsls r5, r6, #0x02
	adds r3, r5, r3
	ldr r3, [r3, #0x00]
	ldr r4, _08101C38 @ =0x02035820
	adds r5, r5, r4
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	subs r4, #0x30
	str r4, [sp, #0x00C]
	bl func_080023E0
	adds r7, #0x18
	adds r6, #0x01
	cmp r6, #0x01
	ble _08101B50
	ldr r0, _08101C3C @ =0x02035890
	movs r7, #0x00
	ldsh r0, [r0, r7]
	cmp r0, #0x06
	bne _08101BAC
	bl func_08102F30
_08101BAC:
	ldr r0, _08101C40 @ =0x020358A8
	bl func_08000EE0
	mov r0, r8
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	movs r0, #0x00
	movs r2, #0x00
	bl func_080054EC
	ldr r0, _08101C44 @ =0x02035880
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	movs r0, #0x01
	movs r2, #0x00
	bl func_080054EC
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08101BE4: .4byte 0x020357C0
_08101BE8: .4byte 0x02035860
_08101BEC: .4byte 0x09993118
_08101BF0: .4byte 0x0203588C
_08101BF4: .4byte 0x02035884
_08101BF8: .4byte 0x02035858
_08101BFC: .4byte 0x0203585C
_08101C00: .4byte 0x00000834
_08101C04: .4byte 0x020357D8
_08101C08: .4byte 0x02035888
_08101C0C: .4byte 0x020357D0
_08101C10: .4byte 0x020357D4
_08101C14: .4byte 0x020357F8
_08101C18: .4byte 0x020357F0
_08101C1C: .4byte 0x020357F4
_08101C20: .4byte 0x08B22BA8
_08101C24: .4byte 0x02035810
_08101C28: .4byte 0x02035814
_08101C2C: .4byte 0x000007D1
_08101C30: .4byte 0x02035828
_08101C34: .4byte 0x02035818
_08101C38: .4byte 0x02035820
_08101C3C: .4byte 0x02035890
_08101C40: .4byte 0x020358A8
_08101C44: .4byte 0x02035880
.syntax divided
