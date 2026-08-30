.syntax unified
	.align 2, 0
	.global func_0811D4FC
	.thumb
	.thumb_func
	.type func_0811D4FC, %function
func_0811D4FC: @ 0811D4FC
	ldr r1, _0811D510 @ =0x04000100
	ldr r2, _0811D514 @ =0x0203C7F0
	ldr r0, [r2, #0x3C]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	movs r0, #0x80
	strh r0, [r1, #0x00]
	movs r0, #0x01
	str r0, [r2, #0x44]
	bx lr
_0811D510: .4byte 0x04000100
_0811D514: .4byte 0x0203C7F0
.syntax divided
