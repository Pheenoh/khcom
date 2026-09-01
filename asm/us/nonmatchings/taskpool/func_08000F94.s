.syntax unified
	.align 2, 0
	.global func_08000F94
	.thumb
	.thumb_func
	.type func_08000F94, %function
func_08000F94: @ 08000F94
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2, #0x00]
	ldr r0, _08000FAC @ =0x0000E0FF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r1, #0xA0
	lsls r1, r1, #0x13
	ldr r0, _08000FB0 @ =0x0300749E
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	bx lr
_08000FAC: .4byte 0x0000E0FF
_08000FB0: .4byte 0x0300749E
.syntax divided
