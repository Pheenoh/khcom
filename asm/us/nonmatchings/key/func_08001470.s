.syntax unified
	.align 2, 0
	.global func_08001470
	.thumb
	.thumb_func
	.type func_08001470, %function
func_08001470: @ 08001470
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r1, #0x0
	cmp r1, #0x10
	beq _080014C8
	cmp r1, #0x10
	bgt _08001498
	cmp r1, #0x02
	beq _08001510
	cmp r1, #0x02
	bgt _0800148E
	cmp r1, #0x01
	beq _08001504
	b _0800152C
_0800148E:
	cmp r1, #0x04
	beq _08001528
	cmp r1, #0x08
	beq _0800151C
	b _0800152C
_08001498:
	cmp r1, #0x80
	beq _080014E0
	cmp r1, #0x80
	bgt _080014AA
	cmp r1, #0x20
	beq _080014BC
	cmp r1, #0x40
	beq _080014D4
	b _0800152C
_080014AA:
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r2, r1
	beq _080014F8
	movs r1, #0x80
	lsls r1, r1, #0x02
	cmp r2, r1
	beq _080014EC
	b _0800152C
_080014BC:
	ldr r0, _080014C4 @ =0x02034008
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_080014C4: .4byte 0x02034008
_080014C8:
	ldr r0, _080014D0 @ =0x02034009
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_080014D0: .4byte 0x02034009
_080014D4:
	ldr r0, _080014DC @ =0x0203400A
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_080014DC: .4byte 0x0203400A
_080014E0:
	ldr r0, _080014E8 @ =0x0203400B
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_080014E8: .4byte 0x0203400B
_080014EC:
	ldr r0, _080014F4 @ =0x0203400E
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_080014F4: .4byte 0x0203400E
_080014F8:
	ldr r0, _08001500 @ =0x0203400F
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_08001500: .4byte 0x0203400F
_08001504:
	ldr r0, _0800150C @ =0x0203400C
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_0800150C: .4byte 0x0203400C
_08001510:
	ldr r0, _08001518 @ =0x0203400D
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_08001518: .4byte 0x0203400D
_0800151C:
	ldr r0, _08001524 @ =0x02034010
	ldrb r0, [r0, #0x00]
	b _0800152C
	.byte 0x00, 0x00
_08001524: .4byte 0x02034010
_08001528:
	ldr r0, _08001530 @ =0x02034011
	ldrb r0, [r0, #0x00]
_0800152C:
	bx lr
	.byte 0x00, 0x00
_08001530: .4byte 0x02034011
.syntax divided
