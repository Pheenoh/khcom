.syntax unified
	.align 2, 0
	.global task_hum_lex_rock_0
	.thumb
	.thumb_func
	.type task_hum_lex_rock_0, %function
task_hum_lex_rock_0: @ 08057420
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r2, r1, #0x0
	movs r0, #0x12
	ldsh r1, [r2, r0]
	cmp r1, #0x00
	beq _0805743A
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r1, r5, r3
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08057442
_0805743A:
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r0, r5, r3
	strb r1, [r0, #0x00]
_08057442:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r1, r5, r3
	ldr r0, [r2, #0x04]
	str r0, [r1, #0x00]
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r2, #0x08]
	str r0, [r1, #0x00]
	movs r1, #0xB1
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r4, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r2, #0xB2
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strh r1, [r0, #0x00]
	ldr r0, _080574A4 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl LoadObjTiles
	movs r3, #0xAE
	lsls r3, r3, #0x02
	adds r1, r5, r3
	str r0, [r1, #0x00]
	ldr r0, _080574A8 @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	movs r2, #0xAF
	lsls r2, r2, #0x02
	adds r1, r5, r2
	str r0, [r1, #0x00]
	movs r3, #0xB0
	lsls r3, r3, #0x02
	adds r0, r5, r3
	strb r4, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080574A4: .4byte 0x08B22CE4
_080574A8: .4byte 0x08F69BA4
.syntax divided
