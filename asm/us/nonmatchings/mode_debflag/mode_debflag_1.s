.syntax unified
	.align 2, 0
	.global mode_debflag_1
	.thumb
	.thumb_func
	.type mode_debflag_1, %function
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
.syntax divided
