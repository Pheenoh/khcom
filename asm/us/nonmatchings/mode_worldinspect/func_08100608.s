.syntax unified
	.align 2, 0
	.global func_08100608
	.thumb
	.thumb_func
	.type func_08100608, %function
func_08100608: @ 08100608
	push {lr}
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0x00
	ble _08100634
	ldr r1, _0810062C @ =0x09EF9488
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r1, #0x14
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldr r1, _08100630 @ =0x02035618
	bl func_08065B6C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _08100636
_0810062C: .4byte 0x09EF9488
_08100630: .4byte 0x02035618
_08100634:
	movs r0, #0x00
_08100636:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
