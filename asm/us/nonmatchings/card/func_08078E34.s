.syntax unified
	.align 2, 0
	.global func_08078E34
	.thumb
	.thumb_func
	.type func_08078E34, %function
func_08078E34: @ 08078E34
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r10, r2
	movs r0, #0x79
	bl m4aSongNumStart
	ldr r7, _08078E88 @ =0x02034A98
	ldr r1, [r7, #0x00]
	ldr r0, [r1, #0x78]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
	str r0, [r1, #0x78]
	adds r1, #0x44
	ldrh r1, [r1, #0x00]
	mov r9, r1
	lsls r0, r6, #0x04
	adds r0, #0x54
	adds r0, r5, r0
	bl func_08000C8C
	adds r2, r0, #0x0
	add r4, sp, #0x010
	cmp r2, #0x00
	beq _08078EAA
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _08078E8C
	str r2, [r7, #0x00]
	b _08078EAA
_08078E88: .4byte 0x02034A98
_08078E8C:
	adds r0, r2, #0x0
	adds r0, #0x64
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _08078EAA
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _08078E8C
	ldr r0, _08078F30 @ =0x02034A98
	str r2, [r0, #0x00]
_08078EAA:
	ldr r0, _08078F30 @ =0x02034A98
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	ldr r2, _08078F34 @ =0x00000804
	orrs r0, r2
	str r0, [r1, #0x78]
	adds r1, #0x44
	movs r0, #0x00
	ldsh r7, [r1, r0]
	subs r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r4, #0x0
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _08078EDA
	lsls r0, r6, #0x01
	adds r1, r5, #0x0
	adds r1, #0xA8
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r2, #0x00]
_08078EDA:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	adds r2, r4, #0x0
	bl func_08076750
	adds r3, r0, #0x0
	lsls r1, r6, #0x04
	mov r8, r1
	cmp r3, #0x00
	beq _08078F7C
	movs r2, #0x00
	ldsh r1, [r4, r2]
	cmp r1, r7
	beq _08078F7C
	mov r2, r9
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	beq _08078F7C
	mov r0, r8
	adds r0, #0x54
	adds r0, r5, r0
	str r0, [sp, #0x000]
	mov r1, sp
	ldrh r0, [r4, #0x00]
	strh r0, [r1, #0x0C]
	mov r0, sp
	strb r6, [r0, #0x0E]
	str r3, [sp, #0x004]
	mov r2, sp
	lsls r1, r6, #0x01
	adds r0, r5, #0x0
	adds r0, #0x9C
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	strb r0, [r2, #0x0F]
	ldr r1, [r3, #0x00]
	ldr r0, _08078F38 @ =0x0000FFFE
	cmp r1, r0
	bne _08078F40
	ldr r1, _08078F3C @ =0x09EE499C
	adds r0, r5, #0x0
	b _08078F46
_08078F30: .4byte 0x02034A98
_08078F34: .4byte 0x00000804
_08078F38: .4byte 0x0000FFFE
_08078F3C: .4byte 0x09EE499C
_08078F40:
	ldr r1, _08078FEC @ =0x09EE496C
	adds r0, r5, #0x0
	mov r2, sp
_08078F46:
	bl TaskCreate
	ldr r3, [r0, #0x04]
	adds r1, r3, #0x0
	adds r1, #0x80
	ldr r0, _08078FF0 @ =0x09033FA8
	ldr r0, [r0, #0x0C]
	str r0, [r3, #0x7C]
	str r0, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0x98
	adds r1, #0x14
	ldr r0, _08078FF4 @ =0x09033FB8
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r0, [r2, #0x00]
	adds r1, #0x10
	movs r0, #0x03
	strb r0, [r1, #0x00]
	subs r1, #0x04
	movs r0, #0x3C
	strb r0, [r1, #0x00]
	ldr r0, [r3, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x04
	orrs r0, r1
	str r0, [r3, #0x78]
_08078F7C:
	mov r0, r8
	adds r0, #0x54
	adds r0, r5, r0
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _08078FD0
	movs r5, #0x00
	ldr r4, _08078FF0 @ =0x09033FA8
_08078F90:
	adds r3, r2, #0x0
	adds r3, #0xA4
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x03
	ble _08078FA4
	strb r5, [r3, #0x00]
_08078FA4:
	adds r1, r2, #0x0
	adds r1, #0xA0
	ldrb r0, [r1, #0x00]
	adds r0, #0x04
	strb r0, [r1, #0x00]
	subs r1, #0x20
	movs r0, #0x00
	ldsb r0, [r3, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x9C
	mov r1, r10
	strh r1, [r0, #0x00]
	subs r0, #0x38
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _08078F90
_08078FD0:
	ldr r0, _08078FF8 @ =0x02034A98
	ldr r0, [r0, #0x00]
	adds r0, #0xA0
	movs r1, #0x32
	strb r1, [r0, #0x00]
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08078FEC: .4byte 0x09EE496C
_08078FF0: .4byte 0x09033FA8
_08078FF4: .4byte 0x09033FB8
_08078FF8: .4byte 0x02034A98
.syntax divided
