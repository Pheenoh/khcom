.syntax unified
	.align 2, 0
	.global task_emy_27_1
	.thumb
	.thumb_func
	.type task_emy_27_1, %function
task_emy_27_1: @ 0803AC84
	push {r4, r5, r6, lr}
	add sp, #-0x024
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r4, r5, #0x0
	adds r4, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803ACDE
	adds r0, r4, #0x0
	movs r1, #0x00
	add r2, sp, #0x018
	movs r3, #0x00
	bl func_0801C700
	ldr r0, [r4, #0x08]
	ldr r1, [sp, #0x018]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0803ACBC
	ldr r0, _0803ACB8 @ =0x00000FFF
	cmp r2, r0
	ble _0803ACC4
	b _0803ACD4
_0803ACB8: .4byte 0x00000FFF
_0803ACBC:
	subs r1, r1, r0
	ldr r0, _0803ACD0 @ =0x00000FFF
	cmp r1, r0
	bgt _0803ACD4
_0803ACC4:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x12
	b _0803ACDC
	.byte 0x00, 0x00
_0803ACD0: .4byte 0x00000FFF
_0803ACD4:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x13
_0803ACDC:
	str r0, [r1, #0x00]
_0803ACDE:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803ACF0
	cmp r0, #0x13
	beq _0803AD94
	b _0803AEBC
_0803ACF0:
	ldr r0, _0803AD44 @ =0x0813DE7C
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r5, #0x0
	adds r0, #0x10
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	bne _0803AD68
	ldrh r0, [r5, #0x1A]
	cmp r0, #0x00
	bne _0803AD68
	ldr r0, _0803AD48 @ =0x00000267
	bl func_0811FE70
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803AD54
	ldr r0, [r4, #0x04]
	ldr r1, _0803AD4C @ =0xFFFFF400
	adds r0, r0, r1
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	ldr r3, _0803AD50 @ =0xFFFFDE00
	adds r2, r2, r3
	bl func_08013480
	b _0803AD68
	.byte 0x00, 0x00
_0803AD44: .4byte 0x0813DE7C
_0803AD48: .4byte 0x00000267
_0803AD4C: .4byte 0xFFFFF400
_0803AD50: .4byte 0xFFFFDE00
_0803AD54:
	ldr r0, [r4, #0x04]
	movs r1, #0xC0
	lsls r1, r1, #0x04
	adds r0, r0, r1
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	ldr r3, _0803AD90 @ =0xFFFFDE00
	adds r2, r2, r3
	bl func_08013480
_0803AD68:
	movs r0, #0xC8
	str r0, [sp, #0x000]
	movs r0, #0x20
	str r0, [sp, #0x004]
	movs r0, #0x9A
	lsls r0, r0, #0x02
	str r0, [sp, #0x008]
	movs r0, #0x28
	str r0, [sp, #0x00C]
	movs r0, #0x00
	str r0, [sp, #0x010]
	movs r0, #0x14
	str r0, [sp, #0x014]
	adds r0, r5, #0x0
	movs r1, #0x3D
	movs r2, #0x06
	movs r3, #0x14
	bl func_0800C980
	b _0803AEBC
_0803AD90: .4byte 0xFFFFDE00
_0803AD94:
	ldr r0, _0803AE18 @ =0x0813DE7C
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x01
	bl func_08019068
	add r1, sp, #0x01C
	add r2, sp, #0x020
	adds r0, r4, #0x0
	movs r3, #0x00
	bl func_0801C700
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r1, #0x06
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0803ADDC
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [sp, #0x01C]
	ldr r3, [sp, #0x020]
	bl func_0801CB6C
	movs r3, #0xB0
	lsls r3, r3, #0x01
	adds r1, r5, r3
	strb r0, [r1, #0x00]
_0803ADDC:
	ldr r3, _0803AE1C @ =0x08121400
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldrb r0, [r1, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r2, [r4, #0x04]
	adds r2, r2, r0
	str r2, [r4, #0x04]
	ldrb r0, [r1, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r3, #0x00
	ldsh r1, [r0, r3]
	ldr r0, [r4, #0x08]
	subs r0, r0, r1
	str r0, [r4, #0x08]
	ldr r0, [sp, #0x01C]
	cmp r2, r0
	ble _0803AE20
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	b _0803AE2A
_0803AE18: .4byte 0x0813DE7C
_0803AE1C: .4byte 0x08121400
_0803AE20:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x05
	negs r2, r2
	ands r0, r2
_0803AE2A:
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r0, r5, #0x0
	adds r0, #0x10
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	beq _0803AE42
	cmp r0, #0x05
	bne _0803AEA0
_0803AE42:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803AE78
	ldr r1, [r4, #0x04]
	ldr r0, _0803AE74 @ =0xFFFFF000
	adds r1, r1, r0
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	movs r0, #0x14
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x20
	str r0, [sp, #0x008]
	movs r0, #0xC7
	bl func_08011F78
	cmp r0, #0x00
	bne _0803AE98
	b _0803AEA0
	.byte 0x00, 0x00
_0803AE74: .4byte 0xFFFFF000
_0803AE78:
	ldr r1, [r4, #0x04]
	movs r2, #0x80
	lsls r2, r2, #0x05
	adds r1, r1, r2
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	movs r0, #0x14
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x20
	str r0, [sp, #0x008]
	movs r0, #0xC7
	bl func_08011F78
	cmp r0, #0x00
	beq _0803AEA0
_0803AE98:
	movs r0, #0x91
	lsls r0, r0, #0x02
	bl func_0811FE70
_0803AEA0:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r1, r5, r3
	ldrh r2, [r1, #0x00]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r0, #0x78
	ble _0803AEB8
	adds r0, r5, #0x0
	bl func_0800CB4C
	b _0803AEBC
_0803AEB8:
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
_0803AEBC:
	adds r0, r5, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x024
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
