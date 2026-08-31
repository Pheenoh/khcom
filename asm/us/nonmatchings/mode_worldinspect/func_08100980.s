.syntax unified
	.align 2, 0
	.global func_08100980
	.thumb
	.thumb_func
	.type func_08100980, %function
func_08100980: @ 08100980
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r7, _08100C00 @ =0x020357A2
	movs r1, #0x00
	ldsh r0, [r7, r1]
	cmp r0, #0x02
	beq _08100A0C
	ldr r0, _08100C04 @ =0x020357B0
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, _08100C08 @ =0x0999F400
	ldr r3, _08100C0C @ =0x02035510
	mov r8, r3
	ldr r3, [r3, #0x00]
	ldr r6, _08100C10 @ =0x02035514
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r1, _08100C14 @ =0x00000BB8
	str r1, [sp, #0x00C]
	movs r1, #0x00
	bl DrawSprite
	ldr r0, _08100C18 @ =0x020357A8
	mov r10, r0
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _08100C1C @ =0x0999F416
	mov r0, r8
	ldr r3, [r0, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _08100C20 @ =0x00000BB9
	mov r9, r0
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl DrawSprite
	mov r2, r10
	ldr r1, [r2, #0x04]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _08100C24 @ =0x0999F44A
	mov r0, r8
	ldr r3, [r0, #0x00]
	ldr r0, [r6, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	mov r4, r9
	str r4, [sp, #0x00C]
	movs r0, #0x80
	bl DrawSprite
	movs r1, #0x00
	ldsh r0, [r7, r1]
	cmp r0, #0x02
	bne _08100AD2
_08100A0C:
	ldr r0, _08100C28 @ =0x02035520
	bl AnimUpdate
	adds r2, r0, #0x0
	ldr r6, _08100C2C @ =0x09EF9384
	ldr r5, _08100C30 @ =0x020354E8
	movs r3, #0x00
	ldsh r0, [r5, r3]
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r1, r1, r6
	movs r4, #0x08
	ldsh r0, [r1, r4]
	lsls r0, r0, #0x13
	movs r3, #0xB0
	lsls r3, r3, #0x0D
	adds r0, r0, r3
	asrs r0, r0, #0x10
	movs r4, #0x0A
	ldsh r1, [r1, r4]
	lsls r1, r1, #0x13
	movs r3, #0xC0
	lsls r3, r3, #0x0C
	adds r1, r1, r3
	asrs r1, r1, #0x10
	ldr r3, _08100C34 @ =0x02035518
	ldr r3, [r3, #0x00]
	ldr r4, _08100C38 @ =0x0203551C
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	mov r10, r4
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	mov r9, r4
	str r4, [sp, #0x008]
	adds r4, #0x98
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r0, _08100C3C @ =0x020357B4
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
	ldr r4, _08100C40 @ =0x020357B8
	movs r0, #0x00
	ldsh r1, [r5, r0]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r6
	movs r2, #0x0A
	ldsh r1, [r0, r2]
	lsls r1, r1, #0x0B
	ldr r3, _08100C44 @ =0xFFFFFA00
	adds r1, r1, r3
	adds r0, r4, #0x0
	bl func_0805F1C0
	ldr r0, _08100C48 @ =0x02035558
	bl AnimUpdate
	adds r2, r0, #0x0
	mov r1, r8
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, _08100C4C @ =0x02035550
	ldr r3, [r3, #0x00]
	ldr r4, _08100C50 @ =0x02035554
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	mov r4, r9
	str r4, [sp, #0x008]
	movs r4, #0xFA
	lsls r4, r4, #0x03
	str r4, [sp, #0x00C]
	bl DrawSprite
_08100AD2:
	movs r6, #0x00
	movs r7, #0x00
_08100AD6:
	ldr r0, _08100C54 @ =0x020355E0
	mov r8, r0
	lsls r4, r6, #0x02
	adds r0, r4, r0
	ldr r5, [r0, #0x00]
	cmp r5, #0x00
	beq _08100B28
	ldr r1, _08100C2C @ =0x09EF9384
	adds r1, r7, r1
	movs r2, #0x08
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x13
	movs r3, #0x80
	lsls r3, r3, #0x0D
	adds r0, r0, r3
	asrs r0, r0, #0x10
	movs r2, #0x0A
	ldsh r1, [r1, r2]
	lsls r1, r1, #0x13
	adds r1, r1, r3
	asrs r1, r1, #0x10
	ldr r2, _08100C58 @ =0x02035570
	adds r2, r4, r2
	ldr r3, [r2, #0x00]
	ldr r2, _08100C5C @ =0x020355A8
	adds r2, r4, r2
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x04
	str r2, [sp, #0x008]
	ldr r4, _08100C60 @ =0x00000834
	adds r2, r6, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r5, #0x0
	bl DrawSprite
_08100B28:
	adds r7, #0x14
	adds r6, #0x01
	cmp r6, #0x0C
	ble _08100AD6
	ldr r0, _08100C64 @ =0x02039BB0
	ldrb r0, [r0, #0x0E]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #0x02
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	beq _08100B64
	ldr r0, _08100C58 @ =0x02035570
	adds r0, r1, r0
	ldr r3, [r0, #0x00]
	ldr r0, _08100C5C @ =0x020355A8
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x02
	str r0, [sp, #0x00C]
	movs r0, #0x70
	movs r1, #0x10
	bl DrawSprite
_08100B64:
	ldr r1, _08100C68 @ =0x020356D8
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08100B82
	ldr r2, _08100C6C @ =0x02035618
	ldr r0, _08100C38 @ =0x0203551C
	ldr r3, [r0, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldrb r0, [r1, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x80
	movs r1, #0x0C
	bl func_080664D8
_08100B82:
	ldr r0, _08100C70 @ =0x02035538
	bl AnimUpdate
	adds r2, r0, #0x0
	ldr r0, _08100C34 @ =0x02035518
	ldr r3, [r0, #0x00]
	ldr r0, _08100C38 @ =0x0203551C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r5, #0x02
	str r5, [sp, #0x00C]
	movs r0, #0xB0
	movs r1, #0x1A
	bl DrawSprite
	ldr r0, _08100C30 @ =0x020354E8
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r1, r0, #0x02
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	beq _08100BD4
	ldr r0, _08100C58 @ =0x02035570
	adds r0, r1, r0
	ldr r3, [r0, #0x00]
	ldr r0, _08100C5C @ =0x020355A8
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r5, [sp, #0x00C]
	movs r0, #0x70
	movs r1, #0x30
	bl DrawSprite
_08100BD4:
	ldr r1, _08100C74 @ =0x020357A0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08100BF0
	ldr r2, _08100C78 @ =0x020356E0
	ldr r0, _08100C50 @ =0x02035554
	ldr r3, [r0, #0x00]
	str r4, [sp, #0x000]
	ldrb r0, [r1, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x80
	movs r1, #0x2C
	bl func_080664D8
_08100BF0:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08100C00: .4byte 0x020357A2
_08100C04: .4byte 0x020357B0
_08100C08: .4byte 0x0999F400
_08100C0C: .4byte 0x02035510
_08100C10: .4byte 0x02035514
_08100C14: .4byte 0x00000BB8
_08100C18: .4byte 0x020357A8
_08100C1C: .4byte 0x0999F416
_08100C20: .4byte 0x00000BB9
_08100C24: .4byte 0x0999F44A
_08100C28: .4byte 0x02035520
_08100C2C: .4byte 0x09EF9384
_08100C30: .4byte 0x020354E8
_08100C34: .4byte 0x02035518
_08100C38: .4byte 0x0203551C
_08100C3C: .4byte 0x020357B4
_08100C40: .4byte 0x020357B8
_08100C44: .4byte 0xFFFFFA00
_08100C48: .4byte 0x02035558
_08100C4C: .4byte 0x02035550
_08100C50: .4byte 0x02035554
_08100C54: .4byte 0x020355E0
_08100C58: .4byte 0x02035570
_08100C5C: .4byte 0x020355A8
_08100C60: .4byte 0x00000834
_08100C64: .4byte 0x02039BB0
_08100C68: .4byte 0x020356D8
_08100C6C: .4byte 0x02035618
_08100C70: .4byte 0x02035538
_08100C74: .4byte 0x020357A0
_08100C78: .4byte 0x020356E0
.syntax divided
