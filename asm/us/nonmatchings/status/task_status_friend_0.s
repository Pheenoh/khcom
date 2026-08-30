.syntax unified
	.align 2, 0
	.global task_status_friend_0
	.thumb
	.thumb_func
	.type task_status_friend_0, %function
task_status_friend_0: @ 080D8AC8
	push {r4, lr}
	adds r4, r0, #0x0
	adds r1, r4, #0x0
	adds r1, #0x0C
	adds r2, r4, #0x0
	adds r2, #0x18
	bl func_080D8B84
	strh r0, [r4, #0x24]
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
