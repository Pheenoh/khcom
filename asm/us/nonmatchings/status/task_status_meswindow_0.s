.syntax unified
	.align 2, 0
	.global task_status_meswindow_0
	.thumb
	.thumb_func
	.type task_status_meswindow_0, %function
task_status_meswindow_0: @ 080D8938
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x1C]
	movs r0, #0x48
	str r0, [r4, #0x18]
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_08000E64
	movs r0, #0x00
	str r0, [r4, #0x14]
	adds r4, #0x20
	strb r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
