.syntax unified
	.align 2, 0
	.global func_080DEE18
	.thumb
	.thumb_func
	.type func_080DEE18, %function
func_080DEE18: @ 080DEE18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	ldr r1, _080DEE24 @ =0x0203C5AC
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
_080DEE24: .4byte 0x0203C5AC
.syntax divided
