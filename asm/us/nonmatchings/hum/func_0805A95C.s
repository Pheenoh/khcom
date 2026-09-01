.syntax unified
	.align 2, 0
	.global func_0805A95C
	.thumb
	.thumb_func
	.type func_0805A95C, %function
func_0805A95C: @ 0805A95C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	str r3, [sp, #0x004]
	ldr r3, [sp, #0x02C]
	ldr r6, [sp, #0x030]
	ldr r4, [sp, #0x034]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r9, r4
	ldr r7, _0805AA70 @ =0x02034934
	ldr r5, [r7, #0x00]
	ldr r3, _0805AA74 @ =0x00000CAE
	mov r10, r3
	adds r4, r5, #0x0
	add r4, r10
	mov r3, r8
	strh r3, [r4, #0x00]
	movs r4, #0xCB
	lsls r4, r4, #0x04
	mov r12, r4
	mov r3, r12
	adds r3, r5, r3
	strh r6, [r3, #0x00]
	adds r4, #0x02
	adds r4, r5, r4
	str r4, [sp, #0x000]
	mov r3, r9
	strh r3, [r4, #0x00]
	ldr r4, _0805AA78 @ =0x00000C76
	adds r4, r5, r4
	strh r1, [r4, #0x00]
	ldr r3, _0805AA7C @ =0x00000C78
	adds r1, r5, r3
	strh r0, [r1, #0x00]
	ldr r4, _0805AA80 @ =0x00000CB4
	adds r1, r5, r4
	str r2, [r1, #0x00]
	ldr r2, _0805AA84 @ =0x00000CB8
	adds r1, r5, r2
	ldr r3, [sp, #0x004]
	str r3, [r1, #0x00]
	adds r4, #0x08
	adds r1, r5, r4
	ldr r2, [sp, #0x028]
	str r2, [r1, #0x00]
	mov r3, r8
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	mov r8, r3
	movs r4, #0x38
	add r8, r4
	ldr r2, _0805AA88 @ =0x00000CC2
	adds r1, r5, r2
	mov r3, r8
	strh r3, [r1, #0x00]
	ldr r4, _0805AA8C @ =0x00000CC6
	adds r1, r5, r4
	strh r3, [r1, #0x00]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	adds r2, r6, #0x0
	subs r2, #0x0A
	ldr r3, _0805AA90 @ =0x00000CC4
	adds r1, r5, r3
	strh r2, [r1, #0x00]
	mov r4, r9
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r9, r4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x01
	mov r1, r9
	muls r1, r0
	adds r0, r1, #0x0
	adds r6, r6, r0
	adds r6, #0x0C
	ldr r2, _0805AA94 @ =0x00000CC8
	adds r0, r5, r2
	strh r6, [r0, #0x00]
	subs r3, #0x18
	adds r2, r5, r3
	ldrh r1, [r2, #0x00]
	ldr r0, _0805AA98 @ =0x0000FFE5
	ands r0, r1
	movs r1, #0x04
	orrs r0, r1
	strh r0, [r2, #0x00]
	movs r4, #0xC7
	lsls r4, r4, #0x04
	adds r5, r5, r4
	movs r0, #0x00
	strb r0, [r5, #0x00]
	ldr r2, [r7, #0x00]
	add r10, r2
	mov r1, r10
	ldrh r0, [r1, #0x00]
	subs r0, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	add r12, r2
	mov r3, r12
	ldrh r1, [r3, #0x00]
	subs r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r4, #0x42
	adds r2, r2, r4
	movs r3, #0x00
	ldsh r2, [r2, r3]
	bl func_0805A4D8
	bl func_0805A7D0
	ldr r0, [r7, #0x00]
	adds r4, #0x8C
	adds r0, r0, r4
	movs r1, #0x00
	strh r1, [r0, #0x00]
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0805AA70: .4byte 0x02034934
_0805AA74: .4byte 0x00000CAE
_0805AA78: .4byte 0x00000C76
_0805AA7C: .4byte 0x00000C78
_0805AA80: .4byte 0x00000CB4
_0805AA84: .4byte 0x00000CB8
_0805AA88: .4byte 0x00000CC2
_0805AA8C: .4byte 0x00000CC6
_0805AA90: .4byte 0x00000CC4
_0805AA94: .4byte 0x00000CC8
_0805AA98: .4byte 0x0000FFE5
.syntax divided
