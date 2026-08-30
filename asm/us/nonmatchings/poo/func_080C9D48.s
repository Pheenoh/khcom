.syntax unified
	.align 2, 0
	.global func_080C9D48
	.thumb
	.thumb_func
	.type func_080C9D48, %function
func_080C9D48: @ 080C9D48
	ldr r0, _080C9D54 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x16
	beq _080C9D58
	movs r0, #0x00
	b _080C9D5A
_080C9D54: .4byte 0x02034DAC
_080C9D58:
	movs r0, #0x01
_080C9D5A:
	bx lr
.syntax divided
