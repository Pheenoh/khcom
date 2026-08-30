.syntax unified
	.align 2, 0
	.global func_08008B84
	.thumb
	.thumb_func
	.type func_08008B84, %function
func_08008B84: @ 08008B84
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x40
	bl func_08000918
	adds r5, r0, #0x0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x0A
	ldr r0, _08008BB8 @ =0x0E000010
	adds r4, r4, r0
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r5, #0x0
	movs r3, #0x40
	bl func_08008AD8
	adds r4, r0, #0x0
	adds r0, r5, #0x0
	bl func_080009C4
	adds r0, r4, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
_08008BB8: .4byte 0x0E000010
.syntax divided
