.syntax unified
	.align 2, 0
	.global func_0808500C
	.thumb
	.thumb_func
	.type func_0808500C, %function
func_0808500C: @ 0808500C
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0x0
	movs r3, #0x00
	strh r3, [r4, #0x00]
	strh r3, [r4, #0x02]
	strh r3, [r4, #0x04]
	strh r3, [r4, #0x06]
	cmp r0, #0x01
	beq _0808503E
	cmp r0, #0x01
	bgt _0808502E
	cmp r0, #0x00
	beq _08085038
	b _0808504E
_0808502E:
	cmp r1, #0x02
	beq _08085044
	cmp r1, #0x03
	beq _0808504A
	b _0808504E
_08085038:
	movs r3, #0x80
	lsls r3, r3, #0x05
	b _0808504E
_0808503E:
	movs r3, #0x80
	lsls r3, r3, #0x06
	b _0808504E
_08085044:
	movs r3, #0x80
	lsls r3, r3, #0x07
	b _0808504E
_0808504A:
	movs r3, #0xE0
	lsls r3, r3, #0x07
_0808504E:
	movs r2, #0x00
	ldr r0, _080850A0 @ =0x0203A858
	adds r6, r0, #0x0
	ldrh r0, [r6, #0x00]
	cmp r2, r0
	bcs _08085098
	ldr r0, _080850A4 @ =0x0203A080
	mov r12, r0
	ldr r5, _080850A8 @ =0x00000FFF
	ldr r7, _080850AC @ =0x08F70AB0
_08085062:
	lsls r0, r2, #0x01
	add r0, r12
	ldrh r1, [r0, #0x00]
	cmp r1, r5
	beq _0808508C
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _0808508C
	adds r0, r5, #0x0
	ands r0, r1
	movs r1, #0x34
	muls r0, r1
	adds r0, r0, r7
	adds r0, #0x2A
	ldrb r1, [r0, #0x00]
	lsls r1, r1, #0x01
	adds r1, r1, r4
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0808508C:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r6, #0x00]
	cmp r2, r0
	bcc _08085062
_08085098:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080850A0: .4byte 0x0203A858
_080850A4: .4byte 0x0203A080
_080850A8: .4byte 0x00000FFF
_080850AC: .4byte 0x08F70AB0
.syntax divided
