.syntax unified
	.align 2, 0
	.global func_08084D78
	.thumb
	.thumb_func
	.type func_08084D78, %function
func_08084D78: @ 08084D78
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r7, #0x00
	cmp r2, #0x01
	bne _08084DBA
	cmp r1, #0x01
	beq _08084DAE
	cmp r1, #0x01
	bgt _08084DA2
	cmp r1, #0x00
	beq _08084DA8
	b _08084DBE
_08084DA2:
	cmp r0, #0x02
	beq _08084DB4
	b _08084DBE
_08084DA8:
	movs r7, #0x80
	lsls r7, r7, #0x05
	b _08084DBE
_08084DAE:
	movs r7, #0x80
	lsls r7, r7, #0x06
	b _08084DBE
_08084DB4:
	movs r7, #0x80
	lsls r7, r7, #0x07
	b _08084DBE
_08084DBA:
	movs r7, #0xE0
	lsls r7, r7, #0x07
_08084DBE:
	movs r2, #0x00
	ldr r0, _08084E08 @ =0x0203A858
	ldrh r0, [r0, #0x00]
	cmp r2, r0
	bcs _08084E40
	ldr r3, _08084E0C @ =0x00000FFF
	movs r1, #0x80
	lsls r1, r1, #0x08
	mov r9, r1
	ldr r6, _08084E10 @ =0x08F70AB0
	mov r10, r6
	ldr r1, _08084E14 @ =0x0203A080
	mov r8, r1
	movs r5, #0x34
	mov r12, r0
_08084DDC:
	lsls r0, r2, #0x01
	add r0, r8
	ldrh r1, [r0, #0x00]
	cmp r1, r3
	beq _08084E36
	adds r0, r7, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _08084E36
	mov r0, r9
	ands r0, r1
	cmp r0, #0x00
	bne _08084E18
	adds r0, r3, #0x0
	ands r0, r1
	muls r0, r5
	add r0, r10
	ldrh r0, [r0, #0x1C]
	lsls r1, r0, #0x05
	adds r1, r1, r4
	b _08084E2E
	.byte 0x00, 0x00
_08084E08: .4byte 0x0203A858
_08084E0C: .4byte 0x00000FFF
_08084E10: .4byte 0x08F70AB0
_08084E14: .4byte 0x0203A080
_08084E18:
	adds r0, r3, #0x0
	ands r0, r1
	muls r0, r5
	add r0, r10
	ldrh r0, [r0, #0x1C]
	lsls r1, r0, #0x05
	adds r1, r1, r4
	movs r6, #0x8F
	lsls r6, r6, #0x05
	adds r1, r1, r6
	adds r0, #0x8F
_08084E2E:
	strh r0, [r1, #0x14]
	ldrh r0, [r1, #0x16]
	adds r0, #0x01
	strh r0, [r1, #0x16]
_08084E36:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r12
	bcc _08084DDC
_08084E40:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
