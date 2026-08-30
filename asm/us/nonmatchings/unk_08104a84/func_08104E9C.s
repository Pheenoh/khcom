.syntax unified
	.align 2, 0
	.global func_08104E9C
	.thumb
	.thumb_func
	.type func_08104E9C, %function
func_08104E9C: @ 08104E9C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #0x02
	adds r2, r2, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r1, #0x0
	bx lr
	.byte 0x00, 0x00
.syntax divided
