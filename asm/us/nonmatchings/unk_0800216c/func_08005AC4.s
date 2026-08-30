.syntax unified
	.align 2, 0
	.global func_08005AC4
	.thumb
	.thumb_func
	.type func_08005AC4, %function
func_08005AC4: @ 08005AC4
	adds r2, r0, #0x0
	ldr r0, [r2, #0x14]
	cmp r0, #0x00
	beq _08005AF2
	ldrh r1, [r2, #0x08]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _08005AE0
	movs r0, #0x80
	lsls r0, r0, #0x05
	ands r0, r1
	cmp r0, #0x00
	bne _08005AF2
_08005AE0:
	ldrh r0, [r2, #0x0A]
	adds r0, #0x01
	ldrh r1, [r2, #0x0E]
	ldr r2, [r2, #0x14]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldrh r1, [r1, #0x02]
	cmp r0, r1
	bge _08005AF6
_08005AF2:
	movs r0, #0x00
	b _08005AF8
_08005AF6:
	movs r0, #0x01
_08005AF8:
	bx lr
	.byte 0x00, 0x00
.syntax divided
