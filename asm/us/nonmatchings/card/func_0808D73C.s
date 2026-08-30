.syntax unified
	.align 2, 0
	.global func_0808D73C
	.thumb
	.thumb_func
	.type func_0808D73C, %function
func_0808D73C: @ 0808D73C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r0, #0x34
	adds r4, r1, #0x0
	muls r4, r0
	ldr r0, _0808D76C @ =0x08F70AB0
	adds r4, r4, r0
	ldr r0, [r4, #0x0C]
	adds r1, r5, #0x0
	adds r1, #0xF8
	bl func_08065B6C
	ldr r2, _0808D770 @ =0x000008C5
	adds r1, r5, r2
	strb r0, [r1, #0x00]
	adds r4, #0x2A
	ldrb r0, [r4, #0x00]
	cmp r0, #0x01
	beq _0808D790
	cmp r0, #0x01
	bgt _0808D774
	cmp r0, #0x00
	beq _0808D77E
	b _0808D7DA
_0808D76C: .4byte 0x08F70AB0
_0808D770: .4byte 0x000008C5
_0808D774:
	cmp r0, #0x02
	beq _0808D798
	cmp r0, #0x03
	beq _0808D7C0
	b _0808D7DA
_0808D77E:
	ldr r0, _0808D788 @ =0x09614458
	ldr r3, _0808D78C @ =0x000004C4
	adds r1, r5, r3
	b _0808D79E
	.byte 0x00, 0x00
_0808D788: .4byte 0x09614458
_0808D78C: .4byte 0x000004C4
_0808D790:
	ldr r0, _0808D794 @ =0x09614478
	b _0808D79A
_0808D794: .4byte 0x09614478
_0808D798:
	ldr r0, _0808D7B4 @ =0x09614498
_0808D79A:
	ldr r2, _0808D7B8 @ =0x000004C4
	adds r1, r5, r2
_0808D79E:
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r3, _0808D7BC @ =0x05000200
	adds r1, r1, r3
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	bl func_08005BE8
	b _0808D7DA
_0808D7B4: .4byte 0x09614498
_0808D7B8: .4byte 0x000004C4
_0808D7BC: .4byte 0x05000200
_0808D7C0:
	ldr r0, _0808D7E0 @ =0x096144B8
	ldr r2, _0808D7E4 @ =0x000004C4
	adds r1, r5, r2
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x06]
	lsls r1, r1, #0x05
	ldr r3, _0808D7E8 @ =0x05000200
	adds r1, r1, r3
	ldrh r2, [r2, #0x08]
	lsls r2, r2, #0x15
	lsrs r2, r2, #0x10
	bl func_08005BE8
_0808D7DA:
	pop {r4, r5}
	pop {r0}
	bx r0
_0808D7E0: .4byte 0x096144B8
_0808D7E4: .4byte 0x000004C4
_0808D7E8: .4byte 0x05000200
.syntax divided
