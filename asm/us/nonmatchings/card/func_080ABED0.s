.syntax unified
	.align 2, 0
	.global func_080ABED0
	.thumb
	.thumb_func
	.type func_080ABED0, %function
func_080ABED0: @ 080ABED0
	ldr r0, _080ABEE8 @ =0x02039DD4
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xE0
	ldr r0, [r0, #0x00]
	ldr r1, _080ABEEC @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0x00
	bne _080ABEF0
	movs r0, #0x00
	b _080ABEF6
	.byte 0x00, 0x00
_080ABEE8: .4byte 0x02039DD4
_080ABEEC: .4byte 0x00FFFF00
_080ABEF0:
	adds r0, r2, #0x0
	adds r0, #0xDD
	ldrb r0, [r0, #0x00]
_080ABEF6:
	bx lr
.syntax divided
