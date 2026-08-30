.syntax unified
	.align 2, 0
	.global func_0800C778
	.thumb
	.thumb_func
	.type func_0800C778, %function
func_0800C778: @ 0800C778
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r7, r5, #0x0
	adds r7, #0x3C
	adds r1, #0x1C
	ldr r4, [r2, #0x00]
	ldr r3, [r2, #0x04]
	ldr r0, [r2, #0x08]
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r2, r4, #0x0
	bl func_0801B37C
	ldrh r0, [r6, #0x12]
	movs r2, #0x85
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r4, #0x00
	strh r0, [r1, #0x00]
	ldrh r1, [r6, #0x14]
	adds r2, #0x02
	adds r0, r5, r2
	strh r1, [r0, #0x00]
	ldrh r0, [r6, #0x16]
	adds r2, #0x02
	adds r1, r5, r2
	strh r0, [r1, #0x00]
	ldrh r0, [r6, #0x18]
	adds r1, r5, #0x0
	adds r1, #0xEE
	strh r0, [r1, #0x00]
	ldr r0, _0800C894 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x04]
	ldr r0, [r7, #0x04]
	cmp r1, r0
	bge _0800C7DA
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	orrs r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
_0800C7DA:
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ldr r2, _0800C898 @ =0x00000300
	ldr r3, _0800C89C @ =0x00000000
	orrs r0, r2
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldr r1, _0800C8A0 @ =0x09EDA4EC
	ldr r0, [r5, #0x3C]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	mov r8, r0
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r6, [r0, #0x00]
	mov r2, r8
	lsls r0, r2, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080028F8
	str r0, [r5, #0x00]
	ldr r0, [r6, #0x00]
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	ldr r0, _0800C8A4 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x08]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r4, [r0, #0x00]
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x0B
	str r0, [r1, #0x00]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	strh r4, [r0, #0x00]
	adds r2, #0x0A
	adds r0, r5, r2
	strh r4, [r0, #0x00]
	adds r1, #0x04
	adds r0, r5, r1
	strh r4, [r0, #0x00]
	adds r2, #0x04
	adds r1, r5, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r5, r0
	movs r0, #0x00
	strb r0, [r1, #0x00]
	adds r2, #0x0A
	adds r1, r5, r2
	ldr r0, [r6, #0x08]
	str r0, [r1, #0x00]
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r5, r1
	str r4, [r0, #0x00]
	subs r2, #0x20
	adds r0, r5, r2
	str r4, [r0, #0x00]
	subs r1, #0x20
	adds r0, r5, r1
	str r4, [r0, #0x00]
	adds r2, #0x1E
	adds r0, r5, r2
	strh r4, [r0, #0x00]
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x0A
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800C8A8
	movs r0, #0xB6
	lsls r0, r0, #0x01
	adds r1, r5, r0
	subs r0, #0x53
	b _0800C8B2
_0800C894: .4byte 0x02039B84
_0800C898: .4byte 0x00000300
_0800C89C: .4byte 0x00000000
_0800C8A0: .4byte 0x09EDA4EC
_0800C8A4: .4byte 0x08F69BC4
_0800C8A8:
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r1, r5, r2
	movs r0, #0x80
	lsls r0, r0, #0x01
_0800C8B2:
	str r0, [r1, #0x00]
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x00
	str r1, [r0, #0x00]
	movs r2, #0xBA
	lsls r2, r2, #0x01
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r5, r2
	str r1, [r0, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08005968
	movs r1, #0xAE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x04]
	ldr r1, [r5, #0x00]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r5, #0x0C]
	adds r4, #0x18
	adds r0, r4, #0x0
	movs r1, #0x03
	bl func_08000E64
	ldrh r1, [r6, #0x1A]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0800C916
	ldr r1, _0800C93C @ =0x09EDAE88
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
_0800C916:
	ldr r1, _0800C940 @ =0x09EDB3F8
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	ldrh r1, [r6, #0x1A]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0800C944
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r0, r5, r2
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x00]
	adds r2, #0x04
	b _0800C952
	.byte 0x00, 0x00
_0800C93C: .4byte 0x09EDAE88
_0800C940: .4byte 0x09EDB3F8
_0800C944:
	movs r1, #0xBE
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0x80
	str r1, [r0, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x01
_0800C952:
	adds r0, r5, r2
	str r1, [r0, #0x00]
	ldr r0, _0800C97C @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xEC
	ldrh r0, [r1, #0x00]
	add r0, r8
	strh r0, [r1, #0x00]
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r1, r2, r0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800C97C: .4byte 0x02039B84
.syntax divided
