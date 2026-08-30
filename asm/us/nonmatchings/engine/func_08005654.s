.syntax unified
	.align 2, 0
	.global func_08005654
	.thumb
	.thumb_func
	.type func_08005654, %function
func_08005654: @ 08005654
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _08005674
	ldr r1, _08005670 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x06
	adds r1, r3, #0x0
	orrs r0, r1
	b _08005682
	.byte 0x00, 0x00
_08005670: .4byte 0x09ECEB30
_08005674:
	ldr r1, _08005688 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	ldr r0, _0800568C @ =0x0000DFFF
	ands r0, r1
_08005682:
	strh r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
_08005688: .4byte 0x09ECEB30
_0800568C: .4byte 0x0000DFFF
.syntax divided
