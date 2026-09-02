.syntax unified
	.align 2, 0
	.global func_0805FA8C
	.thumb
	.thumb_func
	.type func_0805FA8C, %function
func_0805FA8C: @ 0805FA8C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x008]
	lsls r4, r4, #0x10
	lsls r5, r5, #0x10
	bl GetBgCharBase
	mov r9, r0
	ldr r0, [sp, #0x008]
	bl GetBgScreenBase
	mov r10, r0
	movs r6, #0x00
	str r6, [sp, #0x000]
	lsrs r4, r4, #0x12
	movs r0, #0xA0
	lsls r0, r0, #0x13
	mov r8, r0
	orrs r4, r0
	mov r0, sp
	mov r1, r9
	adds r2, r4, #0x0
	bl CpuSet
	str r6, [sp, #0x004]
	add r0, sp, #0x004
	lsrs r5, r5, #0x12
	mov r1, r8
	orrs r5, r1
	mov r1, r10
	adds r2, r5, #0x0
	bl CpuSet
	ldr r4, _0805FB68 @ =0x02034A1C
	movs r0, #0xA5
	lsls r0, r0, #0x04
	bl EwramAlloc
	str r0, [r4, #0x00]
	ldr r0, _0805FB6C @ =0x02034A20
	strb r6, [r0, #0x00]
	movs r5, #0x00
	adds r7, r4, #0x0
	movs r4, #0x00
_0805FAF4:
	movs r2, #0x00
	lsls r6, r5, #0x05
	adds r0, r5, #0x1
	mov r8, r0
	adds r0, r6, r5
	lsls r3, r0, #0x02
_0805FB00:
	ldr r0, [r7, #0x00]
	adds r0, r3, r0
	lsls r1, r2, #0x01
	adds r0, r0, r1
	strh r4, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x3C
	bls _0805FB00
	ldr r0, [r7, #0x00]
	adds r1, r6, r5
	lsls r1, r1, #0x02
	adds r0, r1, r0
	adds r0, #0x7A
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, r1, r0
	adds r0, #0x7B
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	adds r0, r1, r0
	adds r0, #0x7C
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	adds r1, r1, r0
	adds r1, #0x7D
	strb r4, [r1, #0x00]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x13
	bls _0805FAF4
	movs r0, #0x00
	bl func_0805F7B0
	ldr r0, _0805FB70 @ =0x02034A21
	movs r1, #0x00
	strb r1, [r0, #0x00]
	ldr r0, _0805FB74 @ =0x02034A18
	strb r1, [r0, #0x00]
	ldr r0, [sp, #0x008]
	bl EnableBg
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0805FB68: .4byte 0x02034A1C
_0805FB6C: .4byte 0x02034A20
_0805FB70: .4byte 0x02034A21
_0805FB74: .4byte 0x02034A18
.syntax divided
