.syntax unified
	.align 2, 0
	.global func_080E0A38
	.thumb
	.thumb_func
	.type func_080E0A38, %function
func_080E0A38: @ 080E0A38
	push {lr}
	adds r1, r0, #0x0
	ldrh r2, [r1, #0x00]
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	beq _080E0A50
	adds r0, r1, #0x0
	movs r1, #0x01
	bl func_080E0960
	b _080E0A6A
_080E0A50:
	movs r0, #0x02
	ands r0, r2
	cmp r0, #0x00
	beq _080E0A62
	adds r0, r1, #0x0
	movs r1, #0x02
	bl func_080E0960
	b _080E0A6A
_080E0A62:
	adds r0, r1, #0x0
	movs r1, #0x00
	bl func_080E0960
_080E0A6A:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
