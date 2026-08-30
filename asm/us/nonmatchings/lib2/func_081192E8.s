.syntax unified
	.align 2, 0
	.global func_081192E8
	.thumb
	.thumb_func
	.type func_081192E8, %function
func_081192E8: @ 081192E8
	push {r4, r7, lr}
	add sp, #-0x01C
	mov r7, sp
	str r0, [r7, #0x00]
	str r1, [r7, #0x04]
	str r2, [r7, #0x08]
	str r3, [r7, #0x0C]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x18]
	ldr r1, [r7, #0x18]
	adds r0, r1, #0x0
	adds r1, #0x8D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08119308
	b _08119476
_08119308:
	ldr r1, [r7, #0x18]
	ldr r0, [r1, #0x1C]
	ldr r2, [r7, #0x18]
	ldr r1, [r2, #0x5C]
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x18]
	ldr r4, [r3, #0x64]
	adds r3, r4, #0x0
	lsls r4, r3, #0x01
	ldr r3, [r2, #0x58]
	adds r2, r4, r3
	ldrh r3, [r2, #0x00]
	lsrs r2, r3, #0x02
	adds r4, r2, #0x0
	lsls r3, r4, #0x10
	lsrs r2, r3, #0x10
	bl func_08117FE4
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x5C]
	ldr r0, [r1, #0x00]
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x40]
	cmp r1, #0x01
	bne _0811939E
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x5C]
	adds r0, r1, #0x4
	str r0, [r7, #0x14]
	ldr r0, [r7, #0x18]
	adds r1, r0, #0x0
	adds r0, #0x88
	ldr r1, [r7, #0x14]
	ldr r3, [r7, #0x18]
	ldr r2, [r3, #0x28]
	ldr r3, [r7, #0x10]
	ldr r4, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	bl _0811D5C0
	ldr r1, [r7, #0x18]
	ldr r0, [r1, #0x28]
	ldr r1, [r7, #0x04]
	ldr r3, [r7, #0x08]
	adds r2, r3, #0x0
	cmp r2, #0x00
	bge _0811936E
	adds r2, #0x03
_0811936E:
	asrs r2, r2, #0x02
	lsls r3, r2, #0x0B
	lsrs r2, r3, #0x0B
	bl func_08117FE4
	ldr r0, [r7, #0x28]
	cmp r0, #0x00
	beq _0811939C
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x28]
	ldr r2, [r7, #0x08]
	adds r0, r1, r2
	ldr r1, [r7, #0x0C]
	ldr r3, [r7, #0x28]
	adds r2, r3, #0x0
	cmp r2, #0x00
	bge _08119392
	adds r2, #0x03
_08119392:
	asrs r2, r2, #0x02
	lsls r3, r2, #0x0B
	lsrs r2, r3, #0x0B
	bl func_08117FE4
_0811939C:
	b _08119476
_0811939E:
	ldr r0, [r7, #0x10]
	asrs r1, r0, #0x01
	str r1, [r7, #0x10]
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x5C]
	adds r0, r1, #0x4
	str r0, [r7, #0x14]
	ldr r0, [r7, #0x18]
	adds r1, r0, #0x0
	adds r0, #0x88
	ldr r1, [r7, #0x14]
	ldr r3, [r7, #0x18]
	ldr r2, [r3, #0x28]
	ldr r3, [r7, #0x10]
	ldr r4, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	bl _0811D5C0
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x18]
	ldr r2, [r1, #0x64]
	adds r1, r2, #0x0
	lsls r2, r1, #0x01
	ldr r1, [r0, #0x58]
	adds r0, r2, r1
	ldrh r1, [r0, #0x00]
	subs r0, r1, #0x4
	asrs r1, r0, #0x01
	ldr r0, [r7, #0x14]
	adds r1, r0, r1
	str r1, [r7, #0x14]
	ldr r1, [r7, #0x18]
	ldr r0, [r1, #0x28]
	ldr r1, [r7, #0x04]
	ldr r3, [r7, #0x08]
	adds r2, r3, #0x0
	cmp r2, #0x00
	bge _081193F0
	adds r2, #0x03
_081193F0:
	asrs r2, r2, #0x02
	lsls r3, r2, #0x0B
	lsrs r2, r3, #0x0B
	bl func_08117FE4
	ldr r0, [r7, #0x28]
	cmp r0, #0x00
	beq _0811941E
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x28]
	ldr r2, [r7, #0x08]
	adds r0, r1, r2
	ldr r1, [r7, #0x0C]
	ldr r3, [r7, #0x28]
	adds r2, r3, #0x0
	cmp r2, #0x00
	bge _08119414
	adds r2, #0x03
_08119414:
	asrs r2, r2, #0x02
	lsls r3, r2, #0x0B
	lsrs r2, r3, #0x0B
	bl func_08117FE4
_0811941E:
	ldr r0, [r7, #0x18]
	adds r1, r0, #0x0
	adds r0, #0x88
	ldr r1, [r7, #0x14]
	ldr r3, [r7, #0x18]
	ldr r2, [r3, #0x28]
	ldr r3, [r7, #0x10]
	ldr r4, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	bl _0811D5C0
	ldr r1, [r7, #0x18]
	ldr r0, [r1, #0x28]
	ldr r1, [r7, #0x2C]
	ldr r3, [r7, #0x30]
	adds r2, r3, #0x0
	cmp r2, #0x00
	bge _08119448
	adds r2, #0x03
_08119448:
	asrs r2, r2, #0x02
	lsls r3, r2, #0x0B
	lsrs r2, r3, #0x0B
	bl func_08117FE4
	ldr r0, [r7, #0x38]
	cmp r0, #0x00
	beq _08119476
	ldr r0, [r7, #0x18]
	ldr r1, [r0, #0x28]
	ldr r2, [r7, #0x30]
	adds r0, r1, r2
	ldr r1, [r7, #0x34]
	ldr r3, [r7, #0x38]
	adds r2, r3, #0x0
	cmp r2, #0x00
	bge _0811946C
	adds r2, #0x03
_0811946C:
	asrs r2, r2, #0x02
	lsls r3, r2, #0x0B
	lsrs r2, r3, #0x0B
	bl func_08117FE4
_08119476:
	add sp, #0x01C
	pop {r4, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
