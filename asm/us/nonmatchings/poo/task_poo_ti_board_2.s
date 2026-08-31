.syntax unified
	.align 2, 0
	.global task_poo_ti_board_2
	.thumb
	.thumb_func
	.type task_poo_ti_board_2, %function
task_poo_ti_board_2: @ 080CF7C0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r1, [r4, #0x0C]
	asrs r1, r1, #0x08
	ldr r0, _080CF814 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x10]
	asrs r0, r0, #0x08
	ldr r2, _080CF818 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r7, r1, #0x10
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	movs r0, #0x08
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x10
	movs r3, #0x01
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080CF81C
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CF864
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl func_08012304
	b _080CF864
_080CF814: .4byte 0x0203C40C
_080CF818: .4byte 0x0203C3F8
_080CF81C:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CF83A
	ldr r0, _080CF86C @ =0x09849D58
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r0, r4, #0x0
	adds r0, #0x1C
	movs r1, #0x07
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
_080CF83A:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x10]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080CF870 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl DrawSprite
_080CF864:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CF86C: .4byte 0x09849D58
_080CF870: .4byte 0xFFFFEFFC
.syntax divided
