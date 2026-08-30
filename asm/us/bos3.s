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

	thumb_func_start task_bos_jf_shadow_0
task_bos_jf_shadow_0: @ 080C6EE0
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x0C]
	ldr r0, _080C6F08 @ =0x08B22EFE
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _080C6F0C @ =0x08B22EE4
	str r0, [r4, #0x08]
	ldr r0, _080C6F10 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C6F08: .4byte 0x08B22EFE
_080C6F0C: .4byte 0x08B22EE4
_080C6F10: .4byte 0x08F69BA4
	thumb_func_start task_bos_jf_shadow_1
task_bos_jf_shadow_1: @ 080C6F14
	movs r0, #0x01
	bx lr
	thumb_func_start task_bos_jf_shadow_2
task_bos_jf_shadow_2: @ 080C6F18
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r5, [r6, #0x0C]
	adds r0, r5, #0x0
	adds r0, #0xCC
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C6FD4
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r3, #0x04
	ands r0, r2
	ands r1, r3
	orrs r0, r1
	cmp r0, #0x00
	bne _080C6FD4
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _080C6F6C
	ldr r0, _080C6F68 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _080C6F6C
	movs r7, #0x00
	b _080C6F9C
	.byte 0x00, 0x00
_080C6F68: .4byte 0x02039B84
_080C6F6C:
	ldr r1, [r5, #0x10]
	ldr r0, [r5, #0x0C]
	subs r1, r1, r0
	cmp r1, #0x00
	bge _080C6F78
	adds r1, #0x7F
_080C6F78:
	asrs r1, r1, #0x07
	movs r0, #0x80
	lsls r0, r0, #0x02
	subs r2, r0, r1
	cmp r2, #0x7F
	bgt _080C6F86
	movs r2, #0x80
_080C6F86:
	movs r3, #0x00
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	ble _080C6F92
	movs r3, #0x01
_080C6F92:
	movs r0, #0x00
	adds r1, r2, #0x0
	bl func_08002CB4
	adds r7, r0, #0x0
_080C6F9C:
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
	ldr r2, [r6, #0x08]
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
_080C6FD4:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_start task_bos_jf_shadow_3
task_bos_jf_shadow_3: @ 080C6FE0
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
	thumb_func_start func_080C6FF8
func_080C6FF8: @ 080C6FF8
	ldr r0, _080C7004 @ =0x0203C3C0
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _080C7008 @ =0x0203C3BC
	strh r1, [r0, #0x00]
	bx lr
_080C7004: .4byte 0x0203C3C0
_080C7008: .4byte 0x0203C3BC
	thumb_func_start func_080C700C
func_080C700C: @ 080C700C
	ldr r1, _080C701C @ =0x0203C3C0
	ldrh r1, [r1, #0x00]
	strh r1, [r0, #0x00]
	ldr r1, _080C7020 @ =0x0203C3BC
	ldrh r1, [r1, #0x00]
	strh r1, [r0, #0x02]
	bx lr
	.byte 0x00, 0x00
_080C701C: .4byte 0x0203C3C0
_080C7020: .4byte 0x0203C3BC
	.byte 0x03, 0x4A, 0x01, 0x88, 0x11, 0x80, 0x03, 0x49, 0x40, 0x88, 0x08, 0x80, 0x70, 0x47, 0x00, 0x00
	.byte 0xC0, 0xC3, 0x03, 0x02, 0xBC, 0xC3, 0x03, 0x02
