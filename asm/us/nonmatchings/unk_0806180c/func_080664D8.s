.syntax unified
	.align 2, 0
	.global func_080664D8
	.thumb
	.thumb_func
	.type func_080664D8, %function
func_080664D8: @ 080664D8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r5, r2, #0x0
	str r3, [sp, #0x010]
	ldr r2, [sp, #0x034]
	ldr r3, [sp, #0x038]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r10, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	mov r9, r4
	lsls r1, r1, #0x10
	ldr r0, _08066520 @ =0xFFFE0000
	adds r1, r1, r0
	lsrs r6, r1, #0x10
	movs r7, #0x00
	cmp r7, r8
	bcs _08066576
_0806650C:
	ldr r3, [r5, #0x00]
	cmp r3, #0x00
	bne _08066524
	lsls r0, r6, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x0C
	adds r0, r0, r1
	lsrs r6, r0, #0x10
	mov r4, r9
	b _0806656A
_08066520: .4byte 0xFFFE0000
_08066524:
	movs r0, #0x05
	ldsb r0, [r5, r0]
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	beq _08066560
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0806655C @ =0x09EEB204
	ldr r2, [r0, #0x00]
	ldr r0, [sp, #0x010]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	mov r0, r10
	str r0, [sp, #0x00C]
	adds r0, r4, #0x0
	bl DrawSprite
	movs r0, #0x05
	ldsb r0, [r5, r0]
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	b _0806656A
_0806655C: .4byte 0x09EEB204
_08066560:
	lsls r0, r4, #0x10
	movs r1, #0xC0
	lsls r1, r1, #0x0A
	adds r0, r0, r1
	lsrs r4, r0, #0x10
_0806656A:
	adds r5, #0x08
	adds r0, r7, #0x1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, r8
	bcc _0806650C
_08066576:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
