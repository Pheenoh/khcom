.syntax unified
	.align 2, 0
	.global func_080CA67C
	.thumb
	.thumb_func
	.type func_080CA67C, %function
func_080CA67C: @ 080CA67C
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080CA648
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CA6A0
	ldr r1, [r4, #0x04]
	ldr r0, _080CA698 @ =0x0001FFFF
	cmp r1, r0
	bgt _080CA69C
	movs r0, #0x01
	b _080CA6A2
	.byte 0x00, 0x00
_080CA698: .4byte 0x0001FFFF
_080CA69C:
	movs r0, #0x02
	b _080CA6A2
_080CA6A0:
	movs r0, #0x00
_080CA6A2:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
