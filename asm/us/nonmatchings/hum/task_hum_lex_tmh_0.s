.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh_0
	.thumb
	.thumb_func
	.type task_hum_lex_tmh_0, %function
task_hum_lex_tmh_0: @ 08056EE4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _08056F2C @ =0x09618478
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	movs r0, #0x80
	lsls r0, r0, #0x03
	ldr r1, _08056F30 @ =0x08C3724C
	bl AllocObjTiles
	str r0, [r6, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x08
	ldr r1, _08056F34 @ =0x09EE22B0
	ldr r2, _08056F38 @ =0x09EE2298
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	movs r0, #0x12
	ldsh r1, [r5, r0]
	cmp r1, #0x00
	beq _08056F3C
	adds r1, r6, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08056F42
	.byte 0x00, 0x00
_08056F2C: .4byte 0x09618478
_08056F30: .4byte 0x08C3724C
_08056F34: .4byte 0x09EE22B0
_08056F38: .4byte 0x09EE2298
_08056F3C:
	adds r0, r6, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
_08056F42:
	ldr r0, [r5, #0x00]
	str r0, [r6, #0x20]
	ldr r0, [r5, #0x04]
	str r0, [r6, #0x24]
	ldr r0, [r5, #0x08]
	str r0, [r6, #0x28]
	bl GetRandom
	ldr r5, _08056FD0 @ =0x02039B84
	ldr r4, [r5, #0x00]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r4, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x41
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _08056FD4 @ =0xFFFFE000
	adds r0, r0, r1
	ldr r1, [r4, #0x00]
	adds r1, r1, r0
	str r1, [r6, #0x34]
	bl GetRandom
	ldr r4, [r5, #0x00]
	movs r1, #0x9A
	lsls r1, r1, #0x01
	adds r4, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x21
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _08056FD8 @ =0xFFFFF000
	adds r0, r0, r1
	ldr r1, [r4, #0x00]
	adds r1, r1, r0
	str r1, [r6, #0x38]
	movs r0, #0x00
	str r0, [r6, #0x30]
	adds r2, r6, #0x0
	adds r2, #0x4A
	movs r1, #0x00
	strh r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x2D
	strb r1, [r0, #0x00]
	ldr r0, _08056FDC @ =0xFFFFF680
	str r0, [r6, #0x3C]
	ldr r0, _08056FE0 @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r6, #0x40]
	ldr r0, _08056FE4 @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x44]
	ldr r0, _08056FE8 @ =0x000002B1
	bl m4aSongNumStart
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08056FD0: .4byte 0x02039B84
_08056FD4: .4byte 0xFFFFE000
_08056FD8: .4byte 0xFFFFF000
_08056FDC: .4byte 0xFFFFF680
_08056FE0: .4byte 0x08B22BBC
_08056FE4: .4byte 0x08F69BA4
_08056FE8: .4byte 0x000002B1
.syntax divided
