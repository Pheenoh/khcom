.syntax unified
	.align 2, 0
	.global task_hum_vixen_frg_0
	.thumb
	.thumb_func
	.type task_hum_vixen_frg_0, %function
task_hum_vixen_frg_0: @ 08055E2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	adds r7, r1, #0x0
	ldr r0, _08055F18 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	ldrh r1, [r0, #0x06]
	ldr r2, _08055F1C @ =0x08C1E78C
	movs r3, #0x98
	lsls r3, r3, #0x03
	adds r0, r4, #0x0
	bl func_0800380C
	str r4, [r4, #0x30]
	ldr r0, _08055F20 @ =0x08F6DCA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x34]
	movs r1, #0x00
	movs r0, #0x00
	strh r0, [r4, #0x38]
	movs r2, #0x87
	lsls r2, r2, #0x02
	adds r0, r4, r2
	strb r1, [r0, #0x00]
	movs r6, #0x00
	ldr r0, _08055F24 @ =0x08121400
	mov r8, r0
	adds r5, r4, #0x0
	adds r5, #0x3C
_08055E74:
	lsls r2, r6, #0x03
	ldr r0, _08055F28 @ =0x0813FA00
	adds r2, r2, r0
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r7, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x04]
	ldr r0, [r7, #0x04]
	str r0, [r5, #0x08]
	movs r0, #0x02
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r7, #0x08]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldrh r0, [r2, #0x06]
	strh r0, [r5, #0x1C]
	ldr r1, _08055F2C @ =0x09EE218C
	ldrh r0, [r2, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08055F30 @ =0x00000401
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08055F34 @ =0xFFFFFB00
	adds r0, r0, r1
	str r0, [r5, #0x10]
	bl GetRandom
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xE0
	lsls r1, r1, #0x02
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r4, #0x01
	add r1, r8
	movs r2, #0x00
	ldsh r1, [r1, r2]
	muls r1, r0
	asrs r1, r1, #0x08
	str r1, [r5, #0x14]
	adds r4, #0x40
	lsls r4, r4, #0x01
	add r4, r8
	movs r2, #0x00
	ldsh r1, [r4, r2]
	negs r1, r1
	asrs r0, r0, #0x01
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r5, #0x18]
	adds r5, #0x20
	adds r6, #0x01
	cmp r6, #0x0E
	ble _08055E74
	movs r0, #0xA8
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08055F18: .4byte 0x02039B84
_08055F1C: .4byte 0x08C1E78C
_08055F20: .4byte 0x08F6DCA4
_08055F24: .4byte 0x08121400
_08055F28: .4byte 0x0813FA00
_08055F2C: .4byte 0x09EE218C
_08055F30: .4byte 0x00000401
_08055F34: .4byte 0xFFFFFB00
.syntax divided
