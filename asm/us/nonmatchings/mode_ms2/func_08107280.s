.syntax unified
	.align 2, 0
	.global func_08107280
	.thumb
	.thumb_func
	.type func_08107280, %function
func_08107280: @ 08107280
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	ldr r4, _08107374 @ =0x02035E2E
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_0810712C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	movs r2, #0x00
	ldsh r0, [r4, r2]
	bl func_08107220
	ldr r1, _08107378 @ =0x02035E9C
	movs r3, #0x00
	ldsh r2, [r1, r3]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #0x00
	lsls r0, r0, #0x10
	str r0, [sp, #0x010]
	ldr r0, _0810737C @ =0x09EE4C80
	str r0, [sp, #0x004]
_081072BC:
	movs r2, #0x00
	lsls r1, r1, #0x10
	str r1, [sp, #0x008]
	asrs r1, r1, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r1
	mov r10, r0
_081072CA:
	lsls r1, r2, #0x10
	asrs r2, r1, #0x10
	mov r9, r2
	mov r0, r10
	add r0, r9
	lsls r0, r0, #0x02
	mov r8, r0
	ldr r6, _08107380 @ =0x02035EA0
	add r6, r8
	ldr r0, [r6, #0x00]
	str r1, [sp, #0x00C]
	cmp r0, #0x00
	beq _081072E8
	bl func_08002C10
_081072E8:
	ldr r0, _08107384 @ =0x02035ED0
	mov r3, r8
	adds r7, r3, r0
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	beq _081072F8
	bl func_080028C0
_081072F8:
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	adds r3, r0, #0x0
	ldr r4, [sp, #0x010]
	cmp r3, r4
	bge _08107398
	ldr r2, [sp, #0x000]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	ldr r4, _08107388 @ =0x02035E28
	ldr r1, [r4, #0x00]
	lsls r5, r0, #0x03
	subs r5, r5, r0
	lsls r5, r5, #0x02
	adds r1, r5, r1
	ldrh r0, [r1, #0x02]
	lsls r4, r0, #0x02
	adds r4, r4, r0
	lsls r4, r4, #0x03
	ldr r0, [sp, #0x004]
	adds r0, #0x10
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x20
	str r3, [sp, #0x014]
	bl func_08002A14
	str r0, [r6, #0x00]
	ldr r0, [sp, #0x004]
	adds r0, #0x0C
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	ldr r2, [sp, #0x004]
	adds r1, r4, r2
	ldrh r1, [r1, #0x1C]
	bl func_080026A4
	str r0, [r7, #0x00]
	ldr r1, _0810738C @ =0x02035F00
	add r1, r8
	ldr r0, _08107390 @ =0x09EE4C94
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r0, r9
	add r0, r10
	ldr r2, _08107394 @ =0x02035F30
	adds r1, r0, r2
	movs r2, #0x00
	ldr r4, _08107388 @ =0x02035E28
	ldr r0, [r4, #0x00]
	adds r5, r5, r0
	ldrh r0, [r5, #0x04]
	ldr r3, [sp, #0x014]
	cmp r0, #0x03
	bne _0810736E
	movs r2, #0x01
_0810736E:
	strb r2, [r1, #0x00]
	b _081073AE
	.byte 0x00, 0x00
_08107374: .4byte 0x02035E2E
_08107378: .4byte 0x02035E9C
_0810737C: .4byte 0x09EE4C80
_08107380: .4byte 0x02035EA0
_08107384: .4byte 0x02035ED0
_08107388: .4byte 0x02035E28
_0810738C: .4byte 0x02035F00
_08107390: .4byte 0x09EE4C94
_08107394: .4byte 0x02035F30
_08107398:
	movs r0, #0x00
	str r0, [r6, #0x00]
	str r0, [r7, #0x00]
	ldr r1, _081073E8 @ =0x02035F00
	add r1, r8
	str r0, [r1, #0x00]
	mov r1, r9
	add r1, r10
	ldr r2, _081073EC @ =0x02035F30
	adds r1, r1, r2
	strb r0, [r1, #0x00]
_081073AE:
	movs r4, #0x80
	lsls r4, r4, #0x09
	adds r0, r3, r4
	lsrs r4, r0, #0x10
	ldr r1, [sp, #0x00C]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	ble _081072CA
	ldr r3, [sp, #0x008]
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r3, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _081073D8
	b _081072BC
_081073D8:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_081073E8: .4byte 0x02035F00
_081073EC: .4byte 0x02035F30
.syntax divided
