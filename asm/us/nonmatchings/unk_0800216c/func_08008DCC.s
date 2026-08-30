.syntax unified
	.align 2, 0
	.global func_08008DCC
	.thumb
	.thumb_func
	.type func_08008DCC, %function
func_08008DCC: @ 08008DCC
	push {r4, r5, r6, r7, lr}
	ldr r4, _08008E10 @ =0x00000F14
	adds r0, r4, #0x0
	bl func_08000918
	adds r5, r0, #0x0
	movs r6, #0x00
	adds r7, r4, #0x0
_08008DDC:
	adds r0, r5, #0x0
	adds r1, r7, #0x0
	bl func_080089E0
	lsls r4, r6, #0x10
	asrs r4, r4, #0x10
	adds r1, r4, #0x0
	muls r1, r7
	ldr r0, _08008E14 @ =0x0E000090
	adds r1, r1, r0
	adds r0, r5, #0x0
	adds r2, r7, #0x0
	bl func_0811817C
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x01
	ble _08008DDC
	adds r0, r5, #0x0
	bl func_080009C4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08008E10: .4byte 0x00000F14
_08008E14: .4byte 0x0E000090
.syntax divided
