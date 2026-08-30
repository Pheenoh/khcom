.syntax unified
	.align 2, 0
	.global func_080147C8
	.thumb
	.thumb_func
	.type func_080147C8, %function
func_080147C8: @ 080147C8
	ldr r2, _080147D4 @ =0x02034928
	ldr r2, [r2, #0x00]
	str r0, [r2, #0x1C]
	str r1, [r2, #0x20]
	bx lr
	.byte 0x00, 0x00
_080147D4: .4byte 0x02034928
.syntax divided
