.syntax unified
	.align 2, 0
	.global func_080B0634
	.thumb
	.thumb_func
	.type func_080B0634, %function
func_080B0634: @ 080B0634
	push {r4, r5, r6, lr}
	ldr r0, _080B06B0 @ =0x02039810
	ldrh r2, [r0, #0x04]
	ldr r1, _080B06B4 @ =0x00002FCF
	adds r6, r0, #0x0
	cmp r2, r1
	bne _080B0670
	ldr r0, _080B06B8 @ =0x096B2724
	ldr r1, _080B06BC @ =0x06000020
	movs r2, #0xC0
	bl func_080043B4
	ldr r5, _080B06C0 @ =0x02034B40
	ldr r0, [r5, #0x00]
	ldr r4, _080B06C4 @ =0x00000217
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _080B0668
	movs r0, #0x00
	movs r1, #0x01
	movs r2, #0x01
	bl func_080AEED8
_080B0668:
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	movs r1, #0x01
	strb r1, [r0, #0x00]
_080B0670:
	ldrh r1, [r6, #0x06]
	ldr r0, _080B06C8 @ =0x00006AD6
	cmp r1, r0
	bne _080B06A8
	ldr r0, _080B06CC @ =0x096B2B24
	ldr r1, _080B06D0 @ =0x06000300
	movs r2, #0xC0
	bl func_080043B4
	ldr r5, _080B06C0 @ =0x02034B40
	ldr r0, [r5, #0x00]
	movs r4, #0x86
	lsls r4, r4, #0x02
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _080B06A0
	movs r0, #0x01
	movs r1, #0x01
	movs r2, #0x01
	bl func_080AEED8
_080B06A0:
	ldr r0, [r5, #0x00]
	adds r0, r0, r4
	movs r1, #0x01
	strb r1, [r0, #0x00]
_080B06A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B06B0: .4byte 0x02039810
_080B06B4: .4byte 0x00002FCF
_080B06B8: .4byte 0x096B2724
_080B06BC: .4byte 0x06000020
_080B06C0: .4byte 0x02034B40
_080B06C4: .4byte 0x00000217
_080B06C8: .4byte 0x00006AD6
_080B06CC: .4byte 0x096B2B24
_080B06D0: .4byte 0x06000300
.syntax divided
