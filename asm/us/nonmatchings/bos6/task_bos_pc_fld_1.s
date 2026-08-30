.syntax unified
	.align 2, 0
	.global task_bos_pc_fld_1
	.thumb
	.thumb_func
	.type task_bos_pc_fld_1, %function
task_bos_pc_fld_1: @ 0810B5D8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	bl func_0802F208
	bl func_0810B434
	ldr r0, _0810B654 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x7C]
	ldr r0, [r2, #0x00]
	ldr r3, _0810B658 @ =0xFFFF8800
	adds r0, r0, r3
	ldr r1, [r1, #0x04]
	subs r1, r1, r0
	cmp r1, #0x00
	bge _0810B5FA
	movs r1, #0x00
_0810B5FA:
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r0, r0, #0x01
	movs r4, #0xF0
	lsls r4, r4, #0x08
	adds r0, r0, r4
	str r0, [r2, #0x10]
	ldr r1, [r2, #0x08]
	subs r0, r0, r1
	asrs r3, r0, #0x03
	ldr r0, [r2, #0x14]
	ldr r1, [r2, #0x0C]
	subs r0, r0, r1
	asrs r1, r0, #0x03
	movs r0, #0xA0
	lsls r0, r0, #0x03
	cmp r3, r0
	bgt _0810B624
	ldr r0, _0810B65C @ =0xFFFFFB00
	cmp r3, r0
	bge _0810B626
_0810B624:
	adds r3, r3, r0
_0810B626:
	ldr r2, _0810B654 @ =0x02039B84
	ldr r4, [r2, #0x00]
	ldr r0, [r4, #0x08]
	adds r3, r0, r3
	str r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	adds r0, r0, r1
	str r0, [r4, #0x0C]
	str r3, [r4, #0x00]
	str r0, [r4, #0x04]
	ldr r5, _0810B658 @ =0xFFFF8800
	adds r1, r3, r5
	adds r0, r4, #0x0
	adds r0, #0xDA
	movs r7, #0x00
	ldsh r5, [r0, r7]
	lsls r0, r5, #0x08
	cmp r1, r0
	bge _0810B660
	adds r0, r5, #0x0
	adds r0, #0x78
	b _0810B678
	.byte 0x00, 0x00
_0810B654: .4byte 0x02039B84
_0810B658: .4byte 0xFFFF8800
_0810B65C: .4byte 0xFFFFFB00
_0810B660:
	movs r1, #0xF0
	lsls r1, r1, #0x07
	adds r0, r3, r1
	adds r1, r4, #0x0
	adds r1, #0xDC
	movs r5, #0x00
	ldsh r3, [r1, r5]
	lsls r1, r3, #0x08
	cmp r0, r1
	ble _0810B67C
	adds r0, r3, #0x0
	subs r0, #0x78
_0810B678:
	lsls r0, r0, #0x08
	str r0, [r4, #0x00]
_0810B67C:
	ldr r3, [r2, #0x00]
	ldr r4, [r3, #0x04]
	movs r7, #0xC0
	lsls r7, r7, #0x06
	adds r1, r4, r7
	adds r0, r3, #0x0
	adds r0, #0xDE
	movs r5, #0x00
	ldsh r2, [r0, r5]
	lsls r0, r2, #0x08
	cmp r1, r0
	bge _0810B69A
	adds r0, r2, #0x0
	subs r0, #0x30
	b _0810B6B2
_0810B69A:
	movs r7, #0xA0
	lsls r7, r7, #0x07
	adds r0, r4, r7
	adds r1, r3, #0x0
	adds r1, #0xE0
	movs r4, #0x00
	ldsh r2, [r1, r4]
	lsls r1, r2, #0x08
	cmp r0, r1
	ble _0810B6B6
	adds r0, r2, #0x0
	subs r0, #0x50
_0810B6B2:
	lsls r0, r0, #0x08
	str r0, [r3, #0x04]
_0810B6B6:
	bl func_0802F268
	ldr r4, _0810B6F8 @ =0x02039B84
	ldr r2, [r4, #0x00]
	ldr r1, [r2, #0x04]
	adds r1, r1, r0
	str r1, [r2, #0x04]
	bl func_0810B49C
	ldr r1, [r4, #0x00]
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
	adds r0, r6, #0x0
	bl func_0810B4B4
	movs r0, #0x01
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0810B6F8: .4byte 0x02039B84
.syntax divided
