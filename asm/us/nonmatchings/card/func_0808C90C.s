.syntax unified
	.align 2, 0
	.global func_0808C90C
	.thumb
	.thumb_func
	.type func_0808C90C, %function
func_0808C90C: @ 0808C90C
	push {r4, r5, lr}
	adds r5, r0, #0x0
	movs r1, #0xFE
	lsls r1, r1, #0x03
	adds r0, r5, r1
	bl func_08000C8C
	cmp r0, #0x00
	beq _0808C930
	movs r4, #0x01
_0808C920:
	adds r1, r0, #0x0
	adds r1, #0x4A
	strb r4, [r1, #0x00]
	adds r0, #0x2C
	bl func_08000CD4
	cmp r0, #0x00
	bne _0808C920
_0808C930:
	movs r1, #0xF9
	lsls r1, r1, #0x03
	adds r0, r5, r1
	bl TaskPoolUpdate
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
