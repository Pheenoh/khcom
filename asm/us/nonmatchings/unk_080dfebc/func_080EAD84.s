.syntax unified
	.align 2, 0
	.global func_080EAD84
	.thumb
	.thumb_func
	.type func_080EAD84, %function
func_080EAD84: @ 080EAD84
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, r1, #0x0
	ldr r6, _080EADE4 @ =0x02034FDC
	ldr r0, [r6, #0x00]
	ldr r7, _080EADE8 @ =0x0000033D
	adds r0, r0, r7
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080EAD9C
	adds r2, r1, #0x2
_080EAD9C:
	lsls r0, r2, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r3, #0x03
	ldr r0, _080EADEC @ =0x02039D6C
	adds r4, r1, r0
	ldrb r5, [r4, #0x02]
	cmp r5, #0x00
	beq _080EAE04
	ldrb r2, [r4, #0x00]
	adds r0, r3, #0x0
	movs r1, #0x01
	bl func_080EAB20
	ldrb r0, [r4, #0x01]
	bl func_080DF804
	ldr r1, [r6, #0x00]
	adds r1, #0x40
	bl func_08065B6C
	ldr r1, [r6, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	adds r1, r1, r2
	strb r0, [r1, #0x00]
	ldr r1, [r6, #0x00]
	adds r0, r1, r7
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080EADF4
	ldr r0, [r1, #0x3C]
	ldrh r0, [r0, #0x06]
	ldr r1, _080EADF0 @ =0x09991C04
	bl LoadObjPaletteBank
	b _080EAE18
_080EADE4: .4byte 0x02034FDC
_080EADE8: .4byte 0x0000033D
_080EADEC: .4byte 0x02039D6C
_080EADF0: .4byte 0x09991C04
_080EADF4:
	ldr r0, [r1, #0x3C]
	ldrh r0, [r0, #0x06]
	ldr r1, _080EAE00 @ =0x09991C44
	bl LoadObjPaletteBank
	b _080EAE18
_080EAE00: .4byte 0x09991C44
_080EAE04:
	adds r0, r3, #0x0
	movs r1, #0x01
	movs r2, #0x0D
	bl func_080EAB20
	ldr r0, [r6, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r5, [r0, #0x00]
_080EAE18:
	ldr r0, _080EAE40 @ =0x02034FDC
	ldr r1, [r0, #0x00]
	ldr r2, _080EAE44 @ =0x0000033E
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080EAE6C
	subs r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080EAE4C
	ldr r1, _080EAE48 @ =0x0998E744
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgMap
	b _080EAE58
	.byte 0x00, 0x00
_080EAE40: .4byte 0x02034FDC
_080EAE44: .4byte 0x0000033E
_080EAE48: .4byte 0x0998E744
_080EAE4C:
	ldr r1, _080EAE64 @ =0x0998D744
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgMap
_080EAE58:
	ldr r2, _080EAE68 @ =0x0000FFF7
	movs r0, #0x01
	movs r1, #0x00
	bl SetBgScroll
	b _080EAEA2
_080EAE64: .4byte 0x0998D744
_080EAE68: .4byte 0x0000FFF7
_080EAE6C:
	ldr r2, _080EAE84 @ =0x0000033D
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080EAE8C
	ldr r1, _080EAE88 @ =0x0998EF44
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgMap
	b _080EAE98
_080EAE84: .4byte 0x0000033D
_080EAE88: .4byte 0x0998EF44
_080EAE8C:
	ldr r1, _080EAEA8 @ =0x0998DF44
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgMap
_080EAE98:
	ldr r2, _080EAEAC @ =0x0000FFFA
	movs r0, #0x01
	movs r1, #0x00
	bl SetBgScroll
_080EAEA2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080EAEA8: .4byte 0x0998DF44
_080EAEAC: .4byte 0x0000FFFA
.syntax divided
