.syntax unified
	.align 2, 0
	.global func_080D2CE0
	.thumb
	.thumb_func
	.type func_080D2CE0, %function
func_080D2CE0: @ 080D2CE0
	ldr r2, _080D2CF0 @ =0x0203C470
	adds r3, r2, #0x0
	adds r3, #0x40
	strh r0, [r3, #0x00]
	adds r2, #0x42
	strh r1, [r2, #0x00]
	bx lr
	.byte 0x00, 0x00
_080D2CF0: .4byte 0x0203C470
.syntax divided
