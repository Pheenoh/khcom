.syntax unified
	.align 2, 0
	.global func_08005490
	.thumb
	.thumb_func
	.type func_08005490, %function
func_08005490: @ 08005490
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _080054AC
	ldr r1, _080054A8 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	movs r1, #0x40
	orrs r0, r1
	b _080054BA
	.byte 0x00, 0x00
_080054A8: .4byte 0x09ECEB30
_080054AC:
	ldr r1, _080054C0 @ =0x09ECEB30
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	ldr r0, _080054C4 @ =0x0000FFBF
	ands r0, r1
_080054BA:
	strh r0, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
_080054C0: .4byte 0x09ECEB30
_080054C4: .4byte 0x0000FFBF
.syntax divided
