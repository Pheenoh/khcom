.syntax unified
	.align 2, 0
	.global func_080D85A8
	.thumb
	.thumb_func
	.type func_080D85A8, %function
func_080D85A8: @ 080D85A8
	cmp r0, #0x08
	bhi _080D85B0
	movs r0, #0x01
	b _080D85BC
_080D85B0:
	subs r0, #0x09
	cmp r0, #0x25
	bls _080D85BA
	movs r0, #0x03
	b _080D85BC
_080D85BA:
	movs r0, #0x02
_080D85BC:
	bx lr
	.byte 0x00, 0x00
.syntax divided
