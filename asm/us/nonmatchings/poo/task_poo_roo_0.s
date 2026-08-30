.syntax unified
	.align 2, 0
	.global task_poo_roo_0
	.thumb
	.thumb_func
	.type task_poo_roo_0, %function
task_poo_roo_0: @ 080CEDF4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	ldr r0, _080CEE64 @ =0x0203C460
	str r5, [r0, #0x00]
	str r1, [r5, #0x38]
	ldr r4, _080CEE68 @ =0x09EF5EF8
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080CEE6C @ =0x09753154
	bl func_080028F8
	str r0, [r5, #0x00]
	ldr r0, _080CEE70 @ =0x09849CF8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	adds r6, r5, #0x0
	adds r6, #0x0C
	ldr r1, _080CEE74 @ =0x09EF5FA0
	adds r0, r6, #0x0
	adds r2, r4, #0x0
	bl func_08005968
	movs r0, #0x05
	bl func_080D2D50
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	beq _080CEE80
	ldr r0, _080CEE78 @ =0x00095F00
	str r0, [r5, #0x28]
	ldr r0, _080CEE7C @ =0x0004EE00
	str r0, [r5, #0x2C]
	movs r4, #0x00
	str r4, [r5, #0x30]
	adds r0, r6, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	adds r0, r5, #0x0
	adds r0, #0x24
	strb r4, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xB4
	movs r0, #0x03
	str r0, [r1, #0x00]
	adds r6, #0x1C
	b _080CEEA6
	.byte 0x00, 0x00
_080CEE64: .4byte 0x0203C460
_080CEE68: .4byte 0x09EF5EF8
_080CEE6C: .4byte 0x09753154
_080CEE70: .4byte 0x09849CF8
_080CEE74: .4byte 0x09EF5FA0
_080CEE78: .4byte 0x00095F00
_080CEE7C: .4byte 0x0004EE00
_080CEE80:
	adds r1, r5, #0x0
	adds r1, #0x28
	ldr r0, [r5, #0x38]
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x04
	movs r2, #0x00
	bl func_080059A4
	adds r0, r5, #0x0
	adds r0, #0x24
	strb r4, [r0, #0x00]
	adds r0, #0x90
	str r4, [r0, #0x00]
	adds r6, r5, #0x0
	adds r6, #0x28
_080CEEA6:
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	str r0, [r5, #0x08]
	adds r4, r5, #0x0
	adds r4, #0x98
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080CEF00 @ =0x09EF4928
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl func_08000E14
	subs r4, #0x5C
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x04
	movs r3, #0x20
	bl func_080122AC
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2C]
	ldr r3, [r5, #0x30]
	adds r0, r4, #0x0
	bl func_08012324
	movs r0, #0x05
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CEEFA
	adds r0, r4, #0x0
	movs r1, #0x3A
	bl func_080D2E28
	adds r1, r5, #0x0
	adds r1, #0xB8
	strh r0, [r1, #0x00]
_080CEEFA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CEF00: .4byte 0x09EF4928
.syntax divided
