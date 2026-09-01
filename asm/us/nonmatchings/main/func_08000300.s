.syntax unified
	.align 2, 0
	.global func_08000300
	.thumb
	.thumb_func
	.type func_08000300, %function
func_08000300: @ 08000300
	ldr r3, _08000320 @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _08000324 @ =0x04000200
	ldrh r1, [r2, #0x00]
	ldr r0, _08000328 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _0800032C @ =0x04000004
	ldrh r1, [r2, #0x00]
	ldr r0, _08000330 @ =0x0000FFEF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x01
	strh r0, [r3, #0x00]
	bx lr
_08000320: .4byte 0x04000208
_08000324: .4byte 0x04000200
_08000328: .4byte 0x0000FFFD
_0800032C: .4byte 0x04000004
_08000330: .4byte 0x0000FFEF
.syntax divided
