.syntax unified
	.align 2, 0
	.global task_poo_mapbee_0
	.thumb
	.thumb_func
	.type task_poo_mapbee_0, %function
task_poo_mapbee_0: @ 080D2334
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r7, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r7, #0x28]
	movs r6, #0x00
	str r6, [r7, #0x2C]
	ldr r5, _080D239C @ =0x09EF6158
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D23A0 @ =0x097606E8
	bl AllocObjTiles
	str r0, [r7, #0x00]
	ldr r0, _080D23A4 @ =0x09849E38
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x04]
	adds r4, r7, #0x0
	adds r4, #0x0C
	ldr r1, _080D23A8 @ =0x09EF6200
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x08]
	adds r1, r7, #0x0
	adds r1, #0x34
	movs r0, #0x01
	strb r0, [r1, #0x00]
	strh r6, [r7, #0x36]
	movs r0, #0xC1
	lsls r0, r0, #0x01
	bl m4aSongNumStart
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D239C: .4byte 0x09EF6158
_080D23A0: .4byte 0x097606E8
_080D23A4: .4byte 0x09849E38
_080D23A8: .4byte 0x09EF6200
.syntax divided
