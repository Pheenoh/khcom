.syntax unified
	.align 2, 0
	.global func_08104BBC
	.thumb
	.thumb_func
	.type func_08104BBC, %function
func_08104BBC: @ 08104BBC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	ldr r4, _08104CA4 @ =0x02035C18
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_08104A84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	bl func_08104AA4
	ldr r1, _08104CA8 @ =0x02035CE4
	movs r3, #0x00
	ldsh r2, [r1, r3]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #0x00
	lsls r0, r0, #0x10
	str r0, [sp, #0x010]
	ldr r0, _08104CAC @ =0x08F70AB0
	str r0, [sp, #0x004]
_08104BF8:
	movs r2, #0x00
	lsls r1, r1, #0x10
	str r1, [sp, #0x008]
	asrs r1, r1, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r1
	mov r10, r0
_08104C06:
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	mov r9, r2
	mov r0, r10
	add r0, r9
	lsls r0, r0, #0x02
	mov r8, r0
	ldr r6, _08104CB0 @ =0x02035CE8
	add r6, r8
	ldr r0, [r6, #0x00]
	str r1, [sp, #0x00C]
	cmp r0, #0x00
	beq _08104C24
	bl func_08002C10
_08104C24:
	ldr r0, _08104CB4 @ =0x02035D18
	mov r3, r8
	adds r7, r3, r0
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	beq _08104C34
	bl func_080028C0
_08104C34:
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r3, r0, #0x0
	ldr r0, [sp, #0x010]
	cmp r3, r0
	bge _08104CC8
	ldr r2, [sp, #0x000]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	ldr r2, _08104CB8 @ =0x02035C10
	ldr r1, [r2, #0x00]
	movs r2, #0x34
	adds r5, r0, #0x0
	muls r5, r2
	adds r1, r5, r1
	ldrh r0, [r1, #0x02]
	adds r4, r0, #0x0
	muls r4, r2
	ldr r0, [sp, #0x004]
	adds r0, #0x18
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x20
	str r3, [sp, #0x014]
	bl func_08002A14
	str r0, [r6, #0x00]
	ldr r0, [sp, #0x004]
	adds r0, #0x14
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r7, #0x00]
	ldr r1, _08104CBC @ =0x02035D48
	add r1, r8
	ldr r0, _08104CC0 @ =0x08F70AC0
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	mov r1, r9
	add r1, r10
	ldr r2, _08104CC4 @ =0x02035D78
	adds r1, r1, r2
	ldr r2, _08104CB8 @ =0x02035C10
	ldr r0, [r2, #0x00]
	adds r5, r5, r0
	adds r5, #0x2E
	ldrb r0, [r5, #0x00]
	strb r0, [r1, #0x00]
	ldr r3, [sp, #0x014]
	b _08104CDE
	.byte 0x00, 0x00
_08104CA4: .4byte 0x02035C18
_08104CA8: .4byte 0x02035CE4
_08104CAC: .4byte 0x08F70AB0
_08104CB0: .4byte 0x02035CE8
_08104CB4: .4byte 0x02035D18
_08104CB8: .4byte 0x02035C10
_08104CBC: .4byte 0x02035D48
_08104CC0: .4byte 0x08F70AC0
_08104CC4: .4byte 0x02035D78
_08104CC8:
	movs r0, #0x00
	str r0, [r6, #0x00]
	str r0, [r7, #0x00]
	ldr r1, _08104D10 @ =0x02035D48
	add r1, r8
	str r0, [r1, #0x00]
	mov r1, r9
	add r1, r10
	ldr r2, _08104D14 @ =0x02035D78
	adds r1, r1, r2
	strb r0, [r1, #0x00]
_08104CDE:
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r3, r1
	lsrs r4, r0, #0x10
	ldr r2, [sp, #0x00C]
	adds r0, r2, r1
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	ble _08104C06
	ldr r3, [sp, #0x008]
	adds r0, r3, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _08104D00
	b _08104BF8
_08104D00:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08104D10: .4byte 0x02035D48
_08104D14: .4byte 0x02035D78
.syntax divided
