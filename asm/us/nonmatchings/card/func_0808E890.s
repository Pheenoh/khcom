.syntax unified
	.align 2, 0
	.global func_0808E890
	.thumb
	.thumb_func
	.type func_0808E890, %function
func_0808E890: @ 0808E890
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r4, r1
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _0808E8DE
	ldr r3, _0808E8C8 @ =0x00000884
	adds r5, r4, r3
_0808E8A8:
	movs r0, #0x22
	ldsh r1, [r2, r0]
	movs r3, #0x00
	ldsh r0, [r5, r3]
	cmp r1, r0
	bne _0808E8D0
	ldr r1, _0808E8CC @ =0x00000886
	adds r0, r4, r1
	movs r3, #0x24
	ldsh r1, [r2, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	bne _0808E8D0
	movs r0, #0x01
	b _0808E8E0
_0808E8C8: .4byte 0x00000884
_0808E8CC: .4byte 0x00000886
_0808E8D0:
	adds r0, r2, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _0808E8A8
_0808E8DE:
	movs r0, #0x00
_0808E8E0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
