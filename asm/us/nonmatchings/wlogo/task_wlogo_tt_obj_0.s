.syntax unified
	.align 2, 0
	.global task_wlogo_tt_obj_0
	.thumb
	.thumb_func
	.type task_wlogo_tt_obj_0, %function
task_wlogo_tt_obj_0: @ 080B7674
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x24]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x28]
	movs r0, #0x00
	strh r0, [r4, #0x2C]
	strh r0, [r4, #0x2E]
	ldr r0, _080B76C4 @ =0x0962848A
	movs r1, #0xF8
	lsls r1, r1, #0x03
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080B76C8 @ =0x096FAE84
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r5, r4, #0x0
	adds r5, #0x0C
	ldr r1, _080B76CC @ =0x09EF3804
	ldr r2, _080B76D0 @ =0x09EF37F4
	adds r0, r5, #0x0
	bl AnimInit
	adds r0, r5, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	adds r0, r5, #0x0
	bl AnimGetGfx
	str r0, [r4, #0x08]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B76C4: .4byte 0x0962848A
_080B76C8: .4byte 0x096FAE84
_080B76CC: .4byte 0x09EF3804
_080B76D0: .4byte 0x09EF37F4
.syntax divided
