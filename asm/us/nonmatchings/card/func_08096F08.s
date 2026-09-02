.syntax unified
	.align 2, 0
	.global func_08096F08
	.thumb
	.thumb_func
	.type func_08096F08, %function
func_08096F08: @ 08096F08
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _08096F18 @ =0x09EE7620
	bl TaskCreate
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08096F18: .4byte 0x09EE7620
.syntax divided
