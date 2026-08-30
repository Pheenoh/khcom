.syntax unified
	.align 2, 0
	.global func_080AE1A8
	.thumb
	.thumb_func
	.type func_080AE1A8, %function
func_080AE1A8: @ 080AE1A8
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080AE1E2
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r1, [r0, #0x1C]
	ldr r0, [r2, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r3, [r0, #0x1C]
	ldr r0, [r2, #0x08]
	ldr r0, [r0, #0x48]
	adds r2, r0, #0x0
	adds r2, #0x2A
	ldrb r2, [r2, #0x00]
	cmp r1, #0x18
	bne _080AE1E2
	cmp r3, #0x13
	bne _080AE1E2
	cmp r2, #0x01
	bne _080AE1E2
	ldrh r1, [r0, #0x1E]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080AE1E2
	movs r0, #0x01
	b _080AE1E4
_080AE1E2:
	movs r0, #0x00
_080AE1E4:
	bx lr
	.byte 0x00, 0x00
.syntax divided
