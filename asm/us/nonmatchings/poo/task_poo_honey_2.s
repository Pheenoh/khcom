.syntax unified
	.align 2, 0
	.global task_poo_honey_2
	.thumb
	.thumb_func
	.type task_poo_honey_2, %function
task_poo_honey_2: @ 080CCFF0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	cmp r1, #0x1D
	bls _080CD00A
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080CD0EE
_080CD00A:
	ldr r2, [r4, #0x24]
	asrs r2, r2, #0x08
	ldr r0, _080CD070 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080CD074 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r2, r2, #0x10
	asrs r7, r2, #0x10
	lsls r1, r1, #0x10
	asrs r6, r1, #0x10
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x18
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080CD078
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CD0EE
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x74
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0xD0
	bl func_080CCBD4
	b _080CD0EE
	.byte 0x00, 0x00
_080CD070: .4byte 0x0203C40C
_080CD074: .4byte 0x0203C3F8
_080CD078:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CD0AE
	ldrh r0, [r4, #0x20]
	ldr r1, _080CD0F8 @ =0x097339E8
	bl AllocObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080CD0FC @ =0x09849B98
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x74
	movs r1, #0x0A
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
	adds r0, r4, #0x0
	adds r0, #0xD0
	ldr r1, _080CD100 @ =0x00001FA4
	adds r2, r4, #0x0
	adds r2, #0x34
	bl func_080CCB90
_080CD0AE:
	adds r0, r4, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	adds r2, r0, #0x0
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r5, _080CD104 @ =0xFFFFEFFC
	adds r0, r5, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl DrawSprite
	adds r4, #0xF4
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	adds r0, r4, #0x0
	bl TaskPoolDraw
_080CD0EE:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD0F8: .4byte 0x097339E8
_080CD0FC: .4byte 0x09849B98
_080CD100: .4byte 0x00001FA4
_080CD104: .4byte 0xFFFFEFFC
.syntax divided
