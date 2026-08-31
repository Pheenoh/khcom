.syntax unified
	.align 2, 0
	.global task_poo_shadowscale_0
	.thumb
	.thumb_func
	.type task_poo_shadowscale_0, %function
task_poo_shadowscale_0: @ 080CC07C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x10]
	ldr r2, [r0, #0x00]
	str r2, [r4, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [r4, #0x04]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x2C]
	ldr r0, _080CC0CC @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r4, #0x08]
	ldr r0, _080CC0D0 @ =0x08F69BE4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x0C]
	adds r5, r4, #0x0
	adds r5, #0x14
	ldr r1, _080CC0D4 @ =0x09EE1384
	ldr r2, _080CC0D8 @ =0x09EE1380
	adds r0, r5, #0x0
	bl AnimInit
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r5, #0x0
	bl AnimUpdate
	str r0, [r4, #0x30]
	pop {r4, r5}
	pop {r0}
	bx r0
_080CC0CC: .4byte 0x08B22BBC
_080CC0D0: .4byte 0x08F69BE4
_080CC0D4: .4byte 0x09EE1384
_080CC0D8: .4byte 0x09EE1380
.syntax divided
