.syntax unified
	.align 2, 0
	.global task_tutorial_3
	.thumb
	.thumb_func
	.type task_tutorial_3, %function
task_tutorial_3: @ 0805E824
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	bl func_080028C0
	ldr r0, [r4, #0x1C]
	bl func_08002C10
	ldr r0, _0805E844 @ =0x03007480
	ldr r0, [r0, #0x00]
	bl func_08006578
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805E844: .4byte 0x03007480
.syntax divided
