.syntax unified
	.align 2, 0
	.global task_btl_exp_0
	.thumb
	.thumb_func
	.type task_btl_exp_0, %function
task_btl_exp_0: @ 0805CF24
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, _0805CF90 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x00]
	ldr r1, _0805CF94 @ =0x08B25EF0
	movs r0, #0xA0
	bl func_080028F8
	str r0, [r4, #0x04]
	movs r0, #0x00
	str r0, [r4, #0x20]
	movs r5, #0x00
_0805CF42:
	movs r0, #0x20
	ldr r1, _0805CF94 @ =0x08B25EF0
	bl func_080028F8
	lsls r2, r5, #0x02
	adds r1, r4, #0x0
	adds r1, #0x08
	adds r1, r1, r2
	str r0, [r1, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x24
	adds r0, r0, r2
	movs r3, #0x00
	str r3, [r0, #0x00]
	adds r5, #0x01
	cmp r5, #0x05
	ble _0805CF42
	strh r3, [r4, #0x3C]
	ldr r2, _0805CF98 @ =0x02039BB0
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r2, r1
	ldrb r0, [r0, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x3E
	strb r0, [r1, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r2, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x44]
	str r3, [r4, #0x48]
	adds r0, r4, #0x0
	adds r0, #0x40
	strh r3, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805CF90: .4byte 0x08F69BA4
_0805CF94: .4byte 0x08B25EF0
_0805CF98: .4byte 0x02039BB0
.syntax divided
