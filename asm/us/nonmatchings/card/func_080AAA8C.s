.syntax unified
	.align 2, 0
	.global func_080AAA8C
	.thumb
	.thumb_func
	.type func_080AAA8C, %function
func_080AAA8C: @ 080AAA8C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x00
	beq _080AAA9E
	cmp r1, #0x01
	beq _080AAAC0
	b _080AAAEC
_080AAA9E:
	ldr r0, [r5, #0x04]
	ldr r1, _080AAAB0 @ =0x090A4A0C
	bl func_08002A10
	ldr r0, _080AAAB4 @ =0x00000664
	adds r4, r5, r0
	ldr r1, _080AAAB8 @ =0x09EEB064
	ldr r2, _080AAABC @ =0x09EEB050
	b _080AAAD0
_080AAAB0: .4byte 0x090A4A0C
_080AAAB4: .4byte 0x00000664
_080AAAB8: .4byte 0x09EEB064
_080AAABC: .4byte 0x09EEB050
_080AAAC0:
	ldr r0, [r5, #0x04]
	ldr r1, _080AAAF4 @ =0x090A51F6
	bl func_08002A10
	ldr r0, _080AAAF8 @ =0x00000664
	adds r4, r5, r0
	ldr r1, _080AAAFC @ =0x09EEB07C
	ldr r2, _080AAB00 @ =0x09EEB068
_080AAAD0:
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	ldr r2, _080AAB04 @ =0x000004EC
	adds r1, r5, r2
	str r0, [r1, #0x00]
_080AAAEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080AAAF4: .4byte 0x090A51F6
_080AAAF8: .4byte 0x00000664
_080AAAFC: .4byte 0x09EEB07C
_080AAB00: .4byte 0x09EEB068
_080AAB04: .4byte 0x000004EC
.syntax divided
