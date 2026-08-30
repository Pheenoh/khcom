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

	thumb_func_start task_bos_map_0
task_bos_map_0: @ 0803F014
	push {r4, lr}
	adds r4, r1, #0x0
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x04]
	movs r0, #0x00
	bl func_080050B8
	ldr r1, [r4, #0x08]
	ldrh r2, [r4, #0x0C]
	movs r0, #0x00
	bl func_080050DC
	adds r4, #0x10
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	ldr r4, _0803F084 @ =0x02039B84
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	movs r2, #0x80
	lsls r2, r2, #0x09
	str r2, [r0, #0x08]
	movs r1, #0xA0
	lsls r1, r1, #0x09
	str r1, [r0, #0x0C]
	str r2, [r0, #0x00]
	str r1, [r0, #0x04]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1C]
	str r1, [r0, #0x20]
	movs r2, #0x00
	movs r1, #0x0F
	strh r1, [r0, #0x1A]
	strb r2, [r0, #0x18]
	bl func_0802F1C8
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	ldr r2, [r0, #0x04]
	lsls r2, r2, #0x08
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	pop {r4}
	pop {r0}
	bx r0
_0803F084: .4byte 0x02039B84
	thumb_func_start task_bos_map_1
task_bos_map_1: @ 0803F088
	push {r4, r5, r6, lr}
	bl func_0802F208
	ldr r0, _0803F0E0 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r4, r0, #0x03
	ldr r0, [r2, #0x14]
	ldr r1, [r2, #0x0C]
	subs r0, r0, r1
	asrs r1, r0, #0x03
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r4, r0
	bgt _0803F0B0
	ldr r0, _0803F0E4 @ =0xFFFFFB00
	cmp r4, r0
	bge _0803F0B2
_0803F0B0:
	adds r4, r0, #0x0
_0803F0B2:
	ldr r2, _0803F0E0 @ =0x02039B84
	ldr r3, [r2, #0x00]
	ldr r0, [r3, #0x08]
	adds r4, r0, r4
	str r4, [r3, #0x08]
	ldr r0, [r3, #0x0C]
	adds r0, r0, r1
	str r0, [r3, #0x0C]
	str r4, [r3, #0x00]
	str r0, [r3, #0x04]
	ldr r0, _0803F0E8 @ =0xFFFF8800
	adds r1, r4, r0
	adds r0, r3, #0x0
	adds r0, #0xDA
	movs r6, #0x00
	ldsh r5, [r0, r6]
	lsls r0, r5, #0x08
	cmp r1, r0
	bge _0803F0EC
	adds r0, r5, #0x0
	adds r0, #0x78
	b _0803F104
	.byte 0x00, 0x00
_0803F0E0: .4byte 0x02039B84
_0803F0E4: .4byte 0xFFFFFB00
_0803F0E8: .4byte 0xFFFF8800
_0803F0EC:
	movs r1, #0xF0
	lsls r1, r1, #0x07
	adds r0, r4, r1
	adds r1, r3, #0x0
	adds r1, #0xDC
	movs r5, #0x00
	ldsh r4, [r1, r5]
	lsls r1, r4, #0x08
	cmp r0, r1
	ble _0803F108
	adds r0, r4, #0x0
	subs r0, #0x78
_0803F104:
	lsls r0, r0, #0x08
	str r0, [r3, #0x00]
_0803F108:
	ldr r1, [r2, #0x00]
	ldr r0, [r1, #0x04]
	movs r6, #0xA0
	lsls r6, r6, #0x07
	adds r3, r0, r6
	adds r0, r1, #0x0
	adds r0, #0xDE
	movs r4, #0x00
	ldsh r2, [r0, r4]
	lsls r0, r2, #0x08
	cmp r3, r0
	blt _0803F12E
	adds r0, r1, #0x0
	adds r0, #0xE0
	movs r5, #0x00
	ldsh r2, [r0, r5]
	lsls r0, r2, #0x08
	cmp r3, r0
	ble _0803F136
_0803F12E:
	adds r0, r2, #0x0
	subs r0, #0x50
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
_0803F136:
	bl func_0802F268
	ldr r1, _0803F164 @ =0x02039B84
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x04]
	adds r2, r2, r0
	str r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	adds r1, #0x08
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	asrs r2, r2, #0x08
	adds r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_0803F164: .4byte 0x02039B84
	thumb_func_start task_bos_shadow_0
task_bos_shadow_0: @ 0803F168
	push {r4, lr}
	adds r4, r0, #0x0
	str r1, [r4, #0x08]
	ldr r0, _0803F18C @ =0x08B22BBC
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, _0803F190 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803F18C: .4byte 0x08B22BBC
_0803F190: .4byte 0x08F69BA4
	thumb_func_start task_bos_shadow_1
task_bos_shadow_1: @ 0803F194
	movs r0, #0x01
	bx lr
	thumb_func_start task_bos_shadow_2
task_bos_shadow_2: @ 0803F198
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldr r6, [r7, #0x08]
	movs r5, #0x00
	ldr r0, _0803F234 @ =0x08B22BA8
	mov r9, r0
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x0C]
	subs r0, r0, r1
	asrs r0, r0, #0x07
	movs r4, #0x80
	lsls r4, r4, #0x01
	subs r3, r4, r0
	cmp r3, #0xB2
	bgt _0803F1CC
	movs r3, #0xB3
_0803F1CC:
	ldr r0, [r7, #0x08]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x0A
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803F1E4
	adds r3, r3, r4
	movs r5, #0x01
_0803F1E4:
	movs r0, #0x00
	adds r1, r3, #0x0
	adds r2, r3, #0x0
	adds r3, r5, #0x0
	bl func_08002CB4
	adds r5, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	ldr r0, [r6, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r7, #0x00]
	ldr r2, [r7, #0x04]
	str r2, [sp, #0x000]
	str r5, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	ldr r2, _0803F238 @ =0x0000FFF0
	str r2, [sp, #0x00C]
	mov r2, r9
	bl func_080023E0
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0803F234: .4byte 0x08B22BA8
_0803F238: .4byte 0x0000FFF0
	thumb_func_start task_bos_shadow_3
task_bos_shadow_3: @ 0803F23C
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
