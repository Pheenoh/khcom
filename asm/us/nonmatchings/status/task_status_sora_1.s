.syntax unified
	.align 2, 0
	.global task_status_sora_1
	.thumb
	.thumb_func
	.type task_status_sora_1, %function
task_status_sora_1: @ 080D7D58
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r4, #0x08]
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
