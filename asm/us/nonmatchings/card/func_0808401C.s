.syntax unified
	.align 2, 0
	.global func_0808401C
	.thumb
	.thumb_func
	.type func_0808401C, %function
func_0808401C: @ 0808401C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r2, #0x00
	movs r3, #0x00
	ldr r0, _0808405C @ =0x0203A858
	ldrh r0, [r0, #0x00]
	cmp r3, r0
	bcs _08084052
	ldr r6, _08084060 @ =0x0203A080
	ldr r7, _08084064 @ =0x00000FFF
	adds r4, r0, #0x0
_08084034:
	lsls r0, r2, #0x01
	adds r0, r0, r6
	ldrh r1, [r0, #0x00]
	adds r0, r7, #0x0
	ands r0, r1
	cmp r0, r5
	bne _08084048
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
_08084048:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r4
	bcc _08084034
_08084052:
	adds r0, r3, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0808405C: .4byte 0x0203A858
_08084060: .4byte 0x0203A080
_08084064: .4byte 0x00000FFF
.syntax divided
