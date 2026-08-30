.syntax unified
	.align 2, 0
	.global task_bos_ursula_backtako_2
	.thumb
	.thumb_func
	.type task_bos_ursula_backtako_2, %function
task_bos_ursula_backtako_2: @ 080DD408
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	bl func_080DC528
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	bne _080DD49A
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r7, #0x2C]
	ldr r3, [r7, #0x30]
	ldr r0, [r7, #0x34]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	movs r0, #0x08
	adds r0, r0, r7
	mov r8, r0
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r3, [r7, #0x00]
	ldr r4, [r7, #0x04]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	movs r4, #0xFE
	lsls r4, r4, #0x08
	mov r9, r4
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r2, [r7, #0x38]
	ldr r3, [r7, #0x3C]
	ldr r0, [r7, #0x40]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	mov r0, r8
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r3, [r7, #0x00]
	ldr r4, [r7, #0x04]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	ldr r4, _080DD4A8 @ =0x00000C01
	str r4, [sp, #0x008]
	mov r4, r9
	str r4, [sp, #0x00C]
	bl func_080023E0
_080DD49A:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080DD4A8: .4byte 0x00000C01
.syntax divided
