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

	thumb_func_start task_allmap_room_0
task_allmap_room_0: @ 080D37EC
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldrh r2, [r1, #0x00]
	adds r0, #0x8C
	strh r2, [r0, #0x00]
	ldrh r0, [r1, #0x02]
	adds r2, r5, #0x0
	adds r2, #0x8E
	strh r0, [r2, #0x00]
	adds r2, #0x02
	ldrh r0, [r1, #0x02]
	negs r0, r0
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	adds r2, #0x04
	ldrh r0, [r1, #0x02]
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	ldrb r2, [r1, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x98
	strb r2, [r0, #0x00]
	ldrh r0, [r1, #0x06]
	adds r4, r5, #0x0
	adds r4, #0x9C
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_080D35B0
	adds r6, r5, #0x0
	adds r6, #0x9A
	strh r0, [r6, #0x00]
	ldrh r4, [r4, #0x00]
	cmp r4, #0x00
	bne _080D3848
	ldr r0, _080D3844 @ =0x0976B340
	movs r1, #0x90
	lsls r1, r1, #0x06
	bl func_080026A4
	str r0, [r5, #0x00]
	str r4, [r5, #0x08]
	b _080D3868
	.byte 0x00, 0x00
_080D3844: .4byte 0x0976B340
_080D3848:
	ldr r4, _080D3884 @ =0x09EF6424
	adds r0, r4, #0x0
	movs r1, #0x11
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D3888 @ =0x0976B340
	bl func_080028F8
	str r0, [r5, #0x00]
	ldrh r0, [r6, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
_080D3868:
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	adds r2, r5, #0x0
	adds r2, #0x98
	cmp r0, #0x00
	bne _080D3894
	ldr r1, _080D388C @ =0x0203C590
	ldrb r0, [r2, #0x00]
	ldrb r1, [r1, #0x06]
	cmp r0, r1
	bne _080D3894
	ldr r0, _080D3890 @ =0x0984A138
	b _080D389E
_080D3884: .4byte 0x09EF6424
_080D3888: .4byte 0x0976B340
_080D388C: .4byte 0x0203C590
_080D3890: .4byte 0x0984A138
_080D3894:
	ldrb r0, [r2, #0x00]
	bl func_080D37BC
	ldr r1, _080D38AC @ =0x0984A0F8
	adds r0, r0, r1
_080D389E:
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D38AC: .4byte 0x0984A0F8
	thumb_func_start task_allmap_room_1
task_allmap_room_1: @ 080D38B0
	movs r0, #0x01
	bx lr
	thumb_func_start task_allmap_room_2
task_allmap_room_2: @ 080D38B4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r8, r0
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D391C
	mov r0, r8
	adds r0, #0x8C
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D3910 @ =0x0203C540
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r0, r8
	adds r0, #0x8E
	movs r4, #0x00
	ldsh r2, [r0, r4]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	ldr r1, _080D3914 @ =0x0203C53C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r10, r0
	lsls r2, r2, #0x02
	ldr r1, _080D3918 @ =0xFFFFEFFC
	adds r0, r1, #0x0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b _080D393C
	.byte 0x00, 0x00
_080D3910: .4byte 0x0203C540
_080D3914: .4byte 0x0203C53C
_080D3918: .4byte 0xFFFFEFFC
_080D391C:
	ldr r0, _080D39EC @ =0x02039BA0
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x0B
	ands r0, r1
	cmp r0, #0x00
	bne _080D39DC
	mov r0, r8
	adds r0, #0x8C
	ldrh r3, [r0, #0x00]
	adds r0, #0x02
	ldrh r4, [r0, #0x00]
	movs r2, #0x00
	mov r10, r2
	movs r5, #0x50
_080D393C:
	lsls r0, r3, #0x10
	asrs r6, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x0E
	adds r2, r0, r1
	movs r1, #0x88
	lsls r1, r1, #0x11
	str r0, [sp, #0x010]
	cmp r2, r1
	bhi _080D39DC
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	movs r1, #0x20
	negs r1, r1
	str r0, [sp, #0x014]
	cmp r4, r1
	blt _080D39DC
	cmp r4, #0xA0
	bgt _080D39DC
	mov r0, r8
	ldr r2, [r0, #0x08]
	cmp r2, #0x00
	beq _080D3982
	ldr r3, [r0, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	mov r1, r10
	str r1, [sp, #0x008]
	str r5, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080023E0
_080D3982:
	movs r6, #0x00
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	mov r9, r0
	mov r5, r8
	adds r5, #0x1C
	mov r7, r8
	adds r7, #0x2C
_080D3992:
	lsls r4, r6, #0x02
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D39D2
	adds r0, r7, #0x0
	bl func_08005A64
	adds r2, r0, #0x0
	str r2, [r5, #0x00]
	mov r0, r8
	adds r0, #0x0C
	adds r0, r0, r4
	ldr r3, [r0, #0x00]
	mov r4, r8
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	mov r0, r10
	str r0, [sp, #0x008]
	ldr r1, _080D39F0 @ =0x0000FFFC
	adds r0, r6, r1
	add r0, r9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	ldr r4, [sp, #0x010]
	asrs r0, r4, #0x10
	ldr r4, [sp, #0x014]
	asrs r1, r4, #0x10
	bl func_080023E0
_080D39D2:
	adds r5, #0x04
	adds r7, #0x18
	adds r6, #0x01
	cmp r6, #0x03
	ble _080D3992
_080D39DC:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D39EC: .4byte 0x02039BA0
_080D39F0: .4byte 0x0000FFFC
	thumb_func_start task_allmap_room_3
task_allmap_room_3: @ 080D39F4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r4, #0x0C
	movs r5, #0x03
_080D3A08:
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D3A12
	bl func_080028C0
_080D3A12:
	adds r4, #0x04
	subs r5, #0x01
	cmp r5, #0x00
	bge _080D3A08
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start func_080D3A20
func_080D3A20: @ 080D3A20
	push {r4, lr}
	add sp, #-0x008
	ldr r2, _080D3A5C @ =0xFFFF0000
	ldr r1, [sp, #0x000]
	ands r1, r2
	movs r2, #0xD0
	orrs r1, r2
	ldr r4, _080D3A60 @ =0x0000FFFF
	ands r1, r4
	str r1, [sp, #0x000]
	ldr r1, _080D3A64 @ =0x0203C590
	ldrb r3, [r1, #0x06]
	ldr r2, _080D3A68 @ =0xFFFFFF00
	ldr r1, [sp, #0x004]
	ands r1, r2
	orrs r1, r3
	ands r1, r4
	movs r2, #0x80
	lsls r2, r2, #0x09
	orrs r1, r2
	str r1, [sp, #0x004]
	ldr r1, _080D3A6C @ =0x09EF4DC0
	mov r2, sp
	bl func_08000E14
	add sp, #0x008
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D3A5C: .4byte 0xFFFF0000
_080D3A60: .4byte 0x0000FFFF
_080D3A64: .4byte 0x0203C590
_080D3A68: .4byte 0xFFFFFF00
_080D3A6C: .4byte 0x09EF4DC0
	thumb_func_start func_080D3A70
func_080D3A70: @ 080D3A70
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D3A94
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3AA2
_080D3A94:
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3AA6
_080D3AA2:
	movs r0, #0x00
	b _080D3AB2
_080D3AA6:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080D3564
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080D3AB2:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start func_080D3AB8
func_080D3AB8: @ 080D3AB8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3ADE
_080D3ACE:
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3AEE
	b _080D3B12
_080D3ADE:
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3B12
	b _080D3ACE
_080D3AEE:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080D3564
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D3B12
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080D358C
	movs r1, #0x00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3B0E
	movs r1, #0x01
_080D3B0E:
	adds r0, r1, #0x0
	b _080D3B14
_080D3B12:
	movs r0, #0x00
_080D3B14:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start task_allmap_cursor_0
task_allmap_cursor_0: @ 080D3B1C
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x30]
	ldrh r0, [r4, #0x30]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3BB0 @ =0x0203C540
	ldrh r0, [r0, #0x00]
	subs r0, #0x10
	subs r1, r1, r0
	movs r6, #0x00
	strh r1, [r4, #0x24]
	ldrh r0, [r4, #0x32]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3BB4 @ =0x0203C53C
	ldrh r0, [r0, #0x00]
	subs r0, #0x0B
	subs r1, r1, r0
	strh r1, [r4, #0x26]
	movs r1, #0x26
	ldsh r0, [r4, r1]
	negs r0, r0
	lsls r0, r0, #0x08
	str r0, [r4, #0x28]
	movs r1, #0x26
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x2C]
	movs r1, #0x24
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x3C]
	str r0, [r4, #0x34]
	movs r1, #0x26
	ldsh r0, [r4, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x40]
	str r0, [r4, #0x38]
	ldr r0, _080D3BB8 @ =0x0976D7C0
	movs r1, #0xC0
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D3BBC @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	adds r5, r4, #0x0
	adds r5, #0x0C
	ldr r1, _080D3BC0 @ =0x09EF64C4
	ldr r2, _080D3BC4 @ =0x09EF64B4
	adds r0, r5, #0x0
	bl func_08005968
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r5, #0x0
	bl func_08005AFC
	str r0, [r4, #0x08]
	adds r4, #0x44
	strh r6, [r4, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3BB0: .4byte 0x0203C540
_080D3BB4: .4byte 0x0203C53C
_080D3BB8: .4byte 0x0976D7C0
_080D3BBC: .4byte 0x0984A1D8
_080D3BC0: .4byte 0x09EF64C4
_080D3BC4: .4byte 0x09EF64B4
	thumb_func_start task_allmap_cursor_1
task_allmap_cursor_1: @ 080D3BC8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _080D3BF0 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080D3C24
	ldr r3, _080D3BF4 @ =0x0203C508
	ldrh r2, [r3, #0x00]
	adds r0, r2, #0x0
	cmp r0, #0x06
	bls _080D3BF8
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r4, #0x2C]
	subs r2, #0x07
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_080058FC
	b _080D3C24
_080D3BF0: .4byte 0x0203C4E0
_080D3BF4: .4byte 0x0203C508
_080D3BF8:
	cmp r0, #0x03
	bls _080D3C18
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r4, #0x2C]
	ldr r3, _080D3C14 @ =0xFFFFF800
	adds r1, r1, r3
	subs r2, #0x03
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_0800592C
	b _080D3C24
	.byte 0x00, 0x00
_080D3C14: .4byte 0xFFFFF800
_080D3C18:
	adds r0, r4, #0x0
	adds r0, #0x28
	ldr r1, [r4, #0x2C]
	ldrh r2, [r3, #0x00]
	bl func_0800592C
_080D3C24:
	ldr r0, _080D3C34 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	beq _080D3C3C
	ldr r0, _080D3C38 @ =0x09EF64B4
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x08]
	b _080D3CB0
_080D3C34: .4byte 0x0203C4E0
_080D3C38: .4byte 0x09EF64B4
_080D3C3C:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	ldrh r0, [r4, #0x30]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3CB8 @ =0x0203C540
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x10
	subs r1, r1, r0
	lsls r2, r1, #0x08
	ldrh r0, [r4, #0x32]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D3CBC @ =0x0203C53C
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, #0x0B
	subs r1, r1, r0
	lsls r1, r1, #0x08
	ldr r0, [r4, #0x34]
	cmp r2, r0
	bne _080D3C7E
	ldr r0, [r4, #0x38]
	adds r5, r4, #0x0
	adds r5, #0x44
	cmp r1, r0
	beq _080D3C8C
_080D3C7E:
	str r2, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0x0
	adds r1, #0x44
	movs r0, #0x04
	strh r0, [r1, #0x00]
	adds r5, r1, #0x0
_080D3C8C:
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D3CB0
	adds r0, r4, #0x0
	adds r0, #0x3C
	ldr r1, [r4, #0x34]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x40
	ldr r1, [r4, #0x38]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
_080D3CB0:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
_080D3CB8: .4byte 0x0203C540
_080D3CBC: .4byte 0x0203C53C
	thumb_func_start task_allmap_cursor_2
task_allmap_cursor_2: @ 080D3CC0
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_080D4D1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3D16
	ldr r0, _080D3CE0 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	beq _080D3CE4
	ldrh r2, [r4, #0x24]
	ldr r0, [r4, #0x28]
	b _080D3CEC
	.byte 0x00, 0x00
_080D3CE0: .4byte 0x0203C4E0
_080D3CE4:
	ldr r0, [r4, #0x3C]
	lsls r0, r0, #0x08
	lsrs r2, r0, #0x10
	ldr r0, [r4, #0x40]
_080D3CEC:
	lsls r0, r0, #0x08
	lsrs r1, r0, #0x10
	lsls r0, r2, #0x10
	ldr r2, _080D3D20 @ =0xFFF10000
	adds r0, r0, r2
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	ldr r2, _080D3D24 @ =0xFFEA0000
	adds r1, r1, r2
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x31
	str r4, [sp, #0x00C]
	bl func_080023E0
_080D3D16:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3D20: .4byte 0xFFF10000
_080D3D24: .4byte 0xFFEA0000
	thumb_func_start task_allmap_cursor_3
task_allmap_cursor_3: @ 080D3D28
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
	thumb_func_start func_080D3D40
func_080D3D40: @ 080D3D40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x78
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r1, #0x00
	bge _080D3D58
	movs r0, #0x00
_080D3D58:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	mov r6, r8
	cmp r6, #0x00
	bge _080D3D66
	adds r6, #0x07
_080D3D66:
	asrs r6, r6, #0x03
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x02
	bl func_0800514C
	adds r7, r0, #0x0
	adds r1, r7, #0x0
	adds r1, #0x1C
	lsls r4, r4, #0x10
	asrs r4, r4, #0x0F
	ldr r5, _080D3DC8 @ =0x0983B7B4
	subs r5, r5, r4
	adds r0, r5, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r1, r7, #0x0
	adds r1, #0x5C
	adds r5, #0x40
	adds r0, r5, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r1, r7, #0x0
	adds r1, #0x9C
	adds r5, #0x40
	adds r0, r5, #0x0
	movs r2, #0x20
	bl func_080043B4
	lsls r6, r6, #0x03
	mov r0, r8
	subs r6, r0, r6
	lsls r6, r6, #0x10
	asrs r0, r6, #0x10
	lsrs r6, r6, #0x1F
	adds r0, r0, r6
	asrs r0, r0, #0x01
	mov r1, r8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D3DC8: .4byte 0x0983B7B4
_080D3DCC:
	.byte 0x00, 0xB5, 0x00, 0x06, 0x00, 0x0E, 0xC4, 0xF7, 0xF5, 0xFC, 0x00, 0x06, 0x00, 0x0E, 0x04, 0x28
	.byte 0x16, 0xD8, 0x80, 0x00, 0x01, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0xEC, 0x3D, 0x0D, 0x08
	.byte 0x0C, 0x3E, 0x0D, 0x08, 0x00, 0x3E, 0x0D, 0x08, 0x04, 0x3E, 0x0D, 0x08, 0x0C, 0x3E, 0x0D, 0x08
	.byte 0x08, 0x3E, 0x0D, 0x08, 0x40, 0x20, 0x04, 0xE0, 0x60, 0x20, 0x02, 0xE0, 0x00, 0x20, 0x00, 0xE0
	.byte 0x20, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	thumb_func_start task_allmap_roomname_0
task_allmap_roomname_0: @ 080D3E14
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r1, #0x18
	bl func_08065ACC
	ldrb r0, [r4, #0x00]
	bl func_08093C18
	adds r1, r5, #0x0
	bl func_08065B6C
	adds r6, r5, #0x0
	adds r6, #0xCC
	strb r0, [r6, #0x00]
	ldrb r0, [r4, #0x00]
	bl _080D3DCC
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080D3E78 @ =0x0984A1F8
	adds r0, r4, r0
	movs r1, #0x20
	bl func_08002A14
	adds r1, r5, #0x0
	adds r1, #0xC8
	str r0, [r1, #0x00]
	ldr r0, _080D3E7C @ =0x0984A078
	adds r4, r4, r0
	ldr r1, _080D3E80 @ =0x05000160
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_08005BE8
	ldrb r1, [r6, #0x00]
	adds r0, r5, #0x0
	bl func_08065B08
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080D3D40
	adds r5, #0xCE
	strh r0, [r5, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3E78: .4byte 0x0984A1F8
_080D3E7C: .4byte 0x0984A078
_080D3E80: .4byte 0x05000160
	thumb_func_start task_allmap_roomname_1
task_allmap_roomname_1: @ 080D3E84
	movs r0, #0x01
	bx lr
	thumb_func_start task_allmap_roomname_2
task_allmap_roomname_2: @ 080D3E88
	push {lr}
	add sp, #-0x008
	adds r2, r0, #0x0
	adds r0, #0xCE
	ldrh r0, [r0, #0x00]
	adds r0, #0x75
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, #0x0
	adds r1, #0xC8
	ldr r3, [r1, #0x00]
	movs r1, #0x32
	str r1, [sp, #0x000]
	adds r1, r2, #0x0
	adds r1, #0xCC
	ldrb r1, [r1, #0x00]
	str r1, [sp, #0x004]
	movs r1, #0x03
	bl func_080664D8
	add sp, #0x008
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_allmap_roomname_3
task_allmap_roomname_3: @ 080D3EB8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x18
	bl func_08065AE0
	adds r4, #0xC8
	ldr r0, [r4, #0x00]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start func_080D3ED0
func_080D3ED0: @ 080D3ED0
	push {r4, r5, lr}
	movs r0, #0x02
	bl func_0800514C
	adds r5, r0, #0x0
	adds r1, r5, #0x0
	adds r1, #0x1C
	ldr r4, _080D3F0C @ =0x08125E24
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r1, r5, #0x0
	adds r1, #0x5C
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r1, r5, #0x0
	adds r1, #0x9C
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3F0C: .4byte 0x08125E24
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x2C, 0x30, 0x01, 0x21, 0x01, 0x70, 0xA0, 0x6A, 0x00, 0x28, 0x01, 0xD1
	.byte 0x04, 0x20, 0x00, 0xE0, 0x03, 0x20, 0xA0, 0x62, 0xA0, 0x89, 0x00, 0x28, 0x01, 0xD1, 0x10, 0x20
	.byte 0xA0, 0x81, 0x08, 0x49, 0xA0, 0x22, 0xD2, 0x00, 0x03, 0x20, 0x31, 0xF7, 0xE7, 0xF8, 0x06, 0x48
	.byte 0x60, 0x61, 0xA0, 0x20, 0x00, 0x02, 0xE0, 0x61, 0x04, 0x48, 0x60, 0x62, 0x10, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x98, 0xAD, 0x83, 0x09, 0x00, 0xF8, 0xFF, 0xFF, 0x00, 0x80, 0xFF, 0xFF
	thumb_func_start task_allmap_bar_0
task_allmap_bar_0: @ 080D3F60
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _080D3FBC @ =0x0203C460
	str r4, [r0, #0x00]
	ldr r0, _080D3FC0 @ =0x0976D8A6
	movs r1, #0xB0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D3FC4 @ =0x0976DBDA
	movs r1, #0xC0
	bl func_080026A4
	str r0, [r4, #0x04]
	ldr r0, _080D3FC8 @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	movs r2, #0x00
	movs r1, #0x00
	movs r0, #0x10
	strh r0, [r4, #0x0C]
	str r1, [r4, #0x28]
	ldr r0, _080D3FCC @ =0xFFFFF800
	str r0, [r4, #0x10]
	movs r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r4, #0x18]
	ldr r0, _080D3FD0 @ =0xFFFF8000
	str r0, [r4, #0x20]
	str r1, [r4, #0x14]
	movs r0, #0x98
	lsls r0, r0, #0x08
	str r0, [r4, #0x1C]
	str r1, [r4, #0x24]
	adds r0, r4, #0x0
	adds r0, #0x2C
	strb r2, [r0, #0x00]
	adds r4, #0x2D
	strb r2, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3FBC: .4byte 0x0203C460
_080D3FC0: .4byte 0x0976D8A6
_080D3FC4: .4byte 0x0976DBDA
_080D3FC8: .4byte 0x0984A1D8
_080D3FCC: .4byte 0xFFFFF800
_080D3FD0: .4byte 0xFFFF8000
	thumb_func_start func_080D3FD4
func_080D3FD4: @ 080D3FD4
	push {lr}
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006184
	bl func_080063A8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_allmap_bar_1
task_allmap_bar_1: @ 080D3FE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	ldr r0, [r5, #0x28]
	cmp r0, #0x04
	bls _080D3FF8
	b _080D4180
_080D3FF8:
	lsls r0, r0, #0x02
	ldr r1, _080D4004 @ =0x080D4008
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
	.byte 0x00, 0x00
_080D4004: .4byte 0x080D4008
	.byte 0x1C, 0x40, 0x0D, 0x08, 0x4C, 0x40, 0x0D, 0x08, 0x10, 0x41, 0x0D, 0x08, 0x84, 0x40, 0x0D, 0x08
	.byte 0xA6, 0x40, 0x0D, 0x08, 0x28, 0x1C, 0x10, 0x30, 0x69, 0x69, 0xAA, 0x89, 0x31, 0xF7, 0x6A, 0xFC
	.byte 0x28, 0x1C, 0x18, 0x30, 0xE9, 0x69, 0xAA, 0x89, 0x31, 0xF7, 0x64, 0xFC, 0xA8, 0x89, 0x01, 0x38
	.byte 0xA8, 0x81, 0x00, 0x04, 0x00, 0x28, 0x00, 0xD0, 0x9E, 0xE0, 0x10, 0x20, 0xA8, 0x81, 0x01, 0x20
	.byte 0xA8, 0x62, 0x99, 0xE0, 0x28, 0x1C, 0x20, 0x30, 0x69, 0x6A, 0xAA, 0x89, 0x31, 0xF7, 0x52, 0xFC
	.byte 0xA8, 0x89, 0x01, 0x38, 0xA8, 0x81, 0x00, 0x04, 0x00, 0x28, 0x00, 0xD0, 0x8C, 0xE0, 0x05, 0x49
	.byte 0xA0, 0x22, 0xD2, 0x00, 0x03, 0x20, 0x31, 0xF7, 0x4D, 0xF8, 0x02, 0x21, 0xA9, 0x62, 0x02, 0x48
	.byte 0x01, 0x60, 0x81, 0xE0, 0x98, 0xB2, 0x83, 0x09, 0xE0, 0xC4, 0x03, 0x02, 0x28, 0x1C, 0x20, 0x30
	.byte 0x69, 0x6A, 0xAA, 0x89, 0x31, 0xF7, 0x36, 0xFC, 0xA8, 0x89, 0x01, 0x38, 0xA8, 0x81, 0x00, 0x04
	.byte 0x00, 0x28, 0x71, 0xD1, 0x10, 0x20, 0xA8, 0x81, 0x04, 0x20, 0xA8, 0x62, 0x6C, 0xE0, 0x32, 0xF7
	.byte 0x35, 0xF9, 0x00, 0x06, 0x2F, 0x1C, 0x10, 0x37, 0x18, 0x21, 0x49, 0x19, 0x88, 0x46, 0x00, 0x28
	.byte 0x13, 0xD1, 0x28, 0x1C, 0x2D, 0x30, 0x01, 0x78, 0x06, 0x1C, 0x00, 0x29, 0x0D, 0xD1, 0x00, 0x24
	.byte 0x20, 0x04, 0x00, 0x0C, 0x00, 0x21, 0x32, 0xF7, 0x11, 0xF9, 0x01, 0x34, 0x1F, 0x2C, 0xF7, 0xDD
	.byte 0x28, 0x1C, 0xFF, 0xF7, 0x7B, 0xFF, 0x01, 0x20, 0x30, 0x70, 0x69, 0x69, 0xAA, 0x89, 0x38, 0x1C
	.byte 0x31, 0xF7, 0x08, 0xFC, 0xE9, 0x69, 0xAA, 0x89, 0x40, 0x46, 0x31, 0xF7, 0x03, 0xFC, 0xA8, 0x89
	.byte 0x01, 0x38, 0xA8, 0x81, 0x00, 0x04, 0x01, 0x0C, 0x00, 0x29, 0x3D, 0xD1, 0x01, 0x48, 0x01, 0x60
	.byte 0x00, 0x20, 0x3A, 0xE0, 0xE0, 0xC4, 0x03, 0x02, 0x28, 0x1C, 0x2C, 0x30, 0x04, 0x78, 0x00, 0x2C
	.byte 0x32, 0xD1, 0x0C, 0x4E, 0x30, 0x68, 0x03, 0x28, 0x2E, 0xD1, 0x2D, 0xF7, 0x35, 0xF9, 0x08, 0x21
	.byte 0x01, 0x40, 0x00, 0x29, 0x10, 0xD0, 0x68, 0x20, 0x4B, 0xF0, 0x9E, 0xFE, 0x28, 0x1C, 0xFF, 0xF7
	.byte 0x4D, 0xFF, 0x34, 0x60, 0xFF, 0xF7, 0xC8, 0xFE, 0x00, 0x20, 0xFF, 0xF7, 0xF3, 0xF9, 0x00, 0x20
	.byte 0x1B, 0xE0, 0x00, 0x00, 0xE0, 0xC4, 0x03, 0x02, 0x2D, 0xF7, 0x1E, 0xF9, 0x02, 0x21, 0x01, 0x40
	.byte 0x00, 0x29, 0x11, 0xD0, 0x00, 0xF0, 0xDE, 0xFD, 0x00, 0x06, 0x00, 0x28, 0x0C, 0xD1, 0x68, 0x20
	.byte 0x4B, 0xF0, 0x82, 0xFE, 0x28, 0x1C, 0xFF, 0xF7, 0xCF, 0xFE, 0x01, 0x20, 0x30, 0x60, 0xFF, 0xF7
	.byte 0xAB, 0xFE, 0x01, 0x20, 0xFF, 0xF7, 0xD6, 0xF9
_080D4180:
	movs r0, #0x01
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_start task_allmap_bar_2
task_allmap_bar_2: @ 080D418C
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r0, [r6, #0x28]
	cmp r0, #0x02
	beq _080D41F4
	ldr r0, [r6, #0x20]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r2, _080D41FC @ =0x0976D880
	ldr r3, [r6, #0x00]
	ldr r1, [r6, #0x08]
	str r1, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	movs r1, #0xFA
	lsls r1, r1, #0x02
	str r1, [sp, #0x00C]
	movs r1, #0x00
	bl func_080023E0
	ldr r1, [r6, #0x10]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080D4200 @ =0x0976DB68
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _080D4204 @ =0x000003E9
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl func_080023E0
	ldr r1, [r6, #0x18]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _080D4208 @ =0x0976DB9C
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r0, _080D420C @ =0x000003EA
	str r0, [sp, #0x00C]
	movs r0, #0x80
	bl func_080023E0
_080D41F4:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D41FC: .4byte 0x0976D880
_080D4200: .4byte 0x0976DB68
_080D4204: .4byte 0x000003E9
_080D4208: .4byte 0x0976DB9C
_080D420C: .4byte 0x000003EA
	thumb_func_start task_allmap_bar_3
task_allmap_bar_3: @ 080D4210
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_080028C0
	ldr r0, [r4, #0x08]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_start func_080D422C
func_080D422C: @ 080D422C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0x00
	mov r10, r0
	ldr r2, _080D4290 @ =0x096FDC30
	mov r9, r2
_080D4240:
	mov r3, r10
	lsls r7, r3, #0x02
	mov r0, r9
	ldrh r1, [r0, #0x00]
	add r1, r8
	lsls r1, r1, #0x10
	mov r2, r8
	lsrs r0, r2, #0x10
	mov r3, r9
	ldrh r3, [r3, #0x02]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r5, r1, #0x10
	orrs r5, r0
	adds r0, r5, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r4, #0x0
	cmp r4, #0xFF
	beq _080D42B4
	mov r0, r8
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4298
	ldr r0, _080D4294 @ =0x096FDC40
	adds r0, r7, r0
	ldrb r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl func_080D3AB8
	b _080D42A4
_080D4290: .4byte 0x096FDC30
_080D4294: .4byte 0x096FDC40
_080D4298:
	ldr r0, _080D42B0 @ =0x096FDC40
	adds r0, r7, r0
	ldrb r1, [r0, #0x00]
	adds r0, r6, #0x0
	bl func_080D3A70
_080D42A4:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080D42B4
	movs r0, #0x01
	b _080D42C4
_080D42B0: .4byte 0x096FDC40
_080D42B4:
	movs r0, #0x04
	add r9, r0
	movs r2, #0x01
	add r10, r2
	mov r3, r10
	cmp r3, #0x03
	ble _080D4240
	movs r0, #0x00
_080D42C4:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start func_080D42D4
func_080D42D4: @ 080D42D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r7, r0, #0x0
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r1, #0x00
	str r1, [sp, #0x000]
	mov r9, r1
	ldr r2, _080D43DC @ =0x096FDC30
	mov r10, r2
_080D42F6:
	mov r0, r10
	ldrh r1, [r0, #0x00]
	ldrh r2, [r7, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldrh r0, [r0, #0x02]
	ldrh r2, [r7, #0x02]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	orrs r1, r0
	mov r8, r1
	mov r0, r8
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xFF
	beq _080D43F4
	ldr r0, _080D43E0 @ =0x096FDC40
	add r0, r9
	ldrb r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl func_080D3A70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D43F4
	adds r0, r4, #0x0
	bl func_080DF548
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0A
	bne _080D4342
	movs r0, #0x00
_080D4342:
	bl func_080986FC
	movs r1, #0x34
	ldr r2, [sp, #0x000]
	adds r5, r2, #0x0
	muls r5, r1
	adds r1, r7, #0x0
	adds r1, #0x1C
	adds r1, r1, r5
	str r0, [r1, #0x00]
	ldr r0, _080D43E4 @ =0x09618D38
	movs r1, #0x20
	bl func_08002A14
	adds r6, r7, #0x0
	adds r6, #0x28
	adds r6, r6, r5
	str r0, [r6, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x34
	adds r0, r0, r5
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r0, _080D43E8 @ =0x0905E3BA
	movs r1, #0xC0
	lsls r1, r1, #0x03
	bl func_080026A4
	adds r1, r7, #0x0
	adds r1, #0x20
	adds r1, r1, r5
	str r0, [r1, #0x00]
	ldr r0, _080D43E4 @ =0x09618D38
	movs r1, #0x20
	bl func_08002A14
	adds r4, r7, #0x0
	adds r4, #0x2C
	adds r4, r4, r5
	str r0, [r4, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x38
	adds r1, r1, r5
	ldr r0, _080D43EC @ =0x09EE97F4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r6, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r1, r7, #0x0
	adds r1, #0x08
	add r1, r9
	ldr r0, _080D43F0 @ =0x09EF64E8
	add r0, r9
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r1, r7, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	b _080D43FE
	.byte 0x00, 0x00
_080D43DC: .4byte 0x096FDC30
_080D43E0: .4byte 0x096FDC40
_080D43E4: .4byte 0x09618D38
_080D43E8: .4byte 0x0905E3BA
_080D43EC: .4byte 0x09EE97F4
_080D43F0: .4byte 0x09EF64E8
_080D43F4:
	adds r0, r7, #0x0
	adds r0, #0x08
	add r0, r9
	movs r1, #0x00
	str r1, [r0, #0x00]
_080D43FE:
	movs r1, #0x04
	add r9, r1
	add r10, r1
	ldr r2, [sp, #0x000]
	adds r2, #0x01
	str r2, [sp, #0x000]
	cmp r2, #0x03
	bgt _080D4410
	b _080D42F6
_080D4410:
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D447A
	ldr r0, _080D448C @ =0x0976DD62
	movs r1, #0x80
	bl func_080026A4
	str r0, [r7, #0x18]
	ldr r0, _080D4490 @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	adds r1, r7, #0x0
	adds r1, #0xEC
	str r0, [r1, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _080D4494 @ =0x0976B340
	movs r1, #0x90
	lsls r1, r1, #0x06
	bl func_080026A4
	adds r1, r7, #0x0
	adds r1, #0xF0
	str r0, [r1, #0x00]
	adds r1, #0x08
	ldr r0, _080D4498 @ =0x09EF6424
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r4, r7, #0x0
	adds r4, #0xF4
	ldr r0, [r4, #0x00]
	ldr r2, _080D449C @ =0x0984A0F8
	movs r1, #0x0F
	movs r3, #0x20
	bl func_0800388C
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D447A:
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D448C: .4byte 0x0976DD62
_080D4490: .4byte 0x0984A1D8
_080D4494: .4byte 0x0976B340
_080D4498: .4byte 0x09EF6424
_080D449C: .4byte 0x0984A0F8
	thumb_func_start func_080D44A0
func_080D44A0: @ 080D44A0
	push {r4, r5, lr}
	add sp, #-0x020
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, _080D44D0 @ =0x096FDC50
	mov r0, sp
	movs r2, #0x20
	bl _0811F030
	lsls r5, r5, #0x01
	subs r4, #0x01
	lsls r4, r4, #0x03
	adds r5, r5, r4
	mov r1, sp
	adds r0, r1, r5
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	add sp, #0x020
	pop {r4, r5}
	pop {r1}
	bx r1
_080D44D0: .4byte 0x096FDC50
	thumb_func_start func_080D44D4
func_080D44D4: @ 080D44D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	movs r7, #0x00
	ldr r5, _080D4534 @ =0x096FDC30
_080D44E6:
	lsls r0, r7, #0x02
	mov r8, r0
	ldrh r1, [r5, #0x00]
	ldrh r2, [r6, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldrh r0, [r5, #0x02]
	ldrh r2, [r6, #0x02]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r1, #0x10
	orrs r4, r0
	adds r0, r4, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xFF
	beq _080D451E
	ldr r0, _080D4538 @ =0x096FDC40
	add r0, r8
	ldrb r1, [r0, #0x00]
	adds r0, r2, #0x0
	bl func_080D3AB8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4526
_080D451E:
	adds r5, #0x04
	adds r7, #0x01
	cmp r7, #0x03
	ble _080D44E6
_080D4526:
	cmp r7, #0x04
	bne _080D453C
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x00
	b _080D4558
_080D4534: .4byte 0x096FDC30
_080D4538: .4byte 0x096FDC40
_080D453C:
	ldrb r0, [r6, #0x04]
	ldr r2, _080D464C @ =0x096FDC40
	lsls r1, r7, #0x02
	adds r1, r1, r2
	ldrb r1, [r1, #0x00]
	bl func_080E8C84
	bl func_080E8D00
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r1, r6, r2
_080D4558:
	strh r0, [r1, #0x00]
	movs r7, #0x00
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r6, r1
	adds r2, r6, #0x0
	adds r2, #0xF0
	str r2, [sp, #0x000]
	movs r1, #0xF8
	adds r1, r1, r6
	mov r10, r1
	movs r2, #0xF4
	adds r2, r2, r6
	mov r9, r2
	ldrh r0, [r0, #0x00]
	cmp r7, r0
	bge _080D460A
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r8, r0
_080D4582:
	movs r0, #0x34
	adds r5, r7, #0x0
	muls r5, r0
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r4, r6, r4
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl func_080E8D1C
	adds r1, r0, #0x0
	adds r0, r4, #0x0
	bl func_08098014
	mov r1, r8
	ldrh r0, [r1, #0x00]
	adds r1, r7, #0x0
	bl func_080D44A0
	movs r1, #0xD0
	lsls r1, r1, #0x07
	adds r2, r4, #0x0
	bl func_08098598
	adds r0, r6, #0x0
	adds r0, #0x28
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D45CC
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D45CC:
	adds r0, r6, #0x0
	adds r0, #0x2C
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D45E6
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D45E6:
	adds r0, r6, #0x0
	adds r0, #0x30
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D4600
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
_080D4600:
	adds r7, #0x01
	mov r2, r8
	ldrh r2, [r2, #0x00]
	cmp r7, r2
	blt _080D4582
_080D460A:
	ldr r0, _080D4650 @ =0x0976B340
	movs r1, #0x90
	lsls r1, r1, #0x06
	bl func_080026A4
	ldr r1, [sp, #0x000]
	str r0, [r1, #0x00]
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4634
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bne _080D465C
_080D4634:
	ldr r0, _080D4654 @ =0x09EF6424
	ldr r0, [r0, #0x04]
	mov r2, r10
	str r0, [r2, #0x00]
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r2, _080D4658 @ =0x0984A118
	movs r1, #0x0F
	movs r3, #0x20
	bl func_0800388C
	b _080D4672
_080D464C: .4byte 0x096FDC40
_080D4650: .4byte 0x0976B340
_080D4654: .4byte 0x09EF6424
_080D4658: .4byte 0x0984A118
_080D465C:
	ldr r0, _080D4694 @ =0x09EF6424
	ldr r0, [r0, #0x00]
	mov r2, r10
	str r0, [r2, #0x00]
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r2, _080D4698 @ =0x0984A0F8
	movs r1, #0x0F
	movs r3, #0x20
	bl func_0800388C
_080D4672:
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D4694: .4byte 0x09EF6424
_080D4698: .4byte 0x0984A0F8
	thumb_func_start task_allmap_doorinfo_0
task_allmap_doorinfo_0: @ 080D469C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	movs r4, #0x00
_080D46A4:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	adds r4, #0x01
	cmp r4, #0x1F
	ble _080D46A4
	movs r0, #0x28
	bl func_08000918
	adds r1, r6, #0x0
	adds r1, #0xF4
	str r0, [r1, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r6, #0x00]
	bl func_080D5494
	strb r0, [r6, #0x04]
	ldrh r1, [r6, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D473C @ =0x0203C540
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	adds r5, r6, #0x0
	adds r5, #0xFC
	strh r0, [r5, #0x00]
	ldrh r1, [r6, #0x02]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D4740 @ =0x0203C53C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	adds r4, r6, #0x0
	adds r4, #0xFE
	strh r0, [r4, #0x00]
	movs r0, #0x86
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xD0
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4728
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	beq _080D4728
	ldrb r0, [r6, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4744
_080D4728:
	movs r3, #0x88
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r0, #0x84
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	bl func_080D44D4
	b _080D4756
_080D473C: .4byte 0x0203C540
_080D4740: .4byte 0x0203C53C
_080D4744:
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x84
	lsls r0, r0, #0x07
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	bl func_080D42D4
_080D4756:
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r1, r6, r3
	movs r2, #0x00
	movs r0, #0x08
	strh r0, [r1, #0x00]
	adds r0, #0xFC
	adds r1, r6, r0
	movs r3, #0x00
	ldsh r0, [r5, r3]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r0, #0x84
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r3, #0x00
	ldsh r0, [r4, r3]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r1, #0x8B
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x0E
	movs r2, #0x08
	bl func_08006238
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_start task_allmap_doorinfo_1
task_allmap_doorinfo_1: @ 080D4794
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_08001390
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D47F4
	movs r0, #0x8B
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080D47F4
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0x68
	bl func_0811FE70
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r2, r4, r1
	ldrh r1, [r2, #0x00]
	movs r0, #0x08
	subs r0, r0, r1
	strh r0, [r2, #0x00]
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r1, r4, r2
	adds r0, r4, #0x0
	adds r0, #0xFC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r4, #0x0
	adds r0, #0xFE
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x08
	bl func_080061E8
_080D47F4:
	movs r0, #0x80
	lsls r0, r0, #0x01
	adds r5, r4, r0
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D482E
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x86
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	ldrh r2, [r5, #0x00]
	bl func_080058FC
	ldrh r0, [r5, #0x00]
	subs r0, #0x01
	strh r0, [r5, #0x00]
_080D482E:
	movs r1, #0x8B
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D4844
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080D4844
	movs r0, #0x00
	b _080D4846
_080D4844:
	movs r0, #0x01
_080D4846:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start func_080D484C
func_080D484C: @ 080D484C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	adds r6, r0, #0x0
	ldr r0, _080D49DC @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D4864
	b _080D49CA
_080D4864:
	movs r0, #0x00
	mov r8, r0
	adds r1, r6, #0x0
	adds r1, #0x08
	str r1, [sp, #0x018]
	adds r2, r6, #0x0
	adds r2, #0xF8
	str r2, [sp, #0x01C]
	adds r3, r6, #0x0
	adds r3, #0xF0
	str r3, [sp, #0x010]
	adds r4, r6, #0x0
	adds r4, #0xF4
	str r4, [sp, #0x014]
	movs r5, #0x82
	lsls r5, r5, #0x01
	adds r5, r5, r6
	mov r10, r5
	movs r0, #0x84
	lsls r0, r0, #0x01
	adds r0, r0, r6
	mov r9, r0
	ldr r1, _080D49E0 @ =0x096FDC10
	str r1, [sp, #0x020]
_080D4894:
	mov r2, r8
	lsls r0, r2, #0x02
	ldr r3, [sp, #0x018]
	adds r0, r3, r0
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	beq _080D4984
	movs r5, #0x80
	lsls r5, r5, #0x01
	adds r0, r6, r5
	ldrh r7, [r0, #0x00]
	cmp r7, #0x00
	bne _080D4984
	mov r1, r10
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	mov r2, r9
	ldr r1, [r2, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, [r6, #0x18]
	adds r2, r6, #0x0
	adds r2, #0xEC
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r2, r8
	adds r2, #0x33
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r4, #0x0
	bl func_080023E0
	ldr r3, [sp, #0x020]
	movs r4, #0x00
	ldsh r0, [r3, r4]
	ldr r5, _080D49E4 @ =0x02034E84
	str r0, [r5, #0x00]
	movs r2, #0x02
	ldsh r1, [r3, r2]
	ldr r3, _080D49E8 @ =0x02034E88
	str r1, [r3, #0x00]
	mov r4, r10
	ldr r2, [r4, #0x00]
	asrs r2, r2, #0x08
	adds r0, r0, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r5, r9
	ldr r2, [r5, #0x00]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x34
	mov r5, r8
	muls r5, r2
	adds r2, r6, #0x0
	adds r2, #0x34
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	adds r3, r6, #0x0
	adds r3, #0x1C
	adds r3, r3, r5
	ldr r3, [r3, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x28
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r4, r8
	adds r4, #0x28
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	mov r0, r10
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	ldr r2, _080D49E4 @ =0x02034E84
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r3, r9
	ldr r2, [r3, #0x00]
	asrs r2, r2, #0x08
	ldr r4, _080D49E8 @ =0x02034E88
	ldr r1, [r4, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r6, #0x0
	adds r2, #0x38
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	adds r3, r6, #0x0
	adds r3, #0x20
	adds r3, r3, r5
	ldr r3, [r3, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x2C
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r4, r8
	adds r4, #0x1E
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
_080D4984:
	ldr r5, [sp, #0x020]
	adds r5, #0x04
	str r5, [sp, #0x020]
	movs r0, #0x01
	add r8, r0
	mov r1, r8
	cmp r1, #0x03
	bgt _080D4996
	b _080D4894
_080D4996:
	movs r2, #0x82
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	movs r3, #0x84
	lsls r3, r3, #0x01
	adds r1, r6, r3
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r4, [sp, #0x01C]
	ldr r2, [r4, #0x00]
	ldr r5, [sp, #0x010]
	ldr r3, [r5, #0x00]
	ldr r5, [sp, #0x014]
	ldr r4, [r5, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x14
	str r4, [sp, #0x00C]
	bl func_080023E0
_080D49CA:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D49DC: .4byte 0x0203C4E0
_080D49E0: .4byte 0x096FDC10
_080D49E4: .4byte 0x02034E84
_080D49E8: .4byte 0x02034E88
	thumb_func_start func_080D49EC
func_080D49EC: @ 080D49EC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D4A24
	movs r6, #0x00
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bge _080D4A24
	adds r4, r5, #0x0
	adds r4, #0x1C
	adds r7, r5, r2
_080D4A12:
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08098670
	adds r4, #0x34
	adds r6, #0x01
	ldrh r0, [r7, #0x00]
	cmp r6, r0
	blt _080D4A12
_080D4A24:
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	movs r2, #0x84
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	adds r2, r5, #0x0
	adds r2, #0xF8
	ldr r2, [r2, #0x00]
	adds r3, r5, #0x0
	adds r3, #0xF0
	ldr r3, [r3, #0x00]
	adds r4, r5, #0x0
	adds r4, #0xF4
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x14
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_allmap_doorinfo_2
task_allmap_doorinfo_2: @ 080D4A68
	push {r4, lr}
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4A96
	ldrb r0, [r4, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	beq _080D4A96
	ldrb r0, [r4, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4A9E
_080D4A96:
	adds r0, r4, #0x0
	bl func_080D49EC
	b _080D4AA4
_080D4A9E:
	adds r0, r4, #0x0
	bl func_080D484C
_080D4AA4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_allmap_doorinfo_3
task_allmap_doorinfo_3: @ 080D4AAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	movs r1, #0x8B
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D4AC8
	movs r0, #0x00
	movs r1, #0x08
	bl func_080061E8
_080D4AC8:
	adds r0, r5, #0x0
	adds r0, #0xF0
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldrb r0, [r5, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4AFC
	ldrb r0, [r5, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	beq _080D4AFC
	ldrb r0, [r5, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4B2C
_080D4AFC:
	movs r6, #0x00
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0xF4
	adds r1, r1, r5
	mov r8, r1
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bge _080D4B8C
	adds r4, r5, #0x0
	adds r4, #0x1C
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r5, r5, r0
_080D4B1A:
	adds r0, r4, #0x0
	bl func_08098778
	adds r4, #0x34
	adds r6, #0x01
	ldrh r1, [r5, #0x00]
	cmp r6, r1
	blt _080D4B1A
	b _080D4B8C
_080D4B2C:
	ldr r0, [r5, #0x18]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0xEC
	ldr r0, [r0, #0x00]
	bl func_08002C10
	movs r6, #0x00
	movs r0, #0xF4
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0x0
	adds r7, #0x08
_080D4B48:
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	beq _080D4B84
	movs r0, #0x34
	adds r4, r6, #0x0
	muls r4, r0
	adds r0, r5, #0x0
	adds r0, #0x1C
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0x28
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r0, r5, #0x0
	adds r0, #0x20
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08002C10
_080D4B84:
	adds r7, #0x04
	adds r6, #0x01
	cmp r6, #0x03
	ble _080D4B48
_080D4B8C:
	movs r6, #0x00
_080D4B8E:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r6, #0x01
	cmp r6, #0x1F
	ble _080D4B8E
	movs r0, #0x0A
	movs r1, #0x00
	bl func_080062F4
	mov r1, r8
	ldr r0, [r1, #0x00]
	bl func_080009C4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start task_allmap_pusha_0
task_allmap_pusha_0: @ 080D4BB8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _080D4C10 @ =0x0203C460
	str r4, [r0, #0x00]
	str r1, [r4, #0x0C]
	ldrh r2, [r1, #0x30]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	ldr r2, _080D4C14 @ =0x0203C540
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	movs r5, #0x00
	strh r0, [r4, #0x2C]
	ldrh r1, [r1, #0x32]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D4C18 @ =0x0203C53C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	strh r0, [r4, #0x2E]
	ldr r0, _080D4C1C @ =0x0976DCB0
	movs r1, #0x80
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080D4C20 @ =0x0984A1D8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r0, _080D4C24 @ =0x0976DC9C
	str r0, [r4, #0x08]
	strh r5, [r4, #0x10]
	adds r0, r4, #0x0
	adds r0, #0x14
	movs r1, #0x01
	bl func_08000E64
	str r5, [r4, #0x28]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D4C10: .4byte 0x0203C460
_080D4C14: .4byte 0x0203C540
_080D4C18: .4byte 0x0203C53C
_080D4C1C: .4byte 0x0976DCB0
_080D4C20: .4byte 0x0984A1D8
_080D4C24: .4byte 0x0976DC9C
	thumb_func_start task_allmap_pusha_1
task_allmap_pusha_1: @ 080D4C28
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D4D1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4C58
	bl func_08001390
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _080D4C58
	movs r0, #0x66
	bl func_0811FE70
	adds r0, r4, #0x0
	adds r0, #0x14
	ldr r1, _080D4C80 @ =0x09EF4E20
	ldr r2, [r4, #0x0C]
	adds r2, #0x30
	bl func_08000E14
	str r0, [r4, #0x28]
_080D4C58:
	ldr r2, _080D4C84 @ =0x08121400
	ldrh r1, [r4, #0x10]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x12]
	adds r1, #0x10
	strh r1, [r4, #0x10]
	adds r0, r4, #0x0
	adds r0, #0x14
	bl func_08000EA4
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D4C80: .4byte 0x09EF4E20
_080D4C84: .4byte 0x08121400
	thumb_func_start task_allmap_pusha_2
task_allmap_pusha_2: @ 080D4C88
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_080D4D1C
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080D4CA4
	adds r0, r4, #0x0
	adds r0, #0x14
	bl func_08000EE0
	b _080D4CE8
_080D4CA4:
	ldr r2, [r4, #0x0C]
	ldrh r1, [r2, #0x30]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D4CF0 @ =0x0203C540
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	strh r0, [r4, #0x2C]
	ldrh r0, [r2, #0x32]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D4CF4 @ =0x0203C53C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	strh r1, [r4, #0x2E]
	movs r2, #0x2C
	ldsh r0, [r4, r2]
	ldrh r2, [r4, #0x12]
	subs r1, r1, r2
	adds r1, #0x02
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r4, #0x30
	str r4, [sp, #0x00C]
	bl func_080023E0
_080D4CE8:
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
_080D4CF0: .4byte 0x0203C540
_080D4CF4: .4byte 0x0203C53C
	thumb_func_start task_allmap_pusha_3
task_allmap_pusha_3: @ 080D4CF8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	adds r4, #0x14
	adds r0, r4, #0x0
	bl func_08000F0C
	bl func_080D4D44
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start func_080D4D1C
func_080D4D1C: @ 080D4D1C
	push {lr}
	ldr r0, _080D4D38 @ =0x0203C460
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D4D32
	ldr r0, [r0, #0x28]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4D3C
_080D4D32:
	movs r0, #0x00
	b _080D4D3E
	.byte 0x00, 0x00
_080D4D38: .4byte 0x0203C460
_080D4D3C:
	movs r0, #0x01
_080D4D3E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start func_080D4D44
func_080D4D44: @ 080D4D44
	ldr r1, _080D4D4C @ =0x0203C460
	movs r0, #0x00
	str r0, [r1, #0x00]
	bx lr
_080D4D4C: .4byte 0x0203C460
	thumb_func_start func_080D4D50
func_080D4D50: @ 080D4D50
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r7, r2, #0x0
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r10, r3
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080D4D80
	ldr r0, _080D4D7C @ =0x0203C530
	b _080D4D82
	.byte 0x00, 0x00
_080D4D7C: .4byte 0x0203C530
_080D4D80:
	ldr r0, _080D4E14 @ =0x0203C504
_080D4D82:
	ldr r0, [r0, #0x00]
	mov r9, r0
	lsls r4, r2, #0x10
	asrs r0, r4, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D4E18 @ =0x0203C4B4
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xAC
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, r1, r0
	cmp r0, #0x00
	bge _080D4DA4
	adds r0, #0x07
_080D4DA4:
	lsls r0, r0, #0x0D
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r3, r5, #0x10
	asrs r1, r3, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r2, #0x0
	adds r1, #0xAE
	movs r2, #0x00
	ldsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0x00
	bge _080D4DC4
	adds r0, #0x07
_080D4DC4:
	lsls r0, r0, #0x0D
	lsrs r0, r0, #0x10
	mov r8, r0
	lsrs r6, r4, #0x10
	orrs r6, r3
	adds r0, r6, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r7, #0x14
	lsrs r4, r0, #0x10
	adds r0, r5, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4E04
	adds r0, r5, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4E04
	adds r0, r6, #0x0
	bl func_080D422C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D4E32
_080D4E04:
	mov r3, r10
	cmp r3, #0x00
	beq _080D4E1C
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r4, r1
	b _080D4E48
	.byte 0x00, 0x00
_080D4E14: .4byte 0x0203C504
_080D4E18: .4byte 0x0203C4B4
_080D4E1C:
	cmp r7, #0x01
	bne _080D4E26
	movs r2, #0x80
	lsls r2, r2, #0x05
	b _080D4E46
_080D4E26:
	cmp r7, #0x11
	bne _080D4E4C
	movs r3, #0xF0
	lsls r3, r3, #0x08
	adds r0, r4, r3
	b _080D4E48
_080D4E32:
	cmp r7, #0x01
	beq _080D4E3A
	cmp r7, #0x11
	bne _080D4E42
_080D4E3A:
	movs r1, #0xF0
	lsls r1, r1, #0x08
	adds r0, r4, r1
	b _080D4E48
_080D4E42:
	movs r2, #0xE0
	lsls r2, r2, #0x08
_080D4E46:
	adds r0, r4, r2
_080D4E48:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080D4E4C:
	movs r6, #0x00
	mov r3, r8
	lsls r0, r3, #0x10
	ldr r2, [sp, #0x000]
	lsls r1, r2, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	asrs r1, r1, #0x10
	mov r12, r1
_080D4E5E:
	movs r5, #0x00
	adds r7, r6, #0x1
_080D4E62:
	mov r3, r8
	adds r2, r3, r6
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D4E6E
	adds r0, #0x1F
_080D4E6E:
	asrs r0, r0, #0x05
	lsls r1, r0, #0x0B
	lsls r0, r0, #0x05
	subs r0, r2, r0
	lsls r0, r0, #0x05
	adds r3, r1, r0
	mov r0, r12
	adds r2, r0, r5
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D4E86
	adds r0, #0x1F
_080D4E86:
	asrs r0, r0, #0x05
	lsls r1, r0, #0x0A
	adds r1, r3, r1
	lsls r0, r0, #0x05
	subs r0, r2, r0
	adds r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x0F
	add r1, r9
	strh r4, [r1, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, #0x01
	cmp r5, #0x03
	ble _080D4E62
	adds r6, r7, #0x0
	cmp r6, #0x03
	ble _080D4E5E
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start func_080D4EBC
func_080D4EBC: @ 080D4EBC
	push {r4, r5, r6, lr}
	add sp, #-0x004
	ldr r4, _080D50E4 @ =0x0203C4B4
	movs r0, #0xC4
	bl func_08000918
	str r0, [r4, #0x00]
	adds r0, #0xC0
	movs r1, #0xFF
	strb r1, [r0, #0x00]
	ldr r0, [r4, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xBC
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [r2, #0x00]
	ldr r2, _080D50E8 @ =0x0203C538
	ldr r1, _080D50EC @ =0x0203C590
	ldrb r1, [r1, #0x06]
	strb r1, [r2, #0x00]
	movs r1, #0x23
	bl func_08000E64
	ldr r0, [r4, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x9C
	movs r2, #0x00
	str r2, [r1, #0x00]
	adds r0, #0x98
	str r2, [r0, #0x00]
	movs r3, #0x00
_080D4EFA:
	ldr r0, [r4, #0x00]
	lsls r1, r2, #0x02
	adds r0, #0x14
	adds r0, r0, r1
	str r3, [r0, #0x00]
	adds r2, #0x01
	cmp r2, #0x1F
	ble _080D4EFA
	ldr r6, _080D50E4 @ =0x0203C4B4
	ldr r2, [r6, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xB6
	movs r4, #0x00
	movs r1, #0x20
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strh r1, [r0, #0x00]
	adds r0, #0x06
	strh r1, [r0, #0x00]
	subs r0, #0x02
	strh r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x20
	bl func_080D576C
	ldr r3, [r6, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xA0
	strh r4, [r0, #0x00]
	adds r0, #0x02
	strh r4, [r0, #0x00]
	adds r0, #0x12
	ldrh r0, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xB6
	ldrh r1, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xB8
	ldrh r2, [r2, #0x00]
	adds r3, #0xBA
	ldrh r3, [r3, #0x00]
	bl func_080D58AC
	ldr r2, [r6, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xA4
	movs r0, #0xA2
	adds r0, r0, r2
	mov r12, r0
	movs r3, #0x00
	ldsh r0, [r0, r3]
	adds r0, #0xA0
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	adds r1, #0x04
	mov r4, r12
	movs r5, #0x00
	ldsh r0, [r4, r5]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	ldr r1, _080D50F0 @ =0x0203C540
	adds r3, r2, #0x0
	adds r3, #0xAC
	adds r4, r2, #0x0
	adds r4, #0xA0
	ldrh r0, [r4, #0x00]
	ldrh r5, [r3, #0x00]
	adds r0, r0, r5
	strh r0, [r1, #0x00]
	ldr r1, _080D50F4 @ =0x0203C53C
	adds r5, r2, #0x0
	adds r5, #0xAE
	mov r2, r12
	ldrh r0, [r2, #0x00]
	ldrh r2, [r5, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldr r2, _080D50F8 @ =0x02034E8C
	movs r1, #0x00
	ldsh r0, [r3, r1]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r2, _080D50FC @ =0x02034E90
	movs r4, #0x00
	ldsh r0, [r5, r4]
	mov r5, r12
	movs r3, #0x00
	ldsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	movs r5, #0x00
_080D4FB8:
	ldr r0, [r6, #0x00]
	lsls r4, r5, #0x02
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D4FFA
	ldr r0, [r6, #0x00]
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x04]
	adds r0, r2, #0x0
	adds r0, #0x8C
	movs r1, #0x00
	ldsh r4, [r0, r1]
	adds r0, #0x02
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, #0x0C
	ldrh r2, [r0, #0x00]
	movs r3, #0x00
	ldr r0, _080D50E8 @ =0x0203C538
	ldrb r0, [r0, #0x00]
	cmp r5, r0
	bne _080D4FF4
	movs r3, #0x01
_080D4FF4:
	adds r0, r4, #0x0
	bl func_080D4D50
_080D4FFA:
	adds r5, #0x01
	cmp r5, #0x1F
	ble _080D4FB8
	ldr r5, _080D50E4 @ =0x0203C4B4
	ldr r3, [r5, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xA0
	adds r0, r3, #0x0
	adds r0, #0xAC
	movs r4, #0x00
	ldsh r2, [r0, r4]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D5018
	adds r0, r2, #0x7
_080D5018:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r1, [r1, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r3, #0x0
	adds r4, #0xA2
	adds r0, r3, #0x0
	adds r0, #0xAE
	movs r3, #0x00
	ldsh r2, [r0, r3]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D503A
	adds r0, r2, #0x7
_080D503A:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r2, [r4, #0x00]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_080051C4
	ldr r3, [r5, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xA0
	adds r0, r3, #0x0
	adds r0, #0xAC
	movs r4, #0x00
	ldsh r2, [r0, r4]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D5064
	adds r0, r2, #0x7
_080D5064:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r1, [r1, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r3, #0x0
	adds r4, #0xA2
	adds r0, r3, #0x0
	adds r0, #0xAE
	movs r3, #0x00
	ldsh r2, [r0, r3]
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D5086
	adds r0, r2, #0x7
_080D5086:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r2, r0
	ldrh r2, [r4, #0x00]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_080051C4
	ldr r0, [r5, #0x00]
	ldr r1, _080D50E8 @ =0x0203C538
	ldrb r2, [r1, #0x00]
	lsls r2, r2, #0x02
	adds r1, r0, #0x0
	adds r1, #0x14
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x04]
	adds r1, r2, #0x0
	adds r1, #0x8C
	ldrh r4, [r1, #0x00]
	ldr r3, _080D5100 @ =0xFFFF0000
	ldr r1, [sp, #0x000]
	ands r1, r3
	orrs r1, r4
	str r1, [sp, #0x000]
	adds r2, #0x8E
	ldrh r2, [r2, #0x00]
	lsls r2, r2, #0x10
	ldr r3, _080D5104 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp, #0x000]
	ldr r1, _080D5108 @ =0x09EF4DD8
	mov r2, sp
	bl func_08000E14
	ldr r1, [r5, #0x00]
	adds r1, #0x94
	str r0, [r1, #0x00]
	bl func_080D53F8
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080D50E4: .4byte 0x0203C4B4
_080D50E8: .4byte 0x0203C538
_080D50EC: .4byte 0x0203C590
_080D50F0: .4byte 0x0203C540
_080D50F4: .4byte 0x0203C53C
_080D50F8: .4byte 0x02034E8C
_080D50FC: .4byte 0x02034E90
_080D5100: .4byte 0xFFFF0000
_080D5104: .4byte 0x0000FFFF
_080D5108: .4byte 0x09EF4DD8
	thumb_func_start func_080D510C
func_080D510C: @ 080D510C
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0x0
	adds r0, #0xAC
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r2, #0x0
	adds r1, #0xA0
	movs r3, #0x00
	ldsh r1, [r1, r3]
	adds r0, r0, r1
	lsls r7, r0, #0x08
	adds r0, r2, #0x0
	adds r0, #0xAE
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r2, #0x0
	adds r1, #0xA2
	movs r2, #0x00
	ldsh r1, [r1, r2]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	mov r12, r0
	ldr r2, _080D515C @ =0x02034E8C
	ldr r0, [r2, #0x00]
	subs r0, r7, r0
	asrs r4, r0, #0x03
	ldr r1, _080D5160 @ =0x02034E90
	ldr r0, [r1, #0x00]
	mov r3, r12
	subs r0, r3, r0
	asrs r0, r0, #0x03
	movs r3, #0x80
	lsls r3, r3, #0x04
	adds r6, r2, #0x0
	adds r5, r1, #0x0
	cmp r4, r3
	ble _080D5164
	adds r4, r3, #0x0
	b _080D516C
	.byte 0x00, 0x00
_080D515C: .4byte 0x02034E8C
_080D5160: .4byte 0x02034E90
_080D5164:
	ldr r1, _080D5194 @ =0xFFFFF800
	cmp r4, r1
	bge _080D516C
	adds r4, r1, #0x0
_080D516C:
	movs r1, #0x80
	lsls r1, r1, #0x04
	cmp r0, r1
	bgt _080D517A
	ldr r1, _080D5194 @ =0xFFFFF800
	cmp r0, r1
	bge _080D517C
_080D517A:
	adds r0, r1, #0x0
_080D517C:
	ldr r3, [r6, #0x00]
	ldr r2, [r5, #0x00]
	adds r1, r3, r4
	str r1, [r6, #0x00]
	adds r0, r2, r0
	str r0, [r5, #0x00]
	subs r0, r3, r1
	cmp r0, #0x00
	blt _080D5198
	cmp r0, #0x07
	ble _080D519E
	b _080D51A0
_080D5194: .4byte 0xFFFFF800
_080D5198:
	subs r0, r1, r3
	cmp r0, #0x07
	bgt _080D51A0
_080D519E:
	str r7, [r6, #0x00]
_080D51A0:
	ldr r0, [r5, #0x00]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080D51AE
	cmp r1, #0x07
	ble _080D51B4
	b _080D51B8
_080D51AE:
	subs r0, r0, r2
	cmp r0, #0x07
	bgt _080D51B8
_080D51B4:
	mov r0, r12
	str r0, [r5, #0x00]
_080D51B8:
	ldr r1, _080D51D0 @ =0x0203C540
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x08
	strh r0, [r1, #0x00]
	ldr r1, _080D51D4 @ =0x0203C53C
	ldr r0, [r5, #0x00]
	asrs r0, r0, #0x08
	strh r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D51D0: .4byte 0x0203C540
_080D51D4: .4byte 0x0203C53C
	thumb_func_start func_080D51D8
func_080D51D8: @ 080D51D8
	push {r4, r5, r6, r7, lr}
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D51F0
	ldr r0, _080D521C @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080D51F0
	bl func_080D55E4
_080D51F0:
	ldr r0, _080D521C @ =0x0203C4E0
	ldr r1, [r0, #0x00]
	cmp r1, #0x02
	bne _080D5274
	ldr r0, _080D5220 @ =0x0203C534
	ldrh r2, [r0, #0x00]
	cmp r2, #0x06
	bls _080D522C
	ldr r0, _080D5224 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	adds r1, #0xA8
	ldr r1, [r1, #0x00]
	ldr r3, _080D5228 @ =0xFFFFFE00
	adds r1, r1, r3
	subs r2, #0x07
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_080058FC
	b _080D5262
_080D521C: .4byte 0x0203C4E0
_080D5220: .4byte 0x0203C534
_080D5224: .4byte 0x0203C4B4
_080D5228: .4byte 0xFFFFFE00
_080D522C:
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	beq _080D524C
	ldr r0, _080D5248 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	adds r1, #0xA8
	ldr r1, [r1, #0x00]
	movs r2, #0x01
	bl func_080058FC
	b _080D5262
_080D5248: .4byte 0x0203C4B4
_080D524C:
	ldr r0, _080D5284 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	adds r1, #0xA8
	ldr r1, [r1, #0x00]
	ldr r5, _080D5288 @ =0xFFFFFE00
	adds r1, r1, r5
	movs r2, #0x01
	bl func_080058FC
_080D5262:
	ldr r0, _080D5284 @ =0x0203C4B4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xA4
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	adds r1, #0xA2
	strh r0, [r1, #0x00]
	ldr r0, _080D528C @ =0x0203C4E0
_080D5274:
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	bne _080D5290
	ldr r0, _080D5284 @ =0x0203C4B4
	ldr r0, [r0, #0x00]
	bl func_080D510C
	b _080D52DE
_080D5284: .4byte 0x0203C4B4
_080D5288: .4byte 0xFFFFFE00
_080D528C: .4byte 0x0203C4E0
_080D5290:
	ldr r1, _080D5394 @ =0x0203C540
	ldr r0, _080D5398 @ =0x0203C4B4
	ldr r2, [r0, #0x00]
	adds r3, r2, #0x0
	adds r3, #0xAC
	adds r4, r2, #0x0
	adds r4, #0xA0
	ldrh r0, [r4, #0x00]
	ldrh r6, [r3, #0x00]
	adds r0, r0, r6
	strh r0, [r1, #0x00]
	ldr r1, _080D539C @ =0x0203C53C
	movs r0, #0xAE
	adds r0, r0, r2
	mov r12, r0
	adds r5, r2, #0x0
	adds r5, #0xA2
	ldrh r0, [r5, #0x00]
	mov r2, r12
	ldrh r2, [r2, #0x00]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	ldr r2, _080D53A0 @ =0x02034E8C
	movs r6, #0x00
	ldsh r0, [r3, r6]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	ldr r2, _080D53A4 @ =0x02034E90
	mov r6, r12
	movs r1, #0x00
	ldsh r0, [r6, r1]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	adds r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
_080D52DE:
	ldr r0, _080D5394 @ =0x0203C540
	ldr r7, _080D5398 @ =0x0203C4B4
	ldr r2, [r7, #0x00]
	adds r3, r2, #0x0
	adds r3, #0xAC
	ldrh r0, [r0, #0x00]
	ldrh r1, [r3, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080D539C @ =0x0203C53C
	adds r2, #0xAE
	ldrh r0, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r5, #0x00
	ldsh r1, [r3, r5]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080D530C
	adds r0, r1, #0x7
_080D530C:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	lsls r1, r4, #0x10
	asrs r5, r1, #0x10
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x00
	ldsh r1, [r2, r0]
	adds r2, r1, #0x0
	cmp r1, #0x00
	bge _080D5328
	adds r2, r1, #0x7
_080D5328:
	asrs r2, r2, #0x03
	lsls r2, r2, #0x03
	subs r2, r1, r2
	lsls r0, r6, #0x10
	asrs r4, r0, #0x10
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	adds r1, r3, #0x0
	bl func_08005244
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xAC
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080D5352
	adds r0, r1, #0x7
_080D5352:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r2, #0x0
	adds r0, #0xAE
	movs r5, #0x00
	ldsh r0, [r0, r5]
	adds r2, r0, #0x0
	cmp r0, #0x00
	bge _080D536E
	adds r2, r0, #0x7
_080D536E:
	asrs r2, r2, #0x03
	lsls r2, r2, #0x03
	subs r2, r0, r2
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	ldr r0, [r7, #0x00]
	bl func_08000EA4
	ldr r0, [r7, #0x00]
	bl func_08000EE0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D5394: .4byte 0x0203C540
_080D5398: .4byte 0x0203C4B4
_080D539C: .4byte 0x0203C53C
_080D53A0: .4byte 0x02034E8C
_080D53A4: .4byte 0x02034E90
	thumb_func_start func_080D53A8
func_080D53A8: @ 080D53A8
	push {r4, lr}
	ldr r4, _080D53C0 @ =0x0203C4B4
	ldr r0, [r4, #0x00]
	bl func_08000F0C
	ldr r0, [r4, #0x00]
	bl func_080009C4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D53C0: .4byte 0x0203C4B4
	.byte 0x00, 0xB5, 0x2B, 0xF7, 0xDD, 0xFF, 0x80, 0x21, 0x49, 0x00, 0x01, 0x40, 0x00, 0x29, 0x07, 0xD1
	.byte 0x02, 0x48, 0x00, 0x68, 0xBC, 0x30, 0x00, 0x68, 0x00, 0x02, 0x06, 0xE0, 0xB4, 0xC4, 0x03, 0x02
	.byte 0x03, 0x48, 0x00, 0x68, 0xBC, 0x30, 0x00, 0x68, 0x40, 0x02, 0x00, 0x0C, 0x02, 0xBC, 0x08, 0x47
	.byte 0xB4, 0xC4, 0x03, 0x02
	thumb_func_start func_080D53F8
func_080D53F8: @ 080D53F8
	push {r4, r5, r6, r7, lr}
	ldr r2, _080D548C @ =0x0203C4B4
	ldr r0, [r2, #0x00]
	adds r0, #0xBA
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D5490 @ =0x0203C53C
	movs r3, #0x00
	ldsh r1, [r1, r3]
	subs r0, r0, r1
	lsls r6, r0, #0x09
	movs r5, #0x00
	adds r7, r2, #0x0
_080D5416:
	ldr r0, [r7, #0x00]
	lsls r4, r5, #0x02
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D545A
	ldr r0, [r7, #0x00]
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x04]
	adds r2, r3, #0x0
	adds r2, #0x94
	adds r0, r3, #0x0
	adds r0, #0x8E
	movs r4, #0x00
	ldsh r1, [r0, r4]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D5490 @ =0x0203C53C
	movs r4, #0x00
	ldsh r1, [r1, r4]
	subs r0, r0, r1
	lsls r0, r0, #0x08
	str r0, [r2, #0x00]
	adds r1, r3, #0x0
	adds r1, #0x90
	subs r0, r0, r6
	str r0, [r1, #0x00]
_080D545A:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x1F
	bls _080D5416
	ldr r4, _080D548C @ =0x0203C4B4
	ldr r0, [r4, #0x00]
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D5484
	ldr r0, [r4, #0x00]
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x04]
	ldr r0, [r1, #0x2C]
	subs r0, r0, r6
	str r0, [r1, #0x28]
_080D5484:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D548C: .4byte 0x0203C4B4
_080D5490: .4byte 0x0203C53C
	thumb_func_start func_080D5494
func_080D5494: @ 080D5494
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0x0
	movs r5, #0x00
	ldr r7, _080D54E0 @ =0x0203C4B4
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
_080D54A6:
	ldr r0, [r7, #0x00]
	lsls r4, r5, #0x02
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D54E4
	ldr r0, [r7, #0x00]
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x04]
	adds r0, r1, #0x0
	adds r0, #0x8C
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r8, r0
	bne _080D54E4
	lsrs r0, r6, #0x10
	adds r1, #0x8E
	movs r2, #0x00
	ldsh r1, [r1, r2]
	cmp r0, r1
	bne _080D54E4
	adds r0, r5, #0x0
	b _080D54F0
_080D54E0: .4byte 0x0203C4B4
_080D54E4:
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x1F
	bls _080D54A6
	movs r0, #0xFF
_080D54F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start func_080D54FC
func_080D54FC: @ 080D54FC
	push {r4, r5, r6, r7, lr}
	ldr r2, _080D554C @ =0x0203C4B4
	ldr r0, [r2, #0x00]
	mov r12, r0
	ldr r0, _080D5550 @ =0x0203C538
	ldrb r1, [r0, #0x00]
	lsls r1, r1, #0x02
	mov r0, r12
	adds r0, #0x14
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x04]
	adds r0, r5, #0x0
	adds r0, #0x8E
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	mov r1, r12
	adds r1, #0xAE
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	subs r0, #0x45
	mov r3, r12
	adds r3, #0xA2
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	adds r6, r2, #0x0
	cmp r0, #0x00
	blt _080D5548
	mov r2, r12
	adds r2, #0xB2
	ldrh r4, [r2, #0x00]
	movs r7, #0x00
	ldsh r0, [r2, r7]
	cmp r0, #0x9F
	bgt _080D5554
_080D5548:
	movs r0, #0x00
	b _080D5566
_080D554C: .4byte 0x0203C4B4
_080D5550: .4byte 0x0203C538
_080D5554:
	movs r0, #0x00
	ldsh r1, [r3, r0]
	movs r7, #0x00
	ldsh r0, [r2, r7]
	subs r0, #0xA0
	cmp r1, r0
	ble _080D5568
	adds r0, r4, #0x0
	subs r0, #0xA0
_080D5566:
	strh r0, [r3, #0x00]
_080D5568:
	adds r0, r5, #0x0
	adds r0, #0x8E
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r3, [r6, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xAE
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x0F
	bgt _080D5592
	adds r1, r3, #0x0
	adds r1, #0xA2
	ldrh r0, [r1, #0x00]
	subs r0, #0x10
	strh r0, [r1, #0x00]
_080D5592:
	ldr r2, [r6, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x8C
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r2, #0x0
	adds r1, #0xAC
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	subs r0, #0x68
	adds r3, r2, #0x0
	adds r3, #0xA0
	strh r0, [r3, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	blt _080D55C4
	adds r2, #0xB0
	ldrh r4, [r2, #0x00]
	movs r5, #0x00
	ldsh r0, [r2, r5]
	cmp r0, #0xEF
	bgt _080D55C8
_080D55C4:
	movs r0, #0x00
	b _080D55DA
_080D55C8:
	movs r7, #0x00
	ldsh r1, [r3, r7]
	movs r5, #0x00
	ldsh r0, [r2, r5]
	subs r0, #0xF0
	cmp r1, r0
	ble _080D55DC
	adds r0, r4, #0x0
	subs r0, #0xF0
_080D55DA:
	strh r0, [r3, #0x00]
_080D55DC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start func_080D55E4
func_080D55E4: @ 080D55E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0x00
	ldr r0, _080D5610 @ =0x0203C4B4
	ldr r0, [r0, #0x00]
	adds r0, #0x94
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	mov r8, r0
	ldr r4, [r0, #0x30]
	bl func_0800139C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	beq _080D5638
	cmp r0, #0x20
	bgt _080D5614
	cmp r0, #0x10
	beq _080D5634
	b _080D566A
_080D5610: .4byte 0x0203C4B4
_080D5614:
	cmp r0, #0x40
	beq _080D561E
	cmp r0, #0x80
	beq _080D5650
	b _080D566A
_080D561E:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D5630 @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	lsrs r0, r4, #0x10
	subs r0, #0x01
	b _080D5660
_080D5630: .4byte 0xFFFF0000
_080D5634:
	adds r0, r4, #0x1
	b _080D5652
_080D5638:
	subs r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D564C @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	lsrs r0, r4, #0x10
	subs r0, #0x01
	b _080D5660
	.byte 0x00, 0x00
_080D564C: .4byte 0xFFFF0000
_080D5650:
	subs r0, r4, #0x1
_080D5652:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D56FC @ =0xFFFF0000
	ands r4, r1
	orrs r4, r0
	lsrs r0, r4, #0x10
	adds r0, #0x01
_080D5660:
	lsls r0, r0, #0x10
	ldr r1, _080D5700 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	movs r6, #0x01
_080D566A:
	adds r0, r4, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r5, r1, #0x0
	cmp r1, #0xFF
	beq _080D575A
	mov r0, r8
	str r4, [r0, #0x30]
	ldr r7, _080D5704 @ =0x0203C4B4
	ldr r0, [r7, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xC0
	ldrb r0, [r2, #0x00]
	cmp r0, r1
	beq _080D575A
	strb r1, [r2, #0x00]
	ldr r0, _080D5708 @ =0x0203C538
	strb r1, [r0, #0x00]
	cmp r6, #0x00
	beq _080D56A0
	movs r0, #0x65
	bl func_0811FE70
	bl func_080D54FC
_080D56A0:
	ldr r0, [r7, #0x00]
	adds r0, #0x98
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D56BC
	ldr r0, [r7, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x98
	ldr r1, [r1, #0x00]
	bl func_08000DE8
_080D56BC:
	adds r0, r5, #0x0
	bl func_080DEE18
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x08]
	cmp r0, #0x1A
	beq _080D5710
	adds r0, r5, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D56E6
	adds r0, r5, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D5710
_080D56E6:
	ldr r0, [r7, #0x00]
	ldr r1, _080D570C @ =0x09EF4DF0
	adds r2, r4, #0x0
	adds r2, #0x08
	bl func_08000E14
	ldr r1, [r7, #0x00]
	adds r1, #0x98
	str r0, [r1, #0x00]
	b _080D571E
	.byte 0x00, 0x00
_080D56FC: .4byte 0xFFFF0000
_080D5700: .4byte 0x0000FFFF
_080D5704: .4byte 0x0203C4B4
_080D5708: .4byte 0x0203C538
_080D570C: .4byte 0x09EF4DF0
_080D5710:
	ldr r0, _080D5764 @ =0x0203C4B4
	ldr r0, [r0, #0x00]
	adds r0, #0x98
	movs r1, #0x00
	str r1, [r0, #0x00]
	bl func_080D3ED0
_080D571E:
	ldr r4, _080D5764 @ =0x0203C4B4
	ldr r0, [r4, #0x00]
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D573C
	ldr r0, [r4, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x9C
	ldr r1, [r1, #0x00]
	bl func_08000DE8
_080D573C:
	mov r1, r8
	ldr r0, [r1, #0x30]
	bl func_080D422C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D575A
	ldr r0, [r4, #0x00]
	ldr r1, _080D5768 @ =0x09EF4E38
	mov r2, r8
	bl func_08000E14
	ldr r1, [r4, #0x00]
	adds r1, #0x9C
	str r0, [r1, #0x00]
_080D575A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D5764: .4byte 0x0203C4B4
_080D5768: .4byte 0x09EF4E38
	thumb_func_start func_080D576C
func_080D576C: @ 080D576C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov r10, r4
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	str r5, [sp, #0x008]
	bl func_080DED98
	mov r8, r0
	ldr r6, _080D589C @ =0x0203C4B4
	ldr r0, [r6, #0x00]
	lsls r1, r7, #0x02
	mov r9, r1
	adds r0, #0x14
	add r0, r9
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D588A
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xB6
	ldrh r0, [r1, #0x00]
	cmp r0, r4
	bcs _080D57B6
	strh r4, [r1, #0x00]
_080D57B6:
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xB4
	ldrh r0, [r1, #0x00]
	cmp r0, r4
	bls _080D57C4
	strh r4, [r1, #0x00]
_080D57C4:
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xBA
	ldrh r0, [r1, #0x00]
	cmp r0, r5
	bcs _080D57D2
	strh r5, [r1, #0x00]
_080D57D2:
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xB8
	ldrh r0, [r1, #0x00]
	cmp r0, r5
	bls _080D57E0
	strh r5, [r1, #0x00]
_080D57E0:
	lsls r0, r5, #0x10
	ldr r2, _080D58A0 @ =0x0000FFFF
	orrs r0, r4
	str r0, [sp, #0x000]
	ldr r1, _080D58A4 @ =0xFFFFFF00
	ldr r0, [sp, #0x004]
	ands r0, r1
	orrs r0, r7
	ands r0, r2
	str r0, [sp, #0x004]
	ldr r0, [r6, #0x00]
	ldr r1, _080D58A8 @ =0x09EF4DC0
	mov r2, sp
	bl func_08000E14
	ldr r1, [r6, #0x00]
	adds r1, #0x14
	add r1, r9
	str r0, [r1, #0x00]
	mov r0, r8
	ldrb r3, [r0, #0x00]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D5826
	adds r1, r4, #0x1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	subs r2, r5, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D5826:
	mov r1, r8
	ldrb r3, [r1, #0x01]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D5846
	subs r1, r4, #0x1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r5, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D5846:
	mov r0, r8
	ldrb r3, [r0, #0x02]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D5866
	adds r1, r4, #0x1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r5, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D5866:
	mov r1, r8
	ldrb r3, [r1, #0x03]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D588A
	mov r1, r10
	subs r1, #0x01
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [sp, #0x008]
	subs r2, #0x01
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D588A:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D589C: .4byte 0x0203C4B4
_080D58A0: .4byte 0x0000FFFF
_080D58A4: .4byte 0xFFFFFF00
_080D58A8: .4byte 0x09EF4DC0
	thumb_func_start func_080D58AC
func_080D58AC: @ 080D58AC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, _080D58EC @ =0x0203C4B4
	ldr r1, [r2, #0x00]
	subs r3, r3, r5
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x03
	adds r0, #0x20
	adds r1, #0xB2
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r7, r2, #0x0
	cmp r0, #0x9F
	bgt _080D58F0
	movs r2, #0x00
	ldsh r0, [r1, r2]
	movs r1, #0xA0
	subs r1, r1, r0
	lsrs r0, r1, #0x1F
	adds r1, r1, r0
	lsls r1, r1, #0x0F
	lsrs r3, r1, #0x10
	b _080D58F2
_080D58EC: .4byte 0x0203C4B4
_080D58F0:
	movs r3, #0x00
_080D58F2:
	ldr r2, [r7, #0x00]
	subs r1, r6, r4
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, #0x20
	adds r2, #0xB0
	strh r0, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xEF
	bgt _080D591C
	movs r1, #0x00
	ldsh r0, [r2, r1]
	movs r1, #0xF0
	subs r1, r1, r0
	lsrs r0, r1, #0x1F
	adds r1, r1, r0
	lsls r1, r1, #0x0F
	lsrs r1, r1, #0x10
	b _080D591E
_080D591C:
	movs r1, #0x00
_080D591E:
	ldr r2, [r7, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r4
	lsls r0, r0, #0x03
	subs r0, r0, r1
	adds r1, r2, #0x0
	adds r1, #0xAC
	strh r0, [r1, #0x00]
	lsls r0, r5, #0x01
	adds r0, r0, r5
	lsls r0, r0, #0x03
	subs r0, r0, r3
	adds r2, #0xAE
	strh r0, [r2, #0x00]
	bl func_080D54FC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start func_080D5944
func_080D5944: @ 080D5944
	push {r4, lr}
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl func_080DEE18
	ldrb r0, [r0, #0x00]
	ands r4, r0
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x06, 0x04, 0x49, 0x09, 0x68, 0x80, 0x0D, 0x14, 0x31, 0x09, 0x18, 0x08, 0x68, 0x40, 0x68
	.byte 0x70, 0x47, 0x00, 0x00, 0xB4, 0xC4, 0x03, 0x02
	thumb_func_start func_080D5978
func_080D5978: @ 080D5978
	push {lr}
	adds r3, r1, #0x0
	lsls r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, _080D5994 @ =0x02034EC4
	lsrs r0, r0, #0x0B
	ldr r1, [r1, #0x00]
	adds r1, r1, r0
	adds r0, r3, #0x0
	bl func_080043B4
	pop {r0}
	bx r0
_080D5994: .4byte 0x02034EC4
	thumb_func_start func_080D5998
func_080D5998: @ 080D5998
	push {lr}
	ldr r0, _080D59B0 @ =0x02034EC4
	ldr r0, [r0, #0x00]
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x03
	bl func_08005BE8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D59B0: .4byte 0x02034EC4
	.byte 0x00, 0xB5, 0x03, 0x48, 0x00, 0x78, 0x00, 0x28, 0x06, 0xD0, 0x02, 0x48, 0x36, 0xE0, 0x00, 0x00
	.byte 0xCA, 0x4E, 0x03, 0x02, 0x50, 0x4E, 0xEF, 0x09, 0x04, 0x48, 0x00, 0x21, 0x40, 0x5E, 0x05, 0x28
	.byte 0x32, 0xD8, 0x80, 0x00, 0x02, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46, 0xC2, 0x4E, 0x03, 0x02
	.byte 0xE8, 0x59, 0x0D, 0x08, 0x3C, 0x5A, 0x0D, 0x08, 0x0E, 0x5A, 0x0D, 0x08, 0x18, 0x5A, 0x0D, 0x08
	.byte 0x00, 0x5A, 0x0D, 0x08, 0x24, 0x5A, 0x0D, 0x08, 0x2A, 0x5A, 0x0D, 0x08, 0x33, 0xF7, 0x7E, 0xFA
	.byte 0x33, 0xF7, 0xE2, 0xF9, 0x0A, 0xF0, 0x70, 0xFD, 0x1A, 0xE0, 0x01, 0x48, 0x0E, 0xE0, 0x00, 0x00
	.byte 0xE0, 0x6A, 0xEF, 0x09, 0xD9, 0xF7, 0xBC, 0xF8, 0x00, 0x48, 0x07, 0xE0, 0xF8, 0x12, 0xEF, 0x09
	.byte 0x47, 0xF7, 0x7C, 0xF9, 0x01, 0xE0, 0x47, 0xF7, 0x43, 0xF9, 0x02, 0x48, 0x00, 0x21, 0x2B, 0xF7
	.byte 0x4B, 0xFB, 0x05, 0xE0, 0xD0, 0x6A, 0xEF, 0x09, 0x02, 0x48, 0x00, 0x21, 0x2B, 0xF7, 0x44, 0xFB
	.byte 0x01, 0xBC, 0x00, 0x47, 0xD0, 0x6A, 0xEF, 0x09
	thumb_func_start func_080D5A4C
func_080D5A4C: @ 080D5A4C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080D5A78 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r5, #0x80
	lsls r5, r5, #0x02
	ands r0, r5
	cmp r0, #0x00
	beq _080D5A80
	ldr r4, _080D5A7C @ =0x0984A818
	movs r0, #0x01
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080050DC
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080D5978
	b _080D5A96
_080D5A78: .4byte 0x02039BB0
_080D5A7C: .4byte 0x0984A818
_080D5A80:
	ldr r4, _080D5AEC @ =0x0984A418
	movs r0, #0x01
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080050DC
	movs r0, #0x00
	adds r1, r4, #0x0
	adds r2, r5, #0x0
	bl func_080D5978
_080D5A96:
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_0800501C
	movs r0, #0x02
	bl func_0800501C
	ldr r4, _080D5AF0 @ =0x02034EB8
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D5AC2
	ldr r0, _080D5AF4 @ =0x02034EA0
	ldr r1, _080D5AF8 @ =0x09EF4E60
	movs r2, #0x00
	bl func_08000E14
	str r0, [r4, #0x00]
_080D5AC2:
	ldr r4, _080D5AFC @ =0x02034EBC
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D5ADC
	ldr r0, _080D5AF4 @ =0x02034EA0
	ldr r1, _080D5B00 @ =0x09EF4E78
	movs r2, #0x00
	bl func_08000E14
	str r0, [r4, #0x00]
_080D5ADC:
	movs r0, #0x02
	adds r1, r6, #0x0
	bl func_08006120
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D5AEC: .4byte 0x0984A418
_080D5AF0: .4byte 0x02034EB8
_080D5AF4: .4byte 0x02034EA0
_080D5AF8: .4byte 0x09EF4E60
_080D5AFC: .4byte 0x02034EBC
_080D5B00: .4byte 0x09EF4E78
	thumb_func_start func_080D5B04
func_080D5B04: @ 080D5B04
	push {lr}
	ldr r1, _080D5B2C @ =0x0983F398
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	movs r0, #0x00
	movs r1, #0x05
	movs r2, #0x10
	bl func_080057A0
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x06
	bl func_0811FE70
	pop {r0}
	bx r0
_080D5B2C: .4byte 0x0983F398
	.byte 0x00, 0xB5, 0x0C, 0x4A, 0x0C, 0x48, 0x81, 0x8E, 0x48, 0x00, 0x40, 0x18, 0x80, 0x00, 0x80, 0x18
	.byte 0x00, 0x68, 0x05, 0x21, 0x4A, 0xF0, 0x60, 0xFA, 0x00, 0x20, 0x5A, 0x21, 0x30, 0xF7, 0x1A, 0xFB
	.byte 0x00, 0x20, 0x5A, 0x21, 0xF1, 0xF7, 0x26, 0xFD, 0x04, 0x49, 0x09, 0x20, 0x08, 0x60, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x0C, 0xF6, 0xD6, 0x09, 0x44, 0xF7, 0xD6, 0x09, 0x98, 0x4E, 0x03, 0x02
