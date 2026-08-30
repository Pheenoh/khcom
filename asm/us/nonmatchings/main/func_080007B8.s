.syntax unified
	.align 2, 0
	.global func_080007B8
	.thumb
	.thumb_func
	.type func_080007B8, %function
func_080007B8: @ 080007B8
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080007CE
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bls _080007CE
	ldr r0, [r1, #0x04]
	cmp r2, r0
	bcs _080007CE
	movs r0, #0x01
	b _080007D0
_080007CE:
	movs r0, #0x00
_080007D0:
	bx lr
	.byte 0x00, 0x00
.syntax divided
