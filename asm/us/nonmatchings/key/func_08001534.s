.syntax unified
	.align 2, 0
	.global func_08001534
	.thumb
	.thumb_func
	.type func_08001534, %function
func_08001534: @ 08001534
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r1, #0x0
	cmp r1, #0x10
	beq _0800158C
	cmp r1, #0x10
	bgt _0800155C
	cmp r1, #0x02
	beq _080015D4
	cmp r1, #0x02
	bgt _08001552
	cmp r1, #0x01
	beq _080015C8
	b _080015F0
_08001552:
	cmp r1, #0x04
	beq _080015EC
	cmp r1, #0x08
	beq _080015E0
	b _080015F0
_0800155C:
	cmp r1, #0x80
	beq _080015A4
	cmp r1, #0x80
	bgt _0800156E
	cmp r1, #0x20
	beq _08001580
	cmp r1, #0x40
	beq _08001598
	b _080015F0
_0800156E:
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r2, r1
	beq _080015BC
	movs r1, #0x80
	lsls r1, r1, #0x02
	cmp r2, r1
	beq _080015B0
	b _080015F0
_08001580:
	ldr r0, _08001588 @ =0x02034012
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_08001588: .4byte 0x02034012
_0800158C:
	ldr r0, _08001594 @ =0x02034013
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_08001594: .4byte 0x02034013
_08001598:
	ldr r0, _080015A0 @ =0x02034014
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015A0: .4byte 0x02034014
_080015A4:
	ldr r0, _080015AC @ =0x02034015
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015AC: .4byte 0x02034015
_080015B0:
	ldr r0, _080015B8 @ =0x02034018
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015B8: .4byte 0x02034018
_080015BC:
	ldr r0, _080015C4 @ =0x02034019
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015C4: .4byte 0x02034019
_080015C8:
	ldr r0, _080015D0 @ =0x02034016
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015D0: .4byte 0x02034016
_080015D4:
	ldr r0, _080015DC @ =0x02034017
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015DC: .4byte 0x02034017
_080015E0:
	ldr r0, _080015E8 @ =0x0203401A
	ldrb r0, [r0, #0x00]
	b _080015F0
	.byte 0x00, 0x00
_080015E8: .4byte 0x0203401A
_080015EC:
	ldr r0, _080015F4 @ =0x0203401B
	ldrb r0, [r0, #0x00]
_080015F0:
	bx lr
	.byte 0x00, 0x00
_080015F4: .4byte 0x0203401B
.syntax divided
