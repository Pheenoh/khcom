.syntax unified
	.align 2, 0
	.global func_080C5D00
	.thumb
	.thumb_func
	.type func_080C5D00, %function
func_080C5D00: @ 080C5D00
	push {lr}
	bl func_080C5D10
	bl func_080C5D24
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
