.syntax unified
	.align 2, 0
	.global func_080CFCC0
	.thumb
	.thumb_func
	.type func_080CFCC0, %function
func_080CFCC0: @ 080CFCC0
	ldr r0, _080CFCCC @ =0x02034E1C
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _080CFCD0
	movs r0, #0x00
	b _080CFCD2
_080CFCCC: .4byte 0x02034E1C
_080CFCD0:
	movs r0, #0x01
_080CFCD2:
	bx lr
.syntax divided
