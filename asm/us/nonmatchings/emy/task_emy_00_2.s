.syntax unified
	.align 2, 0
	.global task_emy_00_2
	.thumb
	.thumb_func
	.type task_emy_00_2, %function
task_emy_00_2: @ 08037120
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08037138
	b _080372C6
_08037138:
	adds r5, r6, #0x0
	adds r5, #0x3C
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	movs r2, #0xB1
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	movs r3, #0xC0
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r3, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r3, r0
	bne _080371B4
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08037194
	ldr r0, _08037190 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _080371F6
_08037190: .4byte 0x02039B84
_08037194:
	ldr r0, _080371AC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	cmp r2, r3
	bne _080371B0
	adds r2, r3, #0x0
	adds r1, r2, #0x0
	movs r0, #0x01
	mov r7, r8
	orrs r7, r0
	mov r8, r7
	b _080371F6
_080371AC: .4byte 0x02039B84
_080371B0:
	negs r1, r2
	b _080371F6
_080371B4:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080371DC
	ldr r0, _080371D8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r1, r0, #0x08
	b _080371F0
_080371D8: .4byte 0x02039B84
_080371DC:
	ldr r0, _08037208 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r7, #0xBE
	lsls r7, r7, #0x01
	adds r1, r6, r7
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	negs r1, r0
_080371F0:
	adds r0, r2, #0x0
	muls r0, r3
	asrs r2, r0, #0x08
_080371F6:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0803720C
	cmp r1, r2
	bne _0803720C
	movs r7, #0x00
	b _08037220
	.byte 0x00, 0x00
_08037208: .4byte 0x02039B84
_0803720C:
	cmp r2, #0xFF
	bgt _08037216
	movs r0, #0x00
	movs r3, #0x00
	b _0803721A
_08037216:
	movs r0, #0x00
	movs r3, #0x01
_0803721A:
	bl func_08002CB4
	adds r7, r0, #0x0
_08037220:
	adds r0, r5, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0803725C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x08]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _08037258 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	b _08037282
	.byte 0x00, 0x00
_08037258: .4byte 0xFFFFEFFC
_0803725C:
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _08037290
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r4, _0803728C @ =0x0000FFFF
_08037282:
	str r4, [sp, #0x00C]
	bl func_080023E0
	b _080372BE
	.byte 0x00, 0x00
_0803728C: .4byte 0x0000FFFF
_08037290:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _080372D4 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
_080372BE:
	adds r0, r6, #0x0
	adds r0, #0x28
	bl func_08000EE0
_080372C6:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080372D4: .4byte 0xFFFFEFFC
.syntax divided
