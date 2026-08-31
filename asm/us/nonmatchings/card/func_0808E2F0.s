.syntax unified
	.align 2, 0
	.global func_0808E2F0
	.thumb
	.thumb_func
	.type func_0808E2F0, %function
func_0808E2F0: @ 0808E2F0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r1, _0808E304 @ =0x000004D4
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808E336
	movs r5, #0x00
	b _0808E31E
	.byte 0x00, 0x00
_0808E304: .4byte 0x000004D4
_0808E308:
	ldr r1, _0808E33C @ =0x000004D4
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	lsls r0, r5, #0x05
	adds r0, r0, r1
	ldr r0, [r0, #0x1C]
	bl EwramFree
	adds r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0808E31E:
	ldr r1, _0808E340 @ =0x00000898
	adds r0, r4, r1
	ldrh r0, [r0, #0x00]
	cmp r5, r0
	bcc _0808E308
	ldr r0, _0808E33C @ =0x000004D4
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	bl EwramFree
	movs r0, #0x00
	str r0, [r4, #0x00]
_0808E336:
	pop {r4, r5}
	pop {r0}
	bx r0
_0808E33C: .4byte 0x000004D4
_0808E340: .4byte 0x00000898
.syntax divided
