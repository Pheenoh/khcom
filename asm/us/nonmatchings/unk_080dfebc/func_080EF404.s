.syntax unified
	.align 2, 0
	.global func_080EF404
	.thumb
	.thumb_func
	.type func_080EF404, %function
func_080EF404: @ 080EF404
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r7, r1, #0x0
	adds r6, r2, #0x0
	adds r4, r5, #0x0
	adds r4, #0x08
	ldrh r1, [r5, #0x04]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080EF42E
	adds r0, r7, #0x0
	movs r1, #0x05
	bl func_0811D5EC
	adds r7, r0, #0x0
	adds r0, r6, #0x0
	movs r1, #0x05
	bl func_0811D5EC
	adds r6, r0, #0x0
_080EF42E:
	ldr r2, _080EF474 @ =0x08121400
	ldrb r0, [r4, #0x14]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r3, #0x00
	ldsh r1, [r0, r3]
	ldr r0, [r4, #0x10]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x08]
	adds r0, r0, r1
	str r0, [r5, #0x08]
	ldrb r0, [r4, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	ldr r2, [r4, #0x10]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x04]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	adds r2, r2, r7
	str r2, [r4, #0x10]
	cmp r2, r6
	ble _080EF46C
	str r6, [r4, #0x10]
_080EF46C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080EF474: .4byte 0x08121400
.syntax divided
