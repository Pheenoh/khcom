.syntax unified
	.align 2, 0
	.global task_btl_pause_1
	.thumb
	.thumb_func
	.type task_btl_pause_1, %function
task_btl_pause_1: @ 08030254
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	bl GetKeysPressed
	movs r1, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _0803028A
	ldr r0, _080303A8 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0803028A
	movs r2, #0x00
	adds r1, r3, #0x0
	adds r1, #0x70
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08030288
	movs r2, #0x01
_08030288:
	strb r2, [r1, #0x00]
_0803028A:
	ldr r0, _080303A8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r6, [r0, #0x00]
	cmp r6, #0x00
	bne _08030298
	b _08030438
_08030298:
	ldrb r0, [r5, #0x10]
	cmp r0, #0x00
	beq _080302A0
	b _0803040C
_080302A0:
	movs r0, #0x01
	bl func_080063C4
	movs r0, #0x01
	strb r0, [r5, #0x10]
	ldr r0, _080303AC @ =0xFFFFC000
	str r0, [r5, #0x14]
	movs r1, #0xA0
	lsls r1, r1, #0x07
	str r1, [r5, #0x18]
	movs r0, #0x98
	lsls r0, r0, #0x09
	str r0, [r5, #0x1C]
	str r1, [r5, #0x20]
	movs r0, #0x0E
	strh r0, [r5, #0x24]
	ldr r0, _080303B0 @ =0x0203DB10
	movs r1, #0xFF
	movs r2, #0x80
	bl func_08120EF8
	ldr r0, _080303B4 @ =0x0203DC90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303B8 @ =0x0203DCD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303BC @ =0x0203DEE0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303C0 @ =0x0203DE50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303C4 @ =0x0203DA10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303C8 @ =0x0203DAD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303CC @ =0x0203DC50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303D0 @ =0x0203DEA0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303D4 @ =0x0203DA90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303D8 @ =0x0203DD10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303DC @ =0x0203DF20
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303E0 @ =0x0203DDD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303E4 @ =0x0203DA50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303E8 @ =0x0203DE10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303EC @ =0x0203DC10
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303F0 @ =0x0203D990
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303F4 @ =0x0203DB50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303F8 @ =0x0203DBD0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _080303FC @ =0x0203DD90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _08030400 @ =0x0203D9D0
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _08030404 @ =0x0203DB90
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	ldr r0, _08030408 @ =0x0203DD50
	movs r1, #0xFF
	movs r2, #0x00
	bl func_08120EF8
	b _08030530
_080303A8: .4byte 0x02039B84
_080303AC: .4byte 0xFFFFC000
_080303B0: .4byte 0x0203DB10
_080303B4: .4byte 0x0203DC90
_080303B8: .4byte 0x0203DCD0
_080303BC: .4byte 0x0203DEE0
_080303C0: .4byte 0x0203DE50
_080303C4: .4byte 0x0203DA10
_080303C8: .4byte 0x0203DAD0
_080303CC: .4byte 0x0203DC50
_080303D0: .4byte 0x0203DEA0
_080303D4: .4byte 0x0203DA90
_080303D8: .4byte 0x0203DD10
_080303DC: .4byte 0x0203DF20
_080303E0: .4byte 0x0203DDD0
_080303E4: .4byte 0x0203DA50
_080303E8: .4byte 0x0203DE10
_080303EC: .4byte 0x0203DC10
_080303F0: .4byte 0x0203D990
_080303F4: .4byte 0x0203DB50
_080303F8: .4byte 0x0203DBD0
_080303FC: .4byte 0x0203DD90
_08030400: .4byte 0x0203D9D0
_08030404: .4byte 0x0203DB90
_08030408: .4byte 0x0203DD50
_0803040C:
	adds r0, r5, #0x0
	adds r0, #0x14
	movs r4, #0xF0
	lsls r4, r4, #0x07
	ldrh r2, [r5, #0x24]
	adds r1, r4, #0x0
	bl func_080058FC
	adds r0, r5, #0x0
	adds r0, #0x1C
	ldrh r2, [r5, #0x24]
	adds r1, r4, #0x0
	bl func_080058FC
	ldrh r1, [r5, #0x24]
	movs r2, #0x24
	ldsh r0, [r5, r2]
	cmp r0, #0x01
	ble _08030530
	subs r0, r1, #0x1
	strh r0, [r5, #0x24]
	b _08030530
_08030438:
	ldrb r0, [r5, #0x10]
	cmp r0, #0x00
	beq _08030530
	ldr r0, _08030538 @ =0x0203DB10
	movs r4, #0x80
	lsls r4, r4, #0x01
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803053C @ =0x0203DC90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030540 @ =0x0203DCD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030544 @ =0x0203DEE0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030548 @ =0x0203DE50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803054C @ =0x0203DA10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030550 @ =0x0203DAD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030554 @ =0x0203DC50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030558 @ =0x0203DEA0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803055C @ =0x0203DA90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030560 @ =0x0203DD10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030564 @ =0x0203DF20
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030568 @ =0x0203DDD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803056C @ =0x0203DA50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030570 @ =0x0203DE10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030574 @ =0x0203DC10
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030578 @ =0x0203D990
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803057C @ =0x0203DB50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030580 @ =0x0203DBD0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030584 @ =0x0203DD90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030588 @ =0x0203D9D0
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _0803058C @ =0x0203DB90
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	ldr r0, _08030590 @ =0x0203DD50
	movs r1, #0xFF
	adds r2, r4, #0x0
	bl func_08120EF8
	strb r6, [r5, #0x10]
	movs r0, #0x00
	bl func_080063C4
_08030530:
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_08030538: .4byte 0x0203DB10
_0803053C: .4byte 0x0203DC90
_08030540: .4byte 0x0203DCD0
_08030544: .4byte 0x0203DEE0
_08030548: .4byte 0x0203DE50
_0803054C: .4byte 0x0203DA10
_08030550: .4byte 0x0203DAD0
_08030554: .4byte 0x0203DC50
_08030558: .4byte 0x0203DEA0
_0803055C: .4byte 0x0203DA90
_08030560: .4byte 0x0203DD10
_08030564: .4byte 0x0203DF20
_08030568: .4byte 0x0203DDD0
_0803056C: .4byte 0x0203DA50
_08030570: .4byte 0x0203DE10
_08030574: .4byte 0x0203DC10
_08030578: .4byte 0x0203D990
_0803057C: .4byte 0x0203DB50
_08030580: .4byte 0x0203DBD0
_08030584: .4byte 0x0203DD90
_08030588: .4byte 0x0203D9D0
_0803058C: .4byte 0x0203DB90
_08030590: .4byte 0x0203DD50
.syntax divided
