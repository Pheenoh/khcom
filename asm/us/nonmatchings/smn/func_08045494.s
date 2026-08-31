.syntax unified
	.align 2, 0
	.global func_08045494
	.thumb
	.thumb_func
	.type func_08045494, %function
func_08045494: @ 08045494
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x00C
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r0, [r4, #0x08]
	mov r9, r0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x08
	ldr r0, [r4, #0x0C]
	subs r7, r0, r3
	movs r6, #0xC0
	lsls r6, r6, #0x01
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080454DC
	lsls r0, r5, #0x10
	asrs r0, r0, #0x08
	ldr r1, [r4, #0x04]
	adds r4, r1, r0
	ldr r5, _080454D8 @ =0xFFFFFE80
	b _080454E6
	.byte 0x00, 0x00
_080454D8: .4byte 0xFFFFFE80
_080454DC:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x08
	ldr r1, [r4, #0x04]
	subs r4, r1, r0
	adds r5, r6, #0x0
_080454E6:
	adds r0, r4, #0x0
	mov r1, r9
	adds r2, r7, #0x0
	bl func_08014780
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080147C8
	mov r1, r8
	cmp r1, #0x00
	beq _0804553E
	ldr r0, _08045518 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x86
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x98
	bne _0804551C
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0x30
	b _08045522
	.byte 0x00, 0x00
_08045518: .4byte 0x02039B84
_0804551C:
	movs r0, #0x0A
	movs r1, #0x0A
	movs r2, #0x0A
_08045522:
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	str r2, [sp, #0x008]
	movs r0, #0x84
	adds r1, r4, #0x0
	mov r2, r9
	adds r3, r7, #0x0
	bl func_08011F78
	cmp r0, #0x00
	beq _0804553E
	ldr r0, _0804554C @ =0x000001F9
	bl m4aSongNumStart
_0804553E:
	add sp, #0x00C
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0804554C: .4byte 0x000001F9
.syntax divided
