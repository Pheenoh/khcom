.syntax unified
	.align 2, 0
	.global func_080D3538
	.thumb
	.thumb_func
	.type func_080D3538, %function
func_080D3538: @ 080D3538
	push {r4, lr}
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl func_080DED98
	adds r0, r0, r4
	ldrb r0, [r0, #0x00]
	adds r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bls _080D355A
	movs r0, #0x00
	b _080D355C
_080D355A:
	movs r0, #0x01
_080D355C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
