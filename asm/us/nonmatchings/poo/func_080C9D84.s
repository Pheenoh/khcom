.syntax unified
	.align 2, 0
	.global func_080C9D84
	.thumb
	.thumb_func
	.type func_080C9D84, %function
func_080C9D84: @ 080C9D84
	ldr r0, _080C9D90 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x0E
	beq _080C9D94
	movs r0, #0x00
	b _080C9D96
_080C9D90: .4byte 0x02034DAC
_080C9D94:
	movs r0, #0x01
_080C9D96:
	bx lr
.syntax divided
