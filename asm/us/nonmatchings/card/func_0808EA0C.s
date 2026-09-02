.syntax unified
	.align 2, 0
	.global func_0808EA0C
	.thumb
	.thumb_func
	.type func_0808EA0C, %function
func_0808EA0C: @ 0808EA0C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r9, r1
	movs r1, #0x8C
	lsls r1, r1, #0x04
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	bl GetDeck
	str r0, [sp, #0x010]
	movs r4, #0x00
	ldr r2, _0808EA84 @ =0x000008AC
	adds r0, r7, r2
	ldrb r1, [r0, #0x00]
	movs r0, #0x04
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r0, r9
	cmp r0, #0x00
	beq _0808EA46
	b _0808EB60
_0808EA46:
	mov r8, r4
	mov r5, sp
	movs r1, #0x00
	mov r10, r1
_0808EA4E:
	mov r2, r8
	lsls r0, r2, #0x01
	ldr r1, [sp, #0x010]
	adds r3, r0, r1
	ldrh r1, [r3, #0x00]
	ldr r0, _0808EA88 @ =0x0000FFFF
	cmp r1, r0
	beq _0808EB04
	mov r2, r9
	cmp r2, #0x00
	bne _0808EA94
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r7, r1
	str r0, [sp, #0x000]
	ldr r1, _0808EA8C @ =0x0203A080
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	ldr r2, _0808EA90 @ =0x00008FFF
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x04]
	lsls r4, r4, #0x18
	b _0808EAD0
	.byte 0x00, 0x00
_0808EA84: .4byte 0x000008AC
_0808EA88: .4byte 0x0000FFFF
_0808EA8C: .4byte 0x0203A080
_0808EA90: .4byte 0x00008FFF
_0808EA94:
	ldr r1, _0808EAF0 @ =0x0203A080
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x01
	adds r2, r0, r1
	ldrh r0, [r2, #0x00]
	mov r12, r0
	ldr r1, _0808EAF4 @ =0x00000FFF
	adds r0, r1, #0x0
	mov r1, r12
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	ldr r1, _0808EAF8 @ =0x08F70AB0
	adds r0, r0, r1
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	mov r0, r9
	subs r0, #0x01
	lsls r4, r4, #0x18
	cmp r1, r0
	bne _0808EB32
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r7, r1
	str r0, [sp, #0x000]
	ldrh r0, [r2, #0x00]
	ldr r2, _0808EAFC @ =0x00008FFF
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x04]
_0808EAD0:
	asrs r0, r4, #0x18
	strh r0, [r5, #0x06]
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	mov r0, r10
	strb r0, [r5, #0x0A]
	str r3, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r7, r1
	ldr r1, _0808EB00 @ =0x09EE4B28
	mov r2, sp
	bl TaskCreate
	b _0808EB32
_0808EAF0: .4byte 0x0203A080
_0808EAF4: .4byte 0x00000FFF
_0808EAF8: .4byte 0x08F70AB0
_0808EAFC: .4byte 0x00008FFF
_0808EB00: .4byte 0x09EE4B28
_0808EB04:
	movs r2, #0xFE
	lsls r2, r2, #0x03
	adds r0, r7, r2
	str r0, [sp, #0x000]
	ldrh r0, [r5, #0x04]
	orrs r1, r0
	strh r1, [r5, #0x04]
	lsls r4, r4, #0x18
	asrs r0, r4, #0x18
	strh r0, [r5, #0x06]
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	mov r0, r10
	strb r0, [r5, #0x0A]
	str r3, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r7, r1
	ldr r1, _0808EB5C @ =0x09EE4B28
	mov r2, sp
	bl TaskCreate
_0808EB32:
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r0, r4, r2
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _0808EB48
	movs r4, #0x00
	lsls r0, r6, #0x18
	adds r0, r0, r2
	lsrs r6, r0, #0x18
_0808EB48:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x62
	bhi _0808EB58
	b _0808EA4E
_0808EB58:
	b _0808EBFA
	.byte 0x00, 0x00
_0808EB5C: .4byte 0x09EE4B28
_0808EB60:
	movs r0, #0x00
	mov r8, r0
	mov r5, sp
	movs r1, #0x00
	mov r10, r1
_0808EB6A:
	mov r2, r8
	lsls r0, r2, #0x01
	ldr r1, [sp, #0x010]
	adds r3, r0, r1
	ldrh r0, [r3, #0x00]
	ldr r2, _0808EC0C @ =0x0000FFFF
	cmp r0, r2
	beq _0808EBD8
	ldr r1, _0808EC10 @ =0x0203A080
	lsls r0, r0, #0x01
	adds r2, r0, r1
	ldrh r0, [r2, #0x00]
	mov r12, r0
	ldr r1, _0808EC14 @ =0x00000FFF
	adds r0, r1, #0x0
	mov r1, r12
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	ldr r1, _0808EC18 @ =0x08F70AB0
	adds r0, r0, r1
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	mov r0, r9
	subs r0, #0x01
	cmp r1, r0
	bne _0808EBD8
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r7, r1
	str r0, [sp, #0x000]
	ldrh r0, [r2, #0x00]
	ldr r2, _0808EC1C @ =0x00008FFF
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x04]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	mov r0, r10
	strb r0, [r5, #0x0A]
	str r3, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r7, r1
	ldr r1, _0808EC20 @ =0x09EE4B28
	mov r2, sp
	bl TaskCreate
	adds r4, #0x01
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
_0808EBD8:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _0808EBEC
	movs r4, #0x00
	lsls r0, r6, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r0, r0, r2
	lsrs r6, r0, #0x18
_0808EBEC:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0x62
	bls _0808EB6A
_0808EBFA:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808EC0C: .4byte 0x0000FFFF
_0808EC10: .4byte 0x0203A080
_0808EC14: .4byte 0x00000FFF
_0808EC18: .4byte 0x08F70AB0
_0808EC1C: .4byte 0x00008FFF
_0808EC20: .4byte 0x09EE4B28
.syntax divided
