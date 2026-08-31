.syntax unified
	.align 2, 0
	.global task_btl_vslockon_0
	.thumb
	.thumb_func
	.type task_btl_vslockon_0, %function
task_btl_vslockon_0: @ 0805D1A8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _0805D1F8 @ =0x08B1D8BC
	movs r1, #0xC0
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _0805D1FC @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _0805D200 @ =0x09EE10F8
	ldr r2, _0805D204 @ =0x09EE10EC
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x20]
	ldr r0, _0805D208 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, _0805D20C @ =0x02039B9C
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x7C]
	str r0, [r2, #0x78]
	ldr r0, [r2, #0x7C]
	str r0, [r1, #0x78]
	pop {r4, r5}
	pop {r0}
	bx r0
_0805D1F8: .4byte 0x08B1D8BC
_0805D1FC: .4byte 0x08F69BA4
_0805D200: .4byte 0x09EE10F8
_0805D204: .4byte 0x09EE10EC
_0805D208: .4byte 0x02039B84
_0805D20C: .4byte 0x02039B9C
.syntax divided
