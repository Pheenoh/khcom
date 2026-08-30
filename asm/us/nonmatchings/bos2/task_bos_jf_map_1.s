.syntax unified
	.align 2, 0
	.global task_bos_jf_map_1
	.thumb
	.thumb_func
	.type task_bos_jf_map_1, %function
task_bos_jf_map_1: @ 080BD9A8
	push {r4, lr}
	adds r1, r0, #0x0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	movs r2, #0x00
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x0E
	ble _080BD9E0
	strh r2, [r1, #0x00]
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x07
	ble _080BD9CE
	strh r2, [r1, #0x02]
_080BD9CE:
	movs r2, #0x02
	ldsh r0, [r1, r2]
	lsls r0, r0, #0x05
	ldr r1, _080BDA9C @ =0x096FB484
	adds r0, r0, r1
	ldr r1, _080BDAA0 @ =0x05000020
	movs r2, #0x20
	bl func_08005BE8
_080BD9E0:
	bl func_0802F208
	ldr r0, _080BDAA4 @ =0x02039B84
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
	bgt _080BDA06
	ldr r0, _080BDAA8 @ =0xFFFFFB00
	cmp r3, r0
	bge _080BDA08
_080BDA06:
	adds r3, r0, #0x0
_080BDA08:
	ldr r1, _080BDAA4 @ =0x02039B84
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
	adds r0, #0x14
	lsls r0, r0, #0x08
	cmp r3, r0
	blt _080BDA3C
	adds r0, r2, #0x0
	adds r0, #0xDC
	movs r4, #0x00
	ldsh r0, [r0, r4]
	subs r0, #0x1C
	lsls r0, r0, #0x08
	cmp r3, r0
	ble _080BDA3E
_080BDA3C:
	str r0, [r2, #0x00]
_080BDA3E:
	ldr r1, [r1, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xDE
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x90
	lsls r0, r0, #0x08
	ldr r2, [r1, #0x04]
	cmp r2, r0
	blt _080BDA62
	adds r0, r1, #0x0
	adds r0, #0xE0
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, #0x48
	lsls r0, r0, #0x08
	cmp r2, r0
	ble _080BDA64
_080BDA62:
	str r0, [r1, #0x04]
_080BDA64:
	bl func_0802F268
	adds r4, r0, #0x0
	bl func_080BDB58
	ldr r1, _080BDAA4 @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r4, r4, r0
	ldr r2, [r1, #0x04]
	adds r2, r2, r4
	str r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	adds r1, #0x08
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	asrs r2, r2, #0x08
	adds r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080BDA9C: .4byte 0x096FB484
_080BDAA0: .4byte 0x05000020
_080BDAA4: .4byte 0x02039B84
_080BDAA8: .4byte 0xFFFFFB00
.syntax divided
