.syntax unified
	.align 2, 0
	.global func_080E988C
	.thumb
	.thumb_func
	.type func_080E988C, %function
func_080E988C: @ 080E988C
	ldr r1, _080E9894 @ =0x02034FB0
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080E9894: .4byte 0x02034FB0
.syntax divided
