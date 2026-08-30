.syntax unified
	.align 2, 0
	.global func_080E826C
	.thumb
	.thumb_func
	.type func_080E826C, %function
func_080E826C: @ 080E826C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	ldr r0, _080E8360 @ =0x02034F78
	ldrb r5, [r0, #0x00]
	cmp r5, #0x0F
	bgt _080E834E
	ldr r1, _080E8364 @ =0x02034F7A
	mov r10, r1
	mov r8, r0
	ldr r2, _080E8368 @ =0x02034F79
	mov r9, r2
_080E828A:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl _080E6634
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080E836C @ =0x09856FB4
	adds r4, r1, r0
	ldrb r0, [r4, #0x14]
	ldr r1, [r4, #0x04]
	bl func_080E7DB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x010]
	cmp r0, #0x00
	beq _080E82C4
	ldrh r0, [r4, #0x08]
	lsrs r0, r0, #0x05
	mov r3, r10
	ldrh r3, [r3, #0x00]
	adds r0, r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x02
	cmp r0, r1
	bgt _080E8348
_080E82C4:
	ldr r0, [r4, #0x00]
	bl func_080E7D80
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	beq _080E82DA
	mov r7, r9
	ldrb r0, [r7, #0x00]
	cmp r0, #0x05
	bhi _080E8348
_080E82DA:
	ldrb r1, [r4, #0x15]
	mov r0, sp
	bl func_080E7D64
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E8348
	mov r0, r8
	ldrb r1, [r0, #0x00]
	ldr r0, _080E8370 @ =0x0203C7B8
	ldr r2, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	movs r1, #0x00
	strh r1, [r0, #0x00]
	mov r3, r8
	ldrb r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r2
	str r4, [r0, #0x14]
	ldrb r0, [r3, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	adds r1, #0x04
	mov r0, sp
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r7, r8
	ldrb r0, [r7, #0x00]
	adds r0, #0x01
	strb r0, [r7, #0x00]
	ldr r0, [sp, #0x010]
	cmp r0, #0x00
	beq _080E833C
	ldrh r0, [r4, #0x08]
	lsrs r0, r0, #0x05
	mov r1, r10
	ldrh r1, [r1, #0x00]
	adds r0, r0, r1
	mov r2, r10
	strh r0, [r2, #0x00]
_080E833C:
	cmp r6, #0x00
	beq _080E8348
	mov r3, r9
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	strb r0, [r3, #0x00]
_080E8348:
	adds r5, #0x01
	cmp r5, #0x0F
	ble _080E828A
_080E834E:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E8360: .4byte 0x02034F78
_080E8364: .4byte 0x02034F7A
_080E8368: .4byte 0x02034F79
_080E836C: .4byte 0x09856FB4
_080E8370: .4byte 0x0203C7B8
.syntax divided
