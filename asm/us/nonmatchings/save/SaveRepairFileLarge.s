.syntax unified
	.align 2, 0
	.global SaveRepairFileLarge
	.thumb
	.thumb_func
	.type SaveRepairFileLarge, %function
SaveRepairFileLarge: @ 08009150
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	movs r7, #0x01
	negs r7, r7
	adds r6, r7, #0x0
	movs r1, #0x00
	lsls r0, r0, #0x10
	mov r9, r0
	mov r8, r9
_08009168:
	lsls r4, r1, #0x10
	asrs r5, r4, #0x10
	mov r1, r8
	asrs r0, r1, #0x10
	adds r1, r5, #0x0
	bl SaveCheckFileLargeSlot
	lsls r1, r5, #0x02
	add r1, sp
	str r0, [r1, #0x00]
	adds r2, r0, #0x0
	cmp r2, #0x02
	bne _0800918A
	cmp r7, #0x00
	bge _0800918C
	adds r7, r5, #0x0
	b _0800918C
_0800918A:
	adds r6, r5, #0x0
_0800918C:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r4, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _08009168
	cmp r7, #0x00
	blt _08009202
	cmp r6, #0x00
	blt _08009202
	ldr r4, _08009214 @ =0x00000F14
	adds r0, r4, #0x0
	bl EwramAlloc
	adds r6, r0, #0x0
	mov r0, r9
	asrs r1, r0, #0x10
	ldr r0, _08009218 @ =0x00001E28
	adds r5, r1, #0x0
	muls r5, r0
	adds r0, r7, #0x0
	muls r0, r4
	ldr r1, _0800921C @ =0x0E002F20
	adds r0, r0, r1
	adds r0, r5, r0
	adds r1, r6, #0x0
	adds r2, r6, #0x0
	adds r3, r4, #0x0
	bl SaveVerifyBlock
	movs r1, #0x00
	adds r7, r4, #0x0
_080091CE:
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	lsls r0, r4, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _080091EE
	adds r1, r4, #0x0
	muls r1, r7
	ldr r0, _0800921C @ =0x0E002F20
	adds r1, r1, r0
	adds r1, r5, r1
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl WriteAndVerifySramFast
_080091EE:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x01
	ble _080091CE
	adds r0, r6, #0x0
	bl EwramFree
	movs r2, #0x02
_08009202:
	adds r0, r2, #0x0
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08009214: .4byte 0x00000F14
_08009218: .4byte 0x00001E28
_0800921C: .4byte 0x0E002F20
.syntax divided
