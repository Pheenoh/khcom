.syntax unified
	.align 2, 0
	.global task_wlogo_won_1
	.thumb
	.thumb_func
	.type task_wlogo_won_1, %function
task_wlogo_won_1: @ 080B5010
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r2, r5, #0x0
	adds r2, #0xF2
	ldrb r1, [r2, #0x00]
	cmp r1, #0x01
	beq _080B5054
	cmp r1, #0x01
	bgt _080B5032
	cmp r1, #0x00
	beq _080B503A
	b _080B5186
_080B5032:
	cmp r1, #0x02
	bne _080B5038
	b _080B513C
_080B5038:
	b _080B5186
_080B503A:
	ldrh r0, [r5, #0x08]
	adds r0, #0x01
	strh r0, [r5, #0x08]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bhi _080B504A
	b _080B5186
_080B504A:
	strh r1, [r5, #0x08]
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
	b _080B5186
_080B5054:
	movs r0, #0x00
	mov r8, r0
	movs r2, #0xC0
	adds r2, r2, r5
	mov r9, r2
	mov r12, r0
	ldr r4, _080B508C @ =0x09EF1744
	str r4, [sp, #0x000]
	movs r6, #0x00
	adds r3, r5, #0x0
	adds r3, #0xAC
_080B506A:
	mov r2, r9
	add r2, r8
	ldrb r1, [r2, #0x00]
	adds r4, r1, #0x0
	cmp r4, #0x00
	bne _080B5090
	ldrh r7, [r3, #0x00]
	mov r10, r7
	ldr r0, [sp, #0x000]
	ldrh r0, [r0, #0x0C]
	cmp r10, r0
	bls _080B50E8
	adds r0, r1, #0x1
	strb r0, [r2, #0x00]
	strh r4, [r3, #0x00]
	b _080B50E8
	.byte 0x00, 0x00
_080B508C: .4byte 0x09EF1744
_080B5090:
	ldrh r0, [r3, #0x00]
	ldr r4, [sp, #0x000]
	ldrh r4, [r4, #0x0E]
	cmp r0, r4
	bls _080B50A0
	adds r0, r1, #0x1
	strb r0, [r2, #0x00]
	b _080B50E8
_080B50A0:
	adds r2, r5, #0x0
	adds r2, #0x0C
	adds r2, r2, r6
	adds r0, r5, #0x0
	adds r0, #0x5C
	adds r0, r0, r6
	ldr r1, [r2, #0x00]
	ldr r0, [r0, #0x00]
	subs r1, r1, r0
	str r1, [r2, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xDE
	mov r7, r12
	adds r1, r0, r7
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	movs r4, #0x00
	strh r0, [r1, #0x00]
	ldr r2, _080B5138 @ =0x0000FFFF
	mov r10, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bls _080B50E8
	strh r4, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xCA
	adds r1, r0, r7
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	mov r7, r10
	ands r0, r7
	cmp r0, #0x13
	bls _080B50E8
	strh r4, [r1, #0x00]
_080B50E8:
	ldrh r0, [r3, #0x00]
	adds r0, #0x01
	strh r0, [r3, #0x00]
	movs r0, #0x02
	add r12, r0
	ldr r2, [sp, #0x000]
	adds r2, #0x14
	str r2, [sp, #0x000]
	adds r6, #0x04
	adds r3, #0x02
	movs r4, #0x01
	add r8, r4
	mov r7, r8
	cmp r7, #0x09
	ble _080B506A
	ldrh r0, [r5, #0x08]
	adds r0, #0x01
	strh r0, [r5, #0x08]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xE5
	bls _080B5186
	movs r0, #0x00
	strh r0, [r5, #0x08]
	adds r1, r5, #0x0
	adds r1, #0xF3
	movs r0, #0x10
	strb r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x10
	bl func_080057A0
	adds r1, r5, #0x0
	adds r1, #0xF2
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	b _080B5186
	.byte 0x00, 0x00
_080B5138: .4byte 0x0000FFFF
_080B513C:
	ldrh r0, [r5, #0x08]
	adds r0, #0x01
	strh r0, [r5, #0x08]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	adds r1, #0xF3
	cmp r0, #0x04
	bls _080B5176
	movs r0, #0x00
	strh r0, [r5, #0x08]
	ldrb r0, [r1, #0x00]
	subs r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B5176
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x00
	b _080B5188
_080B5176:
	ldrb r2, [r1, #0x00]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
_080B5186:
	movs r0, #0x01
_080B5188:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
