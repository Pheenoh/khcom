.syntax unified
	.align 2, 0
	.global func_080E891C
	.thumb
	.thumb_func
	.type func_080E891C, %function
func_080E891C: @ 080E891C
	push {r4, lr}
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _080E8934
	b _080E892E
_080E8926:
	adds r0, r4, #0x0
	bl func_080E8864
	adds r4, #0x10
_080E892E:
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080E8926
_080E8934:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
