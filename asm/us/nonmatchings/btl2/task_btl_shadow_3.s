.syntax unified
	.align 2, 0
	.global task_btl_shadow_3
	.thumb
	.thumb_func
	.type task_btl_shadow_3, %function
task_btl_shadow_3: @ 0802F650
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
