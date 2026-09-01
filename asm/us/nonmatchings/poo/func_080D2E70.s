.syntax unified
	.align 2, 0
	.global func_080D2E70
	.thumb
	.thumb_func
	.type func_080D2E70, %function
func_080D2E70: @ 080D2E70
	lsls r0, r0, #0x10
	ldr r2, _080D2E80 @ =0x0203C4B4
	ldr r2, [r2, #0x00]
	lsrs r0, r0, #0x0D
	adds r2, r2, r0
	strb r1, [r2, #0x06]
	bx lr
	.byte 0x00, 0x00
_080D2E80: .4byte 0x0203C4B4
.syntax divided
