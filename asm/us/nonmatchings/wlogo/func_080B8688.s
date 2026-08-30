.syntax unified
	.align 2, 0
	.global func_080B8688
	.thumb
	.thumb_func
	.type func_080B8688, %function
func_080B8688: @ 080B8688
	push {r4, lr}
	adds r3, r0, #0x0
	movs r0, #0x94
	lsls r0, r0, #0x01
	adds r1, r3, r0
	movs r0, #0x1E
	strb r0, [r1, #0x00]
	movs r2, #0x91
	lsls r2, r2, #0x02
	adds r1, r3, r2
	movs r0, #0x0A
	strb r0, [r1, #0x00]
	movs r4, #0xD7
	lsls r4, r4, #0x02
	adds r1, r3, r4
	ldr r0, _080B8710 @ =0x09EF397C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0x8F
	lsls r0, r0, #0x03
	adds r1, r3, r0
	ldr r0, _080B8714 @ =0x09EF3960
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x28]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080B8720
	ldr r1, [r2, #0x08]
	movs r4, #0xA0
	lsls r4, r4, #0x04
	adds r0, r1, r4
	str r0, [r2, #0x14]
	ldr r0, [r2, #0x0C]
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x10]
	movs r4, #0xF0
	lsls r4, r4, #0x04
	adds r0, r0, r4
	str r0, [r2, #0x1C]
	movs r0, #0xB0
	lsls r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r3, #0x14]
	movs r4, #0x98
	lsls r4, r4, #0x01
	adds r1, r3, r4
	ldr r0, [r2, #0x14]
	ldr r4, _080B8718 @ =0xFFFFFB00
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0x93
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	movs r4, #0x90
	lsls r4, r4, #0x04
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0xDA
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	ldr r2, _080B871C @ =0xFFFFFC00
	b _080B8766
	.byte 0x00, 0x00
_080B8710: .4byte 0x09EF397C
_080B8714: .4byte 0x09EF3960
_080B8718: .4byte 0xFFFFFB00
_080B871C: .4byte 0xFFFFFC00
_080B8720:
	ldr r1, [r2, #0x08]
	ldr r4, _080B87A8 @ =0xFFFFF600
	adds r0, r1, r4
	str r0, [r2, #0x14]
	ldr r0, [r2, #0x0C]
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x10]
	movs r4, #0xF0
	lsls r4, r4, #0x04
	adds r0, r0, r4
	str r0, [r2, #0x1C]
	ldr r0, _080B87AC @ =0xFFFFF500
	adds r1, r1, r0
	str r1, [r3, #0x14]
	movs r4, #0x98
	lsls r4, r4, #0x01
	adds r1, r3, r4
	ldr r0, [r2, #0x14]
	movs r4, #0xA0
	lsls r4, r4, #0x03
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0x93
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	ldr r4, _080B87B0 @ =0xFFFFF700
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0xDA
	lsls r0, r0, #0x02
	adds r1, r3, r0
	ldr r0, [r2, #0x14]
	movs r2, #0x80
	lsls r2, r2, #0x03
_080B8766:
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r1, [r3, #0x00]
	ldr r0, [r1, #0x1C]
	ldr r4, _080B87B4 @ =0xFFFFDE00
	adds r0, r0, r4
	str r0, [r3, #0x1C]
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r2, r3, r0
	ldr r0, [r1, #0x1C]
	movs r4, #0x90
	lsls r4, r4, #0x04
	adds r0, r0, r4
	str r0, [r2, #0x00]
	movs r0, #0x95
	lsls r0, r0, #0x02
	adds r2, r3, r0
	ldr r0, [r1, #0x1C]
	ldr r4, _080B87B8 @ =0xFFFFE100
	adds r0, r0, r4
	str r0, [r2, #0x00]
	movs r0, #0xDC
	lsls r0, r0, #0x02
	adds r2, r3, r0
	ldr r0, [r1, #0x1C]
	ldr r1, _080B87BC @ =0xFFFFE400
	adds r0, r0, r1
	str r0, [r2, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B87A8: .4byte 0xFFFFF600
_080B87AC: .4byte 0xFFFFF500
_080B87B0: .4byte 0xFFFFF700
_080B87B4: .4byte 0xFFFFDE00
_080B87B8: .4byte 0xFFFFE100
_080B87BC: .4byte 0xFFFFE400
.syntax divided
