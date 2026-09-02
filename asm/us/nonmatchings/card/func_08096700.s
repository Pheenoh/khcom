.syntax unified
	.align 2, 0
	.global func_08096700
	.thumb
	.thumb_func
	.type func_08096700, %function
func_08096700: @ 08096700
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _08096710 @ =0x09EE75D8
	bl TaskCreate
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08096710: .4byte 0x09EE75D8
.syntax divided
