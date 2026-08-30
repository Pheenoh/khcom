.syntax unified
	.align 2, 0
	.global func_080763F0
	.thumb
	.thumb_func
	.type func_080763F0, %function
func_080763F0: @ 080763F0
	ldr r0, _0807640C @ =0x02034A98
	ldr r1, [r0, #0x00]
	cmp r1, #0x00
	beq _08076428
	ldr r0, [r1, #0x78]
	ldr r1, _08076410 @ =0x01000044
	ands r0, r1
	cmp r0, r1
	bne _08076418
	ldr r0, _08076414 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE7
	movs r1, #0x01
	b _0807642E
_0807640C: .4byte 0x02034A98
_08076410: .4byte 0x01000044
_08076414: .4byte 0x02039DD4
_08076418:
	ldr r0, _08076424 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE7
	movs r1, #0x00
	b _0807642E
	.byte 0x00, 0x00
_08076424: .4byte 0x02039DD4
_08076428:
	ldr r0, _08076434 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xE7
_0807642E:
	strb r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08076434: .4byte 0x02039DD4
	.byte 0x70, 0x47, 0x00, 0x00
.syntax divided
