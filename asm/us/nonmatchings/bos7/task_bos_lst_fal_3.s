.syntax unified
	.align 2, 0
	.global task_bos_lst_fal_3
	.thumb
	.thumb_func
	.type task_bos_lst_fal_3, %function
task_bos_lst_fal_3: @ 08111F14
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x20]
	cmp r0, #0x00
	beq _08111F22
	bl ReleaseObjTiles
_08111F22:
	ldr r0, [r4, #0x24]
	cmp r0, #0x00
	beq _08111F2C
	bl ReleaseObjPalette
_08111F2C:
	ldr r1, [r4, #0x1C]
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C
	.byte 0x70, 0x47
.syntax divided
