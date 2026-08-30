.syntax unified
	.align 2, 0
	.global func_080DF750
	.thumb
	.thumb_func
	.type func_080DF750, %function
func_080DF750: @ 080DF750
	ldr r0, _080DF78C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DF794
	ldr r1, _080DF790 @ =0x0203C590
	ldrb r0, [r1, #0x00]
	cmp r0, #0x16
	bhi _080DF7A8
	cmp r0, #0x13
	bhi _080DF7B0
	cmp r0, #0x11
	bhi _080DF7B8
	cmp r0, #0x0F
	bhi _080DF7C0
	cmp r0, #0x0D
	bhi _080DF7C8
	cmp r0, #0x0B
	bhi _080DF7D0
	cmp r0, #0x09
	bhi _080DF7D8
	cmp r0, #0x07
	bhi _080DF7E0
	cmp r0, #0x05
	bhi _080DF7E8
	ldrb r0, [r1, #0x00]
	cmp r0, #0x03
	bhi _080DF7F2
	b _080DF7F6
_080DF78C: .4byte 0x02039BB0
_080DF790: .4byte 0x0203C590
_080DF794:
	ldr r1, _080DF7A0 @ =0x0203C590
	ldrb r0, [r1, #0x00]
	cmp r0, #0x18
	bls _080DF7A4
	movs r0, #0x0C
	b _080DF800
_080DF7A0: .4byte 0x0203C590
_080DF7A4:
	cmp r0, #0x15
	bls _080DF7AC
_080DF7A8:
	movs r0, #0x0B
	b _080DF800
_080DF7AC:
	cmp r0, #0x13
	bls _080DF7B4
_080DF7B0:
	movs r0, #0x0A
	b _080DF800
_080DF7B4:
	cmp r0, #0x11
	bls _080DF7BC
_080DF7B8:
	movs r0, #0x09
	b _080DF800
_080DF7BC:
	cmp r0, #0x0F
	bls _080DF7C4
_080DF7C0:
	movs r0, #0x08
	b _080DF800
_080DF7C4:
	cmp r0, #0x0D
	bls _080DF7CC
_080DF7C8:
	movs r0, #0x07
	b _080DF800
_080DF7CC:
	cmp r0, #0x0B
	bls _080DF7D4
_080DF7D0:
	movs r0, #0x06
	b _080DF800
_080DF7D4:
	cmp r0, #0x09
	bls _080DF7DC
_080DF7D8:
	movs r0, #0x05
	b _080DF800
_080DF7DC:
	cmp r0, #0x07
	bls _080DF7E4
_080DF7E0:
	movs r0, #0x04
	b _080DF800
_080DF7E4:
	cmp r0, #0x05
	bls _080DF7EC
_080DF7E8:
	movs r0, #0x03
	b _080DF800
_080DF7EC:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x03
	bls _080DF7F6
_080DF7F2:
	movs r0, #0x02
	b _080DF800
_080DF7F6:
	cmp r0, #0x01
	bls _080DF7FE
	movs r0, #0x01
	b _080DF800
_080DF7FE:
	movs r0, #0x00
_080DF800:
	bx lr
	.byte 0x00, 0x00
.syntax divided
