.syntax unified
	.align 2, 0
	.global task_hum_hook_moon_2
	.thumb
	.thumb_func
	.type task_hum_hook_moon_2, %function
task_hum_hook_moon_2: @ 0804C950
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x010
	adds r7, r0, #0x0
	ldr r0, _0804CA78 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x00]
	asrs r1, r1, #0x09
	movs r0, #0xF8
	subs r0, r0, r1
	ldr r2, [r2, #0x04]
	asrs r2, r2, #0x09
	movs r1, #0xD0
	subs r1, r1, r2
	ldr r3, _0804CA7C @ =0x08121400
	ldrb r2, [r7, #0x08]
	lsls r2, r2, #0x01
	adds r2, r2, r3
	movs r3, #0x00
	ldsh r2, [r2, r3]
	asrs r2, r2, #0x05
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	mov r10, r2
	movs r3, #0x80
	lsls r3, r3, #0x0F
	adds r0, r0, r3
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r2, r1, #0x10
	mov r9, r2
	ldr r3, _0804CA80 @ =0xFFE40000
	adds r1, r1, r3
	asrs r1, r1, #0x10
	ldr r2, _0804CA84 @ =0x08B5A854
	ldr r3, [r7, #0x00]
	ldr r4, [r7, #0x04]
	str r4, [sp, #0x000]
	movs r6, #0x00
	str r6, [sp, #0x004]
	movs r5, #0xC0
	lsls r5, r5, #0x04
	str r5, [sp, #0x008]
	ldr r4, _0804CA88 @ =0x0000FFFF
	str r4, [sp, #0x00C]
	bl DrawSprite
	mov r0, r10
	subs r0, #0x90
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, _0804CA8C @ =0x08B5A85E
	mov r8, r1
	ldr r3, [r7, #0x00]
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	subs r4, #0x01
	str r4, [sp, #0x00C]
	mov r1, r9
	mov r2, r8
	bl DrawSprite
	mov r0, r10
	subs r0, #0x58
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, [r7, #0x00]
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	mov r1, r9
	mov r2, r8
	bl DrawSprite
	mov r0, r10
	subs r0, #0x20
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, [r7, #0x00]
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	mov r1, r9
	mov r2, r8
	bl DrawSprite
	mov r0, r10
	adds r0, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, [r7, #0x00]
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	mov r1, r9
	mov r2, r8
	bl DrawSprite
	mov r0, r10
	adds r0, #0x50
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, [r7, #0x00]
	ldr r1, [r7, #0x04]
	str r1, [sp, #0x000]
	str r6, [sp, #0x004]
	str r5, [sp, #0x008]
	str r4, [sp, #0x00C]
	mov r1, r9
	mov r2, r8
	bl DrawSprite
	bl func_08006390
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, r4, #0x0
	cmp r4, #0x00
	beq _0804CB04
	bl _08006338
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0xF8
	lsls r0, r0, #0x02
	cmp r1, r0
	beq _0804CAF4
	cmp r1, r0
	bgt _0804CA90
	cmp r1, #0x00
	beq _0804CAA4
	cmp r1, #0x1F
	beq _0804CACE
	b _0804CAFE
_0804CA78: .4byte 0x02039B84
_0804CA7C: .4byte 0x08121400
_0804CA80: .4byte 0xFFE40000
_0804CA84: .4byte 0x08B5A854
_0804CA88: .4byte 0x0000FFFF
_0804CA8C: .4byte 0x08B5A85E
_0804CA90:
	movs r0, #0xF8
	lsls r0, r0, #0x07
	cmp r1, r0
	beq _0804CADA
	ldr r0, _0804CAA0 @ =0x00007FFF
	cmp r1, r0
	beq _0804CAB4
	b _0804CAFE
_0804CAA0: .4byte 0x00007FFF
_0804CAA4:
	movs r0, #0x09
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, #0x00
	bge _0804CAEA
	movs r2, #0x00
	b _0804CAEA
_0804CAB4:
	adds r0, r4, #0x0
	adds r0, #0x09
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1F
	ble _0804CAC4
	movs r2, #0x1F
_0804CAC4:
	adds r0, r4, #0x0
	adds r1, r4, #0x0
	bl func_08005778
	b _0804CAFE
_0804CACE:
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x09
	bl func_08005778
	b _0804CAFE
_0804CADA:
	adds r0, r4, #0x0
	adds r0, #0x09
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1F
	ble _0804CAEA
	movs r2, #0x1F
_0804CAEA:
	movs r0, #0x00
	movs r1, #0x00
	bl func_08005778
	b _0804CAFE
_0804CAF4:
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r2, #0x09
	bl func_08005778
_0804CAFE:
	movs r0, #0x01
	strb r0, [r7, #0x0A]
	b _0804CB16
_0804CB04:
	ldrb r0, [r7, #0x0A]
	cmp r0, #0x00
	beq _0804CB16
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x09
	bl func_08005778
	strb r5, [r7, #0x0A]
_0804CB16:
	add sp, #0x010
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
