.syntax unified
	.align 2, 0
	.global func_0808C974
	.thumb
	.thumb_func
	.type func_0808C974, %function
func_0808C974: @ 0808C974
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _0808C9BC @ =0x000008AE
	adds r0, r4, r1
	movs r2, #0x00
	ldsh r1, [r0, r2]
	subs r1, #0x04
	movs r0, #0xA8
	lsls r0, r0, #0x07
	bl func_0811D5EC
	ldr r3, _0808C9C0 @ =0x00000854
	adds r2, r4, r3
	ldr r1, _0808C9C4 @ =0x000008AC
	adds r4, r4, r1
	movs r3, #0x00
	ldsh r1, [r4, r3]
	subs r1, #0x04
	muls r0, r1
	movs r3, #0xA0
	lsls r3, r3, #0x06
	adds r0, r0, r3
	str r0, [r2, #0x00]
	movs r1, #0xF8
	lsls r1, r1, #0x07
	cmp r0, r1
	ble _0808C9AC
	str r1, [r2, #0x00]
_0808C9AC:
	ldr r1, [r2, #0x00]
	ldr r0, _0808C9C8 @ =0x000027FF
	cmp r1, r0
	bgt _0808C9B6
	str r3, [r2, #0x00]
_0808C9B6:
	pop {r4}
	pop {r0}
	bx r0
_0808C9BC: .4byte 0x000008AE
_0808C9C0: .4byte 0x00000854
_0808C9C4: .4byte 0x000008AC
_0808C9C8: .4byte 0x000027FF
.syntax divided
