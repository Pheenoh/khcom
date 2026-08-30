.syntax unified
	.align 2, 0
	.global task_title_obj_0
	.thumb
	.thumb_func
	.type task_title_obj_0, %function
task_title_obj_0: @ 080D6580
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	ldr r5, _080D65C8 @ =0x02039BB0
	ldr r0, [r5, #0x08]
	movs r4, #0x80
	lsls r4, r4, #0x02
	ands r0, r4
	negs r0, r0
	asrs r6, r0, #0x1F
	movs r0, #0x20
	ands r6, r0
	ldr r0, _080D65CC @ =0x09771060
	movs r1, #0xF0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r7, #0x00]
	ldr r0, _080D65D0 @ =0x0984A718
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x04]
	ldr r0, _080D65D4 @ =0x09EF65E0
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x08]
	ldr r0, [r5, #0x08]
	ands r0, r4
	cmp r0, #0x00
	beq _080D65D8
	movs r0, #0xBA
	lsls r0, r0, #0x08
	str r0, [r7, #0x10]
	movs r0, #0x76
	b _080D65E0
_080D65C8: .4byte 0x02039BB0
_080D65CC: .4byte 0x09771060
_080D65D0: .4byte 0x0984A718
_080D65D4: .4byte 0x09EF65E0
_080D65D8:
	movs r0, #0xF4
	lsls r0, r0, #0x06
	str r0, [r7, #0x10]
	movs r0, #0x77
_080D65E0:
	strh r0, [r7, #0x0C]
	ldr r0, _080D667C @ =0x09771666
	movs r1, #0xE0
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r7, #0x18]
	ldr r5, _080D6680 @ =0x0984A778
	adds r5, r6, r5
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x1C]
	ldr r0, _080D6684 @ =0xFFFF8800
	str r0, [r7, #0x28]
	movs r0, #0xF8
	lsls r0, r0, #0x07
	str r0, [r7, #0x2C]
	movs r6, #0x00
	movs r0, #0x00
	mov r8, r0
	movs r0, #0xA0
	strh r0, [r7, #0x24]
	adds r4, r7, #0x0
	adds r4, #0x48
	ldr r1, _080D6688 @ =0x09EF6604
	ldr r2, _080D668C @ =0x09EF65F0
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r7, #0x20]
	ldr r0, _080D6690 @ =0x0977143A
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r7, #0x30]
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x34]
	ldr r0, _080D6694 @ =0x09EF65E8
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x38]
	movs r0, #0xAC
	lsls r0, r0, #0x09
	str r0, [r7, #0x40]
	movs r0, #0xB8
	lsls r0, r0, #0x08
	str r0, [r7, #0x44]
	movs r0, #0x91
	strh r0, [r7, #0x3C]
	adds r1, r7, #0x0
	adds r1, #0x60
	movs r0, #0x1E
	strh r0, [r1, #0x00]
	ldr r0, _080D6698 @ =0x02034ED0
	strb r6, [r0, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x62
	mov r1, r8
	strh r1, [r0, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D667C: .4byte 0x09771666
_080D6680: .4byte 0x0984A778
_080D6684: .4byte 0xFFFF8800
_080D6688: .4byte 0x09EF6604
_080D668C: .4byte 0x09EF65F0
_080D6690: .4byte 0x0977143A
_080D6694: .4byte 0x09EF65E8
_080D6698: .4byte 0x02034ED0
.syntax divided
