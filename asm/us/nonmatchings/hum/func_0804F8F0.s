.syntax unified
	.align 2, 0
	.global func_0804F8F0
	.thumb
	.thumb_func
	.type func_0804F8F0, %function
func_0804F8F0: @ 0804F8F0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	adds r4, r7, #0x0
	adds r5, r4, #0x0
	adds r5, #0x40
	adds r0, r5, #0x0
	mov r1, sp
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801C700
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804F92C
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r2, r4, r0
	lsls r1, r6, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x04]
	subs r0, r0, r1
	b _0804F93A
_0804F92C:
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r2, r4, r0
	lsls r1, r6, #0x10
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x04]
	adds r0, r0, r1
_0804F93A:
	str r0, [r2, #0x00]
	movs r2, #0xB8
	lsls r2, r2, #0x01
	adds r1, r4, r2
	movs r0, #0x14
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r2, #0x54
	adds r1, r7, r2
	ldr r0, _0804F974 @ =0xFFFFFD00
	str r0, [r1, #0x00]
	ldr r1, [r5, #0x08]
	ldr r0, [sp, #0x000]
	cmp r1, r0
	bge _0804F97C
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0804F978 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xDE
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x10
	b _0804F98E
_0804F974: .4byte 0xFFFFFD00
_0804F978: .4byte 0x02039B84
_0804F97C:
	movs r0, #0xB0
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0804F99C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xE0
	movs r2, #0x00
	ldsh r0, [r0, r2]
	subs r0, #0x10
_0804F98E:
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0804F99C: .4byte 0x02039B84
.syntax divided
