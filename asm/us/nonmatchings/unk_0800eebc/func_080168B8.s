.syntax unified
	.align 2, 0
	.global func_080168B8
	.thumb
	.thumb_func
	.type func_080168B8, %function
func_080168B8: @ 080168B8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	mov r8, r0
	mov r9, r1
	adds r7, r2, #0x0
	ldr r0, [sp, #0x02C]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r10, r3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	bne _0801697E
	bl func_08012674
	ldr r5, _08016930 @ =0x02034928
	ldr r0, [r5, #0x00]
	mov r1, r8
	str r1, [r0, #0x10]
	mov r2, r9
	str r2, [r0, #0x14]
	str r7, [r0, #0x18]
	strh r6, [r0, #0x0A]
	strh r4, [r0, #0x26]
	mov r4, sp
	adds r4, #0x06
	str r7, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	mov r2, r8
	mov r3, r9
	bl WorldToScreen
	ldr r0, _08016934 @ =0x09EDAB10
	add r1, sp, #0x004
	movs r3, #0x00
	ldsh r1, [r1, r3]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r10
	cmp r0, #0x00
	beq _08016938
	ldr r1, [r5, #0x00]
	ldr r2, [sp, #0x028]
	str r2, [r1, #0x28]
	movs r0, #0x4C
	str r0, [r1, #0x1C]
	b _08016946
	.byte 0x00, 0x00
_08016930: .4byte 0x02034928
_08016934: .4byte 0x09EDAB10
_08016938:
	ldr r0, [r5, #0x00]
	ldr r3, [sp, #0x028]
	negs r1, r3
	str r1, [r0, #0x28]
	movs r1, #0x4C
	negs r1, r1
	str r1, [r0, #0x1C]
_08016946:
	ldr r4, _08016990 @ =0x02034928
	ldr r1, [r4, #0x00]
	ldr r0, [sp, #0x028]
	str r0, [r1, #0x2C]
	movs r0, #0x4C
	str r0, [r1, #0x20]
	ldr r0, _08016994 @ =0x00000282
	bl m4aSongNumStart
	ldr r1, [r4, #0x00]
	ldr r0, _08016998 @ =0x080167F9
	str r0, [r1, #0x04]
	movs r0, #0x00
	bl func_08006B34
	ldr r0, _0801699C @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	ldr r2, [r4, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_0801697E:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08016990: .4byte 0x02034928
_08016994: .4byte 0x00000282
_08016998: .4byte 0x080167F9
_0801699C: .4byte 0x02039B84
.syntax divided
