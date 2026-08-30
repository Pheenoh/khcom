.syntax unified
	.align 2, 0
	.global func_080D576C
	.thumb
	.thumb_func
	.type func_080D576C, %function
func_080D576C: @ 080D576C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov r10, r4
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	str r5, [sp, #0x008]
	bl func_080DED98
	mov r8, r0
	ldr r6, _080D589C @ =0x0203C4B4
	ldr r0, [r6, #0x00]
	lsls r1, r7, #0x02
	mov r9, r1
	adds r0, #0x14
	add r0, r9
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D588A
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xB6
	ldrh r0, [r1, #0x00]
	cmp r0, r4
	bcs _080D57B6
	strh r4, [r1, #0x00]
_080D57B6:
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xB4
	ldrh r0, [r1, #0x00]
	cmp r0, r4
	bls _080D57C4
	strh r4, [r1, #0x00]
_080D57C4:
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xBA
	ldrh r0, [r1, #0x00]
	cmp r0, r5
	bcs _080D57D2
	strh r5, [r1, #0x00]
_080D57D2:
	ldr r0, [r6, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xB8
	ldrh r0, [r1, #0x00]
	cmp r0, r5
	bls _080D57E0
	strh r5, [r1, #0x00]
_080D57E0:
	lsls r0, r5, #0x10
	ldr r2, _080D58A0 @ =0x0000FFFF
	orrs r0, r4
	str r0, [sp, #0x000]
	ldr r1, _080D58A4 @ =0xFFFFFF00
	ldr r0, [sp, #0x004]
	ands r0, r1
	orrs r0, r7
	ands r0, r2
	str r0, [sp, #0x004]
	ldr r0, [r6, #0x00]
	ldr r1, _080D58A8 @ =0x09EF4DC0
	mov r2, sp
	bl func_08000E14
	ldr r1, [r6, #0x00]
	adds r1, #0x14
	add r1, r9
	str r0, [r1, #0x00]
	mov r0, r8
	ldrb r3, [r0, #0x00]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D5826
	adds r1, r4, #0x1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	subs r2, r5, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D5826:
	mov r1, r8
	ldrb r3, [r1, #0x01]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D5846
	subs r1, r4, #0x1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r5, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D5846:
	mov r0, r8
	ldrb r3, [r0, #0x02]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D5866
	adds r1, r4, #0x1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r5, #0x1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D5866:
	mov r1, r8
	ldrb r3, [r1, #0x03]
	adds r0, r3, #0x3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _080D588A
	mov r1, r10
	subs r1, #0x01
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [sp, #0x008]
	subs r2, #0x01
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r3, #0x0
	bl func_080D576C
_080D588A:
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D589C: .4byte 0x0203C4B4
_080D58A0: .4byte 0x0000FFFF
_080D58A4: .4byte 0xFFFFFF00
_080D58A8: .4byte 0x09EF4DC0
.syntax divided
