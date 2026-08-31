.syntax unified
	.align 2, 0
	.global task_bos_lst_ptl_0
	.thumb
	.thumb_func
	.type task_bos_lst_ptl_0, %function
task_bos_lst_ptl_0: @ 08111A1C
	push {r4, lr}
	adds r4, r0, #0x0
	movs r2, #0x00
	strh r2, [r4, #0x00]
	strh r2, [r4, #0x02]
	strh r2, [r4, #0x04]
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x06]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x08]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x0C]
	str r2, [r4, #0x10]
	str r2, [r4, #0x14]
	ldr r0, _08111A6C @ =0x09CD0C34
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r4, #0x30]
	ldr r0, _08111A70 @ =0x09D69594
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r4, #0x34]
	adds r4, #0x18
	ldr r1, _08111A74 @ =0x09EFBF54
	ldr r2, _08111A78 @ =0x09EFBF40
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08111A6C: .4byte 0x09CD0C34
_08111A70: .4byte 0x09D69594
_08111A74: .4byte 0x09EFBF54
_08111A78: .4byte 0x09EFBF40
.syntax divided
