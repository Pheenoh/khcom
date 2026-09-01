.syntax unified
	.align 2, 0
	.global mode_sio_btl_option_0
	.thumb
	.thumb_func
	.type mode_sio_btl_option_0, %function
mode_sio_btl_option_0: @ 080AEF38
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	ldr r5, _080AF08C @ =0x02034B40
	ldr r0, _080AF090 @ =0x0000041C
	bl EwramAlloc
	str r0, [r5, #0x00]
	bl func_08004E64
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x0A
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
	movs r3, #0x0A
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
	movs r1, #0x02
	movs r2, #0x18
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x02
	movs r1, #0x02
	bl SetBgPriority
	movs r0, #0x02
	movs r1, #0x01
	bl SetBgOverflow
	movs r1, #0x80
	lsls r1, r1, #0x08
	movs r0, #0x02
	bl SetBgSize
	ldr r4, _080AF094 @ =0x096AD744
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r0, r4, #0x0
	bl RequestDma3Copy
	ldr r0, [r5, #0x00]
	adds r0, #0x54
	movs r1, #0x14
	bl func_08065ACC
	ldr r0, [r5, #0x00]
	adds r0, #0xFC
	movs r1, #0x0A
	bl func_08065ACC
	ldr r0, [r5, #0x00]
	movs r6, #0xAA
	lsls r6, r6, #0x01
	adds r0, r0, r6
	movs r1, #0x0A
	bl func_08065ACC
	ldr r4, _080AF098 @ =0x0203AA30
	ldr r1, [r5, #0x00]
	adds r1, #0xFC
	adds r0, r4, #0x0
	bl func_08065B6C
	ldr r1, [r5, #0x00]
	adds r1, #0xF8
	strb r0, [r1, #0x00]
	adds r4, #0x14
	ldr r1, [r5, #0x00]
	adds r1, r1, r6
	adds r0, r4, #0x0
	bl func_08065B6C
	ldr r1, [r5, #0x00]
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r1, r1, r2
	strb r0, [r1, #0x00]
	ldr r4, _080AF09C @ =0x096FBCC4
	adds r0, r4, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r5, #0x00]
	adds r1, #0xF4
	str r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x40
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r5, #0x00]
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r1, r1, r3
	str r0, [r1, #0x00]
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	ldr r2, [r5, #0x00]
	movs r3, #0xD2
	lsls r3, r3, #0x01
	adds r1, r2, r3
	str r0, [r1, #0x00]
	ldr r1, _080AF0A0 @ =0x0203AAA0
	ldr r0, _080AF0A4 @ =0x0203AA00
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	ldr r1, _080AF0A8 @ =0x00000417
	adds r2, r2, r1
	strb r0, [r2, #0x00]
	movs r0, #0x00
	bl DisableBg
	movs r0, #0x01
	bl DisableBg
	ldr r2, [r5, #0x00]
	ldr r3, _080AF0AC @ =0x0000021A
	adds r0, r2, r3
	movs r1, #0x00
	mov r3, r8
	strh r3, [r0, #0x00]
	strb r1, [r2, #0x02]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080AF08C: .4byte 0x02034B40
_080AF090: .4byte 0x0000041C
_080AF094: .4byte 0x096AD744
_080AF098: .4byte 0x0203AA30
_080AF09C: .4byte 0x096FBCC4
_080AF0A0: .4byte 0x0203AAA0
_080AF0A4: .4byte 0x0203AA00
_080AF0A8: .4byte 0x00000417
_080AF0AC: .4byte 0x0000021A
.syntax divided
