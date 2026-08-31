.syntax unified
	.align 2, 0
	.global GetRandom
	.thumb
	.thumb_func
	.type GetRandom, %function
GetRandom: @ 080065A4
	push {r4, lr}
	ldr r3, _080065F4 @ =0x02034030
	ldr r1, [r3, #0x04]
	lsls r1, r1, #0x01
	ldr r2, [r3, #0x00]
	movs r4, #0x80
	lsls r4, r4, #0x18
	cmp r2, #0x00
	bge _080065B8
	adds r1, #0x01
_080065B8:
	lsls r1, r1, #0x01
	movs r0, #0x80
	lsls r0, r0, #0x17
	ands r2, r0
	cmp r2, #0x00
	beq _080065C6
	adds r1, #0x01
_080065C6:
	ldr r0, [r3, #0x0C]
	lsls r0, r0, #0x01
	str r0, [r3, #0x0C]
	ldr r2, [r3, #0x08]
	ands r4, r2
	cmp r4, #0x00
	beq _080065D8
	adds r0, #0x01
	str r0, [r3, #0x0C]
_080065D8:
	ldr r0, [r3, #0x0C]
	eors r1, r0
	str r2, [r3, #0x0C]
	ldr r0, [r3, #0x04]
	str r0, [r3, #0x08]
	ldr r0, [r3, #0x00]
	str r0, [r3, #0x04]
	str r1, [r3, #0x00]
	ldr r0, _080065F8 @ =0x00007FFF
	ands r1, r0
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
_080065F4: .4byte 0x02034030
_080065F8: .4byte 0x00007FFF
.syntax divided
