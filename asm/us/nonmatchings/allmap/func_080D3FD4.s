.syntax unified
	.align 2, 0
	.global func_080D3FD4
	.thumb
	.thumb_func
	.type func_080D3FD4, %function
func_080D3FD4: @ 080D3FD4
	push {lr}
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006184
	bl func_080063A8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
