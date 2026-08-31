.syntax unified
	.align 2, 0
	.global task_poo_shadowscale_3
	.thumb
	.thumb_func
	.type task_poo_shadowscale_3, %function
task_poo_shadowscale_3: @ 080CC160
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x08]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x0C]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
