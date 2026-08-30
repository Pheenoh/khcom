.syntax unified
	.align 2, 0
	.global func_0810A444
	.thumb
	.thumb_func
	.type func_0810A444, %function
func_0810A444: @ 0810A444
	adds r3, r0, #0x0
	adds r3, #0x38
	movs r2, #0x00
	movs r1, #0x01
	strb r1, [r3, #0x00]
	strh r2, [r0, #0x3A]
	strh r2, [r0, #0x3C]
	bx lr
.syntax divided
