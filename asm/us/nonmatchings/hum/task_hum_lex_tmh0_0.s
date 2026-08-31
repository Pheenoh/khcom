.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh0_0
	.thumb
	.thumb_func
	.type task_hum_lex_tmh0_0, %function
task_hum_lex_tmh0_0: @ 08057294
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _080572DC @ =0x09618478
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x03
	ldr r1, _080572E0 @ =0x08C3151E
	bl AllocObjTiles
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _080572E4 @ =0x09EE2288
	ldr r2, _080572E8 @ =0x09EE2250
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl AnimStart
	movs r0, #0x12
	ldsh r1, [r6, r0]
	cmp r1, #0x00
	beq _080572EC
	adds r1, r5, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _080572F2
	.byte 0x00, 0x00
_080572DC: .4byte 0x09618478
_080572E0: .4byte 0x08C3151E
_080572E4: .4byte 0x09EE2288
_080572E8: .4byte 0x09EE2250
_080572EC:
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
_080572F2:
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x28]
	movs r0, #0x0A
	str r0, [r5, #0x30]
	movs r0, #0x15
	strh r0, [r5, #0x34]
	movs r0, #0xAD
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
