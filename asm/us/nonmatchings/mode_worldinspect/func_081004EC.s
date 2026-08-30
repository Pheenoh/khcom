.syntax unified
	.align 2, 0
	.global func_081004EC
	.thumb
	.thumb_func
	.type func_081004EC, %function
func_081004EC: @ 081004EC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r3, #0x0
	ldr r3, [sp, #0x020]
	ldr r4, [sp, #0x024]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r0, #0x1C
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x0B
	adds r3, r3, r4
	lsls r3, r3, #0x01
	adds r5, r5, r3
	movs r4, #0x00
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	cmp r4, r2
	bge _0810056A
	lsls r1, r1, #0x10
	mov r12, r1
	asrs r7, r1, #0x10
	movs r0, #0x20
	subs r0, r0, r7
	lsls r0, r0, #0x01
	mov r10, r0
	mov r9, r2
_0810052E:
	movs r3, #0x00
	lsls r2, r4, #0x10
	cmp r3, r7
	bge _0810055A
	ldr r6, _08100578 @ =0x00000FFF
	mov r0, r12
	asrs r4, r0, #0x10
_0810053C:
	ldrh r0, [r5, #0x00]
	adds r1, r6, #0x0
	ands r1, r0
	mov r0, r8
	orrs r1, r0
	strh r1, [r5, #0x00]
	adds r5, #0x02
	lsls r0, r3, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r4
	blt _0810053C
_0810055A:
	add r5, r10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r2, r1
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r9
	blt _0810052E
_0810056A:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08100578: .4byte 0x00000FFF
.syntax divided
