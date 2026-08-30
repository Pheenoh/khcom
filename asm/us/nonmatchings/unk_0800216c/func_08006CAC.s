.syntax unified
	.align 2, 0
	.global func_08006CAC
	.thumb
	.thumb_func
	.type func_08006CAC, %function
func_08006CAC: @ 08006CAC
	ldr r0, _08006CBC @ =0x03006C74
	ldr r0, [r0, #0x00]
	ldr r1, _08006CC0 @ =0x080005A5
	str r1, [r0, #0x00]
	ldr r0, _08006CC4 @ =0x03006C64
	str r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_08006CBC: .4byte 0x03006C74
_08006CC0: .4byte 0x080005A5
_08006CC4: .4byte 0x03006C64
.syntax divided
