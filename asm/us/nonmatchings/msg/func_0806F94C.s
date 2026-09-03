.syntax unified
	.align 2, 0
	.global func_0806F94C
	.thumb
	.thumb_func
	.type func_0806F94C, %function
func_0806F94C: @ 0806F94C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	ldrh r4, [r5, #0x3E]
	movs r0, #0xD0
	lsls r0, r0, #0x01
	adds r7, r5, r0
	ldr r1, [r7, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r1, [r0, #0x18]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0x00
	beq _0806F9E0
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _0806F990
	ldr r1, _0806F988 @ =0x00000401
	adds r0, r1, #0x0
	orrs r4, r0
	ldr r0, _0806F98C @ =0x0000F7FF
	ands r4, r0
	b _0806F9FC
_0806F988: .4byte 0x00000401
_0806F98C: .4byte 0x0000F7FF
_0806F990:
	ldr r0, _0806F9C8 @ =0x00000801
	mov r8, r0
	mov r1, r8
	orrs r4, r1
	ldr r0, _0806F9CC @ =0x0000FBFF
	ands r4, r0
	adds r6, r5, #0x0
	adds r6, #0x28
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_0801CE00
	ldr r1, [r7, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0806F9D0
	mov r0, r8
	orrs r4, r0
	adds r0, r6, #0x0
	b _0806FA00
_0806F9C8: .4byte 0x00000801
_0806F9CC: .4byte 0x0000FBFF
_0806F9D0:
	movs r0, #0x01
	orrs r4, r0
	ldr r0, _0806F9DC @ =0x0000F7FF
	ands r4, r0
	adds r0, r6, #0x0
	b _0806FA00
_0806F9DC: .4byte 0x0000F7FF
_0806F9E0:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _0806FA10
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r0, r1, #0x0
	orrs r4, r0
	lsls r0, r4, #0x10
	ldr r1, _0806FA08 @ =0xF7FF0000
	ands r1, r0
	ldr r0, _0806FA0C @ =0xFFFE0000
	ands r0, r1
	lsrs r4, r0, #0x10
_0806F9FC:
	adds r0, r5, #0x0
	adds r0, #0x28
_0806FA00:
	adds r1, r4, #0x0
	bl func_0801CE00
	b _0806FA74
_0806FA08: .4byte 0xF7FF0000
_0806FA0C: .4byte 0xFFFE0000
_0806FA10:
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r9, r0
	mov r1, r9
	orrs r4, r1
	lsls r1, r4, #0x10
	ldr r0, _0806FA5C @ =0xFBFF0000
	ands r0, r1
	ldr r1, _0806FA60 @ =0x0000FFFE
	mov r8, r1
	lsrs r4, r0, #0x10
	ands r4, r1
	adds r6, r5, #0x0
	adds r6, #0x28
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_0801CE00
	ldr r1, [r7, #0x00]
	ldr r2, [r5, #0x00]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x18]
	movs r1, #0x80
	lsls r1, r1, #0x03
	ands r0, r1
	cmp r0, #0x00
	bne _0806FA64
	mov r1, r9
	orrs r1, r4
	mov r0, r8
	ands r1, r0
	adds r0, r6, #0x0
	bl func_0801CE00
	b _0806FA74
_0806FA5C: .4byte 0xFBFF0000
_0806FA60: .4byte 0x0000FFFE
_0806FA64:
	ldr r0, _0806FA80 @ =0x0000F7FF
	ands r4, r0
	mov r1, r8
	ands r4, r1
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_0801CE00
_0806FA74:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0806FA80: .4byte 0x0000F7FF
.syntax divided
