.syntax unified
	.align 2, 0
	.global func_08008E18
	.thumb
	.thumb_func
	.type func_08008E18, %function
func_08008E18: @ 08008E18
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r5, _08008E50 @ =0x00000F14
	adds r0, r5, #0x0
	bl func_08000918
	adds r6, r0, #0x0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	muls r0, r5
	ldr r1, _08008E54 @ =0x0E000090
	adds r0, r0, r1
	adds r1, r6, #0x0
	adds r2, r6, #0x0
	adds r3, r5, #0x0
	bl func_08008AD8
	adds r4, r0, #0x0
	adds r0, r6, #0x0
	bl func_080009C4
	adds r0, r4, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_08008E50: .4byte 0x00000F14
_08008E54: .4byte 0x0E000090
.syntax divided
