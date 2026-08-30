.syntax unified
	.align 2, 0
	.global func_08102A94
	.thumb
	.thumb_func
	.type func_08102A94, %function
func_08102A94: @ 08102A94
	push {r4, lr}
	bl func_08001390
	movs r4, #0x0F
	ands r4, r0
	bl func_0800139C
	movs r1, #0xFC
	lsls r1, r1, #0x02
	ands r1, r0
	orrs r4, r1
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
