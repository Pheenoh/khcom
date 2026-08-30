.syntax unified
	.align 2, 0
	.global func_080055C8
	.thumb
	.thumb_func
	.type func_080055C8, %function
func_080055C8: @ 080055C8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080055E4 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r2, [r0, #0x00]
	ldrh r3, [r2, #0x00]
	ldr r0, _080055E8 @ =0x0000FFFC
	ands r0, r3
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	orrs r1, r0
	strh r1, [r2, #0x00]
	bx lr
_080055E4: .4byte 0x09ECEB30
_080055E8: .4byte 0x0000FFFC
.syntax divided
