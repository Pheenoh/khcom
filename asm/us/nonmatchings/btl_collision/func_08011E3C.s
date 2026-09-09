.syntax unified
	.align 2, 0
	.global func_08011E3C
	.thumb
	.thumb_func
	.type func_08011E3C, %function
func_08011E3C: @ 08011E3C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r8, r0
	mov r9, r1
	mov r10, r2
	ldr r0, [sp, #0x038]
	ldr r1, [sp, #0x03C]
	lsls r3, r3, #0x10
	lsrs r7, r3, #0x10
	str r7, [sp, #0x00C]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r6, [sp, #0x010]
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	str r5, [sp, #0x014]
	ldr r2, _08011EC0 @ =0x02039B84
	ldr r0, [r2, #0x00]
	adds r0, #0xB4
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r2, [r2, #0x00]
	mov r12, r2
	mov r0, r12
	adds r0, #0xB8
	mov r1, r8
	str r1, [r0, #0x00]
	adds r0, #0x04
	mov r1, r9
	str r1, [r0, #0x00]
	adds r0, #0x04
	mov r1, r10
	str r1, [r0, #0x00]
	adds r0, #0x04
	strh r7, [r0, #0x00]
	adds r0, #0x02
	strh r6, [r0, #0x00]
	adds r0, #0x02
	strh r5, [r0, #0x00]
	mov r0, r12
	ldr r3, [r0, #0x68]
	ldr r4, [r0, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08011ECE
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08011EC8
	ldr r0, _08011EC4 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	b _08011F24
_08011EC0: .4byte 0x02039B84
_08011EC4: .4byte 0x02039B9C
_08011EC8:
	mov r1, r12
	ldr r4, [r1, #0x7C]
	b _08011F26
_08011ECE:
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08011F22
	mov r0, r12
	adds r0, #0x80
	bl ListPoolFirst
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08011F54
	lsls r0, r7, #0x10
	asrs r7, r0, #0x10
	lsls r0, r6, #0x10
	asrs r6, r0, #0x10
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
_08011EFA:
	str r7, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	adds r0, r4, #0x0
	mov r1, r8
	mov r2, r9
	mov r3, r10
	bl func_08011270
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08011F50
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl ListPoolNext
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08011EFA
	b _08011F54
_08011F22:
	mov r0, r12
_08011F24:
	ldr r4, [r0, #0x7C]
_08011F26:
	ldr r1, [sp, #0x00C]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x000]
	ldr r1, [sp, #0x010]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x004]
	ldr r1, [sp, #0x014]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0x008]
	adds r0, r4, #0x0
	mov r1, r8
	mov r2, r9
	mov r3, r10
	bl func_08011270
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08011F54
_08011F50:
	movs r0, #0x01
	b _08011F56
_08011F54:
	movs r0, #0x00
_08011F56:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
