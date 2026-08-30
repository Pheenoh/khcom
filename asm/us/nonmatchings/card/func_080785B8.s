.syntax unified
	.align 2, 0
	.global func_080785B8
	.thumb
	.thumb_func
	.type func_080785B8, %function
func_080785B8: @ 080785B8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x00C
	adds r6, r0, #0x0
	adds r7, r1, #0x0
	adds r0, r7, #0x0
	bl func_080858B8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r7, #0x00
	beq _080785DC
	cmp r7, #0x01
	beq _080786B8
	b _08078738
_080785DC:
	mov r0, r8
	cmp r0, #0x00
	beq _08078690
	mov r5, r8
	adds r5, #0x0F
	lsls r4, r5, #0x01
	adds r4, r4, r5
	lsls r0, r4, #0x02
	bl func_08000918
	adds r1, r0, #0x0
	str r1, [r6, #0x44]
	str r7, [sp, #0x000]
	movs r2, #0xA0
	lsls r2, r2, #0x13
	orrs r2, r4
	mov r0, sp
	bl func_08117FE8
	movs r2, #0x00
	mov r4, r8
	adds r4, #0x01
	mov r8, r5
	adds r7, r4, #0x0
	movs r1, #0x94
	adds r1, r1, r6
	mov r9, r1
	cmp r2, r7
	bge _08078644
	movs r3, #0x00
	ldr r5, _0807868C @ =0x0000FFFF
_0807861A:
	ldr r0, [r6, #0x44]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r0, r1, r0
	strb r3, [r0, #0x06]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	str r5, [r0, #0x00]
	strb r3, [r0, #0x07]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r6, #0x44]
	adds r1, r1, r0
	strb r3, [r1, #0x08]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r4
	blt _0807861A
_08078644:
	lsls r0, r7, #0x18
	lsrs r2, r0, #0x18
	mov r5, r8
	cmp r2, r5
	bge _0807867C
	movs r3, #0x01
	ldr r4, _0807868C @ =0x0000FFFF
_08078652:
	ldr r0, [r6, #0x44]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r0, r1, r0
	strb r3, [r0, #0x06]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	str r4, [r0, #0x00]
	strb r3, [r0, #0x07]
	ldr r0, [r6, #0x44]
	adds r0, r1, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r6, #0x44]
	adds r1, r1, r0
	strb r3, [r1, #0x08]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r5
	blt _08078652
_0807867C:
	ldr r0, [r6, #0x44]
	movs r1, #0x00
	bl func_08078330
	movs r0, #0x00
	mov r1, r9
	b _08078736
	.byte 0x00, 0x00
_0807868C: .4byte 0x0000FFFF
_08078690:
	movs r0, #0x0C
	bl func_08000918
	adds r1, r0, #0x0
	str r1, [r6, #0x44]
	mov r0, r8
	str r0, [sp, #0x004]
	add r0, sp, #0x004
	ldr r2, _080786B4 @ =0x05000003
	bl func_08117FE8
	ldr r1, [r6, #0x44]
	movs r0, #0xFF
	str r0, [r1, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x94
	b _08078734
	.byte 0x00, 0x00
_080786B4: .4byte 0x05000003
_080786B8:
	mov r1, r8
	cmp r1, #0x00
	beq _08078714
	lsls r0, r1, #0x01
	add r0, r8
	lsls r0, r0, #0x02
	bl func_08000918
	str r0, [r6, #0x50]
	movs r2, #0x00
	adds r5, r6, #0x0
	adds r5, #0x9A
	cmp r2, r8
	bcs _08078702
	movs r3, #0x00
	ldr r4, _08078710 @ =0x0000FFFF
_080786D8:
	ldr r0, [r6, #0x50]
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r0, r1, r0
	strb r3, [r0, #0x06]
	ldr r0, [r6, #0x50]
	adds r0, r1, r0
	str r4, [r0, #0x00]
	strb r3, [r0, #0x07]
	ldr r0, [r6, #0x50]
	adds r0, r1, r0
	strb r3, [r0, #0x0A]
	ldr r0, [r6, #0x50]
	adds r1, r1, r0
	strb r3, [r1, #0x08]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, r8
	bcc _080786D8
_08078702:
	ldr r0, [r6, #0x50]
	movs r1, #0x01
	bl func_08078330
	movs r0, #0x00
	strh r0, [r5, #0x00]
	b _08078738
_08078710: .4byte 0x0000FFFF
_08078714:
	movs r0, #0x0C
	bl func_08000918
	adds r1, r0, #0x0
	str r1, [r6, #0x50]
	mov r0, r8
	str r0, [sp, #0x008]
	add r0, sp, #0x008
	ldr r2, _08078748 @ =0x05000003
	bl func_08117FE8
	ldr r1, [r6, #0x50]
	ldr r0, _0807874C @ =0x000030FF
	str r0, [r1, #0x00]
	adds r1, r6, #0x0
	adds r1, #0x9A
_08078734:
	ldr r0, _08078750 @ =0x0000FFFF
_08078736:
	strh r0, [r1, #0x00]
_08078738:
	add sp, #0x00C
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08078748: .4byte 0x05000003
_0807874C: .4byte 0x000030FF
_08078750: .4byte 0x0000FFFF
.syntax divided
