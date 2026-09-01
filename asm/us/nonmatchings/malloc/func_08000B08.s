.syntax unified
	.align 2, 0
	.global func_08000B08
	.thumb
	.thumb_func
	.type func_08000B08, %function
func_08000B08: @ 08000B08
	adds r3, r0, #0x0
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08000B12
	str r3, [r1, #0x00]
_08000B12:
	ldr r0, [r2, #0x00]
	str r0, [r3, #0x04]
	cmp r0, #0x00
	beq _08000B1C
	str r3, [r0, #0x08]
_08000B1C:
	movs r0, #0x00
	str r0, [r3, #0x08]
	str r3, [r2, #0x00]
	bx lr
.syntax divided
