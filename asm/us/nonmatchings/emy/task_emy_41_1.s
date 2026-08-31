.syntax unified
	.align 2, 0
	.global task_emy_41_1
	.thumb
	.thumb_func
	.type task_emy_41_1, %function
task_emy_41_1: @ 0803D33C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x018
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r7, r6, #0x0
	adds r7, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D37C
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0803D368
	cmp r1, #0x01
	beq _0803D372
	b _0803D37C
_0803D368:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x12
	b _0803D37A
_0803D372:
	movs r4, #0xA6
	lsls r4, r4, #0x01
	adds r1, r6, r4
	movs r0, #0x13
_0803D37A:
	str r0, [r1, #0x00]
_0803D37C:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803D38E
	cmp r0, #0x13
	beq _0803D408
	b _0803D4F0
_0803D38E:
	ldr r0, _0803D3FC @ =0x0813E3DC
	adds r1, r5, #0x0
	adds r1, #0x10
	ldr r2, [r5, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r4, #0xB4
	lsls r4, r4, #0x01
	adds r0, r6, r4
	movs r3, #0x00
	str r3, [r0, #0x00]
	ldr r2, _0803D400 @ =0x08121400
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x02
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r4, #0x00
	ldsh r0, [r0, r4]
	lsls r0, r0, #0x04
	ldr r1, [r7, #0x0C]
	movs r4, #0x80
	lsls r4, r4, #0x05
	adds r2, r1, r4
	subs r0, r0, r2
	asrs r0, r0, #0x02
	adds r1, r1, r0
	str r1, [r7, #0x0C]
	movs r0, #0xD8
	str r0, [sp, #0x000]
	movs r0, #0x40
	str r0, [sp, #0x004]
	ldr r0, _0803D404 @ =0x00000221
	str r0, [sp, #0x008]
	str r3, [sp, #0x00C]
	movs r0, #0x10
	negs r0, r0
	str r0, [sp, #0x010]
	movs r0, #0x2C
	str r0, [sp, #0x014]
	adds r0, r6, #0x0
	movs r1, #0x14
	movs r2, #0x63
	movs r3, #0x1E
	bl func_0800C980
	b _0803D4F0
	.byte 0x00, 0x00
_0803D3FC: .4byte 0x0813E3DC
_0803D400: .4byte 0x08121400
_0803D404: .4byte 0x00000221
_0803D408:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r1, #0x00
	ldsh r4, [r0, r1]
	cmp r4, #0x00
	bne _0803D442
	ldr r0, _0803D498 @ =0x0813E3DC
	adds r1, r5, #0x0
	adds r1, #0x10
	ldr r2, [r5, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r5, r0
	adds r0, #0x04
	adds r2, r5, r0
	adds r0, r7, #0x0
	movs r3, #0x00
	bl func_0801C700
	movs r1, #0xC6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r4, [r0, #0x00]
_0803D442:
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x04
	bne _0803D4D0
	ldrh r0, [r6, #0x1A]
	cmp r0, #0x00
	bne _0803D4D0
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803D4A0
	ldr r1, [r7, #0x04]
	ldr r0, _0803D49C @ =0xFFFFD400
	adds r1, r1, r0
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	movs r7, #0xC2
	lsls r7, r7, #0x01
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r7, #0x04
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r7, #0x04
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	movs r0, #0xD9
	str r0, [sp, #0x00C]
	movs r0, #0x01
	bl func_08015834
	b _0803D4D0
_0803D498: .4byte 0x0813E3DC
_0803D49C: .4byte 0xFFFFD400
_0803D4A0:
	ldr r1, [r7, #0x04]
	movs r0, #0xB0
	lsls r0, r0, #0x06
	adds r1, r1, r0
	ldr r2, [r7, #0x08]
	ldr r3, [r7, #0x0C]
	movs r7, #0xC2
	lsls r7, r7, #0x01
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r7, #0x04
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x004]
	adds r7, #0x04
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x008]
	movs r0, #0xD9
	str r0, [sp, #0x00C]
	movs r0, #0x01
	bl func_08015834
_0803D4D0:
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803D4E4
	adds r0, r6, #0x0
	bl func_0800CB4C
	b _0803D4F0
_0803D4E4:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0803D4F0:
	adds r0, r6, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x018
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
