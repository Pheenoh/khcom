.syntax unified
	.align 2, 0
	.global func_080CA3FC
	.thumb
	.thumb_func
	.type func_080CA3FC, %function
func_080CA3FC: @ 080CA3FC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	mov r9, r1
	mov r10, r2
	mov r8, r3
	bl func_080CA3A0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CA4D6
	ldrb r0, [r5, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r2, _080CA47C @ =0x08121400
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r7, [r0, r3]
	adds r0, r1, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r6, r0
	lsls r0, r7, #0x02
	add r0, r9
	str r0, [sp, #0x000]
	lsls r0, r6, #0x02
	add r0, r10
	str r0, [sp, #0x004]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x008]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x00C]
	ldr r4, [r5, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r4, r0
	ble _080CA45A
	adds r4, r0, #0x0
_080CA45A:
	mov r0, sp
	str r2, [sp, #0x010]
	bl func_080CA3A0
	lsls r0, r0, #0x18
	ldr r2, [sp, #0x010]
	cmp r0, #0x00
	bne _080CA480
	adds r0, r7, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	mov r3, r8
	str r0, [r3, #0x00]
	adds r0, r6, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	b _080CA4CE
_080CA47C: .4byte 0x08121400
_080CA480:
	ldrb r0, [r5, #0x14]
	subs r0, #0x40
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	lsls r0, r1, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r7, [r0, r3]
	adds r0, r1, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r6, r0
	lsls r0, r7, #0x02
	add r0, r9
	str r0, [sp, #0x000]
	lsls r0, r6, #0x02
	add r0, r10
	str r0, [sp, #0x004]
	mov r0, sp
	bl func_080CA3A0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CA4C8
	adds r0, r7, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	mov r3, r8
	str r0, [r3, #0x00]
	adds r0, r6, #0x0
	muls r0, r4
	asrs r0, r0, #0x08
	b _080CA4CE
_080CA4C8:
	movs r0, #0x00
	mov r3, r8
	str r0, [r3, #0x00]
_080CA4CE:
	ldr r1, [sp, #0x034]
	str r0, [r1, #0x00]
	movs r0, #0x01
	b _080CA4D8
_080CA4D6:
	movs r0, #0x00
_080CA4D8:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
