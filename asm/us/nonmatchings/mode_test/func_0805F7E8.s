.syntax unified
	.align 2, 0
	.global func_0805F7E8
	.thumb
	.thumb_func
	.type func_0805F7E8, %function
func_0805F7E8: @ 0805F7E8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r4, r2, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x000]
	movs r5, #0x00
	ldrb r0, [r4, #0x00]
	ldr r1, _0805F840 @ =0x02034A20
	mov r12, r1
	ldr r2, _0805F844 @ =0x02034A1C
	mov r8, r2
	cmp r0, #0x00
	beq _0805F894
	movs r3, #0xFF
	lsls r3, r3, #0x08
	mov r10, r3
	mov r7, r12
	mov r6, r8
_0805F81C:
	ldrh r3, [r4, #0x00]
	lsrs r0, r3, #0x08
	lsls r1, r3, #0x08
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, r3, #0x0
	mov r0, r10
	ands r1, r0
	movs r0, #0x81
	lsls r0, r0, #0x08
	cmp r1, r0
	beq _0805F848
	movs r0, #0x82
	lsls r0, r0, #0x08
	cmp r1, r0
	beq _0805F864
	b _0805F882
_0805F840: .4byte 0x02034A20
_0805F844: .4byte 0x02034A1C
_0805F848:
	ldrb r1, [r7, #0x00]
	ldr r2, [r6, #0x00]
	lsls r0, r1, #0x05
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	lsls r1, r5, #0x01
	adds r0, r0, r1
	ldr r2, _0805F860 @ =0x00007EC0
	adds r1, r3, r2
	b _0805F880
	.byte 0x00, 0x00
_0805F860: .4byte 0x00007EC0
_0805F864:
	ldrb r1, [r7, #0x00]
	ldr r2, [r6, #0x00]
	lsls r0, r1, #0x05
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	lsls r1, r5, #0x01
	adds r0, r0, r1
	ldr r2, _0805F8EC @ =0x00007DC0
	adds r1, r3, r2
	movs r3, #0x80
	lsls r3, r3, #0x03
	adds r2, r3, #0x0
	orrs r1, r2
_0805F880:
	strh r1, [r0, #0x00]
_0805F882:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r4, #0x02
	cmp r5, #0x3B
	bhi _0805F894
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _0805F81C
_0805F894:
	mov r0, r12
	ldrb r1, [r0, #0x00]
	mov r3, r8
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x05
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	adds r0, #0x7A
	mov r1, r9
	strb r1, [r0, #0x00]
	mov r2, r12
	ldrb r1, [r2, #0x00]
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x05
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	adds r0, #0x7B
	mov r3, sp
	ldrb r3, [r3, #0x00]
	strb r3, [r0, #0x00]
	mov r0, r12
	ldrb r1, [r0, #0x00]
	mov r3, r8
	ldr r2, [r3, #0x00]
	lsls r0, r1, #0x05
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	adds r0, #0x7D
	strb r5, [r0, #0x00]
	mov r1, r12
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0805F8EC: .4byte 0x00007DC0
.syntax divided
