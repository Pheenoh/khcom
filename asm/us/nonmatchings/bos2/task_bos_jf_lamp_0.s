.syntax unified
	.align 2, 0
	.global task_bos_jf_lamp_0
	.thumb
	.thumb_func
	.type task_bos_jf_lamp_0, %function
task_bos_jf_lamp_0: @ 080BDBDC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r2, r1, #0x0
	str r2, [r7, #0x00]
	movs r0, #0x80
	str r0, [r7, #0x28]
	ldr r5, _080BDC8C @ =0x09682AA4
	movs r6, #0xA0
	lsls r6, r6, #0x06
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl LoadObjTiles
	str r0, [r7, #0x04]
	ldr r4, _080BDC90 @ =0x09EF3A48
	ldr r0, [r4, #0x30]
	str r0, [r7, #0x08]
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl LoadObjTiles
	str r0, [r7, #0x0C]
	ldr r0, [r4, #0x38]
	str r0, [r7, #0x10]
	ldr r0, _080BDC94 @ =0x096FB5A4
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r7, #0x14]
	ldr r0, _080BDC98 @ =0x08F69BC4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x14]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	movs r5, #0x00
	movs r4, #0x00
	strh r4, [r7, #0x2E]
	strh r4, [r7, #0x1C]
	strh r4, [r7, #0x1E]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x79
	bl __umodsi3
	movs r1, #0xF0
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	strh r4, [r7, #0x22]
	adds r0, r7, #0x0
	adds r0, #0x24
	movs r1, #0x01
	strb r1, [r0, #0x00]
	adds r0, #0x09
	strb r1, [r0, #0x00]
	adds r0, #0x05
	strb r5, [r0, #0x00]
	strh r4, [r7, #0x34]
	str r4, [r7, #0x38]
	adds r0, #0x10
	strh r4, [r0, #0x00]
	adds r4, r7, #0x0
	adds r4, #0x44
	adds r0, r4, #0x0
	bl TaskPoolInit
	ldr r1, _080BDC9C @ =0x09EDAE88
	ldr r2, [r7, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r2, r2, r0
	adds r0, r4, #0x0
	bl TaskCreate
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BDC8C: .4byte 0x09682AA4
_080BDC90: .4byte 0x09EF3A48
_080BDC94: .4byte 0x096FB5A4
_080BDC98: .4byte 0x08F69BC4
_080BDC9C: .4byte 0x09EDAE88
.syntax divided
