.syntax unified
	.align 2, 0
	.global func_080DFBDC
	.thumb
	.thumb_func
	.type func_080DFBDC, %function
func_080DFBDC: @ 080DFBDC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x0C]
	adds r5, r0, r1
	ldr r0, [r4, #0x00]
	adds r1, r5, #0x0
	bl func_080DFB8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _080DFBF8
	movs r0, #0x01
	b _080DFC1C
_080DFBF8:
	ldr r1, [r2, #0x08]
	ldr r0, [r4, #0x08]
	cmp r1, r0
	blt _080DFC0E
	ldr r1, [r2, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	beq _080DFC0E
	movs r0, #0x00
	b _080DFC1C
_080DFC0E:
	ldr r1, [r4, #0x00]
	adds r0, r2, #0x0
	adds r2, r5, #0x0
	bl func_080E86C8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080DFC1C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
