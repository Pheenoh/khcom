.syntax unified
	.align 2, 0
	.global task_roomcreate_2
	.thumb
	.thumb_func
	.type task_roomcreate_2, %function
task_roomcreate_2: @ 0803F6D4
	push {lr}
	adds r0, #0x2C
	bl func_08000EE0
	pop {r0}
	bx r0
.syntax divided
