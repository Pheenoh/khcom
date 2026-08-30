.syntax unified
	.align 2, 0
	.global func_080CAB24
	.thumb
	.thumb_func
	.type func_080CAB24, %function
func_080CAB24: @ 080CAB24
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x14]
	cmp r0, #0x53
	beq _080CABB4
	cmp r0, #0x53
	bgt _080CAB40
	cmp r0, #0x2D
	beq _080CAB50
	cmp r0, #0x2D
	ble _080CABB4
	cmp r0, #0x40
	beq _080CAB7C
	b _080CABB4
_080CAB40:
	cmp r0, #0xAD
	beq _080CABB4
	cmp r0, #0xAD
	ble _080CABB4
	cmp r0, #0xC0
	beq _080CAB7C
	cmp r0, #0xD3
	bne _080CABB4
_080CAB50:
	ldr r3, _080CAB78 @ =0x08121400
	ldrb r1, [r4, #0x14]
	lsls r0, r1, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r2, [r0, r5]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x02
	ldr r2, [r4, #0x00]
	adds r5, r2, r0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r2, #0x00
	ldsh r0, [r1, r2]
	negs r0, r0
	lsls r1, r0, #0x01
	b _080CABD8
	.byte 0x00, 0x00
_080CAB78: .4byte 0x08121400
_080CAB7C:
	ldr r3, _080CABB0 @ =0x08121400
	ldrb r1, [r4, #0x14]
	lsls r0, r1, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r2, [r0, r5]
	lsls r0, r2, #0x03
	subs r0, r0, r2
	lsls r0, r0, #0x02
	subs r0, r0, r2
	ldr r2, [r4, #0x00]
	adds r5, r2, r0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r0, #0x00
	ldsh r1, [r1, r0]
	negs r1, r1
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x02
	subs r0, r0, r1
	ldr r1, [r4, #0x04]
	adds r1, r1, r0
	b _080CABE0
	.byte 0x00, 0x00
_080CABB0: .4byte 0x08121400
_080CABB4:
	ldr r3, _080CABF4 @ =0x08121400
	ldrb r1, [r4, #0x14]
	lsls r0, r1, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r2, [r0, r5]
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x02
	ldr r2, [r4, #0x00]
	adds r5, r2, r0
	adds r1, #0x40
	lsls r1, r1, #0x01
	adds r1, r1, r3
	movs r2, #0x00
	ldsh r0, [r1, r2]
	negs r0, r0
	lsls r1, r0, #0x02
_080CABD8:
	adds r1, r1, r0
	lsls r1, r1, #0x02
	ldr r0, [r4, #0x04]
	adds r1, r0, r1
_080CABE0:
	ldr r2, [r4, #0x08]
	ldr r0, _080CABF8 @ =0xFFFFF800
	adds r2, r2, r0
	adds r0, r5, #0x0
	bl func_080C7684
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CABF4: .4byte 0x08121400
_080CABF8: .4byte 0xFFFFF800
.syntax divided
