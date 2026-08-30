@ Generated with Luvdis v0.8.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros

	thumb_func_start task_title_logo_0
task_title_logo_0: @ 080D63EC
	push {lr}
	bl func_080D62A8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_title_logo_1
task_title_logo_1: @ 080D63F8
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D6280
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D642A
	ldr r2, _080D6434 @ =0x02034ECC
	ldrb r1, [r2, #0x00]
	cmp r1, #0x00
	bne _080D642A
	ldr r0, [r4, #0x48]
	subs r0, #0x4C
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x4C]
	adds r0, #0x06
	str r0, [r4, #0x4C]
	cmp r0, #0xFF
	ble _080D642A
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r4, #0x4C]
	str r1, [r4, #0x48]
	movs r0, #0x01
	strb r0, [r2, #0x00]
_080D642A:
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D6434: .4byte 0x02034ECC
	thumb_func_start task_title_logo_2
task_title_logo_2: @ 080D6438
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	movs r7, #0x00
	mov r10, r6
	movs r0, #0x00
	str r0, [sp, #0x010]
_080D644E:
	ldr r1, _080D64B8 @ =0x02039BB0
	mov r8, r1
	cmp r7, #0x01
	bne _080D6462
	ldr r1, [r1, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D64FA
_080D6462:
	mov r2, r8
	ldr r0, [r2, #0x08]
	movs r3, #0x80
	lsls r3, r3, #0x02
	mov r9, r3
	ands r0, r3
	movs r4, #0x50
	cmp r0, #0x00
	beq _080D6476
	movs r4, #0xA4
_080D6476:
	movs r1, #0x46
	cmp r7, #0x00
	bne _080D6486
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #0x09
	adds r0, r0, r4
	lsrs r4, r0, #0x10
_080D6486:
	cmp r7, #0x01
	bne _080D64C4
	ldr r2, [r6, #0x4C]
	cmp r2, #0x00
	beq _080D64FA
	movs r0, #0x00
	movs r1, #0x80
	lsls r1, r1, #0x01
	movs r3, #0x00
	bl func_08002CB4
	adds r5, r0, #0x0
	mov r1, r8
	ldr r0, [r1, #0x08]
	mov r2, r9
	ands r0, r2
	cmp r0, #0x00
	beq _080D64C0
	movs r1, #0x56
	lsls r0, r4, #0x10
	ldr r3, _080D64BC @ =0xFFFF0000
	adds r0, r0, r3
	lsrs r4, r0, #0x10
	b _080D64C6
	.byte 0x00, 0x00
_080D64B8: .4byte 0x02039BB0
_080D64BC: .4byte 0xFFFF0000
_080D64C0:
	movs r1, #0x57
	b _080D64C6
_080D64C4:
	movs r5, #0x00
_080D64C6:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r2, r6, #0x0
	adds r2, #0x08
	ldr r4, [sp, #0x010]
	adds r2, r2, r4
	ldr r2, [r2, #0x00]
	mov r3, r10
	ldr r3, [r3, #0x00]
	mov r8, r3
	adds r4, r6, #0x4
	ldr r3, [sp, #0x010]
	adds r4, r4, r3
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	adds r4, r7, #0x0
	adds r4, #0x14
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	mov r3, r8
	bl func_080023E0
_080D64FA:
	movs r4, #0x0C
	add r10, r4
	ldr r0, [sp, #0x010]
	adds r0, #0x0C
	str r0, [sp, #0x010]
	adds r7, #0x01
	cmp r7, #0x05
	ble _080D644E
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_title_logo_3
task_title_logo_3: @ 080D651C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	movs r7, #0x00
	movs r6, #0x05
_080D6526:
	ldr r0, [r4, #0x00]
	bl func_080028C0
	adds r0, r5, #0x4
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r4, #0x0C
	adds r7, #0x0C
	subs r6, #0x01
	cmp r6, #0x00
	bge _080D6526
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x10, 0xB5, 0x03, 0x1C, 0x0C, 0x1C, 0x12, 0x04, 0x12, 0x0C, 0x00, 0x2A, 0x0B, 0xD0
	.byte 0x18, 0x78, 0x99, 0x78, 0x09, 0x02, 0x40, 0x18, 0x20, 0x80, 0x02, 0x34, 0x04, 0x33, 0x10, 0x1F
	.byte 0x00, 0x04, 0x02, 0x0C, 0x00, 0x2A, 0xF3, 0xD1, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x01, 0x48
	.byte 0x00, 0x78, 0x70, 0x47, 0x00, 0x00, 0xCC, 0x4E, 0x03, 0x02
	thumb_func_start task_title_obj_0
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
	thumb_func_start task_title_obj_1
task_title_obj_1: @ 080D669C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	bl func_080D6294
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D66EE
	adds r1, r5, #0x0
	adds r1, #0x62
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D66BA
	subs r0, #0x01
	strh r0, [r1, #0x00]
	b _080D66EE
_080D66BA:
	adds r4, r5, #0x0
	adds r4, #0x60
	ldrh r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D66EE
	adds r0, r5, #0x0
	adds r0, #0x28
	ldr r1, [r5, #0x2C]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r1, [r5, #0x44]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D66EE
	ldr r1, _080D66F8 @ =0x02034ED0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080D66EE:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D66F8: .4byte 0x02034ED0
	thumb_func_start task_title_obj_2
task_title_obj_2: @ 080D66FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	adds r0, #0x48
	bl func_08005A64
	str r0, [r6, #0x20]
	movs r0, #0x00
	mov r8, r0
	adds r5, r6, #0x0
	movs r7, #0x00
_080D6716:
	adds r0, r6, #0x0
	adds r0, #0x10
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	movs r2, #0x0C
	ldsh r1, [r5, r2]
	adds r2, r6, #0x0
	adds r2, #0x08
	adds r2, r2, r7
	ldr r2, [r2, #0x00]
	ldr r3, [r5, #0x00]
	adds r4, r6, #0x4
	adds r4, r4, r7
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	mov r4, r8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	adds r5, #0x18
	adds r7, #0x18
	movs r0, #0x01
	add r8, r0
	mov r2, r8
	cmp r2, #0x01
	ble _080D6716
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start task_title_obj_3
task_title_obj_3: @ 080D6764
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	movs r7, #0x00
	movs r6, #0x02
_080D676E:
	ldr r0, [r4, #0x00]
	bl func_080028C0
	adds r0, r5, #0x4
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r4, #0x18
	adds r7, #0x18
	subs r6, #0x01
	cmp r6, #0x00
	bge _080D676E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00, 0x01, 0x48, 0x00, 0x78, 0x70, 0x47, 0x00, 0x00, 0xD0, 0x4E, 0x03, 0x02
	thumb_func_start task_title_menu_0
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
	thumb_func_start func_080D6908
func_080D6908: @ 080D6908
	movs r2, #0x00
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	ldr r3, _080D6940 @ =0x096FDCC8
	ldr r0, [r3, #0x00]
	cmp r1, r0
	beq _080D6930
_080D6916:
	lsls r0, r2, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _080D6938
	lsls r0, r0, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bne _080D6916
_080D6930:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _080D693A
_080D6938:
	movs r2, #0x00
_080D693A:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	bx lr
_080D6940: .4byte 0x096FDCC8
	thumb_func_start func_080D6944
func_080D6944: @ 080D6944
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _080D6980 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x20
	ands r0, r1
	movs r6, #0x01
	cmp r0, #0x00
	beq _080D6958
	movs r6, #0x02
_080D6958:
	bl func_08001390
	movs r1, #0x40
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _080D6984
	movs r0, #0x65
	bl func_0811FE70
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _080D69A6
	strh r6, [r4, #0x00]
	b _080D69A6
	.byte 0x00, 0x00
_080D6980: .4byte 0x02039BB0
_080D6984:
	bl func_08001390
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080D69A6
	movs r0, #0x65
	bl func_0811FE70
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r6
	ble _080D69A6
	strh r5, [r4, #0x00]
_080D69A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_start func_080D69AC
func_080D69AC: @ 080D69AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r6, r5, #0x0
	bl func_08001390
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080D69E4
	movs r0, #0x65
	bl func_0811FE70
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_080D6908
	lsls r0, r0, #0x10
	ldr r1, _080D69E0 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	cmp r0, #0x00
	bge _080D6A10
	adds r2, r5, #0x0
	b _080D6A10
_080D69E0: .4byte 0xFFFF0000
_080D69E4:
	bl func_08001390
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080D6A1C
	movs r0, #0x65
	bl func_0811FE70
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_080D6908
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r2, r0, #0x10
	lsls r1, r6, #0x10
	cmp r0, r1
	ble _080D6A10
	movs r2, #0x00
_080D6A10:
	ldr r0, _080D6A24 @ =0x096FDCC8
	lsls r1, r2, #0x10
	asrs r1, r1, #0x0E
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	strh r0, [r4, #0x00]
_080D6A1C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D6A24: .4byte 0x096FDCC8
	thumb_func_start task_title_menu_1
task_title_menu_1: @ 080D6A28
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x5C]
	cmp r0, #0x00
	bne _080D6A3A
	ldr r0, [r4, #0x44]
	bl func_080D6944
	b _080D6A54
_080D6A3A:
	cmp r0, #0x03
	bne _080D6A48
	ldr r0, [r4, #0x44]
	movs r1, #0x03
	bl func_080D69AC
	b _080D6A54
_080D6A48:
	cmp r0, #0x04
	bne _080D6A54
	ldr r0, [r4, #0x44]
	movs r1, #0x01
	bl func_080D69AC
_080D6A54:
	adds r0, r4, #0x0
	adds r0, #0x48
	bl func_08000EA4
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_start func_080D6A64
func_080D6A64: @ 080D6A64
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	adds r6, r0, #0x0
	movs r1, #0x20
	ldr r0, _080D6B10 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	ands r0, r1
	movs r2, #0x03
	cmp r0, #0x00
	bne _080D6A84
	movs r2, #0x02
	movs r1, #0x30
_080D6A84:
	lsls r0, r2, #0x10
	movs r5, #0x00
	mov r8, r0
	movs r0, #0x60
	adds r0, r0, r6
	mov r10, r0
	adds r2, r6, #0x0
	adds r2, #0x20
	str r2, [sp, #0x010]
	adds r3, r6, #0x0
	adds r3, #0x08
	str r3, [sp, #0x014]
	movs r7, #0x14
	adds r7, r7, r6
	mov r9, r7
	mov r0, r8
	cmp r0, #0x00
	ble _080D6AEE
	movs r7, #0xC8
	lsls r7, r7, #0x0F
_080D6AAC:
	mov r2, r10
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	ldr r2, _080D6B14 @ =0x09EF6668
	lsls r1, r5, #0x02
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r3, [r6, #0x00]
	ldr r1, [r6, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	lsrs r1, r7, #0x10
	str r1, [sp, #0x00C]
	adds r1, r4, #0x0
	bl func_080023E0
	adds r4, #0x18
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r7, r7, r0
	adds r5, #0x01
	mov r2, r8
	asrs r0, r2, #0x10
	cmp r5, r0
	blt _080D6AAC
_080D6AEE:
	ldr r0, _080D6B10 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080D6B18
	ldr r0, [r6, #0x44]
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x13
	movs r7, #0x80
	lsls r7, r7, #0x0E
	adds r0, r0, r7
	b _080D6B2A
	.byte 0x00, 0x00
_080D6B10: .4byte 0x02039BB0
_080D6B14: .4byte 0x09EF6668
_080D6B18:
	ldr r0, [r6, #0x44]
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x13
	movs r3, #0xC0
	lsls r3, r3, #0x0E
	adds r0, r0, r3
_080D6B2A:
	lsrs r1, r0, #0x10
	movs r5, #0x00
	lsls r1, r1, #0x10
	mov r8, r1
	ldr r4, [sp, #0x014]
	ldr r7, [sp, #0x010]
	str r7, [sp, #0x018]
	movs r6, #0x00
_080D6B3A:
	mov r1, r10
	movs r2, #0x00
	ldsh r0, [r1, r2]
	ldr r3, [sp, #0x018]
	ldm r3!, {r2}
	str r3, [sp, #0x018]
	ldm r4!, {r3}
	mov r7, r9
	adds r7, #0x04
	mov r9, r7
	subs r7, #0x04
	ldm r7!, {r1}
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	mov r7, r8
	asrs r1, r7, #0x10
	bl func_080023E0
	adds r5, #0x01
	cmp r5, #0x02
	ble _080D6B3A
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start func_080D6B7C
func_080D6B7C: @ 080D6B7C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r4, #0x10
	movs r6, #0x00
	ldr r7, _080D6C4C @ =0x09EF6668
	movs r0, #0x60
	adds r0, r0, r5
	mov r9, r0
_080D6B96:
	adds r0, r5, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, _080D6C50 @ =0x096FDCC8
	lsls r1, r6, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r7
	ldr r2, [r1, #0x00]
	ldr r3, [r5, #0x00]
	ldr r1, [r5, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	adds r1, r6, #0x0
	adds r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	adds r1, r4, #0x0
	bl func_080023E0
	adds r4, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r6, #0x01
	cmp r6, #0x03
	ble _080D6B96
	ldr r0, [r5, #0x44]
	movs r2, #0x00
	ldsh r0, [r0, r2]
	bl func_080D6908
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x13
	movs r6, #0x00
	movs r7, #0x14
	adds r7, r7, r5
	mov r8, r7
	movs r0, #0x08
	adds r0, r0, r5
	mov r10, r0
	adds r5, #0x20
	movs r2, #0x80
	lsls r2, r2, #0x0D
	adds r4, r1, r2
_080D6C06:
	mov r7, r9
	movs r1, #0x00
	ldsh r0, [r7, r1]
	ldm r5!, {r2}
	mov r7, r10
	adds r7, #0x04
	mov r10, r7
	subs r7, #0x04
	ldm r7!, {r3}
	mov r7, r8
	adds r7, #0x04
	mov r8, r7
	subs r7, #0x04
	ldm r7!, {r1}
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	asrs r1, r4, #0x10
	bl func_080023E0
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6C06
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D6C4C: .4byte 0x09EF6668
_080D6C50: .4byte 0x096FDCC8
	thumb_func_start func_080D6C54
func_080D6C54: @ 080D6C54
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r4, #0x30
	movs r6, #0x00
	ldr r7, _080D6D24 @ =0x09EF6668
	movs r0, #0x60
	adds r0, r0, r5
	mov r9, r0
_080D6C6E:
	adds r0, r5, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, _080D6D28 @ =0x096FDCC8
	lsls r1, r6, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r7
	ldr r2, [r1, #0x00]
	ldr r3, [r5, #0x00]
	ldr r1, [r5, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	adds r1, r6, #0x0
	adds r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	adds r1, r4, #0x0
	bl func_080023E0
	adds r4, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r6, #0x01
	cmp r6, #0x01
	ble _080D6C6E
	ldr r0, [r5, #0x44]
	movs r2, #0x00
	ldsh r0, [r0, r2]
	bl func_080D6908
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x13
	movs r6, #0x00
	movs r7, #0x14
	adds r7, r7, r5
	mov r8, r7
	movs r0, #0x08
	adds r0, r0, r5
	mov r10, r0
	adds r5, #0x20
	movs r2, #0xC0
	lsls r2, r2, #0x0E
	adds r4, r1, r2
_080D6CDE:
	mov r7, r9
	movs r1, #0x00
	ldsh r0, [r7, r1]
	ldm r5!, {r2}
	mov r7, r10
	adds r7, #0x04
	mov r10, r7
	subs r7, #0x04
	ldm r7!, {r3}
	mov r7, r8
	adds r7, #0x04
	mov r8, r7
	subs r7, #0x04
	ldm r7!, {r1}
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	asrs r1, r4, #0x10
	bl func_080023E0
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6CDE
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D6D24: .4byte 0x09EF6668
_080D6D28: .4byte 0x096FDCC8
	thumb_func_start func_080D6D2C
func_080D6D2C: @ 080D6D2C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _080D6DAC @ =0x09EF6668
	ldr r1, [r5, #0x44]
	movs r3, #0x00
	ldsh r1, [r1, r3]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r3, [r5, #0x00]
	ldr r1, [r5, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	movs r1, #0x64
	str r1, [sp, #0x00C]
	movs r1, #0x38
	bl func_080023E0
	movs r6, #0x00
	movs r7, #0xE0
	lsls r7, r7, #0x0E
_080D6D66:
	adds r0, r5, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r4, r6, #0x02
	adds r1, r5, #0x0
	adds r1, #0x20
	adds r1, r1, r4
	ldr r2, [r1, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x08
	adds r1, r1, r4
	ldr r3, [r1, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x14
	adds r1, r1, r4
	ldr r1, [r1, #0x00]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	asrs r1, r7, #0x10
	bl func_080023E0
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6D66
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D6DAC: .4byte 0x09EF6668
	thumb_func_start task_title_menu_2
task_title_menu_2: @ 080D6DB0
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x2C
	bl func_08005A64
	str r0, [r4, #0x20]
	ldr r1, _080D6DF4 @ =0x09EF6620
	ldr r2, [r4, #0x44]
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x24]
	ldr r1, _080D6DF8 @ =0x09EF663C
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x28]
	ldr r0, _080D6DFC @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D6E00
	adds r1, r4, #0x0
	adds r1, #0x60
	movs r0, #0x78
	strh r0, [r1, #0x00]
	b _080D6E06
	.byte 0x00, 0x00
_080D6DF4: .4byte 0x09EF6620
_080D6DF8: .4byte 0x09EF663C
_080D6DFC: .4byte 0x02039BB0
_080D6E00:
	adds r0, r4, #0x0
	adds r0, #0x60
	strh r1, [r0, #0x00]
_080D6E06:
	ldr r0, [r4, #0x5C]
	cmp r0, #0x00
	bne _080D6E14
	adds r0, r4, #0x0
	bl func_080D6A64
	b _080D6E32
_080D6E14:
	cmp r0, #0x03
	bne _080D6E20
	adds r0, r4, #0x0
	bl func_080D6B7C
	b _080D6E32
_080D6E20:
	cmp r0, #0x04
	bne _080D6E2C
	adds r0, r4, #0x0
	bl func_080D6C54
	b _080D6E32
_080D6E2C:
	adds r0, r4, #0x0
	bl func_080D6D2C
_080D6E32:
	adds r0, r4, #0x0
	adds r0, #0x48
	bl func_08000EE0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start task_title_menu_3
task_title_menu_3: @ 080D6E40
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, [r5, #0x00]
	bl func_080028C0
	ldr r0, [r5, #0x04]
	bl func_08002C10
	movs r6, #0x00
_080D6E52:
	lsls r4, r6, #0x02
	adds r0, r5, #0x0
	adds r0, #0x08
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6E52
	adds r0, r5, #0x0
	adds r0, #0x48
	bl func_08000F0C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_start task_title_lumichange_0
task_title_lumichange_0: @ 080D6E80
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080D6EA4 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080D6EB0
	ldr r0, _080D6EA8 @ =0x0977548C
	movs r1, #0x84
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D6EAC @ =0x0984A7D8
	b _080D6EBE
	.byte 0x00, 0x00
_080D6EA4: .4byte 0x02039BB0
_080D6EA8: .4byte 0x0977548C
_080D6EAC: .4byte 0x0984A7D8
_080D6EB0:
	ldr r0, _080D6ECC @ =0x09773426
	movs r1, #0x94
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D6ED0 @ =0x0984A7B8
_080D6EBE:
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
_080D6ECC: .4byte 0x09773426
_080D6ED0: .4byte 0x0984A7B8
	thumb_func_start task_title_lumichange_1
task_title_lumichange_1: @ 080D6ED4
	push {r4, r5, lr}
	add sp, #-0x008
	bl func_08007E50
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r1, _080D6F08 @ =0x096FDCE8
	mov r0, sp
	movs r2, #0x06
	bl _0811F030
	bl func_08001390
	movs r1, #0xC0
	lsls r1, r1, #0x02
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	beq _080D6F0C
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r1, r0
	beq _080D6F30
	b _080D6F52
	.byte 0x00, 0x00
_080D6F08: .4byte 0x096FDCE8
_080D6F0C:
	movs r3, #0x00
	mov r2, sp
	b _080D6F16
_080D6F12:
	adds r2, #0x02
	adds r3, #0x01
_080D6F16:
	cmp r3, #0x02
	bhi _080D6F52
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x00
	ldsh r1, [r2, r5]
	cmp r0, r1
	bge _080D6F12
	ldrh r4, [r2, #0x00]
	movs r0, #0x67
	bl func_0811FE70
	b _080D6F52
_080D6F30:
	movs r3, #0x02
	add r2, sp, #0x004
	b _080D6F3A
_080D6F36:
	subs r2, #0x02
	subs r3, #0x01
_080D6F3A:
	cmp r3, #0x00
	blt _080D6F52
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x00
	ldsh r1, [r2, r5]
	cmp r0, r1
	ble _080D6F36
	ldrh r4, [r2, #0x00]
	movs r0, #0x67
	bl func_0811FE70
_080D6F52:
	bl func_08001390
	movs r1, #0xC0
	lsls r1, r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D6F6C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	bl func_08007E5C
	bl func_080D5998
_080D6F6C:
	movs r0, #0x01
	add sp, #0x008
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start task_title_lumichange_2
task_title_lumichange_2: @ 080D6F78
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_08007E50
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _080D6FA4 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	ldr r1, _080D6FA8 @ =0x09EF6658
	cmp r0, #0x00
	beq _080D6F98
	ldr r1, _080D6FAC @ =0x09EF6684
_080D6F98:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x00
	bge _080D6FB0
	ldr r0, [r1, #0x00]
	b _080D6FBE
_080D6FA4: .4byte 0x02039BB0
_080D6FA8: .4byte 0x09EF6658
_080D6FAC: .4byte 0x09EF6684
_080D6FB0:
	cmp r0, #0x00
	bne _080D6FB8
	ldr r0, [r1, #0x04]
	b _080D6FBE
_080D6FB8:
	cmp r0, #0x00
	ble _080D6FC0
	ldr r0, [r1, #0x08]
_080D6FBE:
	str r0, [r4, #0x08]
_080D6FC0:
	ldr r0, _080D6FF8 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	movs r1, #0x00
	cmp r0, #0x00
	beq _080D6FD2
	movs r1, #0xF0
_080D6FD2:
	adds r0, r1, #0x0
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r1, [r4, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	movs r1, #0x64
	str r1, [sp, #0x00C]
	movs r1, #0x8F
	bl func_080023E0
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
_080D6FF8: .4byte 0x02039BB0
	thumb_func_start task_title_lumichange_3
task_title_lumichange_3: @ 080D6FFC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
