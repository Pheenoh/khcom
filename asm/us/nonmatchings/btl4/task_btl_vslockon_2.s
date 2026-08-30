.syntax unified
	.align 2, 0
	.global task_btl_vslockon_2
	.thumb
	.thumb_func
	.type task_btl_vslockon_2, %function
task_btl_vslockon_2: @ 0805D26C
	push {r4, r5, r6, lr}
	add sp, #-0x014
	adds r5, r0, #0x0
	ldr r0, _0805D2C8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x78]
	cmp r0, #0x00
	beq _0805D2BE
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	adds r1, r0, #0x0
	adds r1, #0xA2
	movs r6, #0x00
	ldsh r1, [r1, r6]
	lsls r1, r1, #0x08
	ldr r0, [r0, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r5, #0x20]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x80
	lsls r4, r4, #0x01
	str r4, [sp, #0x00C]
	bl func_080023E0
_0805D2BE:
	add sp, #0x014
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805D2C8: .4byte 0x02039B84
.syntax divided
