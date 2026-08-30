.syntax unified
	.align 2, 0
	.global func_0800443C
	.thumb
	.thumb_func
	.type func_0800443C, %function
func_0800443C: @ 0800443C
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r0, _08004478 @ =0x03007574
	ldr r3, [r0, #0x00]
	ldr r0, _0800447C @ =0x000010A8
	adds r2, r3, r0
	ldrh r0, [r2, #0x00]
	cmp r0, #0x03
	bhi _08004484
	ldrh r1, [r2, #0x00]
	lsls r1, r1, #0x03
	movs r6, #0x84
	lsls r6, r6, #0x05
	adds r0, r3, r6
	adds r0, r0, r1
	str r4, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _08004480 @ =0x00001084
	adds r0, r0, r1
	strh r5, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	ldrh r1, [r2, #0x00]
	strh r0, [r2, #0x00]
	movs r0, #0x01
	b _08004486
_08004478: .4byte 0x03007574
_0800447C: .4byte 0x000010A8
_08004480: .4byte 0x00001084
_08004484:
	movs r0, #0x00
_08004486:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
