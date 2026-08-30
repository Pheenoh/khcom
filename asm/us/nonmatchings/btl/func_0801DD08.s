.syntax unified
	.align 2, 0
	.global func_0801DD08
	.thumb
	.thumb_func
	.type func_0801DD08, %function
func_0801DD08: @ 0801DD08
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801DD88
	subs r1, #0x4E
	adds r0, r3, r1
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x78]
	cmp r5, #0x00
	beq _0801DD7E
	ldr r0, _0801DD54 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801DD5C
	ldr r1, [r3, #0x44]
	ldr r0, [r5, #0x04]
	adds r0, r1, r0
	asrs r4, r0, #0x01
	adds r1, r1, r4
	asrs r4, r1, #0x01
	ldr r6, [r3, #0x48]
	ldr r2, [r3, #0x4C]
	ldr r0, _0801DD58 @ =0xFFFFCE00
	cmp r2, r0
	bge _0801DD74
	adds r2, r0, #0x0
	b _0801DD74
_0801DD54: .4byte 0x02039B84
_0801DD58: .4byte 0xFFFFCE00
_0801DD5C:
	ldr r0, [r3, #0x44]
	ldr r1, [r5, #0x04]
	adds r0, r0, r1
	asrs r4, r0, #0x01
	ldr r0, [r3, #0x48]
	ldr r1, [r5, #0x08]
	adds r0, r0, r1
	asrs r6, r0, #0x01
	ldr r0, [r3, #0x4C]
	ldr r1, [r5, #0x0C]
	adds r0, r0, r1
	asrs r2, r0, #0x01
_0801DD74:
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	bl func_0802F284
	b _0801DD88
_0801DD7E:
	ldr r0, [r3, #0x44]
	ldr r1, [r3, #0x48]
	ldr r2, [r3, #0x4C]
	bl func_0802F284
_0801DD88:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
