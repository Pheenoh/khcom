.syntax unified
	.align 2, 0
	.global func_080F7F54
	.thumb
	.thumb_func
	.type func_080F7F54, %function
func_080F7F54: @ 080F7F54
	adds r2, r0, #0x0
	ldr r0, [r2, #0x04]
	cmp r0, #0x0B
	beq _080F7F6C
	ldr r0, [r2, #0x00]
	cmp r0, #0x0B
	beq _080F7F6C
	str r1, [r2, #0x04]
	ldrh r1, [r2, #0x0E]
	movs r0, #0x01
	orrs r0, r1
	strh r0, [r2, #0x0E]
_080F7F6C:
	bx lr
	.byte 0x00, 0x00
.syntax divided
