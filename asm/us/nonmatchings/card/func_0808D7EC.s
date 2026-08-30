.syntax unified
	.align 2, 0
	.global func_0808D7EC
	.thumb
	.thumb_func
	.type func_0808D7EC, %function
func_0808D7EC: @ 0808D7EC
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x34
	muls r0, r1
	ldr r1, _0808D81C @ =0x08F70AB0
	adds r0, r0, r1
	ldr r1, _0808D820 @ =0x09EE8F48
	ldrh r0, [r0, #0x1C]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	movs r2, #0xF4
	lsls r2, r2, #0x01
	adds r1, r4, r2
	bl func_08065B6C
	ldr r1, _0808D824 @ =0x000008C6
	adds r4, r4, r1
	strb r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0808D81C: .4byte 0x08F70AB0
_0808D820: .4byte 0x09EE8F48
_0808D824: .4byte 0x000008C6
.syntax divided
