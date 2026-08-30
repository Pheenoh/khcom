.syntax unified
	.align 2, 0
	.global func_080428E8
	.thumb
	.thumb_func
	.type func_080428E8, %function
func_080428E8: @ 080428E8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r1, #0x03
	bl func_0811D684
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _08042910
	adds r0, r4, #0x0
	adds r0, #0x20
	ldr r1, _08042918 @ =0x09EDB458
	adds r2, r4, #0x0
	adds r2, #0x38
	bl func_08000E14
_08042910:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08042918: .4byte 0x09EDB458
.syntax divided
