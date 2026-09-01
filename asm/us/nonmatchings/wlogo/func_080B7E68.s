.syntax unified
	.align 2, 0
	.global func_080B7E68
	.thumb
	.thumb_func
	.type func_080B7E68, %function
func_080B7E68: @ 080B7E68
	push {r4, lr}
	adds r3, r0, #0x0
	ldrh r1, [r3, #0x28]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080B7EB4
	ldr r0, [r3, #0x14]
	movs r2, #0x80
	lsls r2, r2, #0x05
	adds r1, r0, r2
	str r1, [r3, #0x48]
	ldr r4, _080B7EA4 @ =0xFFFFF900
	adds r0, r0, r4
	str r0, [r3, #0x54]
	ldr r0, [r3, #0x18]
	movs r2, #0xE0
	lsls r2, r2, #0x03
	adds r1, r0, r2
	str r1, [r3, #0x4C]
	ldr r4, _080B7EA8 @ =0xFFFFFC00
	adds r0, r0, r4
	str r0, [r3, #0x58]
	ldr r0, [r3, #0x1C]
	ldr r2, _080B7EAC @ =0xFFFFDE00
	adds r1, r0, r2
	str r1, [r3, #0x50]
	ldr r4, _080B7EB0 @ =0xFFFFE400
	b _080B7EDA
	.byte 0x00, 0x00
_080B7EA4: .4byte 0xFFFFF900
_080B7EA8: .4byte 0xFFFFFC00
_080B7EAC: .4byte 0xFFFFDE00
_080B7EB0: .4byte 0xFFFFE400
_080B7EB4:
	ldr r0, [r3, #0x14]
	movs r2, #0xE0
	lsls r2, r2, #0x03
	adds r1, r0, r2
	str r1, [r3, #0x48]
	ldr r1, _080B7EE4 @ =0xFFFFF200
	adds r0, r0, r1
	str r0, [r3, #0x54]
	ldr r0, [r3, #0x18]
	ldr r4, _080B7EE8 @ =0xFFFFFC00
	adds r1, r0, r4
	str r1, [r3, #0x4C]
	adds r0, r0, r2
	str r0, [r3, #0x58]
	ldr r0, [r3, #0x1C]
	ldr r2, _080B7EEC @ =0xFFFFE400
	adds r1, r0, r2
	str r1, [r3, #0x50]
	ldr r4, _080B7EF0 @ =0xFFFFDE00
_080B7EDA:
	adds r0, r0, r4
	str r0, [r3, #0x5C]
	pop {r4}
	pop {r0}
	bx r0
_080B7EE4: .4byte 0xFFFFF200
_080B7EE8: .4byte 0xFFFFFC00
_080B7EEC: .4byte 0xFFFFE400
_080B7EF0: .4byte 0xFFFFDE00
.syntax divided
