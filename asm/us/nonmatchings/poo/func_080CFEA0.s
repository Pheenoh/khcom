.syntax unified
	.align 2, 0
	.global func_080CFEA0
	.thumb
	.thumb_func
	.type func_080CFEA0, %function
func_080CFEA0: @ 080CFEA0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r5, #0x94
	lsls r5, r5, #0x06
	movs r0, #0x06
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CFEB8
	movs r5, #0x84
	lsls r5, r5, #0x06
_080CFEB8:
	ldr r0, _080CFEF4 @ =0x02034E20
	ldr r2, [r0, #0x00]
	ldr r1, [r4, #0x00]
	ldr r0, [r2, #0x1C]
	subs r3, r1, r0
	ldr r1, [r4, #0x04]
	ldr r0, [r2, #0x20]
	subs r1, r1, r0
	adds r2, r1, r3
	ldr r0, _080CFEF8 @ =0xFFFFE600
	cmp r2, r0
	blt _080CFF04
	lsrs r0, r3, #0x1F
	adds r0, r3, r0
	asrs r0, r0, #0x01
	subs r1, r1, r0
	ldr r3, _080CFEFC @ =0xFFFFF480
	adds r0, r5, r3
	cmp r1, r0
	bgt _080CFF04
	movs r0, #0xC4
	lsls r0, r0, #0x06
	cmp r2, r0
	bgt _080CFF04
	ldr r0, _080CFF00 @ =0xFFFFEE80
	cmp r1, r0
	blt _080CFF04
	movs r0, #0x01
	b _080CFF06
	.byte 0x00, 0x00
_080CFEF4: .4byte 0x02034E20
_080CFEF8: .4byte 0xFFFFE600
_080CFEFC: .4byte 0xFFFFF480
_080CFF00: .4byte 0xFFFFEE80
_080CFF04:
	movs r0, #0x00
_080CFF06:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
