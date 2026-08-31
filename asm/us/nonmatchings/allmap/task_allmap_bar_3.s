.syntax unified
	.align 2, 0
	.global task_allmap_bar_3
	.thumb
	.thumb_func
	.type task_allmap_bar_3, %function
task_allmap_bar_3: @ 080D4210
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
