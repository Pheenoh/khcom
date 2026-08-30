.syntax unified
	.align 2, 0
	.global func_08005130
	.thumb
	.thumb_func
	.type func_08005130, %function
func_08005130: @ 08005130
	ldr r1, _08005148 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x00]
	movs r0, #0x0C
	ands r0, r1
	lsls r0, r0, #0x0C
	movs r1, #0xC0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	bx lr
_08005148: .4byte 0x09ECEB30
.syntax divided
