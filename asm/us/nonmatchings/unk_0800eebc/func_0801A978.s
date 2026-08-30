.syntax unified
	.align 2, 0
	.global func_0801A978
	.thumb
	.thumb_func
	.type func_0801A978, %function
func_0801A978: @ 0801A978
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r6, [r0, #0x34]
	ldr r7, [r0, #0x38]
	movs r2, #0x40
	adds r0, r6, #0x0
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	mov r12, r2
	cmp r2, #0x00
	beq _0801A9D0
	movs r0, #0x41
	negs r0, r0
	adds r4, r6, #0x0
	ands r4, r0
	adds r5, r7, #0x0
	mov r3, r8
	str r4, [r3, #0x34]
	str r5, [r3, #0x38]
	ldr r0, [r3, #0x24]
	movs r1, #0x80
	lsls r1, r1, #0x0A
	ands r0, r1
	cmp r0, #0x00
	beq _0801A9C2
	ldr r3, _0801A9CC @ =0x00000008
	ldr r2, _0801A9C8 @ =0x00000000
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	orrs r1, r3
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
_0801A9C2:
	movs r0, #0x0B
	b _0801AD5E
	.byte 0x00, 0x00
_0801A9C8: .4byte 0x00000000
_0801A9CC: .4byte 0x00000008
_0801A9D0:
	movs r4, #0x02
	adds r0, r6, #0x0
	ands r0, r4
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801A9E0
	b _0801AC76
_0801A9E0:
	movs r2, #0x04
	negs r2, r2
	adds r0, r6, #0x0
	ands r0, r2
	adds r1, r7, #0x0
	mov r3, r8
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	ldrh r0, [r3, #0x2C]
	ldrh r1, [r3, #0x20]
	subs r0, r0, r1
	strh r0, [r3, #0x2C]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0801AA02
	mov r0, r12
	strh r0, [r3, #0x2C]
_0801AA02:
	mov r2, r8
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x02
	negs r2, r2
	ands r0, r2
	mov r3, r8
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	ldr r0, _0801AAB8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x76
	ldrh r1, [r1, #0x00]
	adds r0, #0x72
	strh r1, [r0, #0x00]
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ldr r2, _0801AABC @ =0x00002280
	ldr r3, _0801AAC0 @ =0x00000000
	orrs r0, r2
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0x83
	lsls r0, r0, #0x01
	add r0, r8
	mov r3, r12
	strh r3, [r0, #0x00]
	movs r1, #0x2C
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	bgt _0801AAE8
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ldr r2, _0801AAC4 @ =0x00000100
	ldr r3, _0801AAC8 @ =0x00000000
	orrs r0, r2
	ldr r4, _0801AACC @ =0xFFFFBFDF
	adds r2, r0, #0x0
	ands r2, r4
	adds r3, r1, #0x0
	ldr r4, _0801AAD0 @ =0x00000000
	ldr r5, _0801AAD4 @ =0x00000010
	adds r0, r2, #0x0
	orrs r1, r5
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r0, r8
	adds r0, #0xE8
	mov r3, r12
	str r3, [r0, #0x00]
	adds r0, #0x04
	strh r3, [r0, #0x00]
	ldr r0, [r2, #0x24]
	movs r1, #0x80
	lsls r1, r1, #0x0A
	ands r0, r1
	cmp r0, #0x00
	beq _0801AA8C
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ldr r2, _0801AAD8 @ =0x00000000
	ldr r3, _0801AADC @ =0x00000008
	orrs r1, r3
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
_0801AA8C:
	mov r0, r8
	ldr r3, [r0, #0x34]
	ldr r4, [r0, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x0B
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801AAE4
	ldr r2, _0801AAE0 @ =0xFFFBFFFF
	adds r0, r3, #0x0
	ands r0, r2
	adds r1, r4, #0x0
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0x08
	b _0801AD5E
	.byte 0x00, 0x00
_0801AAB8: .4byte 0x02039B84
_0801AABC: .4byte 0x00002280
_0801AAC0: .4byte 0x00000000
_0801AAC4: .4byte 0x00000100
_0801AAC8: .4byte 0x00000000
_0801AACC: .4byte 0xFFFFBFDF
_0801AAD0: .4byte 0x00000000
_0801AAD4: .4byte 0x00000010
_0801AAD8: .4byte 0x00000000
_0801AADC: .4byte 0x00000008
_0801AAE0: .4byte 0xFFFBFFFF
_0801AAE4:
	movs r0, #0x03
	b _0801AD5E
_0801AAE8:
	mov r3, r8
	ldr r0, [r3, #0x00]
	cmp r0, #0x37
	beq _0801AB12
	bl func_080065A4
	lsls r0, r0, #0x10
	movs r1, #0xE0
	lsls r1, r1, #0x0B
	ands r1, r0
	cmp r1, #0x00
	bne _0801AB12
	mov r1, r8
	ldr r0, [r1, #0x04]
	ldr r1, [r1, #0x08]
	mov r3, r8
	ldr r2, [r3, #0x0C]
	ldr r3, _0801AB54 @ =0xFFFF8800
	adds r2, r2, r3
	bl func_08019ACC
_0801AB12:
	mov r0, r8
	ldr r4, [r0, #0x34]
	ldr r5, [r0, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x0B
	movs r6, #0x00
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801AB64
	ldr r0, _0801AB58 @ =0xFFFBFFFF
	adds r2, r4, #0x0
	ands r2, r0
	adds r3, r5, #0x0
	ldr r4, _0801AB5C @ =0xFFFFB7FF
	ldr r5, _0801AB60 @ =0xFFFFFADF
	adds r0, r4, #0x0
	ands r0, r2
	adds r1, r5, #0x0
	ands r1, r3
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r0, r8
	adds r0, #0xE8
	str r6, [r0, #0x00]
	adds r0, #0x04
	strh r6, [r0, #0x00]
	movs r0, #0x07
	b _0801AD5E
_0801AB54: .4byte 0xFFFF8800
_0801AB58: .4byte 0xFFFBFFFF
_0801AB5C: .4byte 0xFFFFB7FF
_0801AB60: .4byte 0xFFFFFADF
_0801AB64:
	movs r0, #0x80
	lsls r0, r0, #0x07
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801ABA8
	ldr r1, _0801ABA4 @ =0xFFFFFADF
	ldr r0, _0801ABA0 @ =0xFFFFB7FF
	adds r2, r0, #0x0
	ands r2, r4
	adds r3, r1, #0x0
	ands r3, r5
	mov r0, r8
	str r2, [r0, #0x34]
	str r3, [r0, #0x38]
	mov r1, r8
	adds r1, #0xE8
	ldr r0, [r1, #0x00]
	cmp r0, #0x01
	beq _0801AB9C
	movs r0, #0x01
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0xF0
	strh r0, [r1, #0x00]
_0801AB9C:
	movs r0, #0x06
	b _0801AD5E
_0801ABA0: .4byte 0xFFFFB7FF
_0801ABA4: .4byte 0xFFFFFADF
_0801ABA8:
	movs r0, #0x20
	movs r1, #0x00
	adds r2, r5, #0x0
	ands r2, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801ABE8
	ldr r3, _0801ABE4 @ =0xFFFFFADF
	ldr r2, _0801ABE0 @ =0xFFFFB7FF
	adds r0, r2, #0x0
	ands r0, r4
	adds r1, r3, #0x0
	ands r1, r5
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r1, r8
	adds r1, #0xE8
	movs r0, #0x04
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x96
	lsls r0, r0, #0x01
	strh r0, [r1, #0x00]
	movs r0, #0x0C
	b _0801AD5E
	.byte 0x00, 0x00
_0801ABE0: .4byte 0xFFFFB7FF
_0801ABE4: .4byte 0xFFFFFADF
_0801ABE8:
	movs r0, #0x80
	lsls r0, r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	ands r2, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801AC24
	ldr r3, _0801AC20 @ =0xFFFFFADF
	ldr r2, _0801AC1C @ =0xFFFFB7FF
	adds r0, r2, #0x0
	ands r0, r4
	adds r1, r3, #0x0
	ands r1, r5
	mov r3, r8
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	mov r1, r8
	adds r1, #0xE8
	movs r0, #0x03
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x96
	lsls r0, r0, #0x01
	b _0801AC5A
_0801AC1C: .4byte 0xFFFFB7FF
_0801AC20: .4byte 0xFFFFFADF
_0801AC24:
	movs r2, #0x80
	lsls r2, r2, #0x03
	movs r0, #0x00
	adds r1, r5, #0x0
	ands r1, r2
	orrs r1, r0
	cmp r1, #0x00
	beq _0801AC68
	ldr r1, _0801AC64 @ =0xFFFFFADF
	ldr r0, _0801AC60 @ =0xFFFFB7FF
	adds r2, r0, #0x0
	ands r2, r4
	adds r3, r1, #0x0
	ands r3, r5
	mov r0, r8
	str r2, [r0, #0x34]
	str r3, [r0, #0x38]
	mov r1, r8
	adds r1, #0xE8
	ldr r0, [r1, #0x00]
	cmp r0, #0x05
	beq _0801AC72
	movs r0, #0x05
	str r0, [r1, #0x00]
	adds r1, #0x04
	movs r0, #0x96
	lsls r0, r0, #0x02
_0801AC5A:
	strh r0, [r1, #0x00]
	b _0801AC72
	.byte 0x00, 0x00
_0801AC60: .4byte 0xFFFFB7FF
_0801AC64: .4byte 0xFFFFFADF
_0801AC68:
	mov r0, r8
	adds r0, #0xE8
	str r1, [r0, #0x00]
	adds r0, #0x04
	strh r1, [r0, #0x00]
_0801AC72:
	movs r0, #0x01
	b _0801AD5E
_0801AC76:
	movs r0, #0x20
	adds r1, r6, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801ACAC
	movs r0, #0x22
	negs r0, r0
	adds r2, r6, #0x0
	ands r2, r0
	adds r3, r7, #0x0
	ldr r5, _0801ACA8 @ =0x00000000
	ldr r4, _0801ACA4 @ =0x00000280
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0x02
	b _0801AD5E
_0801ACA4: .4byte 0x00000280
_0801ACA8: .4byte 0x00000000
_0801ACAC:
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r6, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801ACE4
	ldr r0, _0801ACE0 @ =0xDFFFFFFF
	adds r1, r6, #0x0
	ands r1, r0
	adds r2, r7, #0x0
	mov r3, r8
	str r1, [r3, #0x34]
	str r2, [r3, #0x38]
	movs r1, #0x2C
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	ble _0801AD5C
	mov r0, r8
	bl func_0801AF08
	movs r0, #0x09
	b _0801AD5E
	.byte 0x00, 0x00
_0801ACE0: .4byte 0xDFFFFFFF
_0801ACE4:
	movs r0, #0x80
	lsls r0, r0, #0x04
	adds r1, r6, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801AD5C
	ldr r3, _0801AD4C @ =0xFFFFFADF
	ldr r2, _0801AD48 @ =0xFFFFB7FF
	adds r0, r2, #0x0
	ands r0, r6
	adds r1, r3, #0x0
	ands r1, r7
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	ldr r0, _0801AD50 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x76
	ldrh r1, [r1, #0x00]
	adds r0, #0x72
	strh r1, [r0, #0x00]
	mov r0, r8
	bl func_0801AF08
	mov r3, r8
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ldr r2, _0801AD54 @ =0x00000200
	ldr r3, _0801AD58 @ =0x00000000
	orrs r0, r2
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r1, r8
	adds r1, #0xE8
	ldr r0, [r1, #0x00]
	cmp r0, #0x02
	beq _0801AD42
	str r4, [r1, #0x00]
	ldrh r1, [r2, #0x20]
	mov r0, r8
	adds r0, #0xEC
	strh r1, [r0, #0x00]
_0801AD42:
	movs r0, #0x0A
	b _0801AD5E
	.byte 0x00, 0x00
_0801AD48: .4byte 0xFFFFB7FF
_0801AD4C: .4byte 0xFFFFFADF
_0801AD50: .4byte 0x02039B84
_0801AD54: .4byte 0x00000200
_0801AD58: .4byte 0x00000000
_0801AD5C:
	movs r0, #0x00
_0801AD5E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
