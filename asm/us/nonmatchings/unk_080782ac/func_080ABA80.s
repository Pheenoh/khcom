.syntax unified
	.align 2, 0
	.global func_080ABA80
	.thumb
	.thumb_func
	.type func_080ABA80, %function
func_080ABA80: @ 080ABA80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x028
	adds r6, r0, #0x0
	add r1, sp, #0x004
	ldr r0, _080ABB48 @ =0x09045188
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	add r5, sp, #0x024
	movs r0, #0x00
	strb r0, [r5, #0x00]
	add r4, sp, #0x01C
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x06
	bl _0811F090
	movs r7, #0x00
	ldr r0, _080ABB4C @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xD0
	mov r12, r5
	mov r8, r4
	ldrb r4, [r1, #0x00]
	cmp r7, r4
	bcs _080ABAE8
	adds r5, r0, #0x0
	adds r4, r1, #0x0
_080ABAC0:
	lsls r2, r7, #0x02
	mov r1, sp
	adds r1, r1, r2
	adds r1, #0x04
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x48]
	ldrh r0, [r3, #0x28]
	str r0, [r1, #0x00]
	cmp r6, #0x00
	beq _080ABADC
	adds r1, r2, r6
	ldr r0, [r3, #0x24]
	str r0, [r1, #0x00]
_080ABADC:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r4, #0x00]
	cmp r7, r0
	bcc _080ABAC0
_080ABAE8:
	ldr r7, _080ABB4C @ =0x02039DD4
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xD0
	ldrb r1, [r2, #0x00]
	adds r4, r7, #0x0
	cmp r1, #0x01
	bne _080ABB62
	adds r0, #0xDD
	strb r1, [r0, #0x00]
	ldr r0, _080ABB50 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080ABB58
	ldr r0, _080ABB54 @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080ABB58
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r1, r0
	cmp r1, #0x00
	bne _080ABB58
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xEE
	ldrb r0, [r2, #0x00]
	cmp r0, #0x01
	beq _080ABB42
	movs r5, #0xE4
	lsls r5, r5, #0x01
	adds r0, r3, r5
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x1D
	ble _080ABB58
_080ABB42:
	strb r1, [r2, #0x00]
	movs r0, #0x2E
	b _080ABC94
_080ABB48: .4byte 0x09045188
_080ABB4C: .4byte 0x02039DD4
_080ABB50: .4byte 0x02039BB0
_080ABB54: .4byte 0x02039B84
_080ABB58:
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x24]
	b _080ABC94
_080ABB62:
	cmp r1, #0x00
	bne _080ABB70
	adds r0, #0xDD
	strb r1, [r0, #0x00]
	movs r0, #0x01
	negs r0, r0
	b _080ABC94
_080ABB70:
	ldrb r1, [r2, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xC2
	ldrb r2, [r2, #0x00]
	mov r4, r12
	str r4, [sp, #0x000]
	add r3, sp, #0x004
	bl func_080AC5E8
	adds r1, r0, #0x0
	cmp r1, #0x6A
	beq _080ABBF4
	cmp r1, #0x6C
	bne _080ABB98
	ldr r0, [r7, #0x00]
	adds r0, #0xDD
	movs r1, #0x01
	strb r1, [r0, #0x00]
	movs r0, #0x2E
	b _080ABC94
_080ABB98:
	ldr r0, _080ABBC4 @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080ABBC8
	adds r0, r2, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080ABBEC
	adds r0, r1, #0x0
	bl _080AC140
	str r0, [r6, #0x04]
	str r0, [r6, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, #0xDD
	movs r1, #0x02
	b _080ABC90
	.byte 0x00, 0x00
_080ABBC4: .4byte 0x02039B84
_080ABBC8:
	ldr r0, _080ABBE8 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080ABBEC
	adds r0, r1, #0x0
	bl _080AC140
	str r0, [r6, #0x04]
	str r0, [r6, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, #0xDD
	movs r1, #0x02
	b _080ABC90
	.byte 0x00, 0x00
_080ABBE8: .4byte 0x02039B9C
_080ABBEC:
	adds r0, r1, #0x0
	bl _080AC140
	b _080ABC94
_080ABBF4:
	cmp r6, #0x00
	beq _080ABC92
	add r0, sp, #0x004
	mov r1, r8
	bl func_080ABEF8
	mov r5, r8
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	bne _080ABC16
	ldr r1, [sp, #0x004]
	str r1, [r6, #0x00]
	movs r0, #0x01
	negs r0, r0
	str r0, [r6, #0x04]
	str r1, [r6, #0x0C]
	b _080ABC38
_080ABC16:
	mov r1, r8
	ldrb r0, [r1, #0x01]
	cmp r0, #0x01
	bne _080ABC32
	movs r2, #0x01
	negs r2, r2
	str r2, [r6, #0x04]
	ldr r1, [sp, #0x008]
	str r1, [r6, #0x08]
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x0C]
	str r2, [r6, #0x10]
	str r1, [r6, #0x14]
	b _080ABC3E
_080ABC32:
	ldr r0, [r6, #0x00]
	str r0, [r6, #0x0C]
	ldr r0, [r6, #0x04]
_080ABC38:
	str r0, [r6, #0x10]
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x14]
_080ABC3E:
	ldr r0, _080ABC58 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080ABC5C
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	beq _080ABC68
	b _080ABC84
_080ABC58: .4byte 0x02039B84
_080ABC5C:
	ldr r0, _080ABC7C @ =0x02039B9C
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080ABC84
_080ABC68:
	ldr r0, _080ABC80 @ =0x02039DD4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r1, #0xDD
	strb r0, [r1, #0x00]
	b _080ABC92
	.byte 0x00, 0x00
_080ABC7C: .4byte 0x02039B9C
_080ABC80: .4byte 0x02039DD4
_080ABC84:
	ldr r0, _080ABCA0 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xD0
	ldrb r1, [r1, #0x00]
	adds r0, #0xDD
_080ABC90:
	strb r1, [r0, #0x00]
_080ABC92:
	movs r0, #0x91
_080ABC94:
	add sp, #0x028
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080ABCA0: .4byte 0x02039DD4
.syntax divided
