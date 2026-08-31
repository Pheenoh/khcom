.syntax unified
	.align 2, 0
	.global task_poo_poohstump_2
	.thumb
	.thumb_func
	.type task_poo_poohstump_2, %function
task_poo_poohstump_2: @ 080CD754
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r1, [r4, #0x24]
	asrs r1, r1, #0x08
	ldr r0, _080CD7B4 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x28]
	asrs r0, r0, #0x08
	ldr r2, _080CD7B8 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r6, r1, #0x10
	movs r0, #0xA0
	lsls r0, r0, #0x0F
	adds r1, r1, r0
	movs r0, #0xC8
	lsls r0, r0, #0x11
	cmp r1, r0
	bhi _080CD794
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	movs r0, #0x18
	negs r0, r0
	cmp r5, r0
	blt _080CD794
	cmp r5, #0xB8
	ble _080CD7BC
_080CD794:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CD816
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08012304
	b _080CD816
_080CD7B4: .4byte 0x0203C40C
_080CD7B8: .4byte 0x0203C3F8
_080CD7BC:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CD7E6
	ldr r0, _080CD820 @ =0x09755F54
	movs r1, #0xA0
	lsls r1, r1, #0x02
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080CD824 @ =0x09849D38
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x07
	movs r2, #0x07
	movs r3, #0x0E
	bl func_080122AC
_080CD7E6:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	ldr r4, _080CD828 @ =0xFFFFFB00
	adds r1, r1, r4
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080CD82C @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl DrawSprite
_080CD816:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD820: .4byte 0x09755F54
_080CD824: .4byte 0x09849D38
_080CD828: .4byte 0xFFFFFB00
_080CD82C: .4byte 0xFFFFEFFC
.syntax divided
