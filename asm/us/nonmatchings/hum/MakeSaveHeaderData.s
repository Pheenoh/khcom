.syntax unified
	.align 2, 0
	.global MakeSaveHeaderData
	.thumb
	.thumb_func
	.type MakeSaveHeaderData, %function
MakeSaveHeaderData: @ 08059DDC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r5, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x00]
	ldr r1, _08059E2C @ =0x02039BB0
	ldr r0, [r1, #0x08]
	movs r3, #0x20
	ands r0, r3
	cmp r0, #0x00
	beq _08059E04
	movs r0, #0x01
	strh r0, [r4, #0x00]
_08059E04:
	ldr r2, [r1, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x04
	ands r0, r2
	cmp r0, #0x00
	beq _08059E3C
	ldrh r0, [r4, #0x00]
	movs r1, #0x04
	orrs r1, r0
	orrs r1, r5
	strh r1, [r4, #0x00]
	movs r0, #0x08
	ands r2, r0
	cmp r2, #0x00
	beq _08059E30
	movs r0, #0x02
	orrs r1, r0
	strh r1, [r4, #0x00]
	b _08059E4A
	.byte 0x00, 0x00
_08059E2C: .4byte 0x02039BB0
_08059E30:
	ldr r0, _08059E38 @ =0x0000FFFD
	ands r1, r0
	strh r1, [r4, #0x00]
	b _08059E4A
_08059E38: .4byte 0x0000FFFD
_08059E3C:
	ands r2, r3
	cmp r2, #0x00
	beq _08059E4A
	ldrh r0, [r4, #0x00]
	movs r1, #0x02
	orrs r0, r1
	strh r0, [r4, #0x00]
_08059E4A:
	movs r1, #0x00
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	lsls r0, r0, #0x03
	adds r6, r4, r0
	ldr r5, _08059E8C @ =0x02039BB0
	movs r2, #0x08
	adds r2, r2, r4
	mov r12, r2
	add r0, r12
	mov r9, r0
	movs r7, #0xE0
	lsls r7, r7, #0x01
	adds r7, r7, r5
	mov r10, r7
_08059E6A:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	str r0, [sp, #0x000]
	cmp r8, r1
	bne _08059E98
	ldrb r0, [r5, #0x0E]
	strb r0, [r6, #0x04]
	ldrb r0, [r5, #0x0C]
	strb r0, [r6, #0x05]
	ldr r1, _08059E90 @ =0x02039CB8
	ldrb r0, [r1, #0x00]
	strb r0, [r6, #0x06]
	ldr r2, _08059E94 @ =0x02039D8C
	ldr r0, [r2, #0x00]
	mov r7, r9
	str r0, [r7, #0x00]
	b _08059EC2
_08059E8C: .4byte 0x02039BB0
_08059E90: .4byte 0x02039CB8
_08059E94: .4byte 0x02039D8C
_08059E98:
	lsls r1, r1, #0x03
	adds r2, r4, r1
	adds r3, r1, r5
	movs r7, #0xDE
	lsls r7, r7, #0x01
	adds r0, r3, r7
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x04]
	adds r7, #0x01
	adds r0, r3, r7
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x05]
	adds r7, #0x01
	adds r0, r3, r7
	ldrb r0, [r0, #0x00]
	strb r0, [r2, #0x06]
	mov r0, r12
	adds r2, r0, r1
	add r1, r10
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
_08059EC2:
	ldr r1, [sp, #0x000]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _08059E6A
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
