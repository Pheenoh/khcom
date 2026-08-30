.syntax unified
	.align 2, 0
	.global func_080C9D5C
	.thumb
	.thumb_func
	.type func_080C9D5C, %function
func_080C9D5C: @ 080C9D5C
	ldr r0, _080C9D68 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x27
	beq _080C9D6C
	movs r0, #0x00
	b _080C9D6E
_080C9D68: .4byte 0x02034DAC
_080C9D6C:
	movs r0, #0x01
_080C9D6E:
	bx lr
.syntax divided
