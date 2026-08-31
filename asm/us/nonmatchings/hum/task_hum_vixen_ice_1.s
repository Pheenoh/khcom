.syntax unified
	.align 2, 0
	.global task_hum_vixen_ice_1
	.thumb
	.thumb_func
	.type task_hum_vixen_ice_1, %function
task_hum_vixen_ice_1: @ 080556DC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	ldr r0, [r5, #0x24]
	ldrb r4, [r0, #0x01]
	cmp r4, #0x00
	bne _08055710
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080556F0
	b _080558D0
_080556F0:
	ldr r0, [r5, #0x08]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, [r5, #0x24]
	strb r4, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x28
	movs r1, #0x01
	bl func_08012614
	b _080558D0
_08055710:
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0805577A
	ldr r0, [r5, #0x08]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r1, [r5, #0x24]
	movs r0, #0x00
	strb r0, [r1, #0x00]
	str r0, [r5, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x84
	strh r0, [r1, #0x00]
	adds r1, #0x08
	movs r0, #0x0A
	str r0, [r1, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x01
	beq _0805576A
	cmp r0, #0x01
	bgt _0805575A
	cmp r0, #0x00
	beq _08055760
	b _0805577A
_0805575A:
	cmp r0, #0x02
	beq _08055772
	b _0805577A
_08055760:
	adds r1, r5, #0x0
	adds r1, #0x90
	movs r0, #0x80
	lsls r0, r0, #0x01
	b _08055778
_0805576A:
	adds r1, r5, #0x0
	adds r1, #0x90
	movs r0, #0xC0
	b _08055778
_08055772:
	adds r1, r5, #0x0
	adds r1, #0x90
	movs r0, #0x80
_08055778:
	str r0, [r1, #0x00]
_0805577A:
	ldr r0, [r5, #0x00]
	cmp r0, #0x01
	beq _080557FC
	cmp r0, #0x01
	bcc _0805578E
	cmp r0, #0x02
	beq _0805583C
	adds r7, r5, #0x0
	adds r7, #0x0C
	b _08055870
_0805578E:
	adds r6, r5, #0x0
	adds r6, #0x84
	movs r1, #0x00
	ldsh r0, [r6, r1]
	adds r4, r5, #0x0
	adds r4, #0x86
	cmp r0, #0x00
	bne _080557A8
	movs r0, #0x1E
	strh r0, [r4, #0x00]
	ldrh r0, [r6, #0x00]
	adds r0, #0x01
	strh r0, [r6, #0x00]
_080557A8:
	adds r0, r5, #0x0
	adds r0, #0x8C
	adds r1, r5, #0x0
	adds r1, #0x90
	ldr r1, [r1, #0x00]
	ldrh r2, [r4, #0x00]
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	adds r7, r5, #0x0
	adds r7, #0x0C
	cmp r0, #0x00
	bgt _08055870
	adds r0, r5, #0x0
	adds r0, #0x28
	movs r1, #0x00
	bl func_08012614
	movs r0, #0x01
	str r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r6, #0x00]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080557F8 @ =0x00000259
	bl __umodsi3
	movs r1, #0x96
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r1, r5, #0x0
	adds r1, #0x88
	strh r0, [r1, #0x00]
	b _08055870
	.byte 0x00, 0x00
_080557F8: .4byte 0x00000259
_080557FC:
	adds r4, r5, #0x0
	adds r4, #0x84
	movs r1, #0x00
	ldsh r0, [r4, r1]
	adds r7, r5, #0x0
	adds r7, #0x0C
	cmp r0, #0x00
	bne _0805581C
	adds r0, r7, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimStart
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
_0805581C:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #0x01
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	bne _08055870
	movs r0, #0x02
	str r0, [r5, #0x00]
	strh r1, [r4, #0x00]
	b _08055870
_0805583C:
	adds r4, r5, #0x0
	adds r4, #0x84
	movs r1, #0x00
	ldsh r0, [r4, r1]
	adds r7, r5, #0x0
	adds r7, #0x0C
	cmp r0, #0x00
	bne _0805585C
	adds r0, r7, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
_0805585C:
	adds r0, r7, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08055870
	movs r0, #0x01
	str r0, [r5, #0x00]
	movs r0, #0x00
	strh r0, [r4, #0x00]
_08055870:
	ldr r0, [r5, #0x00]
	cmp r0, #0x02
	bhi _080558CA
	cmp r0, #0x01
	bcc _080558CA
	adds r6, r5, #0x0
	adds r6, #0x8C
	adds r4, r5, #0x0
	adds r4, #0x88
	ldrh r2, [r4, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x0A
	bl func_080058FC
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _080558A4
	ldr r1, [r5, #0x24]
	movs r0, #0x00
	strb r0, [r1, #0x01]
	ldr r1, [r5, #0x24]
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080558A4:
	adds r4, r5, #0x0
	adds r4, #0x28
	ldr r0, [r6, #0x00]
	lsls r1, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x02
	subs r1, r1, r0
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	adds r0, r4, #0x0
	bl func_08012650
	ldr r0, [r5, #0x24]
	ldr r1, [r0, #0x04]
	ldr r2, [r0, #0x08]
	adds r0, r4, #0x0
	movs r3, #0x00
	bl func_08012324
_080558CA:
	adds r0, r7, #0x0
	bl AnimUpdate
_080558D0:
	movs r0, #0x01
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
