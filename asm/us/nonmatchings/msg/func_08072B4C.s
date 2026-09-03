.syntax unified
	.align 2, 0
	.global func_08072B4C
	.thumb
	.thumb_func
	.type func_08072B4C, %function
func_08072B4C: @ 08072B4C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	mov r12, r3
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	ldr r1, [r4, #0x2C]
	asrs r1, r1, #0x08
	ldr r0, _08072B90 @ =0x02039DC8
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
	beq _08072BB4
	cmp r3, #0x01
	bgt _08072B94
	cmp r3, #0x00
	beq _08072BA0
	b _08072C2A
	.byte 0x00, 0x00
_08072B90: .4byte 0x02039DC8
_08072B94:
	mov r0, r12
	cmp r0, #0x02
	beq _08072BC0
	cmp r0, #0x03
	beq _08072BF4
	b _08072C2A
_08072BA0:
	cmp r7, #0x00
	beq _08072BAC
	ldr r4, _08072BA8 @ =0x00000396
	b _08072BFA
_08072BA8: .4byte 0x00000396
_08072BAC:
	ldr r4, _08072BB0 @ =0x00000397
	b _08072BFA
_08072BB0: .4byte 0x00000397
_08072BB4:
	cmp r7, #0x00
	bne _08072BF8
	ldr r4, _08072BBC @ =0x00000393
	b _08072BFA
_08072BBC: .4byte 0x00000393
_08072BC0:
	ldrh r0, [r4, #0x24]
	cmp r0, #0x4B
	bne _08072BE0
	adds r0, r2, #0x0
	adds r0, #0x6C
	ldrh r1, [r0, #0x00]
	movs r0, #0xAF
	lsls r0, r0, #0x02
	cmp r1, r0
	bls _08072BE0
	cmp r7, #0x00
	bne _08072BF8
	ldr r4, _08072BDC @ =0x00000393
	b _08072BFA
_08072BDC: .4byte 0x00000393
_08072BE0:
	cmp r7, #0x00
	beq _08072BEC
	ldr r4, _08072BE8 @ =0x0000039A
	b _08072BFA
_08072BE8: .4byte 0x0000039A
_08072BEC:
	ldr r4, _08072BF0 @ =0x0000039B
	b _08072BFA
_08072BF0: .4byte 0x0000039B
_08072BF4:
	cmp r7, #0x00
	beq _08072C14
_08072BF8:
	ldr r4, _08072C10 @ =0x00000392
_08072BFA:
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl func_08076110
	b _08072C2A
_08072C10: .4byte 0x00000392
_08072C14:
	ldr r4, _08072C30 @ =0x00000393
	adds r0, r4, #0x0
	bl m4aSongNumStart
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0x0
	bl func_08076110
_08072C2A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08072C30: .4byte 0x00000393
_08072C34:
.syntax divided
