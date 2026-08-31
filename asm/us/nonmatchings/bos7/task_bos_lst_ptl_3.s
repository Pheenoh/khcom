.syntax unified
	.align 2, 0
	.global task_bos_lst_ptl_3
	.thumb
	.thumb_func
	.type task_bos_lst_ptl_3, %function
task_bos_lst_ptl_3: @ 08111BDC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x30]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x34]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C
	.byte 0x70, 0x47
.syntax divided
