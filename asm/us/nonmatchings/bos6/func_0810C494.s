.syntax unified
	.align 2, 0
	.global func_0810C494
	.thumb
	.thumb_func
	.type func_0810C494, %function
func_0810C494: @ 0810C494
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r9, r3
	lsrs r1, r1, #0x10
	mov r8, r1
	lsls r0, r1, #0x11
	lsrs r5, r0, #0x10
	movs r1, #0x12
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	bge _0810C4C0
	movs r0, #0x01
	eors r5, r0
_0810C4C0:
	ldrb r0, [r6, #0x1C]
	cmp r0, #0x01
	bne _0810C4CA
	movs r0, #0x01
	eors r5, r0
_0810C4CA:
	ldr r0, _0810C4E0 @ =0x09A4D14C
	add r0, r8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0810C4E4
	cmp r0, #0x01
	beq _0810C510
	adds r4, r6, #0x0
	adds r4, #0x2C
	b _0810C534
	.byte 0x00, 0x00
_0810C4E0: .4byte 0x09A4D14C
_0810C4E4:
	ldr r0, [r6, #0x28]
	ldr r1, _0810C504 @ =0x09C4B012
	bl func_08002A10
	adds r4, r6, #0x0
	adds r4, #0x2C
	ldr r3, _0810C508 @ =0x09EFAD3C
	ldr r0, _0810C50C @ =0x09EFABB0
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r7, #0x0
	bl func_08005974
	b _0810C534
	.byte 0x00, 0x00
_0810C504: .4byte 0x09C4B012
_0810C508: .4byte 0x09EFAD3C
_0810C50C: .4byte 0x09EFABB0
_0810C510:
	adds r0, r5, #0x0
	subs r0, #0x0E
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, [r6, #0x28]
	ldr r1, _0810C548 @ =0x09C51CBC
	bl func_08002A10
	adds r4, r6, #0x0
	adds r4, #0x2C
	ldr r3, _0810C54C @ =0x09EFADBC
	ldr r0, _0810C550 @ =0x09EFAD74
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r7, #0x0
	bl func_08005974
_0810C534:
	mov r0, r9
	cmp r0, #0x01
	bne _0810C554
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r7, #0x0
	bl AnimChange
	b _0810C564
	.byte 0x00, 0x00
_0810C548: .4byte 0x09C51CBC
_0810C54C: .4byte 0x09EFADBC
_0810C550: .4byte 0x09EFAD74
_0810C554:
	adds r0, r4, #0x0
	bl func_08005B64
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r7, #0x0
	bl AnimStart
_0810C564:
	mov r1, r8
	strh r1, [r6, #0x1E]
	strh r7, [r6, #0x20]
	ldrh r0, [r6, #0x12]
	strh r0, [r6, #0x22]
	add sp, #0x004
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
