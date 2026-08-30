.syntax unified
	.align 2, 0
	.global func_080D06C8
	.thumb
	.thumb_func
	.type func_080D06C8, %function
func_080D06C8: @ 080D06C8
	ldr r0, _080D06D0 @ =0x02034E26
	ldrh r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_080D06D0: .4byte 0x02034E26
.syntax divided
