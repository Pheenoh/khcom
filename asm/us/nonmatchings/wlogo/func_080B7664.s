.syntax unified
	.align 2, 0
	.global func_080B7664
	.thumb
	.thumb_func
	.type func_080B7664, %function
func_080B7664: @ 080B7664
	push {lr}
	bl func_08006CAC
	bl func_08000300
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
