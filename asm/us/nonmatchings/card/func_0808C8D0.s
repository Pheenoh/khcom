.syntax unified
	.align 2, 0
	.global func_0808C8D0
	.thumb
	.thumb_func
	.type func_0808C8D0, %function
func_0808C8D0: @ 0808C8D0
	push {r4, r5, r6, lr}
	adds r3, r0, #0x0
	movs r2, #0x00
	ldr r4, _0808C8E8 @ =0x08F70AB0
	movs r6, #0x80
	lsls r6, r6, #0x08
	ldr r5, _0808C8EC @ =0x000003B5
_0808C8DE:
	ldrh r1, [r4, #0x1C]
	cmp r1, r3
	bne _0808C8F0
	adds r0, r2, #0x0
	b _0808C904
_0808C8E8: .4byte 0x08F70AB0
_0808C8EC: .4byte 0x000003B5
_0808C8F0:
	adds r1, #0x8F
	cmp r1, r3
	bne _0808C8FC
	orrs r2, r6
	adds r0, r2, #0x0
	b _0808C904
_0808C8FC:
	adds r4, #0x34
	adds r2, #0x01
	cmp r2, r5
	bls _0808C8DE
_0808C904:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
