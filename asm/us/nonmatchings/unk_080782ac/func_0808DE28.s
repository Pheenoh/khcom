.syntax unified
	.align 2, 0
	.global func_0808DE28
	.thumb
	.thumb_func
	.type func_0808DE28, %function
func_0808DE28: @ 0808DE28
	push {r4, r5, r6, lr}
	add sp, #-0x004
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #0x03
	bl func_08005130
	adds r6, r0, #0x0
	cmp r5, #0x00
	beq _0808DE8C
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl __udivsi3
	strb r0, [r4, #0x00]
	mov r2, sp
	mov r0, sp
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x01
	subs r0, r5, r0
	strb r0, [r2, #0x01]
	mov r0, sp
	ldrb r0, [r0, #0x00]
	adds r0, #0x03
	lsls r0, r0, #0x05
	ldr r4, _0808DE88 @ =0x0940FA98
	adds r0, r0, r4
	movs r2, #0xCE
	lsls r2, r2, #0x04
	adds r1, r6, r2
	movs r2, #0x20
	bl func_080043B4
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x03
	lsls r0, r0, #0x05
	adds r0, r0, r4
	movs r2, #0xD0
	lsls r2, r2, #0x04
	adds r1, r6, r2
	movs r2, #0x20
	bl func_080043B4
	b _0808DEAA
_0808DE88: .4byte 0x0940FA98
_0808DE8C:
	ldr r4, _0808DEB4 @ =0x0940FAD8
	movs r0, #0xCE
	lsls r0, r0, #0x04
	adds r1, r6, r0
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	movs r2, #0xD0
	lsls r2, r2, #0x04
	adds r1, r6, r2
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
_0808DEAA:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808DEB4: .4byte 0x0940FAD8
.syntax divided
