.syntax unified
	.align 2, 0
	.global func_080AE014
	.thumb
	.thumb_func
	.type func_080AE014, %function
func_080AE014: @ 080AE014
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080AE078
	ldr r3, [r5, #0x00]
	ldr r0, [r3, #0x48]
	ldrh r1, [r0, #0x1E]
	ldr r2, [r5, #0x04]
	ldr r4, [r2, #0x48]
	ldrh r6, [r4, #0x1E]
	movs r0, #0x04
	ands r1, r0
	cmp r1, #0x00
	beq _080AE04C
	cmp r6, #0x00
	bne _080AE04C
	adds r0, r4, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080AE04C
	ldr r0, [r5, #0x08]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, #0x2B
	beq _080AE074
_080AE04C:
	ldr r0, [r3, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, #0x1B
	bne _080AE078
	ldr r0, [r2, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, #0x13
	bne _080AE078
	ldr r0, [r5, #0x08]
	ldr r3, [r0, #0x48]
	adds r0, r3, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080AE078
	ldrh r1, [r3, #0x1E]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080AE078
_080AE074:
	movs r0, #0x01
	b _080AE07A
_080AE078:
	movs r0, #0x00
_080AE07A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
