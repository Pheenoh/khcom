.syntax unified
	.align 2, 0
	.global task_hum_vixen_frz_3
	.thumb
	.thumb_func
	.type task_hum_vixen_frz_3, %function
task_hum_vixen_frz_3: @ 08055E20
	push {lr}
	ldr r0, [r0, #0x04]
	bl ReleaseObjPalette
	pop {r0}
	bx r0
.syntax divided
