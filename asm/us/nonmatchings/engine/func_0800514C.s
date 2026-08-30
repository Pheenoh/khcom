.syntax unified
	.align 2, 0
	.global func_0800514C
	.thumb
	.thumb_func
	.type func_0800514C, %function
func_0800514C: @ 0800514C
	ldr r1, _08005168 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x00]
	movs r0, #0xF8
	lsls r0, r0, #0x05
	ands r0, r1
	lsls r0, r0, #0x03
	movs r1, #0xC0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
_08005168: .4byte 0x09ECEB30
.syntax divided
