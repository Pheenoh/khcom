.syntax unified
	.align 2, 0
	.global func_080ADD58
	.thumb
	.thumb_func
	.type func_080ADD58, %function
func_080ADD58: @ 080ADD58
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080ADDA2
	ldr r0, [r2, #0x00]
	ldr r1, [r0, #0x48]
	ldr r0, [r2, #0x04]
	ldr r3, [r0, #0x48]
	ldr r0, [r2, #0x08]
	ldr r2, [r0, #0x48]
	ldr r0, [r1, #0x24]
	cmp r0, #0x12
	beq _080ADDA2
	ldr r0, [r3, #0x24]
	cmp r0, #0x12
	beq _080ADDA2
	ldr r0, [r2, #0x24]
	cmp r0, #0x12
	beq _080ADDA2
	adds r0, r1, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADDA2
	adds r0, r3, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADDA2
	adds r0, r2, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADDA2
	movs r0, #0x01
	b _080ADDA4
_080ADDA2:
	movs r0, #0x00
_080ADDA4:
	bx lr
	.byte 0x00, 0x00
.syntax divided
