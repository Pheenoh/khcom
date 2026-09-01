.syntax unified
	.align 2, 0
	.global func_08098778
	.thumb
	.thumb_func
	.type func_08098778, %function
func_08098778: @ 08098778
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08098786
	bl ReleaseObjTiles
_08098786:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _08098790
	bl ReleaseObjTiles
_08098790:
	ldr r0, [r4, #0x08]
	cmp r0, #0x00
	beq _0809879A
	bl ReleaseObjTiles
_0809879A:
	ldr r0, [r4, #0x0C]
	cmp r0, #0x00
	beq _080987A4
	bl ReleaseObjPalette
_080987A4:
	ldr r0, [r4, #0x10]
	cmp r0, #0x00
	beq _080987AE
	bl ReleaseObjPalette
_080987AE:
	ldr r0, [r4, #0x14]
	cmp r0, #0x00
	beq _080987B8
	bl ReleaseObjPalette
_080987B8:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
