.syntax unified
	.align 2, 0
	.global func_080DF5F4
	.thumb
	.thumb_func
	.type func_080DF5F4, %function
func_080DF5F4: @ 080DF5F4
	push {r4, lr}
	ldr r0, _080DF61C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DF624
	ldr r4, _080DF620 @ =0x09EF69EE
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0D
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	b _080DF638
_080DF61C: .4byte 0x02039BB0
_080DF620: .4byte 0x09EF69EE
_080DF624:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x15
	bl func_0811D7CC
	adds r0, #0x01
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080DF638:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
