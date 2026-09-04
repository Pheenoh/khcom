.syntax unified
	.align 2, 0
	.global func_0801AD68
	.thumb
	.thumb_func
	.type func_0801AD68, %function
func_0801AD68: @ 0801AD68
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r4, [r6, #0x34]
	ldr r5, [r6, #0x38]
	movs r2, #0x01
	adds r0, r4, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _0801AD7E
	movs r0, #0x00
	b _0801ADA2
_0801AD7E:
	ldr r0, _0801ADA8 @ =0xFFFB9FDC
	adds r2, r4, #0x0
	ands r2, r0
	adds r3, r5, #0x0
	movs r4, #0x90
	movs r5, #0x00
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	ldr r0, [r6, #0x04]
	str r0, [r6, #0x14]
	ldr r0, [r6, #0x08]
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x0C]
	str r0, [r6, #0x1C]
	movs r0, #0x01
_0801ADA2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_0801ADA8: .4byte 0xFFFB9FDC
.syntax divided
