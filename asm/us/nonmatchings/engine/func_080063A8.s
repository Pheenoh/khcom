.syntax unified
	.align 2, 0
	.global func_080063A8
	.thumb
	.thumb_func
	.type func_080063A8, %function
func_080063A8: @ 080063A8
	ldr r0, _080063BC @ =0x03007568
	ldr r1, [r0, #0x00]
	ldr r0, _080063C0 @ =0x00000594
	adds r1, r1, r0
	ldrh r2, [r1, #0x00]
	movs r0, #0x02
	orrs r0, r2
	strh r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080063BC: .4byte 0x03007568
_080063C0: .4byte 0x00000594
.syntax divided
