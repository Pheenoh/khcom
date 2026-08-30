.syntax unified
	.align 2, 0
	.global func_08003CD4
	.thumb
	.thumb_func
	.type func_08003CD4, %function
func_08003CD4: @ 08003CD4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	mov r10, r1
	mov r9, r3
	movs r1, #0x00
	ldsh r3, [r0, r1]
	ldr r4, [r0, #0x04]
	str r4, [sp, #0x000]
	ldr r0, [r0, #0x08]
	str r0, [sp, #0x004]
	movs r1, #0x00
	mov r0, r9
	str r1, [r0, #0x00]
	lsls r0, r3, #0x02
	add r0, r9
	subs r0, #0x04
	str r1, [r0, #0x00]
	movs r7, #0x00
	subs r0, r3, #0x1
	cmp r7, r0
	bge _08003D3C
	adds r6, r2, #0x0
	ldr r4, [sp, #0x004]
	mov r5, r10
	ldr r1, [sp, #0x000]
	mov r8, r1
_08003D10:
	ldr r1, [r5, #0x04]
	ldm r5!, {r0}
	subs r1, r1, r0
	mov r2, r8
	adds r2, #0x04
	mov r8, r2
	subs r2, #0x04
	stm r2!, {r1}
	ldr r0, [r6, #0x04]
	ldm r6!, {r2}
	subs r0, r0, r2
	lsls r0, r0, #0x08
	str r3, [sp, #0x010]
	bl __divsi3
	str r0, [r4, #0x04]
	adds r4, #0x04
	adds r7, #0x01
	ldr r3, [sp, #0x010]
	subs r0, r3, #0x1
	cmp r7, r0
	blt _08003D10
_08003D3C:
	ldr r4, [sp, #0x004]
	ldr r1, [r4, #0x08]
	ldr r0, [r4, #0x04]
	subs r1, r1, r0
	ldr r0, [sp, #0x000]
	ldr r2, [r0, #0x00]
	mov r4, r9
	ldr r0, [r4, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	subs r1, r1, r0
	str r1, [r4, #0x04]
	mov r1, r10
	ldr r0, [r1, #0x08]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x01
	ldr r2, [sp, #0x004]
	str r0, [r2, #0x04]
	lsls r4, r3, #0x02
	str r4, [sp, #0x00C]
	subs r0, r3, #0x2
	str r0, [sp, #0x008]
	cmp r0, #0x01
	ble _08003DC2
	ldr r1, [sp, #0x000]
	adds r1, #0x04
	mov r8, r1
	mov r6, r10
	adds r6, #0x04
	mov r5, r9
	adds r5, #0x04
	adds r4, r2, #0x0
	adds r4, #0x04
	subs r7, r3, #0x3
_08003D82:
	mov r2, r8
	ldr r0, [r2, #0x00]
	lsls r0, r0, #0x08
	ldr r1, [r4, #0x00]
	bl __divsi3
	ldr r2, [r4, #0x08]
	ldr r1, [r4, #0x04]
	subs r2, r2, r1
	ldr r1, [r5, #0x00]
	muls r1, r0
	asrs r1, r1, #0x08
	subs r2, r2, r1
	str r2, [r5, #0x04]
	ldr r1, [r6, #0x08]
	ldm r6!, {r2}
	subs r1, r1, r2
	lsls r1, r1, #0x01
	mov r3, r8
	adds r3, #0x04
	mov r8, r3
	subs r3, #0x04
	ldm r3!, {r2}
	muls r0, r2
	asrs r0, r0, #0x08
	subs r1, r1, r0
	str r1, [r4, #0x04]
	adds r5, #0x04
	adds r4, #0x04
	subs r7, #0x01
	cmp r7, #0x00
	bne _08003D82
_08003DC2:
	ldr r1, [sp, #0x00C]
	add r1, r9
	adds r3, r1, #0x0
	subs r3, #0x08
	ldr r4, [sp, #0x00C]
	ldr r2, [sp, #0x000]
	adds r0, r4, r2
	subs r0, #0x08
	subs r1, #0x04
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	adds r1, r2, #0x0
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r3, #0x00]
	subs r0, r0, r1
	str r0, [r3, #0x00]
	ldr r7, [sp, #0x008]
	cmp r7, #0x00
	ble _08003E1A
	lsls r0, r7, #0x02
	mov r3, r9
	adds r4, r0, r3
	ldr r1, [sp, #0x004]
	adds r6, r0, r1
	ldr r2, [sp, #0x000]
	adds r5, r0, r2
_08003DF8:
	ldr r1, [r5, #0x00]
	ldr r0, [r4, #0x04]
	muls r1, r0
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x08
	ldr r1, [r6, #0x00]
	bl __divsi3
	str r0, [r4, #0x00]
	subs r4, #0x04
	subs r6, #0x04
	subs r5, #0x04
	subs r7, #0x01
	cmp r7, #0x00
	bgt _08003DF8
_08003E1A:
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
