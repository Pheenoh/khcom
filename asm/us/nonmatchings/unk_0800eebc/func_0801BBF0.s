.syntax unified
	.align 2, 0
	.global func_0801BBF0
	.thumb
	.thumb_func
	.type func_0801BBF0, %function
func_0801BBF0: @ 0801BBF0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x020
	adds r7, r0, #0x0
	ldr r0, _0801BC94 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _0801BC86
	bl func_08085BAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0801BC86
	ldr r5, _0801BC98 @ =0x02039B84
	ldr r0, [r5, #0x00]
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x04
	movs r0, #0x00
	adds r1, r4, #0x0
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _0801BC86
	movs r2, #0x01
	movs r0, #0x00
	adds r1, r4, #0x0
	ands r1, r2
	adds r2, r1, #0x0
	orrs r2, r0
	mov r8, r2
	cmp r2, #0x00
	bne _0801BC86
	bl func_080856DC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0801BC86
	bl GetActiveDeckIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_08085B38
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bls _0801BC86
	ldr r0, [r5, #0x00]
	ldr r5, [r0, #0x68]
	ldr r6, [r0, #0x6C]
	adds r1, r5, #0x0
	ldr r3, _0801BC9C @ =0x00000000
	ldr r4, _0801BCA0 @ =0x00000001
	adds r2, r6, #0x0
	orrs r2, r4
	str r1, [r0, #0x68]
	str r2, [r0, #0x6C]
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	ldr r1, [r7, #0x08]
	str r1, [sp, #0x004]
	ldr r1, [r7, #0x0C]
	str r1, [sp, #0x008]
	mov r1, sp
	mov r2, r8
	strh r2, [r1, #0x14]
	adds r0, #0x2C
	ldr r1, _0801BCA4 @ =0x09EDAF30
	mov r2, sp
	bl TaskCreate
_0801BC86:
	add sp, #0x020
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801BC94: .4byte 0x02039BB0
_0801BC98: .4byte 0x02039B84
_0801BC9C: .4byte 0x00000000
_0801BCA0: .4byte 0x00000001
_0801BCA4: .4byte 0x09EDAF30
.syntax divided
