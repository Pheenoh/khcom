.syntax unified
	.align 2, 0
	.global mode_eventselect_1
	.thumb
	.thumb_func
	.type mode_eventselect_1, %function
mode_eventselect_1: @ 0807511C
	push {r4, r5, lr}
	bl GetKeysRepeat
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08075140
	ldr r1, _08075138 @ =0x02034A96
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0807513C
	subs r0, #0x01
	b _0807513E
	.byte 0x00, 0x00
_08075138: .4byte 0x02034A96
_0807513C:
	movs r0, #0x01
_0807513E:
	strb r0, [r1, #0x00]
_08075140:
	bl GetKeysRepeat
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08075160
	ldr r1, _08075158 @ =0x02034A96
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0807515C
	adds r0, #0x01
	b _0807515E
_08075158: .4byte 0x02034A96
_0807515C:
	movs r0, #0x00
_0807515E:
	strb r0, [r1, #0x00]
_08075160:
	ldr r0, _08075170 @ =0x02034A96
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08075174
	cmp r0, #0x01
	beq _080751A4
	b _080751CA
	.byte 0x00, 0x00
_08075170: .4byte 0x02034A96
_08075174:
	ldr r3, _0807519C @ =0x09033ED8
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	ldr r4, _080751A0 @ =0x09033EDC
	movs r0, #0x00
	movs r1, #0x0A
	movs r2, #0x02
	adds r3, r4, #0x0
	bl func_0805FCB0
	movs r0, #0x00
	movs r1, #0x14
	movs r2, #0x02
	adds r3, r4, #0x0
	bl func_0805FCB0
	b _080751CA
_0807519C: .4byte 0x09033ED8
_080751A0: .4byte 0x09033EDC
_080751A4:
	ldr r4, _08075264 @ =0x09033EDC
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x02
	adds r3, r4, #0x0
	bl func_0805FCB0
	ldr r3, _08075268 @ =0x09033ED8
	movs r0, #0x00
	movs r1, #0x0A
	movs r2, #0x02
	bl func_0805FCB0
	movs r0, #0x00
	movs r1, #0x14
	movs r2, #0x02
	adds r3, r4, #0x0
	bl func_0805FCB0
_080751CA:
	bl GetKeysRepeat
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080751DE
	ldr r1, _0807526C @ =0x02034A94
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080751DE:
	bl GetKeysRepeat
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080751F2
	ldr r1, _0807526C @ =0x02034A94
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080751F2:
	ldr r5, _08075270 @ =0x02034A96
	ldrb r0, [r5, #0x00]
	bl func_08075064
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r0, #0x01
	ldr r4, _0807526C @ =0x02034A94
	movs r2, #0x00
	ldsh r1, [r4, r2]
	cmp r0, r1
	bge _0807520E
	movs r0, #0x00
	strh r0, [r4, #0x00]
_0807520E:
	movs r3, #0x00
	ldsh r0, [r4, r3]
	cmp r0, #0x00
	bge _08075220
	ldrb r0, [r5, #0x00]
	bl func_08075064
	subs r0, #0x01
	strh r0, [r4, #0x00]
_08075220:
	ldr r3, _08075274 @ =0x09033EE0
	movs r0, #0x0A
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	ldr r3, _08075278 @ =0x09033EF8
	movs r0, #0x0A
	movs r1, #0x0A
	movs r2, #0x02
	bl func_0805FCB0
	ldr r3, _0807527C @ =0x09033F10
	movs r0, #0x14
	movs r1, #0x28
	movs r2, #0x02
	bl func_0805FCB0
	ldrh r3, [r4, #0x00]
	adds r3, #0x01
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0x64
	movs r1, #0x28
	movs r2, #0x02
	bl func_0805FC04
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _08075280
	cmp r0, #0x01
	beq _080752AC
	b _080752CC
	.byte 0x00, 0x00
_08075264: .4byte 0x09033EDC
_08075268: .4byte 0x09033ED8
_0807526C: .4byte 0x02034A94
_08075270: .4byte 0x02034A96
_08075274: .4byte 0x09033EE0
_08075278: .4byte 0x09033EF8
_0807527C: .4byte 0x09033F10
_08075280:
	ldr r2, _080752A4 @ =0x09EE42C8
	ldr r1, _080752A8 @ =0x09033D50
	movs r3, #0x00
	ldsh r0, [r4, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r3, [r0, #0x00]
	movs r0, #0x14
	movs r1, #0x50
	movs r2, #0x02
	bl func_0805FCB0
	b _080752CC
	.byte 0x00, 0x00
_080752A4: .4byte 0x09EE42C8
_080752A8: .4byte 0x09033D50
_080752AC:
	ldr r2, _080752E8 @ =0x09EE42C8
	ldr r1, _080752EC @ =0x09033E76
	movs r3, #0x00
	ldsh r0, [r4, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r3, [r0, #0x00]
	movs r0, #0x14
	movs r1, #0x50
	movs r2, #0x02
	bl func_0805FCB0
_080752CC:
	bl GetKeysPressed
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08075322
	ldr r0, _080752F0 @ =0x02034A96
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080752F4
	cmp r0, #0x01
	beq _08075310
	b _08075322
	.byte 0x00, 0x00
_080752E8: .4byte 0x09EE42C8
_080752EC: .4byte 0x09033E76
_080752F0: .4byte 0x02034A96
_080752F4:
	ldr r1, _08075308 @ =0x09033D50
	ldr r0, _0807530C @ =0x02034A94
	movs r2, #0x00
	ldsh r0, [r0, r2]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	bl func_0806180C
	b _08075322
_08075308: .4byte 0x09033D50
_0807530C: .4byte 0x02034A94
_08075310:
	ldr r1, _08075348 @ =0x09033E76
	ldr r0, _0807534C @ =0x02034A94
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	bl func_0806180C
_08075322:
	bl GetKeysPressed
	movs r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _08075336
	ldr r0, _08075350 @ =0x09ECEB64
	movs r1, #0x00
	bl func_080010CC
_08075336:
	movs r0, #0x00
	bl func_080605A4
	bl func_08060598
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08075348: .4byte 0x09033E76
_0807534C: .4byte 0x02034A94
_08075350: .4byte 0x09ECEB64
.syntax divided
