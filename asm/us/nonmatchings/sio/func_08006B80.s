.syntax unified
	.align 2, 0
	.global func_08006B80
	.thumb
	.thumb_func
	.type func_08006B80, %function
func_08006B80: @ 08006B80
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _08006B8C
	ldr r0, _08006B98 @ =0x02034046
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
_08006B8C:
	cmp r1, #0x00
	beq _08006B96
	ldr r0, _08006B9C @ =0x02034044
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
_08006B96:
	bx lr
_08006B98: .4byte 0x02034046
_08006B9C: .4byte 0x02034044
.syntax divided
