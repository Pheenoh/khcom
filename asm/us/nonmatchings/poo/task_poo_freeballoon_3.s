.syntax unified
	.align 2, 0
	.global task_poo_freeballoon_3
	.thumb
	.thumb_func
	.type task_poo_freeballoon_3, %function
task_poo_freeballoon_3: @ 080CC464
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x48]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x4C]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
