.syntax unified
	.align 2, 0
	.global func_080CD198
	.thumb
	.thumb_func
	.type func_080CD198, %function
func_080CD198: @ 080CD198
	push {lr}
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x28
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0A
	bl __udivsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _080CD1CE
	cmp r0, #0x01
	bgt _080CD1C4
	cmp r0, #0x00
	beq _080CD1CA
	b _080CD1D6
_080CD1C4:
	cmp r0, #0x02
	beq _080CD1D2
	b _080CD1D6
_080CD1CA:
	movs r0, #0x00
	b _080CD1D8
_080CD1CE:
	movs r0, #0x02
	b _080CD1D8
_080CD1D2:
	movs r0, #0x04
	b _080CD1D8
_080CD1D6:
	movs r0, #0x06
_080CD1D8:
	pop {r1}
	bx r1
.syntax divided
