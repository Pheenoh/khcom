.syntax unified
	.align 2, 0
	.global func_08118C34
	.thumb
	.thumb_func
	.type func_08118C34, %function
func_08118C34: @ 08118C34
	push {r4, r5, r7, lr}
	add sp, #-0x020
	add r7, sp, #0x008
	str r0, [r7, #0x00]
	ldr r0, _08118D84 @ =0x0203C7D0
	ldr r1, [r0, #0x00]
	movs r0, #0x90
	bl _0811D5B4
	str r0, [r7, #0x14]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x00]
	str r1, [r0, #0x0C]
	ldr r0, [r7, #0x14]
	adds r1, r0, #0x0
	adds r0, #0x8C
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
	ldr r0, [r7, #0x14]
	adds r1, r0, #0x0
	adds r0, #0x8D
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	movs r3, #0x02
	adds r1, r2, #0x0
	orrs r1, r3
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x2C]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x30]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x34]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x38]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x3C]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x40]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x44]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x00]
	str r2, [r0, #0x48]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r4, [r7, #0x14]
	ldr r1, [r7, #0x14]
	ldr r0, _08118D88 @ =0x3F800000
	ldr r1, [r1, #0x34]
	bl _0811DD00
	str r0, [r4, #0x70]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x00]
	str r1, [r7, #0x08]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x4C]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x08]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x00]
	str r1, [r7, #0x08]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x00]
	str r1, [r7, #0x0C]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	adds r0, r7, #0x0
	adds r0, #0x10
	ldr r1, [r7, #0x04]
	ldrh r2, [r1, #0x00]
	strh r2, [r0, #0x00]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	adds r2, r1, #0x2
	str r2, [r0, #0x50]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x08]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x10]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x14]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x0C]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r0, #0x2C]
	movs r2, #0x07
	adds r0, r1, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _08118D8C
	ldr r0, [r7, #0x14]
	ldr r1, [r0, #0x2C]
	movs r0, #0x90
	lsls r0, r0, #0x01
	cmp r1, r0
	bhi _08118D8C
	ldr r0, [r7, #0x14]
	ldr r1, [r0, #0x30]
	movs r2, #0x07
	adds r0, r1, #0x0
	ands r0, r2
	cmp r0, #0x00
	bne _08118D8C
	b _08118DA0
	.byte 0x00, 0x00
_08118D84: .4byte 0x0203C7D0
_08118D88: .4byte 0x3F800000
_08118D8C:
	ldr r0, _08118D9C @ =0x0203C7D0
	ldr r1, [r7, #0x14]
	ldr r2, [r0, #0x08]
	adds r0, r1, #0x0
	bl _0811D5B8
	movs r0, #0x00
	b _08118EE4
_08118D9C: .4byte 0x0203C7D0
_08118DA0:
	ldr r0, [r7, #0x14]
	ldr r2, [r7, #0x14]
	adds r1, r2, #0x0
	adds r1, #0x7C
	ldr r3, [r7, #0x14]
	adds r2, r3, #0x0
	adds r2, #0x80
	ldr r4, [r7, #0x14]
	adds r3, r4, #0x0
	adds r3, #0x84
	ldr r4, [r7, #0x14]
	ldr r5, [r4, #0x2C]
	str r5, [sp, #0x000]
	ldr r4, [r7, #0x14]
	ldr r5, [r4, #0x30]
	str r5, [sp, #0x004]
	bl _0811865C
	ldr r0, _08118EB0 @ =0x0203C7D0
	ldr r1, [r7, #0x14]
	ldr r2, [r7, #0x14]
	ldr r1, [r1, #0x2C]
	ldr r2, [r2, #0x30]
	muls r1, r2
	adds r2, r1, #0x0
	lsls r1, r2, #0x01
	ldr r2, [r0, #0x04]
	adds r0, r1, #0x0
	bl _0811D5B8
	ldr r1, [r7, #0x14]
	str r0, [r1, #0x20]
	ldr r0, _08118EB0 @ =0x0203C7D0
	ldr r1, [r7, #0x14]
	ldr r2, [r7, #0x14]
	ldr r1, [r1, #0x2C]
	ldr r2, [r2, #0x30]
	muls r1, r2
	adds r2, r1, #0x0
	lsls r1, r2, #0x01
	ldr r2, [r0, #0x04]
	adds r0, r1, #0x0
	bl _0811D5B8
	ldr r1, [r7, #0x14]
	str r0, [r1, #0x24]
	ldr r0, [r7, #0x14]
	ldr r1, [r0, #0x40]
	cmp r1, #0x00
	beq _08118E96
	ldr r0, [r7, #0x14]
	adds r1, r0, #0x0
	adds r0, #0x8D
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x00]
	str r1, [r7, #0x08]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x54]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x08]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x00]
	str r1, [r7, #0x08]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x00]
	str r1, [r7, #0x0C]
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x4
	str r1, [r7, #0x04]
	adds r0, r7, #0x0
	adds r0, #0x12
	ldr r1, [r7, #0x04]
	ldrh r2, [r1, #0x00]
	strh r2, [r0, #0x00]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	adds r2, r1, #0x2
	str r2, [r0, #0x58]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x08]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x18]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x1C]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x0C]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, _08118EB0 @ =0x0203C7D0
	movs r1, #0x80
	lsls r1, r1, #0x06
	ldr r2, [r0, #0x04]
	adds r0, r1, #0x0
	bl _0811D5B8
	ldr r1, [r7, #0x14]
	str r0, [r1, #0x28]
	ldr r0, [r7, #0x14]
	ldr r2, [r7, #0x14]
	adds r1, r2, #0x0
	adds r1, #0x88
	ldr r3, [r7, #0x14]
	ldr r2, [r3, #0x48]
	bl func_08118ADC
_08118E96:
	ldr r0, _08118EB0 @ =0x0203C7D0
	adds r1, r7, #0x0
	adds r1, #0x10
	adds r2, r7, #0x0
	adds r2, #0x12
	ldrh r1, [r1, #0x00]
	ldrh r2, [r2, #0x00]
	cmp r1, r2
	bls _08118EB4
	adds r2, r7, #0x0
	adds r2, #0x10
	ldrh r1, [r2, #0x00]
	b _08118EBA
_08118EB0: .4byte 0x0203C7D0
_08118EB4:
	adds r2, r7, #0x0
	adds r2, #0x12
	ldrh r1, [r2, #0x00]
_08118EBA:
	ldr r2, [r0, #0x00]
	adds r0, r1, #0x0
	bl _0811D5B8
	ldr r1, [r7, #0x14]
	str r0, [r1, #0x5C]
	ldr r0, [r7, #0x14]
	movs r1, #0x00
	str r1, [r0, #0x60]
	ldr r0, [r7, #0x14]
	movs r1, #0x00
	str r1, [r0, #0x64]
	ldr r0, [r7, #0x14]
	movs r1, #0x00
	str r1, [r0, #0x6C]
	ldr r0, [r7, #0x14]
	movs r1, #0x01
	str r1, [r0, #0x78]
	ldr r1, [r7, #0x14]
	adds r0, r1, #0x0
	b _08118EE4
_08118EE4:
	add sp, #0x020
	pop {r4, r5, r7}
	pop {r1}
	bx r1
.syntax divided
