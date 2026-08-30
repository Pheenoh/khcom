.syntax unified
	.align 2, 0
	.global task_emy_02_0
	.thumb
	.thumb_func
	.type task_emy_02_0, %function
task_emy_02_0: @ 08037518
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _08037534 @ =0x0813D4DC
	bl func_0800C778
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r4, r4, r0
	movs r0, #0x07
	str r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_08037534: .4byte 0x0813D4DC
.syntax divided
