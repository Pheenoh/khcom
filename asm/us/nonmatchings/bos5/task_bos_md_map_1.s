.syntax unified
	.align 2, 0
	.global task_bos_md_map_1
	.thumb
	.thumb_func
	.type task_bos_md_map_1, %function
task_bos_md_map_1: @ 080FCB30
	push {r4, r5, r6, lr}
	bl func_0802F208
	ldr r0, _080FCB88 @ =0x02039B84
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
	bgt _080FCB58
	ldr r0, _080FCB8C @ =0xFFFFFB00
	cmp r4, r0
	bge _080FCB5A
_080FCB58:
	adds r4, r0, #0x0
_080FCB5A:
	ldr r2, _080FCB88 @ =0x02039B84
	ldr r3, [r2, #0x00]
	ldr r0, [r3, #0x08]
	adds r4, r0, r4
	str r4, [r3, #0x08]
	ldr r0, [r3, #0x0C]
	adds r0, r0, r1
	str r0, [r3, #0x0C]
	str r4, [r3, #0x00]
	str r0, [r3, #0x04]
	ldr r0, _080FCB90 @ =0xFFFF8800
	adds r1, r4, r0
	adds r0, r3, #0x0
	adds r0, #0xDA
	movs r6, #0x00
	ldsh r5, [r0, r6]
	lsls r0, r5, #0x08
	cmp r1, r0
	bge _080FCB94
	adds r0, r5, #0x0
	adds r0, #0x78
	b _080FCBB0
	.byte 0x00, 0x00
_080FCB88: .4byte 0x02039B84
_080FCB8C: .4byte 0xFFFFFB00
_080FCB90: .4byte 0xFFFF8800
_080FCB94:
	movs r0, #0xF0
	lsls r0, r0, #0x07
	adds r1, r4, r0
	adds r0, r3, #0x0
	adds r0, #0xDC
	movs r5, #0x00
	ldsh r4, [r0, r5]
	adds r0, r4, #0x0
	adds r0, #0x60
	lsls r0, r0, #0x08
	cmp r1, r0
	ble _080FCBB4
	adds r0, r4, #0x0
	subs r0, #0x18
_080FCBB0:
	lsls r0, r0, #0x08
	str r0, [r3, #0x00]
_080FCBB4:
	ldr r1, [r2, #0x00]
	ldr r0, [r1, #0x04]
	movs r6, #0xA0
	lsls r6, r6, #0x07
	adds r3, r0, r6
	adds r0, r1, #0x0
	adds r0, #0xDE
	movs r4, #0x00
	ldsh r2, [r0, r4]
	lsls r0, r2, #0x08
	cmp r3, r0
	blt _080FCBDA
	adds r0, r1, #0x0
	adds r0, #0xE0
	movs r5, #0x00
	ldsh r2, [r0, r5]
	lsls r0, r2, #0x08
	cmp r3, r0
	ble _080FCBE2
_080FCBDA:
	adds r0, r2, #0x0
	subs r0, #0x50
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
_080FCBE2:
	bl func_0802F268
	ldr r1, _080FCC10 @ =0x02039B84
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
	adds r2, #0x28
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080FCC10: .4byte 0x02039B84
.syntax divided
