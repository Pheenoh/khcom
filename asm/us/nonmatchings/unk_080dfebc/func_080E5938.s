.syntax unified
	.align 2, 0
	.global func_080E5938
	.thumb
	.thumb_func
	.type func_080E5938, %function
func_080E5938: @ 080E5938
	push {r4, lr}
	adds r1, r0, #0x0
	adds r4, r1, #0x0
	adds r4, #0x08
	adds r1, #0x0C
	adds r0, r4, #0x0
	bl func_080E5354
	movs r0, #0x00
	str r0, [r4, #0x08]
	adds r0, r4, #0x0
	bl func_080DFF30
	str r0, [r4, #0x0C]
	ldr r1, [r4, #0x04]
	subs r1, r1, r0
	str r1, [r4, #0x04]
	ldr r0, _080E5964 @ =0xFFFF6000
	str r0, [r4, #0x08]
	pop {r4}
	pop {r0}
	bx r0
_080E5964: .4byte 0xFFFF6000
.syntax divided
