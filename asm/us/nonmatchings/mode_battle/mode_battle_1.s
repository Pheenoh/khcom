.syntax unified
	.align 2, 0
	.global mode_battle_1
	.thumb
	.thumb_func
	.type mode_battle_1, %function
mode_battle_1: @ 0800A4BC
	push {r4, r5, lr}
	ldr r4, _0800A4FC @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0x54
	bl func_08000EA4
	ldr r0, [r4, #0x00]
	adds r0, #0x54
	bl func_08000EE0
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x74
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r0, #0x00
	ble _0800A500
	adds r0, r1, #0x0
	adds r0, #0x40
	bl func_08000EE0
	ldr r0, [r4, #0x00]
	adds r0, #0x2C
	bl func_08000EE0
	ldr r1, [r4, #0x00]
	adds r1, #0x74
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	b _0800A596
	.byte 0x00, 0x00
_0800A4FC: .4byte 0x02039B84
_0800A500:
	adds r0, r1, #0x0
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800A578
	bl _08019CB4
	ldr r1, [r4, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x72
	ldrh r3, [r2, #0x00]
	movs r4, #0x00
	ldsh r0, [r2, r4]
	cmp r0, #0x00
	bgt _0800A528
	adds r0, r1, #0x0
	adds r0, #0x2C
	bl func_08000EA4
	b _0800A52C
_0800A528:
	subs r0, r3, #0x1
	strh r0, [r2, #0x00]
_0800A52C:
	ldr r4, _0800A59C @ =0x02039B84
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	bne _0800A546
	bl func_08012824
_0800A546:
	bl func_080125A4
	ldr r0, [r4, #0x00]
	adds r0, #0x40
	bl func_08000EE0
	ldr r5, [r4, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x10
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800A574
	ldr r2, _0800A5A0 @ =0xFF7FFFFF
	adds r0, r3, #0x0
	ands r0, r2
	adds r1, r4, #0x0
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
_0800A574:
	bl func_0801CC80
_0800A578:
	ldr r0, _0800A59C @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0800A596
	adds r0, r3, #0x0
	adds r0, #0x2C
	bl func_08000EE0
_0800A596:
	pop {r4, r5}
	pop {r0}
	bx r0
_0800A59C: .4byte 0x02039B84
_0800A5A0: .4byte 0xFF7FFFFF
.syntax divided
