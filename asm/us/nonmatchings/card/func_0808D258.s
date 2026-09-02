.syntax unified
	.align 2, 0
	.global func_0808D258
	.thumb
	.thumb_func
	.type func_0808D258, %function
func_0808D258: @ 0808D258
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r10, r7
	movs r0, #0x00
	mov r9, r0
	adds r0, r7, #0x0
	bl func_08085770
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	movs r1, #0xFA
	lsls r1, r1, #0x02
	mov r8, r1
	adds r0, r4, #0x0
	bl __udivsi3
	strb r0, [r5, #0x00]
	mov r5, sp
	movs r6, #0x64
	adds r0, r4, #0x0
	movs r1, #0x64
	bl __udivsi3
	mov r1, sp
	ldrb r2, [r1, #0x00]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r5, #0x01]
	mov r5, sp
	adds r0, r4, #0x0
	movs r1, #0x0A
	bl __udivsi3
	mov r1, sp
	ldrb r1, [r1, #0x00]
	muls r1, r6
	subs r0, r0, r1
	mov r1, sp
	ldrb r2, [r1, #0x01]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r5, #0x02]
	mov r2, sp
	mov r0, sp
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	subs r4, r4, r0
	mov r0, sp
	ldrb r0, [r0, #0x01]
	muls r0, r6
	subs r4, r4, r0
	mov r0, sp
	ldrb r1, [r0, #0x02]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r4, r4, r0
	strb r4, [r2, #0x03]
	add r4, sp, #0x004
	ldr r5, _0808D364 @ =0x02039BB0
	adds r5, #0xFA
	movs r1, #0x00
	ldsh r0, [r5, r1]
	mov r1, r8
	bl __divsi3
	strb r0, [r4, #0x00]
	movs r1, #0x00
	ldsh r0, [r5, r1]
	movs r1, #0x64
	bl __divsi3
	ldrb r2, [r4, #0x00]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r4, #0x01]
	movs r1, #0x00
	ldsh r0, [r5, r1]
	movs r1, #0x0A
	bl __divsi3
	ldrb r1, [r4, #0x00]
	muls r1, r6
	subs r0, r0, r1
	ldrb r2, [r4, #0x01]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	strb r0, [r4, #0x02]
	ldrb r2, [r5, #0x00]
	ldrb r1, [r4, #0x00]
	lsls r0, r1, #0x05
	subs r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x03
	subs r2, r2, r0
	ldrb r0, [r4, #0x01]
	muls r0, r6
	subs r2, r2, r0
	ldrb r1, [r4, #0x02]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r2, r2, r0
	strb r2, [r4, #0x03]
	adds r5, r4, #0x0
	cmp r7, #0x01
	beq _0808D374
	cmp r7, #0x01
	bgt _0808D368
	cmp r7, #0x00
	beq _0808D370
	b _0808D380
	.byte 0x00, 0x00
_0808D364: .4byte 0x02039BB0
_0808D368:
	mov r0, r10
	cmp r0, #0x02
	beq _0808D378
	b _0808D380
_0808D370:
	movs r0, #0x00
	b _0808D37A
_0808D374:
	movs r0, #0x01
	b _0808D37A
_0808D378:
	movs r0, #0x02
_0808D37A:
	bl GetBgCharBase
	mov r9, r0
_0808D380:
	mov r0, sp
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	ldr r4, _0808D434 @ =0x0940F938
	adds r0, r0, r4
	mov r1, r9
	adds r1, #0xA0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	mov r1, r9
	adds r1, #0xC0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x02]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	mov r1, r9
	adds r1, #0xE0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x03]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	movs r1, #0x80
	lsls r1, r1, #0x01
	add r1, r9
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r5, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	movs r1, #0x90
	lsls r1, r1, #0x01
	add r1, r9
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r5, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	movs r1, #0xA0
	lsls r1, r1, #0x01
	add r1, r9
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r5, #0x02]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	movs r1, #0xB0
	lsls r1, r1, #0x01
	add r1, r9
	movs r2, #0x20
	bl RequestDma3Copy
	ldrb r0, [r5, #0x03]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r4
	movs r1, #0xC0
	lsls r1, r1, #0x01
	add r1, r9
	movs r2, #0x20
	bl RequestDma3Copy
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0808D434: .4byte 0x0940F938
.syntax divided
