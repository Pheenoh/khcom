.syntax unified
	.align 2, 0
	.global func_08010A24
	.thumb
	.thumb_func
	.type func_08010A24, %function
func_08010A24: @ 08010A24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08010A50 @ =0x02039B84
	ldr r5, [r0, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x05
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08010A54
	bl func_0800886C
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl func_0800889C
	b _08010A60
	.byte 0x00, 0x00
_08010A50: .4byte 0x02039B84
_08010A54:
	bl func_08008884
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl func_080088B4
_08010A60:
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _08010AB0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x0D
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _08010A90
	movs r0, #0x01
	ands r0, r4
	cmp r0, #0x00
	beq _08010A90
	movs r0, #0xC0
	lsls r0, r0, #0x02
	ands r0, r4
	cmp r0, #0x00
	bne _08010A90
	bl func_080763F0
_08010A90:
	ldr r0, _08010AB0 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x11
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08010AB8
	ldr r1, _08010AB4 @ =0x020348E0
	movs r0, #0x05
	strh r0, [r1, #0x00]
	b _08010C60
	.byte 0x00, 0x00
_08010AB0: .4byte 0x02039B84
_08010AB4: .4byte 0x020348E0
_08010AB8:
	movs r0, #0xE6
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _08010ADA
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _08010AD4
	b _08010C60
_08010AD4:
	bl func_08076394
	b _08010C60
_08010ADA:
	ldr r1, _08010B10 @ =0x020348E0
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x00
	ble _08010AEA
	subs r0, r2, #0x1
	strh r0, [r1, #0x00]
_08010AEA:
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	movs r2, #0x00
	bl func_08010600
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r8, r0
	beq _08010B14
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r8, r0
	bne _08010B18
	bl func_08076318
	b _08010B18
_08010B10: .4byte 0x020348E0
_08010B14:
	bl func_08076324
_08010B18:
	movs r0, #0x04
	ands r0, r7
	cmp r0, #0x00
	beq _08010B24
	bl func_08076394
_08010B24:
	bl func_080763D0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	beq _08010B44
	adds r0, r5, #0x0
	adds r0, #0xE2
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r2, r5, #0x0
	adds r2, #0xE3
	strb r1, [r2, #0x00]
	adds r3, r0, #0x0
	adds r4, r2, #0x0
	b _08010B9C
_08010B44:
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r1, #0x0
	adds r1, r4, #0x0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r1, r0
	bne _08010B68
	adds r0, r5, #0x0
	adds r0, #0xE2
	ldrb r1, [r0, #0x00]
	adds r3, r0, #0x0
	cmp r1, #0xFE
	bhi _08010B70
	adds r0, r1, #0x1
	strb r0, [r3, #0x00]
	b _08010B70
_08010B68:
	adds r0, r5, #0x0
	adds r0, #0xE2
	strb r2, [r0, #0x00]
	adds r3, r0, #0x0
_08010B70:
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r1, #0x0
	ands r4, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r4, r0
	bne _08010B92
	adds r0, r5, #0x0
	adds r0, #0xE3
	ldrb r1, [r0, #0x00]
	adds r4, r0, #0x0
	cmp r1, #0xFE
	bhi _08010B9C
	adds r0, r1, #0x1
	strb r0, [r4, #0x00]
	b _08010B9C
_08010B92:
	adds r1, r5, #0x0
	adds r1, #0xE3
	movs r0, #0x00
	strb r0, [r1, #0x00]
	adds r4, r1, #0x0
_08010B9C:
	ldrb r0, [r3, #0x00]
	cmp r0, #0x20
	bls _08010BA6
	bl func_08076318
_08010BA6:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x20
	bls _08010BB0
	bl func_08076324
_08010BB0:
	ldr r0, [r5, #0x7C]
	ldr r5, [r0, #0x34]
	ldr r6, [r0, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r5, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08010C60
	ldr r0, _08010C28 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x16
	adds r0, r3, #0x0
	ands r0, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _08010C60
	movs r0, #0x80
	lsls r0, r0, #0x14
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08010C60
	movs r0, #0x80
	lsls r0, r0, #0x10
	adds r1, r3, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08010C60
	movs r0, #0x02
	adds r1, r5, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _08010C60
	movs r0, #0xC0
	lsls r0, r0, #0x02
	cmp r8, r0
	bne _08010C30
	bl func_0807B3E0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _08010C2C
	bl func_08076348
	b _08010C30
	.byte 0x00, 0x00
_08010C28: .4byte 0x02039B84
_08010C2C:
	bl func_0807633C
_08010C30:
	movs r0, #0x01
	ands r7, r0
	cmp r7, #0x00
	beq _08010C60
	bl func_08076330
	bl func_0807B3C8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x03
	bne _08010C60
	bl func_0807643C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08010C60
	ldr r0, _08010C6C @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0xE6
	lsls r3, r3, #0x01
	adds r0, r0, r3
	movs r1, #0x0F
	strh r1, [r0, #0x00]
_08010C60:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08010C6C: .4byte 0x02039B84
.syntax divided
