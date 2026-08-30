.syntax unified
	.align 2, 0
	.global func_080763D0
	.thumb
	.thumb_func
	.type func_080763D0, %function
func_080763D0: @ 080763D0
	ldr r0, _080763E8 @ =0x02034A98
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080763EC
	ldr r0, [r0, #0x78]
	movs r1, #0x80
	lsls r1, r1, #0x0D
	ands r0, r1
	cmp r0, #0x00
	beq _080763EC
	movs r0, #0x01
	b _080763EE
_080763E8: .4byte 0x02034A98
_080763EC:
	movs r0, #0x00
_080763EE:
	bx lr
.syntax divided
