.syntax unified
	.align 2, 0
	.global func_080D44D4
	.thumb
	.thumb_func
	.type func_080D44D4, %function
func_080D44D4: @ 080D44D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	movs r7, #0x00
	ldr r5, _080D4534 @ =0x096FDC30
_080D44E6:
	lsls r0, r7, #0x02
	mov r8, r0
	ldrh r1, [r5, #0x00]
	ldrh r2, [r6, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldrh r0, [r5, #0x02]
	ldrh r2, [r6, #0x02]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r1, #0x10
	orrs r4, r0
	adds r0, r4, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xFF
	beq _080D451E
	ldr r0, _080D4538 @ =0x096FDC40
	add r0, r8
	ldrb r1, [r0, #0x00]
	adds r0, r2, #0x0
	bl func_080D3AB8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4526
_080D451E:
	adds r5, #0x04
	adds r7, #0x01
	cmp r7, #0x03
	ble _080D44E6
_080D4526:
	cmp r7, #0x04
	bne _080D453C
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x00
	b _080D4558
_080D4534: .4byte 0x096FDC30
_080D4538: .4byte 0x096FDC40
_080D453C:
	ldrb r0, [r6, #0x04]
	ldr r2, _080D464C @ =0x096FDC40
	lsls r1, r7, #0x02
	adds r1, r1, r2
	ldrb r1, [r1, #0x00]
	bl func_080E8C84
	bl func_080E8D00
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r1, r6, r2
_080D4558:
	strh r0, [r1, #0x00]
	movs r7, #0x00
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r6, r1
	adds r2, r6, #0x0
	adds r2, #0xF0
	str r2, [sp, #0x000]
	movs r1, #0xF8
	adds r1, r1, r6
	mov r10, r1
	movs r2, #0xF4
	adds r2, r2, r6
	mov r9, r2
	ldrh r0, [r0, #0x00]
	cmp r7, r0
	bge _080D460A
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r8, r0
_080D4582:
	movs r0, #0x34
	adds r5, r7, #0x0
	muls r5, r0
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r4, r6, r4
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl func_080E8D1C
	adds r1, r0, #0x0
	adds r0, r4, #0x0
	bl func_08098014
	mov r1, r8
	ldrh r0, [r1, #0x00]
	adds r1, r7, #0x0
	bl func_080D44A0
	movs r1, #0xD0
	lsls r1, r1, #0x07
	adds r2, r4, #0x0
	bl func_08098598
	adds r0, r6, #0x0
	adds r0, #0x28
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D45CC
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D45CC:
	adds r0, r6, #0x0
	adds r0, #0x2C
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D45E6
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D45E6:
	adds r0, r6, #0x0
	adds r0, #0x30
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D4600
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D4600:
	adds r7, #0x01
	mov r2, r8
	ldrh r2, [r2, #0x00]
	cmp r7, r2
	blt _080D4582
_080D460A:
	ldr r0, _080D4650 @ =0x0976B340
	movs r1, #0x90
	lsls r1, r1, #0x06
	bl func_080026A4
	ldr r1, [sp, #0x000]
	str r0, [r1, #0x00]
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4634
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bne _080D465C
_080D4634:
	ldr r0, _080D4654 @ =0x09EF6424
	ldr r0, [r0, #0x04]
	mov r2, r10
	str r0, [r2, #0x00]
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r2, _080D4658 @ =0x0984A118
	movs r1, #0x0F
	movs r3, #0x20
	bl func_0800388C
	b _080D4672
_080D464C: .4byte 0x096FDC40
_080D4650: .4byte 0x0976B340
_080D4654: .4byte 0x09EF6424
_080D4658: .4byte 0x0984A118
_080D465C:
	ldr r0, _080D4694 @ =0x09EF6424
	ldr r0, [r0, #0x00]
	mov r2, r10
	str r0, [r2, #0x00]
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r2, _080D4698 @ =0x0984A0F8
	movs r1, #0x0F
	movs r3, #0x20
	bl func_0800388C
_080D4672:
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D4694: .4byte 0x09EF6424
_080D4698: .4byte 0x0984A0F8
.syntax divided
