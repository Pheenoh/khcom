.syntax unified
	.align 2, 0
	.global func_0801D288
	.thumb
	.thumb_func
	.type func_0801D288, %function
func_0801D288: @ 0801D288
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0801D2E4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r7, [r0, #0x7C]
	movs r1, #0x80
	lsls r1, r1, #0x0B
	mov r8, r1
	movs r1, #0x00
	str r1, [r0, #0x78]
	adds r0, #0x80
	bl func_08000C8C
	adds r4, r0, #0x0
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801D2B8
	b _0801D470
_0801D2B8:
	cmp r4, #0x00
	beq _0801D33E
_0801D2BC:
	ldr r6, [r7, #0x04]
	ldr r5, [r4, #0x04]
	cmp r6, r5
	blt _0801D330
	subs r1, r6, r5
	movs r0, #0x96
	lsls r0, r0, #0x08
	cmp r1, r0
	bgt _0801D330
	ldr r0, [r7, #0x08]
	ldr r1, [r4, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D2E8
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r2, r0
	bgt _0801D330
	b _0801D2F2
	.byte 0x00, 0x00
_0801D2E4: .4byte 0x02039B84
_0801D2E8:
	subs r1, r1, r0
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0801D330
_0801D2F2:
	ldr r0, [r7, #0x0C]
	ldr r1, [r4, #0x0C]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D306
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r2, r0
	bgt _0801D330
	b _0801D310
_0801D306:
	subs r1, r1, r0
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r1, r0
	bgt _0801D330
_0801D310:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	ldr r3, _0801D38C @ =0x00000000
	ldr r2, _0801D388 @ =0x01000000
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801D330
	subs r1, r6, r5
	cmp r1, r8
	bge _0801D330
	ldr r0, _0801D390 @ =0x02039B84
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x78]
	mov r8, r1
_0801D330:
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801D2BC
_0801D33E:
	ldr r0, _0801D390 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	cmp r0, #0x00
	beq _0801D34A
	b _0801D518
_0801D34A:
	movs r0, #0x80
	lsls r0, r0, #0x0B
	mov r8, r0
	adds r0, r1, #0x0
	adds r0, #0x80
	bl func_08000C8C
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801D360
	b _0801D518
_0801D360:
	ldr r6, [r7, #0x04]
	ldr r5, [r4, #0x04]
	cmp r6, r5
	bgt _0801D3DC
	subs r1, r5, r6
	movs r0, #0xB4
	lsls r0, r0, #0x07
	cmp r1, r0
	bgt _0801D3DC
	ldr r0, [r7, #0x08]
	ldr r1, [r4, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D394
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r2, r0
	bgt _0801D3DC
	b _0801D39E
	.byte 0x00, 0x00
_0801D388: .4byte 0x01000000
_0801D38C: .4byte 0x00000000
_0801D390: .4byte 0x02039B84
_0801D394:
	subs r1, r1, r0
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0801D3DC
_0801D39E:
	ldr r0, [r7, #0x0C]
	ldr r1, [r4, #0x0C]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D3B2
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r2, r0
	bgt _0801D3DC
	b _0801D3BC
_0801D3B2:
	subs r1, r1, r0
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r1, r0
	bgt _0801D3DC
_0801D3BC:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	ldr r3, _0801D3F0 @ =0x00000000
	ldr r2, _0801D3EC @ =0x01000000
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801D3DC
	subs r1, r5, r6
	cmp r1, r8
	bge _0801D3DC
	ldr r0, _0801D3F4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x78]
	mov r8, r1
_0801D3DC:
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801D360
	b _0801D518
_0801D3EC: .4byte 0x01000000
_0801D3F0: .4byte 0x00000000
_0801D3F4: .4byte 0x02039B84
_0801D3F8:
	ldr r6, [r7, #0x04]
	ldr r5, [r4, #0x04]
	cmp r6, r5
	bgt _0801D466
	subs r1, r5, r6
	movs r0, #0x96
	lsls r0, r0, #0x08
	cmp r1, r0
	bgt _0801D466
	ldr r0, [r7, #0x08]
	ldr r1, [r4, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D41E
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r2, r0
	bgt _0801D466
	b _0801D428
_0801D41E:
	subs r1, r1, r0
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0801D466
_0801D428:
	ldr r0, [r7, #0x0C]
	ldr r1, [r4, #0x0C]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D43C
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r2, r0
	bgt _0801D466
	b _0801D446
_0801D43C:
	subs r1, r1, r0
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r1, r0
	bgt _0801D466
_0801D446:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	ldr r3, _0801D494 @ =0x00000000
	ldr r2, _0801D490 @ =0x01000000
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801D466
	subs r1, r5, r6
	cmp r1, r8
	bge _0801D466
	ldr r0, _0801D498 @ =0x02039B84
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x78]
	mov r8, r1
_0801D466:
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r4, r0, #0x0
_0801D470:
	cmp r4, #0x00
	bne _0801D3F8
	ldr r0, _0801D498 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x78]
	cmp r0, #0x00
	bne _0801D518
	movs r0, #0x80
	lsls r0, r0, #0x0B
	mov r8, r0
	adds r0, r1, #0x0
	adds r0, #0x80
	bl func_08000C8C
	b _0801D512
	.byte 0x00, 0x00
_0801D490: .4byte 0x01000000
_0801D494: .4byte 0x00000000
_0801D498: .4byte 0x02039B84
_0801D49C:
	ldr r6, [r7, #0x04]
	ldr r5, [r4, #0x04]
	cmp r6, r5
	blt _0801D50A
	subs r1, r6, r5
	movs r0, #0xB4
	lsls r0, r0, #0x07
	cmp r1, r0
	bgt _0801D50A
	ldr r0, [r7, #0x08]
	ldr r1, [r4, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D4C2
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r2, r0
	bgt _0801D50A
	b _0801D4CC
_0801D4C2:
	subs r1, r1, r0
	movs r0, #0xC0
	lsls r0, r0, #0x05
	cmp r1, r0
	bgt _0801D50A
_0801D4CC:
	ldr r0, [r7, #0x0C]
	ldr r1, [r4, #0x0C]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _0801D4E0
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r2, r0
	bgt _0801D50A
	b _0801D4EA
_0801D4E0:
	subs r1, r1, r0
	movs r0, #0xC8
	lsls r0, r0, #0x07
	cmp r1, r0
	bgt _0801D50A
_0801D4EA:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	ldr r3, _0801D528 @ =0x00000000
	ldr r2, _0801D524 @ =0x01000000
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801D50A
	subs r1, r6, r5
	cmp r1, r8
	bge _0801D50A
	ldr r0, _0801D52C @ =0x02039B84
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x78]
	mov r8, r1
_0801D50A:
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl func_08000CD4
_0801D512:
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0801D49C
_0801D518:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801D524: .4byte 0x01000000
_0801D528: .4byte 0x00000000
_0801D52C: .4byte 0x02039B84
.syntax divided
