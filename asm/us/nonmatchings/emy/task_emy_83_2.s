.syntax unified
	.align 2, 0
	.global task_emy_83_2
	.thumb
	.thumb_func
	.type task_emy_83_2, %function
task_emy_83_2: @ 0803E8E8
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_0800DF30
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r0, r4, #0x0
	bl TaskPoolDraw
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
