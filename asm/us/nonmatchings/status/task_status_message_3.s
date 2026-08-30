.syntax unified
	.align 2, 0
	.global task_status_message_3
	.thumb
	.thumb_func
	.type task_status_message_3, %function
task_status_message_3: @ 080D8A88
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x64
	bl func_08065AE0
	movs r0, #0xC9
	lsls r0, r0, #0x02
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
