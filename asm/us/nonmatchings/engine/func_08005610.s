.syntax unified
	.align 2, 0
	.global func_08005610
	.thumb
	.thumb_func
	.type func_08005610, %function
func_08005610: @ 08005610
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x80
	bne _08005634
	ldr r1, _08005630 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2, #0x00]
	b _08005648
	.byte 0x00, 0x00
_08005630: .4byte 0x09ECEB30
_08005634:
	ldr r1, _0800564C @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r1, [r0, #0x00]
	ldrh r2, [r1, #0x00]
	ldr r0, _08005650 @ =0x0000FF7F
	ands r0, r2
	strh r0, [r1, #0x00]
	ldrh r0, [r1, #0x00]
	strh r0, [r1, #0x00]
_08005648:
	bx lr
	.byte 0x00, 0x00
_0800564C: .4byte 0x09ECEB30
_08005650: .4byte 0x0000FF7F
.syntax divided
