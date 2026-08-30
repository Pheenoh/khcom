.syntax unified
	.align 2, 0
	.global func_08008348
	.thumb
	.thumb_func
	.type func_08008348, %function
func_08008348: @ 08008348
	movs r2, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x00]
	strh r1, [r0, #0x02]
	strh r1, [r0, #0x04]
	strh r1, [r0, #0x06]
	strb r2, [r0, #0x08]
	strb r2, [r0, #0x09]
	strb r2, [r0, #0x0A]
	strb r2, [r0, #0x0B]
	strb r2, [r0, #0x0E]
	strb r2, [r0, #0x0F]
	strb r2, [r0, #0x0C]
	strb r2, [r0, #0x0D]
	strb r2, [r0, #0x10]
	strb r2, [r0, #0x11]
	movs r1, #0xFF
	strb r1, [r0, #0x12]
	movs r1, #0x01
	negs r1, r1
	strb r1, [r0, #0x13]
	strb r1, [r0, #0x14]
	strb r1, [r0, #0x15]
	strb r1, [r0, #0x18]
	strb r1, [r0, #0x19]
	strb r1, [r0, #0x16]
	strb r1, [r0, #0x17]
	strb r1, [r0, #0x1A]
	strb r1, [r0, #0x1B]
	bx lr
.syntax divided
