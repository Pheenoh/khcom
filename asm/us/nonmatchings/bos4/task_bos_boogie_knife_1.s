.syntax unified
	.align 2, 0
	.global task_bos_boogie_knife_1
	.thumb
	.thumb_func
	.type task_bos_boogie_knife_1, %function
task_bos_boogie_knife_1: @ 080DB210
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x2C
	ldr r0, _080DB234 @ =0x0203C574
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DB224
	movs r0, #0x02
	str r0, [r4, #0x00]
_080DB224:
	ldr r0, [r4, #0x00]
	cmp r0, #0x01
	beq _080DB26E
	cmp r0, #0x01
	bcc _080DB238
	cmp r0, #0x02
	beq _080DB2D8
	b _080DB2F4
_080DB234: .4byte 0x0203C574
_080DB238:
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r2, #0x00]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _080DB2D0
	movs r0, #0x00
	str r0, [r5, #0x0C]
	movs r0, #0x01
	str r0, [r4, #0x00]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	b _080DB2F4
_080DB26E:
	movs r0, #0xA0
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r5, #0x04]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	movs r1, #0x9E
	lsls r1, r1, #0x01
	adds r2, r4, r1
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r2, #0x00]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldrh r0, [r4, #0x04]
	adds r0, #0x01
	strh r0, [r4, #0x04]
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _080DB2D0
	movs r0, #0x00
	str r0, [r5, #0x0C]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	movs r1, #0x04
	ldsh r0, [r4, r1]
	bl __floatsisf
	ldr r1, _080DB2CC @ =0x4347FFFF
	bl __gtsf2
	cmp r0, #0x00
	ble _080DB2D0
	movs r0, #0x02
	str r0, [r4, #0x00]
	b _080DB2F4
	.byte 0x00, 0x00
_080DB2CC: .4byte 0x4347FFFF
_080DB2D0:
	adds r0, r4, #0x0
	bl func_080DB04C
	b _080DB2F4
_080DB2D8:
	ldr r0, [r5, #0x0C]
	ldr r1, _080DB2EC @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r1, _080DB2F0 @ =0xFFFF4000
	cmp r0, r1
	bge _080DB2F4
	movs r0, #0x00
	b _080DB30C
	.byte 0x00, 0x00
_080DB2EC: .4byte 0xFFFFF800
_080DB2F0: .4byte 0xFFFF4000
_080DB2F4:
	adds r0, r4, #0x0
	adds r0, #0x14
	bl func_08005A64
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	bl func_08012324
	movs r0, #0x01
_080DB30C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
