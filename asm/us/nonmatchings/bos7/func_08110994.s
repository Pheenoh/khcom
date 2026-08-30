.syntax unified
	.align 2, 0
	.global func_08110994
	.thumb
	.thumb_func
	.type func_08110994, %function
func_08110994: @ 08110994
	ldr r2, [r0, #0x04]
	movs r3, #0x00
	movs r0, #0x02
	strh r0, [r2, #0x02]
	strh r3, [r2, #0x04]
	strh r3, [r2, #0x06]
	strh r3, [r2, #0x08]
	strh r1, [r2, #0x12]
	bx lr
	.byte 0x00, 0x00
.syntax divided
