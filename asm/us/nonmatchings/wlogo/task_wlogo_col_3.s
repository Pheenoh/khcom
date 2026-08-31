.syntax unified
	.align 2, 0
	.global task_wlogo_col_3
	.thumb
	.thumb_func
	.type task_wlogo_col_3, %function
task_wlogo_col_3: @ 080B5C4C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
