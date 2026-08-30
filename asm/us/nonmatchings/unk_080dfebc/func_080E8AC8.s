.syntax unified
	.align 2, 0
	.global func_080E8AC8
	.thumb
	.thumb_func
	.type func_080E8AC8, %function
func_080E8AC8: @ 080E8AC8
	push {r4, lr}
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _080E8AE0
	b _080E8ADA
_080E8AD2:
	adds r0, r4, #0x0
	bl func_080E8A24
	adds r4, #0x10
_080E8ADA:
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080E8AD2
_080E8AE0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
