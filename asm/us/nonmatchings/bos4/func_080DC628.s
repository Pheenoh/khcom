.syntax unified
	.align 2, 0
	.global func_080DC628
	.thumb
	.thumb_func
	.type func_080DC628, %function
func_080DC628: @ 080DC628
	ldr r0, _080DC638 @ =0x02034F0C
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	beq _080DC63C
	movs r0, #0x00
	b _080DC63E
	.byte 0x00, 0x00
_080DC638: .4byte 0x02034F0C
_080DC63C:
	movs r0, #0x01
_080DC63E:
	bx lr
.syntax divided
