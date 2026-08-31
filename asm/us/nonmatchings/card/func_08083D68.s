.syntax unified
	.align 2, 0
	.global func_08083D68
	.thumb
	.thumb_func
	.type func_08083D68, %function
func_08083D68: @ 08083D68
	push {lr}
	ldr r0, _08083D78 @ =0x0203A854
	ldr r0, [r0, #0x00]
	bl EwramFree
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08083D78: .4byte 0x0203A854
.syntax divided
