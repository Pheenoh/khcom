.syntax unified
	.align 2, 0
	.global func_080D6B7C
	.thumb
	.thumb_func
	.type func_080D6B7C, %function
func_080D6B7C: @ 080D6B7C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r4, #0x10
	movs r6, #0x00
	ldr r7, _080D6C4C @ =0x09EF6668
	movs r0, #0x60
	adds r0, r0, r5
	mov r9, r0
_080D6B96:
	adds r0, r5, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r2, _080D6C50 @ =0x096FDCC8
	lsls r1, r6, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r7
	ldr r2, [r1, #0x00]
	ldr r3, [r5, #0x00]
	ldr r1, [r5, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	adds r1, r6, #0x0
	adds r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	adds r1, r4, #0x0
	bl DrawSprite
	adds r4, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r6, #0x01
	cmp r6, #0x03
	ble _080D6B96
	ldr r0, [r5, #0x44]
	movs r2, #0x00
	ldsh r0, [r0, r2]
	bl func_080D6908
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x13
	movs r6, #0x00
	movs r7, #0x14
	adds r7, r7, r5
	mov r8, r7
	movs r0, #0x08
	adds r0, r0, r5
	mov r10, r0
	adds r5, #0x20
	movs r2, #0x80
	lsls r2, r2, #0x0D
	adds r4, r1, r2
_080D6C06:
	mov r7, r9
	movs r1, #0x00
	ldsh r0, [r7, r1]
	ldm r5!, {r2}
	mov r7, r10
	adds r7, #0x04
	mov r10, r7
	subs r7, #0x04
	ldm r7!, {r3}
	mov r7, r8
	adds r7, #0x04
	mov r8, r7
	subs r7, #0x04
	ldm r7!, {r1}
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	asrs r1, r4, #0x10
	bl DrawSprite
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6C06
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D6C4C: .4byte 0x09EF6668
_080D6C50: .4byte 0x096FDCC8
.syntax divided
