.syntax unified
	.align 2, 0
	.global func_08000F48
	.thumb
	.thumb_func
	.type func_08000F48, %function
func_08000F48: @ 08000F48
	cmp r0, #0x00
	beq _08000F56
	ldrh r1, [r0, #0x18]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08000F5A
_08000F56:
	movs r0, #0x00
	b _08000F5C
_08000F5A:
	movs r0, #0x01
_08000F5C:
	bx lr
	.byte 0x00, 0x00
.syntax divided
