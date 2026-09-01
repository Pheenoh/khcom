.syntax unified
	.align 2, 0
	.global func_080AF70C
	.thumb
	.thumb_func
	.type func_080AF70C, %function
func_080AF70C: @ 080AF70C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	ldr r7, _080AFA64 @ =0x02034B40
	ldr r0, [r7, #0x00]
	adds r0, #0x20
	bl AnimUpdate
	adds r1, r0, #0x0
	ldr r0, [r7, #0x00]
	str r1, [r0, #0x18]
	adds r0, #0x38
	bl AnimUpdate
	adds r1, r0, #0x0
	ldr r0, [r7, #0x00]
	str r1, [r0, #0x1C]
	movs r1, #0xE2
	lsls r1, r1, #0x01
	adds r0, r0, r1
	bl AnimUpdate
	ldr r4, [r7, #0x00]
	movs r2, #0xE0
	lsls r2, r2, #0x01
	adds r1, r4, r2
	str r0, [r1, #0x00]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x10]
	str r0, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r0, #0x01
	str r0, [sp, #0x008]
	ldr r4, _080AFA68 @ =0x0000FFF0
	str r4, [sp, #0x00C]
	movs r0, #0x3C
	movs r1, #0x58
	bl DrawSprite
	ldr r0, [r7, #0x00]
	ldr r2, [r0, #0x1C]
	ldr r3, [r0, #0x0C]
	ldr r0, [r0, #0x14]
	str r0, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0xB4
	movs r1, #0x58
	bl DrawSprite
	ldr r1, _080AFA6C @ =0x09EF1318
	ldr r4, [r7, #0x00]
	ldr r2, _080AFA70 @ =0x00000417
	adds r0, r4, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x05
	adds r0, r0, r1
	ldrh r0, [r0, #0x1E]
	adds r0, #0x6C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r2, r4, #0x0
	adds r2, #0x54
	adds r1, r4, #0x0
	adds r1, #0xF4
	ldr r3, [r1, #0x00]
	movs r1, #0x14
	str r1, [sp, #0x000]
	adds r4, #0x50
	ldrb r1, [r4, #0x00]
	str r1, [sp, #0x004]
	movs r1, #0x04
	bl func_080664D8
	ldr r1, [r7, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xFC
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	movs r4, #0xF2
	lsls r4, r4, #0x08
	str r4, [sp, #0x000]
	adds r0, r1, #0x0
	adds r0, #0xF8
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x10
	movs r1, #0x90
	bl func_080664D8
	ldr r1, [r7, #0x00]
	movs r5, #0xAA
	lsls r5, r5, #0x01
	adds r2, r1, r5
	movs r3, #0xD2
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0xA8
	lsls r4, r4, #0x01
	adds r0, r1, r4
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x88
	movs r1, #0x90
	bl func_080664D8
	ldr r4, [r7, #0x00]
	movs r6, #0xFD
	lsls r6, r6, #0x01
	adds r0, r4, r6
	ldrh r0, [r0, #0x00]
	lsrs r0, r0, #0x03
	movs r5, #0x03
	mov r10, r5
	ands r0, r5
	negs r0, r0
	adds r0, #0x58
	movs r2, #0xF6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	ldr r2, [r1, #0x00]
	movs r5, #0xF2
	lsls r5, r5, #0x01
	adds r1, r4, r5
	ldr r3, [r1, #0x00]
	movs r1, #0xF4
	lsls r1, r1, #0x01
	mov r9, r1
	add r4, r9
	ldr r1, [r4, #0x00]
	str r1, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r1, #0xFF
	lsls r1, r1, #0x08
	mov r8, r1
	str r1, [sp, #0x00C]
	movs r1, #0x02
	bl DrawSprite
	ldr r4, [r7, #0x00]
	adds r6, r4, r6
	ldrh r0, [r6, #0x00]
	lsrs r0, r0, #0x03
	mov r2, r10
	ands r0, r2
	adds r0, #0xE0
	movs r3, #0xF8
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldr r2, [r1, #0x00]
	adds r5, r4, r5
	ldr r3, [r5, #0x00]
	add r4, r9
	ldr r1, [r4, #0x00]
	str r1, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	mov r5, r8
	str r5, [sp, #0x00C]
	movs r1, #0x02
	bl DrawSprite
	ldr r1, [r7, #0x00]
	movs r2, #0xDA
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080AF910
	movs r3, #0xD8
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldr r2, [r0, #0x00]
	movs r4, #0xD4
	lsls r4, r4, #0x01
	adds r0, r1, r4
	ldr r3, [r0, #0x00]
	movs r5, #0xD6
	lsls r5, r5, #0x01
	adds r0, r1, r5
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x80
	lsls r0, r0, #0x02
	str r0, [sp, #0x00C]
	movs r0, #0x48
	movs r1, #0x26
	bl DrawSprite
	ldr r1, [r7, #0x00]
	movs r2, #0xF0
	lsls r2, r2, #0x01
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080AF910
	adds r5, #0x30
	adds r0, r1, r5
	movs r2, #0x00
	ldsb r2, [r1, r2]
	lsls r1, r2, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x09
	movs r3, #0xA8
	lsls r3, r3, #0x06
	adds r1, r1, r3
	bl func_0805F1C0
	ldr r4, [r7, #0x00]
	adds r5, r4, r5
	ldr r1, [r5, #0x00]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	movs r5, #0xE0
	lsls r5, r5, #0x01
	adds r0, r4, r5
	ldr r2, [r0, #0x00]
	movs r7, #0xDC
	lsls r7, r7, #0x01
	adds r0, r4, r7
	ldr r3, [r0, #0x00]
	movs r0, #0xDE
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0x40
	bl DrawSprite
_080AF910:
	ldr r6, _080AFA64 @ =0x02034B40
	ldr r1, [r6, #0x00]
	movs r5, #0x8A
	lsls r5, r5, #0x02
	adds r0, r1, r5
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080AF980
	movs r7, #0x89
	lsls r7, r7, #0x02
	adds r0, r1, r7
	ldr r2, [r0, #0x00]
	movs r3, #0x87
	lsls r3, r3, #0x02
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	movs r4, #0x88
	lsls r4, r4, #0x02
	adds r0, r1, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0xF0
	lsls r0, r0, #0x08
	str r0, [sp, #0x00C]
	movs r0, #0x78
	movs r1, #0x83
	bl DrawSprite
	ldr r4, [r6, #0x00]
	ldr r5, _080AFA74 @ =0x00000412
	adds r0, r4, r5
	movs r7, #0x00
	ldsh r0, [r0, r7]
	ldr r2, _080AFA78 @ =0x00000414
	adds r1, r4, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r5, #0x8B
	lsls r5, r5, #0x02
	adds r2, r4, r5
	ldr r7, _080AFA7C @ =0x0000040C
	adds r3, r4, r7
	ldr r3, [r3, #0x00]
	movs r5, #0x14
	str r5, [sp, #0x000]
	ldr r5, _080AFA80 @ =0x00000229
	adds r4, r4, r5
	ldrb r4, [r4, #0x00]
	str r4, [sp, #0x004]
	bl func_080664D8
_080AF980:
	ldr r1, [r6, #0x00]
	movs r7, #0x81
	lsls r7, r7, #0x02
	adds r0, r1, r7
	ldr r2, [r0, #0x00]
	movs r3, #0xFE
	lsls r3, r3, #0x01
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	movs r4, #0x83
	lsls r4, r4, #0x02
	adds r0, r1, r4
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r4, #0xF1
	lsls r4, r4, #0x08
	str r4, [sp, #0x00C]
	movs r0, #0x20
	movs r1, #0x18
	bl DrawSprite
	ldr r1, [r6, #0x00]
	adds r7, #0x04
	adds r0, r1, r7
	ldr r2, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x02
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	adds r7, #0x08
	adds r0, r1, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	movs r0, #0x84
	movs r1, #0x18
	bl DrawSprite
	ldr r4, [r6, #0x00]
	movs r1, #0xFC
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080AFA44
	ldr r0, _080AFA84 @ =0x02039828
	ldr r1, [r0, #0x00]
	movs r0, #0x65
	muls r1, r0
	adds r1, #0x2C
	ldr r2, _080AFA88 @ =0x09EF14B8
	ldr r3, _080AFA8C @ =0x00000216
	adds r0, r4, r3
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r7, #0x16
	adds r1, r4, r7
	ldrh r1, [r1, #0x00]
	lsrs r1, r1, #0x03
	movs r2, #0x03
	ands r1, r2
	negs r1, r1
	lsrs r2, r1, #0x1F
	adds r1, r1, r2
	asrs r1, r1, #0x01
	adds r1, #0x16
	subs r3, #0x22
	adds r2, r4, r3
	ldr r2, [r2, #0x00]
	subs r7, #0x16
	adds r3, r4, r7
	ldr r3, [r3, #0x00]
	adds r7, #0x04
	adds r4, r4, r7
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	str r5, [sp, #0x008]
	movs r4, #0xF0
	lsls r4, r4, #0x08
	str r4, [sp, #0x00C]
	bl DrawSprite
_080AFA44:
	ldr r0, [r6, #0x00]
	movs r2, #0xFD
	lsls r2, r2, #0x01
	adds r1, r0, r2
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080AFA64: .4byte 0x02034B40
_080AFA68: .4byte 0x0000FFF0
_080AFA6C: .4byte 0x09EF1318
_080AFA70: .4byte 0x00000417
_080AFA74: .4byte 0x00000412
_080AFA78: .4byte 0x00000414
_080AFA7C: .4byte 0x0000040C
_080AFA80: .4byte 0x00000229
_080AFA84: .4byte 0x02039828
_080AFA88: .4byte 0x09EF14B8
_080AFA8C: .4byte 0x00000216
.syntax divided
