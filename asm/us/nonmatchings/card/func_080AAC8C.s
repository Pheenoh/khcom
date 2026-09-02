.syntax unified
	.align 2, 0
	.global func_080AAC8C
	.thumb
	.thumb_func
	.type func_080AAC8C, %function
func_080AAC8C: @ 080AAC8C
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	bl func_080857D4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080AACA0
	movs r0, #0x01
	b _080AACB8
_080AACA0:
	movs r0, #0x69
	bl m4aSongNumStart
	movs r1, #0xC5
	lsls r1, r1, #0x03
	adds r0, r4, r1
	ldr r1, _080AACC0 @ =0x09EE7FC0
	ldr r3, _080AACC4 @ =0x0000070D
	adds r2, r4, r3
	bl TaskCreate
	movs r0, #0x00
_080AACB8:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080AACC0: .4byte 0x09EE7FC0
_080AACC4: .4byte 0x0000070D
.syntax divided
