.syntax unified
	.align 2, 0
	.global func_080EBA58
	.thumb
	.thumb_func
	.type func_080EBA58, %function
func_080EBA58: @ 080EBA58
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r5, #0x03
	ldr r0, _080EBAA0 @ =0x02039D6C
	adds r4, r1, r0
	ldrb r6, [r4, #0x02]
	cmp r6, #0x00
	beq _080EBAC0
	ldrb r2, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_080EB818
	ldrb r0, [r4, #0x01]
	bl func_080DF804
	ldr r4, _080EBAA4 @ =0x02034FE0
	ldr r1, [r4, #0x00]
	adds r1, #0x3C
	bl func_08065B6C
	ldr r1, [r4, #0x00]
	movs r2, #0xAE
	lsls r2, r2, #0x01
	adds r1, r1, r2
	strb r0, [r1, #0x00]
	cmp r5, #0x01
	bhi _080EBAAC
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x38]
	ldrh r0, [r0, #0x06]
	ldr r1, _080EBAA8 @ =0x09991C04
	bl LoadObjPaletteBank
	b _080EBAD6
_080EBAA0: .4byte 0x02039D6C
_080EBAA4: .4byte 0x02034FE0
_080EBAA8: .4byte 0x09991C04
_080EBAAC:
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x38]
	ldrh r0, [r0, #0x06]
	ldr r1, _080EBABC @ =0x09991C44
	bl LoadObjPaletteBank
	b _080EBAD6
	.byte 0x00, 0x00
_080EBABC: .4byte 0x09991C44
_080EBAC0:
	adds r0, r5, #0x0
	movs r1, #0x01
	movs r2, #0x0D
	bl func_080EB818
	ldr r0, _080EBADC @ =0x02034FE0
	ldr r0, [r0, #0x00]
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strb r6, [r0, #0x00]
_080EBAD6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080EBADC: .4byte 0x02034FE0
.syntax divided
