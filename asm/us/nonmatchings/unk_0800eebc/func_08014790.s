.syntax unified
	.align 2, 0
	.global func_08014790
	.thumb
	.thumb_func
	.type func_08014790, %function
func_08014790: @ 08014790
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080147A4 @ =0x02034928
	ldr r2, [r1, #0x00]
	movs r1, #0x01
	lsls r1, r0
	ldrh r0, [r2, #0x36]
	orrs r1, r0
	strh r1, [r2, #0x36]
	bx lr
_080147A4: .4byte 0x02034928
.syntax divided
