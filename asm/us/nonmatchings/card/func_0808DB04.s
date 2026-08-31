.syntax unified
	.align 2, 0
	.global func_0808DB04
	.thumb
	.thumb_func
	.type func_0808DB04, %function
func_0808DB04: @ 0808DB04
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x28]
	cmp r0, #0x00
	beq _0808DB16
	bl ReleaseObjTiles
	movs r0, #0x00
	str r0, [r4, #0x28]
_0808DB16:
	ldr r0, [r4, #0x1C]
	cmp r0, #0x00
	beq _0808DB4A
	bl ReleaseObjTiles
	ldr r0, [r4, #0x30]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x20]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x34]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x24]
	cmp r0, #0x00
	beq _0808DB40
	bl ReleaseObjTiles
	movs r0, #0x00
	str r0, [r4, #0x24]
_0808DB40:
	movs r0, #0x00
	str r0, [r4, #0x1C]
	str r0, [r4, #0x30]
	str r0, [r4, #0x20]
	str r0, [r4, #0x34]
_0808DB4A:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
