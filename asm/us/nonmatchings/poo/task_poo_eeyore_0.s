.syntax unified
	.align 2, 0
	.global task_poo_eeyore_0
	.thumb
	.thumb_func
	.type task_poo_eeyore_0, %function
task_poo_eeyore_0: @ 080CDD0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, _080CDD48 @ =0x00082700
	str r0, [r5, #0x24]
	ldr r0, _080CDD4C @ =0x00047E00
	str r0, [r5, #0x28]
	movs r4, #0x00
	str r4, [r5, #0x2C]
	str r4, [r5, #0x30]
	ldr r0, _080CDD50 @ =0x09EF5D68
	movs r1, #0x10
	bl func_08003524
	adds r1, r5, #0x0
	adds r1, #0xA8
	strh r0, [r1, #0x00]
	str r4, [r5, #0x00]
	str r4, [r5, #0x04]
	movs r0, #0x02
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CDD54
	adds r0, r5, #0x0
	adds r0, #0xA4
	str r4, [r0, #0x00]
	adds r6, r0, #0x0
	b _080CDD5E
	.byte 0x00, 0x00
_080CDD48: .4byte 0x00082700
_080CDD4C: .4byte 0x00047E00
_080CDD50: .4byte 0x09EF5D68
_080CDD54:
	adds r1, r5, #0x0
	adds r1, #0xA4
	movs r0, #0x04
	str r0, [r1, #0x00]
	adds r6, r1, #0x0
_080CDD5E:
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldr r1, _080CDDC8 @ =0x09EF5DA8
	ldr r2, _080CDDCC @ =0x09EF5D68
	adds r0, r4, #0x0
	bl AnimInit
	ldrh r1, [r6, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x08]
	adds r4, #0x84
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080CDDD0 @ =0x09EF4928
	adds r2, r5, #0x0
	adds r2, #0x24
	adds r0, r4, #0x0
	bl TaskCreate
	subs r4, #0x5C
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x10
	movs r3, #0x10
	bl func_080122AC
	ldr r1, [r5, #0x24]
	ldr r2, [r5, #0x28]
	ldr r3, [r5, #0x2C]
	adds r0, r4, #0x0
	bl func_08012324
	adds r1, r5, #0x0
	adds r1, #0xAC
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0x02
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CDDD4
	adds r0, r4, #0x0
	movs r1, #0x38
	b _080CDDD8
_080CDDC8: .4byte 0x09EF5DA8
_080CDDCC: .4byte 0x09EF5D68
_080CDDD0: .4byte 0x09EF4928
_080CDDD4:
	adds r0, r4, #0x0
	movs r1, #0x39
_080CDDD8:
	bl func_080D2E28
	adds r1, r5, #0x0
	adds r1, #0xAE
	strh r0, [r1, #0x00]
	ldrh r0, [r1, #0x00]
	movs r1, #0x01
	bl func_080D2E70
	adds r1, r5, #0x0
	adds r1, #0xAA
	movs r0, #0x00
	strh r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
