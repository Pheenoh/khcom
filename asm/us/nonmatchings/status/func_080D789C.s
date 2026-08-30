.syntax unified
	.align 2, 0
	.global func_080D789C
	.thumb
	.thumb_func
	.type func_080D789C, %function
func_080D789C: @ 080D789C
	ldr r0, _080D78A4 @ =0x02034F02
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bx lr
_080D78A4: .4byte 0x02034F02
.syntax divided
