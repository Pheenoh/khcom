.syntax unified
	.align 2, 0
	.global func_08057E90
	.thumb
	.thumb_func
	.type func_08057E90, %function
func_08057E90: @ 08057E90
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [r5, #0x0C]
	mov r10, r0
	adds r0, r6, #0x0
	adds r0, #0x10
	bl AnimGetGfx
	str r0, [sp, #0x014]
	adds r4, r5, #0x0
	adds r4, #0x40
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08057EDC
	ldr r1, _08057ED4 @ =0x03007554
	movs r2, #0xF1
	lsls r2, r2, #0x04
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	movs r0, #0x06
	movs r1, #0x0C
	bl func_08005810
	ldr r3, _08057ED8 @ =0x00000804
	mov r8, r3
	b _08057EE8
_08057ED4: .4byte 0x03007554
_08057ED8: .4byte 0x00000804
_08057EDC:
	ldr r0, [r4, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
_08057EE8:
	ldrh r1, [r6, #0x0C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08057EF8
	ldr r2, [r6, #0x2C]
	adds r1, r2, #0x0
	b _08057F18
_08057EF8:
	ldr r2, [r6, #0x2C]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _08057F0E
	adds r1, r2, #0x0
	movs r0, #0x01
	mov r3, r8
	orrs r3, r0
	mov r8, r3
	b _08057F18
_08057F0E:
	ldr r0, _08057F28 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x24]
	negs r1, r0
	adds r2, r0, #0x0
_08057F18:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _08057F2C
	cmp r1, r2
	bne _08057F2C
	movs r7, #0x00
	b _08057F40
_08057F28: .4byte 0x02039B84
_08057F2C:
	cmp r2, #0xFF
	bgt _08057F36
	movs r0, #0x00
	movs r3, #0x00
	b _08057F3A
_08057F36:
	movs r0, #0x00
	movs r3, #0x01
_08057F3A:
	bl AllocObjAffine
	adds r7, r0, #0x0
_08057F40:
	ldr r0, _08057F94 @ =0x0000FFF0
	mov r9, r0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x00]
	ldr r3, [r6, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	mov r1, r10
	ldr r0, [r1, #0x04]
	ldr r1, [r6, #0x28]
	bl func_08002A10
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	mov r2, r10
	ldr r3, [r2, #0x04]
	ldr r2, [r5, #0x08]
	str r2, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	mov r2, r9
	str r2, [sp, #0x00C]
	ldr r2, [sp, #0x014]
	bl DrawSprite
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08057F94: .4byte 0x0000FFF0
.syntax divided
