.syntax unified
	.align 2, 0
	.global func_08073508
	.thumb
	.thumb_func
	.type func_08073508, %function
func_08073508: @ 08073508
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r0, #0x27
	ldrb r0, [r0, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, [r4, #0x3C]
	adds r5, r0, r1
	ldr r1, [r5, #0x08]
	cmp r1, #0x04
	beq _0807352C
	str r1, [r4, #0x20]
	ldr r0, _08073544 @ =0x09033C98
	lsls r1, r1, #0x01
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	str r0, [r4, #0x18]
_0807352C:
	ldrh r1, [r5, #0x14]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _08073548
	adds r1, r4, #0x0
	adds r1, #0x2F
	movs r0, #0x01
	b _0807354C
	.byte 0x00, 0x00
_08073544: .4byte 0x09033C98
_08073548:
	adds r1, r4, #0x0
	adds r1, #0x2F
_0807354C:
	strb r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x2C
	ldrb r1, [r5, #0x00]
	ldrb r2, [r5, #0x04]
	ldr r3, [r4, #0x20]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	bl func_08073E34
	ldr r0, [r5, #0x00]
	cmp r0, #0x3E
	bne _080735A0
	ldr r6, [r4, #0x40]
	cmp r6, #0x00
	beq _08073590
	movs r0, #0xB8
	lsls r0, r0, #0x06
	ldr r2, _08073588 @ =0x09033CB8
	ldr r1, [r4, #0x20]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r2, _0807358C @ =0xFFFFFE00
	adds r1, r1, r2
	adds r3, r4, #0x0
	adds r3, #0x40
	adds r2, r6, #0x0
	b _080735EA
	.byte 0x00, 0x00
_08073588: .4byte 0x09033CB8
_0807358C: .4byte 0xFFFFFE00
_08073590:
	movs r0, #0xB8
	lsls r0, r0, #0x06
	ldr r2, _0807359C @ =0x09033CB8
	ldr r1, [r4, #0x20]
	lsls r1, r1, #0x02
	b _080735DC
_0807359C: .4byte 0x09033CB8
_080735A0:
	ldr r6, [r4, #0x40]
	cmp r6, #0x00
	beq _080735D0
	ldr r0, _080735C4 @ =0x09033CA8
	ldr r1, [r4, #0x20]
	lsls r1, r1, #0x02
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	ldr r2, _080735C8 @ =0x09033CB8
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r2, _080735CC @ =0xFFFFFE00
	adds r1, r1, r2
	adds r3, r4, #0x0
	adds r3, #0x40
	adds r2, r6, #0x0
	b _080735EA
	.byte 0x00, 0x00
_080735C4: .4byte 0x09033CA8
_080735C8: .4byte 0x09033CB8
_080735CC: .4byte 0xFFFFFE00
_080735D0:
	ldr r0, _08073610 @ =0x09033CA8
	ldr r1, [r4, #0x20]
	lsls r1, r1, #0x02
	adds r0, r1, r0
	ldr r0, [r0, #0x00]
	ldr r2, _08073614 @ =0x09033CB8
_080735DC:
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r2, _08073618 @ =0xFFFFFE00
	adds r1, r1, r2
	ldr r2, [r5, #0x10]
	adds r3, r4, #0x0
	adds r3, #0x40
_080735EA:
	bl func_08064EF4
	adds r1, r4, #0x0
	adds r1, #0x26
	strb r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x25
	movs r1, #0x00
	strb r1, [r0, #0x00]
	subs r0, #0x01
	strb r1, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x29
	movs r0, #0x01
	strb r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08073610: .4byte 0x09033CA8
_08073614: .4byte 0x09033CB8
_08073618: .4byte 0xFFFFFE00
.syntax divided
