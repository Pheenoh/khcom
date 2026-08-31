.syntax unified
	.align 2, 0
	.global func_08007A10
	.thumb
	.thumb_func
	.type func_08007A10, %function
func_08007A10: @ 08007A10
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	str r0, [sp, #0x000]
	mov r9, r1
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	str r0, [sp, #0x004]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	movs r0, #0xFB
	lsls r0, r0, #0x18
	add r0, r9
	asrs r7, r0, #0x01
	lsrs r2, r2, #0x11
	mov r12, r2
	movs r0, #0x1F
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r5, #0x00
	cmp r5, r12
	bcs _08007AB8
	movs r1, #0x1F
	mov r10, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
_08007A4E:
	lsls r0, r5, #0x01
	ldr r1, [sp, #0x000]
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	movs r4, #0x1F
	movs r2, #0xF8
	lsls r2, r2, #0x02
	ands r2, r0
	lsrs r2, r2, #0x05
	movs r3, #0xF8
	lsls r3, r3, #0x07
	ands r3, r0
	lsrs r3, r3, #0x0A
	ands r4, r0
	mov r0, r10
	ands r2, r0
	adds r0, r4, r2
	mov r1, r10
	ands r3, r1
	adds r0, r0, r3
	asrs r0, r0, #0x02
	mov r1, r8
	muls r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	muls r4, r6
	adds r4, r1, r4
	lsls r4, r4, #0x0B
	muls r2, r6
	adds r2, r1, r2
	lsls r2, r2, #0x0B
	adds r0, r3, #0x0
	muls r0, r6
	adds r1, r1, r0
	lsls r1, r1, #0x0B
	ldr r0, _08007AD8 @ =0x0300756C
	ldr r3, [r0, #0x00]
	adds r0, r5, r7
	lsls r0, r0, #0x01
	adds r3, r3, r0
	asrs r1, r1, #0x10
	lsls r1, r1, #0x0A
	asrs r2, r2, #0x10
	lsls r2, r2, #0x05
	orrs r1, r2
	asrs r4, r4, #0x10
	orrs r4, r1
	strh r4, [r3, #0x00]
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, r12
	bcc _08007A4E
_08007AB8:
	cmp r7, #0x00
	bne _08007ADC
	ldr r0, _08007AD8 @ =0x0300756C
	ldr r0, [r0, #0x00]
	adds r0, #0x02
	mov r1, r9
	adds r1, #0x02
	ldr r2, [sp, #0x004]
	subs r2, #0x02
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl RequestDma3Copy
	movs r4, #0x00
	b _08007AEC
	.byte 0x00, 0x00
_08007AD8: .4byte 0x0300756C
_08007ADC:
	ldr r0, _08007B04 @ =0x0300756C
	lsls r4, r7, #0x01
	ldr r0, [r0, #0x00]
	adds r0, r0, r4
	mov r1, r9
	ldr r2, [sp, #0x004]
	bl RequestDma3Copy
_08007AEC:
	ldr r0, _08007B04 @ =0x0300756C
	ldr r0, [r0, #0x00]
	adds r0, r0, r4
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08007B04: .4byte 0x0300756C
.syntax divided
