.syntax unified
	.align 2, 0
	.global func_080C9E70
	.thumb
	.thumb_func
	.type func_080C9E70, %function
func_080C9E70: @ 080C9E70
	ldr r0, _080C9E7C @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x0C
	beq _080C9E80
	movs r0, #0x00
	b _080C9E82
_080C9E7C: .4byte 0x02034DAC
_080C9E80:
	movs r0, #0x01
_080C9E82:
	bx lr
.syntax divided
