.syntax unified
	.align 2, 0
	.global task_title_lumichange_1
	.thumb
	.thumb_func
	.type task_title_lumichange_1, %function
task_title_lumichange_1: @ 080D6ED4
	push {r4, r5, lr}
	add sp, #-0x008
	bl func_08007E50
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r1, _080D6F08 @ =0x096FDCE8
	mov r0, sp
	movs r2, #0x06
	bl memcpy
	bl func_08001390
	movs r1, #0xC0
	lsls r1, r1, #0x02
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	beq _080D6F0C
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r1, r0
	beq _080D6F30
	b _080D6F52
	.byte 0x00, 0x00
_080D6F08: .4byte 0x096FDCE8
_080D6F0C:
	movs r3, #0x00
	mov r2, sp
	b _080D6F16
_080D6F12:
	adds r2, #0x02
	adds r3, #0x01
_080D6F16:
	cmp r3, #0x02
	bhi _080D6F52
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x00
	ldsh r1, [r2, r5]
	cmp r0, r1
	bge _080D6F12
	ldrh r4, [r2, #0x00]
	movs r0, #0x67
	bl func_0811FE70
	b _080D6F52
_080D6F30:
	movs r3, #0x02
	add r2, sp, #0x004
	b _080D6F3A
_080D6F36:
	subs r2, #0x02
	subs r3, #0x01
_080D6F3A:
	cmp r3, #0x00
	blt _080D6F52
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x00
	ldsh r1, [r2, r5]
	cmp r0, r1
	ble _080D6F36
	ldrh r4, [r2, #0x00]
	movs r0, #0x67
	bl func_0811FE70
_080D6F52:
	bl func_08001390
	movs r1, #0xC0
	lsls r1, r1, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D6F6C
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	bl func_08007E5C
	bl func_080D5998
_080D6F6C:
	movs r0, #0x01
	add sp, #0x008
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
