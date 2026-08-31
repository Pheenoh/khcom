.syntax unified
	.align 2, 0
	.global task_poo_freeballoon_0
	.thumb
	.thumb_func
	.type task_poo_freeballoon_0, %function
task_poo_freeballoon_0: @ 080CC194
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r2, r6, #0x0
	adds r2, #0x24
	adds r0, r1, #0x0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x6C
	adds r0, r1, #0x0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x34
	adds r0, r1, #0x0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x7C
	adds r0, r1, #0x0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x94
	str r1, [r0, #0x00]
	ldr r5, _080CC264 @ =0x09EF5AA0
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080CC268 @ =0x09732272
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080CC26C @ =0x09849B38
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080CC270 @ =0x09EF5AB4
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x08]
	ldr r5, _080CC274 @ =0x09EF5AB8
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080CC278 @ =0x0973291E
	bl AllocObjTiles
	str r0, [r6, #0x48]
	ldr r0, _080CC27C @ =0x09849B58
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x4C]
	adds r4, #0x48
	ldr r1, _080CC280 @ =0x09EF5ACC
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x50]
	adds r1, r6, #0x0
	adds r1, #0x90
	movs r0, #0x00
	strh r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CC264: .4byte 0x09EF5AA0
_080CC268: .4byte 0x09732272
_080CC26C: .4byte 0x09849B38
_080CC270: .4byte 0x09EF5AB4
_080CC274: .4byte 0x09EF5AB8
_080CC278: .4byte 0x0973291E
_080CC27C: .4byte 0x09849B58
_080CC280: .4byte 0x09EF5ACC
.syntax divided
