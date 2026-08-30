.syntax unified
	.align 2, 0
	.global func_0801E7D4
	.thumb
	.thumb_func
	.type func_0801E7D4, %function
func_0801E7D4: @ 0801E7D4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, _0801E814 @ =0x02039B84
	ldr r5, [r0, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801E832
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801E81C
	movs r0, #0x40
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801E84A
	ldr r0, _0801E818 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	b _0801E84C
_0801E814: .4byte 0x02039B84
_0801E818: .4byte 0x02039B9C
_0801E81C:
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801E84A
	ldr r0, [r5, #0x7C]
	b _0801E84C
_0801E832:
	movs r0, #0x40
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0801E84A
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	b _0801E84C
_0801E84A:
	movs r0, #0x00
_0801E84C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
