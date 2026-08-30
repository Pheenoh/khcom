.syntax unified
	.align 2, 0
	.global func_08005B1C
	.thumb
	.thumb_func
	.type func_08005B1C, %function
func_08005B1C: @ 08005B1C
	ldrh r1, [r0, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x05
	ands r0, r1
	cmp r0, #0x00
	bne _08005B2C
	movs r0, #0x00
	b _08005B2E
_08005B2C:
	movs r0, #0x01
_08005B2E:
	bx lr
.syntax divided
