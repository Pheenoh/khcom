.syntax unified
	.align 2, 0
	.global func_08005B38
	.thumb
	.thumb_func
	.type func_08005B38, %function
func_08005B38: @ 08005B38
	ldrh r1, [r0, #0x0E]
	ldr r0, [r0, #0x14]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	bx lr
.syntax divided
