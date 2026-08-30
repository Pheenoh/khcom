.syntax unified
	.align 2, 0
	.global func_080AE134
	.thumb
	.thumb_func
	.type func_080AE134, %function
func_080AE134: @ 080AE134
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080AE162
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r1, [r0, #0x1C]
	ldr r0, [r2, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r3, [r0, #0x1C]
	ldr r0, [r2, #0x08]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r1, #0x1F
	bne _080AE162
	cmp r3, #0x17
	bne _080AE162
	cmp r0, #0x00
	bne _080AE162
	movs r0, #0x01
	b _080AE164
_080AE162:
	movs r0, #0x00
_080AE164:
	bx lr
	.byte 0x00, 0x00
.syntax divided
