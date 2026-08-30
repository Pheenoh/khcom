.syntax unified
	.align 2, 0
	.global func_08007E5C
	.thumb
	.thumb_func
	.type func_08007E5C, %function
func_08007E5C: @ 08007E5C
	ldr r1, _08007E64 @ =0x03007570
	strh r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08007E64: .4byte 0x03007570
.syntax divided
