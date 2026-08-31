.syntax unified
	.align 2, 0
	.global task_sroll_b_crtn_3
	.thumb
	.thumb_func
	.type task_sroll_b_crtn_3, %function
task_sroll_b_crtn_3: @ 08115160
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x10]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x14]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47
.syntax divided
