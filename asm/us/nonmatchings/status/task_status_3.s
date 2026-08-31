.syntax unified
	.align 2, 0
	.global task_status_3
	.thumb
	.thumb_func
	.type task_status_3, %function
task_status_3: @ 080D7884
	push {lr}
	bl TaskPoolDestroy
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x48, 0x00, 0x78, 0x70, 0x47, 0x00, 0x00, 0x00, 0x4F, 0x03, 0x02
.syntax divided
