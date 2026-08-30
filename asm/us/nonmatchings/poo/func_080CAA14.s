.syntax unified
	.align 2, 0
	.global func_080CAA14
	.thumb
	.thumb_func
	.type func_080CAA14, %function
func_080CAA14: @ 080CAA14
	push {r4, lr}
	adds r2, r0, #0x0
	ldr r3, _080CAA3C @ =0x0203C420
	adds r0, #0x66
	ldrh r0, [r0, #0x00]
	movs r4, #0x01
	adds r1, r4, #0x0
	ands r1, r0
	cmp r1, #0x00
	beq _080CAA40
	ldr r0, [r3, #0x0C]
	ldr r1, [r2, #0x78]
	cmp r0, r1
	bge _080CAA32
	adds r1, r0, #0x0
_080CAA32:
	adds r0, r2, #0x0
	adds r0, #0xAC
	strb r4, [r0, #0x00]
	b _080CAA48
	.byte 0x00, 0x00
_080CAA3C: .4byte 0x0203C420
_080CAA40:
	adds r0, r2, #0x0
	adds r0, #0xAC
	strb r1, [r0, #0x00]
	ldr r1, [r3, #0x0C]
_080CAA48:
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
