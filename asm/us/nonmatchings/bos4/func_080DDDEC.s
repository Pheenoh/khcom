.syntax unified
	.align 2, 0
	.global func_080DDDEC
	.thumb
	.thumb_func
	.type func_080DDDEC, %function
func_080DDDEC: @ 080DDDEC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	ldrb r3, [r5, #0x04]
	cmp r3, #0x00
	bne _080DDE28
	ldrh r0, [r5, #0x00]
	adds r0, #0x01
	strh r0, [r5, #0x00]
	ldrh r1, [r5, #0x02]
	ldr r2, [r6, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #0x00]
	cmp r0, r1
	bls _080DDE28
	strh r3, [r5, #0x00]
	ldrh r0, [r5, #0x02]
	adds r0, #0x01
	strh r0, [r5, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x04]
	cmp r0, r1
	bcc _080DDE28
	strh r3, [r5, #0x02]
_080DDE28:
	cmp r7, #0x00
	bne _080DDE62
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080DDE38
	ldrb r0, [r5, #0x04]
	cmp r0, #0x00
	beq _080DDE6C
_080DDE38:
	ldrh r2, [r6, #0x10]
	ldrh r0, [r5, #0x02]
	ldr r1, [r6, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldrh r0, [r0, #0x02]
	muls r0, r2
	ldr r4, [r6, #0x08]
	adds r4, r4, r0
	ldr r0, [r6, #0x14]
	bl GetBgCharBase
	adds r1, r0, #0x0
	ldrh r0, [r6, #0x0C]
	adds r1, r1, r0
	ldrh r2, [r6, #0x0E]
	adds r0, r4, #0x0
	bl RequestDma3Copy
	strb r7, [r5, #0x04]
	b _080DDE6C
_080DDE62:
	ldrh r0, [r5, #0x00]
	cmp r0, #0x00
	bne _080DDE6C
	movs r0, #0x01
	strb r0, [r5, #0x04]
_080DDE6C:
	adds r0, r7, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
