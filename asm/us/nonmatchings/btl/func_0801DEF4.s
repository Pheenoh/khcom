.syntax unified
	.align 2, 0
	.global func_0801DEF4
	.thumb
	.thumb_func
	.type func_0801DEF4, %function
func_0801DEF4: @ 0801DEF4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _0801DF02
	bl ReleaseObjPalette
_0801DF02:
	movs r0, #0x00
	str r0, [r4, #0x00]
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
