.syntax unified
	.align 2, 0
	.global func_080ADF60
	.thumb
	.thumb_func
	.type func_080ADF60, %function
func_080ADF60: @ 080ADF60
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x03
	bne _080ADF8E
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r1, [r0, #0x1C]
	ldr r0, [r2, #0x04]
	ldr r0, [r0, #0x48]
	ldrh r0, [r0, #0x1C]
	cmp r1, #0x12
	bne _080ADF8E
	cmp r0, #0x1E
	bne _080ADF8E
	ldr r0, [r2, #0x08]
	ldr r0, [r0, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080ADF8E
	movs r0, #0x01
	b _080ADF90
_080ADF8E:
	movs r0, #0x00
_080ADF90:
	bx lr
	.byte 0x00, 0x00
.syntax divided
