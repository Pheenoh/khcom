.syntax unified
	.align 2, 0
	.global task_poo_tigerstump_2
	.thumb
	.thumb_func
	.type task_poo_tigerstump_2, %function
task_poo_tigerstump_2: @ 080CD5E4
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r2, [r4, #0x24]
	asrs r2, r2, #0x08
	ldr r0, _080CD648 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r0, [r4, #0x28]
	ldr r1, _080CD64C @ =0xFFFFF800
	adds r0, r0, r1
	asrs r0, r0, #0x08
	ldr r1, _080CD650 @ =0x0203C3F8
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r2, r2, #0x10
	asrs r6, r2, #0x10
	movs r0, #0xC0
	lsls r0, r0, #0x0F
	adds r2, r2, r0
	movs r0, #0xD8
	lsls r0, r0, #0x11
	cmp r2, r0
	bhi _080CD628
	lsls r0, r1, #0x10
	asrs r5, r0, #0x10
	movs r0, #0x40
	negs r0, r0
	cmp r5, r0
	blt _080CD628
	cmp r5, #0xE0
	ble _080CD654
_080CD628:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CD6AE
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	bl func_08012304
	b _080CD6AE
_080CD648: .4byte 0x0203C40C
_080CD64C: .4byte 0xFFFFF800
_080CD650: .4byte 0x0203C3F8
_080CD654:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CD67E
	ldr r0, _080CD6B8 @ =0x097561E8
	movs r1, #0x80
	lsls r1, r1, #0x03
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080CD6BC @ =0x09849D38
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x34
	movs r1, #0x07
	movs r2, #0x0F
	movs r3, #0x18
	bl func_080122AC
_080CD67E:
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
	ldr r4, _080CD6C0 @ =0xFFFFF900
	adds r1, r1, r4
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080CD6C4 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r5, #0x0
	bl DrawSprite
_080CD6AE:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD6B8: .4byte 0x097561E8
_080CD6BC: .4byte 0x09849D38
_080CD6C0: .4byte 0xFFFFF900
_080CD6C4: .4byte 0xFFFFEFFC
.syntax divided
