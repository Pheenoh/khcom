.syntax unified
	.align 2, 0
	.global func_08001390
	.thumb
	.thumb_func
	.type func_08001390, %function
func_08001390: @ 08001390
	ldr r0, _08001398 @ =0x02034002
	ldrh r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08001398: .4byte 0x02034002
.syntax divided
