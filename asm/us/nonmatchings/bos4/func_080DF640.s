.syntax unified
	.align 2, 0
	.global func_080DF640
	.thumb
	.thumb_func
	.type func_080DF640, %function
func_080DF640: @ 080DF640
	push {r4, r5, r6, lr}
	adds r5, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0x0
	bl func_080DEE18
	adds r4, r0, #0x0
	cmp r5, #0x00
	bne _080DF65E
	ldrh r1, [r4, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080DF6C6
_080DF65E:
	ldrh r1, [r4, #0x00]
	ldr r0, _080DF698 @ =0x0000FFEF
	ands r0, r1
	ldr r1, _080DF69C @ =0x0000FFDF
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r4, #0x00]
	ldr r0, _080DF6A0 @ =0x03007480
	ldr r1, [r0, #0x00]
	ldr r0, [r0, #0x00]
	muls r0, r1
	str r0, [r4, #0x04]
	cmp r5, #0x00
	beq _080DF6B0
	ldrh r1, [r5, #0x00]
	lsls r1, r1, #0x02
	ldr r0, _080DF6A4 @ =0x0984D0CC
	adds r1, r1, r0
	ldrh r0, [r5, #0x02]
	strb r0, [r4, #0x0A]
	ldrb r0, [r1, #0x00]
	strb r0, [r4, #0x08]
	ldrb r0, [r1, #0x01]
	cmp r0, #0x19
	beq _080DF6A8
	strb r0, [r4, #0x09]
	b _080DF6B6
	.byte 0x00, 0x00
_080DF698: .4byte 0x0000FFEF
_080DF69C: .4byte 0x0000FFDF
_080DF6A0: .4byte 0x03007480
_080DF6A4: .4byte 0x0984D0CC
_080DF6A8:
	bl func_080DF5F4
	strb r0, [r4, #0x09]
	b _080DF6B6
_080DF6B0:
	adds r0, r6, #0x0
	bl func_080DF570
_080DF6B6:
	ldrb r0, [r4, #0x09]
	lsls r0, r0, #0x03
	ldr r1, _080DF6CC @ =0x0984D134
	adds r0, r0, r1
	ldrb r1, [r0, #0x02]
	strb r1, [r4, #0x0B]
	ldrb r0, [r0, #0x06]
	strb r0, [r4, #0x0C]
_080DF6C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080DF6CC: .4byte 0x0984D134
.syntax divided
