.syntax unified
	.align 2, 0
	.global func_080DF51C
	.thumb
	.thumb_func
	.type func_080DF51C, %function
func_080DF51C: @ 080DF51C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x00
	bl func_080DEDD8
	adds r1, r0, #0x0
	b _080DF538
_080DF52C:
	ldrb r0, [r1, #0x02]
	cmp r0, r4
	bne _080DF536
	ldrb r0, [r1, #0x00]
	b _080DF540
_080DF536:
	adds r1, #0x08
_080DF538:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x05
	bne _080DF52C
	movs r0, #0x00
_080DF540:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
