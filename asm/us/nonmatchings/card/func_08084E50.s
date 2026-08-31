.syntax unified
	.align 2, 0
	.global func_08084E50
	.thumb
	.thumb_func
	.type func_08084E50, %function
func_08084E50: @ 08084E50
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	movs r3, #0x00
	mov r10, r3
	cmp r2, #0x01
	bne _08084E9E
	cmp r1, #0x01
	beq _08084E8E
	cmp r1, #0x01
	bgt _08084E82
	cmp r1, #0x00
	beq _08084E88
	b _08084EA4
_08084E82:
	cmp r0, #0x02
	beq _08084E96
	b _08084EA4
_08084E88:
	movs r0, #0x80
	lsls r0, r0, #0x05
	b _08084EA2
_08084E8E:
	movs r1, #0x80
	lsls r1, r1, #0x06
	mov r10, r1
	b _08084EA4
_08084E96:
	movs r3, #0x80
	lsls r3, r3, #0x07
	mov r10, r3
	b _08084EA4
_08084E9E:
	movs r0, #0xE0
	lsls r0, r0, #0x07
_08084EA2:
	mov r10, r0
_08084EA4:
	movs r7, #0x00
	movs r1, #0x00
	mov r9, r1
	cmp r9, r8
	bcs _08084EE2
_08084EAE:
	lsls r0, r7, #0x05
	adds r4, r0, r6
	ldrh r2, [r4, #0x16]
	adds r5, r0, #0x0
	cmp r2, #0x00
	beq _08084ED0
	adds r0, r2, #0x0
	lsls r0, r0, #0x01
	bl EwramAlloc
	str r0, [r4, #0x1C]
	mov r0, r9
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	b _08084ED2
_08084ED0:
	str r2, [r4, #0x1C]
_08084ED2:
	adds r1, r5, r6
	movs r0, #0x00
	strh r0, [r1, #0x18]
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, r8
	bcc _08084EAE
_08084EE2:
	movs r7, #0x00
	ldr r0, _08084F2C @ =0x0203A858
	mov r8, r0
	ldrh r3, [r0, #0x00]
	cmp r7, r3
	bcs _08084F98
	ldr r4, _08084F30 @ =0x00000FFF
	ldr r5, _08084F34 @ =0x08F70AB0
	ldr r0, _08084F38 @ =0x0203A080
	mov r12, r0
_08084EF6:
	lsls r0, r7, #0x01
	add r0, r12
	ldrh r2, [r0, #0x00]
	cmp r2, r4
	beq _08084F8A
	mov r0, r10
	ands r0, r2
	cmp r0, #0x00
	bne _08084F8A
	movs r0, #0x80
	lsls r0, r0, #0x08
	ands r0, r2
	cmp r0, #0x00
	bne _08084F40
	adds r1, r4, #0x0
	ands r1, r2
	movs r0, #0x34
	muls r0, r1
	adds r3, r0, r5
	ldrh r2, [r3, #0x1C]
	ldr r0, _08084F3C @ =0x000001C1
	cmp r1, r0
	bls _08084F64
	lsls r2, r2, #0x05
	adds r1, r2, r6
	b _08084F72
	.byte 0x00, 0x00
_08084F2C: .4byte 0x0203A858
_08084F30: .4byte 0x00000FFF
_08084F34: .4byte 0x08F70AB0
_08084F38: .4byte 0x0203A080
_08084F3C: .4byte 0x000001C1
_08084F40:
	adds r1, r4, #0x0
	ands r1, r2
	movs r0, #0x34
	muls r0, r1
	adds r3, r0, r5
	ldrh r0, [r3, #0x1C]
	adds r0, #0x8F
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _08084F60 @ =0x000001C1
	cmp r1, r0
	bls _08084F64
	lsls r2, r2, #0x05
	adds r1, r2, r6
	b _08084F72
	.byte 0x00, 0x00
_08084F60: .4byte 0x000001C1
_08084F64:
	lsls r2, r2, #0x05
	adds r1, r2, r6
	adds r0, r3, #0x0
	adds r0, #0x20
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r1, r1, r0
_08084F72:
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	adds r2, r2, r6
	ldrh r0, [r2, #0x18]
	adds r1, r0, #0x1
	strh r1, [r2, #0x18]
	lsls r0, r0, #0x10
	ldr r1, [r2, #0x1C]
	lsrs r0, r0, #0x0F
	adds r0, r0, r1
	strh r7, [r0, #0x00]
_08084F8A:
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r1, r8
	ldrh r1, [r1, #0x00]
	cmp r7, r1
	bcc _08084EF6
_08084F98:
	mov r0, r9
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
