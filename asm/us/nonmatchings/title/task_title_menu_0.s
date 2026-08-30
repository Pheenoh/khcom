.syntax unified
	.align 2, 0
	.global task_title_menu_0
	.thumb
	.thumb_func
	.type task_title_menu_0, %function
task_title_menu_0: @ 080D679C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	ldr r0, _080D67CC @ =0x02039BB0
	ldr r2, [r0, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r0, r2
	negs r0, r0
	asrs r7, r0, #0x1F
	movs r3, #0x20
	ands r7, r3
	str r1, [r6, #0x44]
	movs r4, #0x00
	ldsh r0, [r1, r4]
	cmp r0, #0x00
	bne _080D67D4
	ands r2, r3
	cmp r2, #0x00
	beq _080D67D0
	movs r0, #0x04
	str r0, [r6, #0x5C]
	strh r0, [r1, #0x00]
	b _080D67E8
	.byte 0x00, 0x00
_080D67CC: .4byte 0x02039BB0
_080D67D0:
	movs r0, #0x01
	b _080D67E6
_080D67D4:
	cmp r0, #0x03
	bne _080D67DC
	movs r0, #0x02
	b _080D67E6
_080D67DC:
	adds r0, r3, #0x0
	ands r0, r2
	cmp r0, #0x00
	beq _080D67E6
	movs r0, #0x03
_080D67E6:
	str r0, [r6, #0x5C]
_080D67E8:
	ldr r0, _080D68D8 @ =0x09773E1A
	movs r1, #0xB0
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r6, #0x00]
	ldr r4, _080D68DC @ =0x0984A7F8
	adds r0, r4, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	movs r2, #0x20
	bl func_080D5978
	ldr r0, _080D68E0 @ =0x09771DC0
	movs r1, #0xA0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r6, #0x08]
	ldr r0, _080D68E4 @ =0x097720F2
	movs r1, #0xB2
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r6, #0x0C]
	ldr r0, _080D68E8 @ =0x09772CC6
	movs r1, #0xE0
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r6, #0x10]
	ldr r4, _080D68EC @ =0x0984A778
	adds r4, r7, r4
	adds r0, r4, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x14]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x18]
	ldr r5, _080D68F0 @ =0x0984A7B8
	adds r5, r7, r5
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x1C]
	ldr r0, [r6, #0x14]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0x0
	movs r2, #0x20
	bl func_080D5978
	ldr r0, [r6, #0x1C]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0x0
	movs r2, #0x20
	bl func_080D5978
	adds r4, r6, #0x0
	adds r4, #0x2C
	ldr r1, _080D68F4 @ =0x09EF661C
	ldr r2, _080D68F8 @ =0x09EF6608
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r6, #0x20]
	ldr r1, _080D68FC @ =0x09EF6620
	ldr r2, [r6, #0x44]
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x24]
	ldr r1, _080D6900 @ =0x09EF663C
	movs r4, #0x00
	ldsh r0, [r2, r4]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x28]
	adds r4, r6, #0x0
	adds r4, #0x48
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _080D6904 @ =0x09EF4EA8
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D68D8: .4byte 0x09773E1A
_080D68DC: .4byte 0x0984A7F8
_080D68E0: .4byte 0x09771DC0
_080D68E4: .4byte 0x097720F2
_080D68E8: .4byte 0x09772CC6
_080D68EC: .4byte 0x0984A778
_080D68F0: .4byte 0x0984A7B8
_080D68F4: .4byte 0x09EF661C
_080D68F8: .4byte 0x09EF6608
_080D68FC: .4byte 0x09EF6620
_080D6900: .4byte 0x09EF663C
_080D6904: .4byte 0x09EF4EA8
.syntax divided
