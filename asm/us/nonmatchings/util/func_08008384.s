.syntax unified
	.align 2, 0
	.global func_08008384
	.thumb
	.thumb_func
	.type func_08008384, %function
func_08008384: @ 08008384
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r3, r1, #0x0
	cmp r1, #0x10
	beq _080083D4
	cmp r1, #0x10
	bgt _080083AC
	cmp r1, #0x02
	beq _080083EC
	cmp r1, #0x02
	bgt _080083A2
	cmp r1, #0x01
	beq _080083E8
	b _080083F6
_080083A2:
	cmp r1, #0x04
	beq _080083F4
	cmp r1, #0x08
	beq _080083F0
	b _080083F6
_080083AC:
	cmp r1, #0x80
	beq _080083DC
	cmp r1, #0x80
	bgt _080083BE
	cmp r1, #0x20
	beq _080083D0
	cmp r1, #0x40
	beq _080083D8
	b _080083F6
_080083BE:
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r3, r1
	beq _080083E4
	movs r1, #0x80
	lsls r1, r1, #0x02
	cmp r3, r1
	beq _080083E0
	b _080083F6
_080083D0:
	ldrb r0, [r2, #0x08]
	b _080083F6
_080083D4:
	ldrb r0, [r2, #0x09]
	b _080083F6
_080083D8:
	ldrb r0, [r2, #0x0A]
	b _080083F6
_080083DC:
	ldrb r0, [r2, #0x0B]
	b _080083F6
_080083E0:
	ldrb r0, [r2, #0x0E]
	b _080083F6
_080083E4:
	ldrb r0, [r2, #0x0F]
	b _080083F6
_080083E8:
	ldrb r0, [r2, #0x0C]
	b _080083F6
_080083EC:
	ldrb r0, [r2, #0x0D]
	b _080083F6
_080083F0:
	ldrb r0, [r2, #0x10]
	b _080083F6
_080083F4:
	ldrb r0, [r2, #0x11]
_080083F6:
	bx lr
.syntax divided
