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

	thumb_func_start mode_copyright2_0
mode_copyright2_0: @ 080D71D8
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	ldr r1, _080D7224 @ =0x097E05B8
	ldr r2, _080D7228 @ =0x00004FC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D722C @ =0x0984AC38
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080D7230 @ =0x09841F98
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	cmp r4, #0x00
	bne _080D7234
	movs r0, #0x00
	movs r1, #0x43
	bl func_08006120
	b _080D723C
_080D7224: .4byte 0x097E05B8
_080D7228: .4byte 0x00004FC0
_080D722C: .4byte 0x0984AC38
_080D7230: .4byte 0x09841F98
_080D7234:
	movs r0, #0x01
	movs r1, #0x43
	bl func_08006120
_080D723C:
	ldr r1, _080D7248 @ =0x02034EDC
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080D7248: .4byte 0x02034EDC
	thumb_func_start mode_copyright2_1
mode_copyright2_1: @ 080D724C
	push {lr}
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D7280
	ldr r1, _080D7274 @ =0x02034EDC
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D7278
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D7280
	movs r0, #0x00
	movs r1, #0x43
	bl func_08006184
	b _080D7280
_080D7274: .4byte 0x02034EDC
_080D7278:
	ldr r0, _080D7284 @ =0x09EF4E50
	movs r1, #0x00
	bl func_080010CC
_080D7280:
	pop {r0}
	bx r0
_080D7284: .4byte 0x09EF4E50
	thumb_func_start mode_copyright2_2
mode_copyright2_2: @ 080D7288
	bx lr
	.byte 0x00, 0x00
	thumb_func_start func_080D728C
func_080D728C: @ 080D728C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	mov r9, r0
	mov r10, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	cmp r2, #0x06
	bls _080D72AA
	movs r0, #0x06
	mov r8, r0
_080D72AA:
	movs r4, #0x01
	mov r0, r8
	cmp r0, #0x00
	beq _080D72C0
	mov r6, r8
_080D72B4:
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r4, r0, #0x01
	subs r6, #0x01
	cmp r6, #0x00
	bne _080D72B4
_080D72C0:
	subs r0, r4, #0x1
	cmp r10, r0
	bgt _080D72CE
	mov r0, r10
	cmp r0, #0x00
	bge _080D72D0
	movs r0, #0x00
_080D72CE:
	mov r10, r0
_080D72D0:
	mov r0, r8
	cmp r0, #0x00
	beq _080D7300
	mov r7, sp
	mov r6, r8
_080D72DA:
	mov r0, r10
	adds r1, r4, #0x0
	bl func_0811D684
	adds r5, r0, #0x0
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl func_0811D5EC
	adds r4, r0, #0x0
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_0811D5EC
	strh r0, [r7, #0x00]
	adds r7, #0x02
	subs r6, #0x01
	cmp r6, #0x00
	bne _080D72DA
_080D7300:
	mov r0, r8
	cmp r0, #0x00
	beq _080D7326
	mov r4, sp
	ldr r5, _080D7338 @ =0x09801C98
	mov r6, r8
_080D730C:
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x05
	adds r0, r0, r5
	mov r1, r9
	movs r2, #0x20
	bl func_080043B4
	movs r0, #0x20
	add r9, r0
	adds r4, #0x02
	subs r6, #0x01
	cmp r6, #0x00
	bne _080D730C
_080D7326:
	mov r0, r9
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080D7338: .4byte 0x09801C98
	thumb_func_start func_080D733C
func_080D733C: @ 080D733C
	push {r4, lr}
	movs r0, #0x02
	bl func_08005130
	adds r2, r0, #0x0
	adds r2, #0x40
	ldr r4, _080D7388 @ =0x02039BB0
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x02
	bl func_080D728C
	adds r2, r0, #0x0
	movs r3, #0x32
	ldsh r1, [r4, r3]
	movs r2, #0x03
	bl func_080D728C
	adds r2, r0, #0x0
	adds r0, r4, #0x0
	adds r0, #0xF8
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x03
	bl func_080D728C
	adds r2, r0, #0x0
	ldr r0, [r4, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D738C
	adds r2, #0x80
	b _080D739E
_080D7388: .4byte 0x02039BB0
_080D738C:
	adds r0, r4, #0x0
	adds r0, #0xFA
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x04
	bl func_080D728C
	adds r2, r0, #0x0
_080D739E:
	ldr r4, _080D73F4 @ =0x02039BB0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x06
	bl func_080D728C
	adds r2, r0, #0x0
	movs r3, #0x82
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldr r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x06
	bl func_080D728C
	adds r2, r0, #0x0
	ldr r0, [r4, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D73F8
	adds r2, #0xC0
	adds r0, r4, #0x0
	adds r0, #0xFE
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x02
	bl func_080D728C
	adds r2, r0, #0x0
	adds r0, r4, #0x0
	adds r0, #0xFC
	movs r3, #0x00
	ldsh r1, [r0, r3]
	adds r0, r2, #0x0
	movs r2, #0x03
	bl func_080D728C
	b _080D740A
_080D73F4: .4byte 0x02039BB0
_080D73F8:
	adds r2, #0x20
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	adds r0, r2, #0x0
	movs r2, #0x05
	bl func_080D728C
_080D740A:
	pop {r4}
	pop {r0}
	bx r0
