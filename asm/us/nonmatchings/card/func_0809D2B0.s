.syntax unified
	.align 2, 0
	.global func_0809D2B0
	.thumb
	.thumb_func
	.type func_0809D2B0, %function
func_0809D2B0: @ 0809D2B0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r9, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x010]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x014]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r10, r2
	ldr r6, _0809D3E4 @ =0x02034AD8
	ldrb r0, [r6, #0x00]
	cmp r0, #0x1F
	bhi _0809D3D2
	mov r0, r9
	bl func_0809D280
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x20
	bls _0809D2E8
	movs r5, #0x20
_0809D2E8:
	movs r4, #0x00
	mov r8, r6
	ldr r7, _0809D3E8 @ =0x02034AD4
	cmp r4, r5
	bcs _0809D336
	mov r0, r10
	lsls r0, r0, #0x0C
	mov r12, r0
_0809D2F8:
	ldr r2, _0809D3E4 @ =0x02034AD8
	ldrb r1, [r2, #0x00]
	ldr r3, [r7, #0x00]
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r3
	lsls r2, r4, #0x01
	adds r0, #0x04
	adds r0, r0, r2
	mov r6, r9
	adds r1, r6, r4
	ldrb r1, [r1, #0x00]
	strh r1, [r0, #0x00]
	ldr r1, _0809D3E4 @ =0x02034AD8
	ldrb r0, [r1, #0x00]
	lsls r1, r0, #0x04
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r1, r1, r3
	adds r1, #0x04
	adds r1, r1, r2
	ldrh r2, [r1, #0x00]
	mov r0, r12
	orrs r0, r2
	strh r0, [r1, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	bcc _0809D2F8
_0809D336:
	mov r2, r8
	ldrb r1, [r2, #0x00]
	ldr r2, [r7, #0x00]
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	mov r6, sp
	ldrb r6, [r6, #0x10]
	strb r6, [r0, #0x01]
	mov r0, r8
	ldrb r1, [r0, #0x00]
	ldr r2, [r7, #0x00]
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r0, #0x02]
	mov r2, r8
	ldrb r1, [r2, #0x00]
	ldr r2, [r7, #0x00]
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	mov r6, r10
	strb r6, [r0, #0x03]
	mov r0, r8
	ldrb r1, [r0, #0x00]
	ldr r2, [r7, #0x00]
	lsls r0, r1, #0x04
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	strb r5, [r0, #0x00]
	ldr r1, _0809D3EC @ =0x02034AD9
	ldrb r0, [r1, #0x00]
	bl GetBgScreenBase
	adds r1, r0, #0x0
	mov r2, r8
	ldrb r0, [r2, #0x00]
	lsls r2, r0, #0x04
	adds r2, r2, r0
	lsls r2, r2, #0x02
	ldr r4, [r7, #0x00]
	adds r2, r4, r2
	adds r0, r2, #0x4
	ldrb r2, [r2, #0x01]
	str r2, [sp, #0x000]
	mov r6, r8
	ldrb r3, [r6, #0x00]
	lsls r2, r3, #0x04
	adds r2, r2, r3
	lsls r2, r2, #0x02
	adds r2, r2, r4
	ldrb r2, [r2, #0x02]
	str r2, [sp, #0x004]
	ldrb r3, [r6, #0x00]
	lsls r2, r3, #0x04
	adds r2, r2, r3
	lsls r2, r2, #0x02
	adds r2, r2, r4
	ldrb r2, [r2, #0x00]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	str r2, [sp, #0x008]
	movs r2, #0x01
	str r2, [sp, #0x00C]
	movs r2, #0x00
	movs r3, #0x00
	bl func_0800448C
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
_0809D3D2:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0809D3E4: .4byte 0x02034AD8
_0809D3E8: .4byte 0x02034AD4
_0809D3EC: .4byte 0x02034AD9
.syntax divided
