.syntax unified
	.align 2, 0
	.global func_0802F1C8
	.thumb
	.thumb_func
	.type func_0802F1C8, %function
func_0802F1C8: @ 0802F1C8
	ldr r1, _0802F1DC @ =0x0203492C
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, _0802F1E0 @ =0x0203492E
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _0802F1E4 @ =0x02034930
	movs r0, #0x00
	str r0, [r1, #0x00]
	bx lr
_0802F1DC: .4byte 0x0203492C
_0802F1E0: .4byte 0x0203492E
_0802F1E4: .4byte 0x02034930
.syntax divided
