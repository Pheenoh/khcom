.syntax unified
	.align 2, 0
	.global func_08072918
	.thumb
	.thumb_func
	.type func_08072918, %function
func_08072918: @ 08072918
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	mov r12, r3
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	ldr r1, [r4, #0x2C]
	asrs r1, r1, #0x08
	ldr r0, _0807295C @ =0x02039DC8
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x58]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r1, [r4, #0x30]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x34]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, [r2, #0x5C]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r3, #0x01
	beq _08072980
	cmp r3, #0x01
	bgt _08072960
	cmp r3, #0x00
	beq _0807296C
	b _08072A58
	.byte 0x00, 0x00
_0807295C: .4byte 0x02039DC8
_08072960:
	mov r0, r12
	cmp r0, #0x02
	beq _0807298C
	cmp r0, #0x03
	beq _08072A24
	b _08072A58
_0807296C:
	cmp r7, #0x00
	beq _08072976
	movs r4, #0xE1
	lsls r4, r4, #0x02
	b _08072A2C
_08072976:
	ldr r4, _0807297C @ =0x00000385
	b _08072A2C
	.byte 0x00, 0x00
_0807297C: .4byte 0x00000385
_08072980:
	cmp r7, #0x00
	bne _08072A28
	ldr r4, _08072988 @ =0x00000389
	b _08072A2C
_08072988: .4byte 0x00000389
_0807298C:
	ldrh r3, [r4, #0x24]
	cmp r3, #0x4B
	bne _080729A0
	adds r0, r2, #0x0
	adds r0, #0x6C
	ldrh r1, [r0, #0x00]
	movs r0, #0xAF
	lsls r0, r0, #0x02
	cmp r1, r0
	bhi _080729AE
_080729A0:
	cmp r3, #0x36
	bne _08072A10
	adds r0, r2, #0x0
	adds r0, #0x6C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x4F
	bhi _08072A10
_080729AE:
	cmp r7, #0x00
	beq _080729CC
	movs r4, #0xE2
	lsls r4, r4, #0x02
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r6, r6, #0x10
	asrs r1, r6, #0x10
	lsls r5, r5, #0x10
	asrs r2, r5, #0x10
	adds r0, r4, #0x0
	bl func_08076110
	b _080729E2
_080729CC:
	ldr r4, _080729F8 @ =0x00000389
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r6, r6, #0x10
	asrs r1, r6, #0x10
	lsls r5, r5, #0x10
	asrs r2, r5, #0x10
	adds r0, r4, #0x0
	bl func_08076110
_080729E2:
	cmp r7, #0x00
	beq _080729FC
	movs r4, #0xE2
	lsls r4, r4, #0x02
	adds r0, r4, #0x0
	bl m4aSongNumStart
	asrs r1, r6, #0x10
	asrs r2, r5, #0x10
	b _08072A3A
	.byte 0x00, 0x00
_080729F8: .4byte 0x00000389
_080729FC:
	ldr r4, _08072A0C @ =0x00000389
	adds r0, r4, #0x0
	bl m4aSongNumStart
	asrs r1, r6, #0x10
	asrs r2, r5, #0x10
	b _08072A3A
	.byte 0x00, 0x00
_08072A0C: .4byte 0x00000389
_08072A10:
	cmp r7, #0x00
	beq _08072A1A
	movs r4, #0xE3
	lsls r4, r4, #0x02
	b _08072A2C
_08072A1A:
	ldr r4, _08072A20 @ =0x0000038D
	b _08072A2C
	.byte 0x00, 0x00
_08072A20: .4byte 0x0000038D
_08072A24:
	cmp r7, #0x00
	beq _08072A42
_08072A28:
	movs r4, #0xE2
	lsls r4, r4, #0x02
_08072A2C:
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
_08072A3A:
	adds r0, r4, #0x0
	bl func_08076110
	b _08072A58
_08072A42:
	ldr r4, _08072A60 @ =0x00000389
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl func_08076110
_08072A58:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08072A60: .4byte 0x00000389
.syntax divided
