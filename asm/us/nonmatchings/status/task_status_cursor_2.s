.syntax unified
	.align 2, 0
	.global task_status_cursor_2
	.thumb
	.thumb_func
	.type task_status_cursor_2, %function
task_status_cursor_2: @ 080D7FD8
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	bl func_08006314
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	bne _080D804C
	ldr r0, _080D8054 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D8000
	bl func_080D8340
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D804C
_080D8000:
	ldr r0, [r5, #0x58]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r5, #0x50]
	asrs r1, r1, #0x08
	subs r1, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x14]
	ldr r3, [r5, #0x04]
	ldr r4, [r5, #0x0C]
	str r4, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl DrawSprite
	adds r0, r5, #0x0
	adds r0, #0x4C
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	blt _080D804C
	ldr r1, [r5, #0x50]
	asrs r1, r1, #0x08
	adds r1, #0x03
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x10]
	ldr r3, [r5, #0x00]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	bl DrawSprite
_080D804C:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D8054: .4byte 0x02039BB0
.syntax divided
