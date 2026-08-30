.syntax unified
	.align 2, 0
	.global func_08076750
	.thumb
	.thumb_func
	.type func_08076750, %function
func_08076750: @ 08076750
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r12, r0
	adds r6, r2, #0x0
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	lsls r1, r2, #0x02
	adds r0, #0x44
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r1, [r6, r3]
	ldr r3, [r0, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r1, r0, r3
	ldrh r0, [r1, #0x06]
	cmp r0, #0x00
	bne _0807679E
	ldr r0, [r1, #0x08]
	ldr r1, _08076794 @ =0x00FF00FF
	ands r0, r1
	cmp r0, #0x00
	bne _0807679E
	movs r0, #0x00
	ldsh r1, [r6, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r3, r0
	b _08076818
	.byte 0x00, 0x00
_08076794: .4byte 0x00FF00FF
_08076798:
	strh r4, [r6, #0x00]
	adds r0, r2, #0x0
	b _08076818
_0807679E:
	ldrh r5, [r6, #0x00]
	subs r0, r5, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0x00
	bge _080767BA
	lsls r0, r2, #0x01
	mov r1, r12
	adds r1, #0xA8
	adds r1, r1, r0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080767BA:
	lsls r3, r4, #0x10
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
	cmp r3, r0
	beq _08076816
	lsls r1, r2, #0x02
	mov r0, r12
	adds r0, #0x44
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov r8, r0
	ldr r1, _08076824 @ =0x0000FFFF
	mov r9, r1
	lsls r1, r2, #0x01
	mov r0, r12
	adds r0, #0xA8
	adds r7, r0, r1
_080767DC:
	asrs r3, r3, #0x10
	lsls r0, r3, #0x01
	adds r0, r0, r3
	lsls r0, r0, #0x02
	mov r1, r8
	adds r2, r0, r1
	ldrh r1, [r2, #0x06]
	mov r0, r9
	ands r0, r1
	cmp r0, #0x00
	bne _080767FC
	ldr r0, [r2, #0x08]
	ldr r1, _08076828 @ =0x00FF00FF
	ands r0, r1
	cmp r0, #0x00
	beq _08076798
_080767FC:
	subs r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r0, #0x00
	bge _0807680E
	ldrh r0, [r7, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0807680E:
	lsls r3, r4, #0x10
	asrs r0, r3, #0x10
	cmp r0, r5
	bne _080767DC
_08076816:
	movs r0, #0x00
_08076818:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08076824: .4byte 0x0000FFFF
_08076828: .4byte 0x00FF00FF
.syntax divided
