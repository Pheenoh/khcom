.syntax unified
	.align 2, 0
	.global func_080E4B78
	.thumb
	.thumb_func
	.type func_080E4B78, %function
func_080E4B78: @ 080E4B78
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x028
	ldr r2, _080E4BC0 @ =0x02034F30
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x004]
	movs r3, #0x80
	lsls r3, r3, #0x04
	adds r3, r2, r3
	str r3, [sp, #0x008]
	movs r4, #0x80
	lsls r4, r4, #0x05
	adds r4, r2, r4
	str r4, [sp, #0x00C]
	lsls r0, r0, #0x10
	ldr r2, _080E4BC4 @ =0xFFFF0000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r1, r1, #0x10
	adds r1, r1, r2
	lsrs r0, r1, #0x10
	movs r2, #0x00
_080E4BAC:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	str r0, [sp, #0x024]
	cmp r1, #0x00
	bge _080E4BC8
	adds r0, r1, #0x0
	subs r0, #0x08
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	b _080E4BCE
_080E4BC0: .4byte 0x02034F30
_080E4BC4: .4byte 0xFFFF0000
_080E4BC8:
	ldr r3, [sp, #0x024]
	lsrs r0, r3, #0x1F
	adds r0, r1, r0
_080E4BCE:
	lsls r0, r0, #0x0F
	lsrs r0, r0, #0x10
	str r0, [sp, #0x010]
	ldr r4, [sp, #0x024]
	asrs r1, r4, #0x10
	lsrs r0, r4, #0x1F
	adds r0, r1, r0
	asrs r0, r0, #0x01
	lsls r0, r0, #0x01
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x014]
	movs r0, #0x1F
	ands r0, r1
	str r0, [sp, #0x018]
	ldr r0, [sp, #0x000]
	adds r2, #0x01
	str r2, [sp, #0x020]
	ldr r1, [sp, #0x018]
	lsls r1, r1, #0x05
	mov r10, r1
	movs r2, #0x1F
	str r2, [sp, #0x01C]
_080E4BFE:
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	mov r9, r0
	cmp r1, #0x00
	bge _080E4C16
	adds r0, r1, #0x0
	subs r0, #0x08
	cmp r0, #0x00
	bge _080E4C12
	subs r0, r1, #0x5
_080E4C12:
	lsls r0, r0, #0x0E
	b _080E4C1C
_080E4C16:
	mov r3, r9
	asrs r0, r3, #0x12
	lsls r0, r0, #0x10
_080E4C1C:
	lsrs r2, r0, #0x10
	mov r4, r9
	asrs r1, r4, #0x10
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080E4C2A
	adds r0, r1, #0x3
_080E4C2A:
	asrs r0, r0, #0x02
	lsls r0, r0, #0x02
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r5, #0x1F
	ands r5, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x010]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r7, r0, #0x0
	cmp r7, #0x00
	beq _080E4CC8
	adds r0, r5, #0x0
	mov r3, r10
	orrs r0, r3
	lsls r4, r0, #0x01
	ldr r0, [sp, #0x004]
	adds r0, r0, r4
	mov r12, r0
	ldr r1, [sp, #0x014]
	lsls r2, r1, #0x10
	lsls r3, r6, #0x10
	asrs r1, r3, #0x10
	asrs r0, r2, #0x0B
	adds r0, r0, r1
	ldr r1, [r7, #0x14]
	lsls r6, r0, #0x01
	adds r1, r6, r1
	ldrh r0, [r1, #0x00]
	mov r1, r12
	strh r0, [r1, #0x00]
	ldr r1, [r7, #0x18]
	ldr r0, [sp, #0x018]
	lsls r0, r0, #0x10
	mov r12, r0
	lsls r5, r5, #0x10
	mov r8, r2
	adds r2, r3, #0x0
	cmp r1, #0x00
	beq _080E4C8E
	ldr r3, [sp, #0x008]
	adds r0, r4, r3
	adds r1, r6, r1
	ldrh r1, [r1, #0x00]
	b _080E4C92
_080E4C8E:
	ldr r3, [sp, #0x008]
	adds r0, r4, r3
_080E4C92:
	strh r1, [r0, #0x00]
	ldr r3, [r7, #0x1C]
	cmp r3, #0x00
	beq _080E4CB6
	asrs r0, r5, #0x10
	mov r4, r12
	lsrs r1, r4, #0x0B
	adds r1, r1, r0
	lsls r1, r1, #0x01
	ldr r0, [sp, #0x00C]
	adds r1, r1, r0
	asrs r2, r2, #0x10
	mov r4, r8
	asrs r0, r4, #0x0B
	adds r0, r0, r2
	lsls r0, r0, #0x01
	adds r0, r0, r3
	b _080E4CF4
_080E4CB6:
	asrs r1, r5, #0x10
	mov r2, r12
	lsrs r0, r2, #0x0B
	adds r0, r0, r1
	lsls r0, r0, #0x01
	ldr r4, [sp, #0x00C]
	adds r0, r0, r4
	strh r3, [r0, #0x00]
	b _080E4CF8
_080E4CC8:
	mov r0, r10
	orrs r5, r0
	lsls r1, r5, #0x01
	ldr r2, [sp, #0x004]
	adds r0, r1, r2
	strh r7, [r0, #0x00]
	ldr r4, [sp, #0x008]
	adds r3, r1, r4
	ldr r0, _080E4D64 @ =0x02034F34
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x1C]
	movs r4, #0xD0
	lsls r4, r4, #0x03
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	strh r0, [r3, #0x00]
	ldr r0, [sp, #0x00C]
	adds r1, r1, r0
	ldr r0, [r2, #0x20]
	movs r2, #0x88
	lsls r2, r2, #0x02
	adds r0, r0, r2
_080E4CF4:
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
_080E4CF8:
	movs r0, #0x80
	lsls r0, r0, #0x09
	add r0, r9
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x01C]
	subs r3, #0x01
	str r3, [sp, #0x01C]
	cmp r3, #0x00
	blt _080E4D0C
	b _080E4BFE
_080E4D0C:
	ldr r4, [sp, #0x024]
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r4, r1
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x020]
	cmp r2, #0x1F
	bgt _080E4D1E
	b _080E4BAC
_080E4D1E:
	movs r0, #0x03
	bl GetBgScreenBase
	adds r1, r0, #0x0
	movs r5, #0x80
	lsls r5, r5, #0x04
	ldr r0, [sp, #0x004]
	adds r2, r5, #0x0
	bl RequestDma3Copy
	movs r0, #0x02
	bl GetBgScreenBase
	adds r1, r0, #0x0
	ldr r0, [sp, #0x008]
	adds r2, r5, #0x0
	bl RequestDma3Copy
	movs r0, #0x01
	bl GetBgScreenBase
	adds r1, r0, #0x0
	ldr r0, [sp, #0x00C]
	adds r2, r5, #0x0
	bl RequestDma3Copy
	add sp, #0x028
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E4D64: .4byte 0x02034F34
.syntax divided
