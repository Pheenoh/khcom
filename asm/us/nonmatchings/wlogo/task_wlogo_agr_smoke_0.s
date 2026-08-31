.syntax unified
	.align 2, 0
	.global task_wlogo_agr_smoke_0
	.thumb
	.thumb_func
	.type task_wlogo_agr_smoke_0, %function
task_wlogo_agr_smoke_0: @ 080B6408
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x08
	str r0, [r6, #0x24]
	movs r2, #0x02
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x08
	str r0, [r6, #0x28]
	ldrb r0, [r1, #0x06]
	adds r5, r6, #0x0
	adds r5, #0x30
	movs r2, #0x00
	strb r0, [r5, #0x00]
	ldrb r0, [r1, #0x07]
	adds r1, r6, #0x0
	adds r1, #0x31
	strb r0, [r1, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r6, #0x2C]
	strh r2, [r6, #0x32]
	movs r0, #0x1E
	strh r0, [r6, #0x34]
	ldr r0, _080B6478 @ =0x0961DC0E
	movs r1, #0xEF
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080B647C @ =0x096FADE4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080B6480 @ =0x09EF36AC
	ldr r2, _080B6484 @ =0x09EF3614
	adds r0, r4, #0x0
	bl AnimInit
	ldrb r1, [r5, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B6478: .4byte 0x0961DC0E
_080B647C: .4byte 0x096FADE4
_080B6480: .4byte 0x09EF36AC
_080B6484: .4byte 0x09EF3614
.syntax divided
