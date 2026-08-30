.syntax unified
	.align 2, 0
	.global func_080ADEAC
	.thumb
	.thumb_func
	.type func_080ADEAC, %function
func_080ADEAC: @ 080ADEAC
	push {r4, lr}
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #0x03
	bne _080ADEE2
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x48]
	ldrh r2, [r0, #0x1C]
	ldr r0, [r3, #0x04]
	ldr r0, [r0, #0x48]
	ldr r1, [r3, #0x08]
	ldr r1, [r1, #0x48]
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	adds r1, #0x2A
	ldrb r1, [r1, #0x00]
	cmp r0, #0x00
	bne _080ADEE2
	cmp r1, #0x00
	bne _080ADEE2
	cmp r2, r4
	bne _080ADEE2
	movs r0, #0x01
	b _080ADEE4
_080ADEE2:
	movs r0, #0x00
_080ADEE4:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
