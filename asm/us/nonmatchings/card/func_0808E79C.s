.syntax unified
	.align 2, 0
	.global func_0808E79C
	.thumb
	.thumb_func
	.type func_0808E79C, %function
func_0808E79C: @ 0808E79C
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	bl func_080857D4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _0808E7B0
	movs r0, #0x01
	b _0808E7C6
_0808E7B0:
	movs r0, #0x69
	bl m4aSongNumStart
	ldr r1, _0808E7CC @ =0x000007DC
	adds r0, r4, r1
	ldr r1, _0808E7D0 @ =0x09EE7FC0
	ldr r3, _0808E7D4 @ =0x000008C9
	adds r2, r4, r3
	bl TaskCreate
	movs r0, #0x00
_0808E7C6:
	pop {r4}
	pop {r1}
	bx r1
_0808E7CC: .4byte 0x000007DC
_0808E7D0: .4byte 0x09EE7FC0
_0808E7D4: .4byte 0x000008C9
.syntax divided
