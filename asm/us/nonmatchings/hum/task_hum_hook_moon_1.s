.syntax unified
	.align 2, 0
	.global task_hum_hook_moon_1
	.thumb
	.thumb_func
	.type task_hum_hook_moon_1, %function
task_hum_hook_moon_1: @ 0804C944
	ldrh r1, [r0, #0x08]
	adds r1, #0x01
	strh r1, [r0, #0x08]
	movs r0, #0x01
	bx lr
	.byte 0x00, 0x00
.syntax divided
