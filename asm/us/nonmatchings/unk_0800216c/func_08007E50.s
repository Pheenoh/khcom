.syntax unified
	.align 2, 0
	.global func_08007E50
	.thumb
	.thumb_func
	.type func_08007E50, %function
func_08007E50: @ 08007E50
	ldr r0, _08007E58 @ =0x03007570
	movs r1, #0x00
	ldsh r0, [r0, r1]
	bx lr
_08007E58: .4byte 0x03007570
.syntax divided
