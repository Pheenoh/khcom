.syntax unified
	.align 2, 0
	.global task_bos_ursula_bubble_single_1
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_single_1, %function
task_bos_ursula_bubble_single_1: @ 080DDAA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x00C
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r5, #0x24
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r4, r6, r0
	ldr r0, [r4, #0x00]
	subs r0, #0x0C
	str r0, [r4, #0x00]
	ldr r1, _080DDC38 @ =0x00000165
	cmp r0, r1
	bgt _080DDACA
	movs r0, #0xB3
	lsls r0, r0, #0x01
	str r0, [r4, #0x00]
_080DDACA:
	movs r1, #0x9C
	lsls r1, r1, #0x01
	adds r1, r1, r6
	mov r12, r1
	ldr r2, [r1, #0x00]
	mov r8, r2
	cmp r2, #0x00
	bne _080DDB3A
	ldr r3, _080DDC3C @ =0x08121400
	movs r7, #0x9E
	lsls r7, r7, #0x01
	adds r2, r6, r7
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r7, #0x00
	ldsh r1, [r0, r7]
	ldr r0, [r4, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x04]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	ldrb r0, [r2, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	ldr r1, [r4, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _080DDB2A
	mov r3, r8
	str r3, [r5, #0x0C]
	strh r3, [r1, #0x00]
_080DDB2A:
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080DDB3A
	movs r0, #0xB4
	strh r0, [r1, #0x00]
	movs r0, #0x01
	mov r7, r12
	str r0, [r7, #0x00]
_080DDB3A:
	movs r1, #0x9C
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080DDC04
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r7, r6, r2
	ldrh r0, [r7, #0x00]
	cmp r0, #0x00
	beq _080DDC04
	ldr r0, [r5, #0x04]
	ldr r1, [r5, #0x0C]
	ldr r3, _080DDC40 @ =0x02039B84
	mov r8, r3
	ldr r2, [r3, #0x00]
	ldr r3, [r2, #0x7C]
	ldr r2, [r3, #0x04]
	ldr r3, [r3, #0x0C]
	bl func_0801CB6C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0x9F
	lsls r2, r2, #0x01
	adds r1, r6, r2
	strh r0, [r1, #0x00]
	movs r3, #0x9E
	lsls r3, r3, #0x01
	adds r4, r6, r3
	ldrh r1, [r1, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x04
	bl func_0800589C
	ldr r3, _080DDC3C @ =0x08121400
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r1, [r0, r2]
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r2, r6, r0
	ldr r0, [r2, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x04]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	ldrb r0, [r4, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	ldr r1, [r2, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldrh r0, [r7, #0x00]
	cmp r0, #0xA9
	bhi _080DDBD2
	adds r0, r5, #0x0
	adds r0, #0x08
	mov r2, r8
	ldr r1, [r2, #0x00]
	ldr r1, [r1, #0x7C]
	ldr r1, [r1, #0x08]
	movs r2, #0x1E
	bl func_080058FC
_080DDBD2:
	ldr r0, [r5, #0x04]
	movs r1, #0x82
	lsls r1, r1, #0x0A
	cmp r0, r1
	bhi _080DDC32
	ldr r0, [r5, #0x08]
	cmp r0, r1
	bgt _080DDC32
	ldrh r0, [r7, #0x00]
	subs r0, #0x01
	strh r0, [r7, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080DDC04
	adds r0, r6, #0x0
	adds r0, #0x0C
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
	adds r0, r6, #0x0
	adds r0, #0x24
	movs r1, #0x01
	bl func_0801C2DC
_080DDC04:
	adds r4, r6, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080DDC48
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r0, #0x01
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0xF2
	bl func_08011F78
	cmp r0, #0x01
	bne _080DDC48
	ldr r0, _080DDC44 @ =0x00000281
	bl func_0811FE70
_080DDC32:
	movs r0, #0x00
	b _080DDC78
	.byte 0x00, 0x00
_080DDC38: .4byte 0x00000165
_080DDC3C: .4byte 0x08121400
_080DDC40: .4byte 0x02039B84
_080DDC44: .4byte 0x00000281
_080DDC48:
	adds r0, r4, #0x0
	bl func_08005B30
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bne _080DDC62
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DDC32
_080DDC62:
	adds r0, r4, #0x0
	bl func_08005A64
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	bl func_08012324
	movs r0, #0x01
_080DDC78:
	add sp, #0x00C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
