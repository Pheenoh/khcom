.syntax unified
	.align 2, 0
	.global func_080063C4
	.thumb
	.thumb_func
	.type func_080063C4, %function
func_080063C4: @ 080063C4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080063E4
	ldr r0, _080063DC @ =0x03007568
	ldr r1, [r0, #0x00]
	ldr r0, _080063E0 @ =0x00000594
	adds r1, r1, r0
	ldrh r2, [r1, #0x00]
	movs r0, #0x04
	orrs r0, r2
	b _080063F2
	.byte 0x00, 0x00
_080063DC: .4byte 0x03007568
_080063E0: .4byte 0x00000594
_080063E4:
	ldr r0, _080063F8 @ =0x03007568
	ldr r1, [r0, #0x00]
	ldr r0, _080063FC @ =0x00000594
	adds r1, r1, r0
	ldrh r2, [r1, #0x00]
	ldr r0, _08006400 @ =0x0000FFFB
	ands r0, r2
_080063F2:
	strh r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080063F8: .4byte 0x03007568
_080063FC: .4byte 0x00000594
_08006400: .4byte 0x0000FFFB
.syntax divided
