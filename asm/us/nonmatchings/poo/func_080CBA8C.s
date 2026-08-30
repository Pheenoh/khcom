.syntax unified
	.align 2, 0
	.global func_080CBA8C
	.thumb
	.thumb_func
	.type func_080CBA8C, %function
func_080CBA8C: @ 080CBA8C
	push {r4, lr}
	movs r4, #0x00
_080CBA90:
	adds r0, r4, #0x0
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080CBAA0
	movs r0, #0x00
	b _080CBAA8
_080CBAA0:
	adds r4, #0x01
	cmp r4, #0x05
	ble _080CBA90
	movs r0, #0x01
_080CBAA8:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
