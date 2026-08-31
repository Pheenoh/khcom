.syntax unified
	.align 2, 0
	.global func_0808C9CC
	.thumb
	.thumb_func
	.type func_0808C9CC, %function
func_0808C9CC: @ 0808C9CC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r5, r1
	bl func_08000C8C
	adds r4, r0, #0x0
	ldr r2, _0808CA64 @ =0x000008AC
	adds r0, r5, r2
	ldr r3, _0808CA68 @ =0x000008AE
	adds r1, r5, r3
	movs r3, #0x00
	ldsh r2, [r0, r3]
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r2, r0
	beq _0808CA5C
	cmp r4, #0x00
	beq _0808CA1A
_0808C9F4:
	ldrh r0, [r4, #0x24]
	subs r0, #0x01
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0808CA0C
	movs r0, #0x80
	lsls r0, r0, #0x0A
	str r0, [r4, #0x44]
	adds r0, r4, #0x0
	bl func_08090170
_0808CA0C:
	adds r0, r4, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0808C9F4
_0808CA1A:
	movs r0, #0x79
	bl m4aSongNumStart
	ldr r1, _0808CA64 @ =0x000008AC
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	adds r1, #0x01
	strh r1, [r0, #0x00]
	ldr r2, _0808CA6C @ =0x00000854
	adds r1, r5, r2
	ldr r0, [r1, #0x00]
	movs r3, #0xC0
	lsls r3, r3, #0x02
	adds r0, r0, r3
	str r0, [r1, #0x00]
	movs r2, #0xF8
	lsls r2, r2, #0x07
	cmp r0, r2
	ble _0808CA42
	str r2, [r1, #0x00]
_0808CA42:
	ldr r1, _0808CA70 @ =0x000008CF
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0808CA56
	ldr r2, _0808CA74 @ =0x00000876
	adds r1, r5, r2
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_0808CA56:
	adds r0, r5, #0x0
	bl func_0808C974
_0808CA5C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808CA64: .4byte 0x000008AC
_0808CA68: .4byte 0x000008AE
_0808CA6C: .4byte 0x00000854
_0808CA70: .4byte 0x000008CF
_0808CA74: .4byte 0x00000876
.syntax divided
