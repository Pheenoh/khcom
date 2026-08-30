.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_obj_3
	.thumb
	.thumb_func
	.type task_wlogo_hwt_obj_3, %function
task_wlogo_hwt_obj_3: @ 080B4F04
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
