.syntax unified
	.align 2, 0
	.global func_080ABCA4
	.thumb
	.thumb_func
	.type func_080ABCA4, %function
func_080ABCA4: @ 080ABCA4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x02C
	adds r6, r0, #0x0
	mov r9, r1
	add r0, sp, #0x008
	movs r1, #0x00
	movs r2, #0x18
	bl _0811F090
	add r5, sp, #0x028
	movs r0, #0x00
	strb r0, [r5, #0x00]
	add r4, sp, #0x020
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x06
	bl _0811F090
	movs r7, #0x00
	ldr r0, _080ABD70 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xD0
	mov r12, r5
	mov r8, r4
	ldrb r2, [r1, #0x00]
	cmp r7, r2
	bcs _080ABD0E
	adds r5, r0, #0x0
	adds r4, r1, #0x0
_080ABCE6:
	lsls r2, r7, #0x02
	mov r1, sp
	adds r1, r1, r2
	adds r1, #0x08
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x48]
	ldrh r0, [r3, #0x28]
	str r0, [r1, #0x00]
	cmp r6, #0x00
	beq _080ABD02
	adds r1, r2, r6
	ldr r0, [r3, #0x24]
	str r0, [r1, #0x00]
_080ABD02:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r3, [r4, #0x00]
	cmp r7, r3
	bcc _080ABCE6
_080ABD0E:
	ldr r7, _080ABD70 @ =0x02039DD4
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xD0
	ldrb r1, [r2, #0x00]
	adds r4, r7, #0x0
	cmp r1, #0x01
	bne _080ABD86
	adds r0, #0xDD
	strb r1, [r0, #0x00]
	ldr r0, _080ABD74 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080ABD7C
	ldr r0, _080ABD78 @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080ABD7C
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r1, r0
	cmp r1, #0x00
	bne _080ABD7C
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xEE
	ldrb r0, [r2, #0x00]
	cmp r0, #0x01
	beq _080ABD68
	movs r5, #0xE4
	lsls r5, r5, #0x01
	adds r0, r3, r5
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x1D
	ble _080ABD7C
_080ABD68:
	strb r1, [r2, #0x00]
	movs r0, #0x2E
	b _080ABEBC
	.byte 0x00, 0x00
_080ABD70: .4byte 0x02039DD4
_080ABD74: .4byte 0x02039BB0
_080ABD78: .4byte 0x02039B84
_080ABD7C:
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x24]
	b _080ABEBC
_080ABD86:
	cmp r1, #0x00
	bne _080ABD94
	adds r0, #0xDD
	strb r1, [r0, #0x00]
	movs r0, #0x01
	negs r0, r0
	b _080ABEBC
_080ABD94:
	ldrb r1, [r2, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xC2
	ldrb r2, [r2, #0x00]
	mov r5, r12
	str r5, [sp, #0x000]
	mov r3, r9
	str r3, [sp, #0x004]
	add r3, sp, #0x008
	bl func_080AD144
	adds r1, r0, #0x0
	cmp r1, #0x6A
	beq _080ABE1C
	cmp r1, #0x6C
	bne _080ABDC0
	ldr r0, [r7, #0x00]
	adds r0, #0xDD
	movs r1, #0x01
	strb r1, [r0, #0x00]
	movs r0, #0x2E
	b _080ABEBC
_080ABDC0:
	ldr r0, _080ABDEC @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080ABDF0
	adds r0, r2, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080ABE14
	adds r0, r1, #0x0
	bl _080AC140
	str r0, [r6, #0x04]
	str r0, [r6, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, #0xDD
	movs r1, #0x02
	b _080ABEB8
	.byte 0x00, 0x00
_080ABDEC: .4byte 0x02039B84
_080ABDF0:
	ldr r0, _080ABE10 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080ABE14
	adds r0, r1, #0x0
	bl _080AC140
	str r0, [r6, #0x04]
	str r0, [r6, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, #0xDD
	movs r1, #0x02
	b _080ABEB8
	.byte 0x00, 0x00
_080ABE10: .4byte 0x02039B9C
_080ABE14:
	adds r0, r1, #0x0
	bl _080AC140
	b _080ABEBC
_080ABE1C:
	cmp r6, #0x00
	beq _080ABEBA
	add r0, sp, #0x008
	mov r1, r8
	bl func_080ABEF8
	mov r5, r8
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	bne _080ABE3E
	ldr r1, [sp, #0x008]
	str r1, [r6, #0x00]
	movs r0, #0x01
	negs r0, r0
	str r0, [r6, #0x04]
	str r1, [r6, #0x0C]
	b _080ABE60
_080ABE3E:
	mov r1, r8
	ldrb r0, [r1, #0x01]
	cmp r0, #0x01
	bne _080ABE5A
	movs r2, #0x01
	negs r2, r2
	str r2, [r6, #0x04]
	ldr r1, [sp, #0x00C]
	str r1, [r6, #0x08]
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x0C]
	str r2, [r6, #0x10]
	str r1, [r6, #0x14]
	b _080ABE66
_080ABE5A:
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x0C]
	ldr r0, [r6, #0x04]
_080ABE60:
	str r0, [r6, #0x10]
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x14]
_080ABE66:
	ldr r0, _080ABE80 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080ABE84
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	beq _080ABE90
	b _080ABEAC
_080ABE80: .4byte 0x02039B84
_080ABE84:
	ldr r0, _080ABEA4 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080ABEAC
_080ABE90:
	ldr r0, _080ABEA8 @ =0x02039DD4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r1, #0xDD
	strb r0, [r1, #0x00]
	b _080ABEBA
	.byte 0x00, 0x00
_080ABEA4: .4byte 0x02039B9C
_080ABEA8: .4byte 0x02039DD4
_080ABEAC:
	ldr r0, _080ABECC @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xD0
	ldrb r1, [r1, #0x00]
	adds r0, #0xDD
_080ABEB8:
	strb r1, [r0, #0x00]
_080ABEBA:
	movs r0, #0x91
_080ABEBC:
	add sp, #0x02C
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080ABECC: .4byte 0x02039DD4
.syntax divided
