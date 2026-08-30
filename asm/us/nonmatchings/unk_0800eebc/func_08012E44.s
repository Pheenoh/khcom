.syntax unified
	.align 2, 0
	.global func_08012E44
	.thumb
	.thumb_func
	.type func_08012E44, %function
func_08012E44: @ 08012E44
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r5, r3, #0x0
	ldr r1, [sp, #0x030]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r9, r1
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08012F56
	bl func_08012674
	ldr r0, _08012EA8 @ =0x02034928
	ldr r0, [r0, #0x00]
	str r6, [r0, #0x10]
	str r7, [r0, #0x14]
	str r5, [r0, #0x18]
	mov r4, sp
	adds r4, #0x06
	str r5, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r6, #0x0
	adds r3, r7, #0x0
	bl func_0801909C
	mov r0, r8
	cmp r0, #0x03
	bne _08012EB0
	ldr r0, _08012EAC @ =0x09EDA588
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	b _08012EC0
	.byte 0x00, 0x00
_08012EA8: .4byte 0x02034928
_08012EAC: .4byte 0x09EDA588
_08012EB0:
	ldr r0, _08012EF0 @ =0x09EDA570
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
_08012EC0:
	ldr r0, _08012EF4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08012EFC
	movs r0, #0x40
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08012EFC
	ldr r0, _08012EF8 @ =0x0000023D
	bl func_0811FE70
	b _08012F04
_08012EF0: .4byte 0x09EDA570
_08012EF4: .4byte 0x02039B84
_08012EF8: .4byte 0x0000023D
_08012EFC:
	movs r0, #0xFC
	lsls r0, r0, #0x01
	bl func_0811FE70
_08012F04:
	movs r0, #0x08
	bl func_08006B34
	ldr r4, _08012F64 @ =0x02034928
	ldr r2, [r4, #0x00]
	ldr r0, _08012F68 @ =0x08012C09
	str r0, [r2, #0x04]
	ldr r0, [sp, #0x024]
	str r0, [r2, #0x28]
	ldr r0, [sp, #0x028]
	str r0, [r2, #0x2C]
	ldr r0, [sp, #0x02C]
	str r0, [r2, #0x30]
	movs r0, #0x0F
	strh r0, [r2, #0x08]
	mov r0, r8
	strh r0, [r2, #0x26]
	ldr r0, [sp, #0x034]
	str r0, [r2, #0x48]
	mov r3, r9
	cmp r3, #0x00
	beq _08012F3C
	ldrh r0, [r2, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
	ldr r0, _08012F6C @ =0xFFFFFF00
	str r0, [r2, #0x1C]
_08012F3C:
	ldr r0, _08012F70 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r4, #0x00]
	ldrh r0, [r2, #0x34]
	movs r1, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08012F56:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08012F64: .4byte 0x02034928
_08012F68: .4byte 0x08012C09
_08012F6C: .4byte 0xFFFFFF00
_08012F70: .4byte 0x02039B84
.syntax divided
