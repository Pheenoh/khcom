.syntax unified
	.align 2, 0
	.global task_status_scrollcursor_1
	.thumb
	.thumb_func
	.type task_status_scrollcursor_1, %function
task_status_scrollcursor_1: @ 080D88D4
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D885C
	strh r0, [r4, #0x12]
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
