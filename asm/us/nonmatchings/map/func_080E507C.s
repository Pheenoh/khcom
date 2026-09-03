.syntax unified
	.align 2, 0
	.global func_080E507C
	.thumb
	.thumb_func
	.type func_080E507C, %function
func_080E507C: @ 080E507C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	adds r4, r0, #0x0
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	ldr r0, [sp, #0x038]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0x00
	bge _080E50AA
	adds r0, r1, #0x0
	subs r0, #0x08
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	b _080E50AE
_080E50AA:
	lsrs r0, r0, #0x1F
	adds r0, r1, r0
_080E50AE:
	lsls r0, r0, #0x0F
	lsrs r0, r0, #0x10
	str r0, [sp, #0x008]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	lsrs r0, r0, #0x1F
	adds r0, r1, r0
	asrs r0, r0, #0x01
	lsls r0, r0, #0x01
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r7, [sp, #0x004]
	ldr r0, [sp, #0x000]
	mov r10, r0
	movs r2, #0x00
	str r2, [sp, #0x014]
	mov r9, r4
	lsrs r4, r1, #0x10
	str r4, [sp, #0x00C]
	asrs r1, r1, #0x0B
	str r1, [sp, #0x010]
_080E50D8:
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r1, #0x00
	bge _080E50F0
	adds r0, r1, #0x0
	subs r0, #0x08
	cmp r0, #0x00
	bge _080E50EC
	subs r0, r1, #0x5
_080E50EC:
	lsls r0, r0, #0x0E
	b _080E50F6
_080E50F0:
	mov r1, r8
	asrs r0, r1, #0x12
	lsls r0, r0, #0x10
_080E50F6:
	lsrs r2, r0, #0x10
	mov r4, r8
	asrs r1, r4, #0x10
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _080E5104
	adds r0, r1, #0x3
_080E5104:
	asrs r0, r0, #0x02
	lsls r0, r0, #0x02
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #0x008]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _080E516C
	lsls r2, r4, #0x10
	asrs r0, r2, #0x10
	ldr r4, [sp, #0x010]
	adds r0, r4, r0
	ldr r1, [r3, #0x14]
	lsls r4, r0, #0x01
	adds r1, r4, r1
	ldrh r0, [r1, #0x00]
	mov r1, r9
	strh r0, [r1, #0x00]
	ldr r1, [r3, #0x18]
	ldr r0, [sp, #0x00C]
	lsls r6, r0, #0x10
	adds r5, r2, #0x0
	cmp r1, #0x00
	beq _080E514C
	adds r0, r4, r1
	ldrh r0, [r0, #0x00]
	mov r1, r10
	strh r0, [r1, #0x00]
	b _080E5154
_080E514C:
	ldr r2, [sp, #0x014]
	ldr r4, [sp, #0x000]
	adds r0, r2, r4
	strh r1, [r0, #0x00]
_080E5154:
	ldr r2, [r3, #0x1C]
	cmp r2, #0x00
	beq _080E5168
	asrs r0, r5, #0x10
	asrs r1, r6, #0x0B
	adds r1, r1, r0
	lsls r1, r1, #0x01
	adds r1, r1, r2
	ldrh r0, [r1, #0x00]
	b _080E518C
_080E5168:
	strh r2, [r7, #0x00]
	b _080E518E
_080E516C:
	mov r0, r9
	strh r3, [r0, #0x00]
	ldr r0, _080E51BC @ =0x02034F34
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x1C]
	movs r2, #0xD0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	ldrh r0, [r0, #0x00]
	mov r4, r10
	strh r0, [r4, #0x00]
	ldr r0, [r1, #0x20]
	movs r1, #0x88
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
_080E518C:
	strh r0, [r7, #0x00]
_080E518E:
	movs r0, #0x80
	lsls r0, r0, #0x09
	add r0, r8
	lsrs r3, r0, #0x10
	adds r7, #0x02
	movs r2, #0x02
	add r10, r2
	ldr r4, [sp, #0x014]
	adds r4, #0x02
	str r4, [sp, #0x014]
	add r9, r2
	ldr r0, [sp, #0x004]
	adds r0, #0x3E
	cmp r7, r0
	ble _080E50D8
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080E51BC: .4byte 0x02034F34
.syntax divided
