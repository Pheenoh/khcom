.syntax unified
	.align 2, 0
	.global func_080008A8
	.thumb
	.thumb_func
	.type func_080008A8, %function
func_080008A8: @ 080008A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	cmp r5, #0x00
	beq _080008C8
	adds r5, #0x3F
	movs r0, #0x20
	negs r0, r0
	ands r5, r0
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080007D4
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080008CC
_080008C8:
	movs r0, #0x00
	b _08000912
_080008CC:
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r2, [r4, #0x00]
	cmp r2, r0
	bge _080008E0
	adds r5, r2, #0x0
	adds r0, r4, #0x0
	bl func_080007A8
	b _080008F4
_080008E0:
	adds r1, r4, #0x0
	subs r0, r2, r5
	str r0, [r4, #0x00]
	adds r4, r4, r0
	ldr r0, [r1, #0x10]
	str r0, [r4, #0x10]
	str r1, [r4, #0x0C]
	str r4, [r1, #0x10]
	ldr r0, [r4, #0x10]
	str r4, [r0, #0x0C]
_080008F4:
	negs r0, r5
	str r0, [r4, #0x00]
	movs r0, #0x00
	str r0, [r4, #0x04]
	str r0, [r4, #0x08]
	ldrb r0, [r6, #0x08]
	cmp r0, #0x00
	beq _08000906
	movs r0, #0x01
_08000906:
	str r0, [r4, #0x14]
	ldr r0, [r6, #0x0C]
	str r0, [r4, #0x18]
	str r4, [r4, #0x1C]
	adds r0, r4, #0x0
	adds r0, #0x20
_08000912:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
