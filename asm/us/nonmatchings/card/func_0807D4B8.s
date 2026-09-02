.syntax unified
	.align 2, 0
	.global func_0807D4B8
	.thumb
	.thumb_func
	.type func_0807D4B8, %function
func_0807D4B8: @ 0807D4B8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _0807D4C6
	bl ReleaseObjTiles
_0807D4C6:
	ldr r0, [r4, #0x14]
	cmp r0, #0x00
	beq _0807D4D0
	bl ReleaseObjPalette
_0807D4D0:
	movs r0, #0x00
	str r0, [r4, #0x00]
	str r0, [r4, #0x14]
	adds r0, r4, #0x0
	bl func_0807C33C
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
