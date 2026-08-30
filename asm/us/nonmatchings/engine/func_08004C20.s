.syntax unified
	.align 2, 0
	.global func_08004C20
	.thumb
	.thumb_func
	.type func_08004C20, %function
func_08004C20: @ 08004C20
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x030
	str r2, [sp, #0x018]
	str r3, [sp, #0x01C]
	ldr r2, [sp, #0x050]
	ldr r3, [sp, #0x054]
	ldr r4, [sp, #0x058]
	ldr r5, [sp, #0x05C]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x010]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x014]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x020]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x024]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	movs r1, #0xFF
	ands r0, r1
	lsrs r0, r0, #0x03
	str r0, [sp, #0x028]
	ldr r0, [sp, #0x014]
	ands r0, r1
	lsrs r7, r0, #0x03
	movs r0, #0x20
	ldr r1, [sp, #0x028]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	blt _08004C7C
	adds r6, r4, #0x0
	movs r0, #0x00
	b _08004C82
_08004C7C:
	subs r0, r4, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08004C82:
	mov r10, r0
	movs r0, #0x20
	subs r0, r0, r7
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r5
	blt _08004C9A
	adds r4, r5, #0x0
	movs r1, #0x00
	str r1, [sp, #0x02C]
	b _08004CA2
_08004C9A:
	subs r0, r5, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x02C]
_08004CA2:
	ldr r0, [sp, #0x018]
	ldr r1, [sp, #0x010]
	ldr r2, [sp, #0x014]
	bl func_08004BD8
	ldr r1, [sp, #0x020]
	str r1, [sp, #0x000]
	ldr r1, [sp, #0x024]
	str r1, [sp, #0x004]
	lsls r6, r6, #0x18
	asrs r6, r6, #0x18
	str r6, [sp, #0x008]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	str r4, [sp, #0x00C]
	ldr r1, [sp, #0x01C]
	ldr r2, [sp, #0x028]
	adds r3, r7, #0x0
	bl func_0800448C
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r8, r0
	ldr r1, [sp, #0x010]
	add r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r9, r1
	ldr r0, [sp, #0x018]
	ldr r2, [sp, #0x014]
	bl func_08004BD8
	ldr r5, [sp, #0x028]
	subs r5, #0x20
	ldr r1, [sp, #0x020]
	subs r5, r1, r5
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r5, [sp, #0x000]
	ldr r1, [sp, #0x024]
	str r1, [sp, #0x004]
	mov r1, r10
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov r10, r1
	str r1, [sp, #0x008]
	str r4, [sp, #0x00C]
	ldr r1, [sp, #0x01C]
	movs r2, #0x00
	adds r3, r7, #0x0
	bl func_0800448C
	ldr r0, [sp, #0x014]
	add r8, r0
	mov r1, r8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r0, [sp, #0x018]
	ldr r1, [sp, #0x010]
	mov r2, r8
	bl func_08004BD8
	ldr r1, [sp, #0x020]
	str r1, [sp, #0x000]
	adds r4, r7, #0x0
	subs r4, #0x20
	ldr r1, [sp, #0x024]
	subs r4, r1, r4
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r1, [sp, #0x02C]
	lsls r6, r1, #0x18
	asrs r6, r6, #0x18
	str r6, [sp, #0x00C]
	ldr r1, [sp, #0x01C]
	ldr r2, [sp, #0x028]
	movs r3, #0x00
	bl func_0800448C
	ldr r0, [sp, #0x018]
	mov r1, r9
	mov r2, r8
	bl func_08004BD8
	str r5, [sp, #0x000]
	str r4, [sp, #0x004]
	mov r1, r10
	str r1, [sp, #0x008]
	str r6, [sp, #0x00C]
	ldr r1, [sp, #0x01C]
	movs r2, #0x00
	movs r3, #0x00
	bl func_0800448C
	add sp, #0x030
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
