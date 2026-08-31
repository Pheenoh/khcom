.syntax unified
	.align 2, 0
	.global func_0808DD20
	.thumb
	.thumb_func
	.type func_0808DD20, %function
func_0808DD20: @ 0808DD20
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r0, #0x03
	bl GetBgCharBase
	adds r7, r0, #0x0
	cmp r5, #0x00
	beq _0808DD8C
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
	ldr r5, _0808DD88 @ =0x0940FA98
	adds r0, r0, r5
	lsls r4, r6, #0x06
	movs r1, #0xD2
	lsls r1, r1, #0x04
	adds r4, r4, r1
	adds r4, r7, r4
	adds r1, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	mov r0, sp
	ldrb r0, [r0, #0x01]
	adds r0, #0x03
	lsls r0, r0, #0x05
	adds r0, r0, r5
	adds r4, #0x20
	adds r1, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	b _0808DDBC
_0808DD88: .4byte 0x0940FA98
_0808DD8C:
	ldr r5, _0808DDC4 @ =0x0940FAD8
	lsls r4, r6, #0x06
	movs r2, #0xD2
	lsls r2, r2, #0x04
	adds r4, r4, r2
	adds r4, r7, r4
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r4, #0x20
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	ldr r0, _0808DDC8 @ =0x09614406
	lsls r1, r6, #0x01
	ldr r2, _0808DDCC @ =0x0500016C
	adds r1, r1, r2
	movs r2, #0x02
	bl LoadPalette
_0808DDBC:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0808DDC4: .4byte 0x0940FAD8
_0808DDC8: .4byte 0x09614406
_0808DDCC: .4byte 0x0500016C
.syntax divided
