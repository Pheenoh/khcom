.syntax unified
	.align 2, 0
	.global func_08085374
	.thumb
	.thumb_func
	.type func_08085374, %function
func_08085374: @ 08085374
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r0, r5, #0x0
	bl GetDeck
	adds r3, r0, #0x0
	movs r1, #0x00
	ldrh r0, [r3, #0x00]
	ldr r2, _080853AC @ =0x0000FFFF
	cmp r0, r2
	beq _080853A4
_08085390:
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x62
	bhi _080853A4
	lsls r0, r1, #0x01
	adds r0, r0, r3
	ldrh r0, [r0, #0x00]
	cmp r0, r2
	bne _08085390
_080853A4:
	cmp r1, #0x63
	bne _080853B0
	movs r0, #0x00
	b _08085438
_080853AC: .4byte 0x0000FFFF
_080853B0:
	lsls r0, r1, #0x01
	adds r0, r0, r3
	strh r4, [r0, #0x00]
	cmp r5, #0x01
	beq _080853E8
	cmp r5, #0x01
	bgt _080853C4
	cmp r5, #0x00
	beq _080853D4
	b _080853C8
_080853C4:
	cmp r5, #0x02
	beq _080853FC
_080853C8:
	ldr r3, _080853D0 @ =0x0203A080
	lsls r4, r4, #0x01
	b _0808540E
	.byte 0x00, 0x00
_080853D0: .4byte 0x0203A080
_080853D4:
	ldr r3, _080853E4 @ =0x0203A080
	lsls r4, r4, #0x01
	adds r2, r4, r3
	ldrh r1, [r2, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x05
	b _08085408
	.byte 0x00, 0x00
_080853E4: .4byte 0x0203A080
_080853E8:
	ldr r3, _080853F8 @ =0x0203A080
	lsls r4, r4, #0x01
	adds r2, r4, r3
	ldrh r1, [r2, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x06
	b _08085408
	.byte 0x00, 0x00
_080853F8: .4byte 0x0203A080
_080853FC:
	ldr r3, _08085440 @ =0x0203A080
	lsls r4, r4, #0x01
	adds r2, r4, r3
	ldrh r1, [r2, #0x00]
	movs r6, #0x80
	lsls r6, r6, #0x07
_08085408:
	adds r0, r6, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
_0808540E:
	adds r0, r4, r3
	ldrh r0, [r0, #0x00]
	bl func_080609AC
	lsls r0, r0, #0x10
	ldr r2, _08085444 @ =0x02039DE0
	lsls r1, r5, #0x03
	subs r1, r1, r5
	lsls r1, r1, #0x05
	adds r1, r1, r2
	adds r2, r1, #0x0
	adds r2, #0xDA
	lsrs r0, r0, #0x10
	ldrh r3, [r2, #0x00]
	adds r0, r0, r3
	strh r0, [r2, #0x00]
	adds r1, #0xDC
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	movs r0, #0x01
_08085438:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08085440: .4byte 0x0203A080
_08085444: .4byte 0x02039DE0
.syntax divided
