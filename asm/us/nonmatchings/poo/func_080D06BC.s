.syntax unified
	.align 2, 0
	.global func_080D06BC
	.thumb
	.thumb_func
	.type func_080D06BC, %function
func_080D06BC: @ 080D06BC
	ldr r0, _080D06C4 @ =0x02034E24
	ldrh r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_080D06C4: .4byte 0x02034E24
.syntax divided
