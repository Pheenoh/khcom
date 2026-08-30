.syntax unified
	.align 2, 0
	.global func_0805B9D0
	.thumb
	.thumb_func
	.type func_0805B9D0, %function
func_0805B9D0: @ 0805B9D0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r6, [sp, #0x01C]
	ldr r4, [sp, #0x020]
	mov r8, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r7, r8
	lsls r7, r7, #0x10
	adds r4, r7, #0x0
	lsrs r4, r4, #0x10
	mov r8, r4
	ldr r4, _0805BA90 @ =0x02034934
	ldr r5, [r4, #0x00]
	ldr r7, _0805BA94 @ =0x00000CAE
	adds r4, r5, r7
	movs r7, #0x00
	mov r9, r7
	strh r3, [r4, #0x00]
	movs r7, #0xCB
	lsls r7, r7, #0x04
	adds r4, r5, r7
	strh r6, [r4, #0x00]
	adds r7, #0x02
	adds r4, r5, r7
	mov r7, r8
	strh r7, [r4, #0x00]
	ldr r7, _0805BA98 @ =0x00000C76
	adds r4, r5, r7
	strh r1, [r4, #0x00]
	ldr r4, _0805BA9C @ =0x00000C78
	adds r1, r5, r4
	strh r0, [r1, #0x00]
	adds r7, #0x3E
	adds r1, r5, r7
	str r2, [r1, #0x00]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r3, #0x38
	ldr r2, _0805BAA0 @ =0x00000CC2
	adds r1, r5, r2
	strh r3, [r1, #0x00]
	adds r4, #0x4E
	adds r1, r5, r4
	strh r3, [r1, #0x00]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	adds r2, r6, #0x0
	subs r2, #0x0A
	adds r7, #0x10
	adds r1, r5, r7
	strh r2, [r1, #0x00]
	mov r1, r8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x01
	mov r2, r8
	muls r2, r0
	adds r0, r2, #0x0
	adds r6, r6, r0
	adds r6, #0x0C
	ldr r3, _0805BAA4 @ =0x00000CC8
	adds r0, r5, r3
	strh r6, [r0, #0x00]
	subs r4, #0x54
	adds r0, r5, r4
	mov r7, r9
	strh r7, [r0, #0x00]
	ldr r1, _0805BAA8 @ =0x00000C74
	adds r0, r5, r1
	mov r2, r9
	strh r2, [r0, #0x00]
	subs r3, #0x08
	adds r0, r5, r3
	strh r2, [r0, #0x00]
	adds r4, #0xCC
	adds r5, r5, r4
	strh r2, [r5, #0x00]
	bl func_0805A8D0
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805BA90: .4byte 0x02034934
_0805BA94: .4byte 0x00000CAE
_0805BA98: .4byte 0x00000C76
_0805BA9C: .4byte 0x00000C78
_0805BAA0: .4byte 0x00000CC2
_0805BAA4: .4byte 0x00000CC8
_0805BAA8: .4byte 0x00000C74
.syntax divided
