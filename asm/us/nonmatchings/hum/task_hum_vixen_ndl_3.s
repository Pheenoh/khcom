.syntax unified
	.align 2, 0
	.global task_hum_vixen_ndl_3
	.thumb
	.thumb_func
	.type task_hum_vixen_ndl_3, %function
task_hum_vixen_ndl_3: @ 08055668
	push {lr}
	ldr r0, [r0, #0x04]
	bl func_08002C10
	pop {r0}
	bx r0
.syntax divided
