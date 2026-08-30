.syntax unified
	.align 2, 0
	.global func_08005778
	.thumb
	.thumb_func
	.type func_08005778, %function
func_08005778: @ 08005778
	push {r4, lr}
	movs r3, #0x1F
	ands r1, r3
	ands r2, r3
	ldr r4, _08005798 @ =0x030074CC
	lsls r2, r2, #0x0A
	lsls r1, r1, #0x05
	orrs r2, r1
	ands r0, r3
	orrs r0, r2
	strh r0, [r4, #0x00]
	ldr r1, _0800579C @ =0x030074D8
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_08005798: .4byte 0x030074CC
_0800579C: .4byte 0x030074D8
.syntax divided
