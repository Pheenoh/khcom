.syntax unified
	.align 2, 0
	.global func_0808E8E8
	.thumb
	.thumb_func
	.type func_0808E8E8, %function
func_0808E8E8: @ 0808E8E8
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r0, r1
	bl func_08000C8C
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _0808E92C
	lsls r0, r4, #0x10
	asrs r6, r0, #0x10
	lsls r0, r5, #0x10
	asrs r4, r0, #0x10
_0808E90A:
	movs r1, #0x22
	ldsh r0, [r3, r1]
	cmp r0, r6
	bne _0808E91E
	movs r1, #0x24
	ldsh r0, [r3, r1]
	cmp r0, r4
	bne _0808E91E
	movs r0, #0x01
	b _0808E92E
_0808E91E:
	adds r0, r3, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _0808E90A
_0808E92C:
	movs r0, #0x00
_0808E92E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
