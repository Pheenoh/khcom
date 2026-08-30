.syntax unified
	.align 2, 0
	.global func_08005AFC
	.thumb
	.thumb_func
	.type func_08005AFC, %function
func_08005AFC: @ 08005AFC
	adds r1, r0, #0x0
	ldr r2, [r1, #0x14]
	cmp r2, #0x00
	beq _08005B16
	ldrh r0, [r1, #0x0E]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	ldr r1, [r1, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	b _08005B18
_08005B16:
	movs r0, #0x00
_08005B18:
	bx lr
	.byte 0x00, 0x00
.syntax divided
