.syntax unified
	.align 2, 0
	.global func_08008B40
	.thumb
	.thumb_func
	.type func_08008B40, %function
func_08008B40: @ 08008B40
	push {r4, r5, r6, lr}
	movs r0, #0x40
	bl func_08000918
	adds r5, r0, #0x0
	movs r6, #0x00
_08008B4C:
	adds r0, r5, #0x0
	movs r1, #0x40
	bl func_080089E0
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	lsls r1, r4, #0x06
	ldr r0, _08008B80 @ =0x0E000010
	adds r1, r1, r0
	adds r0, r5, #0x0
	movs r2, #0x40
	bl WriteAndVerifySramFast
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	ble _08008B4C
	adds r0, r5, #0x0
	bl func_080009C4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08008B80: .4byte 0x0E000010
.syntax divided
