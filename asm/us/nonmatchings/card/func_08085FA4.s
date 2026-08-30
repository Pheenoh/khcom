.syntax unified
	.align 2, 0
	.global func_08085FA4
	.thumb
	.thumb_func
	.type func_08085FA4, %function
func_08085FA4: @ 08085FA4
	ldr r0, _08085FAC @ =0x02034AB0
	ldrb r0, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08085FAC: .4byte 0x02034AB0
.syntax divided
