.syntax unified
	.align 2, 0
	.global task_bos_dsd_2
	.thumb
	.thumb_func
	.type task_bos_dsd_2, %function
task_bos_dsd_2: @ 080C20D0
	push {lr}
	movs r1, #0xDF
	lsls r1, r1, #0x02
	adds r0, r0, r1
	bl func_08000EE0
	pop {r0}
	bx r0
.syntax divided
