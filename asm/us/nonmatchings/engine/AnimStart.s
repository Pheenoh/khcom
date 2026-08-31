.syntax unified
	.align 2, 0
	.global AnimStart
	.thumb
	.thumb_func
	.type AnimStart, %function
AnimStart: @ 080059A4
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r1, [r4, #0x00]
	lsls r0, r6, #0x02
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x0C]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	bne _080059C8
	str r0, [r4, #0x14]
	b _080059FA
_080059C8:
	adds r0, r1, #0x6
	str r0, [r4, #0x14]
	movs r0, #0x04
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	bne _080059F6
	strh r0, [r4, #0x0A]
	movs r0, #0x02
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x00
	beq _080059F4
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4, #0x0C]
	bl __umodsi3
_080059F4:
	strh r0, [r4, #0x0E]
_080059F6:
	strh r5, [r4, #0x08]
	strh r6, [r4, #0x10]
_080059FA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
