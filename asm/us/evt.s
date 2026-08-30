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

	thumb_func_start task_evt_obj_0
task_evt_obj_0: @ 0801CEAC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, [r1, #0x00]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x00]
	ldrh r0, [r5, #0x00]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080028F8
	str r0, [r4, #0x04]
	ldr r0, [r5, #0x08]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	adds r5, r4, #0x0
	adds r5, #0x0C
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r1, [r4, #0x00]
	str r5, [r1, #0x18]
	ldr r0, [r4, #0x08]
	ldrh r0, [r0, #0x06]
	strh r0, [r1, #0x1C]
	adds r0, r4, #0x0
	bl func_0801CE70
	adds r5, #0x18
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _0801CF08 @ =0x09EDADE0
	ldr r2, [r4, #0x00]
	adds r0, r5, #0x0
	bl func_08000E14
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801CF08: .4byte 0x09EDADE0
	thumb_func_start task_evt_obj_1
task_evt_obj_1: @ 0801CF0C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	ldrh r1, [r0, #0x14]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0801CF22
	adds r0, r4, #0x0
	bl func_0801CE70
_0801CF22:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	adds r0, r4, #0x0
	adds r0, #0x24
	bl func_08000EA4
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	thumb_func_start task_evt_obj_2
task_evt_obj_2: @ 0801CF3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r7, [r6, #0x00]
	ldrh r1, [r7, #0x14]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _0801CFCA
	ldr r5, [r7, #0x04]
	asrs r5, r5, #0x08
	ldr r0, _0801CFD8 @ =0x02039DC8
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x58]
	asrs r0, r0, #0x08
	subs r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, [r7, #0x08]
	asrs r4, r4, #0x08
	ldr r0, [r7, #0x0C]
	asrs r0, r0, #0x08
	adds r4, r4, r0
	ldr r0, [r1, #0x5C]
	asrs r0, r0, #0x08
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	mov r8, r0
	adds r0, r7, #0x0
	adds r0, #0x28
	ldrb r0, [r0, #0x00]
	ldr r1, [r7, #0x20]
	ldr r2, [r7, #0x24]
	movs r3, #0x01
	bl func_08002CB4
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [r6, #0x04]
	ldr r1, [r6, #0x08]
	str r1, [sp, #0x000]
	str r0, [sp, #0x004]
	ldrh r0, [r7, #0x16]
	str r0, [sp, #0x008]
	ldr r1, [r7, #0x08]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _0801CFDC @ =0xFFFFEFFE
	adds r0, r2, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	mov r2, r8
	bl func_080023E0
	adds r0, r6, #0x0
	adds r0, #0x24
	bl func_08000EE0
_0801CFCA:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801CFD8: .4byte 0x02039DC8
_0801CFDC: .4byte 0xFFFFEFFE
	thumb_func_start task_evt_obj_3
task_evt_obj_3: @ 0801CFE0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	bl func_080028C0
	ldr r0, [r4, #0x08]
	bl func_08002C10
	adds r4, #0x24
	adds r0, r4, #0x0
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start task_evt_shadow_0
task_evt_shadow_0: @ 0801D000
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x04]
	ldr r0, _0801D03C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x08]
	ldr r0, _0801D040 @ =0x08B22CE4
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r4, #0x10]
	ldr r0, _0801D044 @ =0x08B22EFE
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x0C]
	ldr r0, _0801D048 @ =0x08F69BE4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801D03C: .4byte 0x08B22BBC
_0801D040: .4byte 0x08B22CE4
_0801D044: .4byte 0x08B22EFE
_0801D048: .4byte 0x08F69BE4
	thumb_func_start task_evt_shadow_1
task_evt_shadow_1: @ 0801D04C
	movs r0, #0x01
	bx lr
	thumb_func_start task_evt_shadow_2
task_evt_shadow_2: @ 0801D050
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r4, [r5, #0x04]
	ldrh r1, [r4, #0x14]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _0801D0FC
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0801D074
	ldr r7, _0801D070 @ =0x08B22EE4
	ldr r6, [r5, #0x0C]
	b _0801D08C
_0801D070: .4byte 0x08B22EE4
_0801D074:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _0801D088
	ldr r7, _0801D084 @ =0x08B22CBC
	ldr r6, [r5, #0x10]
	b _0801D08C
	.byte 0x00, 0x00
_0801D084: .4byte 0x08B22CBC
_0801D088:
	ldr r7, _0801D098 @ =0x08B22BA8
	ldr r6, [r5, #0x08]
_0801D08C:
	ldr r0, [r4, #0x0C]
	ldr r1, [r4, #0x10]
	cmp r0, r1
	blt _0801D09C
	movs r0, #0x00
	b _0801D0BC
_0801D098: .4byte 0x08B22BA8
_0801D09C:
	subs r1, r1, r0
	cmp r1, #0x00
	bge _0801D0A4
	adds r1, #0x7F
_0801D0A4:
	asrs r1, r1, #0x07
	movs r0, #0x80
	lsls r0, r0, #0x01
	subs r2, r0, r1
	cmp r2, #0x18
	bgt _0801D0B2
	movs r2, #0x19
_0801D0B2:
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl func_08002CB4
_0801D0BC:
	mov r12, r0
	ldr r0, [r4, #0x04]
	asrs r0, r0, #0x08
	ldr r1, _0801D104 @ =0x02039DC8
	ldr r3, [r1, #0x00]
	ldr r1, [r3, #0x58]
	asrs r1, r1, #0x08
	subs r0, r0, r1
	ldr r1, [r4, #0x08]
	asrs r1, r1, #0x08
	ldr r2, [r4, #0x10]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, [r3, #0x5C]
	asrs r2, r2, #0x08
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x00]
	str r2, [sp, #0x000]
	mov r2, r12
	str r2, [sp, #0x004]
	ldrh r2, [r4, #0x16]
	str r2, [sp, #0x008]
	ldr r2, _0801D108 @ =0x0000FFF0
	str r2, [sp, #0x00C]
	adds r2, r7, #0x0
	adds r3, r6, #0x0
	bl func_080023E0
_0801D0FC:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0801D104: .4byte 0x02039DC8
_0801D108: .4byte 0x0000FFF0
	thumb_func_start task_evt_shadow_3
task_evt_shadow_3: @ 0801D10C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x0C]
	bl func_080028C0
	ldr r0, [r4, #0x10]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
