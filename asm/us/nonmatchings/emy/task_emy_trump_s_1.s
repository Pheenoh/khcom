.syntax unified
	.align 2, 0
	.global task_emy_trump_s_1
	.thumb
	.thumb_func
	.type task_emy_trump_s_1, %function
task_emy_trump_s_1: @ 0803EE74
	push {r4, r5, r6, lr}
	add sp, #-0x018
	adds r4, r0, #0x0
	adds r6, r4, #0x0
	adds r6, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803EE92
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x13
	str r0, [r1, #0x00]
_0803EE92:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r1, #0x00]
	cmp r0, #0x03
	bne _0803EEA2
	movs r0, #0x12
	str r0, [r1, #0x00]
_0803EEA2:
	ldr r0, [r1, #0x00]
	cmp r0, #0x12
	beq _0803EF0C
	cmp r0, #0x13
	bne _0803EF7E
	ldr r0, _0803EF00 @ =0x0813E7B4
	adds r1, r4, #0x0
	adds r1, #0x10
	ldr r2, [r4, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r0, #0x95
	lsls r0, r0, #0x01
	str r0, [sp, #0x000]
	movs r0, #0x46
	str r0, [sp, #0x004]
	ldr r0, _0803EF04 @ =0x0000022F
	str r0, [sp, #0x008]
	movs r0, #0x10
	str r0, [sp, #0x00C]
	movs r0, #0x00
	str r0, [sp, #0x010]
	movs r0, #0x18
	str r0, [sp, #0x014]
	adds r0, r4, #0x0
	movs r1, #0x14
	movs r2, #0x1E
	movs r3, #0x0A
	bl func_0800C980
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x14
	bne _0803EF7E
	movs r0, #0xB4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0803EF08 @ =0xFFFFFB80
	str r0, [r1, #0x00]
	b _0803EF7E
	.byte 0x00, 0x00
_0803EF00: .4byte 0x0813E7B4
_0803EF04: .4byte 0x0000022F
_0803EF08: .4byte 0xFFFFFB80
_0803EF0C:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r5, r4, r1
	movs r1, #0x00
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	bne _0803EF3A
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
	ldr r0, _0803EF6C @ =0x0000023B
	bl func_0811FE70
_0803EF3A:
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r1, _0803EF70 @ =0x08121400
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
	ldr r1, _0803EF74 @ =0x013F0000
	cmp r0, r1
	ble _0803EF78
	adds r0, r6, #0x0
	bl func_0801B994
	movs r0, #0x00
	b _0803EF88
	.byte 0x00, 0x00
_0803EF6C: .4byte 0x0000023B
_0803EF70: .4byte 0x08121400
_0803EF74: .4byte 0x013F0000
_0803EF78:
	adds r0, r2, #0x0
	adds r0, #0x09
	strh r0, [r5, #0x00]
_0803EF7E:
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0803EF88:
	add sp, #0x018
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
