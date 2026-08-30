.syntax unified
	.align 2, 0
	.global func_080D6294
	.thumb
	.thumb_func
	.type func_080D6294, %function
func_080D6294: @ 080D6294
	ldr r0, _080D62A0 @ =0x02034E98
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	bhi _080D62A4
	movs r0, #0x00
	b _080D62A6
_080D62A0: .4byte 0x02034E98
_080D62A4:
	movs r0, #0x01
_080D62A6:
	bx lr
.syntax divided
