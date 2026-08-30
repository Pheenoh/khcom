.syntax unified
	.align 2, 0
	.global func_080E1CA8
	.thumb
	.thumb_func
	.type func_080E1CA8, %function
func_080E1CA8: @ 080E1CA8
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080E1CCE
	ldr r1, [r2, #0x08]
	ldr r0, _080E1CD4 @ =0xFFF00000
	cmp r1, r0
	beq _080E1CCE
	ldr r1, [r2, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	bne _080E1CD8
_080E1CCE:
	movs r0, #0x01
	b _080E1CDA
	.byte 0x00, 0x00
_080E1CD4: .4byte 0xFFF00000
_080E1CD8:
	movs r0, #0x00
_080E1CDA:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
