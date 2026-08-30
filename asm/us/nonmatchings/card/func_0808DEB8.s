.syntax unified
	.align 2, 0
	.global func_0808DEB8
	.thumb
	.thumb_func
	.type func_0808DEB8, %function
func_0808DEB8: @ 0808DEB8
	movs r3, #0x00
	adds r1, r0, #0x0
	movs r2, #0x09
_0808DEBE:
	ldrh r0, [r1, #0x00]
	adds r3, r3, r0
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _0808DEBE
	adds r0, r3, #0x0
	bx lr
	.byte 0x00, 0x00
.syntax divided
