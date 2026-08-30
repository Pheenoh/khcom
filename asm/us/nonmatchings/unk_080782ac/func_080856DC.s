.syntax unified
	.align 2, 0
	.global func_080856DC
	.thumb
	.thumb_func
	.type func_080856DC, %function
func_080856DC: @ 080856DC
	push {r4, r5, r6, r7, lr}
	movs r4, #0x00
	bl func_08085740
	ldr r7, _08085728 @ =0x0000FFFF
	ldr r5, _0808572C @ =0x0203A080
	movs r6, #0x80
	lsls r6, r6, #0x08
	adds r2, r0, #0x0
	movs r3, #0x62
_080856F0:
	ldrh r0, [r2, #0x00]
	cmp r0, r7
	beq _08085706
	lsls r0, r0, #0x01
	adds r0, r0, r5
	ldrh r1, [r0, #0x00]
	adds r0, r6, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08085706
	adds r4, #0x01
_08085706:
	adds r2, #0x02
	subs r3, #0x01
	cmp r3, #0x00
	bge _080856F0
	ldr r2, _08085730 @ =0x02039DE0
	ldr r0, _08085734 @ =0x02034AB0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x05
	adds r0, r0, r2
	adds r0, #0xDC
	ldrh r0, [r0, #0x00]
	cmp r0, r4
	beq _08085738
	movs r0, #0x01
	b _0808573A
_08085728: .4byte 0x0000FFFF
_0808572C: .4byte 0x0203A080
_08085730: .4byte 0x02039DE0
_08085734: .4byte 0x02034AB0
_08085738:
	movs r0, #0x00
_0808573A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
