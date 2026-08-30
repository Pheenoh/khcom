.syntax unified
	.align 2, 0
	.global func_080DEDD8
	.thumb
	.thumb_func
	.type func_080DEDD8, %function
func_080DEDD8: @ 080DEDD8
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _080DEDF0 @ =0x02039BB0
	ldr r0, [r3, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080DEDF8
	ldr r2, _080DEDF4 @ =0x0984C868
	b _080DEDFA
	.byte 0x00, 0x00
_080DEDF0: .4byte 0x02039BB0
_080DEDF4: .4byte 0x0984C868
_080DEDF8:
	ldr r2, _080DEE14 @ =0x0984CBD0
_080DEDFA:
	movs r1, #0x0E
	ldsb r1, [r3, r1]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, #0x08
	adds r0, r0, r2
	lsls r1, r4, #0x03
	ldr r0, [r0, #0x00]
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
_080DEE14: .4byte 0x0984CBD0
.syntax divided
