.syntax unified
	.align 2, 0
	.global func_080D3ED0
	.thumb
	.thumb_func
	.type func_080D3ED0, %function
func_080D3ED0: @ 080D3ED0
	push {r4, r5, lr}
	movs r0, #0x02
	bl GetBgScreenBase
	adds r5, r0, #0x0
	adds r1, r5, #0x0
	adds r1, #0x1C
	ldr r4, _080D3F0C @ =0x08125E24
	adds r0, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r1, r5, #0x0
	adds r1, #0x5C
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r1, r5, #0x0
	adds r1, #0x9C
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3F0C: .4byte 0x08125E24
.syntax divided
