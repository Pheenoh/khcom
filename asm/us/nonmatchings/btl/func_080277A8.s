.syntax unified
	.align 2, 0
	.global func_080277A8
	.thumb
	.thumb_func
	.type func_080277A8, %function
func_080277A8: @ 080277A8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	subs r1, #0x18
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	adds r1, #0x68
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080277CE
	adds r1, #0x34
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	b _080277D0
_080277CE:
	ldr r0, _080277E0 @ =0x096FAC64
_080277D0:
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x08]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080277E0: .4byte 0x096FAC64
.syntax divided
