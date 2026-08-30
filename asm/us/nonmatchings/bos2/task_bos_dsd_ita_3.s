.syntax unified
	.align 2, 0
	.global task_bos_dsd_ita_3
	.thumb
	.thumb_func
	.type task_bos_dsd_ita_3, %function
task_bos_dsd_ita_3: @ 080C4270
	push {lr}
	adds r0, #0x04
	bl func_08012304
	pop {r0}
	bx r0
.syntax divided
