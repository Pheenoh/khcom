.syntax unified
	.align 2, 0
	.global func_08109EF8
	.thumb
	.thumb_func
	.type func_08109EF8, %function
func_08109EF8: @ 08109EF8
	adds r2, r0, #0x0
	ldr r0, _08109F18 @ =0x09EF9DB4
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r2, #0x2C]
	ldr r1, [r1, #0x00]
	cmp r0, r1
	beq _08109F16
	str r1, [r2, #0x2C]
	movs r0, #0x00
	strh r0, [r2, #0x30]
	strh r0, [r2, #0x34]
	strh r0, [r2, #0x32]
	ldr r0, _08109F1C @ =0x0000FFFF
	strh r0, [r2, #0x36]
_08109F16:
	bx lr
_08109F18: .4byte 0x09EF9DB4
_08109F1C: .4byte 0x0000FFFF
.syntax divided
