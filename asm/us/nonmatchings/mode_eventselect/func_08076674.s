.syntax unified
	.align 2, 0
	.global func_08076674
	.thumb
	.thumb_func
	.type func_08076674, %function
func_08076674: @ 08076674
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r12, r0
	mov r8, r2
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r1, r5, #0x02
	adds r0, #0x44
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r2, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r1, r0, r2
	ldrh r0, [r1, #0x06]
	cmp r0, #0x00
	bne _080766C4
	ldr r0, [r1, #0x08]
	ldr r1, _080766B8 @ =0x00FF00FF
	ands r0, r1
	cmp r0, #0x00
	bne _080766C4
	mov r0, r8
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r2, r0
	b _0807673C
_080766B8: .4byte 0x00FF00FF
_080766BC:
	mov r0, r8
	strh r4, [r0, #0x00]
	adds r0, r2, #0x0
	b _0807673C
_080766C4:
	mov r1, r8
	ldrh r6, [r1, #0x00]
	adds r1, r6, #0x1
	lsls r1, r1, #0x10
	lsls r2, r5, #0x01
	mov r0, r12
	adds r0, #0xA8
	adds r7, r0, r2
	lsrs r4, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x00
	ldsh r0, [r7, r2]
	cmp r1, r0
	blt _080766E2
	movs r4, #0x00
_080766E2:
	lsls r3, r4, #0x10
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	cmp r3, r0
	beq _0807673A
	lsls r1, r5, #0x02
	mov r0, r12
	adds r0, #0x44
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov r12, r0
	ldr r0, _08076748 @ =0x0000FFFF
	mov r9, r0
	adds r6, r7, #0x0
	adds r5, r2, #0x0
_08076700:
	asrs r3, r3, #0x10
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x02
	mov r1, r12
	adds r2, r0, r1
	ldrh r1, [r2, #0x06]
	mov r0, r9
	ands r0, r1
	cmp r0, #0x00
	bne _08076720
	ldr r0, [r2, #0x08]
	ldr r1, _0807674C @ =0x00FF00FF
	ands r0, r1
	cmp r0, #0x00
	beq _080766BC
_08076720:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x00
	ldsh r1, [r6, r2]
	cmp r0, r1
	blt _08076732
	movs r4, #0x00
_08076732:
	lsls r3, r4, #0x10
	asrs r0, r3, #0x10
	cmp r0, r5
	bne _08076700
_0807673A:
	movs r0, #0x00
_0807673C:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08076748: .4byte 0x0000FFFF
_0807674C: .4byte 0x00FF00FF
.syntax divided
