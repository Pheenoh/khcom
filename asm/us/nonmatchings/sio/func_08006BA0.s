.syntax unified
	.align 2, 0
	.global func_08006BA0
	.thumb
	.thumb_func
	.type func_08006BA0, %function
func_08006BA0: @ 08006BA0
	ldrh r1, [r0, #0x14]
	ldrh r0, [r0, #0x16]
	muls r0, r1
	bx lr
.syntax divided
