.syntax unified
	.align 2, 0
	.global func_0808C60C
	.thumb
	.thumb_func
	.type func_0808C60C, %function
func_0808C60C: @ 0808C60C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x010]
	lsls r2, r2, #0x18
	movs r3, #0x00
	mov r10, r3
	mov r9, r3
	cmp r2, #0x00
	beq _0808C62E
	b _0808C748
_0808C62E:
	mov r8, r3
	ldr r1, _0808C688 @ =0x00000898
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	cmp r9, r0
	bcc _0808C63C
	b _0808C86E
_0808C63C:
	mov r5, sp
_0808C63E:
	ldr r2, [sp, #0x010]
	cmp r2, #0x05
	bne _0808C690
	ldr r4, _0808C68C @ =0x000004D4
	adds r0, r6, r4
	ldr r1, [r0, #0x00]
	mov r7, r8
	lsls r0, r7, #0x05
	adds r1, r0, r1
	ldrh r0, [r1, #0x16]
	cmp r0, #0x00
	beq _0808C704
	movs r2, #0xFE
	lsls r2, r2, #0x03
	adds r0, r6, r2
	str r0, [sp, #0x000]
	ldrh r0, [r1, #0x14]
	str r3, [sp, #0x014]
	bl func_0808C8D0
	strh r0, [r5, #0x04]
	ldr r3, [sp, #0x014]
	lsls r4, r3, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r7, r10
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strb r0, [r5, #0x0A]
	movs r0, #0x00
	str r0, [sp, #0x00C]
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r6, r1
	b _0808C6EC
_0808C688: .4byte 0x00000898
_0808C68C: .4byte 0x000004D4
_0808C690:
	ldr r2, _0808C734 @ =0x000004D4
	adds r0, r6, r2
	ldr r1, [r0, #0x00]
	mov r4, r8
	lsls r0, r4, #0x05
	adds r1, r0, r1
	ldrh r0, [r1, #0x16]
	cmp r0, #0x00
	beq _0808C704
	movs r7, #0xFE
	lsls r7, r7, #0x03
	adds r0, r6, r7
	str r0, [sp, #0x000]
	ldrh r0, [r1, #0x14]
	str r3, [sp, #0x014]
	bl func_0808C8D0
	movs r7, #0x00
	strh r0, [r5, #0x04]
	ldr r2, _0808C738 @ =0x08F70AB0
	ldr r4, _0808C73C @ =0x00000FFF
	adds r1, r4, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r2
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	ldr r0, [sp, #0x010]
	subs r0, #0x01
	ldr r3, [sp, #0x014]
	cmp r1, r0
	bne _0808C704
	lsls r4, r3, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r1, r10
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strb r0, [r5, #0x0A]
	str r7, [sp, #0x00C]
	movs r2, #0xF9
	lsls r2, r2, #0x03
	adds r0, r6, r2
_0808C6EC:
	ldr r1, _0808C740 @ =0x09EE4B28
	mov r2, sp
	bl func_08000E14
	adds r4, #0x01
	lsls r4, r4, #0x18
	lsrs r3, r4, #0x18
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
_0808C704:
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _0808C71C
	movs r3, #0x00
	mov r4, r10
	lsls r0, r4, #0x18
	movs r7, #0x80
	lsls r7, r7, #0x11
	adds r0, r0, r7
	lsrs r0, r0, #0x18
	mov r10, r0
_0808C71C:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r1, _0808C744 @ =0x00000898
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	cmp r8, r0
	bcc _0808C63E
	b _0808C86E
	.byte 0x00, 0x00
_0808C734: .4byte 0x000004D4
_0808C738: .4byte 0x08F70AB0
_0808C73C: .4byte 0x00000FFF
_0808C740: .4byte 0x09EE4B28
_0808C744: .4byte 0x00000898
_0808C748:
	movs r2, #0x00
	mov r8, r2
	ldr r4, _0808C7AC @ =0x00000898
	adds r0, r6, r4
	ldrh r0, [r0, #0x00]
	cmp r9, r0
	bcc _0808C758
	b _0808C86E
_0808C758:
	mov r5, sp
_0808C75A:
	ldr r7, [sp, #0x010]
	cmp r7, #0x05
	bne _0808C7B4
	ldr r1, _0808C7B0 @ =0x000004D4
	adds r0, r6, r1
	ldr r1, [r0, #0x00]
	mov r2, r8
	lsls r0, r2, #0x05
	adds r1, r0, r1
	ldrh r0, [r1, #0x16]
	cmp r0, #0x00
	beq _0808C840
	ldrh r0, [r1, #0x14]
	subs r0, #0x4E
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0808C840
	movs r4, #0xFE
	lsls r4, r4, #0x03
	adds r0, r6, r4
	str r0, [sp, #0x000]
	ldrh r0, [r1, #0x14]
	str r3, [sp, #0x014]
	bl func_0808C8D0
	strh r0, [r5, #0x04]
	ldr r3, [sp, #0x014]
	lsls r4, r3, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r7, r10
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strb r0, [r5, #0x0A]
	movs r0, #0x00
	str r0, [sp, #0x00C]
	b _0808C822
	.byte 0x00, 0x00
_0808C7AC: .4byte 0x00000898
_0808C7B0: .4byte 0x000004D4
_0808C7B4:
	ldr r2, _0808C8B4 @ =0x000004D4
	adds r2, r6, r2
	str r2, [sp, #0x018]
	ldr r0, [r2, #0x00]
	mov r7, r8
	lsls r4, r7, #0x05
	adds r1, r4, r0
	ldrh r0, [r1, #0x16]
	cmp r0, #0x00
	beq _0808C840
	movs r2, #0xFE
	lsls r2, r2, #0x03
	adds r0, r6, r2
	str r0, [sp, #0x000]
	ldrh r0, [r1, #0x14]
	str r3, [sp, #0x014]
	bl func_0808C8D0
	movs r7, #0x00
	mov r12, r7
	strh r0, [r5, #0x04]
	ldr r2, _0808C8B8 @ =0x08F70AB0
	ldr r7, _0808C8BC @ =0x00000FFF
	adds r1, r7, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r2
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	ldr r0, [sp, #0x010]
	subs r0, #0x01
	ldr r3, [sp, #0x014]
	cmp r1, r0
	bne _0808C840
	ldr r1, [sp, #0x018]
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldrh r0, [r0, #0x14]
	subs r0, #0x4E
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0808C840
	lsls r4, r3, #0x18
	asrs r4, r4, #0x18
	strh r4, [r5, #0x06]
	mov r2, r10
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strb r0, [r5, #0x0A]
	mov r7, r12
	str r7, [sp, #0x00C]
_0808C822:
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r6, r1
	ldr r1, _0808C8C0 @ =0x09EE4B28
	mov r2, sp
	bl func_08000E14
	adds r4, #0x01
	lsls r4, r4, #0x18
	lsrs r3, r4, #0x18
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
_0808C840:
	lsls r0, r3, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x02
	ble _0808C858
	movs r3, #0x00
	mov r2, r10
	lsls r0, r2, #0x18
	movs r4, #0x80
	lsls r4, r4, #0x11
	adds r0, r0, r4
	lsrs r0, r0, #0x18
	mov r10, r0
_0808C858:
	mov r0, r8
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r7, _0808C8C4 @ =0x00000898
	adds r0, r6, r7
	ldrh r0, [r0, #0x00]
	cmp r8, r0
	bcs _0808C86E
	b _0808C75A
_0808C86E:
	movs r0, #0x85
	lsls r0, r0, #0x04
	adds r1, r6, r0
	movs r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldr r2, _0808C8C8 @ =0x00000854
	adds r1, r6, r2
	movs r0, #0xA0
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	ldr r4, _0808C8CC @ =0x000008AC
	adds r1, r6, r4
	movs r0, #0x04
	strh r0, [r1, #0x00]
	mov r7, r10
	lsls r0, r7, #0x18
	asrs r0, r0, #0x18
	lsls r2, r0, #0x01
	adds r2, r2, r0
	lsls r1, r3, #0x18
	asrs r1, r1, #0x18
	adds r1, r1, r2
	adds r0, r6, #0x0
	bl func_0808C940
	mov r0, r9
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0808C8B4: .4byte 0x000004D4
_0808C8B8: .4byte 0x08F70AB0
_0808C8BC: .4byte 0x00000FFF
_0808C8C0: .4byte 0x09EE4B28
_0808C8C4: .4byte 0x00000898
_0808C8C8: .4byte 0x00000854
_0808C8CC: .4byte 0x000008AC
.syntax divided
