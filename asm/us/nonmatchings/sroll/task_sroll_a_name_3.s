.syntax unified
	.align 2, 0
	.global task_sroll_a_name_3
	.thumb
	.thumb_func
	.type task_sroll_a_name_3, %function
task_sroll_a_name_3: @ 08114990
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x1C]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47, 0x40, 0x68, 0x01, 0x60, 0x70, 0x47
	.byte 0x00, 0x00
.syntax divided
