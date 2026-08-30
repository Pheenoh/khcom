.syntax unified
	.align 2, 0
	.global func_080658B8
	.thumb
	.thumb_func
	.type func_080658B8, %function
func_080658B8: @ 080658B8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r6, #0x00
	cmp r6, r7
	bcs _08065934
_080658C6:
	ldr r0, _08065904 @ =0x02034A84
	ldr r1, [r0, #0x00]
	lsls r0, r6, #0x01
	adds r0, r0, r6
	lsls r0, r0, #0x03
	adds r3, r0, r1
	ldrb r0, [r3, #0x15]
	cmp r0, #0x01
	bne _0806592A
	ldr r0, [r3, #0x00]
	ldr r1, [r3, #0x04]
	ldrb r4, [r3, #0x14]
	cmp r4, #0x00
	beq _0806590C
	ldr r4, [r3, #0x08]
	cmp r4, #0x00
	beq _0806592A
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _08065908 @ =0x09EEB204
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x10]
	str r3, [sp, #0x000]
	movs r3, #0x00
	str r3, [sp, #0x004]
	adds r3, r4, #0x0
	bl func_08002488
	b _0806592A
_08065904: .4byte 0x02034A84
_08065908: .4byte 0x09EEB204
_0806590C:
	ldr r5, [r3, #0x08]
	cmp r5, #0x00
	beq _0806592A
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, _0806593C @ =0x09EEB204
	ldr r2, [r2, #0x00]
	ldr r3, [r3, #0x0C]
	str r3, [sp, #0x000]
	str r4, [sp, #0x004]
	adds r3, r5, #0x0
	bl func_08002488
_0806592A:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r7
	bcc _080658C6
_08065934:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0806593C: .4byte 0x09EEB204
.syntax divided
