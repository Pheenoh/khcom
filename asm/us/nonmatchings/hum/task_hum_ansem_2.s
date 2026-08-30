.syntax unified
	.align 2, 0
	.global task_hum_ansem_2
	.thumb
	.thumb_func
	.type task_hum_ansem_2, %function
task_hum_ansem_2: @ 0804E3A4
	push {lr}
	bl func_0800EFE8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
