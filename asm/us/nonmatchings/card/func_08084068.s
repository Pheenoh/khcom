.syntax unified
	.align 2, 0
	.global func_08084068
	.thumb
	.thumb_func
	.type func_08084068, %function
func_08084068: @ 08084068
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0x00
	adds r0, r5, #0x0
	bl CountCardsById
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x62
	bhi _080840D8
	ldr r0, _080840C8 @ =0x0203A080
	ldrh r1, [r0, #0x00]
	ldr r2, _080840CC @ =0x00000FFF
	adds r6, r0, #0x0
	cmp r1, r2
	beq _080840A4
	ldr r0, _080840D0 @ =0x0203A858
	ldrh r1, [r0, #0x00]
	adds r3, r6, #0x0
_08084090:
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r1
	beq _080840D8
	lsls r0, r4, #0x01
	adds r0, r0, r3
	ldrh r0, [r0, #0x00]
	cmp r0, r2
	bne _08084090
_080840A4:
	ldr r2, _080840D4 @ =0x08F70AB0
	ldr r0, _080840CC @ =0x00000FFF
	ands r0, r5
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #0x1E]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	bne _080840D8
	lsls r0, r4, #0x01
	adds r0, r0, r6
	strh r5, [r0, #0x00]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	b _080840DC
	.byte 0x00, 0x00
_080840C8: .4byte 0x0203A080
_080840CC: .4byte 0x00000FFF
_080840D0: .4byte 0x0203A858
_080840D4: .4byte 0x08F70AB0
_080840D8:
	movs r0, #0x01
	negs r0, r0
_080840DC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
