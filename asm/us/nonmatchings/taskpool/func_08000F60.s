.syntax unified
	.align 2, 0
	.global func_08000F60
	.thumb
	.thumb_func
	.type func_08000F60, %function
func_08000F60: @ 08000F60
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _08000F7C
	cmp r1, #0x00
	beq _08000F7C
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, r1
	bne _08000F7C
	ldrh r1, [r2, #0x18]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08000F80
_08000F7C:
	movs r0, #0x00
	b _08000F82
_08000F80:
	movs r0, #0x01
_08000F82:
	bx lr
.syntax divided
