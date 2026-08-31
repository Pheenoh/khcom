.syntax unified
	.align 2, 0
	.global task_poo_balloon_0
	.thumb
	.thumb_func
	.type task_poo_balloon_0, %function
task_poo_balloon_0: @ 080CBDA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r2, r1, #0x0
	str r2, [r6, #0x24]
	ldr r1, [r2, #0x00]
	ldr r0, _080CBDFC @ =0x0003FD00
	cmp r1, r0
	bne _080CBE14
	ldr r1, [r2, #0x04]
	ldr r0, _080CBE00 @ =0x00021B00
	cmp r1, r0
	bne _080CBE14
	ldr r5, _080CBE04 @ =0x09EF5E38
	adds r0, r5, #0x0
	movs r1, #0x03
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080CBE08 @ =0x0974B4D8
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080CBE0C @ =0x09849C98
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080CBE10 @ =0x09EF5E44
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	b _080CBE4C
	.byte 0x00, 0x00
_080CBDFC: .4byte 0x0003FD00
_080CBE00: .4byte 0x00021B00
_080CBE04: .4byte 0x09EF5E38
_080CBE08: .4byte 0x0974B4D8
_080CBE0C: .4byte 0x09849C98
_080CBE10: .4byte 0x09EF5E44
_080CBE14:
	ldr r5, _080CBE5C @ =0x09EF5AD0
	adds r0, r5, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080CBE60 @ =0x09732FB6
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080CBE64 @ =0x09849B78
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080CBE68 @ =0x09EF5AE0
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
_080CBE4C:
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CBE5C: .4byte 0x09EF5AD0
_080CBE60: .4byte 0x09732FB6
_080CBE64: .4byte 0x09849B78
_080CBE68: .4byte 0x09EF5AE0
.syntax divided
