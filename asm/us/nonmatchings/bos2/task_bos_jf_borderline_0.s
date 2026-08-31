.syntax unified
	.align 2, 0
	.global task_bos_jf_borderline_0
	.thumb
	.thumb_func
	.type task_bos_jf_borderline_0, %function
task_bos_jf_borderline_0: @ 080C1424
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r4, r1, #0x0
	str r4, [r7, #0x00]
	bl func_080C1A48
	adds r3, r7, #0x0
	adds r3, #0xA8
	movs r0, #0xA0
	lsls r0, r0, #0x04
	str r0, [r3, #0x00]
	adds r5, r7, #0x0
	adds r5, #0xAC
	movs r0, #0xD8
	lsls r0, r0, #0x06
	str r0, [r5, #0x00]
	adds r2, r7, #0x0
	adds r2, #0x98
	adds r1, r7, #0x0
	adds r1, #0xA4
	ldr r0, [r4, #0x04]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r4, #0x08]
	ldr r1, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldr r0, [r4, #0x0C]
	ldr r1, [r5, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r1, r7, #0x0
	adds r1, #0xB0
	movs r2, #0x00
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r1, #0x02
	strh r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0xB4
	strb r2, [r0, #0x00]
	adds r0, #0x01
	strb r2, [r0, #0x00]
	ldr r0, _080C1548 @ =0x09682AA4
	movs r1, #0xA0
	lsls r1, r1, #0x06
	bl LoadObjTiles
	str r0, [r7, #0x04]
	ldr r0, _080C154C @ =0x096FB5A4
	movs r1, #0x60
	bl LoadObjPalette
	str r0, [r7, #0x08]
	adds r4, r7, #0x0
	adds r4, #0x1C
	ldr r5, _080C1550 @ =0x09EF3B40
	ldr r6, _080C1554 @ =0x09EF3A48
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x1B
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x0C]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x08
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x10]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x14]
	adds r4, #0x18
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x1C
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x18]
	adds r4, #0x1C
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x06
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r7, #0x7C]
	ldr r0, [r7, #0x08]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x00
	bl func_0801C298
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C1548: .4byte 0x09682AA4
_080C154C: .4byte 0x096FB5A4
_080C1550: .4byte 0x09EF3B40
_080C1554: .4byte 0x09EF3A48
.syntax divided
