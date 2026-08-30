.syntax unified
	.align 2, 0
	.global func_08006B74
	.thumb
	.thumb_func
	.type func_08006B74, %function
func_08006B74: @ 08006B74
	ldr r0, _08006B7C @ =0x02034054
	ldrb r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006B7C: .4byte 0x02034054
.syntax divided
