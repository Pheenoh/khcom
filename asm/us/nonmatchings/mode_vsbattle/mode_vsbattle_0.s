.syntax unified
	.align 2, 0
	.global mode_vsbattle_0
	.thumb
	.thumb_func
	.type mode_vsbattle_0, %function
mode_vsbattle_0: @ 0800C428
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r5, _0800C45C @ =0x02039B84
	movs r4, #0xE8
	lsls r4, r4, #0x01
	adds r0, r4, #0x0
	bl func_08000918
	str r0, [r5, #0x00]
	ldr r5, _0800C460 @ =0x02039B9C
	adds r0, r4, #0x0
	bl func_08000918
	str r0, [r5, #0x00]
	ldr r0, _0800C464 @ =0x02039828
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C46C
	ldr r0, _0800C468 @ =0x0203AAC0
	ldrh r0, [r0, #0x1E]
	bl func_08006578
	b _0800C474
_0800C45C: .4byte 0x02039B84
_0800C460: .4byte 0x02039B9C
_0800C464: .4byte 0x02039828
_0800C468: .4byte 0x0203AAC0
_0800C46C:
	ldr r0, _0800C544 @ =0x0203AA10
	ldrh r0, [r0, #0x1E]
	bl func_08006578
_0800C474:
	bl func_0801071C
	bl func_0801C068
	bl _0800C6B8
	bl func_08004F08
	ldr r7, _0800C548 @ =0x02039B84
	ldr r2, [r7, #0x00]
	movs r4, #0xE2
	lsls r4, r4, #0x01
	adds r1, r2, r4
	movs r0, #0x00
	mov r8, r0
	movs r0, #0x02
	strh r0, [r1, #0x00]
	movs r3, #0xE3
	lsls r3, r3, #0x01
	adds r1, r2, r3
	movs r0, #0x03
	strh r0, [r1, #0x00]
	movs r1, #0x00
	movs r2, #0x0C
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x1C
	movs r3, #0x0A
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x02
	bl func_080055C8
	movs r0, #0x02
	movs r1, #0x00
	bl func_080055C8
	movs r0, #0x03
	movs r1, #0x01
	bl func_08005654
	movs r0, #0x02
	movs r1, #0x00
	bl func_08005654
	ldr r0, [r7, #0x00]
	adds r0, #0x2C
	movs r1, #0x20
	bl func_08000E64
	ldr r0, [r7, #0x00]
	adds r0, #0x40
	movs r1, #0x20
	bl func_08000E64
	ldr r0, [r7, #0x00]
	adds r0, r0, r4
	ldrh r1, [r0, #0x00]
	movs r0, #0x80
	bl func_08012798
	bl func_0801227C
	cmp r6, #0x00
	bne _0800C55C
	ldr r1, _0800C54C @ =0xFFFFFF00
	mov r6, sp
	ldr r0, [sp, #0x004]
	ands r0, r1
	movs r5, #0x01
	orrs r0, r5
	str r0, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x000]
	ldr r0, [r7, #0x00]
	adds r0, #0x2C
	ldr r4, _0800C550 @ =0x09EDAE40
	adds r1, r4, #0x0
	mov r2, sp
	bl func_08000E14
	movs r0, #0x00
	strb r0, [r6, #0x04]
	str r5, [sp, #0x000]
	ldr r0, [r7, #0x00]
	adds r0, #0x2C
	adds r1, r4, #0x0
	mov r2, sp
	bl func_08000E14
	ldr r4, [r7, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0800C554 @ =0x00001000
	ldr r3, _0800C558 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	b _0800C58A
	.byte 0x00, 0x00
_0800C544: .4byte 0x0203AA10
_0800C548: .4byte 0x02039B84
_0800C54C: .4byte 0xFFFFFF00
_0800C550: .4byte 0x09EDAE40
_0800C554: .4byte 0x00001000
_0800C558: .4byte 0x00000000
_0800C55C:
	ldr r1, _0800C5D8 @ =0xFFFFFF00
	add r4, sp, #0x008
	ldr r0, [r4, #0x04]
	ands r0, r1
	str r0, [r4, #0x04]
	mov r0, r8
	str r0, [sp, #0x008]
	ldr r0, [r7, #0x00]
	adds r0, #0x2C
	ldr r5, _0800C5DC @ =0x09EDAE40
	adds r1, r5, #0x0
	adds r2, r4, #0x0
	bl func_08000E14
	movs r0, #0x01
	strb r0, [r4, #0x04]
	str r0, [sp, #0x008]
	ldr r0, [r7, #0x00]
	adds r0, #0x2C
	adds r1, r5, #0x0
	adds r2, r4, #0x0
	bl func_08000E14
_0800C58A:
	ldr r0, _0800C5E0 @ =0x02039B90
	ldrh r1, [r0, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r2, r3, #0x0
	subs r0, r2, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r1, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0800C5E4 @ =0x02039B88
	movs r4, #0x00
	ldsh r2, [r2, r4]
	ldr r3, _0800C5E8 @ =0x02039B8C
	movs r4, #0x00
	ldsh r3, [r3, r4]
	bl func_0801A920
	ldr r0, _0800C5EC @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _0800C5F0 @ =0x09EDAE70
	movs r2, #0x00
	bl func_08000E14
	ldr r1, _0800C5F4 @ =0x02039B98
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x3C
	bl func_08006120
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800C5D8: .4byte 0xFFFFFF00
_0800C5DC: .4byte 0x09EDAE40
_0800C5E0: .4byte 0x02039B90
_0800C5E4: .4byte 0x02039B88
_0800C5E8: .4byte 0x02039B8C
_0800C5EC: .4byte 0x02039B84
_0800C5F0: .4byte 0x09EDAE70
_0800C5F4: .4byte 0x02039B98
.syntax divided
