.syntax unified
	.align 2, 0
	.global func_08085BAC
	.thumb
	.thumb_func
	.type func_08085BAC, %function
func_08085BAC: @ 08085BAC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	movs r7, #0x00
	movs r6, #0x00
	bl GetActiveDeck
	mov r8, r0
	ldr r0, _08085C24 @ =0x0000FFFF
	mov r9, r0
	mov r4, r8
	movs r5, #0x62
_08085BC6:
	ldrh r0, [r4, #0x00]
	cmp r0, r9
	beq _08085BE8
	bl func_08085B84
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	beq _08085BE8
	ldrh r0, [r4, #0x00]
	bl func_08085B84
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x03
	beq _08085BE8
	adds r7, #0x01
_08085BE8:
	adds r4, #0x02
	subs r5, #0x01
	cmp r5, #0x00
	bge _08085BC6
	ldr r0, _08085C24 @ =0x0000FFFF
	mov r12, r0
	ldr r3, _08085C28 @ =0x0203A080
	movs r4, #0x80
	lsls r4, r4, #0x08
	mov r2, r8
	movs r5, #0x62
_08085BFE:
	ldrh r0, [r2, #0x00]
	cmp r0, r12
	beq _08085C14
	lsls r0, r0, #0x01
	adds r0, r0, r3
	ldrh r1, [r0, #0x00]
	adds r0, r4, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _08085C14
	adds r6, #0x01
_08085C14:
	adds r2, #0x02
	subs r5, #0x01
	cmp r5, #0x00
	bge _08085BFE
	cmp r6, r7
	beq _08085C2C
	movs r0, #0x00
	b _08085C2E
_08085C24: .4byte 0x0000FFFF
_08085C28: .4byte 0x0203A080
_08085C2C:
	movs r0, #0x01
_08085C2E:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
