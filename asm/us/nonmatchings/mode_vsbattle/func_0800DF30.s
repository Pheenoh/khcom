.syntax unified
	.align 2, 0
	.global func_0800DF30
	.thumb
	.thumb_func
	.type func_0800DF30, %function
func_0800DF30: @ 0800DF30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800DF48
	b _0800E0BE
_0800DF48:
	adds r5, r6, #0x0
	adds r5, #0x3C
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	movs r3, #0xBE
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _0800DFD0
	movs r7, #0xC0
	lsls r7, r7, #0x01
	adds r0, r6, r7
	ldr r3, [r0, #0x00]
	cmp r3, r1
	bne _0800DFD0
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800DFB0
	ldr r0, _0800DFAC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _0800E018
_0800DFAC: .4byte 0x02039B84
_0800DFB0:
	ldr r0, _0800DFC8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	cmp r2, r3
	bne _0800DFCC
	adds r1, r2, #0x0
	movs r0, #0x01
	mov r3, r8
	orrs r3, r0
	mov r8, r3
	b _0800E018
	.byte 0x00, 0x00
_0800DFC8: .4byte 0x02039B84
_0800DFCC:
	negs r1, r2
	b _0800E018
_0800DFD0:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800DFF8
	ldr r0, _0800DFF4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r7, #0xBE
	lsls r7, r7, #0x01
	adds r1, r6, r7
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r1, r0, #0x08
	b _0800E00C
_0800DFF4: .4byte 0x02039B84
_0800DFF8:
	ldr r0, _0800E028 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r7, #0xBE
	lsls r7, r7, #0x01
	adds r1, r6, r7
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	negs r1, r0
_0800E00C:
	movs r3, #0xC0
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r0, [r0, #0x00]
	muls r0, r2
	asrs r2, r0, #0x08
_0800E018:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0800E02C
	cmp r1, r2
	bne _0800E02C
	movs r7, #0x00
	b _0800E040
_0800E028: .4byte 0x02039B84
_0800E02C:
	cmp r2, #0xFF
	bgt _0800E036
	movs r0, #0x00
	movs r3, #0x00
	b _0800E03A
_0800E036:
	movs r0, #0x00
	movs r3, #0x01
_0800E03A:
	bl AllocObjAffine
	adds r7, r0, #0x0
_0800E040:
	adds r0, r5, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800E084
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x08]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _0800E080 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	movs r5, #0x03
	orrs r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	b _0800E0B6
_0800E080: .4byte 0xFFFFEFFC
_0800E084:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _0800E0CC @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	movs r5, #0x03
	orrs r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
_0800E0B6:
	adds r0, r6, #0x0
	adds r0, #0x28
	bl TaskPoolDraw
_0800E0BE:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800E0CC: .4byte 0xFFFFEFFC
.syntax divided
