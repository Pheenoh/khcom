.syntax unified
	.align 2, 0
	.global func_080C9D98
	.thumb
	.thumb_func
	.type func_080C9D98, %function
func_080C9D98: @ 080C9D98
	ldr r0, _080C9DA4 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x0D
	beq _080C9DA8
	movs r0, #0x00
	b _080C9DAA
_080C9DA4: .4byte 0x02034DAC
_080C9DA8:
	movs r0, #0x01
_080C9DAA:
	bx lr
.syntax divided
