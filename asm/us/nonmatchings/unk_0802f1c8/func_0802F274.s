.syntax unified
	.align 2, 0
	.global func_0802F274
	.thumb
	.thumb_func
	.type func_0802F274, %function
func_0802F274: @ 0802F274
	ldr r2, _0802F280 @ =0x02039B84
	ldr r2, [r2, #0x00]
	str r0, [r2, #0x10]
	str r1, [r2, #0x14]
	bx lr
	.byte 0x00, 0x00
_0802F280: .4byte 0x02039B84
.syntax divided
