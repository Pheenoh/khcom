.syntax unified
	.align 2, 0
	.global task_btl_hpenm_0
	.thumb
	.thumb_func
	.type task_btl_hpenm_0, %function
task_btl_hpenm_0: @ 0802FE44
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r0, #0xA0
	lsls r0, r0, #0x01
	ldr r5, _0802FE8C @ =0x08B24DAA
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r4, #0x00]
	movs r0, #0x80
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r4, #0x04]
	movs r0, #0x20
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r4, #0x0C]
	ldr r0, _0802FE90 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	movs r1, #0x00
	strb r1, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r4, #0x10]
	str r1, [r4, #0x18]
	strh r1, [r4, #0x1C]
	str r1, [r4, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0802FE8C: .4byte 0x08B24DAA
_0802FE90: .4byte 0x08F69BA4
.syntax divided
