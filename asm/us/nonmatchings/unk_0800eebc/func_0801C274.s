.syntax unified
	.align 2, 0
	.global func_0801C274
	.thumb
	.thumb_func
	.type func_0801C274, %function
func_0801C274: @ 0801C274
	ldr r3, _0801C294 @ =0x02039B84
	ldr r3, [r3, #0x00]
	mov r12, r3
	movs r3, #0x80
	lsls r3, r3, #0x01
	add r3, r12
	str r0, [r3, #0x00]
	movs r0, #0x82
	lsls r0, r0, #0x01
	add r0, r12
	str r1, [r0, #0x00]
	movs r0, #0x84
	lsls r0, r0, #0x01
	add r0, r12
	str r2, [r0, #0x00]
	bx lr
_0801C294: .4byte 0x02039B84
.syntax divided
