.syntax unified
	.align 2, 0
	.global task_emy_16_p_0
	.thumb
	.thumb_func
	.type task_emy_16_p_0, %function
task_emy_16_p_0: @ 08039190
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	movs r0, #0x12
	ldsh r1, [r6, r0]
	cmp r1, #0x00
	beq _080391A8
	adds r1, r5, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _080391AE
_080391A8:
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
_080391AE:
	ldr r0, _080391F0 @ =0x08F699C4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	ldr r1, _080391F4 @ =0x08A20BCE
	movs r0, #0x80
	bl AllocObjTiles
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _080391F8 @ =0x09EE04B4
	ldr r2, _080391FC @ =0x09EE04AC
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x28]
	movs r0, #0x00
	str r0, [r5, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080391F0: .4byte 0x08F699C4
_080391F4: .4byte 0x08A20BCE
_080391F8: .4byte 0x09EE04B4
_080391FC: .4byte 0x09EE04AC
.syntax divided
