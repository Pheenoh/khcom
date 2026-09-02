.syntax unified
	.align 2, 0
	.global func_0809CAC8
	.thumb
	.thumb_func
	.type func_0809CAC8, %function
func_0809CAC8: @ 0809CAC8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x54
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _0809CB04
	ldr r0, [r4, #0x0C]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x28]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x08]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x24]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x10]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x20]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x1C]
	bl ReleaseObjTiles
	movs r0, #0x00
	strb r0, [r5, #0x00]
_0809CB04:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
