.syntax unified
	.align 2, 0
	.global func_080E9338
	.thumb
	.thumb_func
	.type func_080E9338, %function
func_080E9338: @ 080E9338
	ldr r1, _080E9340 @ =0x02034F88
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_080E9340: .4byte 0x02034F88
.syntax divided
