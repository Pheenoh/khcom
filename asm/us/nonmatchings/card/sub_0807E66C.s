.syntax unified
	.align 2, 0
	.global sub_0807E66C
	.thumb
	.thumb_func
	.type sub_0807E66C, %function
sub_0807E66C:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	movs r2, #0x00
	cmp r2, r0
	bge _0807E712
	ldr r3, _0807E6AC @ =0x0000FFFF
	mov r10, r3
	ldr r3, _0807E6B0 @ =0x08F70AB0
	mov r8, r3
	ldr r3, _0807E6B4 @ =0x00000FFF
	mov r9, r3
	adds r3, r1, #0x0
	movs r1, #0x34
	mov r12, r1
	movs r7, #0x00
	adds r5, r0, #0x0
_0807E69C:
	ldrh r1, [r3, #0x00]
	cmp r1, r10
	beq _0807E70A
	cmp r4, #0x00
	beq _0807E6B8
	cmp r4, #0x03
	beq _0807E6DC
	b _0807E70A
_0807E6AC: .4byte 0x0000FFFF
_0807E6B0: .4byte 0x08F70AB0
_0807E6B4: .4byte 0x00000FFF
_0807E6B8:
	mov r0, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r1, #0x0
	add r0, r8
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _0807E70A
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r6
	strb r4, [r0, #0x06]
	strb r4, [r0, #0x07]
	strb r4, [r0, #0x0A]
	b _0807E6FE
_0807E6DC:
	mov r0, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r1, #0x0
	add r0, r8
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0807E70A
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r0, r0, r6
	strb r7, [r0, #0x06]
	strb r7, [r0, #0x07]
	strb r7, [r0, #0x0A]
_0807E6FE:
	ldrh r1, [r3, #0x00]
	str r1, [r0, #0x00]
	strh r2, [r0, #0x04]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
_0807E70A:
	adds r3, #0x02
	subs r5, #0x01
	cmp r5, #0x00
	bne _0807E69C
_0807E712:
	adds r0, r2, #0x0
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
