.syntax unified
	.align 2, 0
	.global SaveRepairFileSmall
	.thumb
	.thumb_func
	.type SaveRepairFileSmall, %function
SaveRepairFileSmall: @ 080094EC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	movs r6, #0x01
	negs r6, r6
	adds r7, r6, #0x0
	movs r1, #0x00
	lsls r0, r0, #0x10
	mov r9, r0
	mov r8, r9
_08009504:
	lsls r4, r1, #0x10
	asrs r5, r4, #0x10
	mov r1, r8
	asrs r0, r1, #0x10
	adds r1, r5, #0x0
	bl SaveCheckFileSmallSlot
	lsls r1, r5, #0x02
	add r1, sp
	str r0, [r1, #0x00]
	adds r2, r0, #0x0
	cmp r2, #0x02
	bne _08009526
	cmp r6, #0x00
	bge _08009528
	adds r6, r5, #0x0
	b _08009528
_08009526:
	adds r7, r5, #0x0
_08009528:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08009504
	cmp r6, #0x00
	blt _080095B2
	cmp r7, #0x00
	blt _080095B2
	movs r5, #0x83
	lsls r5, r5, #0x03
	adds r0, r5, #0x0
	bl EwramAlloc
	adds r7, r0, #0x0
	mov r1, r9
	asrs r0, r1, #0x10
	lsls r4, r0, #0x05
	adds r4, r4, r0
	lsls r4, r4, #0x02
	subs r4, r4, r0
	lsls r4, r4, #0x04
	lsls r0, r6, #0x05
	adds r0, r0, r6
	lsls r0, r0, #0x02
	subs r0, r0, r6
	lsls r0, r0, #0x03
	ldr r1, _080095C4 @ =0x0E001EC0
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r7, #0x0
	adds r2, r7, #0x0
	adds r3, r5, #0x0
	bl SaveVerifyBlock
	movs r1, #0x00
	adds r5, r4, #0x0
_08009576:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _0800959E
	lsls r1, r4, #0x05
	adds r1, r1, r4
	lsls r1, r1, #0x02
	subs r1, r1, r4
	lsls r1, r1, #0x03
	ldr r0, _080095C4 @ =0x0E001EC0
	adds r1, r1, r0
	adds r1, r5, r1
	adds r0, r7, #0x0
	movs r2, #0x83
	lsls r2, r2, #0x03
	bl WriteAndVerifySramFast
_0800959E:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08009576
	adds r0, r7, #0x0
	bl EwramFree
	movs r2, #0x02
_080095B2:
	adds r0, r2, #0x0
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080095C4: .4byte 0x0E001EC0
.syntax divided
