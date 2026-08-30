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

	thumb_func_start task_acgtrans_0
task_acgtrans_0: @ 0801D130
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x04]
	ldrh r0, [r5, #0x08]
	strh r0, [r4, #0x08]
	ldrh r0, [r4, #0x08]
	ldrh r1, [r5, #0x0A]
	bl _0811D754
	strh r0, [r4, #0x0A]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0801D156
	movs r0, #0x01
	strh r0, [r4, #0x0A]
_0801D156:
	movs r0, #0x00
	strh r0, [r4, #0x0C]
	ldr r0, [r5, #0x0C]
	str r0, [r4, #0x10]
	bl func_0800501C
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start task_acgtrans_1
task_acgtrans_1: @ 0801D168
	push {r4, lr}
	adds r4, r0, #0x0
	ldrh r2, [r4, #0x0A]
	ldrh r0, [r4, #0x0C]
	adds r1, r2, r0
	ldrh r0, [r4, #0x08]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r0, #0x00
	bgt _0801D196
	adds r0, r2, r1
	strh r0, [r4, #0x0A]
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x0A]
	bl func_080043B4
	ldr r0, [r4, #0x10]
	bl func_0800501C
	movs r0, #0x00
	b _0801D1BE
_0801D196:
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x0A]
	bl func_080043B4
	ldrh r1, [r4, #0x0A]
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r0, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r4, #0x00]
	ldrh r0, [r4, #0x0A]
	ldrh r1, [r4, #0x0C]
	adds r0, r0, r1
	strh r0, [r4, #0x0C]
	ldr r0, [r4, #0x10]
	bl func_0800501C
	movs r0, #0x01
_0801D1BE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_start func_0801D1C4
func_0801D1C4: @ 0801D1C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	mov r8, r1
	adds r4, r2, #0x0
	adds r5, r3, #0x0
	ldr r6, [sp, #0x028]
	ldr r0, [sp, #0x02C]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	str r0, [sp, #0x000]
	mov r0, r8
	bl func_08005130
	lsls r4, r4, #0x05
	adds r0, r0, r4
	str r0, [sp, #0x004]
	mov r0, sp
	lsls r5, r5, #0x05
	strh r5, [r0, #0x08]
	strh r6, [r0, #0x0A]
	mov r0, r8
	str r0, [sp, #0x00C]
	mov r0, sp
	ldrh r0, [r0, #0x0A]
	cmp r0, #0x00
	bne _0801D20C
	mov r1, sp
	movs r0, #0x01
	strh r0, [r1, #0x0A]
_0801D20C:
	ldr r1, _0801D224 @ =0x09EDADF8
	adds r0, r7, #0x0
	mov r2, sp
	bl func_08000E14
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801D224: .4byte 0x09EDADF8
