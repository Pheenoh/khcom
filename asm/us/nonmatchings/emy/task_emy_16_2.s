.syntax unified
	.align 2, 0
	.global task_emy_16_2
	.thumb
	.thumb_func
	.type task_emy_16_2, %function
task_emy_16_2: @ 08038E24
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_0800DF30
	movs r0, #0xC6
	lsls r0, r0, #0x01
	adds r4, r4, r0
	adds r0, r4, #0x0
	bl func_08000EE0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
