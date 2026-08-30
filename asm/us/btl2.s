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

	thumb_func_start task_btl_shadow_0
task_btl_shadow_0: @ 0802F4EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x08]
	ldr r5, [r1, #0x34]
	ldr r6, [r1, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x0C
	adds r0, r5, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0802F520
	ldr r0, _0802F518 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _0802F51C @ =0x08B22CBC
	b _0802F55A
	.byte 0x00, 0x00
_0802F518: .4byte 0x08B22CE4
_0802F51C: .4byte 0x08B22CBC
_0802F520:
	movs r0, #0x80
	lsls r0, r0, #0x0A
	adds r1, r5, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0802F54C
	ldr r0, _0802F544 @ =0x08B22EFE
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _0802F548 @ =0x08B22EE4
	b _0802F55A
	.byte 0x00, 0x00
_0802F544: .4byte 0x08B22EFE
_0802F548: .4byte 0x08B22EE4
_0802F54C:
	ldr r0, _0802F56C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _0802F570 @ =0x08B22BA8
_0802F55A:
	str r0, [r4, #0x0C]
	ldr r0, _0802F574 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0802F56C: .4byte 0x08B22BBC
_0802F570: .4byte 0x08B22BA8
_0802F574: .4byte 0x08F69BA4
	thumb_func_start task_btl_shadow_1
task_btl_shadow_1: @ 0802F578
	movs r0, #0x01
	bx lr
	thumb_func_start task_btl_shadow_2
task_btl_shadow_2: @ 0802F57C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r5, [r6, #0x08]
	adds r0, r5, #0x0
	adds r0, #0xCC
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0802F63E
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r3, #0x04
	ands r0, r2
	ands r1, r3
	orrs r0, r1
	cmp r0, #0x00
	bne _0802F63E
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _0802F5D0
	ldr r0, _0802F5CC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _0802F5D0
	movs r7, #0x00
	b _0802F606
	.byte 0x00, 0x00
_0802F5CC: .4byte 0x02039B84
_0802F5D0:
	ldr r1, [r5, #0x10]
	ldr r0, [r5, #0x0C]
	subs r0, r1, r0
	cmp r0, #0x00
	bge _0802F5DC
	adds r0, #0x7F
_0802F5DC:
	asrs r0, r0, #0x07
	movs r1, #0x80
	lsls r1, r1, #0x01
	subs r2, r1, r0
	ldr r0, _0802F64C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x24]
	muls r0, r2
	asrs r2, r0, #0x08
	cmp r2, #0x7F
	bgt _0802F5F4
	movs r2, #0x80
_0802F5F4:
	movs r3, #0x00
	cmp r2, r1
	ble _0802F5FC
	movs r3, #0x01
_0802F5FC:
	movs r0, #0x00
	adds r1, r2, #0x0
	bl func_08002CB4
	adds r7, r0, #0x0
_0802F606:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	adds r4, r5, #0x0
	adds r4, #0xCC
	ldrh r4, [r4, #0x00]
	str r4, [sp, #0x00C]
	bl func_080023E0
_0802F63E:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0802F64C: .4byte 0x02039B84
	thumb_func_start task_btl_shadow_3
task_btl_shadow_3: @ 0802F650
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
	thumb_func_start task_btl_hpply_0
task_btl_hpply_0: @ 0802F668
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, _0802F6A4 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0802F6BC
	ldr r0, _0802F6A8 @ =0x09618118
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x0C]
	movs r0, #0xA0
	lsls r0, r0, #0x02
	ldr r1, _0802F6AC @ =0x08B21438
	bl func_080028F8
	str r0, [r5, #0x10]
	ldr r0, _0802F6B0 @ =0x08B213F0
	str r0, [r5, #0x20]
	adds r4, r5, #0x0
	adds r4, #0x44
	ldr r1, _0802F6B4 @ =0x09EE12C8
	ldr r2, _0802F6B8 @ =0x09EE12BC
	adds r0, r4, #0x0
	bl func_08005968
	b _0802F6E4
	.byte 0x00, 0x00
_0802F6A4: .4byte 0x02039BB0
_0802F6A8: .4byte 0x09618118
_0802F6AC: .4byte 0x08B21438
_0802F6B0: .4byte 0x08B213F0
_0802F6B4: .4byte 0x09EE12C8
_0802F6B8: .4byte 0x09EE12BC
_0802F6BC:
	ldr r0, _0802F748 @ =0x08F683A4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x0C]
	movs r0, #0xA0
	lsls r0, r0, #0x02
	ldr r1, _0802F74C @ =0x08B20D6E
	bl func_080028F8
	str r0, [r5, #0x10]
	ldr r0, _0802F750 @ =0x08B20D20
	str r0, [r5, #0x20]
	adds r4, r5, #0x0
	adds r4, #0x44
	ldr r1, _0802F754 @ =0x09EE12B0
	ldr r2, _0802F758 @ =0x09EE12A4
	adds r0, r4, #0x0
	bl func_08005968
_0802F6E4:
	adds r6, r4, #0x0
	ldr r0, _0802F75C @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x08]
	movs r0, #0xA0
	lsls r0, r0, #0x02
	ldr r4, _0802F760 @ =0x08B24016
	adds r1, r4, #0x0
	bl func_080028F8
	str r0, [r5, #0x14]
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r1, r4, #0x0
	bl func_080028F8
	str r0, [r5, #0x18]
	movs r0, #0x80
	adds r1, r4, #0x0
	bl func_080028F8
	str r0, [r5, #0x1C]
	ldr r0, _0802F764 @ =0x08B23CBA
	str r0, [r5, #0x24]
	adds r4, r5, #0x0
	adds r4, #0x2C
	ldr r1, _0802F768 @ =0x09EE1498
	ldr r2, _0802F76C @ =0x09EE1420
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r6, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r2, _0802F770 @ =0x02039B84
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	movs r3, #0x2E
	ldsh r1, [r0, r3]
	adds r3, r4, #0x0
	cmp r1, #0x28
	bgt _0802F774
	adds r1, r5, #0x0
	adds r1, #0x64
	movs r0, #0x00
	b _0802F7F0
_0802F748: .4byte 0x08F683A4
_0802F74C: .4byte 0x08B20D6E
_0802F750: .4byte 0x08B20D20
_0802F754: .4byte 0x09EE12B0
_0802F758: .4byte 0x09EE12A4
_0802F75C: .4byte 0x08F69BA4
_0802F760: .4byte 0x08B24016
_0802F764: .4byte 0x08B23CBA
_0802F768: .4byte 0x09EE1498
_0802F76C: .4byte 0x09EE1420
_0802F770: .4byte 0x02039B84
_0802F774:
	cmp r1, #0x50
	bgt _0802F782
	adds r2, r5, #0x0
	adds r2, #0x64
	movs r1, #0x00
	movs r0, #0x01
	b _0802F7CA
_0802F782:
	cmp r1, #0x78
	bgt _0802F790
	adds r2, r5, #0x0
	adds r2, #0x64
	movs r1, #0x00
	movs r0, #0x02
	b _0802F7CA
_0802F790:
	cmp r1, #0xA0
	bgt _0802F79E
	adds r2, r5, #0x0
	adds r2, #0x64
	movs r1, #0x00
	movs r0, #0x03
	b _0802F7CA
_0802F79E:
	cmp r1, #0xC8
	bgt _0802F7AC
	adds r2, r5, #0x0
	adds r2, #0x64
	movs r1, #0x00
	movs r0, #0x04
	b _0802F7CA
_0802F7AC:
	cmp r1, #0xF0
	bgt _0802F7BA
	adds r2, r5, #0x0
	adds r2, #0x64
	movs r1, #0x00
	movs r0, #0x05
	b _0802F7CA
_0802F7BA:
	movs r0, #0x8C
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802F7D2
	adds r2, r5, #0x0
	adds r2, #0x64
	movs r1, #0x00
	movs r0, #0x06
_0802F7CA:
	strh r0, [r2, #0x00]
	str r1, [r5, #0x68]
	adds r4, r2, #0x0
	b _0802F852
_0802F7D2:
	movs r0, #0xA0
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802F7E2
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r1, #0x00
	b _0802F84A
_0802F7E2:
	movs r0, #0xB4
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802F7F8
	adds r1, r5, #0x0
	adds r1, #0x64
	movs r0, #0x01
_0802F7F0:
	strh r0, [r1, #0x00]
	str r0, [r5, #0x68]
	adds r4, r1, #0x0
	b _0802F852
_0802F7F8:
	movs r0, #0xC8
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802F808
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r1, #0x02
	b _0802F84A
_0802F808:
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	movs r2, #0x2E
	ldsh r1, [r0, r2]
	movs r0, #0xDC
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802F820
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r1, #0x03
	b _0802F84A
_0802F820:
	movs r0, #0xF0
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802F830
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r1, #0x04
	b _0802F84A
_0802F830:
	movs r0, #0x82
	lsls r0, r0, #0x02
	cmp r1, r0
	bgt _0802F840
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r1, #0x05
	b _0802F84A
_0802F840:
	movs r0, #0x8C
	lsls r0, r0, #0x02
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r1, #0x06
_0802F84A:
	strh r1, [r0, #0x00]
	movs r1, #0x01
	str r1, [r5, #0x68]
	adds r4, r0, #0x0
_0802F852:
	ldr r0, [r5, #0x68]
	cmp r0, #0x00
	bne _0802F8C4
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x06
	bhi _0802F8B6
	lsls r0, r0, #0x02
	ldr r1, _0802F86C @ =0x0802F870
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_0802F86C: .4byte 0x0802F870
	.byte 0x8C, 0xF8, 0x02, 0x08, 0x8C, 0xF8, 0x02, 0x08, 0x92, 0xF8, 0x02, 0x08, 0x98, 0xF8, 0x02, 0x08
	.byte 0x9E, 0xF8, 0x02, 0x08, 0xA4, 0xF8, 0x02, 0x08, 0xAA, 0xF8, 0x02, 0x08, 0x18, 0x1C, 0x01, 0x21
	.byte 0x0D, 0xE0, 0x18, 0x1C, 0x03, 0x21, 0x0A, 0xE0, 0x18, 0x1C, 0x05, 0x21, 0x07, 0xE0, 0x18, 0x1C
	.byte 0x07, 0x21, 0x04, 0xE0, 0x18, 0x1C, 0x09, 0x21, 0x01, 0xE0, 0x18, 0x1C, 0x0B, 0x21, 0x01, 0x22
	.byte 0xD6, 0xF7, 0x78, 0xF8, 0x04, 0xE0
_0802F8B6:
	adds r0, r3, #0x0
	movs r1, #0x0B
	movs r2, #0x01
	bl func_080059A4
	movs r0, #0x00
	b _0802F932
_0802F8C4:
	adds r0, r3, #0x0
	movs r1, #0x0B
	movs r2, #0x01
	bl func_080059A4
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x06
	bhi _0802F930
	lsls r0, r0, #0x02
	ldr r1, _0802F8E0 @ =0x0802F8E4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_0802F8E0: .4byte 0x0802F8E4
	.byte 0x00, 0xF9, 0x02, 0x08, 0x08, 0xF9, 0x02, 0x08, 0x10, 0xF9, 0x02, 0x08, 0x18, 0xF9, 0x02, 0x08
	.byte 0x20, 0xF9, 0x02, 0x08, 0x28, 0xF9, 0x02, 0x08, 0x30, 0xF9, 0x02, 0x08, 0x00, 0x48, 0x16, 0xE0
	.byte 0x7C, 0x3E, 0xB2, 0x08, 0x00, 0x48, 0x12, 0xE0, 0x8C, 0x3E, 0xB2, 0x08, 0x00, 0x48, 0x0E, 0xE0
	.byte 0x9C, 0x3E, 0xB2, 0x08, 0x00, 0x48, 0x0A, 0xE0, 0xAC, 0x3E, 0xB2, 0x08, 0x00, 0x48, 0x06, 0xE0
	.byte 0xBC, 0x3E, 0xB2, 0x08, 0x00, 0x48, 0x02, 0xE0, 0xD2, 0x3E, 0xB2, 0x08
_0802F930:
	ldr r0, _0802F960 @ =0x08B23EE8
_0802F932:
	str r0, [r5, #0x28]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r5, #0x00]
	movs r2, #0x00
	movs r1, #0x01
	strb r1, [r5, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x5C
	strb r1, [r0, #0x00]
	adds r0, #0x02
	movs r1, #0x00
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	adds r0, #0x02
	strh r2, [r0, #0x00]
	subs r0, #0x05
	strb r1, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0802F960: .4byte 0x08B23EE8
	thumb_func_start task_btl_hpply_1
task_btl_hpply_1: @ 0802F964
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldr r0, _0802F990 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r7, [r0, #0x7C]
	cmp r7, #0x00
	beq _0802F98A
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0802F994
_0802F98A:
	movs r0, #0x00
	b _0802FC18
	.byte 0x00, 0x00
_0802F990: .4byte 0x02039B84
_0802F994:
	ldr r0, [r5, #0x68]
	movs r1, #0x00
	mov r8, r1
	cmp r0, #0x01
	beq _0802F9A8
	ldr r0, [r5, #0x00]
	cmp r0, #0x3F
	bgt _0802F9A8
	movs r2, #0x01
	mov r8, r2
_0802F9A8:
	adds r0, r5, #0x0
	adds r0, #0x60
	movs r3, #0x2C
	ldsh r2, [r7, r3]
	movs r4, #0x00
	ldsh r1, [r0, r4]
	mov r9, r0
	adds r6, r5, #0x0
	adds r6, #0x5E
	cmp r2, r1
	bge _0802F9C2
	movs r0, #0x2C
	strh r0, [r6, #0x00]
_0802F9C2:
	movs r1, #0x00
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	beq _0802F9E0
	adds r4, r5, #0x0
	adds r4, #0x44
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl func_08005A00
	ldrh r0, [r6, #0x00]
	subs r0, #0x01
	strh r0, [r6, #0x00]
	b _0802FA04
_0802F9E0:
	mov r2, r8
	cmp r2, #0x00
	beq _0802F9F6
	adds r4, r5, #0x0
	adds r4, #0x44
	adds r0, r4, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_08005A00
	b _0802FA04
_0802F9F6:
	adds r4, r5, #0x0
	adds r4, #0x44
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_08005A00
_0802FA04:
	adds r6, r4, #0x0
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _0802FA1C
	movs r0, #0x00
	strb r0, [r5, #0x04]
	ldrh r1, [r7, #0x2C]
	adds r0, r5, #0x0
	adds r0, #0x62
	strh r1, [r0, #0x00]
	adds r2, r0, #0x0
	b _0802FA5C
_0802FA1C:
	adds r0, r5, #0x0
	adds r0, #0x62
	ldrh r4, [r0, #0x00]
	movs r1, #0x00
	ldsh r3, [r0, r1]
	movs r2, #0x2C
	ldsh r1, [r7, r2]
	adds r2, r0, #0x0
	cmp r3, r1
	bge _0802FA44
	adds r0, r4, #0x3
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r7, #0x2C]
	movs r4, #0x2C
	ldsh r1, [r7, r4]
	cmp r0, r1
	ble _0802FA5C
	b _0802FA5A
_0802FA44:
	cmp r3, r1
	ble _0802FA5C
	subs r0, r4, #0x3
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r7, #0x2C]
	movs r4, #0x2C
	ldsh r1, [r7, r4]
	cmp r0, r1
	bge _0802FA5C
_0802FA5A:
	strh r3, [r2, #0x00]
_0802FA5C:
	ldr r0, [r5, #0x68]
	cmp r0, #0x01
	bne _0802FA72
	movs r0, #0x00
	ldsh r1, [r2, r0]
	movs r0, #0x8C
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FA86
	movs r0, #0x02
	b _0802FA84
_0802FA72:
	cmp r0, #0x02
	bne _0802FA86
	movs r3, #0x00
	ldsh r1, [r2, r3]
	movs r0, #0x8C
	lsls r0, r0, #0x01
	cmp r1, r0
	ble _0802FA86
	movs r0, #0x01
_0802FA84:
	str r0, [r5, #0x68]
_0802FA86:
	ldr r4, [r5, #0x68]
	cmp r4, #0x01
	beq _0802FAA2
	cmp r4, #0x01
	bcc _0802FA96
	cmp r4, #0x02
	beq _0802FAB8
	b _0802FAC8
_0802FA96:
	movs r1, #0x00
	ldsh r0, [r2, r1]
	lsls r0, r0, #0x08
	movs r2, #0x2E
	ldsh r1, [r7, r2]
	b _0802FAC2
_0802FAA2:
	movs r3, #0x00
	ldsh r0, [r2, r3]
	ldr r2, _0802FAB4 @ =0xFFFFFEE8
	adds r0, r0, r2
	lsls r0, r0, #0x08
	movs r3, #0x2E
	ldsh r1, [r7, r3]
	adds r1, r1, r2
	b _0802FAC2
_0802FAB4: .4byte 0xFFFFFEE8
_0802FAB8:
	movs r1, #0x00
	ldsh r0, [r2, r1]
	lsls r0, r0, #0x08
	movs r1, #0x8C
	lsls r1, r1, #0x01
_0802FAC2:
	bl func_0811D5EC
	str r0, [r5, #0x00]
_0802FAC8:
	mov r2, r8
	cmp r2, #0x00
	beq _0802FB62
	adds r1, r5, #0x0
	adds r1, #0x5D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0802FAE2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0x92
	bl func_0811FE70
_0802FAE2:
	ldr r0, [r5, #0x68]
	cmp r0, #0x00
	bne _0802FB52
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x06
	bhi _0802FB52
	lsls r0, r0, #0x02
	ldr r1, _0802FB00 @ =0x0802FB04
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_0802FB00: .4byte 0x0802FB04
	.byte 0x20, 0xFB, 0x02, 0x08, 0x20, 0xFB, 0x02, 0x08, 0x2A, 0xFB, 0x02, 0x08, 0x34, 0xFB, 0x02, 0x08
	.byte 0x3E, 0xFB, 0x02, 0x08, 0x48, 0xFB, 0x02, 0x08, 0x52, 0xFB, 0x02, 0x08, 0x2C, 0x1C, 0x2C, 0x34
	.byte 0x20, 0x1C, 0x02, 0x21, 0x17, 0xE0, 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C, 0x04, 0x21, 0x12, 0xE0
	.byte 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C, 0x06, 0x21, 0x0D, 0xE0, 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C
	.byte 0x08, 0x21, 0x08, 0xE0, 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C, 0x0A, 0x21, 0x03, 0xE0
_0802FB52:
	adds r4, r5, #0x0
	adds r4, #0x2C
	adds r0, r4, #0x0
	movs r1, #0x0C
	movs r2, #0x01
	bl func_08005A00
	b _0802FC00
_0802FB62:
	cmp r4, #0x00
	bne _0802FBDE
	adds r0, r5, #0x0
	adds r0, #0x64
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r0, #0x06
	bhi _0802FBCE
	lsls r0, r0, #0x02
	ldr r1, _0802FB7C @ =0x0802FB80
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_0802FB7C: .4byte 0x0802FB80
	.byte 0x9C, 0xFB, 0x02, 0x08, 0x9C, 0xFB, 0x02, 0x08, 0xA6, 0xFB, 0x02, 0x08, 0xB0, 0xFB, 0x02, 0x08
	.byte 0xBA, 0xFB, 0x02, 0x08, 0xC4, 0xFB, 0x02, 0x08, 0xCE, 0xFB, 0x02, 0x08, 0x2C, 0x1C, 0x2C, 0x34
	.byte 0x20, 0x1C, 0x01, 0x21, 0x17, 0xE0, 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C, 0x03, 0x21, 0x12, 0xE0
	.byte 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C, 0x05, 0x21, 0x0D, 0xE0, 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C
	.byte 0x07, 0x21, 0x08, 0xE0, 0x2C, 0x1C, 0x2C, 0x34, 0x20, 0x1C, 0x09, 0x21, 0x03, 0xE0
_0802FBCE:
	adds r4, r5, #0x0
	adds r4, #0x2C
	adds r0, r4, #0x0
	movs r1, #0x0B
	movs r2, #0x01
	bl func_08005A00
	b _0802FBEC
_0802FBDE:
	adds r4, r5, #0x0
	adds r4, #0x2C
	adds r0, r4, #0x0
	movs r1, #0x0B
	movs r2, #0x01
	bl func_08005A00
_0802FBEC:
	adds r1, r5, #0x0
	adds r1, #0x5D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0802FC00
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x92
	bl func_0811FF3C
_0802FC00:
	adds r0, r6, #0x0
	bl func_08005A64
	str r0, [r5, #0x20]
	adds r0, r4, #0x0
	bl func_08005A64
	str r0, [r5, #0x24]
	ldrh r0, [r7, #0x2C]
	mov r1, r9
	strh r0, [r1, #0x00]
	movs r0, #0x01
_0802FC18:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start task_btl_hpply_2
task_btl_hpply_2: @ 0802FC24
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r2, [r4, #0x20]
	ldr r3, [r4, #0x10]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r6, #0x82
	lsls r6, r6, #0x03
	str r6, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0x04
	movs r1, #0x02
	bl func_080023E0
	ldr r0, [r4, #0x68]
	cmp r0, #0x01
	beq _0802FC6A
	cmp r0, #0x01
	bcc _0802FC58
	cmp r0, #0x02
	beq _0802FCA0
	b _0802FCCE
_0802FC58:
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x14]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x04
	str r0, [sp, #0x00C]
	b _0802FC92
_0802FC6A:
	ldr r2, _0802FC9C @ =0x08B23F08
	ldr r3, [r4, #0x14]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x04
	str r0, [sp, #0x00C]
	movs r1, #0x02
	bl func_080023E0
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x18]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x03
	str r0, [sp, #0x00C]
	movs r0, #0x04
_0802FC92:
	movs r1, #0x02
	bl func_080023E0
	b _0802FCCE
	.byte 0x00, 0x00
_0802FC9C: .4byte 0x08B23F08
_0802FCA0:
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x14]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x04
	str r0, [sp, #0x00C]
	movs r1, #0x02
	bl func_080023E0
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x18]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r6, [sp, #0x008]
	movs r0, #0x05
	str r0, [sp, #0x00C]
	movs r0, #0x04
	movs r1, #0x02
	bl func_080023E0
_0802FCCE:
	ldr r0, [r4, #0x68]
	cmp r0, #0x01
	beq _0802FD26
	cmp r0, #0x01
	bcc _0802FCDE
	cmp r0, #0x02
	bne _0802FD26
	b _0802FD90
_0802FCDE:
	adds r0, r4, #0x0
	adds r0, #0x64
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x06
	bhi _0802FD90
	lsls r0, r0, #0x02
	ldr r1, _0802FCF4 @ =0x0802FCF8
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_0802FCF4: .4byte 0x0802FCF8
	.byte 0x68, 0xFD, 0x02, 0x08, 0x68, 0xFD, 0x02, 0x08, 0x14, 0xFD, 0x02, 0x08, 0x1A, 0xFD, 0x02, 0x08
	.byte 0x20, 0xFD, 0x02, 0x08, 0x86, 0xFD, 0x02, 0x08, 0x90, 0xFD, 0x02, 0x08, 0x20, 0x68, 0x6D, 0x21
	.byte 0x37, 0xE0, 0x20, 0x68, 0x92, 0x21, 0x34, 0xE0, 0x20, 0x68, 0xB6, 0x21, 0x31, 0xE0
_0802FD26:
	adds r0, r4, #0x0
	adds r0, #0x64
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x06
	bhi _0802FD90
	lsls r0, r0, #0x02
	ldr r1, _0802FD3C @ =0x0802FD40
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_0802FD3C: .4byte 0x0802FD40
	.byte 0x5C, 0xFD, 0x02, 0x08, 0x68, 0xFD, 0x02, 0x08, 0x74, 0xFD, 0x02, 0x08, 0x7A, 0xFD, 0x02, 0x08
	.byte 0x80, 0xFD, 0x02, 0x08, 0x86, 0xFD, 0x02, 0x08, 0x90, 0xFD, 0x02, 0x08, 0x21, 0x68, 0xC8, 0x00
	.byte 0x40, 0x18, 0x80, 0x00, 0x01, 0x12, 0x14, 0xE0, 0x21, 0x68, 0xC8, 0x00, 0x40, 0x18, 0xC0, 0x00
	.byte 0x01, 0x12, 0x0E, 0xE0, 0x20, 0x68, 0x6D, 0x21, 0x07, 0xE0, 0x20, 0x68, 0x92, 0x21, 0x04, 0xE0
	.byte 0x20, 0x68, 0xB6, 0x21, 0x01, 0xE0, 0x20, 0x68, 0xDB, 0x21, 0x48, 0x43, 0x01, 0x12, 0x00, 0xE0
_0802FD90:
	ldr r1, [r4, #0x00]
	lsls r1, r1, #0x01
	adds r0, r4, #0x0
	adds r0, #0x62
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	ble _0802FE04
	cmp r1, #0x09
	bgt _0802FDA6
	movs r1, #0x0A
_0802FDA6:
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r1, r2
	ble _0802FDB4
	movs r0, #0x00
	movs r3, #0x01
	b _0802FDB8
_0802FDB4:
	movs r0, #0x00
	movs r3, #0x00
_0802FDB8:
	bl func_08002CB4
	adds r1, r0, #0x0
	ldr r0, [r4, #0x68]
	cmp r0, #0x01
	bne _0802FDE8
	ldr r2, _0802FDE4 @ =0x08B23EFE
	ldr r3, [r4, #0x1C]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x02
	str r0, [sp, #0x00C]
	movs r0, #0x1F
	movs r1, #0x09
	bl func_080023E0
	b _0802FE04
	.byte 0x00, 0x00
_0802FDE4: .4byte 0x08B23EFE
_0802FDE8:
	ldr r2, _0802FE0C @ =0x08B23CB0
	ldr r3, [r4, #0x1C]
	ldr r0, [r4, #0x08]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x02
	str r0, [sp, #0x00C]
	movs r0, #0x1F
	movs r1, #0x06
	bl func_080023E0
_0802FE04:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0802FE0C: .4byte 0x08B23CB0
	thumb_func_start task_btl_hpply_3
task_btl_hpply_3: @ 0802FE10
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x92
	bl func_0811FF3C
	ldr r0, [r4, #0x10]
	bl func_080028C0
	ldr r0, [r4, #0x14]
	bl func_080028C0
	ldr r0, [r4, #0x18]
	bl func_080028C0
	ldr r0, [r4, #0x1C]
	bl func_080028C0
	ldr r0, [r4, #0x08]
	bl func_08002C10
	ldr r0, [r4, #0x0C]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start task_btl_hpenm_0
task_btl_hpenm_0: @ 0802FE44
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r0, #0xA0
	lsls r0, r0, #0x01
	ldr r5, _0802FE8C @ =0x08B24DAA
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r4, #0x00]
	movs r0, #0x80
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r4, #0x04]
	movs r0, #0x20
	adds r1, r5, #0x0
	bl func_080028F8
	str r0, [r4, #0x0C]
	ldr r0, _0802FE90 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	movs r1, #0x00
	strb r1, [r4, #0x14]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r4, #0x10]
	str r1, [r4, #0x18]
	strh r1, [r4, #0x1C]
	str r1, [r4, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0802FE8C: .4byte 0x08B24DAA
_0802FE90: .4byte 0x08F69BA4
	thumb_func_start task_btl_hpenm_1
task_btl_hpenm_1: @ 0802FE94
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _0802FEAC @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA0
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	bne _0802FEB0
	movs r0, #0x00
	b _08030032
	.byte 0x00, 0x00
_0802FEAC: .4byte 0x02039B84
_0802FEB0:
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0802FED4
	ldr r0, _0802FED0 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x7C]
	movs r0, #0x01
	strb r0, [r4, #0x14]
	b _0802FEEC
	.byte 0x00, 0x00
_0802FED0: .4byte 0x02039B9C
_0802FED4:
	ldr r1, [r3, #0x78]
	cmp r1, #0x00
	bne _0802FEE6
	ldrb r0, [r4, #0x14]
	cmp r0, #0x00
	bne _0802FEE2
	b _08030030
_0802FEE2:
	strb r1, [r4, #0x14]
	b _08030030
_0802FEE6:
	movs r0, #0x01
	strb r0, [r4, #0x14]
	ldr r3, [r3, #0x78]
_0802FEEC:
	adds r0, r3, #0x0
	adds r0, #0xD8
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0802FEF8
	adds r3, r0, #0x0
_0802FEF8:
	ldr r0, [r4, #0x18]
	cmp r0, r3
	beq _0802FF64
	str r3, [r4, #0x18]
	ldrh r0, [r3, #0x2C]
	strh r0, [r4, #0x1E]
	movs r0, #0x2E
	ldsh r1, [r3, r0]
	cmp r1, #0x50
	bgt _0802FF12
	movs r0, #0x00
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF12:
	cmp r1, #0xA0
	bgt _0802FF1C
	movs r0, #0x01
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF1C:
	cmp r1, #0xF0
	bgt _0802FF26
	movs r0, #0x02
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF26:
	movs r0, #0xA0
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FF34
	movs r0, #0x03
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF34:
	movs r0, #0xC8
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FF42
	movs r0, #0x04
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF42:
	movs r0, #0xF0
	lsls r0, r0, #0x01
	cmp r1, r0
	bgt _0802FF50
	movs r0, #0x05
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF50:
	movs r0, #0x8C
	lsls r0, r0, #0x02
	cmp r1, r0
	bgt _0802FF5E
	movs r0, #0x06
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF5E:
	movs r0, #0x07
	strh r0, [r4, #0x1C]
	b _0802FF9E
_0802FF64:
	ldrh r0, [r4, #0x1E]
	movs r1, #0x1E
	ldsh r2, [r4, r1]
	movs r5, #0x2C
	ldsh r1, [r3, r5]
	cmp r2, r1
	bge _0802FF86
	adds r0, #0x05
	strh r0, [r4, #0x1E]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r3, #0x2C]
	movs r5, #0x2C
	ldsh r1, [r3, r5]
	cmp r0, r1
	ble _0802FF9E
	b _0802FF9C
_0802FF86:
	cmp r2, r1
	ble _0802FF9E
	subs r0, #0x05
	strh r0, [r4, #0x1E]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r3, #0x2C]
	movs r5, #0x2C
	ldsh r1, [r3, r5]
	cmp r0, r1
	bge _0802FF9E
_0802FF9C:
	strh r2, [r4, #0x1E]
_0802FF9E:
	movs r0, #0x1E
	ldsh r1, [r4, r0]
	movs r0, #0x8C
	lsls r0, r0, #0x02
	cmp r1, r0
	bgt _0802FFAE
	movs r0, #0x00
	b _0802FFC8
_0802FFAE:
	movs r0, #0x8C
	lsls r0, r0, #0x03
	cmp r1, r0
	bgt _0802FFBA
	movs r0, #0x01
	b _0802FFC8
_0802FFBA:
	movs r0, #0xD2
	lsls r0, r0, #0x03
	cmp r1, r0
	bgt _0802FFC6
	movs r0, #0x02
	b _0802FFC8
_0802FFC6:
	movs r0, #0x03
_0802FFC8:
	str r0, [r4, #0x20]
	ldr r0, [r4, #0x20]
	cmp r0, #0x01
	beq _0802FFFC
	cmp r0, #0x01
	bcc _0803000C
	cmp r0, #0x02
	beq _0802FFEC
	cmp r0, #0x03
	bne _08030030
	movs r1, #0x1E
	ldsh r0, [r4, r1]
	ldr r2, _0802FFE8 @ =0xFFFFF970
	adds r0, r0, r2
	b _08030024
	.byte 0x00, 0x00
_0802FFE8: .4byte 0xFFFFF970
_0802FFEC:
	movs r5, #0x1E
	ldsh r0, [r4, r5]
	ldr r1, _0802FFF8 @ =0xFFFFFBA0
	adds r0, r0, r1
	b _08030024
	.byte 0x00, 0x00
_0802FFF8: .4byte 0xFFFFFBA0
_0802FFFC:
	movs r2, #0x1E
	ldsh r0, [r4, r2]
	ldr r5, _08030008 @ =0xFFFFFDD0
	adds r0, r0, r5
	b _08030024
	.byte 0x00, 0x00
_08030008: .4byte 0xFFFFFDD0
_0803000C:
	movs r1, #0x1C
	ldsh r0, [r4, r1]
	cmp r0, #0x06
	bgt _08030020
	movs r2, #0x1E
	ldsh r0, [r4, r2]
	lsls r0, r0, #0x08
	movs r5, #0x2E
	ldsh r1, [r3, r5]
	b _0803002A
_08030020:
	movs r1, #0x1E
	ldsh r0, [r4, r1]
_08030024:
	lsls r0, r0, #0x08
	movs r1, #0x8C
	lsls r1, r1, #0x02
_0803002A:
	bl func_0811D5EC
	str r0, [r4, #0x10]
_08030030:
	movs r0, #0x01
_08030032:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start task_btl_hpenm_2
task_btl_hpenm_2: @ 08030038
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldrb r0, [r6, #0x14]
	cmp r0, #0x00
	bne _08030046
	b _080301CA
_08030046:
	ldr r0, [r6, #0x20]
	cmp r0, #0x01
	beq _08030078
	cmp r0, #0x01
	bcc _08030088
	cmp r0, #0x02
	beq _08030068
	cmp r0, #0x03
	bne _08030088
	ldr r2, _08030060 @ =0x08B24D58
	ldr r7, _08030064 @ =0x08B24D22
	b _080300E8
	.byte 0x00, 0x00
_08030060: .4byte 0x08B24D58
_08030064: .4byte 0x08B24D22
_08030068:
	ldr r2, _08030070 @ =0x08B24D42
	ldr r7, _08030074 @ =0x08B24D18
	b _080300E8
	.byte 0x00, 0x00
_08030070: .4byte 0x08B24D42
_08030074: .4byte 0x08B24D18
_08030078:
	ldr r2, _08030080 @ =0x08B24D2C
	ldr r7, _08030084 @ =0x08B24D0E
	b _080300E8
	.byte 0x00, 0x00
_08030080: .4byte 0x08B24D2C
_08030084: .4byte 0x08B24D0E
_08030088:
	movs r1, #0x1C
	ldsh r0, [r6, r1]
	cmp r0, #0x06
	bhi _080300E4
	lsls r0, r0, #0x02
	ldr r1, _0803009C @ =0x080300A0
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_0803009C: .4byte 0x080300A0
	.byte 0xBC, 0x00, 0x03, 0x08, 0xBC, 0x00, 0x03, 0x08, 0xC4, 0x00, 0x03, 0x08, 0xCC, 0x00, 0x03, 0x08
	.byte 0xD4, 0x00, 0x03, 0x08, 0xDC, 0x00, 0x03, 0x08, 0xE4, 0x00, 0x03, 0x08, 0x00, 0x4A, 0x12, 0xE0
	.byte 0xA2, 0x4C, 0xB2, 0x08, 0x00, 0x4A, 0x0E, 0xE0, 0xB2, 0x4C, 0xB2, 0x08, 0x00, 0x4A, 0x0A, 0xE0
	.byte 0xC2, 0x4C, 0xB2, 0x08, 0x00, 0x4A, 0x06, 0xE0, 0xD2, 0x4C, 0xB2, 0x08, 0x00, 0x4A, 0x02, 0xE0
	.byte 0xE2, 0x4C, 0xB2, 0x08
_080300E4:
	ldr r2, _08030130 @ =0x08B24CF8
	ldr r7, _08030134 @ =0x08B24C98
_080300E8:
	ldr r3, [r6, #0x00]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0x82
	lsls r4, r4, #0x03
	str r4, [sp, #0x008]
	movs r0, #0x03
	str r0, [sp, #0x00C]
	movs r0, #0xEC
	movs r1, #0x02
	bl func_080023E0
	ldr r2, _08030138 @ =0x08B24D6E
	ldr r3, [r6, #0x0C]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xEC
	movs r1, #0x02
	bl func_080023E0
	movs r2, #0x1C
	ldsh r0, [r6, r2]
	cmp r0, #0x06
	bhi _08030184
	lsls r0, r0, #0x02
	ldr r1, _0803013C @ =0x08030140
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_08030130: .4byte 0x08B24CF8
_08030134: .4byte 0x08B24C98
_08030138: .4byte 0x08B24D6E
_0803013C: .4byte 0x08030140
	.byte 0x5C, 0x01, 0x03, 0x08, 0x5C, 0x01, 0x03, 0x08, 0x68, 0x01, 0x03, 0x08, 0x6E, 0x01, 0x03, 0x08
	.byte 0x74, 0x01, 0x03, 0x08, 0x7A, 0x01, 0x03, 0x08, 0x84, 0x01, 0x03, 0x08, 0x31, 0x69, 0xC8, 0x00
	.byte 0x40, 0x18, 0xC0, 0x00, 0x01, 0x12, 0x0E, 0xE0, 0x30, 0x69, 0x6D, 0x21, 0x07, 0xE0, 0x30, 0x69
	.byte 0x92, 0x21, 0x04, 0xE0, 0x30, 0x69, 0xB6, 0x21, 0x01, 0xE0, 0x30, 0x69, 0xDB, 0x21, 0x48, 0x43
	.byte 0x01, 0x12, 0x00, 0xE0
_08030184:
	ldr r1, [r6, #0x10]
	lsls r1, r1, #0x01
	movs r2, #0x1E
	ldsh r0, [r6, r2]
	cmp r0, #0x00
	ble _080301CA
	cmp r1, #0x09
	bgt _08030196
	movs r1, #0x0A
_08030196:
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r1, r2
	ble _080301A4
	movs r0, #0x00
	movs r3, #0x01
	b _080301A8
_080301A4:
	movs r0, #0x00
	movs r3, #0x00
_080301A8:
	bl func_08002CB4
	adds r1, r0, #0x0
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x82
	lsls r0, r0, #0x03
	str r0, [sp, #0x008]
	movs r0, #0x02
	str r0, [sp, #0x00C]
	movs r0, #0xD9
	movs r1, #0x06
	adds r2, r7, #0x0
	bl func_080023E0
_080301CA:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_btl_hpenm_3
task_btl_hpenm_3: @ 080301D4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x0C]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x08]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_btl_pause_0
task_btl_pause_0: @ 080301F8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _0803023C @ =0x08B1E7F4
	movs r1, #0xC0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _08030240 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r1, _08030244 @ =0x09EE115C
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x08]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x0C]
	movs r0, #0x00
	strb r0, [r4, #0x10]
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	ldr r0, _08030248 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0803024C @ =0x04000000
	ldr r3, _08030250 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	pop {r4}
	pop {r0}
	bx r0
_0803023C: .4byte 0x08B1E7F4
_08030240: .4byte 0x08F69BA4
_08030244: .4byte 0x09EE115C
_08030248: .4byte 0x02039B84
_0803024C: .4byte 0x04000000
_08030250: .4byte 0x00000000
	thumb_func_start task_btl_pause_1
task_btl_pause_1: @ 08030254
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	bl func_08001390
	movs r1, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _0803028A
	ldr r0, _080303A8 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0803028A
	movs r2, #0x00
	adds r1, r3, #0x0
	adds r1, #0x70
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08030288
	movs r2, #0x01
_08030288:
	strb r2, [r1, #0x00]
_0803028A:
	ldr r0, _080303A8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r6, [r0, #0x00]
	cmp r6, #0x00
	bne _08030298
	b _08030438
_08030298:
	ldrb r0, [r5, #0x10]
	cmp r0, #0x00
	beq _080302A0
	b _0803040C
_080302A0:
	movs r0, #0x01
	bl func_080063C4
	movs r0, #0x01
	strb r0, [r5, #0x10]
	ldr r0, _080303AC @ =0xFFFFC000
	str r0, [r5, #0x14]
	movs r1, #0xA0
	lsls r1, r1, #0x07
	str r1, [r5, #0x18]
	movs r0, #0x98
	lsls r0, r0, #0x09
	str r0, [r5, #0x1C]
	str r1, [r5, #0x20]
	movs r0, #0x0E
	strh r0, [r5, #0x24]
	ldr r0, _080303B0 @ =0x0203DB10
	movs r1, #0xFF
	movs r2, #0x80
	bl func_08120EF8
	ldr r0, _080303B4 @ =0x0203DC90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303B8 @ =0x0203DCD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303BC @ =0x0203DEE0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303C0 @ =0x0203DE50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303C4 @ =0x0203DA10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303C8 @ =0x0203DAD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303CC @ =0x0203DC50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303D0 @ =0x0203DEA0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303D4 @ =0x0203DA90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303D8 @ =0x0203DD10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303DC @ =0x0203DF20
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303E0 @ =0x0203DDD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303E4 @ =0x0203DA50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303E8 @ =0x0203DE10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303EC @ =0x0203DC10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303F0 @ =0x0203D990
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303F4 @ =0x0203DB50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303F8 @ =0x0203DBD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303FC @ =0x0203DD90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _08030400 @ =0x0203D9D0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _08030404 @ =0x0203DB90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _08030408 @ =0x0203DD50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	b _08030530
_080303A8: .4byte 0x02039B84
_080303AC: .4byte 0xFFFFC000
_080303B0: .4byte 0x0203DB10
_080303B4: .4byte 0x0203DC90
_080303B8: .4byte 0x0203DCD0
_080303BC: .4byte 0x0203DEE0
_080303C0: .4byte 0x0203DE50
_080303C4: .4byte 0x0203DA10
_080303C8: .4byte 0x0203DAD0
_080303CC: .4byte 0x0203DC50
_080303D0: .4byte 0x0203DEA0
_080303D4: .4byte 0x0203DA90
_080303D8: .4byte 0x0203DD10
_080303DC: .4byte 0x0203DF20
_080303E0: .4byte 0x0203DDD0
_080303E4: .4byte 0x0203DA50
_080303E8: .4byte 0x0203DE10
_080303EC: .4byte 0x0203DC10
_080303F0: .4byte 0x0203D990
_080303F4: .4byte 0x0203DB50
_080303F8: .4byte 0x0203DBD0
_080303FC: .4byte 0x0203DD90
_08030400: .4byte 0x0203D9D0
_08030404: .4byte 0x0203DB90
_08030408: .4byte 0x0203DD50
_0803040C:
	adds r0, r5, #0x0
	adds r0, #0x14
	movs r4, #0xF0
	lsls r4, r4, #0x07
	ldrh r2, [r5, #0x24]
	adds r1, r4, #0x0
	bl func_080058FC
	adds r0, r5, #0x0
	adds r0, #0x1C
	ldrh r2, [r5, #0x24]
	adds r1, r4, #0x0
	bl func_080058FC
	ldrh r1, [r5, #0x24]
	movs r2, #0x24
	ldsh r0, [r5, r2]
	cmp r0, #0x01
	ble _08030530
	subs r0, r1, #0x1
	strh r0, [r5, #0x24]
	b _08030530
_08030438:
	ldrb r0, [r5, #0x10]
	cmp r0, #0x00
	beq _08030530
	ldr r0, _08030538 @ =0x0203DB10
	movs r4, #0x80
	lsls r4, r4, #0x01
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803053C @ =0x0203DC90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030540 @ =0x0203DCD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030544 @ =0x0203DEE0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030548 @ =0x0203DE50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803054C @ =0x0203DA10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030550 @ =0x0203DAD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030554 @ =0x0203DC50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030558 @ =0x0203DEA0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803055C @ =0x0203DA90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030560 @ =0x0203DD10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030564 @ =0x0203DF20
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030568 @ =0x0203DDD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803056C @ =0x0203DA50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030570 @ =0x0203DE10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030574 @ =0x0203DC10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030578 @ =0x0203D990
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803057C @ =0x0203DB50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030580 @ =0x0203DBD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030584 @ =0x0203DD90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030588 @ =0x0203D9D0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803058C @ =0x0203DB90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030590 @ =0x0203DD50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	strb r6, [r5, #0x10]
	movs r0, #0x00
	bl func_080063C4
_08030530:
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_08030538: .4byte 0x0203DB10
_0803053C: .4byte 0x0203DC90
_08030540: .4byte 0x0203DCD0
_08030544: .4byte 0x0203DEE0
_08030548: .4byte 0x0203DE50
_0803054C: .4byte 0x0203DA10
_08030550: .4byte 0x0203DAD0
_08030554: .4byte 0x0203DC50
_08030558: .4byte 0x0203DEA0
_0803055C: .4byte 0x0203DA90
_08030560: .4byte 0x0203DD10
_08030564: .4byte 0x0203DF20
_08030568: .4byte 0x0203DDD0
_0803056C: .4byte 0x0203DA50
_08030570: .4byte 0x0203DE10
_08030574: .4byte 0x0203DC10
_08030578: .4byte 0x0203D990
_0803057C: .4byte 0x0203DB50
_08030580: .4byte 0x0203DBD0
_08030584: .4byte 0x0203DD90
_08030588: .4byte 0x0203D9D0
_0803058C: .4byte 0x0203DB90
_08030590: .4byte 0x0203DD50
	thumb_func_start task_btl_pause_2
task_btl_pause_2: @ 08030594
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldrb r0, [r6, #0x10]
	cmp r0, #0x00
	beq _080305DE
	ldr r0, [r6, #0x14]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x18]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
	ldr r0, [r6, #0x1C]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r6, #0x20]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
_080305DE:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_btl_pause_3
task_btl_pause_3: @ 080305E8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	bl func_080063C4
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start task_btl_pop_0
task_btl_pop_0: @ 08030604
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	movs r1, #0x12
	ldsh r0, [r6, r1]
	cmp r0, #0x0A
	bls _08030614
	b _08030858
_08030614:
	lsls r0, r0, #0x02
	ldr r1, _08030620 @ =0x08030624
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_08030620: .4byte 0x08030624
	.byte 0x50, 0x06, 0x03, 0x08, 0x84, 0x06, 0x03, 0x08, 0xB8, 0x06, 0x03, 0x08, 0xEC, 0x06, 0x03, 0x08
	.byte 0x58, 0x08, 0x03, 0x08, 0x20, 0x07, 0x03, 0x08, 0x54, 0x07, 0x03, 0x08, 0x88, 0x07, 0x03, 0x08
	.byte 0xBC, 0x07, 0x03, 0x08, 0xF0, 0x07, 0x03, 0x08, 0x24, 0x08, 0x03, 0x08, 0x09, 0x48, 0x80, 0x21
	.byte 0x49, 0x00, 0xD2, 0xF7, 0x25, 0xF8, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A
	.byte 0x20, 0x1C, 0xD5, 0xF7, 0x7F, 0xF9, 0x20, 0x1C, 0x00, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0x98, 0xF9
	.byte 0x02, 0xE1, 0x00, 0x00, 0x20, 0xF0, 0xB1, 0x08, 0xD0, 0x11, 0xEE, 0x09, 0xCC, 0x11, 0xEE, 0x09
	.byte 0x09, 0x48, 0xC0, 0x21, 0x49, 0x00, 0xD2, 0xF7, 0x0B, 0xF8, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34
	.byte 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7, 0x65, 0xF9, 0x20, 0x1C, 0x00, 0x21, 0x01, 0x22
	.byte 0xD5, 0xF7, 0x7E, 0xF9, 0xE8, 0xE0, 0x00, 0x00, 0x76, 0xED, 0xB1, 0x08, 0xC0, 0x11, 0xEE, 0x09
	.byte 0xBC, 0x11, 0xEE, 0x09, 0x09, 0x48, 0x80, 0x21, 0x49, 0x00, 0xD1, 0xF7, 0xF1, 0xFF, 0x28, 0x60
	.byte 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7, 0x4B, 0xF9, 0x20, 0x1C
	.byte 0x00, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0x64, 0xF9, 0xCE, 0xE0, 0x00, 0x00, 0x0C, 0xEF, 0xB1, 0x08
	.byte 0xC8, 0x11, 0xEE, 0x09, 0xC4, 0x11, 0xEE, 0x09, 0x09, 0x48, 0xC0, 0x21, 0x49, 0x00, 0xD1, 0xF7
	.byte 0xD7, 0xFF, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7
	.byte 0x31, 0xF9, 0x20, 0x1C, 0x00, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0x4A, 0xF9, 0xB4, 0xE0, 0x00, 0x00
	.byte 0x3A, 0xF1, 0xB1, 0x08, 0xD8, 0x11, 0xEE, 0x09, 0xD4, 0x11, 0xEE, 0x09, 0x09, 0x48, 0xA0, 0x21
	.byte 0xC9, 0x00, 0xD1, 0xF7, 0xBD, 0xFF, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A
	.byte 0x20, 0x1C, 0xD5, 0xF7, 0x17, 0xF9, 0x20, 0x1C, 0x00, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0x30, 0xF9
	.byte 0x9A, 0xE0, 0x00, 0x00, 0xAC, 0xF7, 0xB1, 0x08, 0x04, 0x12, 0xEE, 0x09, 0xF4, 0x11, 0xEE, 0x09
	.byte 0x09, 0x48, 0xA0, 0x21, 0xC9, 0x00, 0xD1, 0xF7, 0xA3, 0xFF, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34
	.byte 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7, 0xFD, 0xF8, 0x20, 0x1C, 0x02, 0x21, 0x01, 0x22
	.byte 0xD5, 0xF7, 0x16, 0xF9, 0x80, 0xE0, 0x00, 0x00, 0xAC, 0xF7, 0xB1, 0x08, 0x04, 0x12, 0xEE, 0x09
	.byte 0xF4, 0x11, 0xEE, 0x09, 0x09, 0x48, 0xA0, 0x21, 0xC9, 0x00, 0xD1, 0xF7, 0x89, 0xFF, 0x28, 0x60
	.byte 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7, 0xE3, 0xF8, 0x20, 0x1C
	.byte 0x01, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0xFC, 0xF8, 0x66, 0xE0, 0x00, 0x00, 0xAC, 0xF7, 0xB1, 0x08
	.byte 0x04, 0x12, 0xEE, 0x09, 0xF4, 0x11, 0xEE, 0x09, 0x09, 0x48, 0xA0, 0x21, 0xC9, 0x00, 0xD1, 0xF7
	.byte 0x6F, 0xFF, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7
	.byte 0xC9, 0xF8, 0x20, 0x1C, 0x03, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0xE2, 0xF8, 0x4C, 0xE0, 0x00, 0x00
	.byte 0xAC, 0xF7, 0xB1, 0x08, 0x04, 0x12, 0xEE, 0x09, 0xF4, 0x11, 0xEE, 0x09, 0x09, 0x48, 0xC0, 0x21
	.byte 0x49, 0x00, 0xD1, 0xF7, 0x55, 0xFF, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34, 0x06, 0x49, 0x07, 0x4A
	.byte 0x20, 0x1C, 0xD5, 0xF7, 0xAF, 0xF8, 0x20, 0x1C, 0x00, 0x21, 0x01, 0x22, 0xD5, 0xF7, 0xC8, 0xF8
	.byte 0x32, 0xE0, 0x00, 0x00, 0x72, 0xF4, 0xB1, 0x08, 0xE8, 0x11, 0xEE, 0x09, 0xE4, 0x11, 0xEE, 0x09
	.byte 0x09, 0x48, 0xA0, 0x21, 0x49, 0x00, 0xD1, 0xF7, 0x3B, 0xFF, 0x28, 0x60, 0x2C, 0x1C, 0x0C, 0x34
	.byte 0x06, 0x49, 0x07, 0x4A, 0x20, 0x1C, 0xD5, 0xF7, 0x95, 0xF8, 0x20, 0x1C, 0x00, 0x21, 0x01, 0x22
	.byte 0xD5, 0xF7, 0xAE, 0xF8, 0x18, 0xE0, 0x00, 0x00, 0x0E, 0xF6, 0xB1, 0x08, 0xF0, 0x11, 0xEE, 0x09
	.byte 0xEC, 0x11, 0xEE, 0x09
_08030858:
	ldr r0, _080308A4 @ =0x08B1F2D6
	movs r1, #0xC0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x0C
	ldr r1, _080308A8 @ =0x09EE11E0
	ldr r2, _080308AC @ =0x09EE11DC
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r5, #0x08]
	ldr r0, _080308B0 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x28]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x2C]
	movs r0, #0x00
	strh r0, [r5, #0x30]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080308A4: .4byte 0x08B1F2D6
_080308A8: .4byte 0x09EE11E0
_080308AC: .4byte 0x09EE11DC
_080308B0: .4byte 0x08F69BA4
	thumb_func_start task_btl_pop_1
task_btl_pop_1: @ 080308B4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x2C]
	subs r0, #0xC0
	str r0, [r4, #0x2C]
	ldrh r1, [r4, #0x30]
	movs r2, #0x30
	ldsh r0, [r4, r2]
	cmp r0, #0x31
	bgt _080308DA
	adds r0, r1, #0x1
	strh r0, [r4, #0x30]
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	movs r0, #0x01
	b _080308DC
_080308DA:
	movs r0, #0x00
_080308DC:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start task_btl_pop_2
task_btl_pop_2: @ 080308E4
	push {r4, r5, lr}
	add sp, #-0x014
	adds r4, r0, #0x0
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	ldr r0, [r4, #0x2C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x10
	str r4, [sp, #0x008]
	movs r4, #0x05
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x014
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start task_btl_pop_3
task_btl_pop_3: @ 08030928
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
	thumb_func_start task_btl_escape_0
task_btl_escape_0: @ 08030940
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0xB4
	lsls r0, r0, #0x07
	str r0, [r4, #0x18]
	ldr r0, _08030984 @ =0x08B1EB1C
	movs r1, #0x90
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _08030988 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r1, _0803098C @ =0x09EE11A4
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x08]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x0C]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x10]
	movs r0, #0x00
	str r0, [r4, #0x14]
	str r0, [r4, #0x1C]
	adds r1, r4, #0x0
	adds r1, #0x22
	strb r0, [r1, #0x00]
	strh r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08030984: .4byte 0x08B1EB1C
_08030988: .4byte 0x08F69BA4
_0803098C: .4byte 0x09EE11A4
	thumb_func_start task_btl_escape_1
task_btl_escape_1: @ 08030990
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldr r0, _080309D8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	mov r8, r0
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x11
	movs r0, #0x00
	adds r1, r4, #0x0
	ands r1, r2
	adds r7, r1, #0x0
	orrs r7, r0
	cmp r7, #0x00
	bne _08030A56
	movs r0, #0x08
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _080309DC
	adds r1, r5, #0x0
	adds r1, #0x22
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08030A54
	str r7, [r5, #0x1C]
	strb r7, [r1, #0x00]
	strh r7, [r5, #0x20]
	b _08030A54
_080309D8: .4byte 0x02039B84
_080309DC:
	ldrh r1, [r5, #0x20]
	movs r2, #0x20
	ldsh r0, [r5, r2]
	cmp r0, #0x0F
	bgt _080309F4
	adds r0, r1, #0x1
	movs r1, #0x00
	strh r0, [r5, #0x20]
	adds r0, r5, #0x0
	adds r0, #0x22
	strb r1, [r0, #0x00]
	b _08030A54
_080309F4:
	movs r0, #0x22
	adds r0, r0, r5
	mov r9, r0
	movs r0, #0x01
	mov r1, r9
	strb r0, [r1, #0x00]
	ldr r6, [r5, #0x1C]
	lsls r0, r6, #0x08
	ldr r4, [r5, #0x18]
	adds r1, r4, #0x0
	bl func_0811D5EC
	str r0, [r5, #0x14]
	cmp r6, r4
	blt _08030A4C
	ldr r2, _08030A40 @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r2, #0x08]
	mov r0, r8
	ldr r2, [r0, #0x68]
	ldr r3, [r0, #0x6C]
	movs r0, #0x10
	movs r1, #0x00
	orrs r2, r0
	ldr r4, _08030A44 @ =0x00000000
	ldr r5, _08030A48 @ =0x00000002
	adds r0, r2, #0x0
	adds r1, r3, #0x0
	orrs r1, r5
	mov r2, r8
	str r0, [r2, #0x68]
	str r1, [r2, #0x6C]
	mov r0, r9
	strb r7, [r0, #0x00]
	b _08030A54
	.byte 0x00, 0x00
_08030A40: .4byte 0x02039BB0
_08030A44: .4byte 0x00000000
_08030A48: .4byte 0x00000002
_08030A4C:
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r6, r1
	str r0, [r5, #0x1C]
_08030A54:
	movs r0, #0x01
_08030A56:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start task_btl_escape_2
task_btl_escape_2: @ 08030A64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r0, #0x22
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08030B5E
	ldr r0, _08030AD0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r4, [r0, #0x7C]
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	mov r8, r3
	ands r0, r2
	movs r1, #0x00
	adds r7, r1, #0x0
	orrs r7, r0
	cmp r7, #0x00
	beq _08030ADC
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x04]
	ldr r0, _08030AD4 @ =0xFFFFFD00
	adds r2, r2, r0
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	ldr r1, _08030AD8 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x02
	str r4, [sp, #0x00C]
	bl func_080023E0
	b _08030B16
_08030AD0: .4byte 0x02039B84
_08030AD4: .4byte 0xFFFFFD00
_08030AD8: .4byte 0xFFFFD800
_08030ADC:
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x04]
	ldr r0, _08030B2C @ =0xFFFFF400
	adds r2, r2, r0
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	ldr r1, _08030B30 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r4, #0x02
	str r4, [sp, #0x00C]
	bl func_080023E0
_08030B16:
	ldr r1, [r6, #0x14]
	cmp r1, #0x00
	ble _08030B5E
	lsls r1, r1, #0x01
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r1, r2
	ble _08030B34
	movs r0, #0x00
	movs r3, #0x01
	b _08030B38
_08030B2C: .4byte 0xFFFFF400
_08030B30: .4byte 0xFFFFD800
_08030B34:
	movs r0, #0x00
	movs r3, #0x00
_08030B38:
	bl func_08002CB4
	adds r7, r0, #0x0
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r2, [r6, #0x10]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	movs r4, #0x01
	str r4, [sp, #0x00C]
	bl func_080023E0
_08030B5E:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_btl_escape_3
task_btl_escape_3: @ 08030B6C
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
	thumb_func_start task_btl_prize_0
task_btl_prize_0: @ 08030B84
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [r6, #0x00]
	str r0, [r4, #0x00]
	ldr r0, [r6, #0x04]
	str r0, [r4, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [r4, #0x08]
	movs r7, #0x00
	str r7, [r4, #0x0C]
	ldr r0, _08030C20 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r5, [r0, #0x00]
	cmp r5, #0x00
	beq _08030BBA
	adds r1, r4, #0x4
	adds r2, r4, #0x0
	adds r2, #0x08
	adds r3, r4, #0x0
	adds r3, #0x0C
	adds r0, r4, #0x0
	bl _0811D5C4
_08030BBA:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08030C24 @ =0x00000381
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xC0
	lsls r2, r2, #0x02
	adds r0, r0, r2
	negs r0, r0
	str r0, [r4, #0x20]
	bl func_080065A4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08030C28 @ =0x08B209E0
	movs r1, #0xD0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x10]
	ldr r0, _08030C2C @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x14]
	strh r7, [r4, #0x28]
	ldr r0, _08030C30 @ =0x08B208E8
	str r0, [r4, #0x1C]
	movs r0, #0x03
	strh r0, [r4, #0x2C]
	movs r1, #0x14
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	beq _08030C0A
	movs r0, #0x0B
	strh r0, [r4, #0x2C]
_08030C0A:
	movs r2, #0x12
	ldsh r0, [r6, r2]
	cmp r0, #0x08
	bls _08030C14
	b _08030D00
_08030C14:
	lsls r0, r0, #0x02
	ldr r1, _08030C34 @ =0x08030C38
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_08030C20: .4byte 0x02039B84
_08030C24: .4byte 0x00000381
_08030C28: .4byte 0x08B209E0
_08030C2C: .4byte 0x08F69BA4
_08030C30: .4byte 0x08B208E8
_08030C34: .4byte 0x08030C38
	.byte 0x5C, 0x0C, 0x03, 0x08, 0x78, 0x0C, 0x03, 0x08, 0x88, 0x0C, 0x03, 0x08, 0xA4, 0x0C, 0x03, 0x08
	.byte 0xB4, 0x0C, 0x03, 0x08, 0xC4, 0x0C, 0x03, 0x08, 0xE0, 0x0C, 0x03, 0x08, 0xF0, 0x0C, 0x03, 0x08
	.byte 0x00, 0x0D, 0x03, 0x08, 0x05, 0x48, 0xA0, 0x61, 0x00, 0x20, 0x60, 0x87, 0xAF, 0x20, 0xC0, 0x00
	.byte 0x20, 0x87, 0x78, 0x38, 0x60, 0x62, 0xC0, 0x23, 0x5B, 0x00, 0x4F, 0xE0, 0xF2, 0x08, 0xB2, 0x08
	.byte 0x02, 0x48, 0xA0, 0x61, 0x00, 0x21, 0x03, 0x20, 0x06, 0xE0, 0x00, 0x00, 0xFC, 0x08, 0xB2, 0x08
	.byte 0x05, 0x48, 0xA0, 0x61, 0x00, 0x21, 0x0A, 0x20, 0x60, 0x87, 0x21, 0x87, 0xC0, 0x20, 0x80, 0x00
	.byte 0x60, 0x62, 0x4C, 0x23, 0x3A, 0xE0, 0x00, 0x00, 0x06, 0x09, 0xB2, 0x08, 0x02, 0x48, 0xA0, 0x61
	.byte 0x00, 0x20, 0x60, 0x87, 0x01, 0x20, 0x0E, 0xE0, 0x10, 0x09, 0xB2, 0x08, 0x02, 0x48, 0xA0, 0x61
	.byte 0x00, 0x20, 0x60, 0x87, 0x0A, 0x20, 0x06, 0xE0, 0x1A, 0x09, 0xB2, 0x08, 0x05, 0x48, 0xA0, 0x61
	.byte 0x00, 0x20, 0x60, 0x87, 0x3C, 0x20, 0x20, 0x87, 0x80, 0x20, 0xC0, 0x00, 0x60, 0x62, 0x80, 0x23
	.byte 0x1C, 0xE0, 0x00, 0x00, 0x24, 0x09, 0xB2, 0x08, 0x02, 0x48, 0xA0, 0x61, 0x00, 0x20, 0x60, 0x87
	.byte 0x05, 0x20, 0x0E, 0xE0, 0x2E, 0x09, 0xB2, 0x08, 0x02, 0x48, 0xA0, 0x61, 0x00, 0x20, 0x60, 0x87
	.byte 0x1E, 0x20, 0x06, 0xE0, 0x38, 0x09, 0xB2, 0x08
_08030D00:
	ldr r0, _08030D78 @ =0x08B20942
	str r0, [r4, #0x18]
	movs r0, #0x00
	strh r0, [r4, #0x3A]
	movs r0, #0xC7
	strh r0, [r4, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [r4, #0x24]
	movs r3, #0xB3
	movs r0, #0x00
	str r0, [r4, #0x30]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r4, #0x34]
	ldr r0, _08030D7C @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _08030D80 @ =0x08121400
	lsls r0, r5, #0x01
	adds r0, r0, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	muls r0, r3
	asrs r2, r0, #0x08
	str r2, [r4, #0x3C]
	adds r0, r5, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r4, #0x40]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _08030D56
	negs r0, r2
_08030D56:
	cmp r0, #0x32
	bgt _08030D9A
	cmp r2, #0x00
	bge _08030D84
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x4E
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x33
	negs r0, r0
	b _08030D98
	.byte 0x00, 0x00
_08030D78: .4byte 0x08B20942
_08030D7C: .4byte 0x02039B84
_08030D80: .4byte 0x08121400
_08030D84:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x4E
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x33
_08030D98:
	str r0, [r4, #0x3C]
_08030D9A:
	ldr r0, _08030DA8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r4, #0x48]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08030DA8: .4byte 0x02039B84
	thumb_func_start task_btl_prize_1
task_btl_prize_1: @ 08030DAC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	ldr r6, _08030E34 @ =0x02039B84
	ldr r3, [r6, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08030DD0
	b _08031240
_08030DD0:
	ldr r0, [r7, #0x30]
	cmp r0, #0x00
	beq _08030DD8
	b _08031258
_08030DD8:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _08030E8C
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	adds r5, r7, #0x4
	cmp r4, #0x00
	beq _08030E00
	adds r2, r7, #0x0
	adds r2, #0x08
	adds r3, r7, #0x0
	adds r3, #0x0C
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl _0811D5C0
_08030E00:
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x20]
	adds r0, r0, r1
	str r0, [r7, #0x08]
	subs r1, #0x0F
	ldr r0, [r6, #0x00]
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r7, #0x20]
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801A8A4
	cmp r0, #0x01
	bcc _08030E42
	cmp r0, #0x02
	bhi _08030E38
	ldr r0, [r7, #0x3C]
	negs r0, r0
	str r0, [r7, #0x3C]
	b _08030E42
_08030E34: .4byte 0x02039B84
_08030E38:
	cmp r0, #0x04
	bhi _08030E42
	ldr r0, [r7, #0x40]
	negs r0, r0
	str r0, [r7, #0x40]
_08030E42:
	ldr r0, [r7, #0x00]
	ldr r1, [r7, #0x3C]
	adds r0, r0, r1
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x40]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	ldr r2, [r7, #0x0C]
	cmp r0, r2
	ble _08030E84
	ldrh r1, [r7, #0x2C]
	ldr r0, _08030E80 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r7, #0x2C]
	str r2, [r7, #0x08]
	bl func_080065A4
	ldr r1, [r7, #0x24]
	asrs r4, r1, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r1, r4
	adds r1, #0x01
	bl func_0811D684
	adds r4, r4, r0
	negs r4, r4
	str r4, [r7, #0x20]
	b _08030E8C
_08030E80: .4byte 0x0000FFFD
_08030E84:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x02
	orrs r0, r1
	strh r0, [r7, #0x2C]
_08030E8C:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x10
	ands r0, r1
	mov r12, r1
	cmp r0, #0x00
	bne _08030E9A
	b _08031244
_08030E9A:
	movs r4, #0x00
	mov r9, r4
	ldr r3, _08030EF8 @ =0x02039B84
	ldr r5, [r3, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ldr r0, [sp, #0x000]
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r8, r3
	cmp r0, #0x00
	bne _08030EBE
	b _080310E4
_08030EBE:
	ldr r0, [r5, #0x7C]
	ldr r1, [r7, #0x00]
	ldr r0, [r0, #0x04]
	subs r2, r1, r0
	adds r5, r1, #0x0
	cmp r2, #0x00
	bge _08030ECE
	subs r2, r0, r5
_08030ECE:
	ldr r0, _08030EFC @ =0x02039B9C
	ldr r1, [r0, #0x00]
	ldr r1, [r1, #0x7C]
	ldr r4, [r1, #0x04]
	subs r1, r5, r4
	adds r6, r0, #0x0
	cmp r1, #0x00
	bge _08030EE0
	subs r1, r4, r5
_08030EE0:
	cmp r2, r1
	bne _08030F00
	movs r2, #0x80
	lsls r2, r2, #0x05
	ldr r0, [sp, #0x000]
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, r0, #0x1F
	b _08030F08
_08030EF8: .4byte 0x02039B84
_08030EFC: .4byte 0x02039B9C
_08030F00:
	movs r0, #0x01
	cmp r2, r1
	bge _08030F08
	movs r0, #0x00
_08030F08:
	cmp r0, #0x00
	beq _08030FFC
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08030F20
	movs r4, #0x80
	lsls r4, r4, #0x09
_08030F20:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r1, r0, r5
	cmp r1, #0x00
	blt _08030F30
	cmp r1, r4
	blt _08030F36
	b _08030F7A
_08030F30:
	subs r0, r5, r0
	cmp r0, r4
	bge _08030F7A
_08030F36:
	asrs r4, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08030F4C
	cmp r1, r4
	blt _08030F52
	b _08030F7A
_08030F4C:
	subs r0, r0, r2
	cmp r0, r4
	bge _08030F7A
_08030F52:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08030F70
	ldr r0, _08030F6C @ =0x000031FF
	cmp r2, r0
	bgt _08030F68
	b _080310D8
_08030F68:
	b _08030F7A
	.byte 0x00, 0x00
_08030F6C: .4byte 0x000031FF
_08030F70:
	subs r1, r1, r0
	ldr r0, _08030FA0 @ =0x000031FF
	cmp r1, r0
	bgt _08030F7A
	b _080310D8
_08030F7A:
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08030F90
	movs r4, #0x80
	lsls r4, r4, #0x09
_08030F90:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r2, r0, r5
	cmp r2, #0x00
	blt _08030FA4
	cmp r2, r4
	blt _08030FAC
	b _08031154
_08030FA0: .4byte 0x000031FF
_08030FA4:
	subs r0, r5, r0
	cmp r0, r4
	blt _08030FAC
	b _08031154
_08030FAC:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08030FC4
	cmp r1, r4
	blt _08030FCC
	b _08031154
_08030FC4:
	subs r0, r0, r2
	cmp r0, r4
	blt _08030FCC
	b _08031154
_08030FCC:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08030FEC
	ldr r0, _08030FE8 @ =0x000031FF
	cmp r2, r0
	bgt _08030FE4
	b _0803115A
_08030FE4:
	b _08031154
	.byte 0x00, 0x00
_08030FE8: .4byte 0x000031FF
_08030FEC:
	subs r1, r1, r0
	ldr r0, _08030FF8 @ =0x000031FF
	cmp r1, r0
	ble _08030FF6
	b _08031154
_08030FF6:
	b _0803115A
_08030FF8: .4byte 0x000031FF
_08030FFC:
	mov r4, r8
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031012
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031012:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r1, r0, r5
	cmp r1, #0x00
	blt _08031022
	cmp r1, r4
	blt _08031028
	b _0803106C
_08031022:
	subs r0, r5, r0
	cmp r0, r4
	bge _0803106C
_08031028:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031040
	cmp r1, r4
	blt _08031046
	b _0803106C
_08031040:
	subs r0, r0, r2
	cmp r0, r4
	bge _0803106C
_08031046:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031064
	ldr r0, _08031060 @ =0x000031FF
	cmp r2, r0
	bgt _0803105E
	b _0803115A
_0803105E:
	b _0803106C
_08031060: .4byte 0x000031FF
_08031064:
	subs r1, r1, r0
	ldr r0, _08031090 @ =0x000031FF
	cmp r1, r0
	ble _0803115A
_0803106C:
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031080
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031080:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r2, r0, r5
	cmp r2, #0x00
	blt _08031094
	cmp r2, r4
	blt _0803109A
	b _08031154
_08031090: .4byte 0x000031FF
_08031094:
	subs r0, r5, r0
	cmp r0, r4
	bge _08031154
_0803109A:
	asrs r3, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080310B0
	cmp r1, r3
	blt _080310B6
	b _08031154
_080310B0:
	subs r0, r0, r2
	cmp r0, r3
	bge _08031154
_080310B6:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _080310D0
	ldr r0, _080310CC @ =0x000031FF
	cmp r2, r0
	ble _080310D8
	b _08031154
_080310CC: .4byte 0x000031FF
_080310D0:
	subs r1, r1, r0
	ldr r0, _080310E0 @ =0x000031FF
	cmp r1, r0
	bgt _08031154
_080310D8:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r7, #0x48]
	b _0803115A
_080310E0: .4byte 0x000031FF
_080310E4:
	adds r0, r5, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _080310F6
	movs r4, #0x80
	lsls r4, r4, #0x09
_080310F6:
	ldr r0, [r5, #0x7C]
	ldr r3, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r1, r3, r0
	cmp r1, #0x00
	blt _08031108
	cmp r1, r4
	blt _0803110E
	b _08031154
_08031108:
	subs r0, r0, r3
	cmp r0, r4
	bge _08031154
_0803110E:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031126
	cmp r1, r4
	blt _0803112C
	b _08031154
_08031126:
	subs r0, r0, r2
	cmp r0, r4
	bge _08031154
_0803112C:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031148
	ldr r0, _08031144 @ =0x000031FF
	cmp r2, r0
	ble _08031150
	b _08031154
_08031144: .4byte 0x000031FF
_08031148:
	subs r1, r1, r0
	ldr r0, _08031194 @ =0x000031FF
	cmp r1, r0
	bgt _08031154
_08031150:
	movs r4, #0x01
	mov r9, r4
_08031154:
	mov r0, r9
	cmp r0, #0x00
	beq _08031210
_0803115A:
	movs r0, #0x6B
	bl func_0811FE70
	ldr r0, _08031198 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803119C
	ldr r1, [r7, #0x48]
	ldrh r0, [r7, #0x3A]
	ldrh r2, [r1, #0x2C]
	adds r0, r0, r2
	strh r0, [r1, #0x2C]
	ldr r2, [r7, #0x48]
	movs r4, #0x2C
	ldsh r1, [r2, r4]
	ldrh r3, [r2, #0x2E]
	movs r4, #0x2E
	ldsh r0, [r2, r4]
	cmp r1, r0
	ble _080311C8
	strh r3, [r2, #0x2C]
	b _080311C8
_08031194: .4byte 0x000031FF
_08031198: .4byte 0x02039B84
_0803119C:
	ldr r1, [r7, #0x48]
	ldrh r0, [r7, #0x3A]
	ldrh r2, [r1, #0x2C]
	adds r0, r0, r2
	strh r0, [r1, #0x2C]
	ldr r2, [r7, #0x48]
	movs r4, #0x2C
	ldsh r1, [r2, r4]
	ldrh r3, [r2, #0x2E]
	movs r4, #0x2E
	ldsh r0, [r2, r4]
	cmp r1, r0
	ble _080311B8
	strh r3, [r2, #0x2C]
_080311B8:
	ldr r0, _08031208 @ =0x02039BB0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrh r2, [r7, #0x38]
	ldr r1, [r0, #0x00]
	adds r1, r1, r2
	str r1, [r0, #0x00]
_080311C8:
	movs r0, #0x01
	str r0, [r7, #0x30]
	movs r0, #0x00
	strh r0, [r7, #0x28]
	ldr r1, [r7, #0x48]
	ldr r0, [r1, #0x04]
	ldr r1, [r1, #0x08]
	ldr r2, [r7, #0x00]
	ldr r3, [r7, #0x04]
	bl func_0801CB6C
	adds r1, r7, #0x0
	adds r1, #0x44
	strb r0, [r1, #0x00]
	ldrh r1, [r7, #0x2C]
	ldr r0, _0803120C @ =0x0000FFFD
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r7, #0x2C]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl func_0811D7CC
	adds r0, #0x05
	adds r1, r7, #0x0
	adds r1, #0x2A
	strb r0, [r1, #0x00]
	b _080312DA
_08031208: .4byte 0x02039BB0
_0803120C: .4byte 0x0000FFFD
_08031210:
	movs r0, #0x08
	mov r2, r12
	ands r0, r2
	ldrh r2, [r7, #0x28]
	cmp r0, #0x00
	bne _08031254
	lsls r1, r2, #0x10
	movs r0, #0xB4
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _08031236
	movs r0, #0x03
	ands r0, r2
	cmp r0, #0x00
	bne _08031236
	movs r0, #0x01
	mov r4, r12
	eors r0, r4
	strh r0, [r7, #0x2C]
_08031236:
	lsls r1, r2, #0x10
	movs r0, #0xD2
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _08031254
_08031240:
	movs r0, #0x00
	b _080312DC
_08031244:
	movs r2, #0x28
	ldsh r0, [r7, r2]
	ldrh r2, [r7, #0x28]
	cmp r0, #0x0A
	ble _08031254
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x2C]
_08031254:
	adds r0, r2, #0x1
	b _080312D8
_08031258:
	ldr r5, [r7, #0x48]
	ldr r6, _080312EC @ =0x08121400
	movs r4, #0x44
	adds r4, r4, r7
	mov r8, r4
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r6
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, [r7, #0x34]
	lsls r0, r1, #0x05
	muls r0, r2
	asrs r0, r0, #0x08
	ldr r3, [r5, #0x04]
	adds r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r6
	movs r2, #0x00
	ldsh r0, [r0, r2]
	negs r0, r0
	lsls r1, r1, #0x04
	muls r0, r1
	asrs r0, r0, #0x08
	ldr r2, [r5, #0x08]
	adds r2, r2, r0
	ldrh r0, [r7, #0x28]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x08
	ldr r1, [r5, #0x0C]
	subs r1, r1, r0
	adds r0, r7, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	adds r4, r4, r0
	mov r0, r8
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	subs r3, r3, r0
	asrs r3, r3, #0x02
	adds r0, r0, r3
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x02
	adds r0, r0, r2
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	subs r1, r1, r0
	asrs r1, r1, #0x02
	adds r0, r0, r1
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x34]
	subs r0, #0x02
	str r0, [r7, #0x34]
	ldrh r1, [r7, #0x28]
	movs r2, #0x28
	ldsh r0, [r7, r2]
	cmp r0, #0x3C
	bgt _08031240
	adds r0, r1, #0x1
_080312D8:
	strh r0, [r7, #0x28]
_080312DA:
	movs r0, #0x01
_080312DC:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080312EC: .4byte 0x08121400
	thumb_func_start task_btl_prize_2
task_btl_prize_2: @ 080312F0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldrh r1, [r6, #0x2C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080313A2
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r9, r0
	mov r7, sp
	adds r7, #0x12
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r7, #0x0
	bl func_0801909C
	ldr r0, _080313B0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x01
	bl func_08002CB4
	mov r8, r0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r2, [r6, #0x18]
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r5, [r6, #0x04]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _080313B4 @ =0xFFFFEFFC
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldrh r1, [r6, #0x2C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080313A2
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r7, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r2, [r6, #0x1C]
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r4, _080313B8 @ =0x0000FFFF
	str r4, [sp, #0x00C]
	bl func_080023E0
_080313A2:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080313B0: .4byte 0x02039B84
_080313B4: .4byte 0xFFFFEFFC
_080313B8: .4byte 0x0000FFFF
	thumb_func_start task_btl_prize_3
task_btl_prize_3: @ 080313BC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x10]
	bl func_080028C0
	ldr r0, [r4, #0x14]
	bl func_08002C10
	ldr r0, _080313E0 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080313E0: .4byte 0x02039B84
	thumb_func_start task_btl_premire_0
task_btl_premire_0: @ 080313E4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x08]
	movs r0, #0x00
	mov r8, r0
	str r0, [r5, #0x0C]
	ldr r1, _080314EC @ =0x02039B84
	mov r9, r1
	ldr r0, [r1, #0x00]
	movs r4, #0x94
	lsls r4, r4, #0x01
	adds r0, r0, r4
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	beq _08031424
	adds r1, r5, #0x4
	adds r2, r5, #0x0
	adds r2, #0x08
	adds r3, r5, #0x0
	adds r3, #0x0C
	adds r0, r5, #0x0
	bl _0811D5C0
_08031424:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080314F0 @ =0x00000381
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r0, r1
	negs r0, r0
	str r0, [r5, #0x20]
	bl func_080065A4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _080314F4 @ =0x08B209E0
	movs r1, #0xD0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x10]
	ldr r0, _080314F8 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x14]
	adds r4, r5, #0x0
	adds r4, #0x48
	ldr r1, _080314FC @ =0x09EE1278
	ldr r2, _08031500 @ =0x09EE1244
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r5, #0x18]
	mov r4, r8
	strh r4, [r5, #0x28]
	ldr r0, _08031504 @ =0x08B208E8
	str r0, [r5, #0x1C]
	movs r0, #0x03
	strh r0, [r5, #0x2C]
	movs r1, #0x14
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	beq _08031496
	movs r0, #0x0B
	strh r0, [r5, #0x2C]
_08031496:
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [r5, #0x24]
	movs r3, #0xC0
	lsls r3, r3, #0x01
	mov r4, r8
	str r4, [r5, #0x30]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r5, #0x34]
	mov r0, r9
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _08031508 @ =0x08121400
	lsls r0, r7, #0x01
	adds r0, r0, r1
	movs r4, #0x00
	ldsh r0, [r0, r4]
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r5, #0x38]
	adds r0, r7, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r5, #0x3C]
	ldr r0, [r2, #0x7C]
	str r0, [r5, #0x44]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080314EC: .4byte 0x02039B84
_080314F0: .4byte 0x00000381
_080314F4: .4byte 0x08B209E0
_080314F8: .4byte 0x08F69BA4
_080314FC: .4byte 0x09EE1278
_08031500: .4byte 0x09EE1244
_08031504: .4byte 0x08B208E8
_08031508: .4byte 0x08121400
	thumb_func_start task_btl_premire_1
task_btl_premire_1: @ 0803150C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0x0
	ldr r6, _08031594 @ =0x02039B84
	ldr r3, [r6, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803152E
	b _08031938
_0803152E:
	ldr r0, [r7, #0x30]
	cmp r0, #0x00
	beq _08031536
	b _08031950
_08031536:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080315EC
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	adds r5, r7, #0x4
	cmp r4, #0x00
	beq _0803155E
	adds r2, r7, #0x0
	adds r2, #0x08
	adds r3, r7, #0x0
	adds r3, #0x0C
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl _0811D5C0
_0803155E:
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x20]
	adds r0, r0, r1
	str r0, [r7, #0x08]
	subs r1, #0x0F
	ldr r0, [r6, #0x00]
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r7, #0x20]
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801A8A4
	cmp r0, #0x01
	bcc _080315A2
	cmp r0, #0x02
	bhi _08031598
	ldr r0, [r7, #0x38]
	negs r0, r0
	str r0, [r7, #0x38]
	b _080315A2
	.byte 0x00, 0x00
_08031594: .4byte 0x02039B84
_08031598:
	cmp r0, #0x04
	bhi _080315A2
	ldr r0, [r7, #0x3C]
	negs r0, r0
	str r0, [r7, #0x3C]
_080315A2:
	ldr r0, [r7, #0x00]
	ldr r1, [r7, #0x38]
	adds r0, r0, r1
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x3C]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	ldr r2, [r7, #0x0C]
	cmp r0, r2
	ble _080315E4
	ldrh r1, [r7, #0x2C]
	ldr r0, _080315E0 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r7, #0x2C]
	str r2, [r7, #0x08]
	bl func_080065A4
	ldr r1, [r7, #0x24]
	asrs r4, r1, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r1, r4
	adds r1, #0x01
	bl func_0811D684
	adds r4, r4, r0
	negs r4, r4
	str r4, [r7, #0x20]
	b _080315EC
_080315E0: .4byte 0x0000FFFD
_080315E4:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x02
	orrs r0, r1
	strh r0, [r7, #0x2C]
_080315EC:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x10
	ands r0, r1
	mov r12, r1
	cmp r0, #0x00
	bne _080315FA
	b _0803193C
_080315FA:
	movs r0, #0x00
	mov r9, r0
	ldr r3, _0803165C @ =0x02039B84
	ldr r6, [r3, #0x00]
	ldr r4, [r6, #0x68]
	ldr r5, [r6, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r4, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r8, r3
	cmp r0, #0x00
	bne _0803161A
	b _08031824
_0803161A:
	movs r0, #0x80
	lsls r0, r0, #0x05
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0803162E
	b _08031730
_0803162E:
	ldr r0, _08031660 @ =0x02039B9C
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	adds r6, r0, #0x0
	cmp r1, #0x06
	bne _08031646
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031646:
	ldr r0, [r2, #0x7C]
	ldr r1, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r2, r1, r0
	adds r5, r0, #0x0
	cmp r2, #0x00
	blt _08031664
	cmp r2, r4
	blt _0803166A
	b _080316AE
	.byte 0x00, 0x00
_0803165C: .4byte 0x02039B84
_08031660: .4byte 0x02039B9C
_08031664:
	subs r0, r5, r1
	cmp r0, r4
	bge _080316AE
_0803166A:
	asrs r4, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031680
	cmp r1, r4
	blt _08031686
	b _080316AE
_08031680:
	subs r0, r0, r2
	cmp r0, r4
	bge _080316AE
_08031686:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _080316A4
	ldr r0, _080316A0 @ =0x000031FF
	cmp r2, r0
	bgt _0803169C
	b _08031818
_0803169C:
	b _080316AE
	.byte 0x00, 0x00
_080316A0: .4byte 0x000031FF
_080316A4:
	subs r1, r1, r0
	ldr r0, _080316D4 @ =0x000031FF
	cmp r1, r0
	bgt _080316AE
	b _08031818
_080316AE:
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _080316C4
	movs r4, #0x80
	lsls r4, r4, #0x09
_080316C4:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r1, r0, r5
	cmp r1, #0x00
	blt _080316D8
	cmp r1, r4
	blt _080316E0
	b _08031894
_080316D4: .4byte 0x000031FF
_080316D8:
	subs r0, r5, r0
	cmp r0, r4
	blt _080316E0
	b _08031894
_080316E0:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080316F8
	cmp r1, r4
	blt _08031700
	b _08031894
_080316F8:
	subs r0, r0, r2
	cmp r0, r4
	blt _08031700
	b _08031894
_08031700:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031720
	ldr r0, _0803171C @ =0x000031FF
	cmp r2, r0
	bgt _08031718
	b _0803189A
_08031718:
	b _08031894
	.byte 0x00, 0x00
_0803171C: .4byte 0x000031FF
_08031720:
	subs r1, r1, r0
	ldr r0, _0803172C @ =0x000031FF
	cmp r1, r0
	ble _0803172A
	b _08031894
_0803172A:
	b _0803189A
_0803172C: .4byte 0x000031FF
_08031730:
	adds r0, r6, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031742
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031742:
	ldr r0, [r6, #0x7C]
	ldr r3, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r1, r3, r0
	adds r5, r0, #0x0
	cmp r1, #0x00
	blt _08031756
	cmp r1, r4
	blt _0803175C
	b _080317A2
_08031756:
	subs r0, r5, r3
	cmp r0, r4
	bge _080317A2
_0803175C:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031774
	cmp r1, r4
	blt _0803177A
	b _080317A2
_08031774:
	subs r0, r0, r2
	cmp r0, r4
	bge _080317A2
_0803177A:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031798
	ldr r0, _08031794 @ =0x000031FF
	cmp r2, r0
	bgt _08031792
	b _0803189A
_08031792:
	b _080317A2
_08031794: .4byte 0x000031FF
_08031798:
	subs r1, r1, r0
	ldr r0, _080317CC @ =0x000031FF
	cmp r1, r0
	bgt _080317A2
	b _0803189A
_080317A2:
	ldr r0, _080317D0 @ =0x02039B9C
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	adds r6, r0, #0x0
	cmp r1, #0x06
	bne _080317BA
	movs r4, #0x80
	lsls r4, r4, #0x09
_080317BA:
	ldr r0, [r2, #0x7C]
	ldr r0, [r0, #0x04]
	subs r2, r0, r5
	cmp r2, #0x00
	blt _080317D4
	cmp r2, r4
	blt _080317DA
	b _08031894
	.byte 0x00, 0x00
_080317CC: .4byte 0x000031FF
_080317D0: .4byte 0x02039B9C
_080317D4:
	subs r0, r5, r0
	cmp r0, r4
	bge _08031894
_080317DA:
	asrs r3, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080317F0
	cmp r1, r3
	blt _080317F6
	b _08031894
_080317F0:
	subs r0, r0, r2
	cmp r0, r3
	bge _08031894
_080317F6:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031810
	ldr r0, _0803180C @ =0x000031FF
	cmp r2, r0
	ble _08031818
	b _08031894
_0803180C: .4byte 0x000031FF
_08031810:
	subs r1, r1, r0
	ldr r0, _08031820 @ =0x000031FF
	cmp r1, r0
	bgt _08031894
_08031818:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r7, #0x44]
	b _0803189A
_08031820: .4byte 0x000031FF
_08031824:
	adds r0, r6, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031836
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031836:
	ldr r0, [r6, #0x7C]
	ldr r3, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r1, r3, r0
	cmp r1, #0x00
	blt _08031848
	cmp r1, r4
	blt _0803184E
	b _08031894
_08031848:
	subs r0, r0, r3
	cmp r0, r4
	bge _08031894
_0803184E:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031866
	cmp r1, r4
	blt _0803186C
	b _08031894
_08031866:
	subs r0, r0, r2
	cmp r0, r4
	bge _08031894
_0803186C:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031888
	ldr r0, _08031884 @ =0x000031FF
	cmp r2, r0
	ble _08031890
	b _08031894
_08031884: .4byte 0x000031FF
_08031888:
	subs r1, r1, r0
	ldr r0, _080318F4 @ =0x000031FF
	cmp r1, r0
	bgt _08031894
_08031890:
	movs r0, #0x01
	mov r9, r0
_08031894:
	mov r1, r9
	cmp r1, #0x00
	beq _08031908
_0803189A:
	movs r0, #0x6B
	bl func_0811FE70
	ldr r0, _080318F8 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080318FC @ =0x00000000
	ldr r3, _08031900 @ =0x00080000
	orrs r1, r3
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	movs r1, #0x00
	movs r0, #0x01
	str r0, [r7, #0x30]
	strh r1, [r7, #0x28]
	ldr r1, [r7, #0x44]
	ldr r0, [r1, #0x04]
	ldr r1, [r1, #0x08]
	ldr r2, [r7, #0x00]
	ldr r3, [r7, #0x04]
	bl func_0801CB6C
	adds r1, r7, #0x0
	adds r1, #0x40
	strb r0, [r1, #0x00]
	ldrh r1, [r7, #0x2C]
	ldr r0, _08031904 @ =0x0000FFFD
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r7, #0x2C]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl func_0811D7CC
	adds r0, #0x05
	adds r1, r7, #0x0
	adds r1, #0x2A
	strb r0, [r1, #0x00]
	b _080319D2
	.byte 0x00, 0x00
_080318F4: .4byte 0x000031FF
_080318F8: .4byte 0x02039B84
_080318FC: .4byte 0x00000000
_08031900: .4byte 0x00080000
_08031904: .4byte 0x0000FFFD
_08031908:
	movs r0, #0x08
	mov r2, r12
	ands r0, r2
	ldrh r2, [r7, #0x28]
	cmp r0, #0x00
	bne _0803194C
	lsls r1, r2, #0x10
	movs r0, #0xB4
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0803192E
	movs r0, #0x03
	ands r0, r2
	cmp r0, #0x00
	bne _0803192E
	movs r0, #0x01
	mov r1, r12
	eors r0, r1
	strh r0, [r7, #0x2C]
_0803192E:
	lsls r1, r2, #0x10
	movs r0, #0xD2
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0803194C
_08031938:
	movs r0, #0x00
	b _080319DE
_0803193C:
	movs r2, #0x28
	ldsh r0, [r7, r2]
	ldrh r2, [r7, #0x28]
	cmp r0, #0x0A
	ble _0803194C
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x2C]
_0803194C:
	adds r0, r2, #0x1
	b _080319D0
_08031950:
	ldr r5, [r7, #0x44]
	ldr r6, _080319EC @ =0x08121400
	movs r0, #0x40
	adds r0, r0, r7
	mov r8, r0
	ldrb r4, [r0, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r6
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, [r7, #0x34]
	lsls r0, r1, #0x05
	muls r0, r2
	asrs r0, r0, #0x08
	ldr r3, [r5, #0x04]
	adds r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r6
	movs r2, #0x00
	ldsh r0, [r0, r2]
	negs r0, r0
	lsls r1, r1, #0x04
	muls r0, r1
	asrs r0, r0, #0x08
	ldr r2, [r5, #0x08]
	adds r2, r2, r0
	ldrh r0, [r7, #0x28]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x08
	ldr r1, [r5, #0x0C]
	subs r1, r1, r0
	adds r0, r7, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	adds r4, r4, r0
	mov r0, r8
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	subs r3, r3, r0
	asrs r3, r3, #0x02
	adds r0, r0, r3
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x02
	adds r0, r0, r2
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	subs r1, r1, r0
	asrs r1, r1, #0x02
	adds r0, r0, r1
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x34]
	subs r0, #0x02
	str r0, [r7, #0x34]
	ldrh r1, [r7, #0x28]
	movs r2, #0x28
	ldsh r0, [r7, r2]
	cmp r0, #0x3C
	bgt _08031938
	adds r0, r1, #0x1
_080319D0:
	strh r0, [r7, #0x28]
_080319D2:
	adds r0, r7, #0x0
	adds r0, #0x48
	bl func_08005A64
	str r0, [r7, #0x18]
	movs r0, #0x01
_080319DE:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080319EC: .4byte 0x08121400
	thumb_func_start task_btl_premire_2
task_btl_premire_2: @ 080319F0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldrh r1, [r6, #0x2C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08031AA8
	ldr r0, [r6, #0x04]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	mov r7, sp
	adds r7, #0x12
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r7, #0x0
	bl func_0801909C
	ldr r0, _08031AB8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x01
	bl func_08002CB4
	mov r8, r0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r2, [r6, #0x18]
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r5, [r6, #0x04]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _08031ABC @ =0xFFFFEFFC
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldrh r1, [r6, #0x2C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08031AA8
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r7, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r7, r2]
	ldr r2, [r6, #0x1C]
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0x14]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	mov r5, r9
	str r5, [sp, #0x008]
	ldr r4, _08031AC0 @ =0x0000FFFF
	str r4, [sp, #0x00C]
	bl func_080023E0
_08031AA8:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08031AB8: .4byte 0x02039B84
_08031ABC: .4byte 0xFFFFEFFC
_08031AC0: .4byte 0x0000FFFF
	thumb_func_start task_btl_premire_3
task_btl_premire_3: @ 08031AC4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x10]
	bl func_080028C0
	ldr r0, [r4, #0x14]
	bl func_08002C10
	ldr r0, _08031AE8 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08031AE8: .4byte 0x02039B84
	thumb_func_start task_btl_start_0
task_btl_start_0: @ 08031AEC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	ldr r0, _08031B5C @ =0x09EDA918
	movs r1, #0x78
	movs r2, #0x48
	bl func_08006778
	movs r4, #0x80
	lsls r4, r4, #0x02
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r4, #0x0
	bl func_0800675C
	ldr r6, _08031B60 @ =0x02039B84
	ldr r0, [r6, #0x00]
	movs r5, #0xE2
	lsls r5, r5, #0x01
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	movs r1, #0x10
	movs r2, #0x10
	bl func_080057A0
	movs r2, #0x80
	lsls r2, r2, #0x09
	movs r3, #0xA0
	lsls r3, r3, #0x09
	movs r0, #0x01
	adds r1, r4, #0x0
	bl func_08019050
	movs r0, #0x00
	movs r1, #0x3C
	bl func_08006120
	movs r0, #0x00
	mov r1, r8
	strh r0, [r1, #0x00]
	movs r0, #0x8F
	bl func_0811FE70
	ldr r0, [r6, #0x00]
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	movs r1, #0x00
	bl func_080055C8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08031B5C: .4byte 0x09EDA918
_08031B60: .4byte 0x02039B84
	thumb_func_start task_btl_start_1
task_btl_start_1: @ 08031B64
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x14
	bgt _08031B78
	movs r0, #0x00
	movs r1, #0x28
	bl func_08006120
_08031B78:
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x2B
	beq _08031BA8
	cmp r0, #0x2B
	bgt _08031B8A
	cmp r0, #0x22
	beq _08031B90
	b _08031BB6
_08031B8A:
	cmp r0, #0x4A
	beq _08031BB2
	b _08031BB6
_08031B90:
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldr r0, _08031BA4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	movs r0, #0x23
	bl func_08019050
	b _08031BB6
_08031BA4: .4byte 0x02039B84
_08031BA8:
	movs r0, #0x02
	movs r1, #0x1E
	bl func_08006120
	b _08031BB6
_08031BB2:
	movs r0, #0x00
	b _08031BBE
_08031BB6:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x01
_08031BBE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_start func_08031BC4
func_08031BC4: @ 08031BC4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031BE4
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031BE4
	movs r0, #0xAD
	b _08031D6C
_08031BE4:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031C00
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031C00
	movs r0, #0xD3
	b _08031D6C
_08031C00:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031C1C
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031C1C
	movs r0, #0x2D
	b _08031D6C
_08031C1C:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031C38
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031C38
	movs r0, #0x53
	b _08031D6C
_08031C38:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031C56
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031C56
	movs r0, #0xAD
	b _08031D6C
_08031C56:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08031C74
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031C74
	movs r0, #0x53
	b _08031D6C
_08031C74:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031C92
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031C92
	movs r0, #0xD3
	b _08031D6C
_08031C92:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031CB0
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031CB0
	movs r0, #0x2D
	b _08031D6C
_08031CB0:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031CCE
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031CCE
	movs r0, #0xD3
	b _08031D6C
_08031CCE:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031CEC
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031CEC
	movs r0, #0xAD
	b _08031D6C
_08031CEC:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031D0A
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031D0A
	movs r0, #0x2D
	b _08031D6C
_08031D0A:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031D28
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08031D28
	movs r0, #0x53
	b _08031D6C
_08031D28:
	bl func_08001384
	movs r2, #0x80
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _08031D3E
	strb r2, [r4, #0x14]
	b _08031D6E
_08031D3E:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08031D4E
	strb r5, [r4, #0x14]
	b _08031D6E
_08031D4E:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08031D5E
	movs r0, #0xC0
	b _08031D6C
_08031D5E:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08031D6E
	movs r0, #0x40
_08031D6C:
	strb r0, [r4, #0x14]
_08031D6E:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start func_08031D74
func_08031D74: @ 08031D74
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r7, r0, #0x0
	mov r1, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	add r4, sp, #0x010
	adds r1, r4, #0x0
	adds r0, r7, #0x0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	ldr r5, _08031DE0 @ =0xFFFFFA00
	adds r0, r0, r5
	str r0, [sp, #0x004]
	ldr r0, [r4, #0x04]
	movs r1, #0xC0
	lsls r1, r1, #0x03
	adds r0, r0, r1
	str r0, [r4, #0x04]
	mov r0, sp
	bl func_080DFF1C
	adds r6, r0, #0x0
	ldr r0, [sp, #0x00C]
	cmp r6, r0
	ble _08031DB4
	str r6, [sp, #0x00C]
_08031DB4:
	adds r0, r4, #0x0
	bl func_080DFF1C
	adds r5, r0, #0x0
	ldr r0, [r4, #0x0C]
	cmp r5, r0
	ble _08031DC4
	str r5, [r4, #0x0C]
_08031DC4:
	mov r0, sp
	bl func_080DFBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08031DDC
	adds r0, r4, #0x0
	bl func_080DFBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08031DE4
_08031DDC:
	movs r0, #0x01
	b _08031DF0
_08031DE0: .4byte 0xFFFFFA00
_08031DE4:
	adds r0, r5, #0x0
	cmp r0, r6
	ble _08031DEC
	adds r0, r6, #0x0
_08031DEC:
	str r0, [r7, #0x0C]
	movs r0, #0x00
_08031DF0:
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start func_08031DF8
func_08031DF8: @ 08031DF8
	push {r4, r5, lr}
	add sp, #-0x020
	mov r2, sp
	adds r1, r0, #0x0
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	add r4, sp, #0x010
	adds r1, r4, #0x0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	ldr r1, _08031E44 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #0x004]
	ldr r0, [r4, #0x04]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	str r0, [r4, #0x04]
	mov r0, sp
	bl func_080DFF1C
	adds r5, r0, #0x0
	adds r0, r4, #0x0
	bl func_080DFF1C
	cmp r0, r5
	ble _08031E3A
	adds r0, r5, #0x0
_08031E3A:
	add sp, #0x020
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08031E44: .4byte 0xFFFFFA00
	thumb_func_start func_08031E48
func_08031E48: @ 08031E48
	push {r4, r5, r6, lr}
	add sp, #-0x020
	adds r5, r1, #0x0
	mov r2, sp
	adds r1, r0, #0x0
	ldm r1!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	add r4, sp, #0x010
	adds r1, r4, #0x0
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	ldr r1, _08031E94 @ =0xFFFFFA00
	adds r0, r0, r1
	str r0, [sp, #0x004]
	ldr r0, [r4, #0x04]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	str r0, [r4, #0x04]
	mov r0, sp
	bl _080DFE1C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	beq _08031E98
	adds r1, r5, #0x0
	adds r1, #0xB0
	ldr r0, [sp, #0x000]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [sp, #0x004]
	b _08031EB6
_08031E94: .4byte 0xFFFFFA00
_08031E98:
	adds r0, r4, #0x0
	bl _080DFE1C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x00
	bne _08031EAA
	movs r0, #0x00
	b _08031EBA
_08031EAA:
	adds r1, r5, #0x0
	adds r1, #0xB0
	ldr r0, [sp, #0x010]
	str r0, [r1, #0x00]
	adds r1, #0x04
	ldr r0, [r4, #0x04]
_08031EB6:
	str r0, [r1, #0x00]
	adds r0, r2, #0x0
_08031EBA:
	add sp, #0x020
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start func_08031EC4
func_08031EC4: @ 08031EC4
	push {r4, r5, lr}
	add sp, #-0x010
	mov r2, sp
	adds r1, r0, #0x0
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1, #0x00]
	str r1, [r2, #0x00]
	ldr r3, _08031F0C @ =0x08121400
	ldrb r1, [r0, #0x14]
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r4, #0x00
	ldsh r2, [r1, r4]
	lsls r2, r2, #0x03
	ldr r1, [sp, #0x000]
	adds r1, r1, r2
	str r1, [sp, #0x000]
	ldrb r0, [r0, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r1, [r0, r5]
	lsls r1, r1, #0x03
	ldr r0, [sp, #0x004]
	subs r0, r0, r1
	str r0, [sp, #0x004]
	mov r0, sp
	bl func_080DFCDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08031F10
	movs r0, #0x00
	b _08031F12
_08031F0C: .4byte 0x08121400
_08031F10:
	movs r0, #0x01
_08031F12:
	add sp, #0x010
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start func_08031F1C
func_08031F1C: @ 08031F1C
	push {r4, lr}
	adds r2, r0, #0x0
	ldr r0, _08031F4C @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r3, #0x18
	adds r0, r2, #0x0
	adds r0, #0x66
	ldrh r0, [r0, #0x00]
	movs r4, #0x01
	adds r1, r4, #0x0
	ands r1, r0
	cmp r1, #0x00
	beq _08031F50
	ldr r0, [r3, #0x0C]
	ldr r1, [r2, #0x78]
	cmp r0, r1
	bge _08031F42
	adds r1, r0, #0x0
_08031F42:
	adds r0, r2, #0x0
	adds r0, #0xBC
	strb r4, [r0, #0x00]
	b _08031F58
	.byte 0x00, 0x00
_08031F4C: .4byte 0x02039BA0
_08031F50:
	adds r0, r2, #0x0
	adds r0, #0xBC
	strb r1, [r0, #0x00]
	ldr r1, [r3, #0x0C]
_08031F58:
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_start func_08031F60
func_08031F60: @ 08031F60
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrb r5, [r4, #0x14]
	bl func_08031BC4
	ldrb r0, [r4, #0x14]
	cmp r5, r0
	beq _08031F90
	ldrb r1, [r4, #0x14]
	adds r0, r5, #0x0
	bl func_08005824
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _08031F82
	negs r0, r0
_08031F82:
	cmp r0, #0x64
	ble _08031F8A
	movs r0, #0x00
	b _08031F8E
_08031F8A:
	ldr r0, [r4, #0x10]
	asrs r0, r0, #0x01
_08031F8E:
	str r0, [r4, #0x10]
_08031F90:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start func_08031F98
func_08031F98: @ 08031F98
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	ldr r0, _08031FC4 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x53
	beq _08031FFC
	cmp r0, #0x53
	bgt _08031FC8
	cmp r0, #0x2D
	beq _08031FE0
	cmp r0, #0x2D
	ble _0803201A
	cmp r0, #0x40
	beq _08031FEE
	b _0803201A
	.byte 0x00, 0x00
_08031FC4: .4byte 0x02039BA0
_08031FC8:
	cmp r0, #0xAD
	beq _0803200E
	cmp r0, #0xAD
	bgt _08031FD6
	cmp r0, #0x80
	beq _0803200A
	b _0803201A
_08031FD6:
	cmp r0, #0xC0
	beq _08032012
	cmp r0, #0xD3
	beq _08032016
	b _0803201A
_08031FE0:
	movs r3, #0x04
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _08032026
_08031FEE:
	movs r3, #0x03
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _08032026
_08031FFC:
	movs r3, #0x02
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	movs r0, #0x02
	orrs r0, r1
	b _08032026
_0803200A:
	movs r3, #0x01
	b _0803201C
_0803200E:
	movs r3, #0x02
	b _0803201C
_08032012:
	movs r3, #0x03
	b _0803201C
_08032016:
	movs r3, #0x04
	b _0803201C
_0803201A:
	movs r3, #0x00
_0803201C:
	adds r2, r5, #0x0
	adds r2, #0xA4
	ldrh r1, [r2, #0x00]
	ldr r0, _08032068 @ =0x0000FFFD
	ands r0, r1
_08032026:
	strh r0, [r2, #0x00]
	adds r1, r5, #0x0
	adds r1, #0xA8
	ldr r0, [r1, #0x00]
	cmp r0, r6
	bne _08032036
	movs r0, #0x04
	orrs r7, r0
_08032036:
	str r6, [r1, #0x00]
	lsls r4, r6, #0x02
	adds r4, r4, r6
	lsls r4, r4, #0x04
	lsls r0, r3, #0x04
	ldr r1, _0803206C @ =0x0813C89C
	adds r0, r0, r1
	adds r4, r4, r0
	adds r0, r5, #0x0
	adds r0, #0x08
	ldrb r1, [r4, #0x0C]
	ldr r3, [r4, #0x04]
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	adds r2, r7, #0x0
	bl func_08005974
	ldr r0, [r5, #0x00]
	ldr r1, [r4, #0x08]
	bl func_08002A10
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08032068: .4byte 0x0000FFFD
_0803206C: .4byte 0x0813C89C
