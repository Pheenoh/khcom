.syntax unified
	.align 2, 0
	.global func_08001384
	.thumb
	.thumb_func
	.type func_08001384, %function
func_08001384: @ 08001384
	ldr r0, _0800138C @ =0x02034000
	ldrh r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_0800138C: .4byte 0x02034000
.syntax divided
