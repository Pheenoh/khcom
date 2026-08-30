.syntax unified
	.align 2, 0
	.global func_0801A920
	.thumb
	.thumb_func
	.type func_0801A920, %function
func_0801A920: @ 0801A920
	push {r4, lr}
	adds r4, r2, #0x0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r2, _0801A970 @ =0x02039B84
	ldr r2, [r2, #0x00]
	mov r12, r2
	adds r2, #0xDA
	strh r0, [r2, #0x00]
	adds r2, #0x02
	strh r1, [r2, #0x00]
	adds r2, #0x02
	strh r4, [r2, #0x00]
	adds r2, #0x02
	strh r3, [r2, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r0, r1
	lsls r0, r0, #0x07
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r4, r4, r3
	lsls r4, r4, #0x07
	ldr r2, _0801A974 @ =0xFFFFE000
	adds r1, r4, #0x0
	bl func_0801C274
	pop {r4}
	pop {r0}
	bx r0
_0801A970: .4byte 0x02039B84
_0801A974: .4byte 0xFFFFE000
.syntax divided
