.syntax unified
	.align 2, 0
	.global task_bos_boogie_map_1
	.thumb
	.thumb_func
	.type task_bos_boogie_map_1, %function
task_bos_boogie_map_1: @ 080DAA9C
	push {r4, r5, r6, lr}
	bl func_0802F208
	ldr r0, _080DAAF4 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r4, r0, #0x03
	ldr r0, [r2, #0x14]
	ldr r1, [r2, #0x0C]
	subs r0, r0, r1
	asrs r1, r0, #0x03
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r4, r0
	bgt _080DAAC4
	ldr r0, _080DAAF8 @ =0xFFFFFB00
	cmp r4, r0
	bge _080DAAC6
_080DAAC4:
	adds r4, r0, #0x0
_080DAAC6:
	ldr r2, _080DAAF4 @ =0x02039B84
	ldr r3, [r2, #0x00]
	ldr r0, [r3, #0x08]
	adds r4, r0, r4
	str r4, [r3, #0x08]
	ldr r0, [r3, #0x0C]
	adds r0, r0, r1
	str r0, [r3, #0x0C]
	str r4, [r3, #0x00]
	str r0, [r3, #0x04]
	ldr r0, _080DAAFC @ =0xFFFF8800
	adds r1, r4, r0
	adds r0, r3, #0x0
	adds r0, #0xDA
	movs r6, #0x00
	ldsh r5, [r0, r6]
	lsls r0, r5, #0x08
	cmp r1, r0
	bge _080DAB00
	adds r0, r5, #0x0
	adds r0, #0x78
	b _080DAB18
	.byte 0x00, 0x00
_080DAAF4: .4byte 0x02039B84
_080DAAF8: .4byte 0xFFFFFB00
_080DAAFC: .4byte 0xFFFF8800
_080DAB00:
	movs r1, #0xF0
	lsls r1, r1, #0x07
	adds r0, r4, r1
	adds r1, r3, #0x0
	adds r1, #0xDC
	movs r5, #0x00
	ldsh r4, [r1, r5]
	lsls r1, r4, #0x08
	cmp r0, r1
	ble _080DAB1C
	adds r0, r4, #0x0
	subs r0, #0x78
_080DAB18:
	lsls r0, r0, #0x08
	str r0, [r3, #0x00]
_080DAB1C:
	ldr r2, [r2, #0x00]
	ldr r3, [r2, #0x04]
	ldr r6, _080DAB30 @ =0xFFFFB000
	adds r1, r3, r6
	ldr r0, _080DAB34 @ =0x00018BFF
	cmp r1, r0
	bgt _080DAB38
	movs r0, #0xEE
	lsls r0, r0, #0x09
	b _080DAB4A
_080DAB30: .4byte 0xFFFFB000
_080DAB34: .4byte 0x00018BFF
_080DAB38:
	movs r0, #0xA0
	lsls r0, r0, #0x07
	adds r1, r3, r0
	movs r0, #0x9E
	lsls r0, r0, #0x0A
	cmp r1, r0
	ble _080DAB4C
	movs r0, #0x8A
	lsls r0, r0, #0x0A
_080DAB4A:
	str r0, [r2, #0x04]
_080DAB4C:
	bl func_0802F268
	ldr r1, _080DAB7C @ =0x02039B84
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x04]
	adds r2, r2, r0
	str r2, [r1, #0x04]
	ldr r1, [r1, #0x00]
	asrs r1, r1, #0x08
	adds r1, #0x08
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	asrs r2, r2, #0x08
	ldr r5, _080DAB80 @ =0xFFFFFEF8
	adds r2, r2, r5
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080DAB7C: .4byte 0x02039B84
_080DAB80: .4byte 0xFFFFFEF8
.syntax divided
