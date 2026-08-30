.syntax unified
	.align 2, 0
	.global task_btl_premire_0
	.thumb
	.thumb_func
	.type task_btl_premire_0, %function
task_btl_premire_0: @ 080313E4
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x04]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x08]
	movs r0, #0x00
	mov r8, r0
	str r0, [r5, #0x0C]
	ldr r1, _080314EC @ =0x02039B84
	mov r9, r1
	ldr r0, [r1, #0x00]
	movs r4, #0x94
	lsls r4, r4, #0x01
	adds r0, r0, r4
	ldr r4, [r0, #0x00]
	cmp r4, #0x00
	beq _08031424
	adds r1, r5, #0x4
	adds r2, r5, #0x0
	adds r2, #0x08
	adds r3, r5, #0x0
	adds r3, #0x0C
	adds r0, r5, #0x0
	bl _call_via_r4
_08031424:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080314F0 @ =0x00000381
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x02
	adds r0, r0, r1
	negs r0, r0
	str r0, [r5, #0x20]
	bl func_080065A4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _080314F4 @ =0x08B209E0
	movs r1, #0xD0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x10]
	ldr r0, _080314F8 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x14]
	adds r4, r5, #0x0
	adds r4, #0x48
	ldr r1, _080314FC @ =0x09EE1278
	ldr r2, _08031500 @ =0x09EE1244
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x0A
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r5, #0x18]
	mov r4, r8
	strh r4, [r5, #0x28]
	ldr r0, _08031504 @ =0x08B208E8
	str r0, [r5, #0x1C]
	movs r0, #0x03
	strh r0, [r5, #0x2C]
	movs r1, #0x14
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	beq _08031496
	movs r0, #0x0B
	strh r0, [r5, #0x2C]
_08031496:
	movs r0, #0x80
	lsls r0, r0, #0x03
	str r0, [r5, #0x24]
	movs r3, #0xC0
	lsls r3, r3, #0x01
	mov r4, r8
	str r4, [r5, #0x30]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r5, #0x34]
	mov r0, r9
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _08031508 @ =0x08121400
	lsls r0, r7, #0x01
	adds r0, r0, r1
	movs r4, #0x00
	ldsh r0, [r0, r4]
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r5, #0x38]
	adds r0, r7, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r5, #0x3C]
	ldr r0, [r2, #0x7C]
	str r0, [r5, #0x44]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080314EC: .4byte 0x02039B84
_080314F0: .4byte 0x00000381
_080314F4: .4byte 0x08B209E0
_080314F8: .4byte 0x08F69BA4
_080314FC: .4byte 0x09EE1278
_08031500: .4byte 0x09EE1244
_08031504: .4byte 0x08B208E8
_08031508: .4byte 0x08121400
.syntax divided
