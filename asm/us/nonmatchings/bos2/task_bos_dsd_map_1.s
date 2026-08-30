.syntax unified
	.align 2, 0
	.global task_bos_dsd_map_1
	.thumb
	.thumb_func
	.type task_bos_dsd_map_1, %function
task_bos_dsd_map_1: @ 080C3E64
	push {r4, lr}
	bl func_0802F208
	ldr r0, _080C3ED4 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r3, r0, #0x03
	ldr r0, [r2, #0x14]
	ldr r1, [r2, #0x0C]
	subs r0, r0, r1
	asrs r4, r0, #0x03
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r3, r0
	bgt _080C3E8C
	ldr r0, _080C3ED8 @ =0xFFFFFB00
	cmp r3, r0
	bge _080C3E8E
_080C3E8C:
	adds r3, r0, #0x0
_080C3E8E:
	ldr r1, _080C3ED4 @ =0x02039B84
	ldr r2, [r1, #0x00]
	ldr r0, [r2, #0x08]
	adds r3, r0, r3
	str r3, [r2, #0x08]
	ldr r0, [r2, #0x0C]
	adds r0, r0, r4
	str r0, [r2, #0x0C]
	str r3, [r2, #0x00]
	str r0, [r2, #0x04]
	adds r0, r2, #0x0
	adds r0, #0xDA
	movs r4, #0x00
	ldsh r0, [r0, r4]
	adds r0, #0x78
	lsls r0, r0, #0x08
	cmp r3, r0
	blt _080C3EC2
	adds r0, r2, #0x0
	adds r0, #0xDC
	movs r4, #0x00
	ldsh r0, [r0, r4]
	subs r0, #0x78
	lsls r0, r0, #0x08
	cmp r3, r0
	ble _080C3EC4
_080C3EC2:
	str r0, [r2, #0x00]
_080C3EC4:
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x04]
	ldr r0, _080C3EDC @ =0x00004FFF
	cmp r2, r0
	bgt _080C3EE0
	adds r0, #0x01
	b _080C3EF0
	.byte 0x00, 0x00
_080C3ED4: .4byte 0x02039B84
_080C3ED8: .4byte 0xFFFFFB00
_080C3EDC: .4byte 0x00004FFF
_080C3EE0:
	adds r0, r1, #0x0
	adds r0, #0xE0
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, #0x50
	lsls r0, r0, #0x08
	cmp r2, r0
	ble _080C3EF2
_080C3EF0:
	str r0, [r1, #0x04]
_080C3EF2:
	bl func_0802F268
	ldr r1, _080C3F20 @ =0x02039B84
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x04]
	adds r2, r2, r0
	str r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	subs r1, #0x78
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	asrs r2, r2, #0x08
	subs r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
_080C3F20: .4byte 0x02039B84
.syntax divided
