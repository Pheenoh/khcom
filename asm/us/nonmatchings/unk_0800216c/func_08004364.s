.syntax unified
	.align 2, 0
	.global func_08004364
	.thumb
	.thumb_func
	.type func_08004364, %function
func_08004364: @ 08004364
	ldr r0, _0800439C @ =0x03007574
	ldr r0, [r0, #0x00]
	movs r2, #0x85
	lsls r2, r2, #0x05
	adds r1, r0, r2
	ldrh r2, [r1, #0x00]
	movs r2, #0x00
	strh r2, [r1, #0x00]
	ldr r3, _080043A0 @ =0x000010A2
	adds r1, r0, r3
	ldrh r3, [r1, #0x00]
	strh r2, [r1, #0x00]
	ldr r3, _080043A4 @ =0x000010A4
	adds r1, r0, r3
	ldrh r3, [r1, #0x00]
	strh r2, [r1, #0x00]
	ldr r3, _080043A8 @ =0x000010A6
	adds r1, r0, r3
	ldrh r3, [r1, #0x00]
	strh r2, [r1, #0x00]
	ldr r3, _080043AC @ =0x000010A8
	adds r1, r0, r3
	ldrh r3, [r1, #0x00]
	strh r2, [r1, #0x00]
	ldr r1, _080043B0 @ =0x000010AC
	adds r0, r0, r1
	str r2, [r0, #0x00]
	bx lr
_0800439C: .4byte 0x03007574
_080043A0: .4byte 0x000010A2
_080043A4: .4byte 0x000010A4
_080043A8: .4byte 0x000010A6
_080043AC: .4byte 0x000010A8
_080043B0: .4byte 0x000010AC
.syntax divided
