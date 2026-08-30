.syntax unified
	.align 2, 0
	.global func_0808CBB4
	.thumb
	.thumb_func
	.type func_0808CBB4, %function
func_0808CBB4: @ 0808CBB4
	push {r4, r5, r6, lr}
	add sp, #-0x004
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	cmp r5, #0x00
	bne _0808CBF4
	movs r0, #0x03
	bl func_08005130
	adds r1, r0, #0x0
	ldr r5, _0808CBF0 @ =0x0940F918
	lsls r4, r6, #0x06
	movs r0, #0xD8
	lsls r0, r0, #0x02
	adds r4, r4, r0
	adds r4, r1, r4
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	adds r4, #0x20
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	b _0808CC4A
_0808CBF0: .4byte 0x0940F918
_0808CBF4:
	mov r4, sp
	adds r0, r5, #0x0
	movs r1, #0x0A
	bl _0811D754
	strb r0, [r4, #0x00]
	mov r2, sp
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #0x02
	adds r1, r1, r0
	lsls r1, r1, #0x01
	subs r1, r5, r1
	strb r1, [r2, #0x01]
	movs r0, #0x03
	bl func_08005130
	adds r1, r0, #0x0
	mov r0, sp
	ldrb r0, [r0, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x05
	ldr r5, _0808CC54 @ =0x0940F7B8
	adds r0, r0, r5
	lsls r4, r6, #0x06
	movs r2, #0xD8
	lsls r2, r2, #0x02
	adds r4, r4, r2
	adds r4, r1, r4
	adds r1, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x01
	lsls r0, r0, #0x05
	adds r0, r0, r5
	adds r4, #0x20
	adds r1, r4, #0x0
	movs r2, #0x20
	bl func_080043B4
_0808CC4A:
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808CC54: .4byte 0x0940F7B8
.syntax divided
