.syntax unified
	.align 2, 0
	.global task_wlogo_tt_line_0
	.thumb
	.thumb_func
	.type task_wlogo_tt_line_0, %function
task_wlogo_tt_line_0: @ 080B7750
	push {lr}
	movs r2, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x00]
	strh r1, [r0, #0x02]
	strb r2, [r0, #0x04]
	adds r0, #0x08
	movs r1, #0x21
	bl func_08000E64
	pop {r0}
	bx r0
.syntax divided
