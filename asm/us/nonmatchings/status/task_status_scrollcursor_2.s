.syntax unified
	.align 2, 0
	.global task_status_scrollcursor_2
	.thumb
	.thumb_func
	.type task_status_scrollcursor_2, %function
task_status_scrollcursor_2: @ 080D88E8
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_080D8340
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D8918
	movs r0, #0x12
	ldsh r1, [r4, r0]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	movs r0, #0x06
	str r0, [sp, #0x00C]
	movs r0, #0x54
	bl func_080023E0
_080D8918:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
