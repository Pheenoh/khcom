.syntax unified
	.align 2, 0
	.global func_080B8418
	.thumb
	.thumb_func
	.type func_080B8418, %function
func_080B8418: @ 080B8418
	push {r4, lr}
	adds r3, r0, #0x0
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x28]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080B845C
	ldr r0, [r2, #0x14]
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r0, r0, r1
	str r0, [r3, #0x14]
	movs r4, #0x98
	lsls r4, r4, #0x01
	adds r1, r3, r4
	ldr r0, [r2, #0x14]
	str r0, [r1, #0x00]
	movs r0, #0x93
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0xDA
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	ldr r2, _080B8458 @ =0xFFFFFF00
	b _080B8488
_080B8458: .4byte 0xFFFFFF00
_080B845C:
	ldr r0, [r2, #0x14]
	ldr r4, _080B84F4 @ =0xFFFFFC00
	adds r0, r0, r4
	str r0, [r3, #0x14]
	movs r0, #0x98
	lsls r0, r0, #0x01
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	str r0, [r1, #0x00]
	movs r4, #0x93
	lsls r4, r4, #0x02
	adds r1, r3, r4
	ldr r0, [r2, #0x14]
	ldr r4, _080B84F8 @ =0xFFFFF400
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0xDA
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	movs r2, #0x80
	lsls r2, r2, #0x01
_080B8488:
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r1, [r3, #0x00]
	ldr r0, [r1, #0x18]
	str r0, [r3, #0x18]
	movs r4, #0x9A
	lsls r4, r4, #0x01
	adds r2, r3, r4
	ldr r0, [r1, #0x18]
	str r0, [r2, #0x00]
	movs r0, #0x94
	lsls r0, r0, #0x02
	adds r2, r3, r0
	ldr r0, [r1, #0x18]
	subs r4, #0x34
	adds r0, r0, r4
	str r0, [r2, #0x00]
	movs r0, #0xDB
	lsls r0, r0, #0x02
	adds r2, r3, r0
	ldr r0, [r1, #0x18]
	ldr r4, _080B84F4 @ =0xFFFFFC00
	adds r0, r0, r4
	str r0, [r2, #0x00]
	ldr r0, [r1, #0x1C]
	ldr r2, _080B84FC @ =0xFFFFDE00
	adds r0, r0, r2
	str r0, [r3, #0x1C]
	movs r4, #0x9C
	lsls r4, r4, #0x01
	adds r2, r3, r4
	ldr r0, [r1, #0x1C]
	movs r4, #0x90
	lsls r4, r4, #0x04
	adds r0, r0, r4
	str r0, [r2, #0x00]
	movs r0, #0x95
	lsls r0, r0, #0x02
	adds r2, r3, r0
	ldr r0, [r1, #0x1C]
	ldr r4, _080B8500 @ =0xFFFFDF00
	adds r0, r0, r4
	str r0, [r2, #0x00]
	movs r0, #0xDC
	lsls r0, r0, #0x02
	adds r2, r3, r0
	ldr r0, [r1, #0x1C]
	ldr r1, _080B8504 @ =0xFFFFE200
	adds r0, r0, r1
	str r0, [r2, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B84F4: .4byte 0xFFFFFC00
_080B84F8: .4byte 0xFFFFF400
_080B84FC: .4byte 0xFFFFDE00
_080B8500: .4byte 0xFFFFDF00
_080B8504: .4byte 0xFFFFE200
.syntax divided
