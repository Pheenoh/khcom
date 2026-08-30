.syntax unified
	.align 2, 0
	.global func_0807E34C
	.thumb
	.thumb_func
	.type func_0807E34C, %function
func_0807E34C: @ 0807E34C
	ldr r0, _0807E358 @ =0x02034AAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807E35C
	movs r0, #0x00
	b _0807E366
_0807E358: .4byte 0x02034AAC
_0807E35C:
	ldr r0, [r0, #0x78]
	movs r1, #0x02
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0807E366:
	bx lr
.syntax divided
