.syntax unified
	.align 2, 0
	.global func_08080EB4
	.thumb
	.thumb_func
	.type func_08080EB4, %function
func_08080EB4: @ 08080EB4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	adds r0, #0xBA
	ldrb r5, [r0, #0x00]
	movs r0, #0x00
	mov r9, r0
	add r1, sp, #0x008
	ldr r0, _08080FE8 @ =0x090352FC
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r1, _08080FEC @ =0x02039DD4
	ldr r3, [r1, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xC2
	movs r2, #0x00
	ldsh r0, [r0, r2]
	mov r8, r1
	cmp r0, r5
	ble _08080EEE
	cmp r5, #0x00
	beq _08080EEE
	b _080811FA
_08080EEE:
	movs r2, #0x00
	ldr r0, _08080FF0 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	mov r10, r0
	cmp r1, #0x02
	bne _08080F16
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08080F16
	adds r0, r3, #0x0
	adds r0, #0xE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08080F16
	movs r2, #0x01
_08080F16:
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _08080F3C
	mov r4, r8
	ldr r1, [r4, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #0x24]
	cmp r0, #0x16
	bne _08080F3C
	adds r0, r1, #0x0
	adds r0, #0xE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08080F3C
	movs r2, #0x01
_08080F3C:
	mov r1, r10
	ldr r0, [r1, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x1D
	bne _08080F64
	mov r3, r8
	ldr r1, [r3, #0x00]
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _08080F64
	adds r0, r1, #0x0
	adds r0, #0xE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08080F64
	movs r2, #0x01
_08080F64:
	cmp r2, #0x00
	beq _08080F6A
	b _080811FA
_08080F6A:
	movs r3, #0x00
	mov r4, r8
	ldr r0, [r4, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcs _08080F9A
	mov r6, r8
	movs r4, #0x80
	lsls r4, r4, #0x0E
_08080F7E:
	ldr r2, [r6, #0x00]
	lsls r0, r3, #0x02
	adds r0, r2, r0
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	orrs r0, r4
	str r0, [r1, #0x78]
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r2, #0xD0
	ldrb r2, [r2, #0x00]
	cmp r3, r2
	bcc _08080F7E
_08080F9A:
	mov r0, r10
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08080FF4 @ =0x00800000
	ldr r3, _08080FF8 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xC2
	movs r2, #0x00
	ldsh r0, [r1, r2]
	cmp r0, r5
	bne _08080FBE
	b _080811B4
_08080FBE:
	cmp r5, #0x00
	bne _08080FFC
	ldrb r0, [r1, #0x00]
	negs r0, r0
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r6, r0, r2
	movs r1, #0x00
	ldsb r1, [r6, r1]
	movs r0, #0x09
	negs r0, r0
	cmp r1, r0
	bge _0808101C
	movs r0, #0xF7
	strb r0, [r6, #0x00]
	b _0808101C
	.byte 0x00, 0x00
_08080FE8: .4byte 0x090352FC
_08080FEC: .4byte 0x02039DD4
_08080FF0: .4byte 0x02039B84
_08080FF4: .4byte 0x00800000
_08080FF8: .4byte 0x00000000
_08080FFC:
	ldrb r0, [r1, #0x00]
	subs r0, r0, r5
	movs r2, #0xE5
	lsls r2, r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	mov r4, r10
	ldr r0, [r4, #0x00]
	adds r6, r0, r2
	movs r0, #0x00
	ldsb r0, [r6, r0]
	movs r1, #0x09
	negs r1, r1
	cmp r0, r1
	bge _0808101C
	strb r1, [r6, #0x00]
_0808101C:
	bl func_0807BA54
	ldr r0, _0808108C @ =0x02039B84
	mov r8, r0
	ldr r6, [r0, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _08081090 @ =0x00000400
	ldr r3, _08081094 @ =0x00000000
	orrs r0, r2
	ldr r4, _08081098 @ =0x10000000
	ldr r5, _0808109C @ =0x00000000
	adds r2, r0, #0x0
	orrs r2, r4
	adds r3, r1, #0x0
	movs r0, #0x80
	movs r1, #0x00
	adds r4, r2, #0x0
	orrs r4, r0
	adds r5, r3, #0x0
	movs r2, #0x21
	negs r2, r2
	adds r0, r4, #0x0
	ands r0, r2
	adds r1, r5, #0x0
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	adds r0, r7, #0x0
	bl func_08080268
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _080810A0
	adds r4, r7, #0x0
	adds r4, #0x28
	adds r5, r7, #0x0
	adds r5, #0xB9
	ldrb r1, [r5, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xBA
	ldrb r2, [r0, #0x00]
	add r0, sp, #0x020
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	add r3, sp, #0x008
	bl func_080AC5E8
	b _080810C0
_0808108C: .4byte 0x02039B84
_08081090: .4byte 0x00000400
_08081094: .4byte 0x00000000
_08081098: .4byte 0x10000000
_0808109C: .4byte 0x00000000
_080810A0:
	adds r4, r7, #0x0
	adds r4, #0x28
	adds r5, r7, #0x0
	adds r5, #0xB9
	ldrb r1, [r5, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xBA
	ldrb r2, [r0, #0x00]
	add r0, sp, #0x020
	str r0, [sp, #0x000]
	movs r0, #0x01
	str r0, [sp, #0x004]
	adds r0, r4, #0x0
	add r3, sp, #0x008
	bl func_080AD144
_080810C0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080811A8 @ =0x02039DD4
	mov r8, r2
	ldr r3, _080811AC @ =0x02039B84
	mov r10, r3
	cmp r0, #0x34
	bne _08081112
	movs r3, #0x00
	ldr r0, [r2, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcs _08081112
	mov r6, r8
_080810DE:
	ldr r0, [r6, #0x00]
	lsls r2, r3, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x3C]
	ldrb r0, [r1, #0x08]
	cmp r0, #0x01
	bne _08081102
	strb r0, [r1, #0x0A]
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, r0, r2
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #0x78]
_08081102:
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, [r6, #0x00]
	adds r0, #0xD0
	ldrb r0, [r0, #0x00]
	cmp r3, r0
	bcc _080810DE
_08081112:
	movs r3, #0x00
	ldrb r0, [r5, #0x00]
	cmp r3, r0
	bcs _0808113A
	adds r2, r4, #0x0
	adds r1, r0, #0x0
_0808111E:
	lsls r0, r3, #0x02
	adds r0, r2, r0
	ldr r0, [r0, #0x00]
	adds r0, #0xA5
	ldrb r0, [r0, #0x00]
	add r0, r9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r1
	bcc _0808111E
_0808113A:
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xC2
	mov r3, r9
	strh r3, [r1, #0x00]
	ldrb r1, [r5, #0x00]
	adds r0, #0xD0
	strb r1, [r0, #0x00]
	movs r3, #0x00
	ldrb r0, [r5, #0x00]
	cmp r3, r0
	bcs _0808118C
_08081154:
	mov r1, r8
	ldr r2, [r1, #0x00]
	lsls r1, r3, #0x02
	adds r2, r2, r1
	adds r1, r4, r1
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	ldr r2, [r1, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x06
	orrs r0, r1
	str r0, [r2, #0x78]
	ldr r0, [r2, #0x48]
	ldrh r1, [r0, #0x1E]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08081180
	ldr r1, [r2, #0x3C]
	movs r0, #0x01
	strb r0, [r1, #0x0A]
_08081180:
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r2, [r5, #0x00]
	cmp r3, r2
	bcc _08081154
_0808118C:
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, #0xA4
	movs r1, #0x00
	strb r1, [r0, #0x00]
	mov r4, r8
	ldr r0, [r4, #0x00]
	adds r0, #0xE2
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _080811B0 @ =0x00000213
	bl m4aSongNumStart
	b _080811FA
_080811A8: .4byte 0x02039DD4
_080811AC: .4byte 0x02039B84
_080811B0: .4byte 0x00000213
_080811B4:
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r5, #0x00
	strb r5, [r0, #0x00]
	adds r0, r7, #0x0
	bl func_08080268
	movs r0, #0xCC
	bl m4aSongNumStart
	mov r2, r10
	ldr r6, [r2, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	ldr r2, _0808120C @ =0xFFFFFBFF
	ands r0, r2
	movs r4, #0x21
	negs r4, r4
	adds r2, r0, #0x0
	ands r2, r4
	adds r3, r1, #0x0
	subs r4, #0x60
	adds r0, r2, #0x0
	ands r0, r4
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	mov r3, r8
	ldr r0, [r3, #0x00]
	adds r0, #0xE2
	strb r5, [r0, #0x00]
	mov r4, r10
	ldr r0, [r4, #0x00]
	adds r0, #0xA4
	strb r5, [r0, #0x00]
_080811FA:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808120C: .4byte 0xFFFFFBFF
.syntax divided
