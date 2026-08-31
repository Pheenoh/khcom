.syntax unified
	.align 2, 0
	.global task_poo_pile_2
	.thumb
	.thumb_func
	.type task_poo_pile_2, %function
task_poo_pile_2: @ 080CD3A8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r1, [r5, #0x24]
	asrs r1, r1, #0x08
	ldr r0, _080CD438 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, [r5, #0x28]
	asrs r0, r0, #0x08
	ldr r2, _080CD43C @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsrs r0, r1, #0x10
	mov r9, r0
	movs r3, #0x80
	lsls r3, r3, #0x0D
	adds r1, r1, r3
	movs r0, #0x88
	lsls r0, r0, #0x11
	cmp r1, r0
	bhi _080CD3F2
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	movs r1, #0x24
	negs r1, r1
	mov r8, r0
	cmp r2, r1
	blt _080CD3F2
	cmp r2, #0xC4
	ble _080CD440
_080CD3F2:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080CD408
	ldr r0, [r5, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r5, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r5, #0x04]
_080CD408:
	adds r4, r5, #0x0
	adds r4, #0xCC
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080CD426
	adds r0, r5, #0x0
	adds r0, #0x34
	bl func_08012304
	adds r0, r5, #0x0
	adds r0, #0x90
	bl func_080CCBD4
	movs r0, #0x00
	strb r0, [r4, #0x00]
_080CD426:
	adds r4, r5, #0x0
	adds r4, #0xB4
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	adds r0, r4, #0x0
	bl TaskPoolDraw
	b _080CD4FC
_080CD438: .4byte 0x0203C40C
_080CD43C: .4byte 0x0203C3F8
_080CD440:
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r5, #0x08]
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080CD466
	ldr r0, _080CD4BC @ =0x09742CC2
	movs r1, #0xC0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r5, #0x00]
	ldr r0, _080CD4C0 @ =0x09849BF8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
_080CD466:
	adds r2, r5, #0x0
	adds r2, #0xB0
	ldrh r0, [r2, #0x00]
	cmp r0, #0x07
	beq _080CD4C8
	ldr r0, [r5, #0x28]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r3, _080CD4C4 @ =0xFFFFEFFC
	adds r1, r3, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	adds r6, r5, #0x0
	adds r6, #0xCC
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	bne _080CD4CA
	adds r4, r5, #0x0
	adds r4, #0x34
	ldrh r0, [r2, #0x00]
	bl func_080CD1F8
	adds r3, r0, #0x0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r2, #0x04
	bl func_080122AC
	adds r0, r5, #0x0
	adds r0, #0x90
	movs r1, #0x90
	lsls r1, r1, #0x02
	adds r2, r5, #0x0
	adds r2, #0x24
	bl func_080CCB90
	movs r0, #0x01
	strb r0, [r6, #0x00]
	b _080CD4CA
	.byte 0x00, 0x00
_080CD4BC: .4byte 0x09742CC2
_080CD4C0: .4byte 0x09849BF8
_080CD4C4: .4byte 0xFFFFEFFC
_080CD4C8:
	ldr r7, _080CD50C @ =0x0000FFF1
_080CD4CA:
	mov r1, r9
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	asrs r1, r2, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	str r7, [sp, #0x00C]
	bl DrawSprite
	adds r4, r5, #0x0
	adds r4, #0xB4
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	adds r0, r4, #0x0
	bl TaskPoolDraw
_080CD4FC:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD50C: .4byte 0x0000FFF1
.syntax divided
