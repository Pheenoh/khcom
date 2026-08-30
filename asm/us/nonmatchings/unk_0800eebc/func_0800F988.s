.syntax unified
	.align 2, 0
	.global func_0800F988
	.thumb
	.thumb_func
	.type func_0800F988, %function
func_0800F988: @ 0800F988
	adds r2, r0, #0x0
	ldrb r0, [r2, #0x10]
	adds r1, r0, #0x1
	adds r0, r1, #0x0
	muls r0, r1
	lsls r1, r0, #0x01
	adds r1, r1, r0
	ldr r0, [r2, #0x0C]
	adds r1, r1, r0
	str r1, [r2, #0x0C]
	bx lr
	.byte 0x00, 0x00
.syntax divided
