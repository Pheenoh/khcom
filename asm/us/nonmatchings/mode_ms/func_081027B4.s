.syntax unified
	.align 2, 0
	.global func_081027B4
	.thumb
	.thumb_func
	.type func_081027B4, %function
func_081027B4: @ 081027B4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	movs r1, #0x00
	str r1, [sp, #0x000]
	ldr r7, _081028E0 @ =0x02035B08
	ldr r2, _081028E4 @ =0x0000FFFF
	adds r4, r2, #0x0
	lsls r0, r0, #0x10
	str r0, [sp, #0x008]
	ldr r5, _081028E8 @ =0x02035B18
_081027D0:
	ldr r3, [sp, #0x000]
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r7
	ldrh r0, [r1, #0x00]
	orrs r0, r4
	strh r0, [r1, #0x00]
	movs r6, #0x00
	lsls r3, r2, #0x04
_081027E4:
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x02
	adds r1, r1, r3
	adds r1, r1, r5
	ldrh r0, [r1, #0x00]
	orrs r0, r4
	strh r0, [r1, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x03
	ble _081027E4
	ldr r1, [sp, #0x000]
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r3, r0, #0x10
	str r3, [sp, #0x000]
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _081027D0
	movs r7, #0x00
	str r7, [sp, #0x004]
	movs r0, #0x00
	str r0, [sp, #0x000]
_0810281C:
	movs r3, #0x00
	movs r6, #0x00
	ldr r1, [sp, #0x000]
	lsls r1, r1, #0x10
	str r1, [sp, #0x010]
	ldr r2, [sp, #0x004]
	lsls r2, r2, #0x10
	mov r10, r2
	mov r9, r1
	asrs r1, r1, #0x0D
	mov r8, r1
_08102832:
	lsls r4, r6, #0x10
	asrs r0, r4, #0x0F
	add r0, r8
	ldr r7, [sp, #0x008]
	asrs r1, r7, #0x0B
	adds r0, r0, r1
	ldr r1, _081028EC @ =0x099935C0
	adds r0, r0, r1
	ldrh r5, [r0, #0x00]
	ldr r0, _081028F0 @ =0x0203C590
	ldrb r0, [r0, #0x06]
	lsrs r2, r4, #0x10
	mov r7, r9
	lsrs r1, r7, #0x10
	str r3, [sp, #0x00C]
	bl func_081026C4
	lsls r0, r0, #0x18
	ldr r3, [sp, #0x00C]
	cmp r0, #0x00
	bne _08102880
	lsls r0, r5, #0x10
	cmp r0, #0x00
	blt _08102880
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #0x02
	mov r3, r10
	asrs r1, r3, #0x0C
	adds r0, r0, r1
	ldr r7, _081028E8 @ =0x02035B18
	adds r1, r0, r7
	strh r6, [r1, #0x00]
	ldr r1, _081028F4 @ =0x02035B1A
	adds r0, r0, r1
	strh r5, [r0, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
_08102880:
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r4, r2
	lsrs r6, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _08102832
	lsls r0, r3, #0x10
	cmp r0, #0x00
	ble _081028AE
	ldr r2, _081028E0 @ =0x02035B08
	ldr r3, [sp, #0x004]
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r2
	mov r7, sp
	ldrh r7, [r7, #0x00]
	strh r7, [r0, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x004]
_081028AE:
	ldr r1, [sp, #0x010]
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r1, r2
	lsrs r3, r0, #0x10
	str r3, [sp, #0x000]
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _0810281C
	movs r1, #0x00
	ldr r7, [sp, #0x004]
	lsls r0, r7, #0x10
	cmp r0, #0x00
	ble _081028CC
	movs r1, #0x01
_081028CC:
	adds r0, r1, #0x0
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_081028E0: .4byte 0x02035B08
_081028E4: .4byte 0x0000FFFF
_081028E8: .4byte 0x02035B18
_081028EC: .4byte 0x099935C0
_081028F0: .4byte 0x0203C590
_081028F4: .4byte 0x02035B1A
.syntax divided
