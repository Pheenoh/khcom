.syntax unified
	.align 2, 0
	.global func_08007E68
	.thumb
	.thumb_func
	.type func_08007E68, %function
func_08007E68: @ 08007E68
	ldr r3, _08007E74 @ =0x03007572
	ldr r2, _08007E78 @ =0x03007570
	ldrh r1, [r2, #0x00]
	strh r1, [r3, #0x00]
	strh r0, [r2, #0x00]
	bx lr
_08007E74: .4byte 0x03007572
_08007E78: .4byte 0x03007570
.syntax divided
