.syntax unified
	.align 2, 0
	.global func_080CD1F8
	.thumb
	.thumb_func
	.type func_080CD1F8, %function
func_080CD1F8: @ 080CD1F8
	cmp r0, #0x00
	bne _080CD200
	movs r0, #0x20
	b _080CD212
_080CD200:
	cmp r0, #0x02
	bhi _080CD208
	movs r0, #0x18
	b _080CD212
_080CD208:
	cmp r0, #0x04
	bls _080CD210
	movs r0, #0x09
	b _080CD212
_080CD210:
	movs r0, #0x10
_080CD212:
	bx lr
.syntax divided
