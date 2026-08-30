.syntax unified
	.align 2, 0
	.global func_080034D8
	.thumb
	.thumb_func
	.type func_080034D8, %function
func_080034D8: @ 080034D8
	ldr r1, _080034E4 @ =0x030074C8
	ldr r1, [r1, #0x00]
	ldr r2, _080034E8 @ =0x00002BAF
	adds r1, r1, r2
	strb r0, [r1, #0x00]
	bx lr
_080034E4: .4byte 0x030074C8
_080034E8: .4byte 0x00002BAF
.syntax divided
