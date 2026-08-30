.syntax unified
	.align 2, 0
	.global task_btl_sora_2
	.thumb
	.thumb_func
	.type task_btl_sora_2, %function
task_btl_sora_2: @ 0802714C
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r6, #0x40
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	beq _0802716E
	b _080273A6
_0802716E:
	movs r2, #0x92
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x13
	bne _080271B0
	movs r3, #0xB9
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080271A0
	ldr r0, _0802719C @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _08027198
	b _080273A6
_08027198:
	b _080271B0
	.byte 0x00, 0x00
_0802719C: .4byte 0x03007480
_080271A0:
	ldr r0, _080271F0 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x78
	bl __umodsi3
	cmp r0, #0x3B
	bhi _080271B0
	b _080273A6
_080271B0:
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	movs r4, #0xCE
	lsls r4, r4, #0x01
	adds r0, r5, r4
	ldr r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _08027214
	movs r2, #0xD0
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r3, [r0, #0x00]
	cmp r3, r1
	bne _08027214
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080271F8
	ldr r0, _080271F4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _08027264
_080271F0: .4byte 0x03007480
_080271F4: .4byte 0x02039B84
_080271F8:
	ldr r0, _0802720C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	cmp r2, r3
	bne _08027210
	adds r1, r2, #0x0
	movs r0, #0x01
	orrs r7, r0
	b _08027264
	.byte 0x00, 0x00
_0802720C: .4byte 0x02039B84
_08027210:
	negs r1, r2
	b _08027264
_08027214:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08027244
	ldr r0, _08027240 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0xCE
	lsls r3, r3, #0x01
	adds r1, r5, r3
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r1, r0, #0x08
	movs r4, #0xD0
	lsls r4, r4, #0x01
	adds r0, r5, r4
	b _0802725E
	.byte 0x00, 0x00
_08027240: .4byte 0x02039B84
_08027244:
	ldr r0, _08027278 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0xCE
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	negs r1, r0
	movs r3, #0xD0
	lsls r3, r3, #0x01
	adds r0, r5, r3
_0802725E:
	ldr r0, [r0, #0x00]
	muls r0, r2
	asrs r2, r0, #0x08
_08027264:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0802727C
	cmp r1, r2
	bne _0802727C
	movs r4, #0x00
	mov r8, r4
	b _08027290
	.byte 0x00, 0x00
_08027278: .4byte 0x02039B84
_0802727C:
	cmp r2, #0xFF
	bgt _08027286
	movs r0, #0x00
	movs r3, #0x00
	b _0802728A
_08027286:
	movs r0, #0x00
	movs r3, #0x01
_0802728A:
	bl func_08002CB4
	mov r8, r0
_08027290:
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _080272D4
	movs r2, #0xBA
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldrh r2, [r0, #0x00]
	movs r0, #0x01
	adds r3, r0, #0x0
	orrs r3, r2
	mov r9, r3
	adds r0, r6, #0x0
	adds r0, #0x8C
	ldr r1, [r0, #0x00]
	ldr r0, [r6, #0x50]
	cmp r1, r0
	bgt _080272CA
	ldr r0, [r6, #0x10]
	cmp r0, #0x00
	beq _080272EA
	adds r1, r6, #0x0
	adds r1, #0xCC
	movs r0, #0x00
	b _080272F0
_080272CA:
	movs r0, #0x02
	adds r1, r6, #0x0
	adds r1, #0xCC
	orrs r0, r2
	b _080272F0
_080272D4:
	ldr r1, [r6, #0x08]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _08027330 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	movs r1, #0x01
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
_080272EA:
	adds r1, r6, #0x0
	adds r1, #0xCC
	ldr r0, _08027334 @ =0x0000EFFF
_080272F0:
	strh r0, [r1, #0x00]
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	adds r0, r6, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0802733C
	movs r0, #0xAD
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldrh r1, [r2, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r3, #0x0
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r0, [r5, #0x04]
	ldrh r0, [r0, #0x06]
	ldr r1, _08027338 @ =0x08F69BC4
	bl func_08002BAC
	b _0802737E
_08027330: .4byte 0xFFFFEFFC
_08027334: .4byte 0x0000EFFF
_08027338: .4byte 0x08F69BC4
_0802733C:
	movs r0, #0xAD
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldrh r1, [r2, #0x00]
	subs r0, #0x5A
	ands r0, r1
	cmp r0, #0x00
	beq _0802737E
	ldr r0, _0802736C @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08027374
	ldr r0, [r5, #0x04]
	ldrh r0, [r0, #0x06]
	ldr r1, _08027370 @ =0x08F683A4
	bl func_08002BAC
	b _0802737E
	.byte 0x00, 0x00
_0802736C: .4byte 0x0000FEFF
_08027370: .4byte 0x08F683A4
_08027374:
	ldr r0, [r5, #0x04]
	ldrh r0, [r0, #0x06]
	ldr r1, _080273B4 @ =0x096FAC64
	bl func_08002BAC
_0802737E:
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	mov r4, r9
	str r4, [sp, #0x00C]
	bl func_080023E0
	adds r0, r5, #0x0
	adds r0, #0x24
	bl func_08000EE0
_080273A6:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080273B4: .4byte 0x096FAC64
.syntax divided
