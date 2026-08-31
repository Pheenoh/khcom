.syntax unified
	.align 2, 0
	.global func_080D6A64
	.thumb
	.thumb_func
	.type func_080D6A64, %function
func_080D6A64: @ 080D6A64
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x01C
	adds r6, r0, #0x0
	movs r1, #0x20
	ldr r0, _080D6B10 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	ands r0, r1
	movs r2, #0x03
	cmp r0, #0x00
	bne _080D6A84
	movs r2, #0x02
	movs r1, #0x30
_080D6A84:
	lsls r0, r2, #0x10
	movs r5, #0x00
	mov r8, r0
	movs r0, #0x60
	adds r0, r0, r6
	mov r10, r0
	adds r2, r6, #0x0
	adds r2, #0x20
	str r2, [sp, #0x010]
	adds r3, r6, #0x0
	adds r3, #0x08
	str r3, [sp, #0x014]
	movs r7, #0x14
	adds r7, r7, r6
	mov r9, r7
	mov r0, r8
	cmp r0, #0x00
	ble _080D6AEE
	movs r7, #0xC8
	lsls r7, r7, #0x0F
_080D6AAC:
	mov r2, r10
	movs r3, #0x00
	ldsh r0, [r2, r3]
	lsls r4, r1, #0x10
	asrs r4, r4, #0x10
	ldr r2, _080D6B14 @ =0x09EF6668
	lsls r1, r5, #0x02
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r3, [r6, #0x00]
	ldr r1, [r6, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	lsrs r1, r7, #0x10
	str r1, [sp, #0x00C]
	adds r1, r4, #0x0
	bl DrawSprite
	adds r4, #0x18
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x09
	adds r7, r7, r0
	adds r5, #0x01
	mov r2, r8
	asrs r0, r2, #0x10
	cmp r5, r0
	blt _080D6AAC
_080D6AEE:
	ldr r0, _080D6B10 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080D6B18
	ldr r0, [r6, #0x44]
	movs r3, #0x00
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x13
	movs r7, #0x80
	lsls r7, r7, #0x0E
	adds r0, r0, r7
	b _080D6B2A
	.byte 0x00, 0x00
_080D6B10: .4byte 0x02039BB0
_080D6B14: .4byte 0x09EF6668
_080D6B18:
	ldr r0, [r6, #0x44]
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x13
	movs r3, #0xC0
	lsls r3, r3, #0x0E
	adds r0, r0, r3
_080D6B2A:
	lsrs r1, r0, #0x10
	movs r5, #0x00
	lsls r1, r1, #0x10
	mov r8, r1
	ldr r4, [sp, #0x014]
	ldr r7, [sp, #0x010]
	str r7, [sp, #0x018]
	movs r6, #0x00
_080D6B3A:
	mov r1, r10
	movs r2, #0x00
	ldsh r0, [r1, r2]
	ldr r3, [sp, #0x018]
	ldm r3!, {r2}
	str r3, [sp, #0x018]
	ldm r4!, {r3}
	mov r7, r9
	adds r7, #0x04
	mov r9, r7
	subs r7, #0x04
	ldm r7!, {r1}
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r6, [sp, #0x008]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	mov r7, r8
	asrs r1, r7, #0x10
	bl DrawSprite
	adds r5, #0x01
	cmp r5, #0x02
	ble _080D6B3A
	add sp, #0x01C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
