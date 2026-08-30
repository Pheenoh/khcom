.syntax unified
	.align 2, 0
	.global task_frd_beast_0
	.thumb
	.thumb_func
	.type task_frd_beast_0, %function
task_frd_beast_0: @ 08049830
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x20
	movs r0, #0xBA
	bl func_0811FE70
	mov r0, r8
	ldrb r1, [r0, #0x02]
	cmp r1, #0x00
	beq _08049888
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r5, _0804987C @ =0x02039B84
	ldr r4, [r5, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08049880 @ =0x00200000
	ldr r3, _08049884 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	ldr r3, [r4, #0x78]
	b _080498B8
_0804987C: .4byte 0x02039B84
_08049880: .4byte 0x00200000
_08049884: .4byte 0x00000000
_08049888:
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r1, [r0, #0x00]
	ldr r0, _080498EC @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080498F0 @ =0x00200000
	ldr r3, _080498F4 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r0, [r4, #0x7C]
	str r0, [r6, #0x14]
	ldr r1, _080498F8 @ =0x02039B84
	ldr r0, [r1, #0x00]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r6, #0x18]
	ldr r3, [r4, #0x78]
	adds r5, r1, #0x0
_080498B8:
	mov r1, r8
	ldrh r0, [r1, #0x00]
	ldr r1, _080498FC @ =0x0000014D
	adds r2, r6, r1
	movs r1, #0x00
	strb r0, [r2, #0x00]
	movs r2, #0xA7
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r1, [r0, #0x00]
	adds r2, #0x0A
	adds r0, r6, r2
	str r1, [r0, #0x00]
	cmp r3, #0x00
	beq _08049900
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, [r3, #0x04]
	str r0, [r1, #0x00]
	subs r2, #0x04
	adds r1, r6, r2
	ldr r0, [r3, #0x08]
	str r0, [r1, #0x00]
	ldr r1, [r6, #0x14]
	b _08049918
_080498EC: .4byte 0x02039B9C
_080498F0: .4byte 0x00200000
_080498F4: .4byte 0x00000000
_080498F8: .4byte 0x02039B84
_080498FC: .4byte 0x0000014D
_08049900:
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x80
	lsls r0, r0, #0x09
	str r0, [r1, #0x00]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r2, r6, r1
	ldr r1, [r6, #0x14]
	ldr r0, [r1, #0x08]
	str r0, [r2, #0x00]
_08049918:
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08049944
	ldr r0, [r5, #0x00]
	adds r0, #0xDC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	ldr r1, _08049940 @ =0x00000000
	ldr r0, _0804993C @ =0x00020004
	b _08049956
_0804993C: .4byte 0x00020004
_08049940: .4byte 0x00000000
_08049944:
	ldr r0, [r5, #0x00]
	adds r0, #0xDA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, #0x30
	lsls r0, r0, #0x08
	str r0, [r7, #0x04]
	ldr r1, _08049994 @ =0x00000000
	ldr r0, _08049990 @ =0x00020000
_08049956:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r0, [r0, #0x00]
	str r0, [r7, #0x08]
	movs r0, #0x00
	str r0, [r7, #0x0C]
	str r0, [r7, #0x10]
	ldr r1, _08049998 @ =0x0000014D
	adds r0, r6, r1
	ldrb r1, [r0, #0x00]
	cmp r1, #0x01
	beq _0804999C
	cmp r1, #0x01
	bgt _080499A6
	cmp r1, #0x00
	bne _080499A6
	subs r2, #0x0C
	adds r1, r6, r2
	movs r0, #0x01
	str r0, [r1, #0x00]
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xA0
	b _080499B8
	.byte 0x00, 0x00
_08049990: .4byte 0x00020000
_08049994: .4byte 0x00000000
_08049998: .4byte 0x0000014D
_0804999C:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	b _080499B0
_080499A6:
	movs r2, #0xA4
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x02
	str r0, [r1, #0x00]
_080499B0:
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xA1
_080499B8:
	str r0, [r1, #0x00]
	ldr r0, _08049A04 @ =0x09617E18
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x1C]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r4, r6, r1
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08049A08 @ =0x0813ED90
	ldr r1, [r6, #0x18]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	adds r0, r6, #0x0
	movs r1, #0x01
	bl func_08000E64
	ldr r1, _08049A0C @ =0x09EDAE88
	adds r0, r6, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08049A04: .4byte 0x09617E18
_08049A08: .4byte 0x0813ED90
_08049A0C: .4byte 0x09EDAE88
.syntax divided
