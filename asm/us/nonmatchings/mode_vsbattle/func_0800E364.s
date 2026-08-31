.syntax unified
	.align 2, 0
	.global func_0800E364
	.thumb
	.thumb_func
	.type func_0800E364, %function
func_0800E364: @ 0800E364
	push {r4, lr}
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _0800E378
	ldr r0, [r4, #0x04]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
_0800E378:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
