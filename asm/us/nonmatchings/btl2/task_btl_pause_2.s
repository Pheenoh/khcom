.syntax unified
	.align 2, 0
	.global task_btl_pause_2
	.thumb
	.thumb_func
	.type task_btl_pause_2, %function
task_btl_pause_2: @ 08030594
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldrb r0, [r6, #0x10]
	cmp r0, #0x00
	beq _080305DE
	ldr r0, [r6, #0x14]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x18]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
	ldr r0, [r6, #0x1C]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x20]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
_080305DE:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
