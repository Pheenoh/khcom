.syntax unified
	.align 2, 0
	.global task_btl_lockon_0
	.thumb
	.thumb_func
	.type task_btl_lockon_0, %function
task_btl_lockon_0: @ 0801D228
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _0801D274 @ =0x08B1D8BC
	movs r1, #0xC0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _0801D278 @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _0801D27C @ =0x09EE10F8
	ldr r2, _0801D280 @ =0x09EE10EC
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x20]
	movs r1, #0x00
	strh r1, [r5, #0x24]
	ldr r0, _0801D284 @ =0x02039B84
	ldr r0, [r0, #0x00]
	str r1, [r0, #0x78]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801D274: .4byte 0x08B1D8BC
_0801D278: .4byte 0x08F69BA4
_0801D27C: .4byte 0x09EE10F8
_0801D280: .4byte 0x09EE10EC
_0801D284: .4byte 0x02039B84
.syntax divided
