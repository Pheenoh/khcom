.syntax unified
	.align 2, 0
	.global task_hum_cloud_3
	.thumb
	.thumb_func
	.type task_hum_cloud_3, %function
task_hum_cloud_3: @ 0804B440
	push {lr}
	bl func_0800E380
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
