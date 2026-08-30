.syntax unified
	.align 2, 0
	.global task_status_stocklist_0
	.thumb
	.thumb_func
	.type task_status_stocklist_0, %function
task_status_stocklist_0: @ 080D807C
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, _080D80CC @ =0x02034F04
	str r6, [r0, #0x00]
	movs r2, #0x98
	lsls r2, r2, #0x03
	adds r0, r6, r2
	str r1, [r0, #0x00]
	adds r5, r6, #0x0
	movs r4, #0x03
_080D8090:
	adds r0, r5, #0x0
	bl func_080D8584
	movs r0, #0x92
	lsls r0, r0, #0x01
	adds r5, r5, r0
	subs r4, #0x01
	cmp r4, #0x00
	bge _080D8090
	ldr r0, _080D80D0 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D80D4
	movs r4, #0x42
_080D80B0:
	adds r0, r4, #0x0
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D80C4
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080D8590
_080D80C4:
	adds r4, #0x01
	cmp r4, #0x45
	ble _080D80B0
	b _080D810A
_080D80CC: .4byte 0x02034F04
_080D80D0: .4byte 0x02039BB0
_080D80D4:
	movs r4, #0x00
_080D80D6:
	adds r0, r4, #0x0
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D8104
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl func_080D8590
	adds r0, r4, #0x0
	bl func_080D85A8
	adds r1, r0, #0x0
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r6, r0
	adds r1, r4, #0x0
	bl func_080D8590
_080D8104:
	adds r4, #0x01
	cmp r4, #0x41
	ble _080D80D6
_080D810A:
	movs r1, #0x00
	movs r4, #0x07
	ldr r2, _080D8170 @ =0x000004AC
	adds r0, r6, r2
_080D8112:
	str r1, [r0, #0x00]
	subs r0, #0x04
	subs r4, #0x01
	cmp r4, #0x00
	bge _080D8112
	movs r4, #0x00
	movs r0, #0x00
	bl func_080D8474
	ldr r0, _080D8174 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	movs r2, #0x96
	lsls r2, r2, #0x03
	adds r1, r6, r2
	str r0, [r1, #0x00]
	ldr r0, _080D8178 @ =0x097A2E16
	movs r1, #0xC0
	bl func_080026A4
	ldr r2, _080D817C @ =0x000004B4
	adds r1, r6, r2
	str r0, [r1, #0x00]
	ldr r0, _080D8180 @ =0x0984B278
	movs r1, #0x20
	bl func_08002A14
	movs r2, #0x97
	lsls r2, r2, #0x03
	adds r1, r6, r2
	str r0, [r1, #0x00]
	ldr r0, _080D8184 @ =0x000004BC
	adds r1, r6, r0
	ldr r0, _080D8188 @ =0x097A2DF8
	str r0, [r1, #0x00]
	ldr r1, _080D818C @ =0x000004C6
	adds r0, r6, r1
	movs r1, #0x00
	strh r4, [r0, #0x00]
	adds r2, #0x10
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D8170: .4byte 0x000004AC
_080D8174: .4byte 0x08F69BA4
_080D8178: .4byte 0x097A2E16
_080D817C: .4byte 0x000004B4
_080D8180: .4byte 0x0984B278
_080D8184: .4byte 0x000004BC
_080D8188: .4byte 0x097A2DF8
_080D818C: .4byte 0x000004C6
.syntax divided
