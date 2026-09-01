.syntax unified
	.align 2, 0
	.global func_080B3A68
	.thumb
	.thumb_func
	.type func_080B3A68, %function
func_080B3A68: @ 080B3A68
	push {r4, r5, r6, lr}
	ldr r2, _080B3A84 @ =0x02034B4C
	ldr r0, [r2, #0x00]
	adds r0, #0xA4
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _080B3A88 @ =0x02039828
	ldr r3, [r0, #0x00]
	adds r6, r2, #0x0
	cmp r3, #0x00
	bne _080B3A90
	ldr r0, _080B3A8C @ =0x0203AB10
	strb r3, [r0, #0x00]
	b _080B3A98
_080B3A84: .4byte 0x02034B4C
_080B3A88: .4byte 0x02039828
_080B3A8C: .4byte 0x0203AB10
_080B3A90:
	ldr r1, _080B3B3C @ =0x0203AB10
	movs r0, #0x05
	strb r0, [r1, #0x00]
	adds r0, r1, #0x0
_080B3A98:
	ldr r4, [r6, #0x00]
	movs r1, #0x00
	ldsb r1, [r0, r1]
	adds r3, r4, #0x0
	adds r3, #0x76
	movs r5, #0x00
	strh r1, [r3, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x78
	strh r1, [r0, #0x00]
	ldr r2, _080B3B40 @ =0x09EF150C
	movs r0, #0x00
	ldsh r1, [r3, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x7A
	strh r0, [r1, #0x00]
	movs r0, #0x00
	ldsh r1, [r3, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldrh r1, [r0, #0x02]
	adds r0, r4, #0x0
	adds r0, #0x7C
	strh r1, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x74
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, [r6, #0x00]
	ldr r2, _080B3B44 @ =0x0203AB20
	adds r0, r1, #0x0
	adds r0, #0x76
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	ldr r2, _080B3B48 @ =0x00000202
	adds r1, r1, r2
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_080B1C70
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x00
	bl func_080B1C70
	ldr r4, _080B3B4C @ =0x096B5EE4
	ldr r1, _080B3B50 @ =0x06000020
	adds r0, r4, #0x0
	movs r2, #0xC0
	bl RequestDma3Copy
	movs r3, #0x80
	lsls r3, r3, #0x03
	adds r4, r4, r3
	ldr r1, _080B3B54 @ =0x060000E0
	adds r0, r4, #0x0
	movs r2, #0xC0
	bl RequestDma3Copy
	ldr r0, _080B3B58 @ =0x0203AB34
	strb r5, [r0, #0x00]
	strb r5, [r0, #0x01]
	ldr r0, [r6, #0x00]
	movs r1, #0x83
	lsls r1, r1, #0x02
	adds r0, r0, r1
	strb r5, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B3B3C: .4byte 0x0203AB10
_080B3B40: .4byte 0x09EF150C
_080B3B44: .4byte 0x0203AB20
_080B3B48: .4byte 0x00000202
_080B3B4C: .4byte 0x096B5EE4
_080B3B50: .4byte 0x06000020
_080B3B54: .4byte 0x060000E0
_080B3B58: .4byte 0x0203AB34
.syntax divided
