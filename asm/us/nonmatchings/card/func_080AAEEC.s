.syntax unified
	.align 2, 0
	.global func_080AAEEC
	.thumb
	.thumb_func
	.type func_080AAEEC, %function
func_080AAEEC: @ 080AAEEC
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x03
	bl __divsi3
	adds r6, r0, #0x0
	ldr r0, _080AAF1C @ =0x000006EE
	adds r5, r5, r0
	strh r6, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x03
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080AAF16
	adds r0, r6, #0x1
	strh r0, [r5, #0x00]
_080AAF16:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080AAF1C: .4byte 0x000006EE
.syntax divided
