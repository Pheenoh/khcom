.syntax unified
	.align 2, 0
	.global func_080AE0B4
	.thumb
	.thumb_func
	.type func_080AE0B4, %function
func_080AE0B4: @ 080AE0B4
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080AE0EE
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
	cmp r1, #0x24
	bne _080AE0EE
	cmp r3, #0x26
	bne _080AE0EE
	cmp r2, #0x02
	bne _080AE0EE
	ldrh r1, [r0, #0x1E]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080AE0EE
	movs r0, #0x01
	b _080AE0F0
_080AE0EE:
	movs r0, #0x00
_080AE0F0:
	bx lr
	.byte 0x00, 0x00
.syntax divided
