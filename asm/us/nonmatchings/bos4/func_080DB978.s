.syntax unified
	.align 2, 0
	.global func_080DB978
	.thumb
	.thumb_func
	.type func_080DB978, %function
func_080DB978: @ 080DB978
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	subs r0, #0x03
	cmp r0, #0x01
	bhi _080DB9C4
	ldr r0, _080DB9A0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r4, #0x28]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	ble _080DB9A8
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r2, #0x00]
	ldr r1, _080DB9A4 @ =0x09EF5130
	b _080DB9B2
	.byte 0x00, 0x00
_080DB9A0: .4byte 0x02039B84
_080DB9A4: .4byte 0x09EF5130
_080DB9A8:
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r2, #0x00]
	ldr r1, _080DB9C0 @ =0x09EF5190
_080DB9B2:
	cmp r0, r1
	bne _080DB9DC
	movs r0, #0x00
	bl func_080DD69C
	b _080DBA0A
	.byte 0x00, 0x00
_080DB9C0: .4byte 0x09EF5190
_080DB9C4:
	bl func_080DC510
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DB9F0
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r2, #0x00]
	ldr r1, _080DB9EC @ =0x09EF5100
	cmp r0, r1
	beq _080DBA0A
_080DB9DC:
	str r1, [r2, #0x00]
	movs r0, #0x00
	movs r2, #0x04
	movs r3, #0x03
	bl func_0800516C
	b _080DBA0A
	.byte 0x00, 0x00
_080DB9EC: .4byte 0x09EF5100
_080DB9F0:
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r2, #0x00]
	ldr r1, _080DBA10 @ =0x09EF5160
	cmp r0, r1
	beq _080DBA0A
	str r1, [r2, #0x00]
	movs r0, #0x00
	movs r2, #0x04
	movs r3, #0x03
	bl func_0800516C
_080DBA0A:
	pop {r4}
	pop {r0}
	bx r0
_080DBA10: .4byte 0x09EF5160
.syntax divided
