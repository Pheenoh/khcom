.syntax unified
	.align 2, 0
	.global func_080ADE78
	.thumb
	.thumb_func
	.type func_080ADE78, %function
func_080ADE78: @ 080ADE78
	adds r1, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, r2
	bne _080ADEA8
	ldr r0, [r1, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r0, r3
	bne _080ADEA8
	ldr r0, [r1, #0x08]
	ldr r0, [r0, #0x48]
	ldrh r1, [r0, #0x1E]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _080ADEA8
	movs r0, #0x01
	b _080ADEAA
_080ADEA8:
	movs r0, #0x00
_080ADEAA:
	bx lr
.syntax divided
