.syntax unified
	.align 2, 0
	.global task_status_cursor_0
	.thumb
	.thumb_func
	.type task_status_cursor_0, %function
task_status_cursor_0: @ 080D7E4C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	str r1, [r6, #0x48]
	ldr r5, _080D7EF8 @ =0x09EF68F0
	adds r0, r5, #0x0
	movs r1, #0x05
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D7EFC @ =0x097A1C54
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080D7F00 @ =0x0984B1D8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x08]
	adds r4, r6, #0x0
	adds r4, #0x18
	ldr r1, _080D7F04 @ =0x09EF6904
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x10]
	ldr r5, _080D7F08 @ =0x09EF6908
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D7F0C @ =0x097A2394
	bl AllocObjTiles
	str r0, [r6, #0x04]
	ldr r0, _080D7F10 @ =0x0984B1F8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x0C]
	adds r4, #0x18
	ldr r1, _080D7F14 @ =0x09EF691C
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x14]
	ldr r0, [r6, #0x48]
	ldrh r0, [r0, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x4C
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _080D7F1C
	ldr r1, _080D7F18 @ =0x096FDD8C
	movs r3, #0x00
	ldsh r0, [r2, r3]
	mvns r0, r0
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x58]
	str r0, [r6, #0x5C]
	movs r0, #0x80
	lsls r0, r0, #0x05
	b _080D7F36
_080D7EF8: .4byte 0x09EF68F0
_080D7EFC: .4byte 0x097A1C54
_080D7F00: .4byte 0x0984B1D8
_080D7F04: .4byte 0x09EF6904
_080D7F08: .4byte 0x09EF6908
_080D7F0C: .4byte 0x097A2394
_080D7F10: .4byte 0x0984B1F8
_080D7F14: .4byte 0x09EF691C
_080D7F18: .4byte 0x096FDD8C
_080D7F1C:
	movs r0, #0xC0
	lsls r0, r0, #0x05
	str r0, [r6, #0x58]
	str r0, [r6, #0x5C]
	ldr r0, [r6, #0x48]
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x0A
	movs r3, #0x90
	lsls r3, r3, #0x06
	adds r0, r0, r3
_080D7F36:
	str r0, [r6, #0x50]
	str r0, [r6, #0x54]
	adds r1, r6, #0x0
	adds r1, #0x4E
	movs r0, #0x00
	strh r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
