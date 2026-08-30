.syntax unified
	.align 2, 0
	.global task_bos_ursula_tako_2
	.thumb
	.thumb_func
	.type task_bos_ursula_tako_2, %function
task_bos_ursula_tako_2: @ 080DD148
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r5, #0x28
	movs r1, #0x9C
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	beq _080DD1BA
	bl func_080DC528
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080DD1BA
	adds r0, r5, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD178
	ldr r7, [r6, #0x08]
	b _080DD17A
_080DD178:
	ldr r7, [r6, #0x04]
_080DD17A:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, [r6, #0x00]
	str r7, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	movs r4, #0xFC
	lsls r4, r4, #0x08
	str r4, [sp, #0x00C]
	bl func_080023E0
_080DD1BA:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
