.syntax unified
	.align 2, 0
	.global func_080CA560
	.thumb
	.thumb_func
	.type func_080CA560, %function
func_080CA560: @ 080CA560
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	ldr r0, _080CA620 @ =0x02034DD8
	mov r8, r0
	ldr r1, _080CA624 @ =0x02034DDC
	mov r9, r1
	str r1, [sp, #0x000]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	mov r3, r8
	bl func_080CA3FC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CA59C
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r0, r5, r0
	str r0, [r4, #0x00]
	mov r3, r9
	ldr r0, [r3, #0x00]
	adds r0, r6, r0
	str r0, [r4, #0x04]
_080CA59C:
	asrs r0, r5, #0x08
	ldr r1, _080CA628 @ =0x0203C40C
	mov r10, r1
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	asrs r1, r6, #0x08
	ldr r3, _080CA62C @ =0x0203C3F8
	ldrh r2, [r3, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r7, #0x12
	str r7, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	mov r3, r9
	str r3, [sp, #0x00C]
	movs r2, #0x30
	movs r3, #0x00
	bl func_080CA4E8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CA630
	ldr r0, [r4, #0x00]
	asrs r0, r0, #0x08
	mov r2, r10
	ldrh r1, [r2, #0x00]
	subs r0, r0, r1
	ldr r1, [r4, #0x04]
	asrs r1, r1, #0x08
	ldr r3, _080CA62C @ =0x0203C3F8
	ldrh r2, [r3, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r7, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	mov r3, r9
	str r3, [sp, #0x00C]
	movs r2, #0x30
	movs r3, #0x00
	bl func_080CA4E8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CA634
	ldr r0, [r4, #0x00]
	mov r2, r8
	ldr r1, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r4, #0x00]
	ldr r0, [r4, #0x04]
	mov r3, r9
	ldr r1, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r4, #0x04]
	b _080CA634
	.byte 0x00, 0x00
_080CA620: .4byte 0x02034DD8
_080CA624: .4byte 0x02034DDC
_080CA628: .4byte 0x0203C40C
_080CA62C: .4byte 0x0203C3F8
_080CA630:
	str r5, [r4, #0x00]
	str r6, [r4, #0x04]
_080CA634:
	movs r0, #0x01
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
