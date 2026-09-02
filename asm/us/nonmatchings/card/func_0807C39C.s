.syntax unified
	.align 2, 0
	.global func_0807C39C
	.thumb
	.thumb_func
	.type func_0807C39C, %function
func_0807C39C: @ 0807C39C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0807C3AA
	bl ReleaseObjTiles
_0807C3AA:
	ldr r0, [r4, #0x14]
	cmp r0, #0x00
	beq _0807C3B4
	bl ReleaseObjPalette
_0807C3B4:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _0807C3BE
	bl ReleaseObjTiles
_0807C3BE:
	ldr r0, [r4, #0x08]
	cmp r0, #0x00
	beq _0807C3C8
	bl ReleaseObjTiles
_0807C3C8:
	ldr r0, [r4, #0x0C]
	cmp r0, #0x00
	beq _0807C3D2
	bl ReleaseObjTiles
_0807C3D2:
	movs r0, #0x00
	str r0, [r4, #0x00]
	str r0, [r4, #0x14]
	str r0, [r4, #0x18]
	str r0, [r4, #0x04]
	str r0, [r4, #0x08]
	str r0, [r4, #0x0C]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
