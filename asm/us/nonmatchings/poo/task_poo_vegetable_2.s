.syntax unified
	.align 2, 0
	.global task_poo_vegetable_2
	.thumb
	.thumb_func
	.type task_poo_vegetable_2, %function
task_poo_vegetable_2: @ 080CFD44
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r1, [r4, #0x24]
	asrs r1, r1, #0x08
	ldr r0, _080CFDA0 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x28]
	asrs r0, r0, #0x08
	ldr r2, _080CFDA4 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r7, r1, #0x10
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	movs r0, #0x30
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x20
	movs r3, #0x28
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080CFDA8
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CFDFA
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_08012304
	b _080CFDFA
_080CFDA0: .4byte 0x0203C40C
_080CFDA4: .4byte 0x0203C3F8
_080CFDA8:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CFDD0
	ldrh r0, [r4, #0x34]
	ldr r1, _080CFE04 @ =0x09756E28
	bl AllocObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080CFE08 @ =0x09849DB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x38
	movs r1, #0x07
	movs r2, #0x26
	movs r3, #0x0C
	bl func_080122AC
_080CFDD0:
	ldr r2, [r4, #0x08]
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
	ldr r4, _080CFE0C @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl DrawSprite
_080CFDFA:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CFE04: .4byte 0x09756E28
_080CFE08: .4byte 0x09849DB8
_080CFE0C: .4byte 0xFFFFEFFC
.syntax divided
