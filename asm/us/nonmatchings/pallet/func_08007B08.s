.syntax unified
	.align 2, 0
	.global func_08007B08
	.thumb
	.thumb_func
	.type func_08007B08, %function
func_08007B08: @ 08007B08
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	str r0, [sp, #0x00C]
	mov r10, r1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	str r0, [sp, #0x010]
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	movs r0, #0xFB
	lsls r0, r0, #0x18
	add r0, r10
	asrs r0, r0, #0x01
	mov r8, r0
	lsrs r2, r2, #0x11
	mov r9, r2
	movs r7, #0x00
	cmp r7, r9
	bcs _08007C00
	add r4, sp, #0x008
	movs r1, #0x1F
	mov r12, r1
	add r3, sp, #0x004
	mov r5, sp
_08007B40:
	lsls r0, r7, #0x01
	ldr r1, [sp, #0x00C]
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	mov r0, r12
	ands r0, r1
	strh r0, [r4, #0x00]
	movs r0, #0xF8
	lsls r0, r0, #0x02
	ands r0, r1
	lsrs r0, r0, #0x05
	strh r0, [r3, #0x00]
	movs r0, #0xF8
	lsls r0, r0, #0x07
	ands r0, r1
	lsrs r0, r0, #0x0A
	strh r0, [r5, #0x00]
	mov r0, r12
	strh r0, [r4, #0x02]
	strh r0, [r3, #0x02]
	strh r0, [r5, #0x02]
	ldrh r0, [r5, #0x00]
	cmp r0, #0x1F
	bcs _08007B80
	ldrh r0, [r5, #0x02]
	ldrh r1, [r5, #0x00]
	subs r0, r0, r1
	muls r0, r6
	asrs r0, r0, #0x05
	adds r1, r1, r0
	strh r1, [r5, #0x00]
	b _08007B8E
_08007B80:
	ldrh r0, [r5, #0x00]
	ldrh r1, [r5, #0x02]
	subs r1, r0, r1
	muls r1, r6
	asrs r1, r1, #0x05
	subs r0, r0, r1
	strh r0, [r5, #0x00]
_08007B8E:
	ldrh r1, [r3, #0x02]
	ldrh r0, [r3, #0x00]
	cmp r0, r1
	bcs _08007BA6
	ldrh r0, [r3, #0x02]
	ldrh r1, [r3, #0x00]
	subs r0, r0, r1
	muls r0, r6
	asrs r0, r0, #0x05
	adds r1, r1, r0
	strh r1, [r3, #0x00]
	b _08007BB4
_08007BA6:
	ldrh r0, [r3, #0x00]
	ldrh r1, [r3, #0x02]
	subs r1, r0, r1
	muls r1, r6
	asrs r1, r1, #0x05
	subs r0, r0, r1
	strh r0, [r3, #0x00]
_08007BB4:
	ldrh r1, [r4, #0x02]
	ldrh r0, [r4, #0x00]
	cmp r0, r1
	bcs _08007BCC
	ldrh r0, [r4, #0x02]
	ldrh r1, [r4, #0x00]
	subs r0, r0, r1
	muls r0, r6
	asrs r0, r0, #0x05
	adds r1, r1, r0
	strh r1, [r4, #0x00]
	b _08007BDA
_08007BCC:
	ldrh r0, [r4, #0x00]
	ldrh r1, [r4, #0x02]
	subs r1, r0, r1
	muls r1, r6
	asrs r1, r1, #0x05
	subs r0, r0, r1
	strh r0, [r4, #0x00]
_08007BDA:
	ldr r1, _08007C20 @ =0x0300756C
	ldr r2, [r1, #0x00]
	mov r1, r8
	adds r0, r7, r1
	lsls r0, r0, #0x01
	adds r2, r2, r0
	ldrh r1, [r5, #0x00]
	lsls r1, r1, #0x0A
	ldrh r0, [r3, #0x00]
	lsls r0, r0, #0x05
	orrs r1, r0
	ldrh r0, [r4, #0x00]
	orrs r1, r0
	strh r1, [r2, #0x00]
	adds r0, r7, #0x1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, r9
	bcc _08007B40
_08007C00:
	mov r0, r8
	cmp r0, #0x00
	bne _08007C24
	ldr r0, _08007C20 @ =0x0300756C
	ldr r0, [r0, #0x00]
	adds r0, #0x02
	mov r1, r10
	adds r1, #0x02
	ldr r2, [sp, #0x010]
	subs r2, #0x02
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl RequestDma3Copy
	movs r4, #0x00
	b _08007C36
_08007C20: .4byte 0x0300756C
_08007C24:
	ldr r0, _08007C4C @ =0x0300756C
	mov r1, r8
	lsls r4, r1, #0x01
	ldr r0, [r0, #0x00]
	adds r0, r0, r4
	mov r1, r10
	ldr r2, [sp, #0x010]
	bl RequestDma3Copy
_08007C36:
	ldr r0, _08007C4C @ =0x0300756C
	ldr r0, [r0, #0x00]
	adds r0, r0, r4
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08007C4C: .4byte 0x0300756C
.syntax divided
