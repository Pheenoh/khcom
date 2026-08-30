.syntax unified
	.align 2, 0
	.global task_bos_ursula_bubble_3
	.thumb
	.thumb_func
	.type task_bos_ursula_bubble_3, %function
task_bos_ursula_bubble_3: @ 080DD9A4
	push {lr}
	adds r0, #0x04
	bl func_08000F0C
	pop {r0}
	bx r0
.syntax divided
