.syntax unified
	.align 2, 0
	.global task_status_message_2
	.thumb
	.thumb_func
	.type task_status_message_2, %function
task_status_message_2: @ 080D8A4C
	push {r4, r5, lr}
	add sp, #-0x008
	adds r2, r0, #0x0
	movs r1, #0xCB
	lsls r1, r1, #0x02
	adds r0, r2, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	ldr r4, _080D8A84 @ =0x0000032E
	adds r1, r2, r4
	movs r5, #0x00
	ldsh r1, [r1, r5]
	subs r4, #0x0A
	adds r3, r2, r4
	ldr r3, [r3, #0x00]
	movs r4, #0x03
	str r4, [sp, #0x000]
	movs r5, #0xC8
	lsls r5, r5, #0x02
	adds r4, r2, r5
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
_080D8A84: .4byte 0x0000032E
.syntax divided
