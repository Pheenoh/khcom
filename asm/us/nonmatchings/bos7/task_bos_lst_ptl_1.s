.syntax unified
	.align 2, 0
	.global task_bos_lst_ptl_1
	.thumb
	.thumb_func
	.type task_bos_lst_ptl_1, %function
task_bos_lst_ptl_1: @ 08111A7C
	push {r4, r5, r6, lr}
	mov r12, r0
	movs r5, #0x01
	movs r2, #0x00
	ldsh r1, [r0, r2]
	cmp r1, #0x01
	beq _08111ACA
	cmp r1, #0x01
	bgt _08111A94
	cmp r1, #0x00
	beq _08111A9E
	b _08111A98
_08111A94:
	cmp r1, #0x02
	beq _08111B30
_08111A98:
	mov r4, r12
	adds r4, #0x18
	b _08111B44
_08111A9E:
	mov r3, r12
	ldrh r0, [r3, #0x06]
	subs r0, #0x01
	strh r0, [r3, #0x06]
	lsls r0, r0, #0x10
	mov r4, r12
	adds r4, #0x18
	cmp r0, #0x00
	bgt _08111B44
	strh r5, [r3, #0x00]
	strh r1, [r3, #0x02]
	strh r1, [r3, #0x04]
	strh r1, [r3, #0x06]
	adds r0, r4, #0x0
	bl func_08005B64
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl AnimChange
	b _08111B44
_08111ACA:
	mov r4, r12
	ldr r0, [r4, #0x08]
	subs r0, #0x80
	str r0, [r4, #0x08]
	ldr r1, [r4, #0x0C]
	movs r6, #0x80
	lsls r6, r6, #0x01
	adds r1, r1, r6
	str r1, [r4, #0x0C]
	ldr r3, _08111B2C @ =0x08121400
	movs r2, #0x04
	ldsh r0, [r4, r2]
	lsls r0, r0, #0x03
	movs r2, #0xFF
	ands r0, r2
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	negs r0, r0
	mov r6, r12
	str r0, [r6, #0x10]
	movs r4, #0x04
	ldsh r0, [r6, r4]
	lsls r0, r0, #0x01
	ands r0, r2
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r6, #0x00
	ldsh r0, [r0, r6]
	mov r2, r12
	str r0, [r2, #0x14]
	ldrh r0, [r2, #0x04]
	adds r0, #0x01
	movs r2, #0x00
	mov r3, r12
	strh r0, [r3, #0x04]
	asrs r1, r1, #0x08
	mov r4, r12
	adds r4, #0x18
	cmp r1, #0xA8
	ble _08111B44
	movs r0, #0x02
	strh r0, [r3, #0x00]
	strh r2, [r3, #0x02]
	strh r2, [r3, #0x04]
	strh r2, [r3, #0x06]
	b _08111B44
_08111B2C: .4byte 0x08121400
_08111B30:
	mov r4, r12
	adds r4, #0x18
	adds r0, r4, #0x0
	bl func_08005B64
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimChange
_08111B44:
	adds r0, r4, #0x0
	bl AnimUpdate
	adds r0, r5, #0x0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
