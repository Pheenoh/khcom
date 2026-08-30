.syntax unified
	.align 2, 0
	.global func_080E5B90
	.thumb
	.thumb_func
	.type func_080E5B90, %function
func_080E5B90: @ 080E5B90
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldrh r1, [r5, #0x14]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _080E5BA8
	adds r0, r4, #0x0
	bl func_080E5968
	b _080E5BBE
_080E5BA8:
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080E5BB8
	adds r0, r4, #0x0
	bl func_080E5938
	b _080E5BBE
_080E5BB8:
	adds r0, r4, #0x0
	bl func_080E590C
_080E5BBE:
	bl func_080065A4
	lsls r0, r0, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x0A
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #0x01
	beq _080E5BE4
	cmp r1, #0x01
	bgt _080E5BDA
	cmp r1, #0x00
	beq _080E5BE0
	b _080E5BEC
_080E5BDA:
	cmp r1, #0x02
	beq _080E5BE8
	b _080E5BEC
_080E5BE0:
	movs r0, #0xAD
	b _080E5BEE
_080E5BE4:
	movs r0, #0x53
	b _080E5BEE
_080E5BE8:
	movs r0, #0xD3
	b _080E5BEE
_080E5BEC:
	movs r0, #0x2D
_080E5BEE:
	strb r0, [r4, #0x18]
	movs r0, #0x00
	str r0, [r4, #0x1C]
	str r5, [r4, #0x00]
	str r0, [r4, #0x04]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
