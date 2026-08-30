.syntax unified
	.align 2, 0
	.global func_0800FDD0
	.thumb
	.thumb_func
	.type func_0800FDD0, %function
func_0800FDD0: @ 0800FDD0
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	cmp r5, #0xFA
	bne _0800FE2C
	ldr r3, _0800FE28 @ =0x02039BB0
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r2, r3, r0
	movs r0, #0x01
	negs r0, r0
	asrs r1, r0, #0x1F
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	movs r4, #0x9E
	lsls r4, r4, #0x01
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r4, #0x08
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r4, #0x08
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r4, #0x08
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r4, #0x08
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r4, #0x08
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r4, #0x08
	adds r2, r3, r4
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	b _0800FEF6
	.byte 0x00, 0x00
_0800FE28: .4byte 0x02039BB0
_0800FE2C:
	adds r0, r5, #0x0
	bl func_0800FF00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800FEF6
	cmp r5, #0x3F
	bhi _0800FE64
	ldr r6, _0800FE60 @ =0x02039BB0
	movs r0, #0x9A
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	b _0800FEE8
_0800FE60: .4byte 0x02039BB0
_0800FE64:
	cmp r5, #0x7F
	bhi _0800FE94
	subs r5, #0x40
	ldr r6, _0800FE90 @ =0x02039BB0
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	movs r2, #0xAE
	lsls r2, r2, #0x01
	b _0800FEE8
	.byte 0x00, 0x00
_0800FE90: .4byte 0x02039BB0
_0800FE94:
	cmp r5, #0xBF
	bhi _0800FEC4
	subs r5, #0x80
	ldr r6, _0800FEC0 @ =0x02039BB0
	movs r0, #0xA2
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	movs r2, #0xB2
	lsls r2, r2, #0x01
	b _0800FEE8
	.byte 0x00, 0x00
_0800FEC0: .4byte 0x02039BB0
_0800FEC4:
	subs r5, #0xC0
	ldr r6, _0800FEFC @ =0x02039BB0
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	bl _0811D57C
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	movs r2, #0xB6
	lsls r2, r2, #0x01
_0800FEE8:
	adds r4, r6, r2
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
_0800FEF6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0800FEFC: .4byte 0x02039BB0
.syntax divided
