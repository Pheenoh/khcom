.syntax unified
	.align 2, 0
	.global func_080ADD04
	.thumb
	.thumb_func
	.type func_080ADD04, %function
func_080ADD04: @ 080ADD04
	push {r4, r5, r6, lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080ADD4E
	ldr r0, [r2, #0x00]
	ldr r1, [r0, #0x48]
	ldrh r6, [r1, #0x1C]
	ldr r0, [r2, #0x04]
	ldr r3, [r0, #0x48]
	ldrh r5, [r3, #0x1C]
	ldr r0, [r2, #0x08]
	ldr r2, [r0, #0x48]
	ldrh r4, [r2, #0x1C]
	adds r1, #0x2A
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080ADD4E
	adds r0, r3, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADD4E
	adds r0, r2, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADD4E
	cmp r6, r5
	beq _080ADD4E
	cmp r6, r4
	beq _080ADD4E
	cmp r5, r4
	beq _080ADD4E
	movs r0, #0x01
	b _080ADD50
_080ADD4E:
	movs r0, #0x00
_080ADD50:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
