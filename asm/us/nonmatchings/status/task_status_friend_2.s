.syntax unified
	.align 2, 0
	.global task_status_friend_2
	.thumb
	.thumb_func
	.type task_status_friend_2, %function
task_status_friend_2: @ 080D8AE4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, _080D8B50 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	movs r4, #0xBA
	cmp r0, #0x00
	beq _080D8AFA
	movs r4, #0xD8
_080D8AFA:
	movs r6, #0x00
	ldrh r0, [r5, #0x24]
	cmp r6, r0
	bge _080D8B46
	adds r7, r5, #0x0
_080D8B04:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r6, #0x02
	adds r0, r5, #0x0
	adds r0, #0x18
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldm r7!, {r3}
	adds r0, r5, #0x0
	adds r0, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	adds r0, r6, #0x7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	movs r1, #0x2D
	bl func_080023E0
	adds r4, #0x14
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r6, #0x01
	ldrh r0, [r5, #0x24]
	cmp r6, r0
	blt _080D8B04
_080D8B46:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D8B50: .4byte 0x02039BB0
.syntax divided
