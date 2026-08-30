.syntax unified
	.align 2, 0
	.global task_poo_eeyoretail_0
	.thumb
	.thumb_func
	.type task_poo_eeyoretail_0, %function
task_poo_eeyoretail_0: @ 080CF898
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _080CF8E8 @ =0x0007CD00
	str r0, [r5, #0x0C]
	ldr r0, _080CF8EC @ =0x00049E00
	str r0, [r5, #0x10]
	ldr r0, _080CF8F0 @ =0xFFFFE000
	str r0, [r5, #0x14]
	movs r4, #0x00
	str r4, [r5, #0x18]
	ldr r0, _080CF8F4 @ =0x09EF5D68
	movs r1, #0x10
	bl func_08003524
	strh r0, [r5, #0x1C]
	str r4, [r5, #0x04]
	ldr r0, _080CF8F8 @ =0x09744842
	str r0, [r5, #0x08]
	adds r4, r5, #0x0
	adds r4, #0x24
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	adds r1, r5, #0x0
	adds r1, #0x0C
	adds r0, r4, #0x0
	movs r2, #0x66
	bl func_080CC178
	ldr r1, _080CF8FC @ =0x02034E18
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, [r5, #0x14]
	negs r0, r0
	str r0, [r5, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CF8E8: .4byte 0x0007CD00
_080CF8EC: .4byte 0x00049E00
_080CF8F0: .4byte 0xFFFFE000
_080CF8F4: .4byte 0x09EF5D68
_080CF8F8: .4byte 0x09744842
_080CF8FC: .4byte 0x02034E18
.syntax divided
