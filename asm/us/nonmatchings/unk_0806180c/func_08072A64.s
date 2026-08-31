.syntax unified
	.align 2, 0
	.global func_08072A64
	.thumb
	.thumb_func
	.type func_08072A64, %function
func_08072A64: @ 08072A64
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	mov r12, r3
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	ldr r1, [r4, #0x2C]
	asrs r1, r1, #0x08
	ldr r0, _08072AA8 @ =0x02039DC8
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x58]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r1, [r4, #0x30]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x34]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, [r2, #0x5C]
	asrs r0, r0, #0x08
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r3, #0x01
	beq _08072ACC
	cmp r3, #0x01
	bgt _08072AAC
	cmp r3, #0x00
	beq _08072AB8
	b _08072B40
	.byte 0x00, 0x00
_08072AA8: .4byte 0x02039DC8
_08072AAC:
	mov r0, r12
	cmp r0, #0x02
	beq _08072AD8
	cmp r0, #0x03
	beq _08072B0C
	b _08072B40
_08072AB8:
	cmp r7, #0x00
	beq _08072AC2
	movs r4, #0xE5
	lsls r4, r4, #0x02
	b _08072B14
_08072AC2:
	ldr r4, _08072AC8 @ =0x00000395
	b _08072B14
	.byte 0x00, 0x00
_08072AC8: .4byte 0x00000395
_08072ACC:
	cmp r7, #0x00
	bne _08072B10
	ldr r4, _08072AD4 @ =0x00000391
	b _08072B14
_08072AD4: .4byte 0x00000391
_08072AD8:
	ldrh r0, [r4, #0x24]
	cmp r0, #0x4B
	bne _08072AF8
	adds r0, r2, #0x0
	adds r0, #0x6C
	ldrh r1, [r0, #0x00]
	movs r0, #0xAF
	lsls r0, r0, #0x02
	cmp r1, r0
	bls _08072AF8
	cmp r7, #0x00
	bne _08072B10
	ldr r4, _08072AF4 @ =0x00000391
	b _08072B14
_08072AF4: .4byte 0x00000391
_08072AF8:
	cmp r7, #0x00
	beq _08072B02
	movs r4, #0xE6
	lsls r4, r4, #0x02
	b _08072B14
_08072B02:
	ldr r4, _08072B08 @ =0x00000399
	b _08072B14
	.byte 0x00, 0x00
_08072B08: .4byte 0x00000399
_08072B0C:
	cmp r7, #0x00
	beq _08072B2A
_08072B10:
	movs r4, #0xE4
	lsls r4, r4, #0x02
_08072B14:
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl func_08076110
	b _08072B40
_08072B2A:
	ldr r4, _08072B48 @ =0x00000391
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl func_08076110
_08072B40:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08072B48: .4byte 0x00000391
.syntax divided
