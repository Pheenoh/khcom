.syntax unified
	.align 2, 0
	.global func_080C57A4
	.thumb
	.thumb_func
	.type func_080C57A4, %function
func_080C57A4: @ 080C57A4
	push {lr}
	bl func_08083D68
	bl func_08083DD4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
