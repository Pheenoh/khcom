.syntax unified
	.align 2, 0
	.global func_08081760
	.thumb
	.thumb_func
	.type func_08081760, %function
func_08081760: @ 08081760
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r0, _08081784 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r6, r0, #0x0
	cmp r1, #0x29
	beq _08081790
	ldr r3, _08081788 @ =0x02039B9C
	ldr r1, [r3, #0x00]
	adds r1, #0xF4
	ldr r2, _0808178C @ =0x02039DD4
	ldr r0, [r2, #0x00]
	adds r0, #0xCE
	ldrh r0, [r0, #0x00]
	str r0, [r1, #0x00]
	b _080817A2
_08081784: .4byte 0x02039B84
_08081788: .4byte 0x02039B9C
_0808178C: .4byte 0x02039DD4
_08081790:
	ldr r3, _080817D4 @ =0x02039B9C
	ldr r0, [r3, #0x00]
	adds r0, #0xF4
	movs r1, #0x00
	str r1, [r0, #0x00]
	ldr r2, _080817D8 @ =0x02039DD4
	ldr r0, [r2, #0x00]
	adds r0, #0xCE
	strh r1, [r0, #0x00]
_080817A2:
	adds r5, r2, #0x0
	ldr r2, [r5, #0x00]
	movs r0, #0xCE
	adds r0, r0, r2
	mov r12, r0
	ldrh r0, [r0, #0x00]
	cmp r0, #0x2D
	bne _080817E2
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xF4
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080817DC
	adds r0, r2, #0x0
	adds r0, #0xCC
	ldrh r0, [r0, #0x00]
	mov r2, r12
	strh r0, [r2, #0x00]
	ldr r0, [r3, #0x00]
	adds r0, #0xF4
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	b _080817E2
	.byte 0x00, 0x00
_080817D4: .4byte 0x02039B9C
_080817D8: .4byte 0x02039DD4
_080817DC:
	str r0, [r1, #0x00]
	mov r1, r12
	strh r0, [r1, #0x00]
_080817E2:
	ldr r0, [r3, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _080817F8
	adds r0, r4, #0x0
	adds r0, #0x9C
	movs r1, #0x02
	strh r1, [r0, #0x00]
	adds r0, #0x02
	strh r1, [r0, #0x00]
_080817F8:
	ldr r4, [r3, #0x00]
	adds r3, r4, #0x0
	adds r3, #0xF4
	ldr r0, [r3, #0x00]
	cmp r0, #0x29
	bne _08081820
	ldr r0, [r5, #0x00]
	adds r0, #0xCC
	movs r2, #0x00
	strh r2, [r0, #0x00]
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xF4
	str r2, [r1, #0x00]
	adds r0, #0xF8
	strh r2, [r0, #0x00]
	str r2, [r3, #0x00]
	adds r0, r4, #0x0
	adds r0, #0xF8
	strh r2, [r0, #0x00]
_08081820:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
