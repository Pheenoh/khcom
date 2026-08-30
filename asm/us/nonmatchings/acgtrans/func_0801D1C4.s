.syntax unified
	.align 2, 0
	.global func_0801D1C4
	.thumb
	.thumb_func
	.type func_0801D1C4, %function
func_0801D1C4: @ 0801D1C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	mov r8, r1
	adds r4, r2, #0x0
	adds r5, r3, #0x0
	ldr r6, [sp, #0x028]
	ldr r0, [sp, #0x02C]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	str r0, [sp, #0x000]
	mov r0, r8
	bl func_08005130
	lsls r4, r4, #0x05
	adds r0, r0, r4
	str r0, [sp, #0x004]
	mov r0, sp
	lsls r5, r5, #0x05
	strh r5, [r0, #0x08]
	strh r6, [r0, #0x0A]
	mov r0, r8
	str r0, [sp, #0x00C]
	mov r0, sp
	ldrh r0, [r0, #0x0A]
	cmp r0, #0x00
	bne _0801D20C
	mov r1, sp
	movs r0, #0x01
	strh r0, [r1, #0x0A]
_0801D20C:
	ldr r1, _0801D224 @ =0x09EDADF8
	adds r0, r7, #0x0
	mov r2, sp
	bl func_08000E14
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801D224: .4byte 0x09EDADF8
.syntax divided
