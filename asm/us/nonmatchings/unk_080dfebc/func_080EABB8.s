.syntax unified
	.align 2, 0
	.global func_080EABB8
	.thumb
	.thumb_func
	.type func_080EABB8, %function
func_080EABB8: @ 080EABB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x01
	ands r5, r0
	mov r6, sp
	movs r0, #0x64
	mov r8, r0
	adds r0, r4, #0x0
	movs r1, #0x64
	bl __udivsi3
	strh r0, [r6, #0x00]
	mov r6, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	mov r1, sp
	ldrh r2, [r1, #0x00]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strh r0, [r6, #0x02]
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0, #0x00]
	mov r1, r8
	muls r1, r0
	adds r0, r1, #0x0
	subs r4, r4, r0
	mov r0, sp
	ldrh r1, [r0, #0x02]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r4, r4, r0
	strh r4, [r2, #0x04]
	movs r6, #0x01
	lsls r0, r5, #0x02
	adds r0, r0, r5
	lsls r0, r0, #0x02
	subs r0, r0, r5
	lsls r0, r0, #0x05
	adds r7, r0, #0x0
	adds r7, #0x20
	mov r5, sp
	adds r5, #0x02
_080EAC28:
	ldrh r4, [r5, #0x00]
	lsls r4, r4, #0x05
	ldr r0, _080EAC5C @ =0x09966064
	adds r4, r4, r0
	movs r0, #0x01
	bl GetBgCharBase
	adds r1, r0, #0x0
	adds r1, r1, r7
	lsls r0, r6, #0x05
	adds r1, r1, r0
	adds r0, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r5, #0x02
	adds r6, #0x01
	cmp r6, #0x02
	ble _080EAC28
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080EAC5C: .4byte 0x09966064
.syntax divided
