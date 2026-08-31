.syntax unified
	.align 2, 0
	.global task_wlogo_tt_0
	.thumb
	.thumb_func
	.type task_wlogo_tt_0, %function
task_wlogo_tt_0: @ 080B6DFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	ldr r0, _080B6FB8 @ =0x096FAE84
	mov r8, r0
	movs r0, #0x00
	mov r1, r8
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080B6FBC @ =0x09648EA4
	movs r2, #0x93
	lsls r2, r2, #0x05
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080B6FC0 @ =0x096BE464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r6, _080B6FC4 @ =0x096FB084
	ldr r1, _080B6FC8 @ =0x050001E0
	adds r0, r6, #0x0
	movs r2, #0x20
	bl LoadPalette
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r7, #0x02]
	strh r0, [r7, #0x04]
	strb r1, [r7, #0x00]
	strb r1, [r7, #0x06]
	strb r1, [r7, #0x07]
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x33
	str r1, [r0, #0x00]
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r0, r7, r2
	str r1, [r0, #0x00]
	ldrb r2, [r7, #0x06]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
	movs r4, #0x80
	lsls r4, r4, #0x02
	ldr r5, _080B6FCC @ =0x09624F72
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x08]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x0C]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x10]
	movs r0, #0xF0
	lsls r0, r0, #0x02
	adds r1, r5, #0x0
	bl AllocObjTiles
	str r0, [r7, #0x14]
	ldr r0, _080B6FD0 @ =0x0962848A
	movs r1, #0xF8
	lsls r1, r1, #0x03
	bl LoadObjTiles
	str r0, [r7, #0x18]
	mov r0, r8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x1C]
	ldrh r0, [r0, #0x06]
	ldrb r1, [r7, #0x07]
	lsls r1, r1, #0x05
	ldr r3, _080B6FD4 @ =0xFFFFFE20
	adds r6, r6, r3
	adds r1, r1, r6
	bl LoadObjPaletteBank
	adds r4, r7, #0x0
	adds r4, #0x40
	ldr r5, _080B6FD8 @ =0x09EF37DC
	ldr r6, _080B6FDC @ =0x09EF377C
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x20]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x24]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x28]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x2C]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x30]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x34]
	ldr r0, _080B6FE0 @ =0x09EF37F4
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x38]
	movs r2, #0x00
	movs r1, #0x07
	ldr r3, _080B6FE4 @ =0x00000107
	adds r0, r7, r3
_080B6F84:
	strb r2, [r0, #0x00]
	subs r0, #0x01
	subs r1, #0x01
	cmp r1, #0x00
	bge _080B6F84
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r7, r1
	movs r1, #0x01
	bl TaskPoolInit
	bl func_080B75E8
	ldr r1, _080B6FE8 @ =0x0203AB38
	ldr r0, _080B6FEC @ =0xFFFFFD67
	str r0, [r1, #0x00]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r1, r7, r2
	movs r0, #0x19
	str r0, [r1, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B6FB8: .4byte 0x096FAE84
_080B6FBC: .4byte 0x09648EA4
_080B6FC0: .4byte 0x096BE464
_080B6FC4: .4byte 0x096FB084
_080B6FC8: .4byte 0x050001E0
_080B6FCC: .4byte 0x09624F72
_080B6FD0: .4byte 0x0962848A
_080B6FD4: .4byte 0xFFFFFE20
_080B6FD8: .4byte 0x09EF37DC
_080B6FDC: .4byte 0x09EF377C
_080B6FE0: .4byte 0x09EF37F4
_080B6FE4: .4byte 0x00000107
_080B6FE8: .4byte 0x0203AB38
_080B6FEC: .4byte 0xFFFFFD67
.syntax divided
