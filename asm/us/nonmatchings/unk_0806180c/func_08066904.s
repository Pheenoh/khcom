.syntax unified
	.align 2, 0
	.global func_08066904
	.thumb
	.thumb_func
	.type func_08066904, %function
func_08066904: @ 08066904
	push {lr}
	ldr r0, _08066914 @ =0x08F69BE4
	movs r1, #0x20
	bl LoadObjPalette
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08066914: .4byte 0x08F69BE4
.syntax divided
