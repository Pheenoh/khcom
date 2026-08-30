.syntax unified
	.align 2, 0
	.global task_hum_vixen_frg_1
	.thumb
	.thumb_func
	.type task_hum_vixen_frg_1, %function
task_hum_vixen_frg_1: @ 08055F38
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	ldr r0, _08055FE8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x0E
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _08055FEC
	mov r6, r9
	adds r6, #0x44
	mov r4, r9
	adds r4, #0x40
	movs r0, #0x0E
	mov r8, r0
_08055F64:
	ldr r0, [r4, #0x00]
	ldr r5, [r4, #0x10]
	adds r0, r0, r5
	str r0, [r4, #0x00]
	ldr r0, [r4, #0x04]
	ldr r3, [r4, #0x14]
	adds r0, r0, r3
	str r0, [r4, #0x04]
	ldr r1, [r4, #0x08]
	ldr r2, [r4, #0x0C]
	adds r1, r1, r2
	str r1, [r4, #0x08]
	ldr r0, _08055FE8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r7, #0x96
	lsls r7, r7, #0x01
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	adds r2, r2, r0
	str r2, [r4, #0x0C]
	cmp r1, #0x00
	ble _08055FA2
	movs r0, #0x00
	str r0, [r4, #0x08]
	asrs r0, r2, #0x01
	negs r0, r0
	str r0, [r4, #0x0C]
	asrs r0, r5, #0x01
	str r0, [r4, #0x10]
	asrs r0, r3, #0x01
	str r0, [r4, #0x14]
_08055FA2:
	adds r0, r4, #0x0
	adds r1, r6, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801A8A4
	adds r6, #0x20
	adds r4, #0x20
	movs r0, #0x01
	negs r0, r0
	add r8, r0
	mov r1, r8
	cmp r1, #0x00
	bge _08055F64
	mov r2, r9
	ldrh r0, [r2, #0x38]
	adds r0, #0x01
	strh r0, [r2, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x32
	bne _08055FD8
	movs r1, #0x87
	lsls r1, r1, #0x02
	add r1, r9
	movs r0, #0x01
	strb r0, [r1, #0x00]
_08055FD8:
	mov r7, r9
	movs r1, #0x38
	ldsh r0, [r7, r1]
	cmp r0, #0x46
	bgt _08055FEC
	movs r0, #0x01
	b _08055FEE
	.byte 0x00, 0x00
_08055FE8: .4byte 0x02039B84
_08055FEC:
	movs r0, #0x00
_08055FEE:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
