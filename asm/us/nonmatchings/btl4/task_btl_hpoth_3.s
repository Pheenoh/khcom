.syntax unified
	.align 2, 0
	.global task_btl_hpoth_3
	.thumb
	.thumb_func
	.type task_btl_hpoth_3, %function
task_btl_hpoth_3: @ 0805DA34
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x10]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x14]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x18]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x1C]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x0C]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
