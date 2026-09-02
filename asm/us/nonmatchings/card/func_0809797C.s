.syntax unified
	.align 2, 0
	.global func_0809797C
	.thumb
	.thumb_func
	.type func_0809797C, %function
func_0809797C: @ 0809797C
	push {lr}
	adds r2, r1, #0x0
	ldr r1, _0809798C @ =0x09EE7650
	bl TaskCreate
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0809798C: .4byte 0x09EE7650
.syntax divided
