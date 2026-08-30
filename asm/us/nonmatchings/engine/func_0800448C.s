.syntax unified
	.align 2, 0
	.global func_0800448C
	.thumb
	.thumb_func
	.type func_0800448C, %function
func_0800448C: @ 0800448C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r6, r0, #0x0
	str r1, [sp, #0x008]
	ldr r0, [sp, #0x02C]
	ldr r1, [sp, #0x030]
	ldr r4, [sp, #0x034]
	ldr r5, [sp, #0x038]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r12, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r9, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x000]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x004]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r8, r4
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r10, r5
	ldr r5, _080044EC @ =0x03007574
	ldr r3, [r5, #0x00]
	ldr r4, _080044F0 @ =0x000010A2
	adds r2, r3, r4
	ldrh r0, [r2, #0x00]
	cmp r0, #0x3F
	bhi _080044E6
	mov r1, r8
	lsls r0, r1, #0x18
	cmp r0, #0x00
	ble _080044E6
	mov r7, r10
	lsls r0, r7, #0x18
	cmp r0, #0x00
	bgt _080044F4
_080044E6:
	movs r0, #0x00
	b _0800458A
	.byte 0x00, 0x00
_080044EC: .4byte 0x03007574
_080044F0: .4byte 0x000010A2
_080044F4:
	ldrh r1, [r2, #0x00]
	lsls r1, r1, #0x04
	movs r7, #0xC0
	lsls r7, r7, #0x04
	adds r0, r3, r7
	adds r0, r0, r1
	str r6, [r0, #0x00]
	ldrh r1, [r2, #0x00]
	lsls r1, r1, #0x04
	ldr r6, _0800459C @ =0x00000C04
	adds r0, r3, r6
	adds r0, r0, r1
	ldr r7, [sp, #0x008]
	str r7, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x04
	adds r0, r3, r0
	ldr r1, _080045A0 @ =0x00000C08
	adds r0, r0, r1
	mov r2, r12
	strb r2, [r0, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r1, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r6, #0x05
	adds r1, r1, r6
	mov r7, r9
	strb r7, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r1, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x04
	adds r1, r1, r0
	ldr r0, _080045A4 @ =0x00000C0A
	adds r1, r1, r0
	mov r2, sp
	ldrb r2, [r2, #0x00]
	strb r2, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r1, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r6, #0x02
	adds r1, r1, r6
	mov r7, sp
	ldrb r7, [r7, #0x04]
	strb r7, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r1, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x04
	adds r1, r1, r0
	ldr r0, _080045A8 @ =0x00000C0C
	adds r1, r1, r0
	mov r2, r8
	strb r2, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r0, r1, r4
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r6, #0x02
	adds r1, r1, r6
	mov r7, r10
	strb r7, [r1, #0x00]
	ldr r1, [r5, #0x00]
	adds r1, r1, r4
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	ldrh r2, [r1, #0x00]
	strh r0, [r1, #0x00]
	movs r0, #0x01
_0800458A:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0800459C: .4byte 0x00000C04
_080045A0: .4byte 0x00000C08
_080045A4: .4byte 0x00000C0A
_080045A8: .4byte 0x00000C0C
.syntax divided
