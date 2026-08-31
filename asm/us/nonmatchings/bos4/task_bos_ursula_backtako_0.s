.syntax unified
	.align 2, 0
	.global task_bos_ursula_backtako_0
	.thumb
	.thumb_func
	.type task_bos_ursula_backtako_0, %function
task_bos_ursula_backtako_0: @ 080DD2DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldrb r1, [r1, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x22
	movs r0, #0x00
	strb r1, [r4, #0x00]
	str r0, [r6, #0x24]
	str r0, [r6, #0x28]
	adds r0, r6, #0x0
	adds r0, #0x2C
	adds r1, r6, #0x0
	adds r1, #0x30
	adds r2, r6, #0x0
	adds r2, #0x34
	adds r3, r6, #0x0
	bl func_080DD248
	movs r1, #0x00
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080DD30A
	movs r1, #0x01
_080DD30A:
	strb r1, [r4, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x38
	adds r1, r6, #0x0
	adds r1, #0x3C
	adds r2, r6, #0x0
	adds r2, #0x40
	adds r3, r6, #0x0
	bl func_080DD248
	movs r1, #0x00
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080DD328
	movs r1, #0x01
_080DD328:
	strb r1, [r4, #0x00]
	adds r0, r1, #0x0
	cmp r0, #0x00
	beq _080DD332
	ldr r0, _080DD394 @ =0x0000FFFC
_080DD332:
	strh r0, [r6, #0x20]
	ldr r5, _080DD398 @ =0x09EF6860
	adds r0, r5, #0x0
	movs r1, #0x08
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DD39C @ =0x0979E344
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080DD3A0 @ =0x0984B0F8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x08
	ldr r1, _080DD3A4 @ =0x09EF68A0
	adds r0, r4, #0x0
	adds r2, r5, #0x0
	bl AnimInit
	ldrh r1, [r6, #0x20]
	adds r1, #0x04
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	movs r2, #0x01
	bl AnimStart
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x14]
	bl __umodsi3
	adds r1, r0, #0x0
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_08005B44
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080DD394: .4byte 0x0000FFFC
_080DD398: .4byte 0x09EF6860
_080DD39C: .4byte 0x0979E344
_080DD3A0: .4byte 0x0984B0F8
_080DD3A4: .4byte 0x09EF68A0
.syntax divided
