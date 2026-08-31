.syntax unified
	.align 2, 0
	.global func_080E83DC
	.thumb
	.thumb_func
	.type func_080E83DC, %function
func_080E83DC: @ 080E83DC
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r4, r2, #0x0
	ldr r0, _080E8414 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080E844A
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E8418 @ =0x00002710
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080E841C @ =0x000009C3
	cmp r1, r0
	bhi _080E8420
	str r4, [sp, #0x000]
	movs r0, #0x00
	movs r1, #0x02
	b _080E84B4
	.byte 0x00, 0x00
_080E8414: .4byte 0x02039BB0
_080E8418: .4byte 0x00002710
_080E841C: .4byte 0x000009C3
_080E8420:
	ldr r0, _080E842C @ =0x00001963
	cmp r1, r0
	bhi _080E8430
	str r4, [sp, #0x000]
	movs r0, #0x00
	b _080E84B2
_080E842C: .4byte 0x00001963
_080E8430:
	ldr r0, _080E8440 @ =0x00002327
	cmp r1, r0
	bhi _080E8444
	str r4, [sp, #0x000]
	movs r0, #0x01
	movs r1, #0x03
	b _080E84B4
	.byte 0x00, 0x00
_080E8440: .4byte 0x00002327
_080E8444:
	str r4, [sp, #0x000]
	movs r0, #0x01
	b _080E84B2
_080E844A:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E846C @ =0x00002710
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080E8470 @ =0x000007CF
	cmp r1, r0
	bhi _080E8474
	str r4, [sp, #0x000]
	movs r0, #0x00
	movs r1, #0x02
	b _080E84B4
	.byte 0x00, 0x00
_080E846C: .4byte 0x00002710
_080E8470: .4byte 0x000007CF
_080E8474:
	ldr r0, _080E8480 @ =0x00000F9F
	cmp r1, r0
	bhi _080E8484
	str r4, [sp, #0x000]
	movs r0, #0x00
	b _080E84B2
_080E8480: .4byte 0x00000F9F
_080E8484:
	ldr r0, _080E8494 @ =0x0000176F
	cmp r1, r0
	bhi _080E8498
	str r4, [sp, #0x000]
	movs r0, #0x01
	movs r1, #0x03
	b _080E84B4
	.byte 0x00, 0x00
_080E8494: .4byte 0x0000176F
_080E8498:
	ldr r0, _080E84A4 @ =0x00001963
	cmp r1, r0
	bhi _080E84A8
	str r4, [sp, #0x000]
	movs r0, #0x01
	b _080E84B2
_080E84A4: .4byte 0x00001963
_080E84A8:
	ldr r0, _080E84C0 @ =0x00001F3F
	cmp r1, r0
	bhi _080E84C4
	str r4, [sp, #0x000]
	movs r0, #0x02
_080E84B2:
	movs r1, #0x05
_080E84B4:
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl func_080E9034
	b _080E84D2
	.byte 0x00, 0x00
_080E84C0: .4byte 0x00001F3F
_080E84C4:
	str r4, [sp, #0x000]
	movs r0, #0x03
	movs r1, #0x05
	adds r2, r5, #0x0
	adds r3, r6, #0x0
	bl func_080E9034
_080E84D2:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
