.syntax unified
	.align 2, 0
	.global task_wlogo_bks_0
	.thumb
	.thumb_func
	.type task_wlogo_bks_0, %function
task_wlogo_bks_0: @ 080B7838
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r4, _080B78F0 @ =0x096FB0A4
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B78F4 @ =0x0964A104
	movs r2, #0xD8
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B78F8 @ =0x096BEC64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	movs r1, #0x00
	movs r5, #0x00
	strh r5, [r6, #0x02]
	strh r5, [r6, #0x04]
	strb r1, [r6, #0x00]
	strb r1, [r6, #0x0A]
	strb r1, [r6, #0x06]
	strh r5, [r6, #0x08]
	strh r5, [r6, #0x32]
	adds r0, r6, #0x0
	adds r0, #0x30
	strb r1, [r0, #0x00]
	ldrb r2, [r6, #0x0A]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
	adds r0, r6, #0x0
	adds r0, #0x3C
	movs r1, #0x0F
	bl TaskPoolInit
	movs r0, #0xB0
	lsls r0, r0, #0x03
	ldr r1, _080B78FC @ =0x09628DC0
	bl AllocObjTiles
	str r0, [r6, #0x0C]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x10]
	adds r4, r6, #0x0
	adds r4, #0x18
	ldr r1, _080B7900 @ =0x09EF3850
	ldr r2, _080B7904 @ =0x09EF380C
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x0C
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x14]
	strh r5, [r6, #0x34]
	strh r5, [r6, #0x38]
	adds r5, r6, #0x0
	adds r5, #0x36
	movs r0, #0x04
	strb r0, [r5, #0x00]
	adds r4, #0x1F
	movs r0, #0x06
	strb r0, [r4, #0x00]
	ldr r0, _080B7908 @ =0x080B7C7D
	bl func_080081B8
	ldrb r1, [r5, #0x00]
	ldrb r2, [r4, #0x00]
	movs r0, #0x00
	bl func_080081E4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B78F0: .4byte 0x096FB0A4
_080B78F4: .4byte 0x0964A104
_080B78F8: .4byte 0x096BEC64
_080B78FC: .4byte 0x09628DC0
_080B7900: .4byte 0x09EF3850
_080B7904: .4byte 0x09EF380C
_080B7908: .4byte 0x080B7C7D
.syntax divided
