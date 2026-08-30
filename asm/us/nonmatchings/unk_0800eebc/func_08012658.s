.syntax unified
	.align 2, 0
	.global func_08012658
	.thumb
	.thumb_func
	.type func_08012658, %function
func_08012658: @ 08012658
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x08
	str r1, [r0, #0x14]
	bx lr
.syntax divided
