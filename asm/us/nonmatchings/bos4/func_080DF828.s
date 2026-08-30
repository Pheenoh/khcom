.syntax unified
	.align 2, 0
	.global func_080DF828
	.thumb
	.thumb_func
	.type func_080DF828, %function
func_080DF828: @ 080DF828
	push {r4, lr}
	ldr r2, _080DF83C @ =0x0203C590
	ldrh r1, [r2, #0x02]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _080DF840
	movs r4, #0xFF
	b _080DF862
	.byte 0x00, 0x00
_080DF83C: .4byte 0x0203C590
_080DF840:
	ldr r3, _080DF850 @ =0x02039BB0
	ldr r0, [r3, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DF858
	ldr r1, _080DF854 @ =0x0984B851
	b _080DF85A
_080DF850: .4byte 0x02039BB0
_080DF854: .4byte 0x0984B851
_080DF858:
	ldr r1, _080DF890 @ =0x0984B844
_080DF85A:
	movs r0, #0x0E
	ldsb r0, [r3, r0]
	adds r0, r0, r1
	ldrb r4, [r0, #0x00]
_080DF862:
	cmp r4, #0xFF
	beq _080DF898
	ldr r1, _080DF894 @ =0x02039BB0
	movs r2, #0x00
	strb r2, [r1, #0x0C]
	movs r0, #0x0C
	strb r0, [r1, #0x0D]
	movs r3, #0xDC
	lsls r3, r3, #0x01
	adds r0, r1, r3
	str r2, [r0, #0x00]
	ldr r0, [r1, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DF888
	movs r0, #0x00
	bl _08085D04
_080DF888:
	adds r0, r4, #0x0
	bl func_0806180C
	b _080DF8BA
_080DF890: .4byte 0x0984B844
_080DF894: .4byte 0x02039BB0
_080DF898:
	ldrh r1, [r2, #0x02]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080DF8AE
	movs r0, #0x04
	orrs r0, r1
	strh r0, [r2, #0x02]
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
_080DF8AE:
	movs r0, #0xFD
	movs r1, #0x00
	bl func_080DF730
	bl func_080E04EC
_080DF8BA:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
