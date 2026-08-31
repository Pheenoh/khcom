.syntax unified
	.align 2, 0
	.global task_wlogo_mons_0
	.thumb
	.thumb_func
	.type task_wlogo_mons_0, %function
task_wlogo_mons_0: @ 080B4818
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r4, _080B48A0 @ =0x096FACA4
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B48A4 @ =0x096324C4
	movs r2, #0xC8
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B48A8 @ =0x096B6C64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _080B48AC @ =0x0961AA92
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl LoadObjTiles
	str r0, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	movs r1, #0x00
	movs r2, #0x00
	movs r0, #0x40
	strh r0, [r5, #0x08]
	strh r0, [r5, #0x0A]
	strh r2, [r5, #0x28]
	strh r2, [r5, #0x2A]
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
	adds r0, #0x01
	strb r1, [r0, #0x00]
	adds r0, #0x01
	strb r1, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	bl func_080057A0
	adds r4, r5, #0x0
	adds r4, #0x10
	ldr r1, _080B48B0 @ =0x09EF3544
	ldr r2, _080B48B4 @ =0x09EF351C
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x0C]
	pop {r4, r5}
	pop {r0}
	bx r0
_080B48A0: .4byte 0x096FACA4
_080B48A4: .4byte 0x096324C4
_080B48A8: .4byte 0x096B6C64
_080B48AC: .4byte 0x0961AA92
_080B48B0: .4byte 0x09EF3544
_080B48B4: .4byte 0x09EF351C
.syntax divided
