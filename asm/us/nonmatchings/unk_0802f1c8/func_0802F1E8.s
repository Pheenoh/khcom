.syntax unified
	.align 2, 0
	.global func_0802F1E8
	.thumb
	.thumb_func
	.type func_0802F1E8, %function
func_0802F1E8: @ 0802F1E8
	ldr r1, _0802F1FC @ =0x0203492C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _0802F200 @ =0x0203492E
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _0802F204 @ =0x02034930
	movs r0, #0x00
	str r0, [r1, #0x00]
	bx lr
_0802F1FC: .4byte 0x0203492C
_0802F200: .4byte 0x0203492E
_0802F204: .4byte 0x02034930
.syntax divided
