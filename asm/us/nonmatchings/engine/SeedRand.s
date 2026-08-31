.syntax unified
	.align 2, 0
	.global SeedRand
	.thumb
	.thumb_func
	.type SeedRand, %function
SeedRand: @ 08006548
	ldr r1, _08006550 @ =0x02034028
	str r0, [r1, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006550: .4byte 0x02034028
.syntax divided
