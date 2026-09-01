.syntax unified
	.align 2, 0
	.global func_08012F74
	.thumb
	.thumb_func
	.type func_08012F74, %function
func_08012F74: @ 08012F74
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	mov r8, r1
	adds r6, r2, #0x0
	ldr r0, [sp, #0x030]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r10, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08013056
	bl func_08012674
	ldr r5, _08013014 @ =0x02034928
	ldr r0, [r5, #0x00]
	str r7, [r0, #0x10]
	mov r1, r8
	str r1, [r0, #0x14]
	str r6, [r0, #0x18]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	mov r3, r8
	bl WorldToScreen
	ldr r0, _08013018 @ =0x09EDA570
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r0, _0801301C @ =0x0000023D
	bl m4aSongNumStart
	movs r0, #0x08
	bl func_08006B34
	ldr r5, [r5, #0x00]
	ldr r0, _08013020 @ =0x08012C09
	str r0, [r5, #0x04]
	ldr r0, _08013024 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x7C]
	ldr r0, [r1, #0x04]
	str r0, [r5, #0x28]
	ldr r0, [r1, #0x08]
	str r0, [r5, #0x2C]
	ldr r0, [r1, #0x0C]
	str r0, [r5, #0x30]
	mov r0, r9
	strh r0, [r5, #0x08]
	movs r0, #0x01
	strh r0, [r5, #0x26]
	ldr r0, [sp, #0x02C]
	str r0, [r5, #0x48]
	mov r1, r10
	cmp r1, #0x00
	beq _0801302C
	ldrh r0, [r5, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r5, #0x34]
	ldr r0, _08013028 @ =0xFFFFFE80
	b _08013030
_08013014: .4byte 0x02034928
_08013018: .4byte 0x09EDA570
_0801301C: .4byte 0x0000023D
_08013020: .4byte 0x08012C09
_08013024: .4byte 0x02039B84
_08013028: .4byte 0xFFFFFE80
_0801302C:
	movs r0, #0xC0
	lsls r0, r0, #0x01
_08013030:
	str r0, [r5, #0x1C]
	ldr r4, _08013068 @ =0x02034928
	ldr r1, [r4, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x01
	str r0, [r1, #0x20]
	ldr r0, _0801306C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r4, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08013056:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08013068: .4byte 0x02034928
_0801306C: .4byte 0x02039B84
.syntax divided
