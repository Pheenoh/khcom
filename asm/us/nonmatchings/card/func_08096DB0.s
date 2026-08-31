.syntax unified
	.align 2, 0
	.global func_08096DB0
	.thumb
	.thumb_func
	.type func_08096DB0, %function
func_08096DB0: @ 08096DB0
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _08096DC0 @ =0x09EE75F0
	bl TaskCreate
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08096DC0: .4byte 0x09EE75F0
.syntax divided
