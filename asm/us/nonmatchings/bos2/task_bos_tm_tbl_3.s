.syntax unified
	.align 2, 0
	.global task_bos_tm_tbl_3
	.thumb
	.thumb_func
	.type task_bos_tm_tbl_3, %function
task_bos_tm_tbl_3: @ 080BCE78
	push {lr}
	adds r0, #0x04
	bl func_08012304
	movs r0, #0x01
	bl func_0800501C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
