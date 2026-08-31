.syntax unified
	.align 2, 0
	.global task_btl_pause_3
	.thumb
	.thumb_func
	.type task_btl_pause_3, %function
task_btl_pause_3: @ 080305E8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	bl func_080063C4
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
