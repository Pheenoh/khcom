.syntax unified
	.align 2, 0
	.global task_wlogo_dil_0
	.thumb
	.thumb_func
	.type task_wlogo_dil_0, %function
task_wlogo_dil_0: @ 080B5D8C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, _080B5DF0 @ =0x096FAE24
	movs r0, #0x00
	adds r1, r5, #0x0
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B5DF4 @ =0x096444E4
	movs r2, #0xBD
	lsls r2, r2, #0x05
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B5DF8 @ =0x096BB464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _080B5DFC @ =0x0961FA28
	movs r1, #0xE2
	lsls r1, r1, #0x04
	bl LoadObjTiles
	str r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	ldr r0, _080B5E00 @ =0x09EF36D0
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x08]
	movs r1, #0x00
	movs r2, #0x00
	movs r0, #0x40
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	strb r1, [r4, #0x16]
	strh r2, [r4, #0x0E]
	strb r1, [r4, #0x0C]
	strb r1, [r4, #0x10]
	movs r0, #0x00
	movs r1, #0x10
	bl func_080057A0
	pop {r4, r5}
	pop {r0}
	bx r0
_080B5DF0: .4byte 0x096FAE24
_080B5DF4: .4byte 0x096444E4
_080B5DF8: .4byte 0x096BB464
_080B5DFC: .4byte 0x0961FA28
_080B5E00: .4byte 0x09EF36D0
.syntax divided
