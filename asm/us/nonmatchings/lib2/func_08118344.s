.syntax unified
	.align 2, 0
	.global func_08118344
	.thumb
	.thumb_func
	.type func_08118344, %function
func_08118344: @ 08118344
	push {r4, r7, lr}
	add sp, #-0x054
	add r7, sp, #0x014
	str r0, [r7, #0x00]
	str r1, [r7, #0x04]
	ldr r1, _081183BC @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x30
	adds r2, r7, #0x0
	adds r2, #0x34
	bl func_0811968C
	movs r0, #0xF0
	ldr r1, [r7, #0x30]
	subs r0, r0, r1
	asrs r1, r0, #0x01
	str r1, [r7, #0x38]
	movs r0, #0xA0
	ldr r1, [r7, #0x34]
	subs r0, r0, r1
	asrs r1, r0, #0x01
	str r1, [r7, #0x3C]
	ldr r1, _081183BC @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	ldr r1, [r7, #0x3C]
	adds r3, r1, #0x0
	lsls r2, r3, #0x04
	subs r2, r2, r1
	lsls r1, r2, #0x04
	ldr r2, [r7, #0x38]
	adds r1, r1, r2
	adds r2, r1, #0x0
	lsls r1, r2, #0x01
	movs r3, #0xC0
	lsls r3, r3, #0x13
	adds r2, r1, r3
	adds r1, r2, #0x0
	bl func_0811904C
	ldr r0, _081183BC @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119224
	bl func_0811D4FC
	ldr r0, _081183BC @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119654
	str r0, [r7, #0x28]
	ldr r0, [r7, #0x28]
	cmp r0, #0x00
	beq _081183C0
	movs r0, #0x01
	str r0, [r7, #0x2C]
	b _081183C4
	.byte 0x00, 0x00
_081183BC: .4byte 0x0203C7C4
_081183C0:
	movs r0, #0x00
	str r0, [r7, #0x2C]
_081183C4:
	b _081183C8
	.byte 0xB2, 0xE0
_081183C8:
	ldr r0, _081183D8 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_0811950C
	cmp r0, #0x00
	beq _081183DC
	b _081183DE
_081183D8: .4byte 0x0203C7C4
_081183DC:
	b _081183C8
_081183DE:
	ldr r1, _08118410 @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	ldr r1, [r7, #0x3C]
	adds r3, r1, #0x0
	lsls r2, r3, #0x04
	subs r2, r2, r1
	lsls r1, r2, #0x04
	ldr r2, [r7, #0x38]
	adds r1, r1, r2
	adds r2, r1, #0x0
	lsls r1, r2, #0x01
	movs r3, #0xC0
	lsls r3, r3, #0x13
	adds r2, r1, r3
	adds r1, r2, #0x0
	bl func_0811904C
	ldr r0, _08118410 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119224
	cmp r0, #0x00
	bne _08118414
	b _0811852E
_08118410: .4byte 0x0203C7C4
_08118414:
	ldr r0, [r7, #0x2C]
	cmp r0, #0x00
	bne _0811841C
	b _08118514
_0811841C:
	ldr r0, [r7, #0x28]
	cmp r0, #0x01
	bne _08118488
	ldr r0, _08118484 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_081192B0
	adds r1, r0, #0x0
	adds r2, r7, #0x0
	adds r2, #0x08
	adds r3, r7, #0x0
	adds r3, #0x18
	adds r0, r7, #0x0
	adds r0, #0x0C
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0x1C
	str r0, [sp, #0x004]
	movs r0, #0x00
	bl func_0811D408
	ldr r1, _08118484 @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	ldr r1, [r7, #0x08]
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x0C]
	ldr r4, [r7, #0x1C]
	str r4, [sp, #0x000]
	ldr r4, [r7, #0x10]
	str r4, [sp, #0x004]
	ldr r4, [r7, #0x20]
	str r4, [sp, #0x008]
	ldr r4, [r7, #0x14]
	str r4, [sp, #0x00C]
	ldr r4, [r7, #0x24]
	str r4, [sp, #0x010]
	bl func_081192E8
	movs r0, #0x00
	bl func_0811D550
	ldr r0, _08118484 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119480
	cmp r0, #0x00
	bne _08118482
	movs r0, #0x00
	str r0, [r7, #0x2C]
_08118482:
	b _08118514
_08118484: .4byte 0x0203C7C4
_08118488:
	ldr r0, _08118528 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_081192B0
	adds r1, r0, #0x0
	adds r2, r7, #0x0
	adds r2, #0x08
	adds r3, r7, #0x0
	adds r3, #0x18
	adds r0, r7, #0x0
	adds r0, #0x0C
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0x1C
	str r0, [sp, #0x004]
	movs r0, #0x00
	bl func_0811D408
	ldr r0, _08118528 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_081192B0
	adds r1, r0, #0x0
	adds r2, r7, #0x0
	adds r2, #0x10
	adds r3, r7, #0x0
	adds r3, #0x20
	adds r0, r7, #0x0
	adds r0, #0x14
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0x24
	str r0, [sp, #0x004]
	movs r0, #0x01
	bl func_0811D408
	ldr r1, _08118528 @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	ldr r1, [r7, #0x08]
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x0C]
	ldr r4, [r7, #0x1C]
	str r4, [sp, #0x000]
	ldr r4, [r7, #0x10]
	str r4, [sp, #0x004]
	ldr r4, [r7, #0x20]
	str r4, [sp, #0x008]
	ldr r4, [r7, #0x14]
	str r4, [sp, #0x00C]
	ldr r4, [r7, #0x24]
	str r4, [sp, #0x010]
	bl func_081192E8
	movs r0, #0x00
	bl func_0811D550
	movs r0, #0x01
	bl func_0811D550
	ldr r0, _08118528 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119480
	cmp r0, #0x00
	bne _08118514
	movs r0, #0x00
	str r0, [r7, #0x2C]
_08118514:
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	beq _0811852C
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x00]
	bl _0811D5B4
	cmp r0, #0x00
	beq _0811852C
	b _0811852E
_08118528: .4byte 0x0203C7C4
_0811852C:
	b _081183C4
_0811852E:
	add sp, #0x054
	pop {r4, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
