.syntax unified
	.align 2, 0
	.global func_08096DC4
	.thumb
	.thumb_func
	.type func_08096DC4, %function
func_08096DC4: @ 08096DC4
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _08096DD4 @ =0x09EE7608
	bl TaskCreate
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08096DD4: .4byte 0x09EE7608
.syntax divided
