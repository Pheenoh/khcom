.syntax unified
	.align 2, 0
	.global task_emy_02_1
	.thumb
	.thumb_func
	.type task_emy_02_1, %function
task_emy_02_1: @ 08037538
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r4, r0, #0x0
	adds r6, r4, #0x0
	adds r5, r4, #0x0
	adds r5, #0x3C
	bl _0800CBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08037578
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08037564
	cmp r1, #0x01
	beq _0803756E
	b _08037578
_08037564:
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x12
	b _08037576
_0803756E:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r0, #0x13
_08037576:
	str r0, [r1, #0x00]
_08037578:
	movs r3, #0xA6
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldr r0, [r0, #0x00]
	cmp r0, #0x12
	beq _0803758A
	cmp r0, #0x13
	beq _0803764C
	b _08037720
_0803758A:
	ldr r0, _080375F4 @ =0x0813D4BC
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r7, #0x00
	str r7, [r0, #0x00]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r4, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	beq _0803762C
	cmp r0, #0x16
	bne _0803762C
	ldr r6, [r5, #0x08]
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _08037604
	ldr r1, [r5, #0x04]
	ldr r2, _080375F8 @ =0xFFFFC400
	adds r0, r1, r2
	ldr r3, _080375FC @ =0xFFFFD800
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _08037600 @ =0xFFFFF800
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xA9
	str r0, [sp, #0x010]
	movs r0, #0x00
	adds r2, r6, #0x0
	bl func_08013308
	b _0803762C
_080375F4: .4byte 0x0813D4BC
_080375F8: .4byte 0xFFFFC400
_080375FC: .4byte 0xFFFFD800
_08037600: .4byte 0xFFFFF800
_08037604:
	ldr r1, [r5, #0x04]
	movs r3, #0xF0
	lsls r3, r3, #0x06
	adds r0, r1, r3
	movs r3, #0xA0
	lsls r3, r3, #0x06
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _08037648 @ =0xFFFFF800
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xA9
	str r0, [sp, #0x010]
	movs r0, #0x00
	adds r2, r6, #0x0
	bl func_08013308
_0803762C:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x15
	ble _08037714
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08037708
	b _08037714
	.byte 0x00, 0x00
_08037648: .4byte 0xFFFFF800
_0803764C:
	ldr r0, _080376B8 @ =0x0813D4BC
	adds r1, r6, #0x0
	adds r1, #0x10
	ldr r2, [r6, #0x00]
	str r2, [sp, #0x000]
	movs r2, #0x01
	movs r3, #0x00
	bl func_08019068
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r7, #0x00
	str r7, [r0, #0x00]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r4, r2
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r0, #0x00
	beq _080376F0
	cmp r0, #0x03
	bne _080376F0
	ldr r6, [r5, #0x08]
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	adds r2, r1, #0x0
	orrs r2, r0
	cmp r2, #0x00
	beq _080376C8
	ldr r1, [r5, #0x04]
	ldr r2, _080376BC @ =0xFFFFC400
	adds r0, r1, r2
	ldr r3, _080376C0 @ =0xFFFFD800
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _080376C4 @ =0xFFFFF800
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r0, #0x01
	str r0, [sp, #0x00C]
	movs r0, #0xAA
	str r0, [sp, #0x010]
	movs r0, #0x01
	adds r2, r6, #0x0
	bl func_08013308
	b _080376F0
	.byte 0x00, 0x00
_080376B8: .4byte 0x0813D4BC
_080376BC: .4byte 0xFFFFC400
_080376C0: .4byte 0xFFFFD800
_080376C4: .4byte 0xFFFFF800
_080376C8:
	ldr r1, [r5, #0x04]
	movs r3, #0xF0
	lsls r3, r3, #0x06
	adds r0, r1, r3
	movs r3, #0xA0
	lsls r3, r3, #0x06
	adds r1, r1, r3
	ldr r3, [r5, #0x0C]
	ldr r5, _08037710 @ =0xFFFFF800
	adds r3, r3, r5
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r2, [sp, #0x008]
	str r2, [sp, #0x00C]
	movs r0, #0xAA
	str r0, [sp, #0x010]
	movs r0, #0x01
	adds r2, r6, #0x0
	bl func_08013308
_080376F0:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x02
	ble _08037714
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08037714
_08037708:
	adds r0, r4, #0x0
	bl func_0800CB4C
	b _08037720
_08037710: .4byte 0xFFFFF800
_08037714:
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r1, r4, r3
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08037720:
	adds r0, r4, #0x0
	bl _0800CDF0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
