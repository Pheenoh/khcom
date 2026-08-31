.syntax unified
	.align 2, 0
	.global func_0808D16C
	.thumb
	.thumb_func
	.type func_0808D16C, %function
func_0808D16C: @ 0808D16C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	movs r0, #0x00
	bl GetBgCharBase
	adds r7, r0, #0x0
	movs r0, #0x01
	bl GetBgCharBase
	mov r8, r0
	movs r0, #0x02
	bl GetBgCharBase
	mov r9, r0
	cmp r4, #0x01
	beq _0808D1D8
	cmp r4, #0x01
	bgt _0808D1A0
	cmp r4, #0x00
	beq _0808D1A6
	b _0808D244
_0808D1A0:
	cmp r5, #0x02
	beq _0808D214
	b _0808D244
_0808D1A6:
	ldr r4, _0808D1D4 @ =0x0940FC58
	movs r5, #0xD0
	lsls r5, r5, #0x01
	adds r1, r7, r5
	movs r6, #0xF0
	lsls r6, r6, #0x01
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl RequestDma3Copy
	movs r0, #0x80
	lsls r0, r0, #0x03
	adds r4, r4, r0
	mov r2, r8
	adds r1, r2, r5
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl RequestDma3Copy
	add r5, r9
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	b _0808D200
_0808D1D4: .4byte 0x0940FC58
_0808D1D8:
	ldr r6, _0808D20C @ =0x09410058
	movs r4, #0xD0
	lsls r4, r4, #0x01
	adds r1, r7, r4
	movs r5, #0xF0
	lsls r5, r5, #0x01
	adds r0, r6, #0x0
	adds r2, r5, #0x0
	bl RequestDma3Copy
	ldr r1, _0808D210 @ =0xFFFFFC00
	adds r0, r6, r1
	mov r2, r8
	adds r1, r2, r4
	adds r2, r5, #0x0
	bl RequestDma3Copy
	add r4, r9
	adds r0, r6, #0x0
	adds r1, r4, #0x0
_0808D200:
	movs r2, #0xF0
	lsls r2, r2, #0x01
	bl RequestDma3Copy
	b _0808D244
	.byte 0x00, 0x00
_0808D20C: .4byte 0x09410058
_0808D210: .4byte 0xFFFFFC00
_0808D214:
	ldr r4, _0808D250 @ =0x09410058
	movs r5, #0xD0
	lsls r5, r5, #0x01
	adds r1, r7, r5
	movs r6, #0xF0
	lsls r6, r6, #0x01
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl RequestDma3Copy
	mov r0, r8
	adds r1, r0, r5
	adds r0, r4, #0x0
	adds r2, r6, #0x0
	bl RequestDma3Copy
	ldr r1, _0808D254 @ =0xFFFFFC00
	adds r4, r4, r1
	add r5, r9
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	adds r2, r6, #0x0
	bl RequestDma3Copy
_0808D244:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0808D250: .4byte 0x09410058
_0808D254: .4byte 0xFFFFFC00
.syntax divided
