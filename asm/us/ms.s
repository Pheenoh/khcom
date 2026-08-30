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

	thumb_func_start task_ms_shop_hosi_0
task_ms_shop_hosi_0: @ 0810951C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	movs r1, #0x00
	ldsh r0, [r5, r1]
	lsls r0, r0, #0x08
	str r0, [r4, #0x00]
	movs r2, #0x02
	ldsh r0, [r5, r2]
	lsls r0, r0, #0x08
	str r0, [r4, #0x04]
	ldr r2, _08109588 @ =0x08121400
	ldrb r0, [r5, #0x08]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r1, [r5, #0x0C]
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r4, #0x08]
	ldrb r0, [r5, #0x08]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r0, [r0, r2]
	negs r0, r0
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r4, #0x0C]
	movs r0, #0x00
	strh r0, [r4, #0x10]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x07
	ands r0, r1
	adds r0, #0x04
	strh r0, [r4, #0x14]
	strh r0, [r4, #0x12]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x18]
	ldr r0, _0810958C @ =0x099A6962
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x1C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08109588: .4byte 0x08121400
_0810958C: .4byte 0x099A6962
	thumb_func_start task_ms_shop_hosi_1
task_ms_shop_hosi_1: @ 08109590
	adds r2, r0, #0x0
	movs r3, #0x01
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, [r2, #0x0C]
	adds r1, #0x0A
	str r1, [r2, #0x0C]
	ldr r0, [r2, #0x04]
	adds r0, r0, r1
	str r0, [r2, #0x04]
	ldrh r0, [r2, #0x12]
	subs r0, #0x01
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _081095C8
	ldrh r0, [r2, #0x14]
	strh r0, [r2, #0x12]
	ldrh r0, [r2, #0x10]
	adds r0, #0x01
	strh r0, [r2, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x05
	ble _081095C8
	movs r3, #0x00
_081095C8:
	adds r0, r3, #0x0
	bx lr
	thumb_func_start task_ms_shop_hosi_2
task_ms_shop_hosi_2: @ 081095CC
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldrh r1, [r4, #0x12]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08109606
	ldr r0, [r4, #0x00]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x04]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r3, _08109610 @ =0x09EF9A4C
	movs r5, #0x10
	ldsh r2, [r4, r5]
	lsls r2, r2, #0x02
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r4, #0x1C]
	ldr r4, [r4, #0x18]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl func_080023E0
_08109606:
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08109610: .4byte 0x09EF9A4C
	thumb_func_start task_ms_shop_hosi_3
task_ms_shop_hosi_3: @ 08109614
	push {lr}
	ldr r0, [r0, #0x1C]
	bl func_080028C0
	pop {r0}
	bx r0
	thumb_func_start func_08109620
func_08109620: @ 08109620
	push {lr}
	bl func_081025AC
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start func_0810962C
func_0810962C: @ 0810962C
	push {lr}
	bl func_081025D4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	thumb_func_start func_08109638
func_08109638: @ 08109638
	push {lr}
	bl func_08102610
	pop {r0}
	bx r0
	.byte 0x00, 0x00
