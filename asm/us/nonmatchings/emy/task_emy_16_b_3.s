.syntax unified
	.align 2, 0
	.global task_emy_16_b_3
	.thumb
	.thumb_func
	.type task_emy_16_b_3, %function
task_emy_16_b_3: @ 08039174
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x40
	bl func_08012304
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
