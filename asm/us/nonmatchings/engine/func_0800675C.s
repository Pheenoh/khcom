.syntax unified
	.align 2, 0
	.global func_0800675C
	.thumb
	.thumb_func
	.type func_0800675C, %function
func_0800675C: @ 0800675C
	ldr r3, _0800676C @ =0x02034064
	strb r0, [r3, #0x00]
	ldr r0, _08006770 @ =0x0203405C
	str r1, [r0, #0x00]
	ldr r0, _08006774 @ =0x02034060
	str r2, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_0800676C: .4byte 0x02034064
_08006770: .4byte 0x0203405C
_08006774: .4byte 0x02034060
.syntax divided
