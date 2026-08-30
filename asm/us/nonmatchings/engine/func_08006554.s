.syntax unified
	.align 2, 0
	.global func_08006554
	.thumb
	.thumb_func
	.type func_08006554, %function
func_08006554: @ 08006554
	ldr r2, _08006568 @ =0x02034028
	ldr r1, [r2, #0x00]
	ldr r0, _0800656C @ =0x41C64E6D
	muls r0, r1
	ldr r1, _08006570 @ =0x00003039
	adds r0, r0, r1
	ldr r1, _08006574 @ =0x00007FFF
	ands r0, r1
	str r0, [r2, #0x00]
	bx lr
_08006568: .4byte 0x02034028
_0800656C: .4byte 0x41C64E6D
_08006570: .4byte 0x00003039
_08006574: .4byte 0x00007FFF
.syntax divided
