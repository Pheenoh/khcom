.syntax unified
	.align 2, 0
	.global func_08007E7C
	.thumb
	.thumb_func
	.type func_08007E7C, %function
func_08007E7C: @ 08007E7C
	ldr r0, _08007E88 @ =0x03007570
	ldr r1, _08007E8C @ =0x03007572
	ldrh r1, [r1, #0x00]
	strh r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08007E88: .4byte 0x03007570
_08007E8C: .4byte 0x03007572
.syntax divided
