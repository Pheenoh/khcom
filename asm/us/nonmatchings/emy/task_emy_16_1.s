.syntax unified
	.align 2, 0
	.global task_emy_16_1
	.thumb
	.thumb_func
	.type task_emy_16_1, %function
task_emy_16_1: @ 08038C10
	push {r4, r5, r6, r7, lr}
	add sp, #-0x024
	adds r6, r0, #0x0
	adds r7, r6, #0x0
	adds r5, r6, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08038C80
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	ldr r1, _08038C48 @ =0x09EDB0B0
	ldr r1, [r1, #0x00]
	bl func_08000F60
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08038C4C
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x12
	b _08038C74
	.byte 0x00, 0x00
_08038C48: .4byte 0x09EDB0B0
_08038C4C:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08038C62
	cmp r1, #0x01
	beq _08038C6C
	b _08038C76
_08038C62:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x12
	b _08038C74
_08038C6C:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x13
_08038C74:
	str r0, [r1, #0x00]
_08038C76:
	movs r0, #0xD0
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x00
	strb r0, [r1, #0x00]
_08038C80:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _08038C92
	cmp r0, #0x13
	beq _08038D58
	b _08038DFE
_08038C92:
	ldr r0, _08038CE4 @ =0x0813D9AC
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r6, #0x0
	adds r0, #0x10
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bne _08038D26
	ldrh r0, [r6, #0x1A]
	cmp r0, #0x00
	bne _08038D26
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	cmp r1, #0x00
	beq _08038CEC
	ldr r0, [r5, #0x04]
	ldr r1, _08038CE8 @ =0xFFFFF000
	adds r0, r0, r1
	str r0, [sp, #0x004]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x008]
	ldr r0, [r5, #0x0C]
	adds r0, r0, r1
	str r0, [sp, #0x00C]
	add r1, sp, #0x004
	movs r0, #0x01
	strh r0, [r1, #0x12]
	b _08038D06
_08038CE4: .4byte 0x0813D9AC
_08038CE8: .4byte 0xFFFFF000
_08038CEC:
	ldr r0, [r5, #0x04]
	movs r2, #0x80
	lsls r2, r2, #0x05
	adds r0, r0, r2
	str r0, [sp, #0x004]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x008]
	ldr r0, [r5, #0x0C]
	ldr r2, _08038D50 @ =0xFFFFF000
	adds r0, r0, r2
	str r0, [sp, #0x00C]
	add r0, sp, #0x004
	strh r1, [r0, #0x12]
_08038D06:
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r1, _08038D54 @ =0x09EDB0C8
	add r2, sp, #0x004
	bl TaskCreate
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r0, #0xD0
	lsls r0, r0, #0x01
	adds r1, r7, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_08038D26:
	movs r1, #0xD0
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08038DFE
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r0, r7, r2
	ldr r0, [r0, #0x00]
	ldr r1, _08038D54 @ =0x09EDB0C8
	ldr r1, [r1, #0x00]
	bl func_08000F60
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08038DFE
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _08038DFE
_08038D50: .4byte 0xFFFFF000
_08038D54: .4byte 0x09EDB0C8
_08038D58:
	ldr r0, _08038DB0 @ =0x0813D9AC
	adds r1, r7, #0x0
	adds r1, #0x10
	ldr r2, [r7, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x0A
	bne _08038DEC
	ldrh r0, [r6, #0x1A]
	cmp r0, #0x00
	bne _08038DEC
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	cmp r1, #0x00
	beq _08038DBC
	ldr r0, [r5, #0x04]
	ldr r1, _08038DB4 @ =0xFFFFF400
	adds r0, r0, r1
	str r0, [sp, #0x004]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x008]
	ldr r0, [r5, #0x0C]
	ldr r2, _08038DB8 @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [sp, #0x00C]
	add r1, sp, #0x004
	movs r0, #0x01
	strh r0, [r1, #0x12]
	b _08038DD6
	.byte 0x00, 0x00
_08038DB0: .4byte 0x0813D9AC
_08038DB4: .4byte 0xFFFFF400
_08038DB8: .4byte 0xFFFFFE00
_08038DBC:
	ldr r0, [r5, #0x04]
	movs r2, #0xC0
	lsls r2, r2, #0x04
	adds r0, r0, r2
	str r0, [sp, #0x004]
	ldr r0, [r5, #0x08]
	str r0, [sp, #0x008]
	ldr r0, [r5, #0x0C]
	ldr r2, _08038E1C @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [sp, #0x00C]
	add r0, sp, #0x004
	strh r1, [r0, #0x12]
_08038DD6:
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r7, r1
	ldr r1, _08038E20 @ =0x09EDB0B0
	add r2, sp, #0x004
	bl TaskCreate
	movs r2, #0xC4
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
_08038DEC:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08038DFE
	adds r0, r6, #0x0
	bl func_0800CB4C
_08038DFE:
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r7, r1
	bl TaskPoolUpdate
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x024
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08038E1C: .4byte 0xFFFFFE00
_08038E20: .4byte 0x09EDB0B0
.syntax divided
