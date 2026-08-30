.syntax unified
	.align 2, 0
	.global task_poo_wagonwheel_2
	.thumb
	.thumb_func
	.type task_poo_wagonwheel_2, %function
task_poo_wagonwheel_2: @ 080D07F0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x24]
	asrs r0, r0, #0x08
	ldr r1, _080D0858 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, [r5, #0x28]
	asrs r1, r1, #0x08
	ldr r2, [r5, #0x2C]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080D085C @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	lsrs r6, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x10
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x20
	movs r3, #0x00
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D0864
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080D08D8
	ldr r0, [r5, #0x00]
	bl func_080028C0
	ldr r0, [r5, #0x04]
	bl func_08002C10
	movs r0, #0x00
	str r0, [r5, #0x04]
	ldrh r0, [r5, #0x36]
	cmp r0, #0x03
	bne _080D08D8
	movs r0, #0x04
	strh r0, [r5, #0x36]
	ldr r0, _080D0860 @ =0x09758BF4
	str r0, [r5, #0x08]
	b _080D08D8
	.byte 0x00, 0x00
_080D0858: .4byte 0x0203C40C
_080D085C: .4byte 0x0203C3F8
_080D0860: .4byte 0x09758BF4
_080D0864:
	ldr r0, [r5, #0x04]
	cmp r0, #0x00
	bne _080D087E
	ldrh r0, [r5, #0x34]
	ldr r1, _080D0898 @ =0x09758C94
	bl func_080028F8
	str r0, [r5, #0x00]
	ldr r0, _080D089C @ =0x09849DD8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
_080D087E:
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D08A4
	ldr r4, _080D08A0 @ =0x02034E28
	bl func_080D06BC
	subs r0, #0x01
	strh r0, [r4, #0x00]
	b _080D08B4
	.byte 0x00, 0x00
_080D0898: .4byte 0x09758C94
_080D089C: .4byte 0x09849DD8
_080D08A0: .4byte 0x02034E28
_080D08A4:
	ldr r2, _080D08E0 @ =0x02034E28
	ldr r1, [r5, #0x28]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _080D08E4 @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
	strh r0, [r2, #0x00]
_080D08B4:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _080D08E0 @ =0x02034E28
	ldrh r4, [r4, #0x00]
	str r4, [sp, #0x00C]
	bl func_080023E0
_080D08D8:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D08E0: .4byte 0x02034E28
_080D08E4: .4byte 0xFFFFEFFC
.syntax divided
