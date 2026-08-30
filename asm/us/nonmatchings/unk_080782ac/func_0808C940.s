.syntax unified
	.align 2, 0
	.global func_0808C940
	.thumb
	.thumb_func
	.type func_0808C940, %function
func_0808C940: @ 0808C940
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x03
	bl func_0811D5EC
	adds r6, r0, #0x0
	ldr r0, _0808C970 @ =0x000008AE
	adds r5, r5, r0
	strh r6, [r5, #0x00]
	adds r0, r4, #0x0
	movs r1, #0x03
	bl func_0811D684
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _0808C96A
	adds r0, r6, #0x1
	strh r0, [r5, #0x00]
_0808C96A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0808C970: .4byte 0x000008AE
.syntax divided
