.syntax unified
	.align 2, 0
	.global func_080D484C
	.thumb
	.thumb_func
	.type func_080D484C, %function
func_080D484C: @ 080D484C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r6, r0, #0x0
	ldr r0, _080D49DC @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D4864
	b _080D49CA
_080D4864:
	movs r0, #0x00
	mov r8, r0
	adds r1, r6, #0x0
	adds r1, #0x08
	str r1, [sp, #0x018]
	adds r2, r6, #0x0
	adds r2, #0xF8
	str r2, [sp, #0x01C]
	adds r3, r6, #0x0
	adds r3, #0xF0
	str r3, [sp, #0x010]
	adds r4, r6, #0x0
	adds r4, #0xF4
	str r4, [sp, #0x014]
	movs r5, #0x82
	lsls r5, r5, #0x01
	adds r5, r5, r6
	mov r10, r5
	movs r0, #0x84
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r9, r0
	ldr r1, _080D49E0 @ =0x096FDC10
	str r1, [sp, #0x020]
_080D4894:
	mov r2, r8
	lsls r0, r2, #0x02
	ldr r3, [sp, #0x018]
	adds r0, r3, r0
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	beq _080D4984
	movs r5, #0x80
	lsls r5, r5, #0x01
	adds r0, r6, r5
	ldrh r7, [r0, #0x00]
	cmp r7, #0x00
	bne _080D4984
	mov r1, r10
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	mov r2, r9
	ldr r1, [r2, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, [r6, #0x18]
	adds r2, r6, #0x0
	adds r2, #0xEC
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r2, r8
	adds r2, #0x33
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r4, #0x0
	bl DrawSprite
	ldr r3, [sp, #0x020]
	movs r4, #0x00
	ldsh r0, [r3, r4]
	ldr r5, _080D49E4 @ =0x02034E84
	str r0, [r5, #0x00]
	movs r2, #0x02
	ldsh r1, [r3, r2]
	ldr r3, _080D49E8 @ =0x02034E88
	str r1, [r3, #0x00]
	mov r4, r10
	ldr r2, [r4, #0x00]
	asrs r2, r2, #0x08
	adds r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r5, r9
	ldr r2, [r5, #0x00]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x34
	mov r5, r8
	muls r5, r2
	adds r2, r6, #0x0
	adds r2, #0x34
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	adds r3, r6, #0x0
	adds r3, #0x1C
	adds r3, r3, r5
	ldr r3, [r3, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x28
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r4, r8
	adds r4, #0x28
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	mov r0, r10
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	ldr r2, _080D49E4 @ =0x02034E84
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r3, r9
	ldr r2, [r3, #0x00]
	asrs r2, r2, #0x08
	ldr r4, _080D49E8 @ =0x02034E88
	ldr r1, [r4, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r6, #0x0
	adds r2, #0x38
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	adds r3, r6, #0x0
	adds r3, #0x20
	adds r3, r3, r5
	ldr r3, [r3, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x2C
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r4, r8
	adds r4, #0x1E
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
_080D4984:
	ldr r5, [sp, #0x020]
	adds r5, #0x04
	str r5, [sp, #0x020]
	movs r0, #0x01
	add r8, r0
	mov r1, r8
	cmp r1, #0x03
	bgt _080D4996
	b _080D4894
_080D4996:
	movs r2, #0x82
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	movs r3, #0x84
	lsls r3, r3, #0x01
	adds r1, r6, r3
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r4, [sp, #0x01C]
	ldr r2, [r4, #0x00]
	ldr r5, [sp, #0x010]
	ldr r3, [r5, #0x00]
	ldr r5, [sp, #0x014]
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x14
	str r4, [sp, #0x00C]
	bl DrawSprite
_080D49CA:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D49DC: .4byte 0x0203C4E0
_080D49E0: .4byte 0x096FDC10
_080D49E4: .4byte 0x02034E84
_080D49E8: .4byte 0x02034E88
.syntax divided
