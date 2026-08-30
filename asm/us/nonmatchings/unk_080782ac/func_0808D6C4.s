.syntax unified
	.align 2, 0
	.global func_0808D6C4
	.thumb
	.thumb_func
	.type func_0808D6C4, %function
func_0808D6C4: @ 0808D6C4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x38
	adds r0, r5, #0x0
	movs r1, #0x08
	bl func_08065ACC
	adds r6, r4, #0x0
	adds r6, #0x78
	adds r0, r6, #0x0
	movs r1, #0x08
	bl func_08065ACC
	movs r0, #0xB8
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x08
	bl func_08065ACC
	movs r0, #0x00
	bl func_080857BC
	adds r1, r5, #0x0
	bl func_08065B6C
	ldr r2, _0808D730 @ =0x000008C2
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	movs r0, #0x01
	bl func_080857BC
	adds r1, r6, #0x0
	bl func_08065B6C
	ldr r2, _0808D734 @ =0x000008C3
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	movs r0, #0x02
	bl func_080857BC
	mov r1, r8
	bl func_08065B6C
	ldr r1, _0808D738 @ =0x000008C4
	adds r4, r4, r1
	strb r0, [r4, #0x00]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0808D730: .4byte 0x000008C2
_0808D734: .4byte 0x000008C3
_0808D738: .4byte 0x000008C4
.syntax divided
