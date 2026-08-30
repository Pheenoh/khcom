.syntax unified
	.align 2, 0
	.global func_080C9E84
	.thumb
	.thumb_func
	.type func_080C9E84, %function
func_080C9E84: @ 080C9E84
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
	ldr r4, _080C9EA8 @ =0x096FCAF4
_080C9E8C:
	ldrh r1, [r4, #0x08]
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	adds r0, r6, #0x0
	bl func_080CD550
	adds r4, #0x0C
	adds r5, #0x01
	cmp r5, #0x0B
	bls _080C9E8C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C9EA8: .4byte 0x096FCAF4
.syntax divided
