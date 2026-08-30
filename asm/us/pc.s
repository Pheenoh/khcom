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

	thumb_func_start task_pc_acddmg_0
task_pc_acddmg_0: @ 08049DCC
	str r1, [r0, #0x04]
	movs r2, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x02]
	movs r1, #0x28
	strh r1, [r0, #0x00]
	strb r2, [r0, #0x08]
	bx lr
	thumb_func_start task_pc_acddmg_1
task_pc_acddmg_1: @ 08049DDC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r3, _08049E34 @ =0x02039B84
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x0D
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	cmp r1, #0x00
	bne _08049E68
	ldr r5, [r4, #0x04]
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _08049E44
	movs r0, #0x01
	strb r0, [r4, #0x08]
	ldrh r1, [r4, #0x00]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	bgt _08049E40
	movs r1, #0x02
	ldsh r0, [r4, r1]
	movs r1, #0x3C
	bl func_0811D684
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _08049E2A
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	ldr r2, _08049E38 @ =0x20000000
	ldr r3, _08049E3C @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_08049E2A:
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	b _08049E68
	.byte 0x00, 0x00
_08049E34: .4byte 0x02039B84
_08049E38: .4byte 0x20000000
_08049E3C: .4byte 0x00000000
_08049E40:
	subs r0, r1, #0x1
	b _08049E66
_08049E44:
	ldrb r0, [r4, #0x08]
	cmp r0, #0x00
	beq _08049E50
	strb r1, [r4, #0x08]
	strh r1, [r4, #0x02]
	strh r1, [r4, #0x00]
_08049E50:
	ldr r0, [r3, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08049E68
	movs r0, #0x28
_08049E66:
	strh r0, [r4, #0x00]
_08049E68:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_start func_08049E70
func_08049E70: @ 08049E70
	push {r4, r5, r6, lr}
	mov r12, r0
	adds r6, r2, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	mov r4, r12
	mov r3, r12
	adds r3, #0x40
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049EA0
	movs r2, #0xAE
	lsls r2, r2, #0x01
	add r2, r12
	lsls r1, r5, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x04]
	subs r0, r0, r1
	b _08049EAE
_08049EA0:
	movs r2, #0xAE
	lsls r2, r2, #0x01
	add r2, r12
	lsls r1, r5, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x04]
	adds r0, r0, r1
_08049EAE:
	str r0, [r2, #0x00]
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r3, #0x08]
	str r0, [r1, #0x00]
	movs r0, #0xB8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x19
	str r0, [r1, #0x00]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	strh r2, [r0, #0x00]
	adds r1, #0x38
	add r1, r12
	negs r0, r6
	str r0, [r1, #0x00]
	movs r0, #0xC6
	lsls r0, r0, #0x01
	add r0, r12
	strh r2, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_start func_08049EE4
func_08049EE4: @ 08049EE4
	push {r4, lr}
	adds r3, r0, #0x0
	movs r4, #0xAE
	lsls r4, r4, #0x01
	adds r0, r3, r4
	str r1, [r0, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r3, r1
	str r2, [r0, #0x00]
	adds r4, #0x14
	adds r1, r3, r4
	movs r0, #0x19
	str r0, [r1, #0x00]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r3, r1
	movs r2, #0x00
	strh r2, [r0, #0x00]
	adds r4, #0x18
	adds r1, r3, r4
	ldr r0, _08049F20 @ =0xFFFFFB00
	str r0, [r1, #0x00]
	movs r1, #0xC8
	lsls r1, r1, #0x01
	adds r0, r3, r1
	strh r2, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_08049F20: .4byte 0xFFFFFB00
	.byte 0x10, 0xB5, 0x03, 0x1C, 0xAE, 0x24, 0x64, 0x00, 0x18, 0x19, 0x01, 0x60, 0xB0, 0x21, 0x49, 0x00
	.byte 0x58, 0x18, 0x02, 0x60, 0x14, 0x34, 0x19, 0x19, 0x21, 0x20, 0x08, 0x60, 0xA8, 0x20, 0x40, 0x00
	.byte 0x19, 0x18, 0x00, 0x20, 0x08, 0x80, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47
	thumb_func_start func_08049F50
func_08049F50: @ 08049F50
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r5, _08049FBC @ =0x02039B84
	ldr r0, [r5, #0x00]
	ldr r6, [r0, #0x7C]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x3C
	bl func_0811D7CC
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0804A00A
	adds r0, r4, #0x0
	adds r0, #0x40
	add r2, sp, #0x004
	mov r1, sp
	movs r3, #0x00
	bl func_0801C700
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_0800F368
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	adds r2, r3, #0x0
	bl func_0800F504
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0804A00A
	ldr r0, [r5, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049FC0
	subs r1, #0x63
	movs r2, #0xA0
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl func_08049E70
	b _0804A006
_08049FBC: .4byte 0x02039B84
_08049FC0:
	bl func_080065A4
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08049FF8
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049FE4
	ldr r1, [sp, #0x000]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	b _08049FE8
_08049FE4:
	ldr r1, [sp, #0x000]
	ldr r0, _08049FF4 @ =0xFFFFD800
_08049FE8:
	adds r1, r1, r0
	ldr r2, [sp, #0x004]
	adds r0, r4, #0x0
	bl func_08049EE4
	b _0804A006
_08049FF4: .4byte 0xFFFFD800
_08049FF8:
	movs r1, #0x50
	negs r1, r1
	movs r2, #0xA0
	lsls r2, r2, #0x03
	adds r0, r4, #0x0
	bl func_08049E70
_0804A006:
	movs r0, #0x01
	b _0804A00C
_0804A00A:
	movs r0, #0x00
_0804A00C:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
