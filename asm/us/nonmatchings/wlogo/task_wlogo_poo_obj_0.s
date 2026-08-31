.syntax unified
	.align 2, 0
	.global task_wlogo_poo_obj_0
	.thumb
	.thumb_func
	.type task_wlogo_poo_obj_0, %function
task_wlogo_poo_obj_0: @ 080B6C00
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r6, #0x41
	movs r4, #0x00
	strb r1, [r6, #0x00]
	ldr r0, _080B6CA8 @ =0x096249F4
	movs r1, #0xE0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080B6CAC @ =0x096FAE64
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	movs r0, #0x82
	lsls r0, r0, #0x08
	str r0, [r5, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x07
	str r0, [r5, #0x28]
	ldr r3, _080B6CB0 @ =0x09619A04
	ldrb r0, [r6, #0x00]
	movs r2, #0x64
	muls r0, r2
	adds r1, r3, #0x4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x2C]
	ldrb r0, [r6, #0x00]
	muls r0, r2
	adds r1, #0x04
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x30]
	ldrb r0, [r6, #0x00]
	muls r0, r2
	adds r1, #0x04
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x34]
	ldrb r0, [r6, #0x00]
	muls r0, r2
	adds r1, #0x04
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x38]
	movs r1, #0x00
	strh r4, [r5, #0x3C]
	strh r4, [r5, #0x3E]
	adds r0, r5, #0x0
	adds r0, #0x40
	strb r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x42
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _080B6CB4 @ =0x09EF1AEC
	ldrb r0, [r6, #0x00]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	adds r6, #0x02
	strb r0, [r6, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldr r1, _080B6CB8 @ =0x09EF376C
	ldr r2, _080B6CBC @ =0x09EF3734
	adds r0, r4, #0x0
	bl AnimInit
	ldrb r1, [r6, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B6CA8: .4byte 0x096249F4
_080B6CAC: .4byte 0x096FAE64
_080B6CB0: .4byte 0x09619A04
_080B6CB4: .4byte 0x09EF1AEC
_080B6CB8: .4byte 0x09EF376C
_080B6CBC: .4byte 0x09EF3734
.syntax divided
