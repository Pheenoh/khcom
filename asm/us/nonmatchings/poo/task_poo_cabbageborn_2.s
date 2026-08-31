.syntax unified
	.align 2, 0
	.global task_poo_cabbageborn_2
	.thumb
	.thumb_func
	.type task_poo_cabbageborn_2, %function
task_poo_cabbageborn_2: @ 080D16E4
	push {lr}
	bl TaskPoolDraw
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
