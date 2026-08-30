.syntax unified
	.align 2, 0
	.global task_btl_exp_2
	.thumb
	.thumb_func
	.type task_btl_exp_2, %function
task_btl_exp_2: @ 0805D0E8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x48]
	cmp r0, #0x00
	beq _0805D170
	movs r4, #0x00
	ldr r2, [r5, #0x20]
	ldr r3, [r5, #0x04]
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x000]
	str r4, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x00
	movs r1, #0x28
	bl func_080023E0
	ldr r0, [r5, #0x48]
	movs r4, #0x20
	cmp r0, #0x02
	bne _0805D120
	movs r4, #0x28
_0805D120:
	movs r7, #0x00
	movs r0, #0x00
	mov r8, r0
	adds r6, r5, #0x0
	adds r6, #0x24
	movs r0, #0x28
	lsls r0, r0, #0x10
	mov r9, r0
_0805D130:
	lsls r1, r7, #0x02
	ldr r2, [r6, #0x00]
	cmp r2, #0x00
	beq _0805D168
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r5, #0x0
	adds r0, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov r12, r0
	ldr r0, [r5, #0x00]
	str r0, [sp, #0x000]
	mov r3, r8
	str r3, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	str r3, [sp, #0x00C]
	adds r0, r4, #0x0
	mov r3, r9
	asrs r1, r3, #0x10
	mov r3, r12
	bl func_080023E0
	adds r4, #0x08
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
_0805D168:
	adds r6, #0x04
	adds r7, #0x01
	cmp r7, #0x05
	ble _0805D130
_0805D170:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
