.syntax unified
	.align 2, 0
	.global mode_sio_chg_card_0
	.thumb
	.thumb_func
	.type mode_sio_chg_card_0, %function
mode_sio_chg_card_0: @ 080B1CD0
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r6, _080B1DBC @ =0x02034B4C
	ldr r0, _080B1DC0 @ =0x00000BF8
	bl EwramAlloc
	str r0, [r6, #0x00]
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x00
	movs r1, #0x00
	bl SetBgPriority
	movs r0, #0x00
	movs r1, #0x01
	bl SetBgOverflow
	movs r0, #0x00
	movs r1, #0x00
	bl SetBgSize
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x01
	movs r1, #0x01
	bl SetBgPriority
	movs r0, #0x01
	movs r1, #0x01
	bl SetBgOverflow
	movs r0, #0x01
	movs r1, #0x00
	bl SetBgSize
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x18
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x02
	movs r1, #0x02
	bl SetBgPriority
	movs r0, #0x02
	movs r1, #0x01
	bl SetBgOverflow
	movs r0, #0x02
	movs r1, #0x00
	bl SetBgSize
	ldr r4, _080B1DC4 @ =0x096B2BE4
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r0, r4, #0x0
	bl RequestDma3Copy
	movs r0, #0x00
	bl DisableBg
	movs r0, #0x01
	bl DisableBg
	movs r0, #0x02
	bl DisableBg
	ldr r0, [r6, #0x00]
	movs r3, #0x00
	movs r2, #0x00
	strh r2, [r0, #0x02]
	strh r2, [r0, #0x04]
	adds r0, #0xA4
	strb r3, [r0, #0x00]
	ldr r0, [r6, #0x00]
	strb r3, [r0, #0x01]
	ldr r0, [r6, #0x00]
	ldr r4, _080B1DC8 @ =0x00000404
	adds r1, r0, r4
	strh r2, [r1, #0x00]
	movs r1, #0xBE
	lsls r1, r1, #0x04
	adds r0, r0, r1
	strb r3, [r0, #0x00]
	ldr r0, [r6, #0x00]
	ldr r3, _080B1DCC @ =0x00000202
	adds r0, r0, r3
	strh r5, [r0, #0x00]
	ldr r2, _080B1DD0 @ =0x02039B58
	ldr r0, _080B1DD4 @ =0x0203AB10
	ldrb r1, [r0, #0x00]
	movs r0, #0x0F
	ands r0, r1
	lsls r0, r0, #0x0C
	adds r5, #0x01
	ldr r4, _080B1DD8 @ =0x00000FFF
	adds r1, r4, #0x0
	ands r5, r1
	orrs r0, r5
	strh r0, [r2, #0x06]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B1DBC: .4byte 0x02034B4C
_080B1DC0: .4byte 0x00000BF8
_080B1DC4: .4byte 0x096B2BE4
_080B1DC8: .4byte 0x00000404
_080B1DCC: .4byte 0x00000202
_080B1DD0: .4byte 0x02039B58
_080B1DD4: .4byte 0x0203AB10
_080B1DD8: .4byte 0x00000FFF
.syntax divided
