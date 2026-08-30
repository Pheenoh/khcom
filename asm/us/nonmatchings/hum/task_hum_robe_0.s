.syntax unified
	.align 2, 0
	.global task_hum_robe_0
	.thumb
	.thumb_func
	.type task_hum_robe_0, %function
task_hum_robe_0: @ 08059CC8
	push {r4, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r1, _08059CF8 @ =0x0813FDF4
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, _08059CFC @ =0x0813FDD4
	adds r1, r4, #0x0
	adds r1, #0x14
	ldr r2, [r4, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	add sp, #0x004
	pop {r4}
	pop {r0}
	bx r0
_08059CF8: .4byte 0x0813FDF4
_08059CFC: .4byte 0x0813FDD4
.syntax divided
