.syntax unified
	.align 2, 0
	.global task_bos_ursula_mapanime_1
	.thumb
	.thumb_func
	.type task_bos_ursula_mapanime_1, %function
task_bos_ursula_mapanime_1: @ 080DD4F0
	push {r4, r5, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	ldr r1, [r5, #0x08]
	movs r2, #0x00
	bl func_080DDDEC
	adds r0, r5, #0x0
	bl func_080DDE74
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD576
	ldr r1, [r5, #0x08]
	ldr r0, _080DD524 @ =0x096FE278
	cmp r1, r0
	bne _080DD540
	ldr r0, [r5, #0x0C]
	cmp r0, #0x01
	bne _080DD52C
	ldr r1, _080DD528 @ =0x096FE290
	adds r0, r5, #0x0
	bl func_080DDDDC
	movs r0, #0x04
	b _080DD574
_080DD524: .4byte 0x096FE278
_080DD528: .4byte 0x096FE290
_080DD52C:
	cmp r0, #0x02
	bne _080DD576
	ldr r1, _080DD53C @ =0x096FE2A8
	adds r0, r5, #0x0
	bl func_080DDDDC
	movs r0, #0x04
	b _080DD574
_080DD53C: .4byte 0x096FE2A8
_080DD540:
	ldr r0, _080DD558 @ =0x096FE290
	cmp r1, r0
	beq _080DD54C
	ldr r0, _080DD55C @ =0x096FE2A8
	cmp r1, r0
	bne _080DD564
_080DD54C:
	ldr r1, _080DD560 @ =0x096FE2C0
	adds r0, r5, #0x0
	bl func_080DDDDC
	movs r0, #0x04
	b _080DD574
_080DD558: .4byte 0x096FE290
_080DD55C: .4byte 0x096FE2A8
_080DD560: .4byte 0x096FE2C0
_080DD564:
	ldr r0, _080DD5CC @ =0x096FE2C0
	cmp r1, r0
	bne _080DD576
	ldr r1, _080DD5D0 @ =0x096FE260
	adds r0, r5, #0x0
	bl func_080DDDDC
	movs r0, #0x00
_080DD574:
	str r0, [r5, #0x0C]
_080DD576:
	ldr r1, [r5, #0x08]
	ldr r0, _080DD5D4 @ =0x096FE2A8
	cmp r1, r0
	bne _080DD630
	adds r0, r5, #0x0
	bl func_080DDEA0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bne _080DD630
	adds r1, r5, #0x0
	adds r1, #0x28
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080DD5E0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	bl func_080DC510
	adds r3, r0, #0x0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, _080DD5D8 @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xCC
	ldr r0, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xD0
	ldr r1, [r1, #0x00]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	adds r1, r1, r4
	adds r2, #0xD4
	ldr r2, [r2, #0x00]
	ldr r4, _080DD5DC @ =0x00000266
	str r4, [sp, #0x000]
	movs r4, #0x78
	str r4, [sp, #0x004]
	bl func_080168B8
	b _080DD5FE
_080DD5CC: .4byte 0x096FE2C0
_080DD5D0: .4byte 0x096FE260
_080DD5D4: .4byte 0x096FE2A8
_080DD5D8: .4byte 0x02039B84
_080DD5DC: .4byte 0x00000266
_080DD5E0:
	ldr r0, _080DD674 @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xCC
	ldr r0, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xD0
	ldr r1, [r1, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x04
	adds r1, r1, r3
	adds r2, #0xD4
	ldr r2, [r2, #0x00]
	bl func_08014780
_080DD5FE:
	bl func_080DC510
	lsls r0, r0, #0x18
	movs r2, #0xA0
	lsls r2, r2, #0x07
	cmp r0, #0x00
	beq _080DD60E
	ldr r2, _080DD678 @ =0xFFFFB000
_080DD60E:
	ldr r0, _080DD674 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xCC
	ldr r1, [r0, #0x00]
	adds r1, r1, r2
	movs r2, #0xE2
	lsls r2, r2, #0x09
	movs r0, #0x18
	str r0, [sp, #0x000]
	movs r0, #0x38
	str r0, [sp, #0x004]
	movs r0, #0x50
	str r0, [sp, #0x008]
	movs r0, #0xF3
	movs r3, #0x00
	bl func_08011F78
_080DD630:
	ldr r1, [r5, #0x08]
	ldr r0, _080DD67C @ =0x096FE290
	adds r4, r5, #0x0
	adds r4, #0x10
	cmp r1, r0
	bne _080DD664
	adds r0, r5, #0x0
	bl func_080DDEA0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x02
	bne _080DD664
	adds r1, r5, #0x0
	adds r1, #0x28
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _080DD664
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r1, _080DD680 @ =0x09EF5250
	adds r0, r4, #0x0
	movs r2, #0x00
	bl TaskCreate
	str r0, [r5, #0x24]
_080DD664:
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	movs r0, #0x01
	add sp, #0x00C
	pop {r4, r5}
	pop {r1}
	bx r1
_080DD674: .4byte 0x02039B84
_080DD678: .4byte 0xFFFFB000
_080DD67C: .4byte 0x096FE290
_080DD680: .4byte 0x09EF5250
.syntax divided
