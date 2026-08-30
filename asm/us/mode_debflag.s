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

	thumb_func_start mode_debflag_0
mode_debflag_0: @ 0800C1B8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0x0
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	bl func_08004FC8
	movs r1, #0xA8
	lsls r1, r1, #0x07
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl func_0805FA8C
	ldr r1, _0800C21C @ =0x08128304
	movs r0, #0x00
	movs r2, #0x20
	movs r3, #0x0F
	bl func_0805FA60
	ldr r1, _0800C220 @ =0x020348C0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r3, _0800C224 @ =0x08130E34
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	cmp r4, #0x00
	beq _0800C238
	ldr r2, _0800C228 @ =0x020348C1
	movs r0, #0x07
	strb r0, [r2, #0x00]
	ldr r1, _0800C22C @ =0x020348C4
	ldr r0, _0800C230 @ =0x08130DE0
	str r0, [r1, #0x00]
	ldr r1, _0800C234 @ =0x02039B94
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _0800C248
_0800C21C: .4byte 0x08128304
_0800C220: .4byte 0x020348C0
_0800C224: .4byte 0x08130E34
_0800C228: .4byte 0x020348C1
_0800C22C: .4byte 0x020348C4
_0800C230: .4byte 0x08130DE0
_0800C234: .4byte 0x02039B94
_0800C238:
	ldr r2, _0800C294 @ =0x020348C1
	movs r0, #0x0E
	strb r0, [r2, #0x00]
	ldr r1, _0800C298 @ =0x020348C4
	ldr r0, _0800C29C @ =0x08130BE8
	str r0, [r1, #0x00]
	ldr r0, _0800C2A0 @ =0x02039B94
	strb r4, [r0, #0x00]
_0800C248:
	movs r6, #0x00
	movs r0, #0x00
	ldsb r0, [r2, r0]
	cmp r6, r0
	bge _0800C2CC
	ldr r0, _0800C298 @ =0x020348C4
	mov r8, r0
	movs r7, #0x00
	ldr r1, _0800C2A4 @ =0x03006C10
	mov r9, r1
_0800C25C:
	lsls r4, r6, #0x03
	lsrs r5, r7, #0x18
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r0, r4, r0
	ldr r3, [r0, #0x00]
	movs r0, #0x0C
	adds r1, r5, #0x0
	movs r2, #0x02
	bl func_0805FCB0
	mov r1, r8
	ldr r0, [r1, #0x00]
	adds r4, r4, r0
	mov r1, r9
	ldr r0, [r1, #0x00]
	ldr r1, [r4, #0x04]
	ands r0, r1
	cmp r0, #0x00
	beq _0800C2AC
	movs r0, #0x78
	adds r1, r5, #0x0
	movs r2, #0x02
	ldr r3, _0800C2A8 @ =0x08130E38
	bl func_0805FCB0
	b _0800C2B8
	.byte 0x00, 0x00
_0800C294: .4byte 0x020348C1
_0800C298: .4byte 0x020348C4
_0800C29C: .4byte 0x08130BE8
_0800C2A0: .4byte 0x02039B94
_0800C2A4: .4byte 0x03006C10
_0800C2A8: .4byte 0x08130E38
_0800C2AC:
	movs r0, #0x78
	adds r1, r5, #0x0
	movs r2, #0x02
	ldr r3, _0800C2D8 @ =0x08130E40
	bl func_0805FCB0
_0800C2B8:
	movs r0, #0x90
	lsls r0, r0, #0x14
	adds r7, r7, r0
	adds r6, #0x01
	ldr r0, _0800C2DC @ =0x020348C1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r6, r0
	blt _0800C25C
_0800C2CC:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800C2D8: .4byte 0x08130E40
_0800C2DC: .4byte 0x020348C1
	thumb_func_start mode_debflag_1
mode_debflag_1: @ 0800C2E0
	push {r4, r5, lr}
	ldr r4, _0800C320 @ =0x020348C0
	ldrb r5, [r4, #0x00]
	bl func_0800139C
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _0800C2F8
	ldrb r0, [r4, #0x00]
	subs r0, #0x01
	strb r0, [r4, #0x00]
_0800C2F8:
	bl func_0800139C
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _0800C30A
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
_0800C30A:
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r5, r0
	beq _0800C364
	adds r1, r0, #0x0
	cmp r1, #0x00
	bge _0800C328
	ldr r0, _0800C324 @ =0x020348C1
	ldrb r0, [r0, #0x00]
	subs r0, #0x01
	b _0800C336
_0800C320: .4byte 0x020348C0
_0800C324: .4byte 0x020348C1
_0800C328:
	ldr r0, _0800C3A8 @ =0x020348C1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _0800C338
	movs r0, #0x00
_0800C336:
	strb r0, [r4, #0x00]
_0800C338:
	lsls r1, r5, #0x03
	adds r1, r1, r5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _0800C3AC @ =0x08130E48
	movs r0, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	ldr r0, _0800C3B0 @ =0x020348C0
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #0x03
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _0800C3B4 @ =0x08130E34
	movs r0, #0x00
	movs r2, #0x02
	bl func_0805FCB0
_0800C364:
	bl func_08001390
	movs r1, #0x30
	ands r1, r0
	cmp r1, #0x00
	beq _0800C3DA
	ldr r1, _0800C3B8 @ =0x020348C4
	ldr r3, _0800C3B0 @ =0x020348C0
	movs r0, #0x00
	ldsb r0, [r3, r0]
	lsls r0, r0, #0x03
	ldr r1, [r1, #0x00]
	adds r1, r1, r0
	ldr r2, _0800C3BC @ =0x03006C10
	ldr r0, [r2, #0x00]
	ldr r1, [r1, #0x04]
	eors r0, r1
	str r0, [r2, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0800C3C4
	movs r0, #0x00
	ldsb r0, [r3, r0]
	lsls r1, r0, #0x03
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _0800C3C0 @ =0x08130E38
	movs r0, #0x78
	movs r2, #0x02
	bl func_0805FCB0
	b _0800C3DA
	.byte 0x00, 0x00
_0800C3A8: .4byte 0x020348C1
_0800C3AC: .4byte 0x08130E48
_0800C3B0: .4byte 0x020348C0
_0800C3B4: .4byte 0x08130E34
_0800C3B8: .4byte 0x020348C4
_0800C3BC: .4byte 0x03006C10
_0800C3C0: .4byte 0x08130E38
_0800C3C4:
	movs r0, #0x00
	ldsb r0, [r3, r0]
	lsls r1, r0, #0x03
	adds r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _0800C3F4 @ =0x08130E40
	movs r0, #0x78
	movs r2, #0x02
	bl func_0805FCB0
_0800C3DA:
	bl func_08001390
	movs r1, #0x0F
	ands r1, r0
	cmp r1, #0x00
	beq _0800C40C
	ldr r0, _0800C3F8 @ =0x02039B94
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C3FC
	bl func_080E04EC
	b _0800C416
_0800C3F4: .4byte 0x08130E40
_0800C3F8: .4byte 0x02039B94
_0800C3FC:
	ldr r0, _0800C408 @ =0x09ECEB64
	movs r1, #0x00
	bl func_080010CC
	b _0800C416
	.byte 0x00, 0x00
_0800C408: .4byte 0x09ECEB64
_0800C40C:
	movs r0, #0x00
	bl func_080605A4
	bl func_08060598
_0800C416:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_start mode_debflag_2
mode_debflag_2: @ 0800C41C
	push {lr}
	bl func_080609A0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
