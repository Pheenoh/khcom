.syntax unified
	.align 2, 0
	.global func_080AE080
	.thumb
	.thumb_func
	.type func_080AE080, %function
func_080AE080: @ 080AE080
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080AE0B0
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r1, [r0, #0x1C]
	ldr r0, [r2, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r3, [r0, #0x1C]
	ldr r0, [r2, #0x08]
	ldr r0, [r0, #0x48]
	ldrh r2, [r0, #0x1E]
	cmp r1, #0x1A
	bne _080AE0B0
	cmp r3, #0x1D
	bne _080AE0B0
	movs r0, #0x04
	ands r2, r0
	cmp r2, #0x00
	beq _080AE0B0
	movs r0, #0x01
	b _080AE0B2
_080AE0B0:
	movs r0, #0x00
_080AE0B2:
	bx lr
.syntax divided
