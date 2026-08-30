.syntax unified
	.align 2, 0
	.global func_080C9E4C
	.thumb
	.thumb_func
	.type func_080C9E4C, %function
func_080C9E4C: @ 080C9E4C
	ldr r0, _080C9E58 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x21
	bne _080C9E5C
	movs r0, #0x00
	b _080C9E6E
_080C9E58: .4byte 0x02034DAC
_080C9E5C:
	cmp r0, #0x22
	bne _080C9E64
	movs r0, #0x01
	b _080C9E6E
_080C9E64:
	cmp r0, #0x23
	beq _080C9E6C
	movs r0, #0x03
	b _080C9E6E
_080C9E6C:
	movs r0, #0x02
_080C9E6E:
	bx lr
.syntax divided
