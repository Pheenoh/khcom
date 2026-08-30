.syntax unified
	.align 2, 0
	.global func_08085A58
	.thumb
	.thumb_func
	.type func_08085A58, %function
func_08085A58: @ 08085A58
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	bl GetActiveDeck
	adds r6, r0, #0x0
	cmp r5, #0x00
	beq _08085A74
	cmp r5, #0x01
	beq _08085AD0
	b _08085B16
_08085A74:
	movs r3, #0x00
	ldr r0, _08085ABC @ =0x0000FFFF
	mov r9, r0
	ldr r0, _08085AC0 @ =0x08F70AB0
	mov r8, r0
	ldr r7, _08085AC4 @ =0x0203A080
	ldr r0, _08085AC8 @ =0x00000FFF
	mov r12, r0
	ldr r5, _08085ACC @ =0x00008FFF
_08085A86:
	lsls r0, r3, #0x01
	adds r1, r0, r6
	ldrh r0, [r1, #0x00]
	cmp r0, r9
	beq _08085AB0
	lsls r0, r0, #0x01
	adds r0, r0, r7
	ldrh r2, [r0, #0x00]
	mov r0, r12
	ands r0, r2
	movs r1, #0x34
	muls r0, r1
	add r0, r8
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _08085AB0
	adds r0, r5, #0x0
	ands r0, r2
	strh r0, [r4, #0x00]
	adds r4, #0x02
_08085AB0:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x62
	bls _08085A86
	b _08085B16
_08085ABC: .4byte 0x0000FFFF
_08085AC0: .4byte 0x08F70AB0
_08085AC4: .4byte 0x0203A080
_08085AC8: .4byte 0x00000FFF
_08085ACC: .4byte 0x00008FFF
_08085AD0:
	movs r3, #0x00
	ldr r0, _08085B24 @ =0x0000FFFF
	mov r9, r0
	ldr r0, _08085B28 @ =0x08F70AB0
	mov r8, r0
	ldr r7, _08085B2C @ =0x0203A080
	ldr r0, _08085B30 @ =0x00000FFF
	mov r12, r0
	ldr r5, _08085B34 @ =0x00008FFF
_08085AE2:
	lsls r0, r3, #0x01
	adds r1, r0, r6
	ldrh r0, [r1, #0x00]
	cmp r0, r9
	beq _08085B0C
	lsls r0, r0, #0x01
	adds r0, r0, r7
	ldrh r2, [r0, #0x00]
	mov r0, r12
	ands r0, r2
	movs r1, #0x34
	muls r0, r1
	add r0, r8
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _08085B0C
	adds r0, r5, #0x0
	ands r0, r2
	strh r0, [r4, #0x00]
	adds r4, #0x02
_08085B0C:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x62
	bls _08085AE2
_08085B16:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08085B24: .4byte 0x0000FFFF
_08085B28: .4byte 0x08F70AB0
_08085B2C: .4byte 0x0203A080
_08085B30: .4byte 0x00000FFF
_08085B34: .4byte 0x00008FFF
.syntax divided
