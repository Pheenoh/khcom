.syntax unified
	.align 2, 0
	.global func_08065B6C
	.thumb
	.thumb_func
	.type func_08065B6C, %function
func_08065B6C: @ 08065B6C
	push {lr}
	bl func_08065B7C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
