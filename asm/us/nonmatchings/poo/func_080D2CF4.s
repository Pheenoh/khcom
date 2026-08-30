.syntax unified
	.align 2, 0
	.global func_080D2CF4
	.thumb
	.thumb_func
	.type func_080D2CF4, %function
func_080D2CF4: @ 080D2CF4
	ldr r2, _080D2D08 @ =0x0203C470
	adds r3, r2, #0x0
	adds r3, #0x40
	ldrh r3, [r3, #0x00]
	strh r3, [r0, #0x00]
	adds r2, #0x42
	ldrh r0, [r2, #0x00]
	strh r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080D2D08: .4byte 0x0203C470
.syntax divided
