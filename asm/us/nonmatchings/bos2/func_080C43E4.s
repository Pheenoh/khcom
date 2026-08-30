.syntax unified
	.align 2, 0
	.global func_080C43E4
	.thumb
	.thumb_func
	.type func_080C43E4, %function
func_080C43E4: @ 080C43E4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r3, [r4, #0x00]
	subs r0, r1, r3
	asrs r2, r0, #0x01
	cmp r1, r3
	ble _080C4404
	ldr r0, _080C4400 @ =0x000004FF
	cmp r2, r0
	ble _080C4410
	movs r2, #0xA0
	lsls r2, r2, #0x03
	b _080C4410
	.byte 0x00, 0x00
_080C4400: .4byte 0x000004FF
_080C4404:
	cmp r1, r3
	bge _080C4414
	ldr r0, _080C441C @ =0xFFFFFB00
	cmp r2, r0
	bgt _080C4410
	adds r2, r0, #0x0
_080C4410:
	adds r0, r3, r2
	str r0, [r4, #0x00]
_080C4414:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C441C: .4byte 0xFFFFFB00
.syntax divided
