.syntax unified
	.align 2, 0
	.global func_0808DDD0
	.thumb
	.thumb_func
	.type func_0808DDD0, %function
func_0808DDD0: @ 0808DDD0
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x88
	lsls r1, r1, #0x04
	adds r0, r4, r1
	ldrh r0, [r0, #0x00]
	ldr r2, _0808DE1C @ =0x000004D4
	adds r1, r4, r2
	ldr r1, [r1, #0x00]
	lsls r0, r0, #0x05
	adds r0, r0, r1
	ldrh r0, [r0, #0x14]
	bl func_0808C8D0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0808DE20 @ =0x00000884
	adds r1, r4, r3
	movs r3, #0x00
	ldsh r2, [r1, r3]
	lsls r1, r2, #0x02
	adds r1, r1, r2
	ldr r2, _0808DE24 @ =0x00000886
	adds r4, r4, r2
	adds r0, r0, r1
	ldrh r4, [r4, #0x00]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl func_080609AC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_0808DE28
	pop {r4}
	pop {r0}
	bx r0
_0808DE1C: .4byte 0x000004D4
_0808DE20: .4byte 0x00000884
_0808DE24: .4byte 0x00000886
.syntax divided
