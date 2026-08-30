.syntax unified
	.align 2, 0
	.global func_08006BB4
	.thumb
	.thumb_func
	.type func_08006BB4, %function
func_08006BB4: @ 08006BB4
	ldr r0, _08006BEC @ =0x04000208
	ldrh r1, [r0, #0x00]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08006BF8
	ldr r0, _08006BF0 @ =0x04000004
	ldrh r1, [r0, #0x00]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08006BF8
	ldr r0, _08006BF4 @ =0x04000200
	ldrh r1, [r0, #0x00]
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08006BF8
	movs r0, #0x80
	lsls r0, r0, #0x13
	ldrh r1, [r0, #0x00]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0x00
	bne _08006BF8
	movs r0, #0x01
	b _08006BFA
_08006BEC: .4byte 0x04000208
_08006BF0: .4byte 0x04000004
_08006BF4: .4byte 0x04000200
_08006BF8:
	movs r0, #0x00
_08006BFA:
	bx lr
.syntax divided
