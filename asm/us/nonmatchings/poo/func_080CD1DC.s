.syntax unified
	.align 2, 0
	.global func_080CD1DC
	.thumb
	.thumb_func
	.type func_080CD1DC, %function
func_080CD1DC: @ 080CD1DC
	cmp r0, #0x00
	bne _080CD1E4
	movs r0, #0x01
	b _080CD1F6
_080CD1E4:
	cmp r0, #0x02
	bhi _080CD1EC
	movs r0, #0x03
	b _080CD1F6
_080CD1EC:
	cmp r0, #0x04
	bls _080CD1F4
	movs r0, #0x07
	b _080CD1F6
_080CD1F4:
	movs r0, #0x05
_080CD1F6:
	bx lr
.syntax divided
