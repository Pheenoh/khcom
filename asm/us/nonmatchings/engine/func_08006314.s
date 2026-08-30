.syntax unified
	.align 2, 0
	.global func_08006314
	.thumb
	.thumb_func
	.type func_08006314, %function
func_08006314: @ 08006314
	ldr r0, _0800632C @ =0x03007568
	ldr r0, [r0, #0x00]
	ldr r1, _08006330 @ =0x00000594
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08006334
	movs r0, #0x00
	b _08006336
	.byte 0x00, 0x00
_0800632C: .4byte 0x03007568
_08006330: .4byte 0x00000594
_08006334:
	movs r0, #0x01
_08006336:
	bx lr
.syntax divided
