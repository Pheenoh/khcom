.syntax unified
	.align 2, 0
	.global task_hum_vixen_ice_3
	.thumb
	.thumb_func
	.type task_hum_vixen_ice_3, %function
task_hum_vixen_ice_3: @ 08055970
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	bl func_080028C0
	ldr r0, [r4, #0x08]
	bl func_08002C10
	adds r4, #0x28
	adds r0, r4, #0x0
	bl func_08012304
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
