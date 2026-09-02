.syntax unified
	.align 2, 0
	.global func_08082F24
	.thumb
	.thumb_func
	.type func_08082F24, %function
func_08082F24: @ 08082F24
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08082F32
	bl ReleaseObjTiles
_08082F32:
	ldr r0, [r4, #0x14]
	cmp r0, #0x00
	beq _08082F3C
	bl ReleaseObjPalette
_08082F3C:
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
