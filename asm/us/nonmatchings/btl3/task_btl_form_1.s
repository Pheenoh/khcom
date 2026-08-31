.syntax unified
	.align 2, 0
	.global task_btl_form_1
	.thumb
	.thumb_func
	.type task_btl_form_1, %function
task_btl_form_1: @ 0803FE74
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	ldr r0, _0803FEC0 @ =0x02039B84
	ldr r6, [r0, #0x00]
	ldr r0, [r6, #0x68]
	ldr r1, [r6, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x11
	movs r0, #0x00
	ands r1, r2
	adds r3, r1, #0x0
	orrs r3, r0
	cmp r3, #0x00
	beq _0803FE92
	b _08040042
_0803FE92:
	ldrh r7, [r4, #0x20]
	movs r0, #0x02
	ands r0, r7
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0x00
	beq _0803FEF0
	ldr r5, [r4, #0x08]
	movs r0, #0x08
	ldsh r1, [r5, r0]
	ldrh r2, [r4, #0x22]
	adds r0, r6, #0x0
	adds r0, #0xEC
	movs r6, #0x00
	ldsh r0, [r0, r6]
	adds r0, r2, r0
	cmp r1, r0
	bge _0803FEB8
	b _08040040
_0803FEB8:
	cmp r2, #0x00
	bne _0803FEC4
	movs r0, #0x00
	b _08040042
_0803FEC0: .4byte 0x02039B84
_0803FEC4:
	movs r1, #0x10
	ldsh r0, [r4, r1]
	ldr r1, [r5, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x0C]
	ldrh r0, [r0, #0x08]
	strh r0, [r4, #0x00]
	strh r3, [r4, #0x02]
	strh r3, [r4, #0x04]
	ldr r0, _0803FEEC @ =0x0000FFFD
	ands r0, r7
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x10]
	adds r0, #0x01
	strh r0, [r4, #0x10]
	movs r0, #0x64
	strh r0, [r4, #0x24]
	b _08040040
_0803FEEC: .4byte 0x0000FFFD
_0803FEF0:
	ldr r0, [r4, #0x0C]
	movs r3, #0x00
	ldsh r2, [r0, r3]
	movs r3, #0x04
	ldsh r1, [r4, r3]
	adds r3, r0, #0x0
	cmp r2, r1
	bgt _0803FF58
	ldrh r0, [r4, #0x24]
	subs r1, r0, #0x1
	strh r1, [r4, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _0803FF0E
	b _08040040
_0803FF0E:
	movs r0, #0x02
	orrs r0, r7
	strh r0, [r4, #0x20]
	ldr r2, _0803FF40 @ =0x02039BB0
	movs r6, #0xDC
	lsls r6, r6, #0x01
	adds r0, r2, r6
	ldr r0, [r0, #0x00]
	cmp r0, #0x04
	beq _0803FF2C
	ldr r0, [r2, #0x08]
	movs r1, #0x05
	negs r1, r1
	ands r0, r1
	str r0, [r2, #0x08]
_0803FF2C:
	ldr r2, [r4, #0x08]
	movs r0, #0x10
	ldsh r1, [r4, r0]
	movs r3, #0x00
	ldsh r0, [r2, r3]
	cmp r1, r0
	blt _0803FF44
	strh r5, [r4, #0x22]
	movs r0, #0x00
	b _08040042
_0803FF40: .4byte 0x02039BB0
_0803FF44:
	movs r6, #0x10
	ldsh r0, [r4, r6]
	ldr r1, [r2, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_0803FDC8
	strh r0, [r4, #0x22]
	b _08040040
_0803FF58:
	ldrh r0, [r4, #0x00]
	movs r1, #0x00
	ldsh r2, [r4, r1]
	cmp r2, #0x00
	ble _0803FF68
	subs r0, #0x01
	strh r0, [r4, #0x00]
	b _08040040
_0803FF68:
	cmp r2, #0x00
	bne _0803FFD6
	ldr r1, [r6, #0x7C]
	ldr r0, [r1, #0x04]
	movs r3, #0x80
	lsls r3, r3, #0x09
	adds r0, r0, r3
	asrs r0, r0, #0x01
	str r0, [r4, #0x14]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x18]
	str r2, [r4, #0x1C]
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803FFAC
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _0803FFC8
	ldrh r1, [r4, #0x20]
	movs r0, #0x01
	orrs r0, r1
	b _0803FFCE
_0803FFAC:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _0803FFC8
	ldrh r1, [r4, #0x20]
	movs r0, #0x01
	orrs r0, r1
	b _0803FFCE
_0803FFC8:
	ldrh r1, [r4, #0x20]
	ldr r0, _08040008 @ =0x0000FFFE
	ands r0, r1
_0803FFCE:
	strh r0, [r4, #0x20]
	ldr r0, _0804000C @ =0x0000FFFF
	strh r0, [r4, #0x00]
	ldr r3, [r4, #0x0C]
_0803FFD6:
	movs r6, #0x04
	ldsh r1, [r4, r6]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldr r1, [r3, #0x04]
	adds r5, r1, r0
	ldrh r2, [r4, #0x02]
	movs r0, #0x02
	ldsh r1, [r4, r0]
	movs r3, #0x0A
	ldsh r0, [r5, r3]
	cmp r1, r0
	blt _0804003C
	ldrh r1, [r4, #0x20]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08040010
	movs r6, #0x04
	ldsh r0, [r5, r6]
	lsls r0, r0, #0x08
	ldr r1, [r4, #0x14]
	subs r1, r1, r0
	b _0804001A
_08040008: .4byte 0x0000FFFE
_0804000C: .4byte 0x0000FFFF
_08040010:
	movs r1, #0x04
	ldsh r0, [r5, r1]
	lsls r0, r0, #0x08
	ldr r1, [r4, #0x14]
	adds r1, r1, r0
_0804001A:
	movs r2, #0x06
	ldsh r0, [r5, r2]
	lsls r0, r0, #0x08
	ldr r2, [r4, #0x18]
	adds r2, r2, r0
	movs r3, #0x08
	ldsh r0, [r5, r3]
	lsls r0, r0, #0x08
	ldr r3, [r4, #0x1C]
	adds r3, r3, r0
	ldr r0, [r5, #0x00]
	bl func_0801BDDC
	ldrh r0, [r4, #0x04]
	adds r0, #0x01
	strh r0, [r4, #0x04]
	b _08040040
_0804003C:
	adds r0, r2, #0x1
	strh r0, [r4, #0x02]
_08040040:
	movs r0, #0x01
_08040042:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
