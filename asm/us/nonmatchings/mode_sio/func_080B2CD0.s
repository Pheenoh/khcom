.syntax unified
	.align 2, 0
	.global func_080B2CD0
	.thumb
	.thumb_func
	.type func_080B2CD0, %function
func_080B2CD0: @ 080B2CD0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r5, _080B2F8C @ =0x02034B4C
	ldr r0, [r5, #0x00]
	adds r0, #0x20
	bl AnimUpdate
	adds r1, r0, #0x0
	ldr r0, [r5, #0x00]
	str r1, [r0, #0x18]
	adds r0, #0x38
	bl AnimUpdate
	adds r1, r0, #0x0
	ldr r0, [r5, #0x00]
	str r1, [r0, #0x1C]
	adds r0, #0x5C
	bl AnimUpdate
	adds r1, r0, #0x0
	ldr r0, [r5, #0x00]
	str r1, [r0, #0x58]
	adds r0, #0x8C
	bl AnimUpdate
	ldr r1, [r5, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x88
	str r0, [r2, #0x00]
	ldr r2, [r1, #0x18]
	ldr r3, [r1, #0x08]
	ldr r0, [r1, #0x10]
	str r0, [sp, #0x000]
	movs r7, #0x00
	str r7, [sp, #0x004]
	ldr r0, _080B2F90 @ =0x00000401
	str r0, [sp, #0x008]
	ldr r4, _080B2F94 @ =0x0000FFFF
	str r4, [sp, #0x00C]
	movs r0, #0x48
	movs r1, #0x48
	bl DrawSprite
	ldr r0, [r5, #0x00]
	ldr r2, [r0, #0x1C]
	ldr r3, [r0, #0x0C]
	ldr r0, [r0, #0x14]
	str r0, [sp, #0x000]
	str r7, [sp, #0x004]
	movs r6, #0x80
	lsls r6, r6, #0x03
	str r6, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0xA8
	movs r1, #0x48
	bl DrawSprite
	ldr r4, [r5, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x74
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B2DB6
	adds r0, r4, #0x0
	adds r0, #0x7A
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r1, r4, #0x0
	adds r1, #0x7C
	movs r2, #0x00
	ldsh r1, [r1, r2]
	ldr r2, [r4, #0x58]
	ldr r3, [r4, #0x50]
	ldr r4, [r4, #0x54]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, _080B2F98 @ =0x0000FFC0
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r4, [r5, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x7A
	ldrh r0, [r0, #0x00]
	adds r0, #0x02
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0x0
	adds r1, #0x7C
	ldrh r1, [r1, #0x00]
	subs r1, #0x08
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r4, #0x0
	adds r2, #0x88
	ldr r2, [r2, #0x00]
	adds r3, r4, #0x0
	adds r3, #0x80
	ldr r3, [r3, #0x00]
	adds r4, #0x84
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, _080B2F9C @ =0x0000FFA0
	str r4, [sp, #0x00C]
	bl DrawSprite
_080B2DB6:
	movs r6, #0x00
	mov r9, r5
_080B2DBA:
	mov r3, r9
	ldr r2, [r3, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA5
	adds r0, r0, r6
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B2EB6
	movs r4, #0xFC
	lsls r4, r4, #0x01
	adds r0, r2, r4
	adds r0, r0, r6
	ldrb r0, [r0, #0x00]
	lsls r5, r6, #0x02
	movs r7, #0xD4
	lsls r7, r7, #0x01
	adds r1, r2, r7
	adds r1, r1, r5
	ldr r1, [r1, #0x00]
	movs r3, #0xE8
	lsls r3, r3, #0x01
	adds r2, r2, r3
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	movs r3, #0x01
	bl AllocObjAffine
	mov r10, r0
	mov r7, r9
	ldr r4, [r7, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xB0
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	adds r0, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0x0
	adds r1, #0xD8
	adds r1, r1, r5
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	adds r1, #0x14
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r2, r4, r3
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	movs r7, #0x80
	lsls r7, r7, #0x01
	adds r3, r4, r7
	adds r3, r3, r5
	ldr r3, [r3, #0x00]
	adds r7, #0x28
	adds r4, r4, r7
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	movs r7, #0x80
	lsls r7, r7, #0x03
	mov r8, r7
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r4, _080B2FA0 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl DrawSprite
	ldr r2, _080B2FA4 @ =0x08F70AB0
	ldr r1, _080B2FA8 @ =0x0203AB20
	lsls r0, r6, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x34
	muls r0, r1
	adds r0, r0, r2
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	beq _080B2EB6
	mov r7, r9
	ldr r4, [r7, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xB0
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	adds r0, #0x0D
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r4, #0x0
	adds r1, #0xD8
	adds r1, r1, r5
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	adds r1, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0xC0
	lsls r3, r3, #0x01
	adds r2, r4, r3
	adds r2, r2, r5
	ldr r2, [r2, #0x00]
	movs r5, #0xBC
	lsls r5, r5, #0x01
	adds r3, r4, r5
	ldr r3, [r3, #0x00]
	movs r7, #0xBE
	lsls r7, r7, #0x01
	adds r4, r4, r7
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	mov r4, r10
	str r4, [sp, #0x004]
	mov r5, r8
	str r5, [sp, #0x008]
	ldr r4, _080B2FAC @ =0x0000FFE0
	str r4, [sp, #0x00C]
	bl DrawSprite
_080B2EB6:
	adds r6, #0x01
	cmp r6, #0x09
	bgt _080B2EBE
	b _080B2DBA
_080B2EBE:
	ldr r6, _080B2F8C @ =0x02034B4C
	ldr r1, [r6, #0x00]
	movs r7, #0x83
	lsls r7, r7, #0x02
	adds r0, r1, r7
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B2F2E
	movs r2, #0x82
	lsls r2, r2, #0x02
	adds r0, r1, r2
	ldr r2, [r0, #0x00]
	movs r3, #0x81
	lsls r3, r3, #0x02
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	movs r4, #0xBE
	lsls r4, r4, #0x01
	adds r0, r1, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0xFF
	lsls r0, r0, #0x08
	str r0, [sp, #0x00C]
	movs r0, #0x78
	movs r1, #0x83
	bl DrawSprite
	ldr r4, [r6, #0x00]
	ldr r5, _080B2FB0 @ =0x00000BDC
	adds r0, r4, r5
	movs r7, #0x00
	ldsh r0, [r0, r7]
	ldr r2, _080B2FB4 @ =0x00000BDE
	adds r1, r4, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r5, #0x84
	lsls r5, r5, #0x02
	adds r2, r4, r5
	adds r3, r4, #0x0
	adds r3, #0x84
	ldr r3, [r3, #0x00]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r7, _080B2FB8 @ =0x0000020D
	adds r4, r4, r7
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
_080B2F2E:
	ldr r1, [r6, #0x00]
	movs r2, #0xD8
	lsls r2, r2, #0x02
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B2F7C
	movs r3, #0xD9
	lsls r3, r3, #0x02
	adds r2, r1, r3
	ldr r3, [r1, #0x54]
	movs r4, #0x12
	str r4, [sp, #0x000]
	ldr r5, _080B2FBC @ =0x00000361
	adds r0, r1, r5
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x3A
	movs r1, #0x1B
	bl func_080664D8
	ldr r0, [r6, #0x00]
	movs r7, #0x84
	lsls r7, r7, #0x02
	adds r2, r0, r7
	adds r1, r0, #0x0
	adds r1, #0x84
	ldr r3, [r1, #0x00]
	str r4, [sp, #0x000]
	ldr r1, _080B2FB8 @ =0x0000020D
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x34
	movs r1, #0x2A
	bl func_080664D8
_080B2F7C:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080B2F8C: .4byte 0x02034B4C
_080B2F90: .4byte 0x00000401
_080B2F94: .4byte 0x0000FFFF
_080B2F98: .4byte 0x0000FFC0
_080B2F9C: .4byte 0x0000FFA0
_080B2FA0: .4byte 0x0000FFF0
_080B2FA4: .4byte 0x08F70AB0
_080B2FA8: .4byte 0x0203AB20
_080B2FAC: .4byte 0x0000FFE0
_080B2FB0: .4byte 0x00000BDC
_080B2FB4: .4byte 0x00000BDE
_080B2FB8: .4byte 0x0000020D
_080B2FBC: .4byte 0x00000361
.syntax divided
