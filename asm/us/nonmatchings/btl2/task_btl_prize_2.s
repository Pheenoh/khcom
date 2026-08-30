.syntax unified
	.align 2, 0
	.global task_btl_prize_2
	.thumb
	.thumb_func
	.type task_btl_prize_2, %function
task_btl_prize_2: @ 080312F0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldrh r1, [r6, #0x2C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080313A2
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r9, r0
	mov r7, sp
	adds r7, #0x12
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r7, #0x0
	bl func_0801909C
	ldr r0, _080313B0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x01
	bl func_08002CB4
	mov r8, r0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r2, [r6, #0x18]
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r5, [r6, #0x04]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _080313B4 @ =0xFFFFEFFC
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldrh r1, [r6, #0x2C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080313A2
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r7, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r2, [r6, #0x1C]
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r4, _080313B8 @ =0x0000FFFF
	str r4, [sp, #0x00C]
	bl func_080023E0
_080313A2:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080313B0: .4byte 0x02039B84
_080313B4: .4byte 0xFFFFEFFC
_080313B8: .4byte 0x0000FFFF
.syntax divided
