.syntax unified
	.align 2, 0
	.global task_emy_83_3
	.thumb
	.thumb_func
	.type task_emy_83_3, %function
task_emy_83_3: @ 0803E904
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl TaskPoolDestroy
	adds r0, r4, #0x0
	bl func_0800E0D0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
