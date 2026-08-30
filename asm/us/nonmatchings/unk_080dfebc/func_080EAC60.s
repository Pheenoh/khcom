.syntax unified
	.align 2, 0
	.global func_080EAC60
	.thumb
	.thumb_func
	.type func_080EAC60, %function
func_080EAC60: @ 080EAC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x00C
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	movs r0, #0x01
	ands r6, r0
	movs r1, #0xE1
	lsls r1, r1, #0x04
	adds r0, r5, #0x0
	bl __udivsi3
	adds r4, r0, #0x0
	mov r8, sp
	movs r1, #0x0A
	bl __udivsi3
	mov r1, r8
	strh r0, [r1, #0x00]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r0, r4, r0
	strh r0, [r2, #0x02]
	lsls r0, r4, #0x03
	subs r0, r0, r4
	lsls r0, r0, #0x05
	adds r0, r0, r4
	lsls r0, r0, #0x04
	subs r5, r5, r0
	adds r0, r5, #0x0
	movs r1, #0x3C
	bl __udivsi3
	adds r4, r0, #0x0
	mov r8, sp
	movs r1, #0x0A
	bl __udivsi3
	mov r1, r8
	strh r0, [r1, #0x04]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0x04]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r0, r4, r0
	strh r0, [r2, #0x06]
	lsls r0, r4, #0x04
	subs r0, r0, r4
	lsls r0, r0, #0x02
	subs r5, r5, r0
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __udivsi3
	strh r0, [r4, #0x08]
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0x08]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r5, r5, r0
	strh r5, [r2, #0x0A]
	movs r7, #0x00
	lsls r0, r6, #0x02
	adds r0, r0, r6
	lsls r0, r0, #0x02
	subs r0, r0, r6
	lsls r0, r0, #0x05
	adds r6, r0, #0x0
	adds r6, #0x80
	mov r5, sp
_080EAD04:
	ldrh r4, [r5, #0x00]
	lsls r4, r4, #0x05
	ldr r0, _080EAD38 @ =0x09966064
	adds r4, r4, r0
	movs r0, #0x01
	bl func_08005130
	adds r1, r0, #0x0
	adds r1, r1, r6
	lsls r0, r7, #0x05
	adds r1, r1, r0
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r5, #0x02
	adds r7, #0x01
	cmp r7, #0x05
	ble _080EAD04
	add sp, #0x00C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080EAD38: .4byte 0x09966064
.syntax divided
