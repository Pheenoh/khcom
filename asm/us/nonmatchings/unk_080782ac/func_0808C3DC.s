.syntax unified
	.align 2, 0
	.global func_0808C3DC
	.thumb
	.thumb_func
	.type func_0808C3DC, %function
func_0808C3DC: @ 0808C3DC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r9, r1
	movs r1, #0x8C
	lsls r1, r1, #0x04
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	bl func_08085758
	str r0, [sp, #0x010]
	movs r4, #0x00
	mov r8, r4
	mov r2, r9
	cmp r2, #0x00
	beq _0808C40A
	b _0808C520
_0808C40A:
	movs r7, #0x00
	mov r5, sp
	movs r0, #0x00
	mov r10, r0
_0808C412:
	lsls r0, r7, #0x01
	ldr r1, [sp, #0x010]
	adds r3, r0, r1
	ldrh r1, [r3, #0x00]
	ldr r0, _0808C444 @ =0x0000FFFF
	cmp r1, r0
	beq _0808C4C4
	mov r2, r9
	cmp r2, #0x00
	bne _0808C450
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r6, r1
	str r0, [sp, #0x000]
	ldr r1, _0808C448 @ =0x0203A080
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	ldr r2, _0808C44C @ =0x00008FFF
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x04]
	lsls r4, r4, #0x18
	b _0808C48C
_0808C444: .4byte 0x0000FFFF
_0808C448: .4byte 0x0203A080
_0808C44C: .4byte 0x00008FFF
_0808C450:
	ldr r1, _0808C4B0 @ =0x0203A080
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x01
	adds r2, r0, r1
	ldrh r0, [r2, #0x00]
	mov r12, r0
	ldr r1, _0808C4B4 @ =0x00000FFF
	adds r0, r1, #0x0
	mov r1, r12
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	ldr r1, _0808C4B8 @ =0x08F70AB0
	adds r0, r0, r1
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	mov r0, r9
	subs r0, #0x01
	lsls r4, r4, #0x18
	cmp r1, r0
	bne _0808C4F4
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r6, r1
	str r0, [sp, #0x000]
	ldrh r0, [r2, #0x00]
	ldr r2, _0808C4BC @ =0x00008FFF
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x04]
_0808C48C:
	asrs r0, r4, #0x18
	strh r0, [r5, #0x06]
	mov r1, r8
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	mov r2, r10
	strb r2, [r5, #0x0A]
	str r3, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldr r1, _0808C4C0 @ =0x09EE4B28
	mov r2, sp
	bl func_08000E14
	b _0808C4F4
	.byte 0x00, 0x00
_0808C4B0: .4byte 0x0203A080
_0808C4B4: .4byte 0x00000FFF
_0808C4B8: .4byte 0x08F70AB0
_0808C4BC: .4byte 0x00008FFF
_0808C4C0: .4byte 0x09EE4B28
_0808C4C4:
	movs r2, #0xFE
	lsls r2, r2, #0x03
	adds r0, r6, r2
	str r0, [sp, #0x000]
	ldrh r0, [r5, #0x04]
	orrs r1, r0
	strh r1, [r5, #0x04]
	lsls r4, r4, #0x18
	asrs r0, r4, #0x18
	strh r0, [r5, #0x06]
	mov r1, r8
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	mov r2, r10
	strb r2, [r5, #0x0A]
	str r3, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldr r1, _0808C51C @ =0x09EE4B28
	mov r2, sp
	bl func_08000E14
_0808C4F4:
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r0, r4, r2
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _0808C50E
	movs r4, #0x00
	mov r1, r8
	lsls r0, r1, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	mov r8, r0
_0808C50E:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0x62
	bhi _0808C51A
	b _0808C412
_0808C51A:
	b _0808C5B8
_0808C51C: .4byte 0x09EE4B28
_0808C520:
	movs r7, #0x00
	mov r5, sp
	movs r2, #0x00
	mov r10, r2
_0808C528:
	lsls r0, r7, #0x01
	ldr r1, [sp, #0x010]
	adds r3, r0, r1
	ldrh r0, [r3, #0x00]
	ldr r2, _0808C5F0 @ =0x0000FFFF
	cmp r0, r2
	beq _0808C596
	ldr r1, _0808C5F4 @ =0x0203A080
	lsls r0, r0, #0x01
	adds r2, r0, r1
	ldrh r0, [r2, #0x00]
	mov r12, r0
	ldr r1, _0808C5F8 @ =0x00000FFF
	adds r0, r1, #0x0
	mov r1, r12
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	ldr r1, _0808C5FC @ =0x08F70AB0
	adds r0, r0, r1
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	mov r0, r9
	subs r0, #0x01
	cmp r1, r0
	bne _0808C596
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r6, r1
	str r0, [sp, #0x000]
	ldrh r0, [r2, #0x00]
	ldr r2, _0808C600 @ =0x00008FFF
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x04]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r1, r8
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	mov r2, r10
	strb r2, [r5, #0x0A]
	str r3, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldr r1, _0808C604 @ =0x09EE4B28
	mov r2, sp
	bl func_08000E14
	adds r4, #0x01
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
_0808C596:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _0808C5AE
	movs r4, #0x00
	mov r2, r8
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	mov r8, r0
_0808C5AE:
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0x62
	bls _0808C528
_0808C5B8:
	movs r2, #0x85
	lsls r2, r2, #0x04
	adds r1, r6, r2
	movs r0, #0x90
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	ldr r0, _0808C608 @ =0x00000854
	adds r1, r6, r0
	movs r0, #0xA0
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	adds r2, #0x5C
	adds r1, r6, r2
	movs r0, #0x04
	strh r0, [r1, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x63
	bl func_0808C940
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808C5F0: .4byte 0x0000FFFF
_0808C5F4: .4byte 0x0203A080
_0808C5F8: .4byte 0x00000FFF
_0808C5FC: .4byte 0x08F70AB0
_0808C600: .4byte 0x00008FFF
_0808C604: .4byte 0x09EE4B28
_0808C608: .4byte 0x00000854
.syntax divided
