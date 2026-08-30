.syntax unified
	.align 2, 0
	.global func_080FB930
	.thumb
	.thumb_func
	.type func_080FB930, %function
func_080FB930: @ 080FB930
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldrb r0, [r7, #0x1C]
	cmp r0, #0x00
	beq _080FB9FE
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl func_080FB908
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl func_080FB8E8
	ldr r4, _080FBA10 @ =0x09992108
	movs r0, #0x4C
	adds r3, r5, #0x0
	muls r3, r0
	adds r2, r3, r4
	ldrh r1, [r2, #0x00]
	movs r5, #0xBC
	lsls r5, r5, #0x01
	adds r0, r7, r5
	strh r1, [r0, #0x00]
	ldrh r0, [r2, #0x02]
	movs r2, #0xBD
	lsls r2, r2, #0x01
	adds r1, r7, r2
	strh r0, [r1, #0x00]
	movs r5, #0x00
	mov r8, r5
	mov r9, r4
	mov r0, r9
	adds r0, #0x24
	adds r0, r3, r0
	str r0, [sp, #0x004]
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r5, r7, r0
	mov r0, r9
	adds r0, #0x1C
	adds r4, r3, r0
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r1, r7, r1
	str r1, [sp, #0x000]
	adds r2, #0x06
	adds r2, r2, r7
	mov r10, r2
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r6, r7, r0
_080FB9A4:
	mov r0, r9
	adds r0, #0x2C
	adds r0, r3, r0
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x04]
	ldr r1, [r6, #0x00]
	ldr r0, [r4, #0x08]
	cmp r1, r0
	beq _080FB9E0
	mov r1, r8
	cmp r1, #0x00
	bne _080FB9E0
	ldr r0, [sp, #0x004]
	ldr r2, [r0, #0x00]
	mov r1, r10
	str r2, [r1, #0x00]
	movs r1, #0xBE
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x00C]
	ldr r0, [sp, #0x000]
	ldr r0, [r0, #0x00]
	mov r12, r0
	ldr r0, [sp, #0x00C]
	mov r1, r12
	str r3, [sp, #0x008]
	bl func_080038E4
	ldr r3, [sp, #0x008]
_080FB9E0:
	ldrh r0, [r4, #0x00]
	strh r0, [r5, #0x00]
	ldrh r0, [r4, #0x02]
	strh r0, [r5, #0x02]
	ldrh r0, [r4, #0x04]
	strh r0, [r5, #0x04]
	adds r5, #0x14
	adds r4, #0x14
	adds r3, #0x14
	adds r6, #0x14
	movs r1, #0x01
	add r8, r1
	mov r2, r8
	cmp r2, #0x01
	ble _080FB9A4
_080FB9FE:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FBA10: .4byte 0x09992108
.syntax divided
