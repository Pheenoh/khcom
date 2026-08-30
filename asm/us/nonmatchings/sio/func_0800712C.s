.syntax unified
	.align 2, 0
	.global func_0800712C
	.thumb
	.thumb_func
	.type func_0800712C, %function
func_0800712C: @ 0800712C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0x0
	ldr r2, _080071A0 @ =0x0203406E
	ldr r1, _080071A4 @ =0x04000208
	ldrh r0, [r1, #0x00]
	strh r0, [r2, #0x00]
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _080071A8 @ =0x02039830
	ldr r3, _080071AC @ =0x0000011D
	adds r0, r1, r3
	ldrb r3, [r0, #0x00]
	mov r10, r2
	mov r12, r1
	cmp r3, #0x1F
	bhi _080071B8
	movs r0, #0x8E
	lsls r0, r0, #0x01
	add r0, r12
	ldrb r0, [r0, #0x00]
	adds r0, r3, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1F
	bls _0800716C
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0800716C:
	movs r3, #0x00
	ldr r1, _080071B0 @ =0x02034076
	mov r8, r1
	ldr r2, _080071B4 @ =0x020397D0
	mov r9, r2
	mov r2, r8
	lsls r5, r0, #0x01
	mov r7, r12
	adds r7, #0x1C
	movs r6, #0x00
_08007180:
	ldrh r0, [r2, #0x00]
	ldrh r1, [r4, #0x00]
	orrs r0, r1
	strh r0, [r2, #0x00]
	lsls r0, r3, #0x06
	adds r0, r5, r0
	adds r0, r0, r7
	strh r1, [r0, #0x00]
	strh r6, [r4, #0x00]
	adds r4, #0x02
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x03
	bls _08007180
	b _080071CA
_080071A0: .4byte 0x0203406E
_080071A4: .4byte 0x04000208
_080071A8: .4byte 0x02039830
_080071AC: .4byte 0x0000011D
_080071B0: .4byte 0x02034076
_080071B4: .4byte 0x020397D0
_080071B8:
	mov r3, r12
	ldrb r1, [r3, #0x14]
	movs r0, #0x01
	orrs r0, r1
	strb r0, [r3, #0x14]
	ldr r0, _08007200 @ =0x02034076
	mov r8, r0
	ldr r1, _08007204 @ =0x020397D0
	mov r9, r1
_080071CA:
	mov r2, r8
	ldrh r0, [r2, #0x00]
	cmp r0, #0x00
	beq _080071E0
	ldr r3, _08007208 @ =0x0000011D
	add r3, r12
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	movs r1, #0x00
	strb r0, [r3, #0x00]
	strh r1, [r2, #0x00]
_080071E0:
	ldr r0, _0800720C @ =0x04000208
	mov r3, r10
	ldrh r1, [r3, #0x00]
	strh r1, [r0, #0x00]
	ldr r0, _08007208 @ =0x0000011D
	add r0, r12
	ldrb r0, [r0, #0x00]
	mov r1, r9
	strb r0, [r1, #0x00]
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08007200: .4byte 0x02034076
_08007204: .4byte 0x020397D0
_08007208: .4byte 0x0000011D
_0800720C: .4byte 0x04000208
.syntax divided
