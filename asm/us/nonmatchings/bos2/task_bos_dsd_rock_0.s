.syntax unified
	.align 2, 0
	.global task_bos_dsd_rock_0
	.thumb
	.thumb_func
	.type task_bos_dsd_rock_0, %function
task_bos_dsd_rock_0: @ 080C4420
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	str r1, [r6, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	adds r5, r6, #0x0
	adds r5, #0x20
	strb r0, [r5, #0x00]
	bl GetRandom
	ldr r4, _080C44A4 @ =0x09EF3BF8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x0E
	adds r0, #0x04
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x1C]
	ldr r0, [r6, #0x00]
	movs r1, #0xD7
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	ble _080C44F8
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080C44B4
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C44A8 @ =0x00000301
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xE0
	lsls r2, r2, #0x03
	adds r5, r0, r2
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0D
	bl __umodsi3
	adds r0, #0x3A
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080C44AC @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	ldr r2, _080C44B0 @ =0xFFFF7800
	adds r0, r0, r2
	str r0, [r6, #0x04]
	adds r1, #0xE0
	b _080C4582
_080C44A4: .4byte 0x09EF3BF8
_080C44A8: .4byte 0x00000301
_080C44AC: .4byte 0x02039B84
_080C44B0: .4byte 0xFFFF7800
_080C44B4:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C44F0 @ =0x00000201
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r5, r0, r1
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0D
	bl __umodsi3
	adds r0, #0x3A
	negs r0, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080C44F4 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	movs r2, #0x88
	lsls r2, r2, #0x08
	b _080C457C
	.byte 0x00, 0x00
_080C44F0: .4byte 0x00000201
_080C44F4: .4byte 0x02039B84
_080C44F8:
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080C4548
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C4540 @ =0x00000301
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xE0
	lsls r1, r1, #0x03
	adds r5, r0, r1
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0D
	bl __umodsi3
	adds r0, #0x3A
	negs r0, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080C4544 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	movs r2, #0x88
	lsls r2, r2, #0x08
	adds r0, r0, r2
	str r0, [r6, #0x04]
	adds r1, #0xE0
	b _080C4582
	.byte 0x00, 0x00
_080C4540: .4byte 0x00000301
_080C4544: .4byte 0x02039B84
_080C4548:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C45CC @ =0x00000201
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x03
	adds r5, r0, r1
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0D
	bl __umodsi3
	adds r0, #0x3A
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080C45D0 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	ldr r2, _080C45D4 @ =0xFFFF7800
_080C457C:
	adds r0, r0, r2
	str r0, [r6, #0x04]
	adds r1, #0xDE
_080C4582:
	movs r2, #0x00
	ldsh r0, [r1, r2]
	subs r0, #0x8C
	lsls r0, r0, #0x08
	str r0, [r6, #0x08]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x65
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	str r0, [r6, #0x0C]
	ldr r1, _080C45D8 @ =0x08121400
	lsls r0, r4, #0x01
	adds r0, r0, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	muls r0, r5
	asrs r0, r0, #0x08
	str r0, [r6, #0x10]
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	muls r0, r5
	asrs r0, r0, #0x08
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C45CC: .4byte 0x00000201
_080C45D0: .4byte 0x02039B84
_080C45D4: .4byte 0xFFFF7800
_080C45D8: .4byte 0x08121400
.syntax divided
