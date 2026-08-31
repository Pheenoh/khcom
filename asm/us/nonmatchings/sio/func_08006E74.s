.syntax unified
	.align 2, 0
	.global func_08006E74
	.thumb
	.thumb_func
	.type func_08006E74, %function
func_08006E74: @ 08006E74
	push {r4, r5, lr}
	add sp, #-0x004
	ldr r0, _08006EB4 @ =0x0203406E
	ldr r2, _08006EB8 @ =0x04000208
	ldrh r5, [r2, #0x00]
	strh r5, [r0, #0x00]
	movs r4, #0x00
	strh r4, [r2, #0x00]
	ldr r3, _08006EBC @ =0x04000200
	ldrh r1, [r3, #0x00]
	ldr r0, _08006EC0 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r3, #0x00]
	strh r5, [r2, #0x00]
	ldr r0, _08006EC4 @ =0x04000128
	strh r4, [r0, #0x00]
	subs r0, #0x1A
	strh r4, [r0, #0x00]
	ldr r1, _08006EC8 @ =0x04000202
	movs r0, #0xC0
	strh r0, [r1, #0x00]
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r1, _08006ECC @ =0x02039830
	ldr r2, _08006ED0 @ =0x050000C9
	mov r0, sp
	bl CpuSet
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
_08006EB4: .4byte 0x0203406E
_08006EB8: .4byte 0x04000208
_08006EBC: .4byte 0x04000200
_08006EC0: .4byte 0x0000FF3F
_08006EC4: .4byte 0x04000128
_08006EC8: .4byte 0x04000202
_08006ECC: .4byte 0x02039830
_08006ED0: .4byte 0x050000C9
.syntax divided
