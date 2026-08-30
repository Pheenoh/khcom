.syntax unified
	.align 2, 0
	.global func_0807ABC8
	.thumb
	.thumb_func
	.type func_0807ABC8, %function
func_0807ABC8: @ 0807ABC8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r7, r0, #0x0
	movs r4, #0x00
	movs r1, #0x00
	adds r0, #0xB9
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bcs _0807AC08
	adds r3, r7, #0x0
	adds r3, #0x28
	movs r5, #0x40
	adds r2, r0, #0x0
_0807ABEA:
	lsls r0, r4, #0x02
	adds r0, r3, r0
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x78]
	ands r0, r5
	cmp r0, #0x00
	beq _0807ABFE
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0807ABFE:
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r2
	bcc _0807ABEA
_0807AC08:
	adds r0, r7, #0x0
	adds r0, #0xB9
	mov r9, r0
	ldrb r0, [r0, #0x00]
	cmp r1, r0
	bcs _0807AC16
	b _0807AE64
_0807AC16:
	ldr r5, _0807ACF8 @ =0x02039DD4
	ldr r1, [r5, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xC0
	movs r3, #0x00
	movs r0, #0x00
	strh r0, [r2, #0x00]
	adds r1, #0xE3
	strb r3, [r1, #0x00]
	adds r4, r7, #0x0
	adds r4, #0xC5
	strb r3, [r4, #0x00]
	ldr r6, _0807ACFC @ =0x02039B84
	ldr r3, [r6, #0x00]
	ldr r1, [r3, #0x68]
	ldr r2, [r3, #0x6C]
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x80
	ldr r0, [sp, #0x000]
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r12, r5
	str r4, [sp, #0x008]
	adds r5, r6, #0x0
	cmp r0, #0x00
	bne _0807AD10
	mov r2, r12
	ldr r0, [r2, #0x00]
	mov r2, r9
	ldrb r1, [r2, #0x00]
	adds r0, #0xD0
	strb r1, [r0, #0x00]
	movs r4, #0x00
	movs r0, #0xBA
	adds r0, r0, r7
	mov r10, r0
	ldrb r1, [r2, #0x00]
	cmp r4, r1
	bcs _0807ACB0
_0807AC68:
	mov r2, r12
	ldr r1, [r2, #0x00]
	lsls r2, r4, #0x02
	adds r1, r1, r2
	adds r0, r7, #0x0
	adds r0, #0x28
	adds r3, r0, r2
	ldr r0, [r3, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r3, #0x00]
	adds r2, #0x32
	adds r0, #0xA0
	strb r2, [r0, #0x00]
	ldr r2, [r3, #0x00]
	ldr r0, [r2, #0x48]
	ldrh r1, [r0, #0x1E]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0807AC96
	ldr r1, [r2, #0x3C]
	movs r0, #0x01
	strb r0, [r1, #0x0A]
_0807AC96:
	ldr r2, [r3, #0x00]
	ldr r0, [r2, #0x78]
	movs r1, #0xA0
	lsls r1, r1, #0x08
	orrs r0, r1
	str r0, [r2, #0x78]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, r9
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bcc _0807AC68
_0807ACB0:
	mov r1, r12
	ldr r0, [r1, #0x00]
	mov r2, r10
	ldrb r1, [r2, #0x00]
	adds r0, #0xC2
	strh r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	adds r0, #0xA4
	movs r1, #0x01
	mov r8, r1
	mov r2, r8
	strb r2, [r0, #0x00]
	ldr r6, [r5, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	movs r2, #0x80
	movs r3, #0x00
	orrs r0, r2
	ldr r4, _0807AD00 @ =0x00000400
	ldr r5, _0807AD04 @ =0x00000000
	adds r2, r0, #0x0
	orrs r2, r4
	adds r3, r1, #0x0
	ldr r4, _0807AD08 @ =0x08000000
	ldr r5, _0807AD0C @ =0x00000000
	adds r0, r2, #0x0
	orrs r0, r4
	str r0, [r6, #0x68]
	str r1, [r6, #0x6C]
	mov r1, r12
	ldr r0, [r1, #0x00]
	adds r0, #0xE1
	mov r2, r8
	strb r2, [r0, #0x00]
	b _0807AD76
	.byte 0x00, 0x00
_0807ACF8: .4byte 0x02039DD4
_0807ACFC: .4byte 0x02039B84
_0807AD00: .4byte 0x00000400
_0807AD04: .4byte 0x00000000
_0807AD08: .4byte 0x08000000
_0807AD0C: .4byte 0x00000000
_0807AD10:
	adds r0, r3, #0x0
	adds r0, #0xA4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0807AD1C
	b _0807AE64
_0807AD1C:
	movs r0, #0x20
	ldr r1, [sp, #0x000]
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0807AD5A
	adds r0, r7, #0x0
	bl func_0807A80C
	ldr r0, [r6, #0x00]
	ldr r1, [r0, #0x68]
	ldr r2, [r0, #0x6C]
	ldr r4, _0807AD50 @ =0x00000000
	ldr r3, _0807AD4C @ =0x08000000
	orrs r1, r3
	str r1, [r0, #0x68]
	str r2, [r0, #0x6C]
	movs r0, #0xBA
	adds r0, r0, r7
	mov r10, r0
	b _0807AD76
	.byte 0x00, 0x00
_0807AD4C: .4byte 0x08000000
_0807AD50: .4byte 0x00000000
_0807AD54:
	ldr r0, [r0, #0x3C]
	strb r1, [r0, #0x0A]
	b _0807AE0E
_0807AD5A:
	adds r0, r7, #0x0
	bl func_0807A80C
	ldr r0, [r6, #0x00]
	ldr r1, [r0, #0x68]
	ldr r2, [r0, #0x6C]
	ldr r4, _0807ADAC @ =0x00000000
	ldr r3, _0807ADA8 @ =0x08000000
	orrs r1, r3
	str r1, [r0, #0x68]
	str r2, [r0, #0x6C]
	movs r1, #0xBA
	adds r1, r1, r7
	mov r10, r1
_0807AD76:
	movs r4, #0x00
	mov r2, r9
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	bcs _0807ADD6
	movs r3, #0x01
	ldr r5, _0807ADB0 @ =0x02039B84
_0807AD84:
	lsls r0, r4, #0x02
	adds r1, r7, #0x0
	adds r1, #0x28
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	ldr r2, [r0, #0x3C]
	movs r0, #0x00
	strb r0, [r2, #0x07]
	ldr r2, [r1, #0x00]
	ldr r0, [r2, #0x48]
	ldrh r1, [r0, #0x1E]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0807ADB4
	ldr r0, [r2, #0x3C]
	b _0807ADC6
	.byte 0x00, 0x00
_0807ADA8: .4byte 0x08000000
_0807ADAC: .4byte 0x00000000
_0807ADB0: .4byte 0x02039B84
_0807ADB4:
	cmp r4, #0x00
	bne _0807ADC8
	ldr r0, [r5, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x0F
	beq _0807ADC8
	ldr r0, [r7, #0x28]
	ldr r0, [r0, #0x3C]
_0807ADC6:
	strb r3, [r0, #0x0A]
_0807ADC8:
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, r9
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bcc _0807AD84
_0807ADD6:
	adds r0, r7, #0x0
	movs r1, #0x00
	bl func_0807885C
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0807AE0E
	movs r4, #0x00
	mov r1, r9
	ldrb r0, [r1, #0x00]
	cmp r4, r0
	bcs _0807AE0E
	adds r3, r7, #0x0
	adds r3, #0x28
	adds r2, r0, #0x0
_0807ADF4:
	lsls r0, r4, #0x02
	adds r0, r3, r0
	ldr r0, [r0, #0x00]
	adds r1, r0, #0x0
	adds r1, #0x46
	ldrb r1, [r1, #0x00]
	cmp r1, #0x00
	beq _0807AD54
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r2
	bcc _0807ADF4
_0807AE0E:
	movs r4, #0x00
	mov r2, r9
	ldrb r2, [r2, #0x00]
	cmp r4, r2
	bcs _0807AE44
	movs r6, #0x00
	adds r5, r7, #0x0
	adds r5, #0x1C
	adds r3, r7, #0x0
	adds r3, #0x28
_0807AE22:
	lsls r2, r4, #0x02
	adds r1, r5, r2
	adds r2, r3, r2
	ldr r0, [r2, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [r2, #0x00]
	adds r0, #0xA1
	movs r1, #0x05
	strb r1, [r0, #0x00]
	str r6, [r2, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, r9
	ldrb r0, [r0, #0x00]
	cmp r4, r0
	bcc _0807AE22
_0807AE44:
	bl func_0807BC08
	movs r4, #0x00
	mov r1, r9
	strb r4, [r1, #0x00]
	ldr r0, _0807AE74 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xDE
	strb r4, [r0, #0x00]
	mov r2, r10
	strb r4, [r2, #0x00]
	adds r0, r7, #0x0
	bl func_0807AE78
	ldr r0, [sp, #0x008]
	strb r4, [r0, #0x00]
_0807AE64:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0807AE74: .4byte 0x02039DD4
.syntax divided
