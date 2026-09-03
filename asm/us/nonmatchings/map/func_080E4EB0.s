.syntax unified
	.align 2, 0
	.global func_080E4EB0
	.thumb
	.thumb_func
	.type func_080E4EB0, %function
func_080E4EB0: @ 080E4EB0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r4, r0, #0x0
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	ldr r0, [sp, #0x034]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0x00
	bge _080E4EE2
	adds r0, r2, #0x0
	subs r0, #0x08
	cmp r0, #0x00
	bge _080E4EDE
	subs r0, r2, #0x5
_080E4EDE:
	lsls r0, r0, #0x0E
	b _080E4EE6
_080E4EE2:
	asrs r0, r0, #0x12
	lsls r0, r0, #0x10
_080E4EE6:
	lsrs r2, r0, #0x10
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
	adds r0, r3, #0x0
	cmp r3, #0x00
	bge _080E4EF4
	adds r0, r3, #0x3
_080E4EF4:
	asrs r0, r0, #0x02
	lsls r0, r0, #0x02
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x008]
	lsls r2, r2, #0x10
	str r2, [sp, #0x00C]
	ldr r7, [sp, #0x004]
	ldr r0, [sp, #0x000]
	mov r10, r0
	movs r2, #0x00
	str r2, [sp, #0x010]
	mov r9, r4
_080E4F10:
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x00
	bge _080E4F24
	adds r0, r1, #0x0
	subs r0, #0x08
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	b _080E4F2A
_080E4F24:
	mov r3, r8
	lsrs r0, r3, #0x1F
	adds r0, r1, r0
_080E4F2A:
	lsls r0, r0, #0x0F
	lsrs r2, r0, #0x10
	mov r5, r8
	asrs r0, r5, #0x10
	lsrs r1, r5, #0x1F
	adds r1, r0, r1
	asrs r1, r1, #0x01
	lsls r1, r1, #0x01
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r2, [sp, #0x00C]
	asrs r0, r2, #0x10
	bl func_080E08BC
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _080E4F9C
	lsls r2, r5, #0x10
	ldr r5, [sp, #0x008]
	lsls r3, r5, #0x10
	asrs r1, r3, #0x10
	asrs r0, r2, #0x0B
	adds r0, r0, r1
	ldr r1, [r4, #0x14]
	lsls r5, r0, #0x01
	adds r1, r5, r1
	ldrh r0, [r1, #0x00]
	mov r1, r9
	strh r0, [r1, #0x00]
	ldr r1, [r4, #0x18]
	adds r6, r2, #0x0
	cmp r1, #0x00
	beq _080E4F7C
	adds r0, r5, r1
	ldrh r0, [r0, #0x00]
	mov r2, r10
	strh r0, [r2, #0x00]
	b _080E4F84
_080E4F7C:
	ldr r5, [sp, #0x010]
	ldr r2, [sp, #0x000]
	adds r0, r5, r2
	strh r1, [r0, #0x00]
_080E4F84:
	ldr r2, [r4, #0x1C]
	cmp r2, #0x00
	beq _080E4F98
	asrs r0, r3, #0x10
	asrs r1, r6, #0x0B
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	b _080E4FBC
_080E4F98:
	strh r2, [r7, #0x00]
	b _080E4FBE
_080E4F9C:
	mov r3, r9
	strh r4, [r3, #0x00]
	ldr r0, _080E4FEC @ =0x02034F34
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x1C]
	movs r5, #0xD0
	lsls r5, r5, #0x03
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	mov r2, r10
	strh r0, [r2, #0x00]
	ldr r0, [r1, #0x20]
	movs r3, #0x88
	lsls r3, r3, #0x02
	adds r0, r0, r3
	ldrh r0, [r0, #0x00]
_080E4FBC:
	strh r0, [r7, #0x00]
_080E4FBE:
	movs r0, #0x80
	lsls r0, r0, #0x09
	add r0, r8
	lsrs r1, r0, #0x10
	adds r7, #0x02
	movs r5, #0x02
	add r10, r5
	ldr r0, [sp, #0x010]
	adds r0, #0x02
	str r0, [sp, #0x010]
	add r9, r5
	ldr r0, [sp, #0x004]
	adds r0, #0x3E
	cmp r7, r0
	ble _080E4F10
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E4FEC: .4byte 0x02034F34
.syntax divided
