.syntax unified
	.align 2, 0
	.global func_080277E4
	.thumb
	.thumb_func
	.type func_080277E4, %function
func_080277E4: @ 080277E4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
	movs r0, #0x00
	str r0, [r4, #0x00]
	str r0, [r4, #0x08]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
