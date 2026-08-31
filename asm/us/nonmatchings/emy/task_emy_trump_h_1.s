.syntax unified
	.align 2, 0
	.global task_emy_trump_h_1
	.thumb
	.thumb_func
	.type task_emy_trump_h_1, %function
task_emy_trump_h_1: @ 0803ED48
	push {r4, r5, r6, lr}
	add sp, #-0x018
	adds r4, r0, #0x0
	adds r6, r4, #0x0
	adds r6, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803ED66
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x13
	str r0, [r1, #0x00]
_0803ED66:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r1, #0x00]
	cmp r0, #0x03
	bne _0803ED76
	movs r0, #0x12
	str r0, [r1, #0x00]
_0803ED76:
	ldr r0, [r1, #0x00]
	cmp r0, #0x12
	beq _0803EDC4
	cmp r0, #0x13
	bne _0803EE36
	ldr r0, _0803EDB8 @ =0x0813E734
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	ldr r0, _0803EDBC @ =0x0000012B
	str r0, [sp, #0x000]
	movs r0, #0x30
	str r0, [sp, #0x004]
	ldr r0, _0803EDC0 @ =0x0000022E
	str r0, [sp, #0x008]
	movs r0, #0x50
	str r0, [sp, #0x00C]
	movs r0, #0x00
	str r0, [sp, #0x010]
	movs r0, #0x18
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x19
	movs r2, #0x08
	movs r3, #0x0A
	bl func_0800C980
	b _0803EE36
_0803EDB8: .4byte 0x0813E734
_0803EDBC: .4byte 0x0000012B
_0803EDC0: .4byte 0x0000022E
_0803EDC4:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r5, r4, r1
	movs r1, #0x00
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	bne _0803EDF2
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	ldr r0, _0803EE24 @ =0x0000023B
	bl m4aSongNumStart
_0803EDF2:
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r1, _0803EE28 @ =0x08121400
	ldrb r0, [r5, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	str r0, [r2, #0x00]
	ldrh r2, [r5, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x08
	strh r0, [r5, #0x00]
	lsls r0, r0, #0x10
	ldr r1, _0803EE2C @ =0x013F0000
	cmp r0, r1
	ble _0803EE30
	adds r0, r6, #0x0
	bl func_0801B994
	movs r0, #0x00
	b _0803EE40
	.byte 0x00, 0x00
_0803EE24: .4byte 0x0000023B
_0803EE28: .4byte 0x08121400
_0803EE2C: .4byte 0x013F0000
_0803EE30:
	adds r0, r2, #0x0
	adds r0, #0x09
	strh r0, [r5, #0x00]
_0803EE36:
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0803EE40:
	add sp, #0x018
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
