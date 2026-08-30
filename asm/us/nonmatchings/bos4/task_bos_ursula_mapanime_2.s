.syntax unified
	.align 2, 0
	.global task_bos_ursula_mapanime_2
	.thumb
	.thumb_func
	.type task_bos_ursula_mapanime_2, %function
task_bos_ursula_mapanime_2: @ 080DD684
	push {lr}
	adds r0, #0x10
	bl func_08000EE0
	pop {r0}
	bx r0
.syntax divided
