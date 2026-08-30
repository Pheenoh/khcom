.syntax unified
	.align 2, 0
	.global func_0808E750
	.thumb
	.thumb_func
	.type func_0808E750, %function
func_0808E750: @ 0808E750
	push {r4, lr}
	adds r4, r0, #0x0
	bl GetActiveDeckIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_08085770
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0808E774 @ =0x02039BB0
	adds r1, #0xFA
	movs r2, #0x00
	ldsh r1, [r1, r2]
	cmp r0, r1
	bgt _0808E778
	movs r0, #0x01
	b _0808E78E
_0808E774: .4byte 0x02039BB0
_0808E778:
	ldr r3, _0808E794 @ =0x000007DC
	adds r0, r4, r3
	ldr r1, _0808E798 @ =0x09EE7FA8
	adds r3, #0xED
	adds r2, r4, r3
	bl func_08000E14
	movs r0, #0x69
	bl func_0811FE70
	movs r0, #0x00
_0808E78E:
	pop {r4}
	pop {r1}
	bx r1
_0808E794: .4byte 0x000007DC
_0808E798: .4byte 0x09EE7FA8
.syntax divided
