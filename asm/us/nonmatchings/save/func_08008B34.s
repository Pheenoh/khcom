.syntax unified
	.align 2, 0
	.global func_08008B34
	.thumb
	.thumb_func
	.type func_08008B34, %function
func_08008B34: @ 08008B34
	push {lr}
	bl SetSramFastFunc
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
