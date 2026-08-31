.syntax unified
	.align 2, 0
	.global func_0800C980
	.thumb
	.thumb_func
	.type func_0800C980, %function
func_0800C980: @ 0800C980
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r7, r0, #0x0
	ldr r0, [sp, #0x048]
	ldr r4, [sp, #0x04C]
	ldr r5, [sp, #0x050]
	ldr r6, [sp, #0x058]
	mov r8, r6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r9, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r10, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x00C]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r12, r0
	str r0, [sp, #0x010]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x014]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	str r5, [sp, #0x018]
	ldr r1, [sp, #0x054]
	lsls r6, r1, #0x10
	lsrs r6, r6, #0x10
	str r6, [sp, #0x01C]
	mov r2, r8
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	movs r3, #0x3C
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0x00
	str r4, [sp, #0x020]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r4, r7, r0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _0800C9F2
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r2, r7, r3
	ldrh r1, [r2, #0x00]
	ldr r0, _0800CA3C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2, #0x00]
_0800C9F2:
	ldrh r3, [r4, #0x00]
	movs r0, #0x00
	ldsh r1, [r4, r0]
	mov r2, r9
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bge _0800CA04
	b _0800CB2E
_0800CA04:
	adds r4, r1, #0x0
	mov r1, r10
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, r0
	cmp r4, r1
	blt _0800CA14
	b _0800CB18
_0800CA14:
	subs r0, r1, r3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r2, r8
	ldr r5, [r2, #0x18]
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x74]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800CA40
	mov r3, r12
	lsls r0, r3, #0x10
	asrs r0, r0, #0x08
	mov r2, r8
	ldr r1, [r2, #0x14]
	subs r1, r1, r0
	b _0800CA4C
_0800CA3C: .4byte 0x0000FFFB
_0800CA40:
	ldr r3, [sp, #0x010]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x08
	mov r2, r8
	ldr r1, [r2, #0x14]
	adds r1, r1, r0
_0800CA4C:
	mov r0, r8
	adds r0, #0xE8
	ldr r0, [r0, #0x00]
	cmp r0, #0x05
	beq _0800CA6C
	mov r0, r8
	adds r0, #0x04
	adds r2, r4, #0x0
	bl func_0800592C
	mov r0, r8
	adds r0, #0x08
	adds r1, r5, #0x0
	adds r2, r4, #0x0
	bl func_0800592C
_0800CA6C:
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r5, r7, r3
	ldrh r1, [r5, #0x00]
	movs r4, #0x04
	mov r9, r4
	movs r2, #0x04
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _0800CB2E
	mov r3, r8
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800CAD4
	ldr r4, [sp, #0x018]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x08
	ldr r1, [r3, #0x04]
	subs r1, r1, r0
	ldr r2, [r3, #0x08]
	ldr r3, [sp, #0x01C]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x08
	mov r4, r8
	ldr r3, [r4, #0x0C]
	adds r3, r3, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsrs r4, r6, #0x01
	str r4, [sp, #0x004]
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x044]
	bl func_08011F78
	cmp r0, #0x00
	beq _0800CB2E
	ldr r0, [sp, #0x014]
	bl m4aSongNumStart
	ldrh r0, [r5, #0x00]
	mov r6, r9
	orrs r0, r6
	strh r0, [r5, #0x00]
	movs r0, #0x01
	str r0, [sp, #0x020]
	b _0800CB2E
_0800CAD4:
	ldr r1, [sp, #0x018]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x08
	mov r2, r8
	ldr r1, [r2, #0x04]
	adds r1, r1, r0
	ldr r2, [r2, #0x08]
	ldr r3, [sp, #0x01C]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x08
	mov r4, r8
	ldr r3, [r4, #0x0C]
	adds r3, r3, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsrs r4, r6, #0x01
	str r4, [sp, #0x004]
	str r0, [sp, #0x008]
	ldr r0, [sp, #0x044]
	bl func_08011F78
	cmp r0, #0x00
	beq _0800CB2E
	ldr r0, [sp, #0x014]
	bl m4aSongNumStart
	movs r6, #0x01
	str r6, [sp, #0x020]
	ldrh r0, [r5, #0x00]
	mov r1, r9
	orrs r0, r1
	strh r0, [r5, #0x00]
	b _0800CB2E
_0800CB18:
	ldr r2, [sp, #0x00C]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r0, r1, r0
	cmp r4, r0
	ble _0800CB2E
	adds r0, r7, #0x0
	bl func_0800CB4C
	movs r0, #0x02
	b _0800CB3C
_0800CB2E:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	strh r1, [r0, #0x00]
	ldr r0, [sp, #0x020]
_0800CB3C:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
